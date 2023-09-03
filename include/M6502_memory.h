#pragma once

#include "config.h"
#include <stddef.h> // size_t


typedef struct
{
    // including RAM, ROM, and memory-mapped I/O
    uchar8_t address[max_address];
    // each address can hold one byte
}M6502_memory;

struct M6502; // forward declaration so compiler knows struct exists and will be defined later

void M6502_set_memory(struct M6502* computer, ushort16_t address, uchar8_t value);
void M6502_memory_inbounds(ushort16_t index);

uchar8_t M6502_get_byte(struct M6502* computer, ushort16_t address);
ushort16_t M6502_get_word(struct M6502* computer, ushort16_t address, uchar8_t increment);

void M6502_store_program(struct M6502* computer, uchar8_t* file, size_t program_size);

/*
memory map (reservered)

The first 256 byte page of memory ($0000-$00FF) is referred to as 'Zero Page' and is the focus of a number of special 
addressing modes that result in shorter (and quicker) instructions

The second page of memory ($0100-$01FF) is reserved for the system stack and which cannot be relocated

The only other reserved locations in the memory map are the very last 6 bytes of memory $FFFA to $FFFF which must be
programmed with the addresses of the non-maskable interrupt handler ($FFFA/B), the power on reset location ($FFFC/D)
and the BRK/interrupt request handler ($FFFE/F) respectively

Concering pages think of memory as separated into pages, theres 256 pages and 256 locations on each page,
so 256x256 is 65535 bytes and zero page is just the first page with shortest addresses
*/

/*
a well-known bug in indirect jump instruction, JMP (address), where if the address is on a page boundary, 
it doesn't fetch the correct second byte of the target address. This is a specific quirk of the 6502
*/