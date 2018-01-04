# Folder with tests for Stm32

## Use 

To launch a simulation in debug mode, run in a terminal after having changed paths:
```
./nucleo-f401re.sh -gdb-server 1234 -nographic -components.flash-native.file-blob ../QemuSTM32/tests/PATH_TO_BIN/NAME.bin -components.flash-boot.file-blob ../QemuSTM32/tests/PATH_TO_BIN/NAME.bin 
```
and in an other terminal:
```
arm-none-eabi-gdb test.elf -ex "tar rem :1234"
```
If you use tests with mbed, you must add to the previous command : '-ex "cd ../mbed-dev/BUILD"' in order to access debug information in .c and .cpp files. 


## Different folders 
 - mbed_softs : Contains softs created with mbed lib. To use it, copy "template" directory and modify main.cpp with your own tests. Mbed sources are already compiled in mbed-dev dir
 - softs : can be used to make specifics tests without mbed.
 - lib : can be used to help specifics tests but not useful anymore
