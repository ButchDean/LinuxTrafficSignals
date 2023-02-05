# LinuxTrafficSignals
North American traffic signals with ncurses on Linux.

![](ltsStop.JPG)
![](ltsPrepStop.JPG)
![](ltsGo.JPG)

## Build
There are two options to build this project: CMake and Automake

### CMake
```
$ cmake -S . -B build
```
Then build the code:
```
$ cmake --build build
```
### Automake
```
$ autoreconf -i
$ ./configure
```
Then to build the project:
```
$ make
```

## Run
To run the built program in the *_build directory_* do:
```
$ ./lts
```
And to exit just hit any key.
