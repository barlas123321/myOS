# My Kernel Project

A simple hobby kernel written in C++ and x86 assembly.

## Features

- Basic C++ runtime support (constructor calls)
- Makefile build system for ISO generation
- Works with VirtualBox or QEMU

## Prerequisites

Make sure you have the following tools installed on your system:

- `gcc-multilib` / `g++-multilib` (32-bit cross compilation)
- `nasm` (for assembly files)
- `make`
- `qemu` or `VirtualBox` (to test the ISO)

*i wrote this project in arch so here is a breakdown for build and running in especially arch but the other distros must work same.*
> On Arch Linux:
```bash
sudo pacman -S base-devel gcc-multilib nasm qemu virtualbox
```
## Build and Run

- 1.Build the ISO image:
```bash 
make mykernel.iso
```
- 2.Run in VirtualBox (VM must have ISO attached):
```bash
make run
```
- 3.Optional: Run with QEMU:
*(i recommend virtualbox)*
```bash
qemu-system-i386 -cdrom mykernel.iso
```

## Project Structure
- kernel.cpp      - C++ kernel source
- loader.s        - Assembly bootloader
- linker.ld       - Linker script
- Makefile        - Build system \

*Note: Generated files like .o, .bin, .iso are ignored in the repository (.gitignore).*

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

enjoy <3
