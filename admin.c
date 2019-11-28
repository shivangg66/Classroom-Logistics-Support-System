#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
    setup();
    return 0;
}
void setup()
{
    system("cls");
    int a;
    printf("\t\t\t\t\t\tWelcome to A interface");
    printf("\nEnter your choice");
    printf("\n1. View Complaints");
    printf("\n2. Add Inventories");
    printf("\n3. Add Block");
    printf("\n4. Remove Solved Complaint");
    printf("\n0. Exit");
    printf("\n");
    scanf("%d",&a);
    switch(a)
    {
        case 0: exit(EXIT_SUCCESS);
        case 1: view_complaints();
                break;
        case 2: add_inventory();
                break;
        case 3: add_block();
                break;
        case 4: remove_complaint();
                break;
        default: printf("\nyou entered wrong choice");

    }
}
    void view_complaints()
    {
        system("cls");
        printf("\t\t\t\t\t\tWelcome to A interface\n");
        FILE *fp;
        char ch[50];
        fp=fopen("complaints.txt","r");
        printf("Complaints registered (room no,faulty inventory,description) -->\n\n ");
         while(!feof(fp))
        {
            fflush(stdin);
            fgets(ch,50,fp);
            printf("%s",ch);

        }
        printf("\nPress 0 to go back\n");
        int back;
        scanf("%d",&back);
        if(back==0)
        {
            setup();
        }
    }
    void add_inventory()
    {
        system("cls");
        printf("\t\t\t\t\t\tWelcome to A interface\n");
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
        printf("\nHow many inventories you want to add\n");
        scanf("%d",&n);
        switch(n)
        {

        case 0:
                printf("No inventories added.\n");
                Sleep(2000);
                setup();
                break;
        default:
                printf("Write the names of inventories you want to add\n");
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
                fprintf(fp2,"\n");
                for(int i=0;i<strlen(in2);i++)
                {
                    fprintf(fp2,"%s\n",in2[i]);
                    fflush(stdin);
                }
                fclose(fp2);
                printf("\nInventories added");
                int back;
                printf("\nPress 0 to go back\n");
                scanf("%d",&back);
                if(back==0)
                {
                    setup();
                }

        }


    }
    void add_block()
    {
        system("cls");
        printf("\t\t\t\t\t\tWelcome to A interface\n");
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
        Sleep(1000);
        setup();
    }

    void remove_complaint()
    {
        system("cls");
        printf("\t\t\t\t\t\tWelcome to A interface\n");
        FILE *fp1, *fp2;
        char ch[100],ch1;
        char filename[40];
        int delete_line, temp=1;
        fp1=fopen("complaints.txt","r");
         while(!feof(fp1))
        {

            fgets(ch,100,fp1);
            printf("%s",ch);

        }

        printf(" \n Enter line number of the line to be deleted:\n");
        scanf("%d", &delete_line);
        fp2 = fopen("replica.txt", "w");
        rewind(fp1);
        ch1 = getc(fp1);
        while (ch1 != EOF)
        {
            ch1 = getc(fp1);
            if (ch1 == '\n')
                    temp++;
            if (temp != delete_line)
            {
                putc(ch1, fp2);

            }
        }
        fclose(fp1);
        fclose(fp2);
        remove("complaints.txt");
        char oldname[]="replica.txt";
        char newname[]="complaints.txt";
        rename(oldname,newname);
        system("cls");
        printf("\t\t\t\t\t\tWelcome to A interface\n");
        printf("\n The contents of file after being modified are as follows:\n");
        fp1 = fopen("complaints.txt", "r");
         while(!feof(fp1))
        {
            fgets(ch,100,fp1);
            printf("%s",ch);
        }
        fclose(fp1);
        printf("\nPress 0 to go back\n");
        int back;
        scanf("%d",&back);
        if(back==0)
        {
            setup();
        }

    }



