### Install with development
```
npm install
```

### Install with production
```
npm install --production
// or
npm install --omit=dev
```

### Show outdated packages
```
npm outdated
```

### Update packages [npm version 5.0.0^] (minor and patch only)
```
npm update
```

### Update packages (major)

1. pre-requisite tool - (install once)
    ```
    npm install -g npm-check-updates
    ```

2. upgrade all version hints in ```package.json```
    ```
    ncu -u
    ```

3. install major updates
    ```
    npm install
    ```
    
### Update globally installed packages (minor and patch)
```
sudo npm update -g
```
ommit `sudo` if node and npm is not installed in a write protected directory.
    
### Update globally installed packages (major)
```
sudo npm update -g
sudo npm install -g npm@8.15.0
```
    
