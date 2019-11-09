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
    int floor_res= funcfloor();

}
int funcfloor()
{

    FILE *fp;
    fp=fopen("block.txt","r+");
    char ch;
    int i=0;
    char f[50];
    int flag=0;

    while( !feof(fp) )
    {
        ch=fgetc(fp);
        printf("%c",ch);
        if(ch==';')
        {
            flag = 1;

        if(flag==1)
        {
            if(ch!=';')
            {

            }
            else{
                strncat(f,&ch,1);

            printf("%d",f);
            }
        }
        }



    }
}
