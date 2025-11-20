# Combinatorics Note

## Geometric Series

We can find the total number of vertex/node a perfect tree data structure have (meaning that all nodes from the root up to the given $k - 1$ depth have a fixed $n$ number of childrens) using geometic series.

$$
v = \frac{n^k - 1}{n - 1}
$$

## n-th triangular number

Find the max possible number ($m$) of subsets (improper subset included) with a cardinality greater than $1$ in a given set of size $s = n + 1$, also note that $n = s - 1$.

$$
m = \frac{n(n+1)}{2}
$$

## Permutation vs Combination

Consider the following scenario, there are 5 different kinds of fruit and 3 boxes.

- $n = 5$
- $r = 3$

### Permutation - order matters.

You are tasked to find out how many ways you can put one fruit in each of the boxes, to get the total ways to do it you can use the permutation formula below

$$
n^P r = P(n,r)=\frac{n!}{(n-r)!},\quad(0\le r\le n).
$$

### Combination - order does not matter (unordered).

You are tasked to count how many ways to place one fruit in each of the 3 boxes. That is, the arrangement is the same no matter which box
holds which fruit, for example, (Box1: apple, Box2: orange, Box3: mango) is identical to (Box1: mango, Box2: apple, Box3: orange),
to get the total number of ways, you can use the combination formula below.

$$
n^C r = C(n,r)=\frac{n!}{(n-r)! \cdot r!},\quad(0\le r\le n).
$$

**NOTE:** in some sources $k$ is used instead of $r$.

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

Notice that you could extend it to multiple sets using the same idea.

$$
n = s! \cdot (\prod_{i=1}^{n} |S_i|)
$$

Here the $s$ is the number of sets, $S_i$ is a set we get when we iterate over all of the sets, and for $|S_i|$ we just get the size/cardinality of the current set during iteration.

## Permutations of *n* distinct elements

**Question.** Given a sequence of *n* **distinct** elements, how many different sequential arrangements (permutations or *P*) are possible?

**Answer:** $P = n!$

**Example:** `ABC`, $P = 3! = 6$

**Notes:**

* This assumes all elements are distinct.
* By convention ($0! = 1$).
* If you want the number of ordered arrangements of length (sub) (without repetition) from (n) distinct elements, use the permutation formula

$$
P(n,sub)=\frac{n!}{(n-sub)!},\quad(0\le sub\le n).
$$

## Permutations of an *n*-element sequence with repeated values

**Question.** Given a sequence of (n) elements that may include repeated values, how many distinct sequential arrangements (permutations) are possible?

**Answer:**
If the sequence contains $(k)$ distinct symbols and the multiplicities (counts) of those symbols are

$$
n_1,n_2,\dots,n_k,\quad(\sum_{j=1}^k n_j = n)
$$

then the number of distinct permutations is the multinomial formula

$$
P=\dfrac{n!}{n_1! n_2! \cdots n_k!}
$$

Here, division to $n_1! n_2! \cdots n_k!$ corrects for the overcounting caused by swapping identical items of symbol.

**Example:** sequence `AABCC`.

* $(n=5)$.
* Distinct symbols: $(A,B,C)$ with multiplicities $(n_A=2, n_B=1, n_C=2)$.

$$
P=\frac{n!}{n_A! \cdot n_B! \cdot n_C!}=\frac{5!}{2!\cdot1!\cdot2!}=\frac{120}{2\cdot1\cdot2}=\frac{120}{4}=30.
$$

## Number of possible *n*-digit sequences in base (B)

**Question.** For a digit system of base (B), how many different (n)-digit sequences are possible? (Here an "n-digit sequence" means an ordered string of (n) digits; leading zeros are allowed.)

**Answer:** $C = B^n$

**Example:** for base 10 $(B=10)$ and $(n=2)$ digits, there are $C = 10^2 = 100$, possible sequences, namely `00` through `99`.

If when digits cannot repeat and $(n \le B)$, the count is the permutation of $(B)$ taken $(n)$ at a time:

$$
P(B,n)=\frac{B!}{(B-n)!}.
$$
