#include<iostream>
#include<pthread.h>
#include<cstdlib>
using namespace std;
#define THREAD_NUM 5
void * fuck(void*args)
{
    int tid=*((int*)args);
    cout<<"线程ID，"<<tid<<endl;
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[THREAD_NUM];
    int indexes[THREAD_NUM];
    int rc;
    int i;
    for(int i=0;i<THREAD_NUM;i++)
    {
	cout<<"main():创建线程:"<<i<<endl;
	indexes[i]=i;
	rc=pthread_create(&threads[i],NULL,fuck,(void*)&(indexes[i]));
	if(rc)
	{
	    cout<<"Error:"<<rc<<endl;
	    exit(-1);
	}
    }
    cout<<"fuck"<<endl;
    pthread_exit(NULL);
}
