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
int ft_strlen(char *str);
void ft_strdup(char *str);


# endif