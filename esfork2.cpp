#include <stdio.h>
#include <iostream>
#include <sys/shm.h>

using namespace std;

struct F4info{
    char Nome1[50];
    char Pedina1;
    char Nome2[50];
    char Pedina2;
};

int main()
{
    key_t shm_key_x = ftok(".", 0);
    int shm_id_x = shmget(shm_key_x, sizeof(char), IPC_CREAT | 0666);
    
    char *shm_data_x = (char *)shmat(shm_id_x, NULL, 0);
    
    cin >> *shm_data_x;
    
    key_t shm_key_o = ftok(".", 0);
    int shm_id_o = shmget(shm_key_o, sizeof(char), IPC_CREAT | 0666);
    
    char *shm_data_o = (char *)shmat(shm_id_o, NULL, 0);
    
    *shm_data_o = 'O';
    
    
    
    return 0;
}
