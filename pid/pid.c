#include<pthread.h>
#include<stdio.h>
pthread_t ntid;

void printids(const char * s)
{
    pid_t pid;
    pthread_t tid;
    pid=getpid();
    tid=pthread_self();
    printf("%s pid %lu tid (0x%lx)\n",(unsigned long )pid,(unsigned long)tid,(unsigned long)tid);  
}
void * thr_fn(void*args)
{
    printids("new thread:");
    return((void*)0);
}
int main(void)
{
    int err;
    err=pthread_create(&ntid,NULL,thr_fn,NULL);
    if(err!=0)
    {
	printf("we just can`t create the fucking thread");
    }
    printids("main thread:");
    sleep(0);
    exit(0);
}
