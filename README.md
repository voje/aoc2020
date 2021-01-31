# AOC 2020

Let's go baby!

Weapon of choice: C++

## C++ env
VSCode

Extensions:
* C/C++

A bit stuck on the Graph part. Note to self: don't abuse CPP pointers!!

## Useful stuff

```cmake
# Debug flags in CMakeLists.txt
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
```

See cmake debugging output
```bash
cmake .. --debug-output
```

Build with cmake, then debug with VScode.   
`Run > OpenConfiguration`
```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",

    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "/c/Users/kristjan/git/aoc2020/day07/lib/build/bag_test",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "console": "externalTerminal",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        },
    ]
}
```


