#pragma once

typedef unsigned char uchar8_t;
typedef unsigned short ushort16_t;
typedef const char* cString;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

#define max_memory 65535 // 6502's 16-bit address bus can only handle this much
#define stack_max_size 256

#define zero_page_start 0x0000
#define stack_start 0x0100 // decimal(byte) 256 - Start of stack
#define stack_end 0x01FF // decimal(byte) 511 - Use as offset for programs
#define program_initial_load 0x0200 // decimal(byte) 512 - Programs first byte

// Instructions 
/*
#define ADC_IMMEDIATE 0x69 // Add with Carry, Immediate mode
#define ADC_ZERO_PAGE 0x65 // Add with Carry, Zero Page mode
#define ADC_ZERO_PAGE_X 0x75 // Add with Carry, Zero Page,X mode
#define ADC_ABSOLUTE 0x6D // Add with Carry, Absolute mode
#define ADC_ABSOLUTE_X 0x7D // Add with Carry, Absolute,X mode
#define ADC_ABSOLUTE_Y 0x79 // Add with Carry, Absolute,Y mode
#define ADC_INDIRECT_X 0x61 // Add with Carry - (Indirect, X) mode
#define ADC_INDIRECT_Y 0x71 // Add with Carry - (Indirect), Y

#define AND_IMMEDIATE 0x29 // Logical AND - Immediate
#define AND_ZERO_PAGE 0x25 // Logical AND - Zero Page
#define AND_ZERO_PAGE_X 0x35 // Logical AND - Zero Page,X
#define AND_ABSOLUTE 0x2D // Logical AND - Absolute
#define AND_ABSOLUTE_X 0x3D // Logical AND - Absolute,X
#define AND_ABSOLUTE_Y 0x39 // Logical AND - Absolute,Y
#define AND_INDIRECT_X 0x21 // Logical AND - (Indirect, X)

#define ASL_ACCUMULATOR 0x0A // Arithmetic Shift Left - Accumulator
#define ASL_ZERO_PAGE 0x06 // Arithmetic Shift Left - Zero Page
#define ASL_ZERO_PAGE_X 0x16 // Arithmetic Shift Left - Zero Page, X
#define ASL_ABSOLUTE 0x0E // Arithmetic Shift Left - Absolute
#define ASL_ABSOLUTE_X 0x1E // Arithmetic Shift Left - Absolute, X

#define BCC_RELATIVE 0x90 // Branch if Carry Clear - Relative
#define BCS_RELATIVE 0xB0 // Branch if Carry Set - Relative
#define BEQ_RELATIVE 0xF0 // Branch if Equal - Relative
#define BMI_RELATIVE 0x30 // Branch if Minus - Relative
#define BNE_RELATIVE 0xD0 // Branch if Not Equal - Relative
#define BPL_RELATIVE 0x10 // Branch if Plus - Relative
#define BVC_RELATIVE 0x50 // Branch if Overflow Clear - Relative
#define BVS_RELATIVE 0x70 // Branch if Overflow Set - Relative

#define BIT_ZERO_PAGE 0x24 // Bit Test - Zero Page
#define BIT_ABSOLUTE 0x2C // Bit Test - Absolute

#define BRK 0x00 // Force Interrupt - Implied

#define CLC 0x18 // Clear Carry Flag - Implied
#define CLD 0xD8 // Clear Decimal Mode - Implied
#define CLI 0x58 // Clear Interrupt Disable - Implied
#define CLV 0xB8 // Clear Overflow Flag - Implied

#define CMP_IMMEDIATE 0xC9 // Compare Accumulator - Immediate
#define CMP_ZERO_PAGE 0xC5 // Compare Accumulator - Zero Page
#define CMP_ZERO_PAGE_X 0xD5 // Compare Accumulator - Zero Page, X
#define CMP_ABSOLUTE 0xCD // Compare Accumulator - Absolute
#define CMP_ABSOLUTE_X 0xDD // Compare Accumulator - Absolute, X
#define CMP_ABSOLUTE_Y 0xD9 // Compare Accumulator - Absolute, Y
#define CMP_INDIRECT_X 0xC1 // Compare Accumulator - (Indirect, X)

#define CPX_IMMEDIATE 0xE0 // Compare X Register - Immediate
#define CPX_ZERO_PAGE 0xE4 // Compare X Register - Zero Page
#define CPX_ABSOLUTE 0xEC // Compare X Register - Absolute

#define CPY_IMMEDIATE 0xC0 // Compare Y Register - Immediate
#define CPY_ZERO_PAGE 0xC4 // Compare Y Register - Zero Page
#define CPY_ABSOLUTE 0xCC // Compare Y Register - Absolute

#define DEC_ZERO_PAGE 0xC6 // Decrement a Memory Location - Zero Page
#define DEC_ZERO_PAGE_X 0xD6 // Decrement a Memory Location - Zero Page, X
#define DEC_ABSOLUTE 0xCE // Decrement a Memory Location - Absolute
#define DEC_ABSOLUTE_X 0xDE // Decrement a Memory Location - Absolute, X

#define DEX 0xCA // Decrement the X Register - Implied
#define DEY 0x88 // Decrement the Y Register - Implied

#define EOR_IMMEDIATE 0x49 // Exclusive OR - Immediate
#define EOR_ZERO_PAGE 0x45 // Exclusive OR - Zero Page
#define EOR_ZERO_PAGE_X 0x55 // Exclusive OR - Zero Page, X
#define EOR_ABSOLUTE 0x4D // Exclusive OR - Absolute
#define EOR_ABSOLUTE_X 0x5D // Exclusive OR - Absolute, X
#define EOR_ABSOLUTE_Y 0x59 // Exclusive OR - Absolute, Y
#define EOR_INDIRECT_X 0x41 // Exclusive OR - (Indirect, X)

#define INC_ZERO_PAGE 0xE6 // Increment a Memory Location - Zero Page
#define INC_ZERO_PAGE_X 0xF6 // Increment a Memory Location - Zero Page, X
#define INC_ABSOLUTE 0xEE // Increment a Memory Location - Absolute
#define INC_ABSOLUTE_X 0xFE // Increment a Memory Location - Absolute, X

#define INX 0xE8 // Increment the X Register - Implied
#define INY 0xC8 // Increment the Y Register - Implied

#define JMP_ABSOLUTE 0x4C // Jump to Another Location - Absolute
#define JMP_INDIRECT 0x6C // Jump to Another Location - Indirect

#define JSR_ABSOLUTE 0x20 // Jump to a Subroutine - Absolute

#define LDA_IMMEDIATE 0xA9 // Load Accumulator - Immediate
#define LDA_ZERO_PAGE 0xA5 // Load Accumulator - Zero Page
#define LDA_ZERO_PAGE_X 0xB5 // Load Accumulator - Zero Page, X
#define LDA_ABSOLUTE 0xAD // Load Accumulator - Absolute
#define LDA_ABSOLUTE_X 0xBD // Load Accumulator - Absolute, X
#define LDA_ABSOLUTE_Y 0xB9 // Load Accumulator - Absolute, Y
#define LDA_INDIRECT_X 0xA1 // Load Accumulator - (Indirect, X)

#define LDX_IMMEDIATE 0xA2 // Load X Register - Immediate
#define LDX_ZERO_PAGE 0xA6 // Load X Register - Zero Page
#define LDX_ZERO_PAGE_Y 0xB6 // Load X Register - Zero Page, Y
#define LDX_ABSOLUTE 0xAE // Load X Register - Absolute
#define LDX_ABSOLUTE_Y 0xBE // Load X Register - Absolute, Y

#define LDY_IMMEDIATE 0xA0 // Load Y Register - Immediate
#define LDY_ZERO_PAGE 0xA4 // Load Y Register - Zero Page
#define LDY_ZERO_PAGE_X 0xB4 // Load Y Register - Zero Page, X
#define LDY_ABSOLUTE 0xAC // Load Y Register - Absolute
#define LDY_ABSOLUTE_X 0xBC // Load Y Register - Absolute, X

#define LSR_ACCUMULATOR 0x4A // Logical Shift Right - Accumulator
#define LSR_ZERO_PAGE 0x46 // Logical Shift Right - Zero Page
#define LSR_ZERO_PAGE_X 0x56 // Logical Shift Right - Zero Page, X
#define LSR_ABSOLUTE 0x4E // Logical Shift Right - Absolute
#define LSR_ABSOLUTE_X 0x5E // Logical Shift Right - Absolute, X

#define NOP 0xEA // No Operation - Implied

#define ORA_IMMEDIATE 0x09 // Logical Inclusive OR - Immediate
#define ORA_ZERO_PAGE 0x05 // Logical Inclusive OR - Zero Page
#define ORA_ZERO_PAGE_X 0x15 // Logical Inclusive OR - Zero Page, X
#define ORA_ABSOLUTE 0x0D // Logical Inclusive OR - Absolute
#define ORA_ABSOLUTE_X 0x1D // Logical Inclusive OR - Absolute, X
#define ORA_ABSOLUTE_Y 0x19 // Logical Inclusive OR - Absolute, Y
#define ORA_INDIRECT_X 0x01 // Logical Inclusive OR - (Indirect, X)

#define PHA 0x48 // Push Accumulator on Stack - Implied
#define PHP 0x08 // Push Processor Status on Stack - Implied
#define PLA 0x68 // Pull Accumulator from Stack - Implied
#define PLP 0x28 // Pull Processor Status from Stack - Implied

#define ROL_ACCUMULATOR 0x2A // Rotate Left - Accumulator
#define ROL_ZERO_PAGE 0x26 // Rotate Left - Zero Page
#define ROL_ZERO_PAGE_X 0x36 // Rotate Left - Zero Page, X
#define ROL_ABSOLUTE 0x2E // Rotate Left - Absolute
#define ROL_ABSOLUTE_X 0x3E // Rotate Left - Absolute, X

#define ROR_ACCUMULATOR 0x6A // Rotate Right - Accumulator
#define ROR_ZERO_PAGE 0x66 // Rotate Right - Zero Page
#define ROR_ZERO_PAGE_X 0x76 // Rotate Right - Zero Page, X
#define ROR_ABSOLUTE 0x6E // Rotate Right - Absolute
#define ROR_ABSOLUTE_X 0x7E // Rotate Right - Absolute, X

#define RTI 0x40 // Return from Interrupt - Implied
#define RTS 0x60 // Return from Subroutine - Implied

#define SBC 0xE9 // Subtract with Carry - Immediate
#define SBC_ZERO_PAGE 0xE5 // Subtract with Carry - Zero Page
#define SBC_ZERO_PAGE_X 0xF5 // Subtract with Carry - Zero Page, X
#define SBC_ABSOLUTE 0xED // Subtract with Carry - Absolute
#define SBC_ABSOLUTE_X 0xFD // Subtract with Carry - Absolute, X
#define SBC_ABSOLUTE_Y 0xF9 // Subtract with Carry - Absolute, Y
#define SBC_INDIRECT_X 0xE1 // Subtract with Carry - (Indirect, X)

#define SEC 0x38 // Set Carry Flag - Implied
#define SED 0xF8 // Set Decimal Mode Flag - Implied
#define SEI 0x78 // Set Interrupt Disable Flag - Implied

#define STA_ZERO_PAGE 0x85 // Store Accumulator - Zero Page
#define STA_ZERO_PAGE_X 0x95 // Store Accumulator - Zero Page, X
#define STA_ABSOLUTE 0x8D // Store Accumulator - Absolute
#define STA_ABSOLUTE_X 0x9D // Store Accumulator - Absolute, X
#define STA_ABSOLUTE_Y 0x99 // Store Accumulator - Absolute, Y
#define STA_INDIRECT_X 0x81 // Store Accumulator - (Indirect, X)

#define STX_ZERO_PAGE 0x86 // Store X Register - Zero Page
#define STX_ZERO_PAGE_Y 0x96 // Store X Register - Zero Page, Y
#define STX_ABSOLUTE 0x8E // Store X Register - Absolute

#define STY_ZERO_PAGE 0x84 // Store Y Register - Zero Page
#define STY_ZERO_PAGE_X 0x94 // Store Y Register - Zero Page, X
#define STY_ABSOLUTE 0x8C // Store Y Register - Absolute

#define TAX 0xAA // Transfer Accumulator to X - Implied
#define TAY 0xA8 // Transfer Accumulator to Y - Implied
#define TSX 0xBA // Transfer Stack Pointer to X - Implied
#define TXA 0x8A // Transfer X to Accumulator - Implied
#define TXS 0x9A // Transfer X to Stack Pointer - Implied
#define TYA 0x98 // Transfer Y to Accumulator - Implied
*/

/*
Concering zero page think of the memory addresses as pages, theres 256 pages
probably from page 0-255, and 256 locations on each page so 256x256 is 65536
Zero page is just addresses without a highbyte ranging from 0x0000-0x00FF
*/


/*
Rewrite these with masswerk examples

Addressing Modes:

Accumulator - A -- specified using a special operand value 'A'

Absolute - $0000 -- Instructions using absolute addressing 16 bit address
                    JMP $1234       ;Jump to location $1234
Absolute X-indexed - $0000, X -- Add supplied address with whats in X register for new address
Absolute Y-indexed - $0000, Y -- ""

Immediate - #00 -- '#' symbol followed by an numeric expression
                    LDA #10         ;Load 10 ($0A) into the accumulator
                    LDX #LO LABEL   ;Load the LSB of a 16 bit address into X
                    LDY #HI LABEL   ;Load the MSB of a 16 bit address into Y

Implied - BRK -- is implicit doesnt need anything else ~

Indirect - ($0000) -- Only for JMP contains a 16 bit address which identifies 
                      the location of the least significant byte of another address
                      JMP ($FFFC)     ;Force a power on reset
                      JMP (TARGET)    ;Jump via a labelled memory area

Indirect Indexed ($00), Y --  LDA ($40),Y     ;Load a byte indirectly from memory
                              STA (DST),Y     ;Store accumulator indirectly into memory

Indexed Indirect ($00, X) --  LDA ($40,X)     ;Load a byte indirectly from memory
                              STA (MEM,X)     ;Store accumulator indirectly into memory

Relative - BCC -- only used by branch instructions (BCC, BEQ, BNE, etc.)

Zero Page - $00 -- Same as Absolute but only 8bit addresses
Zero Page X-indexed - $00, X -- ""  Add supplied address with whats in X register for new address
Zero Page Y-indexed - $00, Y -- ""  This mode can only be used with the LDX and STX instructions


*/

/*
    implicit - is just as is

    accumulator =  act directly on the accumulator, uses A

    immeadiate - is specifying a literal number like #10 - ($0A)

    zero page - any relation to page 0, always low byte 0xFF
    zero page x - same but offset by x, LDA ($70,X)- 70 + x -- get value at $0075
    zero page y - same as x but only used with LDX and STX

    absolute - same as zero page but word $7085
    absolute X - ""
    absolute Y - ""

    indirect - only used by JMP
    indirect X - like zero page, X, but 2 more cycles to fetch a pointer address to another address where it gets value
    indirect Y - same as x but with y register

    relative - only used for Branching - option to branch from a location of PC

    anything X or Y is mainly for iterating through data sets
    
*/