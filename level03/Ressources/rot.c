#include <stdio.h>

int main(void)
{
    char first = 'Q';
    char res;
    
    for (int i = 0; i < 22; ++i)
    {
        res = first ^ i;
        printf("i: %d, result: %c\n", i, res);
    }
    return (0);
}