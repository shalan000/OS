#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

void main () {
    key_t key = ftok("shmfile",30);
    int shmid = shmget(key , 1024 , 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid,NULL,0);
    printf("Write data : ");
    scanf("%s",str);

    printf("Data written in memory : %s\n",str);
    shmdt(str);
}