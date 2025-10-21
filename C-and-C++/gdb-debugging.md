# Debugging using GDB

### Compile
compile with "-g" or "g3"

### Display Assembly

```bash
layout asm
```

### Display Code and Assembly

```bash
layout split
```


### Display Code
```bash
layout next
l
```

### Run Code

```bash
run
# or
r
```

### Run Code with Standard Input

store your input in a input.txt file.

```bash
run < input.txt
```

### Add Break Point

```bash
b <line-number or variable-or-function-name>
```

### Display Break Points

```bash
info break
```

### Step through the code (go inside of functions)

```bash
s <optional-number-of-steps>
```

### Next Line of Code (does not go inside functions)

```bash
n <optional-number-of-next-lines>
```

### Next Assembly Instruction (does not go inside functions)

```bash
nexti <optional-number-of-next-lines>
```

### Print a Variable

(works with function calls too?)

```bash
print <variable-name-of-code>
```

if output is `0x0` then there is no value / null

### Print Array Memory Addresses

```bash
print ptr@element-size
```

you could also print std::vector to see its value `print vec_name`, and even call the methods of std::vector and see the result `print vec_name.size()`.

I don't know if this extends to other classes and stl type or maybe even your own class or type, but it's free to try.

### Print Array Values
 
```bash
print *ptr@element-size
```

### Watch a Variable

It prints automatically the watch variables

```bash
watch <variable-name-of-code>
```

### Change variable value

```bash
set args 4
set <variable-name> <value>

### Continue a Running Program Until Next Error or Break Point

```bash
c
```

### Print all function call

```bash
backtrace full
```

### Refresh the Screen if the design broke

```bash
refresh
```

### Quit

```bash
quit
```
