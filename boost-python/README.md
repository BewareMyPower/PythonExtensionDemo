# Python C++ Extension

```bash
$ cmake -B build
$ cmake --build build
$ cp ./build/libhello.so hello.so
$ python3 -c 'import hello; print(hello.hello());'
hello, world
```
