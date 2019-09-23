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
int main()
{
    system("cls");
    char op;
    XY:
        printf("\t\t\t\t\t|'''''''''''''''''''''''''''''|\n");
        printf("\t\t\t\t\t| LOGISTICS MANAGEMENT SYSTEM |\n");
        printf("\t\t\t\t|.............................|\n\n");
        printf("Enter R to register\n");
        printf("Enter L to login\n");
        scanf(" %c", &op);
        op = toupper(op);
        if(op=='R')
        {
        system("cls");
        reg();
        }
        else if (op=='L')
        {
        system("cls");
        login();
        }
        else
        {
            printf("NO MATCH FOUND\n");
            printf("Press Enter to Re-Enter your choice");
            if(getch()==13)
                system("cls");
                goto XY;
        }
return 0;
 }
  void reg()
  {
    FILE *fp;
    char c,checker[30];int sap;
    fp=fopen("stu_reg.txt","a+");
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");
    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
             system("cls");
            reg();
            }
            else
          {
            strcpy(w[i].name,checker);

          }
        }

         printf("\n\n\t\t\t\t ENTER SAP-ID: ");
         scanf("%d",&sap);
         fwrite(&sap,sizeof(w[i]),1,fp);
         fclose(fp);
         printf("\n\n\tPress enter if you agree with Username and Password");
       if((c=getch())==13)
        {
        system("cls");
        printf("\n\n\t\tYou are successfully registered");
        }
        break;
     }
     getch();
  }
    void login()
    {
       printf("hi");
       getch();
    }
