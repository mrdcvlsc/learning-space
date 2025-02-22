# Accidental Purge

I recently accidentally purge a specific package in ubuntu that also removed other packages that depends on it,
I quickly canceled the process when I found that it was removing OS specific packages with `ctrl+z` (`ctrl+c` is not working), then I use the following
commands below to try to bring back the purged packages.

```bash
# kill if there's a process being held
sudo kill -9 <pid>
sudo kill -1 <pid>
```

```bash
# look at the last packages that was purged
grep "remove " /var/log/dpkg.log | tail -150

# find the packages that was purged then manually install them back and pray

# example: reinstall desktop
sudo apt install lubuntu-desktop
```
