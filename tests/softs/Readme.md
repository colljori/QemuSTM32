# Folder with tests for Stm32

## Use 

To launch a simulation in debug mode, run in one terminal:
```
./nucleo-f401re.sh -gdb-server 1234 -nographic -components.flash.file-blob ../QemuSTM32/test/softs/NAME_OF_THE_TEST/test.bin
```
and in an other terminal:
```
arm-none-eabi-gdb test.elf -ex "tar rem :1234"
```
