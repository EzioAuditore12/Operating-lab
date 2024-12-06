#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *str;

    // Create a unique key for shared memory
    key_t key = ftok("shmfile", 65);

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    // Attach the shared memory segment to the address space
    str = shmat(shmid, NULL, 0);

    if (fork() == 0) { // Child process
        printf("Child: Enter a message: ");
        fgets(str, SHM_SIZE, stdin);

        // Detach from shared memory after writing
        shmdt(str);
    } else { // Parent process
        sleep(1); // Ensure the child writes first

        // Parent reads the shared memory
        printf("Parent: Received message: %s", str);

        // Detach from shared memory after reading
        shmdt(str);

        // Destroy the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
