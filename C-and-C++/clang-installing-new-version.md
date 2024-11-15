# installing New Clang Version In Ubuntu

In some cases, a simple `update` and `upgrade` is sufficient.
However sometimes with Clang, running `update` and `upgrade` might not
install the latest version. This guide is for those situations
where additional steps are needed to ensure you have the latest Clang version.

### Remove old Clang installations (depending on the version)

```bash
sudo apt-get purge llvm clang

# Specifying the version may be better
sudo apt-get purge llvm-<version> clang-<version>

# Example:
sudo apt-get purge llvm-3.2 clang-3.2

# Then lastly
sudo apt autoremove
```

### Verify that Clang is not installed

```bash
clang --version    # Should not work
clang++ --version  # Should also not work
```

### Download the Clang installation script

```bash
wget https://apt.llvm.org/llvm.sh
chmod u+x llvm.sh
```

### Run the Clang installation script

```bash
# Install the latest version
sudo ./llvm.sh

# Alternatively, specify a version to install:
sudo ./llvm.sh <new-selected-version>

# Example:
sudo ./llvm.sh 17
```

### Get the path of the installed Clang binary

```bash
which clang-<new-selected-version>

# Example:
which clang-17
```

Output:

```bash
/usr/bin/clang-17
```

### Locate the main binary of the installed Clang using the output from `which`

```bash
ls -l /usr/bin/clang-17
```

Output:

```bash
lrwxrwxrwx 1 root root XX XXX XX XXXX /usr/bin/clang-17 -> ../lib/llvm-17/bin/clang
```

This indicates the main binary path is `/usr/lib/llvm-17/bin/clang`.

### Confirm the binary is the actual Clang executable

```bash
ls -l /usr/lib/llvm-17/bin/clang
```

If the output does not start with `l`, as shown below, it confirms this is the Clang main binary:

```bash
-rwxr-xr-x 1 root root XX XXX XX XXXX /usr/lib/llvm-17/bin/clang
```

### Create a new symbolic link for Clang

```bash
sudo ln -s /usr/lib/llvm-17/bin/clang /usr/bin/clang 
sudo ln -s /usr/lib/llvm-17/bin/clang /usr/bin/clang++
```

### Restart the PC, then verify the installation

```bash
clang --version
```

### Something is weird?

You might wonder why we link both `clang` (the C compiler) and `clang++` (the C++ compiler)
to the same Clang binary. The reason is that Clang determines its behavior based on the
program's name (`argv[0]`). If the executable is named `clang` (without `++`),
the binary behaves as a C compiler. On the other hand, if the executable is named `clang++`,
it operates as a C++ compiler. This naming convention allows a single binary to serve both purposes.
