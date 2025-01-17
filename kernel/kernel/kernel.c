#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/kbd.h>
#include <kernel/kbd_input.h>
#include <d_unit/d_unit.h>
#include <kernel/interrupts.h>
#include <kernel/gdt.h>
#include <stdlib.h>

// Comment out the follow macro definiton to disable unit tests from running
#define D_UNIT_ENABLED

void print_header()
{
    tty_write_string_centered("DAX Operating System");
    tty_write_string_centered("2021 (c)");
    tty_print_horizontal_rule('-');
}

void init_devices()
{
    tty_initialize();
    kbd_init();
}

void init_descriptors()
{
    gdt_init();
    idt_init();
}

void kernel_main(void)
{
    init_descriptors();
    init_devices();
    print_header();
#ifdef D_UNIT_ENABLED
    D_UNIT_run();
#endif
}
