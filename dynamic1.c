#include<stdio.h>
#include<stdlib.h>

#define max_desc 100
#define max_name 20

struct day{
    char name[max_name];
    int date;
    char desc[max_desc];
};
struct day* week;

void read(int days){
    week =(struct day*)malloc(days * sizeof(struct day));
    if(week==NULL){
       printf("memory allocation fail!");
       exit(1);
    }
    
    for(int i=0;i<days ;i++){
        printf("enter day name, day date ,activity for day\n:",i+1);
        scanf("%s %d %[^\n]s",week[i].name,&week[i].date,week[i].desc);
    } 
}
void display(int days){
    printf("---weekly cleander---\n");
    for(int i=0;i<days ;i++){
        printf("day %d:%s  date:%d  desc:%s\n",i+1,week[i].name,week[i].date,week[i].desc);
    }
}
int main(){
    int days;
    printf("enter number of days in week:");
    scanf("%d",&days);
    if(days>7){
        printf("invalid days");
    }
    read(days);
    display(days);
    free(week);
    return 0;
}

