#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

static int alarm_fired = 0;

void ouch(int sig) {
    alarm_fired = 1;
}
 
int main()
{
	pid_t pid;
	pid = fork();
	switch(pid)	{
        case -1:
            perror("fork failed\n");
            exit(1);
        case 0:
            //子进程
            sleep(5);
            //向父进程发送信号
            kill(getppid(), SIGALRM);
            exit(0);
        default:;
	}
	//设置处理函数
	signal(SIGALRM, ouch);
	while(!alarm_fired) {
		printf("Hello World!\n");
		sleep(1);
	}
	if(alarm_fired)
		printf("\nI got a signal %d\n", SIGALRM);
 
	exit(0);
}
