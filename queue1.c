#include <stdio.h>
#define MAX_SIZE 5

int Queue[MAX_SIZE], front = -1, rear = -1, count = 0;

int Qfull() {
  return count == MAX_SIZE; 
}
int Qempty() { 
    return count == 0; 
}

void insert(int ele) {
    if (Qfull()) {
        printf("\nQueue is full\n");
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    Queue[rear] = ele;
    count++;
    if (front == -1) front = 0;
}

int deleteq() {
    if (Qempty()) {
        printf("\nQueue is empty\n");
        return -1;
    }
    int ret = Queue[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return ret;
}

void display() {
    if (Qempty()) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = 0, j = front; i < count; i++, j = (j + 1) % MAX_SIZE) {
        printf("%d ", Queue[j]);
    }
    printf("\n");
}

int main() {
    int ch, ele;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &ele);
            insert(ele);
        } else if (ch == 2) {
            int deleted = deleteq();
            if (deleted != -1) printf("Deleted: %d\n", deleted);
        } else if (ch == 3) {
            display();
        } else if (ch == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
