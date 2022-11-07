#include <stdio.h>
#include <stdlib.h>

int main()
{
    char command[100];
    int pid;
    // FILE *file = fopen("process.txt", "r");
    system("rm process.txt");
    system("touch process.txt");
    system("ps -e > process.txt");
    printf("Pls gimme a pid: ");
    scanf("%d", &pid);

    sprintf(command, "grep ' %d ?' process.txt && kill %d", pid, pid);
    system(command);
    printf("p has been terminated");

    return 0;
}
