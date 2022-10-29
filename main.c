#include "src/get_next_line.h"

int	main(void)
{
	char *s;
	int i;
	int fd;

	i = 0;
	fd = fileno(fopen("./test.txt", "r"));
	printf("BUFFER_SIZE '%d'\n\n\n", BUFFER_SIZE);
	while (i++ < 7)
		printf("value is '%s'\n\n\n", get_next_line(fd));
	return (0);
}