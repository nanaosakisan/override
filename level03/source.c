#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void decrypt(int rot)
{
    char buffer[] = "Q}|u`sfg~sf{}|a3";
    int len;

    len = strlen(buffer);
    for (int i = 0; i < len; i++) 
    {
        buffer[i] = buffer[i] ^ rot;
    }

    if (!strncmp(buffer, "Congratulations!", 17)) 
    {
        system("/bin/sh");
        return;
    } 
    puts("\nInvalid Password");
}

void test(int user_pwd, int real_pwd) 
{
    int diff = real_pwd - user_pwd;

    switch (diff)
    {
        case 1: // 1
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0x9: // 9
        case 0x10: // 16
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15: // 21
            decrypt(diff);
            break;
        default:
            decrypt(rand());
            break;
    }
}

int main(int argc, char *argv[]) 
{
    int user_pwd;

    srand(time(0));
    puts("\b***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("\b***********************************");

    printf("Password:");
    scanf("%d", &user_pwd);
    test(user_pwd, 322424845);
}