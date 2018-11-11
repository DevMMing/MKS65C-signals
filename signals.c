#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

static void sighandler( int signum){
    if (signum == SIGINT){
	char *c = (char *) calloc(100, sizeof(char)); 
        int file=open("file.txt",O_APPEND | O_WRONLY | O_CREAT);
        write(file, "the program exited due to SIGINT\n",strlen("the program exited due to SIGINT\n"));
        printf("Signal %d\n",signum);
		close(file);
    exit(0);
	}
	if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
		printf("Parent Process: %d\n",getppid());
    }
}
int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("Process: %d\n",getpid());
    sleep(1);
  }
  return 0;
}
