# Bootloader-STM32F103
This is the bootloader for STM32F103 chips



# Usage

## Build

This project uses KEIL software to build the project.  Open Stm32f103Bootloader.uvproj file in Bootloader-STM32F103\Bootloader-STM32F103\PROJ and click the build button.

## Upload bootloader

There is a pre-build hex file in the OUTPUT folder of this firmware. You need to upload it to your board first.

You can use SWD , serial or USB cable. And if you are using our cheetah or AIO boards , you can upload it with the STM32Flasher software which only work in Windows.

https://github.com/FYSETC/STM32Flasher

In linux and mac or even windows, you can use the open source software stm32flash

https://github.com/FYSETC/stm32flash

with the command

```
stm32flash -w Bootloader-STM32F103.hex -v -i rts,-dtr /dev/ttyUSB0
```

## Change firmware flash address

The firmware boot address is 0x8010000 , so if you want to use this bootloader you need to change the firmware location to 0x8010000.

And if you are using our stm32f103 boards for 3d printing. You need to add the following lines (or check Marlin PR: https://github.com/MarlinFirmware/Marlin/pull/18179)

```
# Relocate firmware from 0x08000000 to 0x08010000
for define in env['CPPDEFINES']:
    if define[0] == "VECT_TAB_ADDR":
        env['CPPDEFINES'].remove(define)
env['CPPDEFINES'].append(("VECT_TAB_ADDR", "0x08010000"))

custom_ld_script = os.path.abspath("buildroot/share/PlatformIO/ldscripts/fysetc_stm32f103rc.ld")
for i, flag in enumerate(env["LINKFLAGS"]):
    if "-Wl,-T" in flag:
        env["LINKFLAGS"][i] = "-Wl,-T" + custom_ld_script
    elif flag == "-T":
        env["LINKFLAGS"][i + 1] = custom_ld_script
```

to the file "Marlin\Marlin\buildroot\share\PlatformIO\scripts\fysetc_STM32F1.py"

You can add it after the line 

```
Import("env")
```

And then rebuild the 3d printer firmware.

## Upload with SD card

1. Copy the 3d printer firmware to the SD card , you need to be sure the firmware name is "firmware.bin". 
2. And then power off the machine.
3. Insert the SD card to the board.
4. Power on the machine. 
5. And wait for 10~20 seconds , it will be done. 

You can connect the usb cable to monitor the process.

## Change the bootloader flash address

You need to modify Marlin and this Bootloader 

### Marlin:

Change following `0x08010000` to your address. It's in `STM32F103RC_fysetc.py` file

```
env['CPPDEFINES'].append(("VECT_TAB_ADDR", "0x08010000"))
```

And change following `64K` to your address corresponding size. It's in `fysetc_stm32f103rc.ld` file

```
rom (rx) : ORIGIN = 0x08010000, LENGTH = 256K - 64K
```

*note : 64K is for 0x10000, as 1K==1024==0x400* 

### Bootloader:

Change following `0x08010000` to your address,  it's in `Bootloader-STM32F103/CODE/APP/bootloaders.h` file

```
 #define BOOTLOADER_FLASH_ADDR   ( 0x08010000 )
```

### Example:

You want to change flash address to `0x807000`, `so 0x7000 / 0x400 = 28`, so all lines need to change are

```
env['CPPDEFINES'].append(("VECT_TAB_ADDR", "0x08007000"))

rom (rx) : ORIGIN = 0x08007000, LENGTH = 256K - 28K

#define BOOTLOADER_FLASH_ADDR   ( 0x08007000 )
```

# Issues

And the moment , according to the test , this firmware is not stable. And some SD card will fail all the time , but some will succeed , so if it fail (you can monitor it from USB  (UART) ) , change another SD card and try again. And welcome to give us your improvement ideas.