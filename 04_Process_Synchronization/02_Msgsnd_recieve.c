#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define MSG_SIZE 100
#define PERMISSIONS 0666

struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    int msgid;
    struct msg_buffer message;
    msgid = msgget(IPC_PRIVATE, PERMISSIONS | IPC_CREAT);

    if (fork() == 0) { 
        message.msg_type = 1;
        printf("Child: Enter a message: ");
        fgets(message.msg_text, sizeof(message.msg_text), stdin);
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Child: Message sent\n");
    } else {

        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Parent: Received message: %s", message.msg_text);
    }

    return 0;
}
