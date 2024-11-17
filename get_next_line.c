#include "get_next_line.h"
char *get_next_line(int fd);
static char *read_from_file(int fd, char *str);
static char *extract_line(char *str);
static char *get_the_rest(char *str);
/*
*       /\_/\  
*      ( o.o ) 
*       > ^ < 
        Meow!
*/

char *get_next_line(int fd)
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
    static char *full_str; // The main buffer that will extract line from it
    char *line; // The line that will be extract
    char *temp; // To free full str after joining and after update
    
    if (fd < 0 || BUFFER_SIZE <= 0) // When fd is less than 0 this mean that can't open the file or its not exist or the permission does't allow to open the file, and when the buffer is less or equal 0 this is mean there is nothing to read
        return (NULL);
    full_str = read_from_file(fd, full_str); // first we need to read from the file
    if (!full_str)
        return (NULL);
    line = extract_line(full_str); // extract one line and end it with \n char
    if (!line) // because it will allocate the line 
        return (NULL);
    temp = full_str; // to free the old value of full_str
    full_str = get_the_rest(full_str); // update the string by removing the line extracted
    if (!full_str)
        return (NULL);
    free(temp);
    return (line); // the line
}

static char *read_from_file(int fd, char *str)
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
    int read_bytes; // number of bytes that read
    char *buff; // store line
    char *temp; // hold the old value of str
    
    if (!str)
        str = ft_strdup(""); // TODO: ft_strdup()
    buff = malloc((BUFFER_SIZE +1) * sizeof(char)); // buff must same with buffer_size for read it each iteration
    if (!buff)
        return (NULL);
    read_bytes = 1;
    while (read_bytes != 0 && !(ft_strchr(str, '\n'))) // Reach the end of the file or \n // TODO: ft_strchr()
    { // while not \n or EOF
        read_bytes = read(fd, buff, BUFFER_SIZE);//read as buffer_size
        if (read_bytes == -1)//if can't read: permition or file not exist
            return (free(buff), free(str),NULL);
    buff[read_bytes] = '\0'; // null terminator after each read
    temp = str; // to free the old value after done
    str = ft_strjoin(str, buff); // add the read to the full string
    if (!str)
        return (free(buff), free(temp), NULL);
    free(temp);
    }
    return (free(buff), str);
}

static char *extract_line(char *str)
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
    char *line; //The line from buffer
    int i;

    i = 0;
    if (!str) // if no str
        return (NULL);
    while (str[i] != '\0' && str[i] != '\n') // Loop over the buffer to count how many character to set in the line
        i++;
    line = malloc((i + (str[i] == '\n') + 1) * sizeof(char)); // allocate the line buffer with i num in addition of 2 for new line char and null terminator
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i] != '\n')// Loop over the buffer to set the value of the current char into line buffer
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n') // add new line when it is founded
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}

static char *get_the_rest(char *str)
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
    char *the_rest;
    int i; // To loop over the str
    int j; // to fill the rest
    if (!str)
        return (NULL);
    i = 0;
    j = -1;
    while(str[i] != '\0' && str[i] != '\n')
        i++; // counting chars to remove
    if(str[i] == '\n')
        i++;
    the_rest = malloc((ft_strlen(str) - i + 1) * sizeof(char)); // TODO: ft_strlen() 
    // the malloc will be the strlen - the part we don't need + null terminator
    if (!the_rest)
        return (NULL);
    while (str[i] != '\0')
        the_rest[++j] = str[i++];
    the_rest[++j] = '\0';
    return (the_rest);
}

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    char *final;
    char *null = NULL;

    final = ft_strjoin("", "");
    printf("1 Empty strs: \n");
    printf("Result: \"%s\"\n", final ? final : "(null)");  // Should print an empty string
    printf("================================================\n");

    final = ft_strjoin("Hi", "");
    printf("2 s2 is empty: \n");
    printf("Result: \"%s\"\n", final ? final : "(null)");  // Should print "Hi"
    printf("================================================\n");

    final = ft_strjoin("", "asmaa");
    printf("3 s1 is empty: \n");
    printf("Result: \"%s\"\n", final ? final : "(null)");  // Should print "asmaa"
    printf("================================================\n");

    final = ft_strjoin("", null);
    printf("4 s2 null: \n");
    printf("Result: \"%s\"\n", final ? final : "(null)");  // Should print "(null)" as null is passed
    printf("================================================\n");

    final = ft_strjoin(null, "");
    printf("5 s1 null: \n");
    printf("Result: \"%s\"\n", final ? final : "(null)");  // Should print "(null)" as null is passed
    printf("================================================\n");

    final = ft_strjoin("String1 ", "String2");
    printf("6 s1 and s2 are both non-empty: \n");
    printf("Result: \"%s\"\n", final ? final : "(null)");  // Should print "String1 String2"
    printf("================================================\n");

    return 0;
}
