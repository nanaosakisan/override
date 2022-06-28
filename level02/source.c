#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int read;
    char buf[42];
    char username[100];
    char pass[100];
    int fd;

    fd = fopen("/home/users/level03/.pass", "r");
    if (!fd)
    {
        fwrite("ERROR: failed to open password file\n", 1, 37, stderr);
        exit(1);
    }
    read = fread(buf, 1, 41, fd);
    buf[strcspn(buf, "\n")] = 0;
    if (read != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 37, stderr);
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
    fgets(pass, 100, 1);
    pass[strcspn(pass, "\n")] = 0;

    puts("*****************************************");
    if (strncmp(buf1, pass, 41) == 0)
    {
        printf("Greetings, %s!", buf1);
        system("/bin/sh");
    }
    printf(username);
    puts(" does not have access!");
    exit(1);
    return (0);
}