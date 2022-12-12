#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str)
{
    char **result;
    int index = 0;
    int pntr = 0;
    int pntr_index;

    result = malloc((sizeof(char *))*256); // malloc(1024) werkt ook?
    if (!result)
        return NULL;
    while (str[index] == '\n' || str[index] == '\t' || str[index] == ' ')
        index++;
    while(str[index])
    {
        pntr_index = 0;
        result[pntr] = malloc((sizeof(char))*4096); // malloc(1024) werkt ook?
        if (!result[pntr])
            return NULL;
        while (str[index] != '\n' && str[index] != '\t' && str[index] != ' ' && str[index])
            result[pntr][pntr_index++] = str[index++];
        while (str[index] == '\n' || str[index] == '\t' || str[index] == ' ')
            index++;
        result[pntr][pntr_index] = '\0';
        pntr++;
    }
    result[pntr] = NULL;
    return(result);
}

int main(void)
{
    char *str = "This is my test str r   r ring  hrth        ";
    char **result = ft_split(str);
    int i = 0;
    while (result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    // printf("%d\n", 256*16);
    return (0);
}