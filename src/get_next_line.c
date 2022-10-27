#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*back_up;
	ssize_t		i;
	char		*buffer;

	back_up = malloc(BUFFER_SIZE);

	buffer = malloc(BUFFER_SIZE);
	i = read(fd, buffer, BUFFER_SIZE);
	if(i <= 0 ){
		if(get_strlen(back_up) >= 0)
		{
			return back_up;
		}
		free(back_up);
		return NULL;
	}

	return ((char *)buffer);
}

int	main(void)
{
	char	*s;
	FILE	*file;
	int		i;
	char	c;
	// file = fopen("./file.txt", "rw");
	// i = fileno(file);
	// printf("%d", i);
	// c = 's';
	// write(i, &c, 1);
	s = get_next_line(0);
	printf("%s", s);


}
