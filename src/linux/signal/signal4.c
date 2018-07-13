#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
 
static int alarm_fired = 0;
 
void ouch(int sig)
{
	alarm_fired = 1;
}
 
int main()
{
	//关联信号处理函数
	signal(SIGALRM, ouch);
	//调用alarm函数，5秒后发送信号SIGALRM
	alarm(5);
	//挂起进程
	pause();
	//接收到信号后，恢复正常执行
	if(alarm_fired == 1)
		printf("Receive a signal %d\n", SIGALRM);
	exit(0);
}
