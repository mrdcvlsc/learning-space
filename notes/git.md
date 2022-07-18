## Git User

- **Set User and Email**
  ```
  git config --global user.name "yourUserName"
  git config --global user.email "yourEmail@whatever.com"
  ```

- **Cache the next git user and password**
  ```
  git config --global credential.helper cache
  ```

- **Unset user and password cache credentials**
  ```
  git config --global --unset credential.helper
  ```

## Git Variables

- **Unset global config variables**
  ```
  git config --global --unset user.name
  git config --global --unset user.email
  ```

- **Display Global Configs Variables**
  ```
  git config -l
  ```

## Branches

- **Display status of current branch**
  ```
  git status
  ```

- **Display local branch**
  ```
  git branch
  ```

- **Display all branch even on remote repository**
  ```
  git branch -a
  ```

- **Switch to a branch**
  ```
  git checkout NewBranchName
  ```

- **Create a new branch using the current branch you're currently in**
  ```
  git checkout -b NewBranchName
  ```

## Pulls

- **Remote changes are applied**
  ```
  git pull
  ```

- **Local changes are reapplied on top of the remote changes.**
  ```
  git pull --rebase
  ```
  
## Commits

- **Go back to a certain commit, this will make the `commit hash` as the current head, and remove anything above it**
  ```
  git reset --hard <commit hash>
  ```

## Stages

- **Stage (add) the new edited files**
  ```
  git add <files>...
  ```

- **Unstage (remove) the added files when the git `add` command was used**
  ```
  git restore --staged <file>...
  ```
  
# Dot Character
use to denote `<all files>` instead of just selecting a specific file name.

Example, to add all changes:

```
git add .
```
