#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <time.h>

struct Student
{
    int ID;
    char name[50];
    char birthday[50];
    int score;
    struct Student *next;
}*head,*ptr;
int n;
void insert_begin(int ID,char* name, char* birthday ,int score)
{
    struct Student *stude = (struct Student*)malloc(sizeof(struct Student));
    stude->ID = ID;
    strcpy(stude->name, name);
    strcpy(stude->birthday, birthday);
    stude->score = score;
    stude->next = NULL;
    if(head==NULL){
        head = stude;
    }
    else{
            stude->next = head;
        head = stude;
    }

}
 void insert_middle (int ID,char* name, char* birthday ,int score)
    {
        struct Student *stude = (struct Student*)malloc(sizeof(struct Student));
        struct Student *temp;
        struct student *ptr;
        struct Student * temp1 = head;
        int i=0;
            stude->ID = ID;
            strcpy(stude->name, name);
            strcpy(stude->birthday, birthday);
            stude->score =score;
        if(head == NULL)
        {
            stude -> next = NULL;
            head = stude;
        }
        else
            {
            while(temp1!=NULL){

            i++;
            temp1 = temp1 -> next;}
                temp = head;
                for(int j=0;j<i/2-1;j++)
                {
                    temp = temp -> next;
                }
                ptr =temp->next ;
                stude->next = ptr;
                temp->next =stude;
            }
}
void lastinsert(int ID, char* name, char* birthday,int score)
    {
        struct Student *stude = (struct Student*)malloc(sizeof(struct Student));
        struct Student *ptr;
            stude->ID = ID;
            strcpy(stude->name, name);
            strcpy(stude->birthday, birthday);
            stude->score =score;
            if(head == NULL)
            {
                stude->next = NULL;
                head = stude;
            }
            else
            {
                ptr = head;
                while (ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                }
                ptr->next = stude;
                stude->next = NULL;
            }
        }
        void display()
{
    struct Student *ptr = head;
    while(ptr!=NULL){
        printf("\nID : %d\n", ptr->ID);
        printf("Name: %s\n", ptr->name);
        printf("birthday: %s\n", ptr->birthday);
        printf("score: %d\n", ptr->score);
        printf("---------------------------------------------");
        ptr = ptr->next;}}
void createDynamicArray()
{
    printf("Number of students => ");
    scanf("%d",&n);
    ptr = (struct Student*)malloc(n*sizeof(struct Student));
    for (int i=0; i<n; i++)
    {
        printf("Student ID => ");
        scanf("%d", &(ptr[i].ID));
        printf("Student name => ");
        scanf("%s", ptr[i].name);
        printf("Student birthday => ");
        scanf("%s", ptr[i].birthday);
        printf("Student Score => ");
        scanf("%d", &(ptr[i].score));
    }
}
void insertDynamicEnd()
{
    n=n+1;
    ptr = (struct Student*)realloc(ptr,n*sizeof(struct Student));
    printf("Student ID => ");
    scanf("%d", &(ptr[n-1].ID));
    printf("Student name => ");
    scanf("%s", ptr[n-1].name);
    printf("Student birthday => ");
    scanf("%s", ptr[n-1].birthday);
    printf("Student Score => ");
    scanf("%d", &(ptr[n-1].score));
}
void insertDynamicBeginning()
{
    n=n+1;
    struct Student *temp = (struct Student*)malloc(n*sizeof(struct Student));
    printf("Student ID => ");
    scanf("%d", &(temp[0].ID));
    printf("Student name => ");
    scanf("%s", temp[0].name);
    printf("Student birthday => ");
    scanf("%s", temp[0].birthday);
    printf("Student Score => ");
    scanf("%d", &(temp[0].score));
    for(int i=1;i<n;i++)
        temp[i]=ptr[i-1];
    ptr=temp;
}
void insertDynamicMiddle()
{
    n=n+1;
    struct Student *temp = (struct Student*)malloc(n*sizeof(struct Student));
    for(int i=0;i<(n/2);i++)
        temp[i]=ptr[i];
    printf("Student ID => ");
    scanf("%d", &(temp[n/2].ID));
    printf("Student name => ");
    scanf("%s", temp[n/2].name);
    printf("Student birthday => ");
    scanf("%s", temp[n/2].birthday);
    printf("Student Score => ");
    scanf("%d", &(temp[n/2].score));
    for(int i=(n/2)+1;i<n;i++)
        temp[i]=ptr[i-1];
    ptr=temp;
}
void displayDynamic()
{
    for (int j=0; j <n; j++)
    {
        printf("\nID : %d\n", ptr[j].ID);
        printf("Name: %s\n", ptr[j].name);
        printf("birthday: %s\n", ptr[j].birthday);
        printf("score: %d\n", ptr[j].score);
        if (j<n-1)
            printf("---------------------------------------------");
    }
}
int main (){
    int ID;
    char name[50];
    char birthday[50];
    int score;
    char i;
    int j=0;
    int choice;
    printf("Welcome :) \n");
    printf("For linked list press 1.\nFor dynamic array press 2.\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        clock_t begin=clock();
        while (i!=5){
            printf("\nChoose one of this instructions ==>)\n");
            printf(" 1)Insret student  \n");
            printf(" 2)Insret student at the middle  \n");
            printf(" 3)Insret student at the end \n");
            printf(" 4)Display student data \n");
            printf(" 5)Stop and print execution time \n");
            scanf("%d", &i);
             switch (i)
            {
                case 1:
                    printf("Number of students => ");
                    scanf("%d", &j);
                    for(int k=0;k<j;k++)
                        {
                    printf("Student ID => ");
                    scanf("%d", &ID);
                    printf("Student name => ");
                    scanf("%s", name);
                    printf("Student birthday => ");
                    scanf("%s", birthday);
                    printf("Student Score => ");
                    scanf("%d", &score);
                    insert_begin(ID,name,birthday,score);
                    }
                    break;
                case 2:
                    printf("Student ID => ");
                    scanf("%d", &ID);
                    printf("Student name => ");
                    scanf("%s", name);
                    printf("Student birthday => ");
                    scanf("%s", birthday);
                    printf("Student Score => ");
                    scanf("%d", &score);
                    insert_middle(ID,name,birthday,score);
                    break;
                case 3:
                    printf("Student ID => ");
                    scanf("%d", &ID);
                    printf("Student name => ");
                    scanf("%s", name);
                    printf("Student birthday => ");
                    scanf("%s", birthday);
                    printf("Student Score => ");
                    scanf("%d", &score);
                    lastinsert(ID,name,birthday,score);
                    break;
                case 4:
                    display();
                    break;
        }}
        clock_t end=clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution time is %f ",time_spent);
    }
    else if(choice==2)
    {
        clock_t begin=clock();
    while (i!=5){
            printf("\nChoose one of this instructions ==>)\n");
            printf(" 1)Insret student  \n");
            printf(" 2)Insret student at the middle  \n");
            printf(" 3)Insret student at the end \n");
            printf(" 4)Display student data \n");
            printf(" 5)Stop and print execution time \n");
            scanf("%d", &i);
             switch (i)
            {
                case 1:
                    insertDynamicBeginning();
                    break;
                case 2:
                    insertDynamicMiddle();
                    break;
                case 3:
                   insertDynamicEnd();
                    break;
                case 4:
                    displayDynamic();
                    break;
        }
        }
    clock_t end=clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution time is %f ",time_spent);
    }


        return 0;}



