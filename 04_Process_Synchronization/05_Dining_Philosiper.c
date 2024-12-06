#include <stdio.h>
#define n 5
int forks[n] = {1, 1, 1, 1, 1};
int philosiper_state[n];

void eating(int Philosiper) {
    printf("Philosiper %d is eating\n", Philosiper);
    philosiper_state[Philosiper] = 0;
}

void thinking(int Philosiper) {
    printf("Philosiper %d is thinking\n", Philosiper);
    philosiper_state[Philosiper] = 1;
}

void displayState() {
    for (int i = 0; i < n; i++) {
        if (philosiper_state[i] == 1) {
            printf("Philosiper %d is thinking\n", i);
        } else {
            printf("Philosiper %d is eating\n", i);
        }
    }
}

int main() {
    int choice;
    for (int i = 0; i < n; i++) {
        philosiper_state[i] = 1;
    }
    while (1) {
        printf("Enter choices : \n1. Philosiper 0\n2. Philosiper 1\n3. Philosiper 2\n4. Philosiper 3\n5. Philosiper 4\n6. Display State\n7. Exit\n");
        scanf("%d", &choice);
        int philosopher = choice - 1;
        if (choice >= 1 && choice <= 5) {
            if (forks[philosopher] == 1 && forks[(philosopher + 1) % n] == 1) {
                forks[philosopher] = 0;
                forks[(philosopher + 1) % n] = 0;
                eating(philosopher);
                forks[philosopher] = 1;
                forks[(philosopher + 1) % n] = 1;
            } else {
                printf("Philosiper %d cannot eat because forks are not available\n", philosopher);
            }
        } else if (choice == 6) {
            displayState();
        } else if (choice == 7) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
