int verify_user_name(char *a_user_name)
{
    puts("verifying username....\n");
    if (strcmp("dat_wil", a_user_name) == 0)
        return (1);
    return (0);
}

int verify_user_pass(char *a_user_name)
{
    if (strcmp("admin", a_user_pass) == 0)
        return (1);
    return (0);
}

int main (int ac, char **av)
{
    char a_user_name[];
    char a_user_pass[];

    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(a_user_name, 256, 1);
    if (verify_user_name(a_user_name) != 0)
    {
        puts("Enter Password: ");
        fget(a_user_pass, 256, 1);
        verify_user_pass(a_user_pass)
        puts("nope, incorrect password...\n");
    }
    puts("nope, incorrect username...\n");
    return (0);
}
