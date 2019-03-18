#include<iostream>
#include<pthread.h>
using namespace std;
#define THREAD_NUM 5
void * fuck(void*args)
{
    cout<<"hello fuck"<<endl;
}
int main()
{
    pthread_t tid[THREAD_NUM];
    for(int i=0;i<THREAD_NUM;i++)
    {
	int ret=pthread_create(&tid[i],NULL,fuck,NULL);
	if(ret!=0)
	{
	    cout<<"pthread_create_error:error code="<<ret<<endl;
	}
    }
    pthread_exit(NULL);
}
