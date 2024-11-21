#include<stdio.h>

#define MAX_DESC 100
#define MAX_NAME 20

struct day {
    char name[MAX_NAME];
    int date;
    char description[MAX_DESC];
};
struct day week[7];

void read() {
    for (int i = 0; i < 7; i++) {
        printf("Enter day name, date, and activity description for day %d:\n", i + 1);
        scanf("%s %d %[^\n]s ", week[i].name, &week[i].date, week[i].description);
    }
}

void display() {
    printf("\n--- Weekly Calendar ---\n");
    for (int i = 0; i < 7; i++){
        printf("Day %d: %s, Date: %d, Activity: %s\n",i+1, week[i].name, week[i].date, week[i].description);
    }
}

int main() {
    printf("Enter details for each day:\n");
    read();
    display();
    return 0;
}