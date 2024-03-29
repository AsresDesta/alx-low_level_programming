#include <alf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: A pointer to an array containing the ELF magic numbers
 *
 * Descripion: If the file is not an ELF File- exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints the magic numbers of an ELF header
 * @e_indet: A pointer to an array containing the ELF magic numbers
 *
 * Descripion: magic numbers are sepaated by spaces
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  magic:  ");

	for (index = 0; index < index < EI_NIDENT; index++)
	{
		printf("%02x", e_indet[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class of an ELF header
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                               ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_dat - prints the data of an ELF header
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data:                                 ");

	switch (e_ident[EI_DAT])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_idnet[EI_CLASS]);
	}
}

/**
 * print_version - prints the version of an ELF header
 * @e_ident: A pointer to an array containing the ELF version
 */
void print_version(unsigned char *e_ident)
{
	printf("  version                              %d",
			e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_osabi - prints the os/ABI of an ELF header
 * @e_ident: A pointer to an array containing the ELF version
 */
void print_osabi(unsigned chae *e_idnet)
{
	printf(" os/ABI:                              ");

	switch (e_idnet[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - system v\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSO\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - IRIX\n");
			break;
		case ELFPSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone APP\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints the ABI version of an ELF header
 * @e_ident: A pointer to an array containing the ELF ABI version
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                         %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of an ELF header
 * @e_type: The ELF type
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                               ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (none)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}
 /**
  * print_entry - prints the entry point of an ELF header
  * @e_entry: The address of the ELF entry point
  * @e_ident: A pointer to an array containing the ELF class
  */
void print_entry(unsigned long int e-entry, unsigned char *e-ident)
{
	printf(" Entry point address:                 ");

	if (e-ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes an ELF file
 * @elf: the file descriptor of the ELF file
 *
 * Description: if the file can not be closed - exit code 98
 */

void close-elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


/**
 * main - Displays the info contained in the ELF headerof an ELF file
 * @argc: The number of arguments supplied to the program
 * @argv: AAn array of pointers to the arguments
 *
 * Return: 0 on Success
 *
 * Description: If the file is not an ELF file of func fails - exit the code 98
 */

int main(int__attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = raed(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FFILENO, "Error: '%s' : no such file\n", argv[1]);
		exit(98);
	}

	chech_elf(header->e_idnet);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_type(header->_type, header->e_ident);
	print_entry(header->_entry, header->e_indet);

	free(header);
	close_elf(o);
	return (0);
}

			

