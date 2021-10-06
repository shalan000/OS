#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
int f= fork();
if(f==0)
{
printf("Child is executing\n");
}
else
{
wait(NULL);
printf("Parent is executing\n");
}
}
