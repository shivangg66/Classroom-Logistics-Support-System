#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{   int a;
    printf("\t\t\t\t\t\tWelcome to admin interface");
    printf("\nEnter your choice");
    printf("\n1. view complaints");
    printf("\n2. add inventories");
    printf("\n3. add block");
    printf("\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1: view_complaints();
                break;
        case 2: add_inventory();
                break;
        case 3: add_block();
                break;
        default: printf("\nyou entered wrong choice");

    }
}
    void view_complaints()
    {
        FILE *fp;
        char ch[50];
        fp=fopen("complaints.txt","r+");
        printf("Complaints registered (room no,faulty inventory,description) -->\n\n ");

         while(!feof(fp))
        {
            fgets(ch,50,fp);
            printf("%s",ch);
        }
    }
    void add_inventory()
    {
        printf("\nPresent list of inventories\n\n");
        FILE *fp;
        char ch[50];
        int n;
        char in[20];
        char in2[50][50];
        fp=fopen("inventories.txt","r+");
         while(!feof(fp))
        {
            fgets(ch,50,fp);
            printf("%s",ch);
        }
        fclose(fp);
        printf("How many inventories you want to add\n");
        scanf("%d",&n);
        switch(n)
        {

        case 1:
                printf("write the name of inventory you want to add\n");
                scanf("%s",&in);
                FILE *fp1;
                fp1=fopen("inventories.txt","a+");
                fprintf(fp1, "\n");
                for(int i=0;i<strlen(in);i++)
                {
                    fputc(in[i],fp1);
                }
                fclose(fp1);
                printf("inventory added");
                break;
        default:
                printf("write the names of inventories you want to add\n");
                for(int i=0;i<n;i++)
                {

                    scanf("%s",in2[i]);
                }
                for(int i=0;i<n;i++)
                {
                    printf("\n");
                    printf("%s",in2[i]);
                }
                FILE *fp2;
                fp2=fopen("inventories.txt","a+");

                for(int i=0;i<strlen(in2);i++)
                {
                    fprintf(fp2,"%s\n",in2[i]);
                }
                fclose(fp2);
                printf("\nInventories added");
        }
    }
    void add_block()
    {
        char newb[10],newf[2],newc[2],semi[2]=";";
        printf("Enter the name of block you want to add\n");
        scanf("%s",&newb);
        printf("Enter No of floors on that block\n");
        scanf("%s",&newf);
        printf("Enter No of classrooms each floor\n");
        scanf("%s",&newc);
        strcat(newb,semi);
        strcat(newb,newf);
        strcat(newb,semi);
        strcat(newb,newc);
        FILE *fp;
        fp=fopen("block.txt","a+");
        fprintf(fp,"\n");
        for(int i=0;i<strlen(newb);i++)
        {
            fputc(newb[i],fp);
        }
        fclose(fp);
        printf("\nBlock added successfully");


    }
