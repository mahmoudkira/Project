#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int ID;
    char name[50];
    char birthday[50];
    int score;
    struct Student *next;      }

 * head;
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


void  insert_end(int ID, char* name, char* birthday,int score)
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


        printf("ID : %d\n", ptr->ID);
        printf("Name: %s\n", ptr->name);
        printf("birthday: %s\n", ptr->birthday);
        printf("score: %d\n", ptr->score);
        ptr = ptr->next;}}

    int main (){
    int ID;
    char name[50];
    char birthday[50];
    int score;
    char i;
    int j=0;
    printf("Welcome :) \n");
while (1){
        printf("Choose one of this instructions ==>)\n");
        printf(" 1)Insret student  \n");
        printf(" 2)Insret student at the middle  \n");
        printf(" 3)Insret student at the end \n");
        printf(" 4)Display student data \n");
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
                insert_end(ID,name,birthday,score);}
                break;
            case 4:
                display();
                break;
        }}

        return 0;}



