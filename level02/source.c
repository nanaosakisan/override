int main(int ac, char **av)
{
    fd = fopen("/home/users/level03/.pass", r);
    stderr(); //??
    if (!fd)
    {
        fwrite("ERROR: failed to open password file\n", 1, 37, stderr/1);
        exit(1);
    }
    fread(buf, 1, 41, fd); //taille buf ?
    if (strcspn(buf, "\n") != 41)  //a confirmer
    {
        fwrite("ERROR: failed to read password file\n", 1, 37,stderr/1);
        fwrite("ERROR: failed to read password file\n", 1, 37, stderr/1);
        exit(1);
    }
    fclose(fd);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");
    fgets(buf2, 100, 1); //taille ?
    strcspn(buf2, "\n");
    printf("--[ Password: ");
    fgets(buf3, 100, 1); //taille ?
    strcspn(buf3, "\n");
    puts("*****************************************");
    if (strncmp(buf1, buf3, 29) == 0) //vide dans gdb, peut être buf1 ?
    {
        printf("Greetings, %s!", buf1);
        system("/bin/sh");
    }
    printf(buf2);
    puts(" does not have access!");
    exit(1);
    return (0);
}