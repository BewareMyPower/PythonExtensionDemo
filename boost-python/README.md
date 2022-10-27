# Python C++ Extension

## Windows

```PowerShell
vcpkg install --feature-flags=manifests --triplet x64-windows-static
cmake -B build
cmake --build build
```

## Linux

```bash
$ cmake -B build
$ cmake --build build
$ cp ./build/libhello.so hello.so
$ python3 -c 'import hello; print(hello.hello());'
hello, world
```
