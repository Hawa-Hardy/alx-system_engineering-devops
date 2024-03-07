#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - Runs an infinite loop.
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Creates 5 zombie processes.
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid > 0)
        {
            // Parent process
            printf("Zombie process created, PID: %d\n", pid);
        }
        else if (pid == 0)
        {
            // Child process
            exit(0);
        }
        else
        {
            // Fork failed
            perror("fork");
            return (1);
        }
    }

    // Keep the parent process running to maintain zombie children
    infinite_while();

    return (0);
}
