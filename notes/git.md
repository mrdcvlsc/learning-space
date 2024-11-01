## Git User

- **Set User and Email**

  ```bash
  git config --global user.name "yourUserName"
  git config --global user.email "yourEmail@whatever.com"
  ```

- **Cache the next git user and password (in-memory)**
  
  ```bash
  git config --global credential.helper cache --timeout=<seconds>
  ```
 
- **Cache the next git user and password (disk)**
  
  ```bash
  git config --global credential.helper store
  ```

- **Unset user and password cache credentials**
  
  ```bash
  git config --global --unset credential.helper
  ```

## Git Variables

- **Unset global config variables**
  ```bash
  git config --global --unset user.name
  git config --global --unset user.email
  ```

- **Display Global Configs Variables**
  
  ```bash
  git config -l
  ```
  
- **Edit Git Global Config Variables**
  
  ```bash
  git config --global --edit
  ```

## Branches

- **Display status of current branch**
  
  ```bash
  git status
  ```

- **Display local branch**
  
  ```bash
  git branch
  ```

- **Display all branch even on remote repository**
  ```bash
  git branch -a
  ```
  
- **Push all branches**
  
  ```bash
  git push <remote-name> --all
  ```

- **Switch to a branch**
  
  ```bash
  git checkout NewBranchName
  ```

- **Create a new branch using the current branch you're currently in**
  
  ```bash
  git checkout -b NewBranchName
  ```
  
- **Create a new branch from a commit**
  ```bash
  git log
  git branch <branch-name> <identifier>
  ```

- **Create a new EMPTY branch**

  ```bash
  git switch --orphan <new-branch-name>
  git commit --allow-empty -m "new empty branch"
  git push -u origin <new-branch-name>
  ```
    
- **Download a branch from a remote**
  
  ```bash
  git checkout -t <remote-name>/<branch-name>
  ```
  
- **Delete branch locally**
  ```bash
  git branch -d <branch-name>
  git branch -D <branch-name>
  ```
  - The `-d` option is an alias for `--delete`, which only deletes the branch if it has already been fully merged in its upstream branch.
  - The `-D` option is an alias for `--delete --force`, which deletes the branch "irrespective of its merged status." [Source: man git-branch]

## Pulls

- **Remote changes are applied**
  ```bash
  git pull
  ```

- **Local changes are reapplied on top of the remote changes.**
  ```bash
  git pull --rebase
  ```
  
## Commits

- **Commit changes**

  use when writing a more detailed commit message
  ```bash
  git commit
  ```
  
- **Commit changes directly**

  use for simple commits that only requires a commit message, and no further information
  ```bash
  git commit -m <the-commit-message>
  ```
  
- **Go back to a certain commit (for specific files)**

  ```bash
  git checkout <commit-hash> -- file1/to/restore file2/to/restore
  ```

- **Go back to a certain commit**

  this will make the `commit hash` as the current head, and remove anything above it
  ```bash
  git reset --hard <commit-hash>
  ```

  After resetting to a certain commit, you might want to force push it to a repo if that repo also contains all the commits ahead in your local repo.
  ```bash
  git push --force
  ```
  
- **Edit a recent commit's message (locally)**
  ```bash
  git commit --amend
  ```
  
- **Edit a recent commit's message (pushed in a repo)**
  ```bash
  git commit --amend
  git push --force-with-lease <remote-name> <branch-name>
  // <remote-name> and <branch-name> are optional
  ```

- **Edit the history of the next following commits after a selected base commit**
  
  This will prompt an interactive shell where you can edit **all (up to `HEAD` commit)**
  of the **following commits** after the chosen base commit, the shell will let you pick
  which commits do you want to edit.

  _the `<base-commit-hash>` is not included_

  ```bash
  git rebase -i <base-commit-hash>
  ```

  After entering the command above and picking the actions you want to do for each commits,
  it will **reset** your files to the state of the **next** commit (`<next-commit-hash>`)
  after the `<base-commit-hash>` that was given.

  Now you can edit the `<next-commit-hash>` by amending changes in either
  or both the code or commit message (see amend section):

  1. If you only edited the commit message you will not have any
     problems after using `git rebase --continue`.
     
  2. But if you edited files or code during amending you might encounter (but not everytime)
     conflicts after using `git rebase --continue` so you will need to fix it.

- **Fixing conflict after `rebase --continue`**

  After using `git rebase --continue` if there are conflicts, it will show what
  is the next incoming commit that cannot be applied due to differences in the file/code.

  example:

  ```bash
  Auto-merging text.txt
  CONFLICT (content): Merge conflict in text.txt
  error: could not apply 7928385... Some Random Commit Message Of Commit 7928385
  hint: Resolve all conflicts manually, mark them as resolved with
  hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
  hint: You can instead skip this commit: run "git rebase --skip".
  hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
  Could not apply 7928385... Some Random Commit Message Of 7928385
  ```

  At this point you need to edit the source code or files where the conflict happens, one
  way to see the code where the conflict occured is by using `git diff` :

  ```bash
  git --diff

  # output
  
  diff --cc text.txt
  index 53681c6,13e34e5..0000000
  --- a/text.txt
  +++ b/text.txt
  @@@ -1,3 -1,4 +1,8 @@@
    initial commit
    1st first additional commit
  ++<<<<<<< HEAD
   +2nd second additional commit corrected line of code (amended)
  ++=======
  + 2nd second additional change - a wrong line of code (initially wrong code)
  + 3rd
  ++>>>>>>> 7928385 (Some Random Commit Message Of 7928385)
  ```

  The above output is how conflicts are structured/annotated in the source code, here you
  will be able to see the structure of the conflicting code in the section of the **incoming
  changes** `7928385 (Some Random Commit Message Of 7928385)` below the `++=======` line.
  Above it is the auto-merge's new **current changes** which are the conflicting code that
  arised due to our amends earlier.

  Some IDE and Editors will have a quick button to either:
  
  - `Accept Only The Current Changes` - (`+<<<<<<<`)
  - `Accept Only The Incoming Changes` - (`++>>>>>>>`)
  - `Accept Both The Current and Incoming Changes`

  But you can always edit it youself manually, for example:

  **Opened From Text Editor: From:**
  
  ```bash
  <<<<<<< HEAD
  2nd second additional commit corrected line of code (amended)
  =======
  2nd second additional change - a wrong line of code (initially wrong code)
  3rd
  >>>>>>> 7928385 (3rd)
  ```

  **Opened From Text Editor: Fixed Manually (Edited and Saved):**

  Just remove the conflict annotations and choose which line of code
  you want to keep from the incoming change `7928385`.

  ```bash
  2nd second additional commit corrected line of code (amended)
  3rd
  ```

  In short, you just want to fix the code to look the way you want
  after committing `7928385`, or how you want the code to appear as
  the result of committing `7928385`.

  After that just stage the fix-changes you applied.`

  ```bash
  git add .
  ```

  Then after staging the fix-changes can continue the rebase step with:

  ```bash
  git rebase --continue
  ```

  If there are more conflicts ahead just repeat this process.

  These following commands might help you to get more info when fixing conflicts:

  - `git diff` and `git diff --cached`
  - `git status`
  - `git log`

## Stages

- **Stage (add) the new edited files**
- 
  ```bash
  git add <files>...
  ```

- **Unstage (remove) the added files when the git `add` command was used**
- 
  ```bash
  git restore --staged <file>...
  ```
  
- **Show staged file changes**
- 
  ```bash
  git diff --cached
  ```

## Remote

- **Show remote repository `<remote-name>` and `<url>`**
- 
  ```bash
  git remote
  git remote -v
  ```

- **Add a remote repository**
- 
  ```bash
  git remote add <remote-name> <url>
  ```

- **Remove a remote repository**
- 
  ```bash
  git remote remove <remote-name>
  ```

# Submodules

- **add a submodule in a repo**
- 
  ```bash
  git submodule add <url>
  ```

- **after cloning a repo with submodules**
  
  ```bash
  git submodule update --init --recursive
  ```

- **updating a repo with the latest changes to submodules**

  ```bash
  git submodule update --recursive --remote
  ```

# Dot Character

use to denote `<all files>` instead of just selecting a specific file name.

Example, to add all changes:

```bash
git add .
```

# Merge Vs Rebase

- (`feature` -> `main`) merge is mostly used for bringing new commits from feature branch to master/main branch
- (`main` -> `feature`) rebase is mostly used for bringing new commits from master/main branch to a feature branch

- **Merge branch**

  _This operation stacks the incoming feature branch commits on top of the existing commit history of the main branch._

  ```bash
  git checkout <main-branch>
  git merge <feature-branch>
  ```

- **Rebase branch**

  _This operation temporarily removes the current feature branch commits, stacks the new incoming commits from the main branch on top of the feature branch history, and then restacks the current feature branch commits back._

  ```bash
  git checkout <feature-branch>
  git rebase <main-branch>
  ```

# Tags

- **List all of the tags**

  ```bash
  git tag -l
  ```

- **Delete a local Git tag**

  ```bash
  git tag -d <tag-name>
  ```

- **Create a local Git tag**

  ```bash
  git tag <tag-name>
  ```

- **Create a local annotated tag**

  ```bash
  git tag <tag-name> -a
  ```

- **Push all local tag**

  ```bash
  git push <remote-name> --tags
  ```

- **Push a specific local tag**

  ```bash
  git push <remote-name> <tag-name>
  ```

- **Checkout a tag**

  ```bash
  git checkout tags/<tag-name>
  ```

## Stash

Reminder: [git stash is not branch specific](https://stackoverflow.com/questions/20526355/is-git-stash-branch-specific-or-for-the-whole-repository) but for the whole repo.

- **Stash changes for later use**

  _untracked files not included_

  ```bash
  git stash
  ```

- **Stash changes and untracked files**

  ```bash
  git stash -u
  ```

- **Re-apply/Get back changes inside the stash**

  ```bash
  git stash pop
  ```

- **Working with multiple stashes: Show Stash Stack**
  
  _yes stashed changes is stored in a stack, the command
  below will list all of the stashes along with it's index._

  ```bash
  git stash list
  ```

- **Working with multiple stashes: Get a Specific Stash**

  ```bash
  git stash apply stash@{<stash-index-number>}
  git stash drop stash@{<stash-index-number>}
  // or
  git stash pop stash@{<stash-index-number>}
  ```

- **Stash some specific file changes from another branch**
  
  ```bash
  git checkout <main-branch>
  git checkout <another-branch> -- <file>
  ```
