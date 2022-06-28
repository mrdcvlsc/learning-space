**Set User and Email**
```
git config --global user.name "yourUserName"
git config --global user.email "yourEmail@whatever.com"
```

**Unset global config variables**
```
git config --global --unset user.name
git config --global --unset user.email
```

**Display Global Configs Variables**
```
git config -l
```

**Display status of current branch**
```
git status
```

**Display local branch**
```
git branch
```

**Display all branch even on remote repository**
```
git branch -a
```

**Switch to a branch**
```
git checkout NewBranchName
```

**Create a new branch using the current branch you're currently in**
```
git checkout -b NewBranchName
```

**Local changes are reapplied on top of the remote changes.**
```
git pull --rebase
```
