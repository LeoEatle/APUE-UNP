#include <stdio.h>
#include <signal.h>
#include <unistd.h> // unix standard

void ouch(int sig) {
    printf("\n Ouch! I got signal %d \n", sig);
    (void) signal(sig, SIG_DFL); // Signal Default 恢复终端中断信号SIGINT默认行为（第二次Ctrl+C）时
}

int main() {
    // 改变终端信号SIGINT的默认行为，SIGINT即由Ctrl+C产生
    (void) signal(SIGINT, ouch);
    while(1) {
        printf("\nI will never stop!");
        sleep(1);
    }
    return 0;
}

