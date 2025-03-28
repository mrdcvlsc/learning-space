# VS-Code Keybindings

## File navigation (local)

`Ctrl + G` go to line number

`Alt + PgUp/PgDn` Scroll page up/down

`Ctrl + ↑/↓` Scroll line up/down

`Home/End` Go to beginning/end of **line**

`Ctrl + Home/End` Go to beginning/end of **file**

`Ctrl + Shift + \` Jump to matching bracket

`Alt + Enter` Select all occurences of Find match

## File manipulation

`Alt + ↑/↓` Move line up/down

`Ctrl + ]/[` Indent/outdent line

`Alt + ←` Go Back

`Alt + →` Go Forward

## Formating

`Ctrl + Shift + I` - format with current formatter

## Suggestions / Completion / Hints

`Ctrl + Space`, `Ctrl + I` Trigger suggestion

`Ctrl + Shift + Space` Trigger parameter hints

## All Files Definitions (global)

`F2` Rename Symbols

`F12` Go to Symbol Definition

`Ctrl + F12` Go to Symbol Implementation

`Ctrl + T` Search/Show all Symbols

## Override Keybindings

```json
// keybinding.json

// Place your key bindings in this file to override the defaults:
// Ctrl+P then search Keyboard Shortcuts (JSON) and select it
// copy paste then save this json

[
    {
        "key": "alt+left",
        "command": "workbench.action.navigateBackInEditLocations",
        "when": "canNavigateBackInEditLocations"
    },
    {
        "key": "alt+right",
        "command": "workbench.action.navigateForwardInEditLocations",
        "when": "canNavigateForwardInEditLocations"
    },
    {
        "key": "alt+,",
        "command": "workbench.action.navigateBack",
        "when": "canNavigateBack"
    },
    {
        "key": "alt+.",
        "command": "workbench.action.navigateForward",
        "when": "canNavigateForward"
    }
]
```
