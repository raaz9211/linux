// 'perror()' and 'strerror()' library functions use to  print an error message based on the errno value of failed system call.

#include <stdio.h>    // For printf, perror
#include <fcntl.h>    // For open() and file control options
#include <unistd.h>   // For close()
#include <sys/stat.h> // For file mode constants
#include <errno.h>    // provides a declaration of errno, set of constants for the various error numbers

int main()
{

    // after adding wrong file name  \/ error came.
    const char *pathname = "/home/raatz/Programming/Linux/3 System Programming Concepts/4_test.txt"; // File to open
    int flags = O_CREAT | O_WRONLY;                                                                  // Create file if it doesn't exist, open for writing
    mode_t mode = S_IRUSR | S_IWUSR;

    int fd = open(pathname, flags, mode);

    // Usually, an error is indicated by a return of –1.
    if (fd == -1)
    {
        // When a system call fails, it sets the global integer variable errno to a positive value that identifies the specific error.
        if (errno == ENOENT)
        {
            // The 'perror()' function prints the string pointed to by its msg argument, followed by a message corresponding to the current value of errno.
            perror("Error opening file"); // Print error message if open fails
        }
    }

    // Always close the file descriptor after use
    close(fd);
}
