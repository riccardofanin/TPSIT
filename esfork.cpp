#include <stdio.h>
#include <unistd.h>
#include <wait.h>

using namespace std;

int es_fork()
{
    int pid = fork();
    int* status;
    
    waitpid(pid, status, 0);
    
    return (pid == 0)? printf("Figlio : %d\n", pid):printf("Padre : %d\tFiglio: %d", getpid(), pid);
}

int main()
{
    es_fork();
    
    return 0;
}