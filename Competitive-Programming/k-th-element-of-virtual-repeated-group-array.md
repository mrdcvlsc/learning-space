# Finding the K-th Element in a Virtual Repeated-Group Array

## The Problem

You are given $N$ groups. Each group $i$ holds an array $A_i$ of some length $L_i$, and a repetition count $C_i$. Conceptually, these groups are concatenated into one enormous virtual array $B$:

$$B = [\underbrace{A_0, A_0, \ldots, A_0}_{C_0 \text{ times}},\ \underbrace{A_1, A_1, \ldots, A_1}_{C_1 \text{ times}},\ \ldots,\ \underbrace{A_{N-1}, A_{N-1}, \ldots, A_{N-1}}_{C_{N-1} \text{ times}}]$$

The total length of $B$ is:

$$|B| = \sum_{i=0}^{N-1} C_i \cdot L_i$$

Your task is: **given index $K$ (1-based), return $B[K]$** — without ever building $B$.

The naive approach of actually constructing $B$ is impractical because $|B|$ can be astronomically large. Instead, we use the mathematical structure of the virtual layout to jump directly to the answer.

---

## Key Insight: Group Spans

Because each group $i$ contributes exactly $C_i \cdot L_i$ consecutive elements to $B$, we can think of $B$ as a sequence of **spans** — one per group:

| Group | Elements contributed | Span in $B$                              |
|-------|---------------------|------------------------------------------|
| 0     | $C_0 \cdot L_0$     | $[1,\ C_0 L_0]$                          |
| 1     | $C_1 \cdot L_1$     | $[C_0 L_0 + 1,\ C_0 L_0 + C_1 L_1]$     |
| ...   | ...                 | ...                                      |
| i     | $C_i \cdot L_i$     | continues from where group $i-1$ ended   |

So the question reduces to: **which group does position $K$ fall in?**

---

## The Algorithm

We scan through the groups one by one, subtracting each group's span from $K$ until $K$ is small enough to land inside the current group.

```cpp
for (size_t i = 0; i < N; i++) {
    // How many elements does group i contribute to the virtual array?
    size_t add_size = C[i] * A[i].size();   // = C_i * L_i

    // Does K fall within this group's span?
    if (K <= add_size) {
        // Yes — K lands somewhere in the C_i repetitions of A[i].
        // (K - 1) converts to 0-based, then modulo wraps it
        // into a valid index within A[i].
        cout << A[i][(K - 1) % A[i].size()];
        return 0;
    }

    // No — K is beyond this group. Subtract the whole span and move on.
    K -= add_size;
}
```

---

## Why `(K - 1) % A[i].size()` Works

Once we know $K$ is inside group $i$, we need to identify *which element of* $A_i$ it points to.

Group $i$ is just $A_i$ repeated $C_i$ times. So the elements in that span look like:

$$A_i[0],\ A_i[1],\ \ldots,\ A_i[L_i - 1],\ A_i[0],\ A_i[1],\ \ldots,\ A_i[L_i - 1],\ \ldots$$

The local position within the group is $K$ itself (after all previous groups have been subtracted out). Converting to 0-based gives $K - 1$, and since $A_i$ repeats with period $L_i$:

$$\text{answer} = A_i\bigl[(K - 1) \bmod L_i\bigr]$$

For example, if $A_i = [10, 20, 30]$ and $K = 5$ (local, 1-based), then $(5 - 1) \bmod 3 = 1$, giving $A_i[1] = 20$. That is correct because the 5th element in the repeating sequence $[10, 20, 30, 10, 20, 30, \ldots]$ is indeed $20$.

---

## Worked Example

Suppose we have:

- $A_0 = [1, 2]$, $C_0 = 3$ → contributes $3 \times 2 = 6$ elements: $[1, 2, 1, 2, 1, 2]$
- $A_1 = [5, 6, 7]$, $C_1 = 2$ → contributes $2 \times 3 = 6$ elements: $[5, 6, 7, 5, 6, 7]$

Virtual array $B$ (length 12):

$$B = [1, 2, 1, 2, 1, 2,\ 5, 6, 7, 5, 6, 7]$$

**Query: $K = 9$**

- Group 0: $add\_size = 6$. Is $9 \leq 6$? No. Subtract: $K = 9 - 6 = 3$.
- Group 1: $add\_size = 6$. Is $3 \leq 6$? Yes.
  - Index in $A_1$: $(3 - 1) \bmod 3 = 2 \bmod 3 = 2$.
  - Answer: $A_1[2] = 7$. ✓

Indeed, $B[9] = 7$ (1-based).

---

## Complexity

The algorithm runs in $O(N)$ time and $O(1)$ extra space (beyond the input). It never constructs $B$ at any point — the entire virtual array of potentially billions of elements is navigated purely through arithmetic.

This pattern — *scanning group spans and using modulo to pinpoint a position within a repeating unit* — appears frequently in problems involving virtual or implicitly-defined sequences, such as tiling problems, circular buffer queries, and run-length encoded arrays.
