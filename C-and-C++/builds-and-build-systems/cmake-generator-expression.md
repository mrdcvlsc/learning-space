# **CMAKE GENERATOR EXPRESSION**

### Get Target Build Directory

Usually targets are the first argument of `add_library` and `add_executable`
(maybe `ExternalProject_Add` and `FetchContent_Declare` too)

```cmake
$<TARGET_FILE_DIR:TARGET_NAME>
```

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
