# Bare-metal Raspberry PI (B+) experiments

For science

## Getting started

You can compile the `kernel.img` using the makefile.
Then you just have to copy that *image* and the standard *bootcode.bin* and *start.elf* from the raspberry pi firmware
repository to the root of your FAT32 formatted micro SD. A tiny SD card will already suffice.

The current code will make the OK Led on the board blink using the right GPIO pins.

## Resources

The code in this repo has been inspired (and some of it copied) from resources such as:

- [osdev wiki](http://wiki.osdev.org/Raspberry_Pi_Bare_Bones)
- [welch's barebones pi repository](https://github.com/dwelch67/raspberrypi)
- [camebridge's baking pi course](http://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/)

## Contributing

The Raspberry PI blog has some awesome examples of first year students hacking beautiful low level
(assembly/bare bones C) projects together.
My plans with this repo are listed below; feel free to contribute (make a pull request).
But also feel free to fork the repository and take it in any other direction!

Examples of first year student's awesomeness:

- [15.000 lines of assembly chess, anyone?](http://www.raspberrypi.org/chess-bare-metal-assembly-chess/)
- [tetris duel, multiplayer... in assembly](http://hackaday.com/2014/06/29/tetris-duel-with-the-raspberry-pi/)

## Rough plans

I was thinking to:

1) write C that enables UART communication, inspired by the code snippet in the osdev raspberry wiki (note: different model)
2) start to implement bits of newlib C; a relatively easy to port C base library.
