#include "src/get_next_line.h"

int	main(void)
{
	char *s;
	int i = 0;
	int fd = fileno(fopen("./test.txt", "r"));
	// while ((s = get_next_line(fd)) != 0)
	while (i++ < 4)
		printf("\nvalue is '%s'", get_next_line(fd));
	return (0);
}