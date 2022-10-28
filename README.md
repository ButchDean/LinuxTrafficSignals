# LinuxTrafficSignals
North American traffic signals with ncurses on Linux.

![](ltsStop.JPG)
![](ltsPrepStop.JPG)
![](ltsGo.JPG)

## Build
```
$ cmake -S . -B build
```
Then build the code:
```
$ cmake --build build -j$(nproc)
```

## Run
To run the built program in the build directory do:
```
$ ./lts
```
And to exit just hit any key.
