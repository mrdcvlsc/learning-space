# Replace Substring Occurrence Commands

## Replace all substring for all text files in a folder (ubuntu)

```bash
cd <target_folder>

# ================ perform a dry run ================
# show matching lines with filenames and line numbers
grep -RIn --color=always 'target-substring' .

# ================ replace all substring ================
# This finds files containing the pattern and runs sed in-place on them.
grep -RIlZ 'target-substring' . | xargs -0 -r sed -i 's/target-substring/NewSubstring/g'
```

If your old or new string contains slashes (/), use a different delimiter, e.g. `sed -i 's|old/string|new/string|g'`.

If you want to limit to certain extensions


```bash
find . -type f \( -name '*.txt' -o -name '*.md' -o -name '*.cpp' -o -name '*.go' \) -print0 \
  | xargs -0 -r grep -IlZ 'target-substring' \
  | xargs -0 -r sed -i 's/target-substring/NewSubString/g'

```
