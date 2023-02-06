#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to posix stdout
 * @filename: A pointer to the name of the file
 * @letters: The number of letters the fun should read and print
 *
 * Return: if the fun fails or filename is NULL - 0. o/s can read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (0 == -1 || r == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}