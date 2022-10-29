#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1999
# endif

char	*get_next_line(int fd);
size_t	gt_strlen(const char *c);
void	gt_bzero(void *s, size_t n);
void	*gt_calloc(size_t nmemb, size_t size);
char	*gt_strchr(const char *s, int c);
char	*gt_strjoin(char *s1, char *s2);
void	*gt_memmove(void *dest, const void *src, size_t n);
void	*gt_memcpy(void *restrict dest, const void *restrict src, size_t n);
#endif
