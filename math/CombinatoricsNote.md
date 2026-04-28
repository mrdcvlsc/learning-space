# Combinatorics Note

## Geometric Series

We can find the total number of vertex/node a perfect tree (with depth $k$) data structure have using geometic series, when I say a perfect tree what I mean is that all the nodes starting from the root up to the nodes at $k - 1$ depth have a fixed number of $n$ child nodes).

**NOTE**: $k - 1$ since the nodes at depth $k$ does not have children since they are the leaf nodes.

$$
v = \frac{n^k - 1}{n - 1}, \quad (n \gt 1 \quad \land \quad k \ge 0)
$$

## n-th triangular number

Given ($k$) players in a chess tournament (or any 1v1 game) in a round-robin format (each players need to play against all other players), find the total ($m$) number of games or total matchups.

$$
n = k - 1
$$

Then we can use the n-th triangular number formula to find out the ($m$) total matchups or number of games:

$$
m = \frac{n(n+1)}{2}
$$

The n-th triangular number is also the shortcut of the summation of incrementing numbers starting from $1$ up to $n$ (eg: $1 + 2 + 3 + ... + n$).

## Total Number of Subset

Given a set of size $n$, how many subsets ($s$) does it have including the improper subset and the empty set?

$$
s = 2^n
$$

Remember this ($s = l + m + n + o$) equation:
- $l = 1$ representing the number of empty set
- $m = 1$ representing the number of improper subset or the set itself
- $n$ is number of all possible sets with cardinality of only 1
- and $o$ is every other set that is not an empty, not an improper subset, and sets that has a cardinality greater than 1.

## Permutation vs Combination

Consider the following scenario, there are 5 different kinds of fruit and 3 boxes.

- $n = 5$
- $r = 3$

### Permutation - order matters.

You are tasked to find out how many ways you can put one fruit (you can choose) in each of the boxes (there are only one fruit per kind, so you cannot repeat putting apples in multiple boxes), to get the total ways to do it you can use the permutation formula below

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

**Example:** `ABC`

$$
P = 3! = 6
$$

Which are `ABC`, `ACB`, `BAC`, `BCA`, `CAB`, `CBA`.

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
Say the sequence contains $(k)$ distinct symbols and the multiplicities (counts) of each symbols are represented by each elements of the vector $M$, where $(|M| = k)$.

$$
M_1,M_2,\dots,M_k,\quad(\sum_{i=1}^k M_i = n)
$$

then the number of distinct permutations is the multinomial formula

$$
P=\dfrac{n!}{M_1! M_2! \cdots M_k!}
$$

Here, division to $M_1! M_2! \cdots M_k!$ corrects for the overcounting caused by swapping identical items of symbol.

**Example:** sequence `AABCC`.

* $(n=5, \quad k=3)$.
* Distinct symbols: $(A,B,C)$ with multiplicities $(M_1=2, \quad M_2=1, \quad M_3=2)$ or count of each unique symbol.

$$
P=\frac{n!}{M_1! \cdot M_2! \cdot M_3!}=\frac{5!}{2!\cdot1!\cdot2!}=\frac{120}{2\cdot1\cdot2}=\frac{120}{4}=30.
$$

## Number of possible *n*-digit sequences in base (B)

**Question.** For a digit system of base (B), how many different (n)-digit sequences are possible? (Here an "n-digit sequence" means an ordered string of (n) digits; leading zeros are allowed.)

**Answer:** $C = B^n$

**Example:** for base 10 $(B=10)$ and $(n=2)$ digits, there are $C = 10^2 = 100$, possible sequences, namely `00` through `99`.

**Note:** There might be tricky questions that disguise itself a **set** type of question but they are **not**, for example; when given a set $Y = \\{ a, b, c \\}$, and you're task to find the total number of subsets with cardinality $2$ and such that the elements of the sets can be repeated in the subsets, don't be tricked because this is still the solution to that, each of the elements in the set can be considered as the base $B$ and the specific cardinality for all of the subsets you're finding is $n$.

If when digits cannot repeat and $(n \le B)$, the count is the permutation of $(B)$ taken $(n)$ at a time:

$$
P(B,n)=\frac{B!}{(B-n)!}.
$$
