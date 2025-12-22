# Computer Troubleshooting

## Memory Tests

### Using `Windows Memory Diagnostic` (windows specific)

1. Find `Windows Memory Diagnostics` program by searching in the start panel.
2. Click `Restart now and check for problems`.
3. F1 to choose options.
4. Select `Extended` and you could also test the cache (this could take some time), F10 to apply.
5. view result in `Event Viewer` > `Windows Logs` > `System` > `Filter Current Log` > filter `Event sources: MemoryDiagnostics-Results`.
