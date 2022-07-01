#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int read;
    char buf[100];
    char username[100];
    char pass[42];
    int fd;

    fd = fopen("/home/users/level03/.pass", "r");
    if (!fd)
    {
        fwrite("ERROR: failed to open password file\n", 1, 37, stderr);
        exit(1);
    }
    read = fread(pass, 1, 41, fd);
    buf[strcspn(pass, "\n")] = 0;
    if (read != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 37, stderr);
        exit(1);
    }
    fclose(fd);

    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");

    fgets(username, 100, 1);
    username[strcspn(username, "\n")] = 0;

    printf("--[ Password: ");
    fgets(buf, 100, 1);
    pass[strcspn(buf, "\n")] = 0;

    puts("*****************************************");
    if (strncmp(buf, pass, 41) == 0)
    {
        printf("Greetings, %s!", username);
        system("/bin/sh");
    }
    printf(username);
    puts(" does not have access!");
    exit(1);
    return (0);
}