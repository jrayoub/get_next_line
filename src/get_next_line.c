#include "get_next_line.h"

int	cpy_enl(char *dst, char *s)
{
	int		i;
	char	*temp;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		dst[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		dst[i++] = '\n';
	dst[i + 1] = 0;
	if (s[i] == '\0')
		return (-1);
	j = 0;
	// temp = malloc(gt_strlen(s) - i + 1);
	while (s[i] != '\0')
		temp[j++] = s[i++];
	temp[j] = 0;
	gt_bzero(s, BUFFER_SIZE);
	j = 0;
	while (temp[j] != '\0')
	{
		s[j] = temp[j];
		j++;
	}
//	free(temp);
	return (j);
}

char	*holder_into_line(char *holder)
{
	char	*cur_line;
	int		holder_index;
	int		remains;

	holder_index = 0;
	while (holder[holder_index] && holder[holder_index] != '\n')
		holder_index++;
	if (holder_index == 0)
		return (NULL);
	cur_line = gt_calloc(holder_index + 1, sizeof(char));
	remains = cpy_enl(cur_line, holder);
	if (remains == -1)
	{
		free(holder);
		return NULL;
	}
	return (cur_line);
}

int	check_new_line(char *str)
{
	int		i;
	char	*temp;

	temp = str;
	i = 0;
	if (!temp)
		return (0);
	if (temp[0] == '\0')
		return (0);
	while (!*temp)
	{
		if (*temp == '\n')
			return (1);
		temp++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char *holder;
	ssize_t i;
	static int first_h = 0;
	char *cur_line;
	if(first_h == 0){
		holder = gt_calloc(BUFFER_SIZE , 1);
	}
	first_h++;
	// printf("\nholder value : %s fi %d\n", holder, first_h);

	cur_line = holder_into_line(holder);

	if (check_new_line(cur_line))
		return (cur_line);
	i = read(fd, holder, BUFFER_SIZE);
	cur_line = holder_into_line(holder);

	// if (!check_new_line(holder) && i > 0)
		// get_next_line(fd);

	if (i <= 0 && !cur_line)
		return (NULL);
	return ((char *)cur_line);
}