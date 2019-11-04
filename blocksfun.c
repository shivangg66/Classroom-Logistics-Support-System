#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void setup()
{
    system("cls");
    printf("\t\t\t\t\t|'''''''''''''''''''''''''''''|\n");
    printf("\t\t\t\t\t| LOGISTICS MANAGEMENT SYSTEM |\n");
    printf("\t\t\t\t\t|.............................|\n\n");
}
int main()
{
     system("cls");
     setup();
    int blockres= funcblock();

}
int funcblock()
{
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
