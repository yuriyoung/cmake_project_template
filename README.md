## This is an example project using CMake.

The requirements are:

  - CMake 3.12 or better; 3.14+ highly recommended.
  - A C++11 compatible compiler
  - Git
  - Doxygen (optional)

## Configure and build:

```shell
cmake -S . -B build
```

Add `-GNinja` if you have Ninja.

To build:

```shell
cmake --build build
```

To test (--target can be written as -t in CMake 3.15+):

```shell
cmake --build build --target test
```

To build docs (requires Doxygen, output in build/docs/html):

```shell
cmake --build build --target docs
```

## Project structure

```
- example
  - .clang-format
  - .gitignore
  - README.md
  - LICENSE.md
  - CMakeLists.txt
  - cmake
    - FindSomeLib.cmake
    - AddGoogleTest.cmake
  - include
    - libexample
      - example.h
  - src
    - CMakeLists.txt
    - example.cpp
  - apps
    - CMakeLists.txt
    - app1
      - app1.cpp
    - app2
      - app2.cpp
    - app3
      - app3.cpp
  - tests
    - CMakeLists.txt
    - auto
    - manual
    - unit
      - CMakeLists.txt
      - testlib.cpp
  - docs
    - CMakeLists.txt
  - extern
    - CMakeLists.txt
  - scripts
    - setup.py
```

src folder:

- 1.Components

```
- src
  - CMakeLists.txt
  - lib1
    - lib1.cpp
  - lib2
    - lib2.cpp
  - lib3
    - lib3.cpp
```

- 2.Nested-Dependencies
  
```
- src
  - lib1
    - CMakeLists.txt
    - lib1.cpp
  - lib2
    - CMakeLists.txt
    - lib2.cpp
  - lib3
    - CMakeLists.txt
    - lib3.cpp
  - ...
```