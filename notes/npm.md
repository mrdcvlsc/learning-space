### Clean Install (mostly use for CI)
```
npm ci
```

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

### Show outdated local packages
```
npm outdated
```

### Update local packages [npm version 5.0.0^] (Minor and Patch only)
```
npm update
```

### Update local packages (Major)

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
    
### Semver Note
**Version number** format `MAJOR.MINOR.PATCH`:

- `MAJOR` version when you make incompatible API changes (`PATCH` and `MINOR` versions MUST be reset to 0 when `MAJOR` version is incremented.).
- `MINOR` version when you add functionality in a backwards compatible manner (`PATCH` version MUST be reset to 0 when `MINOR` version is incremented.).
- `PATCH` version when you make backwards compatible bug fixes.

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
    
### Run locally install npm CLI tool/program
```
npx <tool/program>
```

### Run globally install npm CLI tool/program
```
<tool/program>
```
