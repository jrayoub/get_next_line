#include "get_next_line.h"

char	*cpy_enl(char *holder)
{
	int		i;
	char	*line;

	i = 0;
	if (!holder)
		return (NULL);
	while (holder[i] && holder[i++] != '\n')
		;
	line = gt_calloc(i, sizeof(char));
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	line[i + 1] = 0;
	if (gt_strchr(holder, '\n'))
		gt_memmove(holder, gt_strchr(holder, '\n') + 1,
				gt_strlen(gt_strchr(holder, '\n')));
	else
	{
		gt_bzero(holder, gt_strlen(holder));
		free(holder);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *holder;
	char *cursor;
	ssize_t i;

	cursor = malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 1;
	if (gt_strchr(holder, '\n'))
		return (cpy_enl(holder));
	while (!gt_strchr(holder, '\n') && i != 0)
	{
		i = read(fd, cursor, BUFFER_SIZE);
		if (i == -1)
		{
			free(cursor);
			return (NULL);
		}
		cursor[i] = 0;
		holder = gt_strjoin(holder, cursor);
	}
	if (i == 0)
		return (NULL);
	return (cpy_enl(holder));
}