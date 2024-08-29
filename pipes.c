#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(pipefd[0]); // Close unused read end
        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        close(pipefd[1]); // Close write end after writing
    } else {
        // Child process
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], read_msg, sizeof(read_msg));
        close(pipefd[0]); // Close read end after reading
        printf("Child received: %s\n", read_msg);
    }

    return 0;
}

