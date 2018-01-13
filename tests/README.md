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
If you use tests with mbed, you may add to the previous command : `-ex "cd ../mbed-dev/OBJDIR"` in order to access debug information in .c and .cpp files. It's not mandatory but sometimes gdb don't find debug informations. 

## Test with board

To launch a test on the Nucleo board, you must install "st-link" which provides "st-util" binary. This binary allows you to connect gdb to the board. 

To add a test on the board, `st-flash write path_to_test/test.bin 0x08000000 `


## Different folders 
 - mbed_softs : Contains softs created with mbed lib. To use it, firstly ` cd mbed-dev && make -k `. It must only have one error when linking ( "main" is undefined ). After that, copy "template" directory and modify main.cpp with your own tests. 
 - softs : can be used to make specifics tests without mbed.
 - lib : can be used to help specifics tests but not useful anymore
