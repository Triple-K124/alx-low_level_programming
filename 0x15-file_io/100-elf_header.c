#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void read_elf_header(const char *filename)
{
	int fd;
	Elf64_Ehdr elf_header;
	int i;
	fd = open(filename, O_RDONLY);
    	if (fd == -1)
	{
        	print_error("Error opening file");
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		print_error("Error reading ELF header");
	}

	close(fd);

	/** Check ELF magic number */
	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || 
	elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file");
	}

	/** Print ELF header information */
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", elf_header.e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "2's complement, little endian");
	printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n", elf_header.e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d\n", elf_header.e_type);
	printf("  Entry point address:               %lx\n", (unsigned long)elf_header.e_entry);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        	exit(98);
	}

	read_elf_header(argv[1]);

	return 0;
}
