#include <stdio.h>    // For printf, perror
#include <fcntl.h>    // For open() and file control options
#include <unistd.h>   // For close()
#include <sys/stat.h> // For file mode constants


int main(){

    // after adding wrong file name  \/ error came.
    const char *pathname = "/home/raatz/Programming/Linux/3 System Programming Concepts/4_test.txt"; // File to open
    int flags = O_CREAT | O_WRONLY;                                                                  // Create file if it doesn't exist, open for writing
    mode_t mode = S_IRUSR | S_IWUSR;   
    
    int fd = open(pathname, flags, mode);

    // Usually, an error is indicated by a return of –1. 
    if(fd == -1){
        printf("Error occur\n");
    }


    // Always close the file descriptor after use
    close(fd);
}