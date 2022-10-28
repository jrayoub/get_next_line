#include "get_next_line.h"

size_t	gt_strlen(const char *c)
{
	int	i;

	if (c == NULL)
		return (0);
	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	gt_bzero(void *s, size_t n)
{
	unsigned char	*cs;
	unsigned int	i;

	cs = s;
	i = 0;
	while (i < n)
	{
		cs[i] = '\0';
		i++;
	}
}

void	*gt_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	gt_bzero(ptr, size * nmemb);
	return (ptr);
}