
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	get_next_line(fd, &line);
	printf("%s\n", line);
	// while (get_next_line(fd, &line) > 0)
	// 	printf("%s\n", line);
	return (0);
}