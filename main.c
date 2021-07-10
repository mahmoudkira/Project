#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
    int ID;
    char name[50];
    char birthday[50];
    int score;
    struct Student *next;
}* head,*ptr;
int n;
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
        //printf("%d",ptr[j]);
        if (j<n-1)
            printf("---------------------------------------------");
    }

}
int main()
{   clock_t begin=clock();
    while (1){char i;
            printf("Choose one of this instructions ==>)\n");
            printf(" 1)Insret student  \n");
            printf(" 2)Insret student at the middle  \n");
            printf(" 3)Insret student at the end \n");
            printf(" 4)Display student data \n");
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
        }}
    clock_t end=clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution time is %f ",time_spent);
    return 0;
}
