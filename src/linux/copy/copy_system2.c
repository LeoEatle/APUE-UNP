#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
 
int main()
{
	char buff[1024];
	int in = -1, out = -1;
	int nread = 0;
 
	in = open("Data.txt", O_RDONLY);
	out = open("copy_system2.out.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    //一次读写1024个字节 效率更高
	while((nread = read(in, buff, sizeof(buff))) > 0)
		write(out, buff, nread);
 
	close(in);
	close(out);
	return 0;
}
