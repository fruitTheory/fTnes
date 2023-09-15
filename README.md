# M6502 Microprocessor

Currently a 6502 microprocessor but PPU is on the way  
if continue emulation of NES, written in C - fTNES  

## Features

- Full emulation of the legal CPU opcodes
- Emulation of primary system components I/O
- Support for NROM games, non memory-mapped

### Prerequisites

- A C 64-bit compiler (ex. GCC, Clang, MSVC)
- Simple DirectMedia Layer (SDL2)
- Basic make and lib linking knowledge

### Building

```mingw32-make``` ```make```

### Running

```
./main path_to_bin or 'mingw32-make run'
```

![Emulator Test](./img/emulator_test.gif)

## Roadmap

- ~~Implement primary opcodes~~
- Timings and Interrupts
- Debug functions
- Build on top, more functionality
- Refine components
- Streamline build

## Acknowledgments

- nesdev.org - obelisk's guide - Andrew Jacobs
- as65 - assembler by Andrew Jacobs
- masswerk.at - 6502 instruction set reference
- ca65 - Assembler by Ullrich von Bassewitz, Greg King
- hex editor - hexed.it ♡
- NES Documentation - Patrick Diskin 2004
- mcs6500 family programming manual

