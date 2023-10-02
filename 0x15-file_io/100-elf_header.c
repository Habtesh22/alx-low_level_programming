#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ELF_HEADER_SIZE 64

typedef struct Elf64_Ehdr
{
	unsigned char e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
}
Elf64_Ehdr;

/**
 * print_elf_header_info - Print information from the ELF header
 * @elf_header: Pointer to the ELF header structure
 */
void print_elf_header_info(const Elf64_Ehdr *elf_header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x ", elf_header->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n",
			elf_header->e_ident[4] == 1 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
			elf_header->e_ident[5] == 1 ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n",
			elf_header->e_ident[6]);
	printf("  OS/ABI:                            %d\n", elf_header->e_ident[7]);
	printf("  ABI Version:                       %d\n", elf_header->e_ident[8]);
	printf("  Type:                              0x%04x\n", elf_header->e_type);
	printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 if successful, otherwise 98
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Failed to open file '%s'\n", argv[1]);
		exit(98);
	}
	Elf64_Ehdr elf_header;

	if (read(fd, &elf_header, ELF_HEADER_SIZE) != ELF_HEADER_SIZE)
	{
		fprintf(stderr, "Error: Failed to read ELF header\n");
		close(fd);
		exit(98);
	}
	if (memcmp(elf_header.e_ident, "\x7f\x45\x4c\x46", 4) != 0)
	{
		fprintf(stderr, "Error: File '%s' is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}
	print_elf_header_info(&elf_header);
	close(fd);
	return (0);
}
