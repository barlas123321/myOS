#include "types.h"
#include "gdt.h"

void printf(const int8_t* str)
{
        static volatile uint16_t* VideoMemory = (volatile uint16_t*)0xb8000;
        uint8_t fg = 0x0F; // ön plan beyaz
        uint8_t bg = 0x00; // arka plan siyah
        uint16_t color = (bg << 4) | fg;

        for(int i = 0; str[i] != '\0'; ++i)
                VideoMemory[i] = (color << 8) | str[i];
}

typedef void(*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" void mainKernel(void* multiboot_structure, uint32_t magicnumber)
{
        printf("Hello world! -- bbarlas123321");

        GlobalDescriptorTable gdt;

        while(1);
}
