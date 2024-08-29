#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[128];

    // Use popen to execute the "ls" command and open a pipe to read its output
    fp = popen("ls -l", "r");
    if (fp == NULL) {
        perror("popen failed");
        return 1;
    }

    // Read the output of the command line by line and print it to the console
    //while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        //printf("%s", buffer);
    //}

    // Close the pipe and wait for the process to terminate
    if (pclose(fp) == -1) {
        perror("pclose failed");
        return 1;
    }

    return 0;
}

