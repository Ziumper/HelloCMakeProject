# Hello Project in Learning CMake

Simple project for learning Cmake

## Windows Setup

https://stackoverflow.com/questions/70197831/unable-to-determine-what-cmake-generator-to-use-vs-code-windows-10

Firstly check the system.

Install MINGW https://www.msys2.org/

Install gcc, g++, gdb, and cmake using pacman.

```
pacman -S mingw-w64-x86_64-gcc

pacman -S mingw-w64-x86_64-gdb

pacman -S mingw-w64-x86_64-cmake
```

Check installation:

```
gcc --version

g++ --version

gdb --version
```

Edit environment variables for your account (PATH)
```
C:\msys64\mingw64\bin
```

### VSCode

For cmake project on Vscode:

Create a cmake project: https://code.visualstudio.com/docs/cpp/cmake-linux#_create-a-cmake-project

Choose the Kit (Toolchain) which was installed before

Set cmake.cmakePath (If you installed with pacman, the path should be same as gcc/g++.

```
"cmake.cmakePath": "C:\msys64\mingw64\bin\cmake.exe"
```

Set inside extension settings menu Cmake Generator to use
```
MinGW Makefiles
```

Reset VScode: Ctrl+shift+P and type "CMake:Reset CMake Tools for Extension State"

Configure project: Ctrl+shift+P and type "CMake: Configure". You will see "built" directory and generated files.

Format code  (https://stackoverflow.com/questions/56883170/beautify-c-files-in-vscode)
Simple go to command palette using Ctrl+Shift+P

search "format"

and select "Format document with"

and simply select "C/C++"

