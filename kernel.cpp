
void printf(const char* str)
{
        volatile unsigned short* VideoMemory = (volatile unsigned short*)0xb8000;
        unsigned char fg = 0x0F; // ön plan beyaz
        unsigned char bg = 0x00; // arka plan siyah
        unsigned short color = (bg << 4) | fg;

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

extern "C" void mainKernel(void* multiboot_structure, unsigned int magicnumber)
{
        printf("Hello world! -- bbarlas123321");

        while(1);
}
