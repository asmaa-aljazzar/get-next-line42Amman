#include "get_next_line.h"
char *ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
void ft_strdup(char *str);
void ft_strchr(char *str, int c);

char *ft_strjoin(char *s1, char *s2)
/******************************************************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *****************************************************************************/
{
    char *joined_str;
    int i;
    int j;
    
    i = -1;//to decreasing lines
    j = 0;
    if (!s1)
        s1 = ""; // set an empty str
    if (!s2)
        s2 = "";
    joined_str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char)); //final str
    if(!joined_str)
        return (free(s1), free(s2), NULL);
    while (s1[++i] != '\0')// ++(-1) = 0
        joined_str[i] = s1[i];
    while (s2[j] != '\0')
        joined_str[i++] = s2[j++]; 
    joined_str[i] = '\0'; 
    return (joined_str);
}

int ft_strlen(char *str)
/******************************************************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *****************************************************************************/
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_strdup(char *str)
/******************************************************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *****************************************************************************/
{

}