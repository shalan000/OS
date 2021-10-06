#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

void main () {
    key_t key = ftok("shmfile" , 30);

    int shmid = shmget(key , 0 , 0);

    char *str  = (char*) shmat(shmid,NULL,0);
    printf("Data read from memory : %s\n",str);

    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
}
