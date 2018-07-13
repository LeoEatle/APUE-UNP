#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
// 这个程序实现了 ls -l | grep rwxrwxr-r 这么一个命令的相同效果
// 但是由于使用的是popen，每次都会启动一次sh命令，导致资源浪费
// 如果直接使用pip调用就能更加方便高效

int main()
{
	FILE *read_fp = NULL;
	FILE *write_fp = NULL;
	char buffer[BUFSIZ + 1];
	int chars_read = 0;
	
	//初始化缓冲区
	memset(buffer, '\0', sizeof(buffer));
	//打开ls和grep进程
	read_fp = popen("ls -l", "r");
	write_fp = popen("grep rwxrwxr-x", "w");
	//两个进程都打开成功
	if(read_fp && write_fp)
	{
		//读取一个数据块
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while(chars_read > 0)
		{
			buffer[chars_read] = '\0';
			//把数据写入grep进程
			fwrite(buffer, sizeof(char), chars_read, write_fp);
			//还有数据可读，循环读取数据，直到读完所有数据
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		//关闭文件流
		pclose(read_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
