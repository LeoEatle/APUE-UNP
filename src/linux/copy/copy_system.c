#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    char c = '\0';
    int in = -1, out = -1;
    // Open file in only-read
    in = open("Data.text", O_RDONLY);
    // Create file in only-write, if not exist, create a new one
    // Owner can read and write
    out = open("copy_system.out.text", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while(read(in, &c, 1) == 1) // Read one then write one
        write(out, &c, 1);
    close(in);
    close(out);
    return 0;
}