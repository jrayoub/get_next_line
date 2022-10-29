#include "get_next_line.h"

int	main(void)
{
	char *s;
	int i;
	int fd;

	i = 0;
	fd = fileno(fopen("./test.txt", "r"));
	printf("fd : %d", fd);
	printf("BUFFER_SIZE '%d'\n\n\n", BUFFER_SIZE);
	do
	{
		printf("value is '%s'\n\n\n", (s = get_next_line(fd)));
	} while (s != 0);
	return (0);
}