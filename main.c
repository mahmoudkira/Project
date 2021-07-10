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
