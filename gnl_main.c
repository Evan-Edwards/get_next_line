#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
 
/* int	main()
{
	int		fd, fd2, i = 0;
	char	*line;

	fd = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
	while (i < 4)
	{
        line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
        line = get_next_line(fd2);
        printf("%s\n", line);
		free(line);
        i++;
	}
	close(fd);
	return (0);
} */

/*int	main(int argc, char *argv[])
{
	int	fd;
	char *line;

	printf("started\n");
    if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
    printf("fd valid\n");
	line = get_next_line(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	close(fd);
	return (0);
} */

