#include "elf_loader.h"
#include <string.h>

void *memcpy(void *dst, const void *src, uint64_t len)
{
    uint64_t *dword_ptr = (uint64_t *) dst;
    uint64_t *dword_src = (uint64_t *) src;

    while (len >= 8) {
        *dword_ptr++ = *dword_src++;
        len -= 8;
    }

    char *byte_ptr = (char *) dword_ptr;
    char *byte_src = (char *) dword_src;
    while (len--) {
        *byte_ptr++ = *byte_src++;
    }

    return (void *) dst;
}

void *elf_loader(ehdr64_t *elf)
{
    shdr64_t *sec_header =
        (shdr64_t *) ((uint64_t) elf + (uint64_t) elf->e_shoff);
    uint16_t sec_header_num = elf->e_shnum;
    uint32_t i;

    for (i = 0; i < sec_header_num; ++i) {
        if (sec_header[i].sh_type == SHT_PROGBITS && sec_header[i].sh_addr)
            memcpy((void *) sec_header[i].sh_addr,
                   (const void *) elf + sec_header[i].sh_offset,
                   sec_header[i].sh_size);
    }

    return (void *) elf->e_entry;
}
