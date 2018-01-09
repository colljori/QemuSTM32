# Folder with tests for Stm32

## Test with rabbit



To launch a simulation in debug mode, run in a terminal after having changed paths, in rabbit folder:
```
./nucleo-f401re.sh -gdb-server 1234 -nographic -components.flash-native.file-blob ../QemuSTM32/tests/PATH_TO_BIN/NAME.bin -components.flash-boot.file-blob ../QemuSTM32/tests/PATH_TO_BIN/NAME.bin 
```
and in an other terminal in your test folder:
```
arm-none-eabi-gdb NAME.elf -ex "tar rem :1234"
```
If you use tests with mbed, you must add to the previous command : '-ex "cd ../mbed-dev/OBJDIR"' in order to access debug information in .c and .cpp files. It's easier if you are in the root of your test and not in BUILD folder. 

## Test with board

To launch a test on the Nucleo board, you must install "st-link" which provides "st-util" binary. This binary allows you to connect gdb to the board. 

To add a test on the board, you just have to copy the test binary on the board root. 


## Different folders 
 - mbed_softs : Contains softs created with mbed lib. To use it, copy "template" directory and modify main.cpp with your own tests. Mbed sources are already compiled in mbed-dev dir
 - softs : can be used to make specifics tests without mbed.
 - lib : can be used to help specifics tests but not useful anymore
