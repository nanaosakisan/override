#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

int main()
{
    char buffer[32];
    pid_t waitedPid = 0;
    pid_t backupPid;
    pid_t thirdPid;
    int ret = 0;

    pid_t pid = fork(); 

    memset(buffer, 0, 32);
    
    if (pid == 0) {
        prctl(1, 1); //PR_SET_PDEATHSIG
        ptrace(0, 0, 0, 0); //PTRACE_TRACEME 
        puts("Give me some shellcode, k");
        gets(buffer); //pas protegé
        return 0;
    }

    while (1) {
        wait(&waitedPid);
        backupPid = waitedPid;
        thirdPid = backupPid;
        if (WIFEXITED(thirdPid)) {
            puts("child is exiting");
            return 0;
        }

        if (ptrace(3, ret, 44, 0) == 11) { // If syscall exec
            puts("no exec() for you");
            kill(ret, 9);
        }
    }

    return 0;
}