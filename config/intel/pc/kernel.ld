
ENTRY(multibootEntry)
TARGET("elf32-i386")
OUTPUT_FORMAT("elf32-i386")

SECTIONS
{
    . = 0x00100000;
    __start = .;

    .text :
    {
        KEEP (*(.boot))
        *(.text)
        *(*.text)
        *(.text*)
        *(.gnu.linkonce.*)
        *(.rodata)
        *(.rodata.*)
        *(.eh_frame)
        . = ALIGN(4096);
    }

    .data :
    {
        *(.data)
        *(.note.gnu.build-id)

        CTOR_LIST = .;
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
        KEEP (*(.preinit_array))
        KEEP (*(.init_array.*))
        KEEP (*(.init_array))
        LONG(0)
        CTOR_END = .;

        DTOR_LIST = .;
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
        KEEP (*(.fini_array.*))
        KEEP (*(.fini_array))
        LONG(0)
        DTOR_END = .;
        . += 4;

        initStart = .;
        KEEP (*(SORT(.init*)))
        initEnd   = .;
        isKernel = .;
        LONG(1);
        . = ALIGN(4096);
    }

    .bss :
    {
        __bss_start = .;
        *(.bss)
        *(*.bss)
        *(.bss*)
        __bss_end = .;
        *(COMMON)
        LONG(0)
    }

    __end = .;
}
