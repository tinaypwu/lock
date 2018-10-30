#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <bits/pthreadtypes.h>

#define SIZE 10000
#define TRUE 1
#define FALSE 0

int data[SIZE];
int myindex = 0;
//定义互斥锁变量并初始化
static pthread_rwlock_t myrwlock;

void *thread_func1(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;){
		//进入临界区
		pthread_rwlock_wrlock(&myrwlock);
		//临界区
			data[myindex++] = i;
			i+=2;
			//printf("write thread 1:write data=%d\n",data[myindex%SIZE]);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}

void *thread_func2(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;){
		//进入临界区
		pthread_rwlock_wrlock(&myrwlock);
		//临界区
			data[myindex++] = i;
			i+=2;
			//printf("write thread 2:write data=%d\n",data[myindex%SIZE]);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func3(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func4(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func5(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func6(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func7(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func8(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func9(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
void *thread_func10(void *arg){
	int i,j;
	//thread 1
	for(i=0;i<SIZE;i++){
		//进入临界区
		pthread_rwlock_rdlock(&myrwlock);
		//临界区
			j = data[myindex];
			//printf("read thread 1: read data = %d\n",j);
		//退出临界区
		pthread_rwlock_unlock(&myrwlock);	
	}
	return NULL;
}
int main(){
	pthread_t mythread1,mythread2,mythread3,mythread4,mythread5,mythread6,mythread7,mythread8,mythread9,mythread10;
	int res;
	res=pthread_rwlock_init(&myrwlock,NULL);//初始化读写锁
	if (res != 0){
		perror("rwlock initialization failed");
		exit(EXIT_FAILURE);
	}
	struct timeval start,finish;
	int i;
	gettimeofday(&start,NULL);
	//创建线程1
	if(pthread_create(&mythread1,NULL,thread_func1,NULL)){
		printf("error creating thread1.\n");
		abort();
	}
	//创建线程2
	if(pthread_create(&mythread2,NULL,thread_func2,NULL)){
		printf("error creating thread2.\n");
		abort();
	}
	if(pthread_create(&mythread3,NULL,thread_func3,NULL)){
		printf("error creating thread3.\n");
		abort();
	}
	if(pthread_create(&mythread4,NULL,thread_func4,NULL)){
		printf("error creating thread4.\n");
		abort();
	}
	if(pthread_create(&mythread5,NULL,thread_func5,NULL)){
		printf("error creating thread5.\n");
		abort();
	}
	if(pthread_create(&mythread6,NULL,thread_func6,NULL)){
		printf("error creating thread5.\n");
		abort();
	}
	if(pthread_create(&mythread7,NULL,thread_func7,NULL)){
		printf("error creating thread5.\n");
		abort();
	}
	if(pthread_create(&mythread8,NULL,thread_func8,NULL)){
		printf("error creating thread5.\n");
		abort();
	}
	if(pthread_create(&mythread9,NULL,thread_func9,NULL)){
		printf("error creating thread5.\n");
		abort();
	}
	if(pthread_create(&mythread10,NULL,thread_func10,NULL)){
		printf("error creating thread5.\n");
		abort();
	}
	if(pthread_join(mythread1,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread2,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread3,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread4,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread5,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread6,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread7,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread8,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread9,NULL)){
		printf("error joining thread\n");
		abort();
	}
	if(pthread_join(mythread10,NULL)){
		printf("error joining thread\n");
		abort();
	}
	
	gettimeofday(&finish,NULL);

	printf("run time = \t%ld ns\n",(finish.tv_sec - start.tv_sec)*1000000000 + (finish.tv_usec - start.tv_usec)*1000);
	pthread_rwlock_destroy(&myrwlock);//销毁读写锁               
	exit(EXIT_SUCCESS);
	return 0;	
}
