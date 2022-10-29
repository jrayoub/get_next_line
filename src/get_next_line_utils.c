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
	void	*ptr;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	gt_bzero(ptr, size * nmemb);
	return (ptr);
}

char	*gt_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	if (!s)
		return (0);
	uc = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != uc)
	{
		i++;
	}
	if (s[i] == uc)
		return ((char *)&s[i]);
	return (0);
}

char	*gt_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ns;
	int		j;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 | !s2)
		return (NULL);
	len2 = gt_strlen(s2);
	len1 = gt_strlen(s1);
	j = 0;
	i = 0;
	ns = malloc(len1 + len2 + 1);
	if (ns == NULL)
		return (NULL);
	while (s1[j])
		ns[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ns[i++] = s2[j++];
	ns[i] = '\0';
	return (ns);
}

void	*gt_memmove(void *dest, const void *src, size_t n)
{
	char		*dstcpy;
	const char	*srccpy;
	int			i;

	dstcpy = (char *)dest;
	srccpy = (const char *)src;
	if (n == 0)
	{
		return (dest);
	}
	if (dest > src)
	{
		i = n - 1;
		while (i >= 0)
		{
			dstcpy[i] = srccpy[i];
			i--;
		}
		return ((void *)dest);
	}
	else
		return (gt_memcpy((void *)dest, src, n));
}
void	*gt_memcpy(void *dest, const void *src, size_t n)
{
	char *dstcpy;
	const char *srccpy;

	if (dest == NULL || src == NULL)
		return (NULL);
	dstcpy = dest;
	srccpy = src;
	while (n--)
		*dstcpy++ = *srccpy++;
	return (dest);
}