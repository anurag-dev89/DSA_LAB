#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int Queue[MAX_SIZE];
int front = -1;
int rear = -1;
int count = 0;

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
    if (front == -1) {
        front = 0;
    }
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
    int i, j = front;
    printf("\nElements in the Queue:\n");
    for (i = 0; i < count; i++) {
        printf(" %d", Queue[j]);
        j = (j + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int ch, ele, flag = 1;
    while (flag) {
        printf("\nMenu\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (Qfull()) {
                    printf("\nQueue is full\n");
                } else {
                    printf("Enter the value to insert: ");
                    scanf("%d", &ele);
                    insert(ele);
                }
                break;

            case 2:
                if (!Qempty()) {
                    ele = deleteq();
                    printf("\nDeleted element: %d\n", ele);
                } else {
                    printf("\nQueue is empty\n");
                }
                break;

            case 3:
                display();
                break;

            case 4:
                flag = 0;
                break;

            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
