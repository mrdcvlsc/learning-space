# Debugging using GDB

---

## Compile with debug symbols

To debug a C/C++ program with gdb, you should compile it with compile with "-g" then open the program using gdb.

---

## Run the program with GDB

Open the program with gdb.

 ```bash
 gdb <program>.exe
 ```

Then run it.

```bash
run
```

You could also run it with standard input,
Fist save the inputs to a file, for example `input.txt`,
then run the program.

```bash
run < input.txt
```

And here's how you run a program with arguments.

```bash
run arg1 arg2 ...  argN
```

---

## Display Modes

Before running the program, you could choose which display you want using the three commands below. 

```bash
# Display Assembly
layout asm

# Display Code and Assembly
layout split

# Display Code
layout next
l
```

---

## Break Points

Breakpoints are where the running program will automatically pause, usually you should display the
source code to see the line number where you want to pause the program.

Here's how you can **add breakpoints** to your program.

```bash
b <line-number or variable-or-function-name>
```

To **show breakpoint** and **watchpoint** numbers use the command below, you could also use `info watch`
for displaying watchpoints only.

```bash
info break
```

---

## Controlling Program Execution

#### Pause the program

just press `ctrl+c`.

usefull when debugging an infinite loop, you could find out why is it happening.

#### `step`

This command executes the next statement. If the next statement is a function call, `step` 
will enter (step into) the function and execute its first line.

```bash
s <optional-number-of-steps>
```

#### `next`

This command also executes the next statement. However, if the next statement is a function call, 
`next` will execute the entire function and then stop at the line immediately following the function
call in the current frame (it **"steps over"** the function).

```bash
n <optional-number-of-next-lines>
```

For assembly level next, use the command below.

```bash
nexti <optional-number-of-next-lines>
```

#### `continue`

This command resumes program execution until a breakpoint is hit, the program terminates, or a 
signal is received that GDB is configured to stop for.

```bash
c
```

#### `finish`

Used to continue the execution of the current function until it returns to its caller. When the 
function returns, GDB will stop execution and display the return value of the function, if applicable.

This command is particularly useful when you are inside a function and want to quickly step out of it
without having to repeatedly use next or step through every line of code within that function.

```
finish
```

---

## Displaying Values and Information

#### Print a Variable using `print` or `p`.

(works with function calls too?)

```bash
print <variable-name-of-code>
```

#### `print`/`display` Formats

```bash
# Display in hexadecimal
p/x <variable>

# Display in binary
p/t <variable>

# Display in signed decimal (default for integers)
p/d <variable>

# Display in unsigned decimal
p/u <variable>

# Display in octal
p/o <variable>

# Display as a character
p/c <variable>
```

See `help x` for more info on the FMT (format) switches.

if output is `0x0` then there is no value / null

#### Print Array Memory Addresses

```bash
print ptr@element-size
```

you could also print std::vector to see its value `print vec_name`, and even call the methods of std::vector and see the result `print vec_name.size()`.

I don't know if this extends to other classes and stl type or maybe even your own class or type, but it's free to try.

#### Print Array Values
 
```bash
print *ptr@element-size
```

#### Watch a Variable

It prints automatically the watch variables

```bash
watch <variable-name-of-code>
```

#### Unwatch

delete breakpoints and watchpoints, use with `info break`

```bash
d <watchpoint-number or breakpoint-number>
```

#### Display

used to automatically show the value of an expression every time the program stops (e.g., at a breakpoint,
after a step, or when a watchpoint is hit). This allows for continuous monitoring of specific variables or
memory locations during debugging.

```bash
display <format> <expression>
```

#### Print all function call

`bt` alone prints a summary of the stack frames. Each line typically includes the frame number, the function name,
and sometimes the line number and source file where the call originated. It provides a concise overview of the call stack.

`bt full` or `backtrace full` provides a more detailed backtrace. In addition to the information provided by the basic `bt`
command, it also prints the values of local variables and function arguments within each stack frame. This can be extremely 
helpful for understanding the state of the program at each step of the call chain.

```bash
backtrace full

# or

bt full
```

---

## Manipulating Values

#### Change variable value

```bash
set args 4
set <variable-name> <value>
```

---

## Working with Threads

#### Display threads

```bash
info threads
```

#### Jump to a thread

```bash
thread <gdb-thread-id-number>
```

#### Scheduler Locking

- `set scheduler-locking off` (default), all threads are allowed to run when the program is resumed,
if another thread hits a breakpoint, GDB will stop all threads and switch to the thread that hit the breakpoint.


- When `set scheduler-locking on` is enabled, GDB ensures that only the currently selected thread 
is allowed to execute when the program is resumed (e.g., using continue, next, step). 
All other threads in the program are prevented from running.

- `set scheduler-locking step`, This mode optimizes for single-stepping. It locks other threads only
during single-stepping operations (like step or next) to prevent them from seizing the prompt by
preempting the current thread. Other threads will rarely get a chance to run when you step,
but they can run during continue.

---

## Others

### Refresh the Screen if the design broke

```bash
refresh
```

### Quit

```bash
quit
```
