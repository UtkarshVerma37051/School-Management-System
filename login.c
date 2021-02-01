#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include <windows.h>
#define SIZE 32
//#include"adminTeacher.c"
//#include"reset_password.c"
#include"Admin.c"
void LOGIN()
{
    char pwd[SIZE],pd[SIZE],ch;
    char option;
    //Read inbuild passward
    FILE *fp;
    FILE *fp1;
    char path[100];
    fp=fopen("./pswrd","rb");

    if(fp == NULL)
    {
        fclose(fp);
        FILE *fptr=fopen("./pswrd","wb");
        fprintf(fptr,"abcd1234");
        fclose(fptr);
    }
    fp=fopen("./pswrd","rb");
    fscanf(fp,"%s",pwd);
    fclose(fp);
    //printf("\nPwd is %s",pwd);
    //Login details
    ENTER_PASSWARD:
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\tPLEASE ENTER THE LOGIN PASSWORD: ");
    int p=0;
    do
    {
        pd[p]=getch();
        if(pd[p]!='\r')
        {
            if(pd[p]=='\b' && p>0)
            {
                    p=p-2;
                    printf("\b \b");
            }
            else if(pd[p]!='\b')
                printf("*");
        }
        if(pd[p]!='\b')
            p++;
    }while(pd[p-1]!='\r');
    pd[p-1]='\0';

    if(strcmp(pwd,pd)==0)
    {
        printf("\n\n \t\t\t\t\tWELCOME........LOGIN IN SUCESSFULLY ");
        printf("\n\n \t\t\t\t\tPLEASE WAIT . . . ");
        Sleep(1000);
        system("cls");
        admin();
    }
    else
    {
        printf("\n\n \t\t\t\t\tIncorrect Login!");
        printf("\n\n \t\t\t\t\tPLEASE WAIT . . . ");
        Sleep(1000);
        system("cls");
        goto ENTER_PASSWARD;
    }

}
