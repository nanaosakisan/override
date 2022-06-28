#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void log_wrapper(FILE *file, char *str, char *name)
{
    char buffer[255];

    strcpy(buffer, str);
    snprintf(buffer + strlen(buffer), 255 - 1 - strlen(buffer), name);
    buffer[strcspn(buffer, "\n")] = 0;
    fprintf(file, "LOG: %s\n", buffer);
}

int main(int argc, char *argv[])
{
    char buffer[100];
    char c = -1;
    int dest = -1;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", *argv);
    }

    FILE *log_file;
    if (!(log_file = fopen("./backups/.log", "w")))
    {
        printf("ERROR: Failed to open%s\n", "./backups/.log");
        exit(1);
    }

    log_wrapper(log_file, "Starting back up: ", argv[1]);

    FILE *origin;
    if (!(origin = fopen(argv[1], "r")))
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }

    strcpy(buffer, "./backups/");
    strncat(buffer, argv[1], 100 - 1 - strlen(buffer));

    if ((dest = open(buffer, 193, 432) < 0))
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }

    do
    {
        write(dest, &c, 1);
        c = fgetc(origin);
    } while (c != 255);

    log_wrapper(log_file, "Finished back up ", argv[1]);
    fclose(origin);
    close(dest);

    return 0;
}