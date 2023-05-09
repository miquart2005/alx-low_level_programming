#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - STDOUT text file and print.
 * @filename: text file readable
 * @letters: number of letters to be read
 * Return: Always
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t m;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	m = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (m);
}
