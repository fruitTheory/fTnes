#include <stdio.h>
#include "config.h"
#include "check_SDL_version.h"
#include "MOS_6502.h"
#include "MOS_6502_stack.h"
#include "load_binary.h"


int main(int argc, char* argv[]){

    load_binary(argc, argv);
    Check_SDL_Version();
    printf("total memory: %i\n", max_memory);

    // initialized MOS_6502 variable
    struct MOS_6502 MOS_6502;

    printf("%lli", sizeof(MOS_6502));
    // TO FIX TMRW -- CAPPED AT uchar8_t(255) cant init to 511(0x1FF)
    MOS_6502_stack_init(&MOS_6502);

    printf("%i\n", MOS_6502.registers.SP);

    MOS_6502.registers.SP = 5;

    printf("%i\n", MOS_6502.registers.SP);

    MOS_6502_init(&MOS_6502);

    //printf("addy: %p\n", (void*)&MOS_6502);

    MOS_6502_stack_push(&MOS_6502, 0x100);
    MOS_6502_stack_pop(&MOS_6502, 0x100);

    return EXIT_SUCCESS;
}

/*
LDA(mos6502, int user_value){
    if immeadiate
    mos6502.registers.AC = user_value(19);

    if LDA zeropage(0xA5)
    mos6502.registers.AC = user_value(0x00FF);
    Example: LDA $50 loads the value at memory address 0x0050.

    if LDA absolute(0xAD)
    mos6502.registers.AC = user_value(0xFFFF);

    


}
*/