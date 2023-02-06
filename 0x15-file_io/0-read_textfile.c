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
	ssize_t fd, t, w;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
