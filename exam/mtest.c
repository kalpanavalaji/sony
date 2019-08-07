#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<error.h>
void *thread1fun(void*);
void *thread2fun(void*);
char *reverse(const char*);

FILE *fp;
pthread_t thread1,thread2;
char filename[30];
char word[10], fileword[100];
void signalhandler1(int signo1) {
	if (signo1 == SIGUSR1) {
		//printf("Caught SIGUSR1 signal.\n");
	}
}
void signalhandler2(int signo2) {
	if (signo2 == SIGUSR2) {
		//printf("Caught SIGUSR1 signal.\n");
	}
}

int main(int argc,char *argv[])
{


	strcpy(filename,argv[1]);
	strcpy(word,argv[2]);

	int tid1,tid2;
	tid1=pthread_create(&thread1, NULL,thread1fun, NULL);
	if(tid1!=0)
		printf("pthread1 create unsuccessful\n");
	else
		printf("pthread1 create successful\n");

	pthread_create(&thread2, NULL, thread2fun, NULL); 
	if(tid2!=0)
		printf("pthread2 create unsuccessful\n");
	else
		printf("pthread2 create successful\n");



	pthread_join(thread1, NULL); 
//	pthread_join(thread2, NULL); 
	//pthread_exit(0);
}
void *thread1fun(void* arg)
{

	
		sleep(1);
	signal(SIGUSR1,signalhandler1);
	int signo1;
	sigset_t set1;
	sigemptyset(&set1);
	sigaddset(&set1,SIGUSR1);

	fp=fopen(filename,"r+");
	while((fscanf(fp,"%s",fileword))!=EOF)
	{

		printf("%s\n",fileword);
		pthread_kill(thread2,SIGUSR2);
		sigwait(&set1,&signo1);
		//pthread_exit(0);

	

	}
	pthread_kill(thread2,SIGUSR2);	
	pthread_exit(0);
}
void *thread2fun(void* arg)
{
	//	char  *word="the";
//		sleep(1);
	signal(SIGUSR2,signalhandler2);
	int signo2;
	sigset_t set2;
	sigemptyset(&set2);
	sigaddset(&set2,SIGUSR2);
	char *rev;
	int count=0,i,j;
	sigwait(&set2,&signo2);
	//if((strcasecmp(str,world))==0)
	while(!feof(fp))
	{
		if(strlen(fileword)==strlen(word))
		{
			for(i=0;fileword[i]&&word[i];i++)
			{
				if(fileword[i]==word[i]||(fileword[i]+32)==word[i]||(fileword[i]-32)==word[i])
				{
					continue;
				}
				else
					break;

			}
			if(word[i]=='\0')
			{
				rev=reverse(fileword);
				printf("%s",rev);
				fseek(fp,-strlen(rev),1);
				fprintf(fp,"%s",rev);
			}
		}

		pthread_kill(thread1,SIGUSR1);
		//	sigwait(&set2,&signo2);

	}

	//pthread_kill(thread1,SIGUSR1);
	pthread_exit(0);
}
char *reverse(const char* fileword)
{
	char *buff;
	int i,j,k,temp;
	buff=malloc(sizeof(char)*(strlen(fileword)));
	memcpy(buff,fileword,sizeof(char)*strlen(fileword));
	int len=strlen(buff);
	for(i=0,j=strlen(buff)-1;i<j;i++,j--)
	{
		temp=buff[i];
		buff[i]=buff[j];
		buff[j]=temp;
	}
	return buff;
}

