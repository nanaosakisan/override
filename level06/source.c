#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <string.h>

int auth(char *login_str, unsigned int serial)
{
	size_t login_len;

	login_str[strcspn(login_str, "\n")] = 0;
	login_len = strnlen(login_str, 32);
	
	if (login_len <= 5) {
		return 1;
	}
	if (ptrace(0, 0, 1, 0) == -1) {
		puts("\e[32m.---------------------------.");
		puts("\e[31m| !! TAMPERING DETECTED !!  |");
		puts("\e[32m.---------------------------.");
		return 1;
	}

	int hash = ((0xff & (char)(*login_str + 3)) ^ 0x1337) + 0x5eeded;
	int tmp = 0;

	while (tmp < login_len)
	{
		if (login_str[tmp] <= 31) return 1;
		hash += hash_func(login_str[tmp++]); //has avec toutes sortes d'operation
	}

	if (hash == serial)
		return 0;
	else
		return 1;
}

int main()
{
	char login_buffer[32];
	unsigned int serial;

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(login_buffer, 20, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);

	if (!auth(login_buffer, serial)) {
		puts("Authenticated!");
		system("/bin/sh");
		return 0;
	}

	return 1;
}