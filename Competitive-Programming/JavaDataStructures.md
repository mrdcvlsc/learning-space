# Java Containers Cheat Sheet
*Java Data Structures and Algorithm - Competitive Programming Refresher*

- [Constants & Type Limits](#0-constants--type-limits)
- [Primitive Arrays - (contiguous)](#1-raw--primitive-arrays)
- [Dynamic Arrays - (non-contiguous)](#2-dynamic-arrays-arraylist)
- [Binary Search On Sorted Asc Array](#2-dynamic-arrays-arraylist)
- [Linked List](#3-linked-list)
- [Stacks](#4-stack-arraydeque--preferred-over-legacy-stack)
- [Queues](#5-queue-fifo--arraydeque)
- [Pairs & Tuples](#6-pair--tuple)
- [Utilities for Arrays](#7-arrays-utilities)
- [Utilities for Collections](#8-collections-utilities)
- [Frequency Counting With Hashmaps - (Multimap like)](#9-frequency-counting-with-hashmap)
- [String Builder](#10-stringbuilder)
- [Ordered & Unordered Sets](#11-set-variants)
- [Ordered & Unordered Maps](#12-map-variants)
- [Min Heaps](#13-min-heap-priorityqueue)
- [Max Heaps](#14-max-heap-priorityqueue-reversed)
- [Min/Max Heaps With Pairs](#15-priorityqueue-with-pairs--custom-objects)
- [Monotonic Dequeue](#16-monotonic-deque-sliding-window-maxmin)
- [Bitsets](#17-bitset)
- [Big Integers](#18-biginteger)

---

## CP Quick Notes
- Prefer `offer/poll/peek` over `add/remove/element` in queues/heaps - they return `null`/`false` instead of throwing exceptions.
- `int[]` pairs beat `Map.Entry` or custom classes for speed and simplicity in CP.
- All sections use **JDK-only** classes - no external libraries required.

---

## 0. Constants & Type Limits

```java
// Safe infinity values (avoids overflow on INF + INF)
int    INF  = (int) 1e9;         // use instead of Integer.MAX_VALUE in graphs
long   LINF = (long) 1e18;       // use instead of Long.MAX_VALUE in graphs
double EPS  = 1e-9;              // epsilon for floating-point comparison

// Absolute limits (for reference)
int    INT_MAX  = Integer.MAX_VALUE; // 2^31 - 1 = 2,147,483,647
int    INT_MIN  = Integer.MIN_VALUE;
long   LONG_MAX = Long.MAX_VALUE;    // ~9.2 * 10^18
```

---

## 1. Raw / Primitive Arrays

> The closest Java gets to a C++ `std::vector<int>` in terms of memory layout.
> Elements are stored **inline and contiguously** - no boxing, no heap pointers per element.
> Fixed size: you must know the length upfront, or resize manually (copy to a new array).

### Memory layout vs. ArrayList

```
int[] a = {1, 2, 3, 4, 5};

Memory (contiguous ints, no indirection):
[ 1 | 2 | 3 | 4 | 5 ]
  ^   ^   ^   ^   ^
  each slot IS the int value - no pointer, no Integer object

ArrayList<Integer> list = new ArrayList<>();
list.add(1); list.add(2); ...

Memory (contiguous references, objects scattered on heap):
[ ref0 | ref1 | ref2 | ref3 | ref4 ]   <- backing Object[] (contiguous)
    |      |      |      |      |
  Int(1) Int(2) Int(3) Int(4) Int(5)   <- boxed Integer objects (scattered)
```

This matters for cache performance on large arrays: iterating `int[]` is cache-friendly
because every element is adjacent. Iterating `ArrayList<Integer>` chases a pointer per
element, causing cache misses proportional to how scattered the Integer objects are.

### Declaration and initialization

```java
int[]    a = new int[5];         // zero-initialized               - O(n)
int[]    b = {3, 1, 4, 1, 5};    // inline literal                 - O(n)
int[]    c = new int[]{3, 1, 4}; // explicit literal (works anywhere) - O(n)
long[]   d = new long[5];        // zero-initialized               - O(n)
double[] e = new double[5];      // zero-initialized to 0.0        - O(n)
boolean[]f = new boolean[5];     // zero-initialized to false      - O(n)
char[]   g = new char[5];        // zero-initialized to '\0'       - O(n)

int n = b.length;                // fixed length field             - O(1)
```

### Access and modification

```java
int[] a = {3, 1, 4, 1, 5};

int x    = a[2];     // read by index  - O(1)
a[2]     = 99;       // write by index - O(1)
int len  = a.length; // length field   - O(1)
```

### Sorting

```java
int[] a = {3, 1, 4, 1, 5};

Arrays.sort(a);              // sort asc in-place (dual-pivot quicksort) - O(n log n)
Arrays.sort(a, 1, 4);        // sort subarray [1, 4) in-place           - O(k log k), k = range size

// PITFALL: Arrays.sort on primitives has NO overload that accepts a Comparator.
// You CANNOT do: Arrays.sort(a, Comparator.reverseOrder()); - compile error.
// To sort descending you have two options:

// Option A: sort asc then reverse - O(n log n) + O(n)
Arrays.sort(a);
for (int i = 0, j = a.length - 1; i < j; i++, j--) {
    int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
}

// Option B: box to Integer[], sort with Comparator, then unbox if needed
// This defeats the purpose of using primitives - avoid in hot paths.
Integer[] boxed = new Integer[a.length];
for (int i = 0; i < a.length; i++) boxed[i] = a[i];   // O(n) - boxing cost
Arrays.sort(boxed, Comparator.reverseOrder());          // O(n log n)
// Unbox back if you need int[]:
for (int i = 0; i < a.length; i++) a[i] = boxed[i];   // O(n) - unboxing cost
```

### Copying and filling

```java
int[] a = {3, 1, 4, 1, 5};

int[] copy  = Arrays.copyOf(a, a.length);     // full copy                        - O(n)
int[] grown = Arrays.copyOf(a, a.length * 2); // copy + grow (zero-pads new slots) - O(n)
int[] slice = Arrays.copyOfRange(a, 1, 4);    // partial copy [1, 4)              - O(k), k = range size

Arrays.fill(a, 0);                            // fill entire array                - O(n)
Arrays.fill(a, 1, 4, -1);                     // fill subarray [1, 4) with -1     - O(k)
```

### 2D arrays

```java
// 2D array - array of row arrays; rows are contiguous, but row objects are scattered
int[][] grid = new int[3][4];                           // 3 rows, 4 cols, zero-init - O(n*m)
for (int[] row : grid) Arrays.fill(row, -1);           // fill all cells with -1    - O(n*m)

int val    = grid[1][2];     // read cell (row 1, col 2)  - O(1)
grid[0][0] = 7;              // write cell                - O(1)
int rows   = grid.length;    // number of rows            - O(1)
int cols   = grid[0].length; // number of cols            - O(1)

// PITFALL: rows in a 2D array are separate heap objects.
// grid[0], grid[1], grid[2] are pointers to three separate int[] arrays.
// Accessing grid[r][c] = two pointer hops: one to get row r, one to get element c.
// This is fine for most CP problems but means 2D arrays are NOT a flat contiguous block.

// Flat 1D array as a 2D grid - single contiguous block, better cache behavior:
int[] flat = new int[3 * 4];              // O(n*m)
flat[1 * 4 + 2] = 7;                     // write grid[1][2]  - O(1)
int v = flat[1 * 4 + 2];                 // read grid[1][2]   - O(1)
// Helper: inline index formula -> row * numCols + col
```

### Printing for debugging

```java
int[]   a      = {1, 2, 3};
int[][] matrix = {{1, 2}, {3, 4}};

System.out.println(Arrays.toString(a));           // "[1, 2, 3]"         - O(n)
System.out.println(Arrays.deepToString(matrix));  // "[[1, 2], [3, 4]]"  - O(n*m)

// PITFALL: do NOT use a.toString() or System.out.println(a) -
// these print the identity hashcode (e.g. "[I@6d06d69c"), not the contents.
```

### CP best practices summary

```
DO:
  - Use int[] / long[] for all fixed-size numeric data - no boxing overhead, cache-friendly.
  - Pre-allocate at maximum possible size (e.g. int[200_005]) rather than resizing.
  - Use a manual `size` variable to track the logical end if you need dynamic behavior.
  - Use Arrays.sort(a) for ascending sort - it's fast (dual-pivot quicksort on primitives).
  - Use the reverse-in-place trick for descending sort instead of boxing.
  - Use flat 1D arrays (row * cols + col) for 2D grids in performance-critical code.

DON'T:
  - Use Integer[] when int[] works - boxing/unboxing adds GC pressure and cache misses.
  - Call a.toString() or print an array directly - use Arrays.toString().
  - Sort a primitive array with a Comparator - it won't compile; box first or sort then reverse.
  - Assume 2D arrays (int[][]) are a flat memory block - each row is a separate heap object.
```

---

## 2. Dynamic Arrays (`ArrayList`)

> **Autoboxing and cache-miss warning for CP**
>
> `ArrayList` requires a type parameter, and Java generics do not support primitives.
> This means `ArrayList<Integer>` stores **boxed `Integer` objects**, not raw `int` values.
> Every `add` autoboxes the `int` to an `Integer` heap object; every `get` may unbox it back.
>
> Two costs you pay that `int[]` does not:
> - **Autoboxing overhead**: each element addition allocates an `Integer` object on the heap.
> - **Cache misses on iteration**: the backing `Object[]` holds *references* (pointers) to
>   `Integer` objects scattered across the heap. Iterating a large `ArrayList<Integer>` chases
>   one pointer per element, destroying cache locality. An `int[]` of the same data is a single
>   contiguous block with zero indirection.
>
> **CP rule of thumb**: if the size is bounded and known (or has a safe upper bound),
> prefer a pre-allocated `int[]` with a manual size counter. Use `ArrayList` when you
> genuinely need dynamic resizing and the boxing cost is acceptable (e.g. storing objects
> that are already on the heap, like `int[]` pairs or `String`s).

```java
import java.util.ArrayList;
import java.util.List;

List<Integer> a = new ArrayList<>();    // init
a.add(10);                              // add to end              - O(1) amortized (autoboxes int -> Integer)
a.add(20);                             // add to end              - O(1) amortized
a.add(1, 15);                           // insert at index         - O(n) (shifts elements right)

int x = a.get(0);                       // get by index            - O(1) (unboxes Integer -> int)
boolean has20 = a.contains(20);         // search                  - O(n)
int idx = a.indexOf(15);               // first index of value    - O(n)

a.sort(Comparator.naturalOrder());      // sort asc                - O(n log n)
a.sort(Comparator.reverseOrder());      // sort desc               - O(n log n)

a.remove(Integer.valueOf(10));          // remove by object        - O(n) (search + shift)
a.remove(0);                            // remove by index         - O(n) (shifts elements left)

int size = a.size();                    // size                    - O(1)
a.clear();                              // clear all elements      - O(n)
```

## 2.5 Binary Search, Lower Bound, Upper Bound, Equal Range
> List **must be sorted** before calling any of these.

### Binary search on sorted primitive arrays

```java
int[] a = {1, 3, 3, 5, 7, 9}; // must be sorted first

int idx = Arrays.binarySearch(a, 5); // O(log n) - exact index, or -(insertionPoint+1) if absent
// Same caveat as Collections.binarySearch: no guarantee which duplicate is returned.
// Use the custom lowerBound / upperBound helpers from section 2 for precise control.
```

### Binary Search On ArrayList

```java
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

List<Integer> a = new ArrayList<>(Arrays.asList(1, 3, 3, 5, 7, 9));

// --- Binary Search ---
// Returns index of any match, or -(insertionPoint + 1) if not found.
// If duplicates exist, no guarantee which index is returned.
int idx = Collections.binarySearch(a, 3);  // O(log n) - some index where a.get(idx) == 3
if (idx < 0) {
    // not found; insertion point = -(idx + 1)
    int insertAt = -(idx + 1);
}
```

### Lower Bound Binary Search - like `std::lower_bound`

```java
// First index of an element >= target.
// Returns `n` if all elements are < target.
static int lowerBound(long[] a, int n, long target) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
```

### Upper Bound Binary Search - like `std::upper_bound`

```java
// First index of an element > target.
// Returns `n` if all elements are <= target.
static int upperBound(long[] a, int n, long target) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
```

### Equal Range Binary Search - like `std::equal_range`

```java
// Returns int[]{lo, hi} - the half-open range [lo, hi) where arr[i] == target.
// Range is empty (lo == hi) if target is not found.
// Faster than calling lowerBound + upperBound independently:
static int[] equalRange(long[] a, int n, long target) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    int left = l;

    r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= target)
            l = mid + 1;
        else
            r = mid;
    }
    int right = l;

    return new int[] { left, right };
}
```

### Usage Example

```java
// arr = [1, 3, 3, 5, 7, 9]
long[] arr = {1, 3, 3, 5, 7, 9};
int n = arr.length;

lowerBound(arr, n, 3);   // O(log n) -> 1  (first index where value >= 3)
upperBound(arr, n, 3);   // O(log n) -> 3  (first index where value >  3)
lowerBound(arr, n, 4);   // O(log n) -> 3  (first index where value >= 4, lands on 5)
upperBound(arr, n, 4);   // O(log n) -> 3  (first index where value >  4, lands on 5)

int[] range = equalRange(arr, n, 3); // O(log n) -> [1, 3)  i.e. range[0]=1, range[1]=3
int[] empty = equalRange(arr, n, 4); // O(log n) -> [3, 3)  i.e. range[0]==range[1] -> not found

// Count occurrences of target:
int count = range[1] - range[0];        // O(1) -> 2 (two 3s)

// Check if target exists:
boolean exists = range[0] < range[1];   // O(1) -> true

// Iterate over all matching elements:
for (int i = range[0]; i < range[1]; i++) {
    // arr[i] == target                  // O(1) per access
}

// Check if target exists (using lowerBound directly):
int lb = lowerBound(arr, n, 3);            // O(log n)
boolean found = lb < n && arr[lb] == 3;   // O(1) -> true
```

---

## 3. Linked List

```java
import java.util.LinkedList;
import java.util.Deque;

LinkedList<String> ll = new LinkedList<>();
ll.add("a");                                // add to end              - O(1)
ll.addFirst("head");                        // add to front            - O(1)
ll.addLast("tail");                         // add to end              - O(1)
ll.add(1, "middle");                        // insert at index         - O(n)

String first = ll.getFirst();               // peek front              - O(1)
String last  = ll.getLast();                // peek last               - O(1)
boolean has  = ll.contains("a");            // search                  - O(n)

ll.sort(Comparator.naturalOrder());         // sort asc                - O(n log n)
ll.sort(Comparator.reverseOrder());         // sort desc               - O(n log n)

ll.removeFirst();                           // remove front            - O(1)
ll.removeLast();                            // remove back             - O(1)
ll.remove("middle");                        // remove by object        - O(n) (scan + unlink)
ll.remove(1);                               // remove by index         - O(n) (scan to index + unlink)

// Use as Deque (stack-like or queue-like)
Deque<String> dq = ll;
dq.push("stackTop");       // add to front            - O(1)
String popped = dq.pop();  // remove from front       - O(1)
```

---

## 4. Stack (`ArrayDeque` - preferred over legacy `Stack`)

> `ArrayDeque` is faster and not synchronized. Prefer it over `java.util.Stack`.

```java
import java.util.ArrayDeque;
import java.util.Deque;

Deque<Integer> st = new ArrayDeque<>();
st.push(10);                      // push to top             - O(1)
st.push(20);                      // push to top             - O(1)
Integer top    = st.peek();       // peek top (20)           - O(1), returns null if empty
Integer popped = st.pop();        // pop top (20)            - O(1), throws NoSuchElementException if empty
boolean empty  = st.isEmpty();    // check empty             - O(1)
int size       = st.size();       // size                    - O(1)
```

---

## 5. Queue (FIFO - `ArrayDeque`)

```java
import java.util.ArrayDeque;
import java.util.Queue;

Queue<Integer> q = new ArrayDeque<>();
q.offer(1);                   // enqueue                 - O(1), returns false if fails (prefer over add())
q.offer(2);                   // enqueue                 - O(1)
Integer head   = q.peek();    // peek front              - O(1), returns null if empty
Integer polled = q.poll();    // dequeue                 - O(1), returns null if empty (prefer over remove())
boolean empty  = q.isEmpty(); // check empty             - O(1)
int size       = q.size();    // size                    - O(1)
```

---

## 6. Pair / Tuple
> Java has no built-in `Pair`. These are your options, ranked for CP use.

---

### Option 1: `int[]` - fastest, zero overhead, best for CP

```java
// --- Create ---
int[] pair = new int[]{3, 7};          // allocate pair           - O(1)
List<int[]> pairs = new ArrayList<>();
pairs.add(new int[]{3, 7});            // add to list             - O(1) amortized
pairs.add(new int[]{1, 5});            // add to list             - O(1) amortized
pairs.add(new int[]{3, 2});            // add to list             - O(1) amortized

// --- Access ---
int first  = pair[0];   // read first element      - O(1)
int second = pair[1];   // read second element     - O(1)

// --- Sort ---
pairs.sort((a, b) -> a[0] - b[0]);                                     // by first asc              - O(n log n)
pairs.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);      // by first, then second     - O(n log n)
pairs.sort((a, b) -> Integer.compare(b[0], a[0]));                     // by first desc             - O(n log n)
// Use Integer.compare() / Long.compare() when values may overflow int subtraction
```

---

### Option 2: `record` (Java 16+) - clean and type-safe

```java
// --- Define (once, outside method) ---
record Pair<A, B>(A first, B second) {}

// --- Create ---
Pair<Integer, Integer> pair = new Pair<>(3, 7);  // allocate pair          - O(1)
List<Pair<Integer, Integer>> pairs = new ArrayList<>();
pairs.add(new Pair<>(3, 7));                      // add to list            - O(1) amortized
pairs.add(new Pair<>(1, 5));                      // add to list            - O(1) amortized
pairs.add(new Pair<>(3, 2));                      // add to list            - O(1) amortized

// --- Access ---
int first  = pair.first();   // read first component   - O(1)
int second = pair.second();  // read second component  - O(1)

// --- Sort ---
pairs.sort(Comparator.comparingInt(Pair::first));                                           // by first asc                - O(n log n)
pairs.sort(Comparator.comparingInt(Pair::first).reversed());                                // by first desc               - O(n log n)
pairs.sort(Comparator.comparingInt(Pair::first).thenComparingInt(Pair::second));            // by first asc, then sec asc  - O(n log n)
pairs.sort(Comparator.comparingInt(Pair::first).thenComparingInt(Pair::second).reversed()); // both desc                   - O(n log n)
```

---

### Option 3: `Map.Entry` - no class needed, but verbose

```java
// --- Create ---
Map.Entry<Integer, Integer> pair = Map.entry(3, 7);  // allocate entry        - O(1)
List<Map.Entry<Integer, Integer>> pairs = new ArrayList<>();
pairs.add(Map.entry(3, 7));                           // add to list           - O(1) amortized
pairs.add(Map.entry(1, 5));                           // add to list           - O(1) amortized
pairs.add(Map.entry(3, 2));                           // add to list           - O(1) amortized

// --- Access ---
int first  = pair.getKey();    // read key             - O(1)
int second = pair.getValue();  // read value           - O(1)

// --- Sort ---
pairs.sort(Map.Entry.comparingByKey());                                              // by key asc                - O(n log n)
pairs.sort(Map.Entry.<Integer, Integer>comparingByKey().reversed());                 // by key desc               - O(n log n)
pairs.sort(Map.Entry.comparingByKey(Comparator.comparingInt(k -> k)));               // by key asc (explicit)     - O(n log n)
pairs.sort(Map.Entry.<Integer, Integer>comparingByKey()
           .thenComparing(Map.Entry.comparingByValue()));                             // by key, then value        - O(n log n)
```

---

## 7. Arrays Utilities

```java
import java.util.Arrays;

int[] a = {3, 1, 4, 1, 5};

// Sorting
Arrays.sort(a);                             // sort primitive array asc      - O(n log n)
Arrays.sort(a, 0, 3);                       // sort subarray [0, 3)          - O(k log k), k = range size

// Reverse sort requires boxed Integer[], NOT int[]
Integer[] b = {3, 1, 4};
Arrays.sort(b, Comparator.reverseOrder());  // sort desc                     - O(n log n)
Arrays.sort(b, (x, y) -> y - x);           // sort desc (same effect)       - O(n log n)

// Copying
int[] copy  = Arrays.copyOf(a, a.length);      // full copy                 - O(n)
int[] range = Arrays.copyOfRange(a, 1, 4);     // partial copy [1, 4)       - O(k), k = range size

// Fill
Arrays.fill(a, 0);                              // fill entire array         - O(n)
int[][] matrix = new int[3][4];
for (int[] row : matrix) Arrays.fill(row, -1); // fill 2D array             - O(n*m)

// Binary search (array must be sorted first)
int idx = Arrays.binarySearch(a, 4);        // binary search                - O(log n), returns negative if not found

// Debug printing
System.out.println(Arrays.toString(a));          // print 1D array           - O(n)
System.out.println(Arrays.deepToString(matrix)); // print 2D array           - O(n*m)
```

---

## 8. Collections Utilities

```java
import java.util.Collections;

List<Integer> list = new ArrayList<>(Arrays.asList(3, 1, 2));

Collections.sort(list);                            // sort asc                - O(n log n)
Collections.sort(list, Comparator.reverseOrder()); // sort desc               - O(n log n)
Collections.reverse(list);                         // reverse in-place        - O(n)
Collections.shuffle(list);                         // random shuffle          - O(n)
Collections.swap(list, 0, 1);                      // swap two elements       - O(1)
Collections.fill(list, 0);                         // fill with value         - O(n)

int min  = Collections.min(list);                  // find minimum            - O(n)
int max  = Collections.max(list);                  // find maximum            - O(n)
int freq = Collections.frequency(list, 3);         // count occurrences of 3  - O(n)

// Binary search (list must be sorted first)
int idx = Collections.binarySearch(list, 2);       // binary search           - O(log n), returns negative if not found

// Immutable list of n copies (useful for initialization)
List<Integer> zeros = new ArrayList<>(Collections.nCopies(5, 0)); // O(n)
```

---

## 9. Frequency Counting with `HashMap`

```java
import java.util.HashMap;
import java.util.Map;

Map<String, Integer> freq = new HashMap<>();

// Increment count
freq.merge("apple", 1, Integer::sum);                  // increment by 1          - O(1) average
freq.put("apple", freq.getOrDefault("apple", 0) + 1); // increment by 1          - O(1) average (explicit form)

// Read count
int c = freq.getOrDefault("apple", 0);                 // get count (0 if absent) - O(1) average

// Decrement / remove
freq.merge("apple", -1, Integer::sum);                 // decrement by 1          - O(1) average
freq.remove("apple");                                   // remove key entirely     - O(1) average
```

---

## 10. StringBuilder

```java
StringBuilder sb = new StringBuilder();
sb.append("hello");            // append string          - O(k) amortized, k = length of appended string
sb.append(' ');                // append char            - O(1) amortized
sb.insert(0, "prefix");        // insert at index        - O(n) (shifts all chars right)
sb.deleteCharAt(0);            // delete one char        - O(n) (shifts chars left)
sb.delete(0, 3);               // delete range [0, 3)    - O(n) (shifts chars left)
sb.reverse();                  // reverse in-place       - O(n)
sb.setCharAt(1, 'z');          // overwrite one char     - O(1)
char c   = sb.charAt(1);       // read one char          - O(1)
int len  = sb.length();        // current length         - O(1)
String result = sb.toString(); // convert to String      - O(n)
```

---

## 11. Set Variants

```java
import java.util.HashSet;
import java.util.TreeSet;
import java.util.LinkedHashSet;

// HashSet - unordered, backed by hash table
Set<String> hs = new HashSet<>();
hs.add("a");                    // insert               - O(1) average
boolean has = hs.contains("a"); // membership test      - O(1) average
hs.remove("a");                 // delete               - O(1) average
int size = hs.size();           // size                 - O(1)

// TreeSet - sorted (red-black tree)
TreeSet<Integer> ts = new TreeSet<>();
ts.add(5);                               // insert               - O(log n)
ts.add(2);                               // insert               - O(log n)
ts.add(9);                               // insert               - O(log n)
boolean hasFive = ts.contains(5);        // membership test      - O(log n)
Integer smallest  = ts.first();          // smallest element     - O(log n)
Integer largest   = ts.last();           // largest element      - O(log n)
Integer floor     = ts.floor(6);         // largest element <= 6 - O(log n)
Integer ceiling   = ts.ceiling(6);       // smallest element >= 6- O(log n)
Integer lower     = ts.lower(5);         // largest element < 5  - O(log n)
Integer higher    = ts.higher(5);        // smallest element > 5 - O(log n)
ts.remove(5);                            // delete               - O(log n)
int tsSize = ts.size();                  // size                 - O(1)

// LinkedHashSet - insertion-ordered, backed by hash table + linked list
Set<String> ins = new LinkedHashSet<>();
ins.add("b");                   // insert (preserves order) - O(1) average
ins.add("a");                   // insert (preserves order) - O(1) average
ins.contains("a");              // membership test          - O(1) average
ins.remove("a");                // delete                   - O(1) average
int insSize = ins.size();       // size                     - O(1)
```

---

## 12. Map Variants

### Unordered (`HashMap`)

```java
import java.util.HashMap;
import java.util.Map;

Map<String, Integer> hm = new HashMap<>();
hm.put("x", 1);                        // insert / overwrite      - O(1) average
int val  = hm.getOrDefault("x", 0);    // get (with default)      - O(1) average
boolean has = hm.containsKey("y");     // key existence test      - O(1) average
hm.remove("x");                        // delete by key           - O(1) average
hm.putIfAbsent("z", 3);               // insert only if absent   - O(1) average
hm.computeIfAbsent("z", k -> 42);     // compute value if absent - O(1) average
int hmSize = hm.size();                // size                    - O(1)
```

### Sorted (`TreeMap`)

```java
import java.util.TreeMap;
import java.util.Map;

TreeMap<Integer, Integer> tm = new TreeMap<>();
tm.put(1, 10);                       // insert / overwrite        - O(log n)
tm.put(3, 30);                       // insert / overwrite        - O(log n)
tm.put(5, 50);                       // insert / overwrite        - O(log n)

int v = tm.getOrDefault(1, 0);       // get (with default)        - O(log n) (get() can return null -> NPE)
tm.putIfAbsent(2, 20);               // insert only if absent     - O(log n)
boolean tmHas = tm.containsKey(3);   // key existence test        - O(log n)

// Closest-key operations - all O(log n)
Integer floorKey   = tm.floorKey(4);      // largest key <= 4        - O(log n) -> 3
Integer ceilingKey = tm.ceilingKey(4);    // smallest key >= 4       - O(log n) -> 5
Integer lowerKey   = tm.lowerKey(3);      // largest key < 3         - O(log n) -> 1
Integer higherKey  = tm.higherKey(3);     // smallest key > 3        - O(log n) -> 5

Map.Entry<Integer, Integer> floorEntry   = tm.floorEntry(4);   // entry with largest key <= 4    - O(log n)
Map.Entry<Integer, Integer> ceilingEntry = tm.ceilingEntry(4); // entry with smallest key >= 4   - O(log n)

Integer firstKey = tm.firstKey();    // smallest key              - O(log n)
Integer lastKey  = tm.lastKey();     // largest key               - O(log n)
tm.remove(1);                        // delete by key             - O(log n)
int tmSize = tm.size();              // size                      - O(1)
```

### Multimap (JDK-only - Map to List)

```java
Map<String, List<String>> mm = new HashMap<>();
mm.computeIfAbsent("k1", k -> new ArrayList<>()).add("v1"); // computeIfAbsent: O(1) average; ArrayList.add: O(1) amortized
mm.computeIfAbsent("k1", k -> new ArrayList<>()).add("v2"); // computeIfAbsent: O(1) average; ArrayList.add: O(1) amortized

List<String> vals = mm.getOrDefault("k1", List.of()); // HashMap.getOrDefault: O(1) average
mm.get("k1").remove("v1");                            // HashMap.get: O(1) average; ArrayList.remove by object: O(n)
```

---

## 13. Min-Heap (`PriorityQueue`)

```java
import java.util.PriorityQueue;

PriorityQueue<Integer> minHeap = new PriorityQueue<>(); // min-heap by default
minHeap.offer(5);  // insert                  - O(log n)
minHeap.offer(1);  // insert                  - O(log n)
minHeap.offer(3);  // insert                  - O(log n)

Integer top    = minHeap.peek();    // read minimum (no remove)  - O(1),     returns null if empty
Integer polled = minHeap.poll();    // remove and return minimum - O(log n), returns null if empty
int size       = minHeap.size();    // size                      - O(1)
boolean empty  = minHeap.isEmpty(); // check empty               - O(1)
```

---

## 14. Max-Heap (`PriorityQueue` reversed)

```java
import java.util.PriorityQueue;
import java.util.Comparator;

PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
maxHeap.offer(5);  // insert                  - O(log n)
maxHeap.offer(1);  // insert                  - O(log n)
maxHeap.offer(3);  // insert                  - O(log n)

Integer max     = maxHeap.peek();    // read maximum (no remove)  - O(1),     returns null if empty
Integer removed = maxHeap.poll();    // remove and return maximum - O(log n), returns null if empty
int size        = maxHeap.size();    // size                      - O(1)
boolean empty   = maxHeap.isEmpty(); // check empty               - O(1)
```

---

## 15. PriorityQueue with Pairs / Custom Objects

```java
// Min-heap by first element of int[2] - classic Dijkstra pattern
// (dist and node are placeholder variable names)
PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
pq.offer(new int[]{dist, node}); // insert {dist, node}       - O(log n)
int[] top = pq.poll();           // remove min-dist entry     - O(log n) - top[0] = dist, top[1] = node

// If values can overflow int (e.g. long distances), use Long.compare:
PriorityQueue<long[]> pq2 = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
pq2.offer(new long[]{dist, node}); // insert {dist, node}     - O(log n) - same placeholder names, now long

// Custom class comparator
// For reference types, prefer Comparator.comparingInt (avoids boxing):
PriorityQueue<Person> pq3 = new PriorityQueue<>(Comparator.comparingInt(p -> p.age));
PriorityQueue<Person> pq4 = new PriorityQueue<>(Comparator.comparingInt((Person p) -> p.age).reversed());

Person person = new Person("Alice", 30); // placeholder - replace with your actual object
pq3.offer(person);               // insert by age asc         - O(log n)
pq4.offer(person);               // insert by age desc        - O(log n)
```

---

## 16. Monotonic Deque (Sliding Window Max/Min)

```java
import java.util.ArrayDeque;
import java.util.Deque;

int[] a = {1, 3, -1, -3, 5, 3, 6, 7};
int k = 3; // window size
int n = a.length;
int[] windowMax = new int[n - k + 1];

Deque<Integer> dq = new ArrayDeque<>(); // stores indices

// Overall algorithm: O(n) - each index is added and removed at most once
for (int i = 0; i < n; i++) {
    while (!dq.isEmpty() && dq.peekFirst() < i - k + 1) dq.pollFirst();  // remove out-of-window front - O(1) amortized
    while (!dq.isEmpty() && a[dq.peekLast()] <= a[i])   dq.pollLast();   // maintain decreasing order  - O(1) amortized (flip <= to >= for min)
    dq.offerLast(i);                                                       // append new index           - O(1)
    if (i >= k - 1) windowMax[i - k + 1] = a[dq.peekFirst()];            // read window max from front - O(1)
}
```

---

## 17. Bitset

> Java's `BitSet` is dynamic (grows as needed), unlike C++'s fixed-size `std::bitset<N>`.

```java
import java.util.BitSet;

BitSet bs = new BitSet(128);    // allocate with capacity hint (grows if needed)

bs.set(2);                      // set single bit              - O(1)
bs.set(10, 20);                 // set bits [10, 20)           - O(k), k = range size
boolean bit2 = bs.get(2);       // read single bit             - O(1)
bs.clear(2);                    // clear single bit            - O(1)
bs.flip(5);                     // toggle single bit           - O(1)

int count = bs.cardinality();   // popcount across all words   - O(n/64), n = highest set bit

// Iterate set bits
for (int i = bs.nextSetBit(0); i >= 0; i = bs.nextSetBit(i + 1)) {
    // process bit i                                           // O(n/64) per nextSetBit call in worst case
}

// Bitwise ops (in-place, modify bs)
BitSet other = new BitSet();
other.set(10);                  // set single bit              - O(1)
bs.and(other);                  // bs &= other                 - O(max(bs.size(), other.size()) / 64)
bs.or(other);                   // bs |= other                 - O(max(bs.size(), other.size()) / 64)
bs.xor(other);                  // bs ^= other                 - O(max(bs.size(), other.size()) / 64)

int highestPlusOne = bs.length(); // index of highest set bit + 1 (0 if empty) - O(1)
bs.clear();                       // clear all bits              - O(n/64)
```

---

## 18. BigInteger

> **Immutable** - all operations return new objects. Significantly slower than `long`; use only when precision is required.

```java
import java.math.BigInteger;
import java.security.SecureRandom;

BigInteger a = BigInteger.valueOf(123456789L);          // from long literal      - O(1)
BigInteger b = new BigInteger("9876543210123456789");   // from decimal string    - O(n), n = digits
BigInteger c = new BigInteger("deadbeef", 16);          // from hex string        - O(n), n = digits

// n = number of bits in the operands
// Arithmetic
BigInteger sum  = a.add(b);             // addition                - O(n)
BigInteger diff = b.subtract(a);        // subtraction             - O(n)
BigInteger prod = a.multiply(b);        // multiplication          - O(n^1.585) Karatsuba
BigInteger[] dr = b.divideAndRemainder(a);  // quotient + remainder- O(n^2) - dr[0]=quotient, dr[1]=remainder
BigInteger mod  = b.mod(a);             // b % a (a must be > 0)  - O(n^2)
BigInteger modPow = a.modPow(BigInteger.valueOf(7), BigInteger.valueOf(1000)); // a^7 % 1000 - O(log(exp) * n^2)

// Comparison & GCD
BigInteger g   = a.gcd(b);             // GCD                     - O(n^2)
int        cmp = a.compareTo(b);       // compare (-1, 0, or 1)   - O(n)
boolean    eq  = a.equals(b);          // equality check           - O(n)

// Bit operations
BigInteger sl   = a.shiftLeft(10);     // a * 2^10                - O(n)
BigInteger sr   = a.shiftRight(3);     // a / 2^3 (floor)         - O(n)
boolean    bit2 = a.testBit(2);        // read single bit          - O(1)
BigInteger set5 = a.setBit(5);         // set bit 5               - O(n) (returns new object)

// Conversion
String decimal = b.toString();         // to decimal string        - O(n^2) (base conversion is expensive)
String hex     = b.toString(16);       // to hex string            - O(n)   (word-by-word formatting)
byte[] bytes   = a.toByteArray();      // to byte array            - O(n)

// Primality
BigInteger prime = BigInteger.probablePrime(128, new SecureRandom()); // O(k * n^2), k = certainty rounds
boolean isPrime  = prime.isProbablePrime(100); // Miller-Rabin        - O(k * n^2), k = 100 rounds here

// Constants
BigInteger ZERO = BigInteger.ZERO;
BigInteger ONE  = BigInteger.ONE;
BigInteger TWO  = BigInteger.TWO;
```
