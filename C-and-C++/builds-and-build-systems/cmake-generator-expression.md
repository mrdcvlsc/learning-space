# **CMAKE GENERATOR EXPRESSION**

### Equality

Returns `TRUE` if arguments are equal and `FALSE` if not.

```cmake
# Format
$<EQUAL:ARG1, ARG2>

# Example - check if pointer size is equal to 8 to determine architecture 8 = 64bit, 4 = 32bit
$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>
```

### If Conditions

Returns `VALUE_IF_TRUE` or `VALUE_IF_FALSE` depending on the `BOOL` argument.

```cmake
# Format
$<IF:BOOL, VALUE_IF_TRUE, VALUE_IF_FALSE>

# Example
$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>
```
