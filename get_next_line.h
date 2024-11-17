# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *str);
char *ft_strchr(char *str, int c);
int ft_strlen(char *str);


# endif