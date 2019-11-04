#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
static int i=0;
struct minor
{
char name[30];
}w[99];
int n;
void login(void);
void reg(void);
void setup()
{
    system("cls");
    printf("\t\t\t\t\t|'''''''''''''''''''''''''''''|\n");
    printf("\t\t\t\t\t| LOGISTICS MANAGEMENT SYSTEM |\n");
    printf("\t\t\t\t\t|.............................|\n\n");
}
int main()
{
    login();
    return 0;

}

    void login()
    {
        int sap;
        char password[50],ch;
        system("cls");
        setup();
        printf("Enter your sap id: ");
        scanf("%d",&sap);
        printf("Enter your pass: ");
        int p=0;
    do
    {
        ch = getch();
        if(ch==8)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            p--;
            continue;
        }
        password[p]=ch;
        if(password[p]!='\r'){
                ch= '*';
            putch(ch);
        }
        p++;
    }while(password[p-1]!='\r');
    password[p-1]='\0';
    checkpass(sap, pass);

    }
    int checkpass(int sap, char pass[50])
    {
        FILE *fp;
     fp=fopen("stu_reg.txt","r+");
     int sap_check;
     char pass_check[50];


    }
