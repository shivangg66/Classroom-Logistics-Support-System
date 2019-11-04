#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
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
        int check;
        char sap[10];
        char password[50],ch;
        system("cls");
        setup();
        printf("Enter your sap id: ");
        scanf("%s",&sap);
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
    printf("\n");
    check = checkpass(sap,password,p);
    if(check==0)
    {
        printf("Login Successful...");
        Sleep(2000);
        system("cls");
        int blockres= funcblock();
    }
    else
    {
        printf("You entered wrong details");
        Sleep(2000);
        login();
    }

    }
int checkpass(char sap[10], char pass[50],int p)
{
    FILE *fp;
    fp=fopen("stu_reg.txt","r+");
    char sap_check[50]="";
    char pass_check[50]="";
    char ch1,ch2;
    int result_sap,result_pass,i=0;
    while(!feof(fp))
    {
        here:
        ch1=fgetc(fp);
        if(ch1==',')
        {
            result_sap = strcmp(sap_check,sap);
            if(result_sap==0)
            {
                while(!feof(fp))
                {
                    ch2 = fgetc(fp);
                    if(ch2=='\n')
                    {
                        result_pass = strcmp(pass_check, pass);
                        if(result_pass==0)
                        {
                            return result_pass;
                            break;
                        }
                        else
                        {
                            return 1;
                            break;
                        }
                    }
                    else{
                        strncat(pass_check,&ch2,1);
                    }
                }
            }
            else
            {
                while(!feof(fp))
                {
                    ch1=fgetc(fp);
                    if(ch1=='\n')
                    {
                        sap_check[0] = '\0';
                        pass_check[0] = '\0';
                        goto here;
                    }
                }
            }
        }
       else{
        strncat(sap_check,&ch1,1);
        //strcat(sap_check,ch1);
        }
    }

}
int funcblock()
{
    setup();
    FILE *fp;
    fp=fopen("block.txt","r+");
    int b,i=11;
    char ch;
    int flag = 1;
    char block[20];
    printf("Enter the integer value for relevant block number where the issue is\nBlock:");
    while( !feof(fp) )
        {
            ch = fgetc(fp);
            if(ch==';')
                {
                    flag = 0;
                }
            if(flag==1)
            {
                printf("%c",ch);
            }
            else if(ch=='\n')
            {
                flag = 1;
                printf("\nBlock:");
            }
            else
                continue;
        }
    printf("\n ");
    here:
    scanf("%d",&b);
    if(b>0 && b<=11)
    {
        printf("You selected block %d",b);
    }
    else
    {
        printf("No such block found. Please enter correct block number\n");
        goto here;
    }
    return b;


}

