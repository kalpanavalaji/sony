#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
void *thread1function(void *arg);
void *thread2function(void *arg);
pthread_t thread1,thread2,threadself;
FILE *fp,*fp1;
char filename[100], str1[100],str2[20];
int main(int argc,char *argv[])
{
	threadself=pthread_self();

	int tid1,tid2,sig;
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
	sigprocmask(SIG_BLOCK,&set,NULL);
	strcpy(filename,argv[1]);
	tid1=pthread_create(&thread1,NULL,&thread1function,NULL);
	if(tid1!=0)
		printf("thread1 create unsuccessfully\n");
	else
		printf("thread1 created successfully\n");
	tid2=pthread_create(&thread2,NULL,&thread2function,NULL);
	if(tid2!=0)
		printf("thread2 create unsuccessfully");
	else
		printf("thread2 created successfully\n");
	fp1=fopen(argv[2],"w");
	if(fp1==NULL)
		printf("fp1 is not open");
	if(thread1)
		pthread_kill(thread1,SIGUSR1);
	else
		printf("thread1 is not created");
	sigwait(&set,&sig);
	while(!feof(fp))
	{

		fprintf(fp1,"%s",str1);
		  fprintf(fp1,"%s"," ");
		memset(str1,'\0',strlen(str1));
		fprintf(fp1,"%s",str2);
		 fprintf(fp1,"%s"," ");
		memset(str2,'\0',strlen(str2));

		pthread_kill(thread1,SIGUSR1);
		sigwait(&set,&sig);
	}
	fclose(fp1);
	fclose(fp);
	return 0;

}

void *thread1function(void *arg)
{       int sig;
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
	sigprocmask(SIG_BLOCK,&set,NULL);
	//int m,i,l,n=0;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("fp is not open\n");

	}

	sigwait(&set,&sig);
	while((fscanf(fp,"%s",str1))!=EOF)
	{

		printf("t1 %s\n",str1);
		pthread_kill(thread2,SIGUSR1);
		sigwait(&set,&sig);

	}
	if(thread2)
		pthread_kill(thread2,SIGUSR1);
	else		
		printf("thread1 is not create");
	pthread_exit(0);
}


void *thread2function(void *arg)
{	
	int sig;
	sigset_t set;
	sigemptyset(&set);

	sigaddset(&set,SIGUSR1);

	sigprocmask(SIG_BLOCK,&set,NULL);

	//fp=fopen(str,"r");
	if(fp==NULL)
		//printf("fp is not open");

		sigwait(&set,&sig);
	while(((fscanf(fp,"%s",str2))!=EOF)&&(thread2))
	{
		printf("t2 %s\n",str2);                                                              
		pthread_kill(threadself,SIGUSR1);
		sigwait(&set,&sig);
	}

	if(threadself)
		pthread_kill(threadself,SIGUSR1);
	else
		printf("thread1 is not open");


	pthread_exit(0);
}
