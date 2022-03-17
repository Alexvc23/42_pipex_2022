#include<stdio.h>
#include <fcntl.h>
#include"get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("bible.txt", O_RDWR, S_IRUSR);
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    return (0);
}
