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
    setup();
    register_complaint();
}
void register_complaint()
{
    FILE *fp, *fp1;
    char ch[50];
    char ans[50], desc[50];
    char c[100];
    char comma[2]=",";
    char s, s1='S';
    printf("Enter the classroom number where the issue is");
    printf("\n");
    scanf("\n%s",&c);
    printf("\nChoose faulty inventory from the following list-->\n");
    fp=fopen("inventories.txt","r");
    while(!feof(fp))
    {
        fgets(ch,50,fp);
        printf("%s",ch);
    }
    fclose(fp);
    printf("\n");
    scanf("\n%s",&ans);
    printf("\nAny description you want to add in not more than 50 words (otherwise write null)-->\n");
    scanf("\n%s",&desc);
    printf("Press S to submit\n");
    scanf("\n%c",&s);
    strcat(c,comma);
    strcat(c,ans);
    strcat(c,comma);
    strcat(c,desc);
    if(s==s1)
    {
    fp1=fopen("complaints.txt","a+");
    fprintf(fp1,"\n");
    for(int i=0;i<strlen(c);i++)
    {
            fputc(c[i],fp1);
    }
    fclose(fp1);
    printf("Complaint registered successfully");
    }
    else{
        printf("you entered wrong key");
    }


}
