# Java Containers Cheat Sheet

---

## 1.) Dynamic arrays - continuous block in memory (`ArrayList`)

```java
import java.util.ArrayList;
import java.util.List;

List<Integer> a = new ArrayList<>();    // init
a.add(10);                              // add
a.add(20);
a.add(1, 15);                           // insert at index

int x = a.get(0);                       // get
boolean has20 = a.contains(20);         // search
int idx = a.indexOf(15);

a.remove(Integer.valueOf(10));          // remove by object
a.remove(0);                            // remove by index

int size = a.size();
a.clear();
```

---

## 2.) Dynamic arrays - linked list type (`LinkedList`)

```java
import java.util.LinkedList;
import java.util.List;
import java.util.Deque;
import java.util.Iterator;

LinkedList<String> ll = new LinkedList<>(); // init
ll.add("a");                                // add (end)
ll.addFirst("head");                        // add front
ll.addLast("tail");                         // add end
ll.add(1, "middle");                        // insert at index

String first = ll.getFirst();               // peek front
String last = ll.getLast();                 // peek last
boolean has = ll.contains("a");             // search

ll.removeFirst();                           // remove front
ll.removeLast();                            // remove last
ll.remove("middle");                        // remove by object
ll.remove(1);                               // remove by index

// use as Deque: push/pop (stack-like) or queue-like methods
Deque<String> dq = ll;
dq.push("stackTop");
String popped = dq.pop();
```

---

## 3.) Set (ordered) - `TreeSet` (red-black tree)

```java
import java.util.TreeSet;
import java.util.NavigableSet;

TreeSet<Integer> ts = new TreeSet<>();  // init (sorted)
ts.add(5);
ts.add(2);
ts.add(9);

boolean contains = ts.contains(2);      // search
ts.remove(5);                           // remove

Integer first = ts.first();             // smallest
Integer last = ts.last();               // largest
Integer higher = ts.higher(2);          // least > 2
NavigableSet<Integer> range = ts.subSet(2, true, 9, false); // range view
```

---

## 4.) Multiset (counts) - Guava `Multiset` (no built-in JDK multiset)

```java
// Requires Guava library on the classpath
import com.google.common.collect.HashMultiset;
import com.google.common.collect.Multiset;

Multiset<String> ms = HashMultiset.create(); // init
ms.add("apple");                              // add one
ms.add("apple", 2);                           // add 2 more
int count = ms.count("apple");                // count occurrences

ms.remove("apple");                           // remove one occurrence
ms.remove("apple", 2);                        // remove up to 2 occurrences
boolean contains = ms.contains("apple");      // membership (>=1)
for (String elem : ms.elementSet()) {         // distinct elements
    int c = ms.count(elem);
}
```

**Alternative (JDK-only):** `Map<T,Integer>` or `computeIfAbsent` with counts.

```java
import java.util.HashMap;
import java.util.Map;
Map<String,Integer> m = new HashMap<>();
m.merge("apple", 1, Integer::sum);    // increment count
int c = m.getOrDefault("apple", 0);
m.put("apple", Math.max(0, c - 1));  // decrement or remove
```

---

## 5.) Map (ordered) - `TreeMap` (sorted map)

```java
import java.util.TreeMap;
import java.util.NavigableMap;
import java.util.Map;

TreeMap<String,Integer> tm = new TreeMap<>(); // init (sorted)
tm.put("a", 1);                               // put
tm.putIfAbsent("b", 2);
int v = tm.get("a");                          // get (may be null)
boolean hasKey = tm.containsKey("b");
tm.remove("a");                               // remove

String firstKey = tm.firstKey();
String lastKey  = tm.lastKey();
Map.Entry<String,Integer> low = tm.lowerEntry("c"); // entry lower than "c"
NavigableMap<String,Integer> sub = tm.subMap("a", true, "z", true);
```

---

## 6.) Multimap - Guava `Multimap` and JDK alternative

```java
// Guava option (add Guava to classpath)
import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.Multimap;
import java.util.Collection;

Multimap<String,String> mm = ArrayListMultimap.create(); // init
mm.put("k1", "v1");
mm.put("k1", "v2");
Collection<String> vals = mm.get("k1");                // returns collection view
mm.remove("k1", "v1");                                 // remove single mapping
Collection<String> removed = mm.removeAll("k1");       // remove all values for key
```

**JDK-only alternative (Map→List)**

```java
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

Map<String,List<String>> mm2 = new HashMap<>();
mm2.computeIfAbsent("k1", k -> new ArrayList<>()).add("v1");
mm2.computeIfAbsent("k1", k -> new ArrayList<>()).add("v2");

List<String> listForK1 = mm2.getOrDefault("k1", List.of());
mm2.get("k1").remove("v1");            // remove one value
```

---

## 7.) Unordered map (`HashMap`)

```java
import java.util.HashMap;
import java.util.Map;

Map<String,Integer> hm = new HashMap<>();   // init (hash table)
hm.put("x", 1);                            // add
hm.put("y", 2);
int val = hm.getOrDefault("x", 0);         // get with default
boolean has = hm.containsKey("y");
hm.remove("x");                            // remove

// useful atomic-style methods (since Java 8+)
hm.putIfAbsent("z", 3);
hm.computeIfAbsent("z", k -> 42);
```

**Concurrent version**

```java
import java.util.concurrent.ConcurrentHashMap;
ConcurrentHashMap<String,Integer> chm = new ConcurrentHashMap<>();
chm.putIfAbsent("a", 1);
```

---

## 8.) Unordered set (`HashSet`)

```java
import java.util.HashSet;
import java.util.Set;

Set<String> hs = new HashSet<>();    // init (hash set)
hs.add("apple");                     // add
boolean has = hs.contains("apple");  // search
hs.remove("apple");                  // remove
int size = hs.size();
for (String s : hs) System.out.println(s);
```

---

## 9.) Queue (FIFO) - `ArrayDeque` as queue and blocking queue example

```java
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;

// non-blocking FIFO using ArrayDeque
Queue<Integer> q = new ArrayDeque<>();
q.offer(1);                 // add (returns false if cannot)
q.offer(2);
Integer head = q.peek();    // peek at head
Integer polled = q.poll();  // poll removes and returns head

// bounded blocking queue (concurrent) example
ArrayBlockingQueue<Integer> bq = new ArrayBlockingQueue<>(10);
bq.put(5);                  // blocks if full
Integer take = bq.take();   // blocks if empty
```

---

## 10.) Set - `HashSet`, `TreeSet`, `LinkedHashSet` (insertion-ordered)

```java
import java.util.HashSet;
import java.util.TreeSet;
import java.util.LinkedHashSet;

HashSet<String> u = new HashSet<>();        // unordered
TreeSet<String> ordered = new TreeSet<>();  // sorted
LinkedHashSet<String> insOrdered = new LinkedHashSet<>(); // insertion order

u.add("a"); ordered.add("a"); insOrdered.add("a");
u.contains("a"); ordered.contains("a"); insOrdered.contains("a");
u.remove("a"); ordered.remove("a"); insOrdered.remove("a");
```

---

## 11.) Min-heap - `PriorityQueue` (default is min-heap)

```java
import java.util.PriorityQueue;
import java.util.Queue;

PriorityQueue<Integer> minHeap = new PriorityQueue<>(); // min-heap
minHeap.offer(5);
minHeap.offer(1);
minHeap.offer(3);

int top = minHeap.peek();   // smallest element (1)
int polled = minHeap.poll(); // removes smallest
```

---

## 12.) Max-heap - `PriorityQueue` with reversed comparator

```java
import java.util.PriorityQueue;
import java.util.Comparator;

PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder()); // max-heap
maxHeap.offer(5);
maxHeap.offer(1);
maxHeap.offer(3);

int max = maxHeap.peek();   // largest element (5)
int removedMax = maxHeap.poll();
```

---

## 13.) Red-black tree - `TreeSet` / `TreeMap` (already shown above)

```java
// TreeSet example (red-black tree)
import java.util.TreeSet;

TreeSet<String> rb = new TreeSet<>();
rb.add("c");
rb.add("a");
rb.add("b");

boolean exists = rb.contains("a");
rb.remove("c");
String smallest = rb.first();
```

---

## 14. Stack (LIFO structure, like `std::stack` in C++)

* **Legacy class:** `java.util.Stack<E>` (since Java 1.0, synchronized, extends `Vector`).
* **Preferred modern replacement:** `ArrayDeque<E>` used as a stack (Java 1.6+).
* **Time complexity:** `push`, `pop`, `peek` are O(1).

**Example with modern `ArrayDeque` (preferred):**

```java
import java.util.ArrayDeque;
import java.util.Deque;

Deque<Integer> st = new ArrayDeque<>();
st.push(10);
st.push(20);
System.out.println(st.peek()); // 20
System.out.println(st.pop());  // 20
System.out.println(st.isEmpty());
```

---

## 15. Bitset

Nice - good call. Java’s analogue to `std::bitset` is `java.util.BitSet`. It’s a compact bit container with fast bitwise ops - but note some differences vs C++ `bitset` (Java `BitSet` is dynamically sized and grows as needed; `std::bitset<N>` is fixed-size at compile time).

**Quick notes**

* Java: `java.util.BitSet` - dynamic/grows, methods for `set/clear/flip/get`, bitwise ops `and/or/xor`, fast `cardinality()` (population count), `nextSetBit(int)` to iterate set bits, `toLongArray()`/`toByteArray()` for compact export.
* C++ `std::bitset<N>` is fixed-size and has some compile-time guarantees; if you need a *fixed-size* bitset in Java, either create a `BitSet` with a known capacity and only use indices < N, or manage a `long[]` yourself.
* `BitSet` is **not** synchronized - not thread-safe by default.

**Short example**

```java
import java.util.BitSet;

// create with initial capacity (optional)
BitSet bs = new BitSet(128);   // can hold bits 0..127 initially (grows if needed)

// set / clear / flip / get
bs.set(2);                     // set bit 2
bs.set(10, 20);                // set bits 10..19 (end exclusive)
boolean bit2 = bs.get(2);      // true
bs.clear(2);                   // clear bit 2
bs.flip(5);                    // toggle bit 5

// cardinality & iteration
int count = bs.cardinality();  // number of set bits
for (int i = bs.nextSetBit(0); i >= 0; i = bs.nextSetBit(i + 1)) {
    // i is index of a set bit
}

// bitwise ops (in-place)
BitSet other = new BitSet();
other.set(10);
bs.and(other);    // bs = bs & other
bs.or(other);     // bs = bs | other
bs.xor(other);    // bs = bs ^ other

// useful helpers
int highestPlusOne = bs.length();    // index of highest-set-bit + 1 (0 if empty)
long[] words = bs.toLongArray();     // compact long[] representation
byte[] bytes = bs.toByteArray();     // compact byte[] representation

// clear all
bs.clear();
```

---

## Big Integers

```java
// BigInteger examples
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Random;

// creation
BigInteger a = BigInteger.valueOf(123456789L);        // from long
BigInteger b = new BigInteger("9876543210123456789"); // from decimal string
BigInteger c = new BigInteger("deadbeef", 16);        // from hex string (radix 16)

// arithmetic
BigInteger sum = a.add(b);
BigInteger diff = b.subtract(a);
BigInteger prod = a.multiply(b);
BigInteger[] divRem = b.divideAndRemainder(a); // divRem[0]=quotient, divRem[1]=remainder
BigInteger quot = divRem[0];
BigInteger rem  = divRem[1];

// division with rounding: usually do divideAndRemainder or use BigDecimal for non-integer division.
// modular arithmetic
BigInteger mod = b.mod(a);                         // b % a (a must be >0)
BigInteger modPow = a.modPow(BigInteger.valueOf(7), BigInteger.valueOf(1000)); // a^7 % 1000

// gcd, sign, compare
BigInteger g = a.gcd(b);
int cmp = a.compareTo(b);    // -1,0,1
boolean eq = a.equals(b);

// bit ops
BigInteger shiftedLeft  = a.shiftLeft(10);  // multiply by 2^10
BigInteger shiftedRight = a.shiftRight(3);  // divide floor by 2^3
boolean bit2 = a.testBit(2);                // is bit 2 set?
BigInteger withBitSet = a.setBit(5);        // returns new BigInteger with bit 5 = 1

// conversion
byte[] bytes = a.toByteArray();
String decimal = b.toString();              // decimal string
String hex = b.toString(16);                // hex string

// prime generation / primality
Random rnd = new SecureRandom();
BigInteger prime = BigInteger.probablePrime(128, rnd); // 128-bit probable prime
boolean isProbablyPrime = prime.isProbablePrime(100);  // 100 = certainty parameter

// helpful patterns
BigInteger ZERO = BigInteger.ZERO;
BigInteger ONE  = BigInteger.ONE;
BigInteger TWO  = BigInteger.TWO;
```

Short notes:

* `BigInteger` is **immutable** — methods return new objects.
* For decimal (non-integer) arbitrary precision use `java.math.BigDecimal`. `BigDecimal` supports scale and rounding modes and is the right choice for financial calculations.
* `BigInteger.probablePrime(bitLen, rnd)` gives a *probable* prime; use a high certainty or additional deterministic checks if you need strict guarantees.
* `BigInteger` arithmetic can be significantly slower than primitive `long`/`int` — use it only when you need arbitrary precision.
