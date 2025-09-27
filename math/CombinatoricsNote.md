# Combinatorics Note

## Permutation vs Combination

- **Permutation** - order matters.
- **Combination** - order does not matter (unordered).

## Finding all possible number of pairs from the elements of set A & B (order DOES NOT matter)

```py
A = { a, b }, B = { c }
C = {{ a, c }, { b, c }}
```

$$
n = |A| \cdot |B |
$$

## Finding all possible number of pairs from the elements of set A & B (order matters)

```py
A = { a, b }, B = { c }
C = {{ a, c }, { b, c }, { c, a }, { c, b }}
```

$$
n = 2! \cdot (|A| \cdot |B|)
$$

**NOTE:** If you have 3 sets and you want to get the total number of possible tripples, then the formula would look like this.

$$
n = 3! \cdot (|A| \cdot |B| \cdot |C|)
$$

or

$$
n = s! \cdot (|A| \cdot |B| \cdot |C|)
$$

Where *s* is the number of sets. Notice that you could extend it to multiple sets using the same idea.

## Permutations of *n* distinct elements

**Question.** Given a sequence of *n* **distinct** elements, how many different sequential arrangements (permutations or *P*) are possible?

**Answer:** $P = n!$

**Notes:**

* This assumes all elements are distinct.
* By convention ($0! = 1$).
* If you want the number of ordered arrangements of length (r) (without repetition) from (n) distinct elements, use the permutation formula

$$
P(n,r)=\frac{n!}{(n-r)!}\quad(0\le r\le n).
$$

---

## Number of possible *n*-digit sequences in base (B)

**Question.** For a digit system of base (B), how many different (n)-digit sequences are possible? (Here an "n-digit sequence" means an ordered string of (n) digits; leading zeros are allowed.)

**Answer.**

$$
C = B^n
$$

**Example.** For base 10 (*B=10*) and (*n=2*) digits, there are $C = 10^2 = 100$, possible sequences, namely `00` through `99`.

**If repetition is not allowed:** when digits cannot repeat (and (n\le B)), the count is the permutation of (B) taken (n) at a time:

$$
P(B,n)=\frac{B!}{(B-n)!}.
$$

---

**Terminology note:** In combinatorics the word *combination* usually means an unordered selection (order does not matter). In the sections above we discuss *ordered* arrangements (permutations) and *digit sequences* — so using "sequence" or "ordered arrangement" is less ambiguous than "combination."
