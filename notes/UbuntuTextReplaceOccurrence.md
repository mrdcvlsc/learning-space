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
