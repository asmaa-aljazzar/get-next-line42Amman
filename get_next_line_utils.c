#include "get_next_line.h"
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *str);
char *ft_strchr(char *str, int c);
int ft_strlen(char *str);

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

char *ft_strdup(char *str)
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
    int len;
    char *dupl;
    int i;

    if (!str)
        return (NULL);
    len = ft_strlen(str);
    dupl = malloc((len + 1) * sizeof(char));
    if (!dupl)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        dupl[i] = str[i];
        i++;
    }
    dupl[i] = '\0';
    
    return (dupl);
}

char *ft_strchr(char *str, int c)
/******************************************************************************
 * Finds the first occurrence of the character `c` in the string `str`.
 * If `c` is the null terminator, returns a pointer to the end of the string.
 * Returns NULL if the character is not found or if `str` is NULL.
 *****************************************************************************/
{
    int i;
    
    i = 0;
    if (!str)
        return (NULL);
    if (c == '\0')
        return (&str[ft_strlen(str)]);
    while (str[i] != '\0' && str[i] != c)
    {
        i++;
    }
    if (str[i] == c)
        return (&str[i]);
    return (NULL);
}
