#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(){
  signal(SIGINT, sighandler)
  while(1){
    printf("Process: %d",getpid());
    sleep(1);
    printf("Parent Process: %d",getppid());
    sleep(1);
  }
  return 0;
}

static void sighandler( int signum){
  printf("Signal %d",signum)
    exit();
}
