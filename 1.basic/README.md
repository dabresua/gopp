# How to build

## Linux

Create the library.

``` bash
go build -o example.so -buildmode=c-shared example.go
```

Link the library and generate the executable.

``` bash
g++ main.cpp ./example.so -o main && ./main
```
