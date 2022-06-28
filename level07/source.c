#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void clear_stdin()
{
    char val = 0;

    while (1)
    {
        val = getchar();
        if (val == '\n' || val == EOF)
        {
            return;
        }
    }
}

unsigned int get_unum(void)
{
    int var1 = 0;

    fflush(stdout);
    scanf("%u", &var1);
    clear_stdin();
    return var1;
}

void prog_timeout()
{
    exit(1);
}

int store_number(int *buffer)
{
    int number;
    int index;

    printf(" Number: ");
    number = get_unum();
    printf(" Index: ");
    index = get_unum();

    if (!(index % 3) || number >> 24 != 183)
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return 1;
    }
    buffer[index] = number;
    return 0;
}

int read_number(int *buffer)
{
    int index = 0;

    printf(" Index:");
    index = get_unum();
    printf(" Number at data[%u] is %u\n", index, buffer[index]);
    return 0;
}

int main(int argc, char *argv[], char *envp[])
{
    char buffer[100] = {0};
    char **av = argv;
    char **ep = envp;

    int cmd_ret = 0;
    char cmd_buffer[20];

    while (*av)
    {
        memset(*av, 0, strlen(*av));
        *av++;
    }
    while (*ep)
    {
        memset(*ep, 0, strlen(*ep));
        *ep++;
    }

    puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------");

    while (1)
    {
        printf("Input command: ");
        fgets(cmd_buffer, 20, stdin);
        cmd_buffer[strlen(&cmd_buffer) - 1] = 0;

        if (!strncmp(cmd_buffer, "store", 5))
            cmd_ret = store_number(buffer);
        else if (!strncmp(cmd_buffer, "read", 4))
            cmd_ret = read_number(buffer);
        else if (!strncmp(cmd_buffer, "quit", 4))
            return 0;

        if (cmd_ret == 0)
            printf(" Completed %s command successfully\n", &cmd_buffer);
        else
            printf(" Failed to do %s command\n", &cmd_buffer);
        memset(&cmd_buffer, 0, 20);
    }
    return 0;
}