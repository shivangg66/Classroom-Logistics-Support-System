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
void setup()
{
    system("cls");
    printf("\t\t\t\t\t|'''''''''''''''''''''''''''''|\n");
    printf("\t\t\t\t\t| LOGISTICS MANAGEMENT SYSTEM |\n");
    printf("\t\t\t\t\t|.............................|\n\n");
}
int main()
{
    int block_res,floor_res,classroom,class_res;
    char bl[2], fl[2], cl[20], c[100];
    block_res = login();
    floor_res= floor_cus(block_res,&classroom);
    system("cls");
    sprintf(bl, "%d", block_res);
    sprintf(fl, "%d", floor_res);
    cl[0]='\0';
    strncat(cl,&bl,1);
    strncat(cl,&fl,1);
    classrooms(cl,classroom,&c);
    register_complaint(c);
    return 0;

}

    int login()
    {

        int check;
        char sap[10];
        char password[50],ch;
        a:
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
        int blockres = funcblock();
        return blockres;
    }
    else if(check==2)
    {
        printf("Admin Login Successful...");
        Sleep(2000);
        admin_setup();

    }
    else
    {
        printf("You entered wrong details");
        Sleep(2000);
        goto a;
    }

    }
int checkpass(char sap[10], char pass[50],int p)
{
    FILE *fp;
    fp=fopen("stu_reg.txt","r+");
    char sap_check[50]="";
    char pass_check[50]="";
    char admin_sap[10]="111111111";
    char admin_pass[50]="adminpass";
    char ch1,ch2;
    int admin_res,result_sap,result_pass,i=0;
    admin_res = strcmp(sap,admin_sap);
    if(admin_res==0)
    {

        result_pass=strcmp(pass,admin_pass);
        if(result_pass==0)
        {
            return 2;
        }
        else
            return result_pass;
    }
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
    printf("\n");
    here:
    printf("Your choice: ");
    scanf("%d",&b);
    return b;


}
int floor_cus(int block,int* classroom)
{
    setup();
    FILE *fp;
    fp=fopen("block.txt","r+");
    char ch;
    int i=0;
    char bl[4];
    int f,floor,b;
    printf("\nENTER FLOOR NUMBER\n");
    while( !feof(fp) )
    {
        here:
        ch=fgetc(fp);
        if(ch==';')
        {
            bl[i]='\0';
            sscanf(bl, "%d", &b);
            if(b==block)
            {
            while( !feof(fp) )
            {
                ch=fgetc(fp);

                    f=(int)ch;
                    f=f-48;

                    for(int i=0;i<=f;i++)
                    {
                        printf("\nFLOOR:%d",i);
                    }
                    break;


            }
            break;
        }else
        {

            while(!feof(fp))
                {
                    ch = fgetc(fp);
                    if(ch=='\n')
                    {
                        bl[0]='\0';
                        i=0;
                        goto here;
                    }
                }
        }
        }
        else
        {
            strncat(bl,&ch,1);
            i++;

        }
    }
        printf("\n");
        fseek(fp,1,SEEK_CUR);
        ch=fgetc(fp);
        int classes=(int)ch;
        classes-=48;
        *classroom=classes;
        printf("Your choice: ");
        scanf("%d",&floor);
        return floor;
}
void classrooms(char cl[20], int classes, char* c[100])
{
    setup();
    printf("Enter the classroom number where the issue is\n");
    for(int i =1;i<=classes;i++)
    {
        if(i<10)
        {
            printf("%s%02d\n",cl,i);
        }
        else
        {
            printf("%s%d\n",cl,i);
        }
    }
    printf("Your choice: ");
    printf("\n");
    scanf("\n%s",c);
}
void register_complaint(char c[100])
{
    setup();
    FILE *fp, *fp1;
    char ch[50];
    char ans[50], desc[50];
    char comma[2]=",";
    char s, s1='S';
    printf("\nChoose faulty inventory from the following list-->\n");
    fp=fopen("inventories.txt","r");
    while(!feof(fp))
    {
        fgets(ch,50,fp);
        printf("%s",ch);
    }
    fclose(fp);
    printf("\n");
    printf("\nYour choice: ");
    scanf("\n%s",&ans);
    printf("\nAny description you want to add in not more than 50 words (otherwise write null)-->\n");
    scanf("\n%s",&desc);
    printf("Press S to submit or C to cancel\n");
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
    printf("Complaint registered successfully.");
    exit(EXIT_SUCCESS);
    }
    else if(s=='C')
    {
        exit(EXIT_FAILURE);
    }
    else{
        printf("You entered wrong key.");
    }


}
void admin_setup()
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
            admin_setup();
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
                admin_setup();
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
                    admin_setup();
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
        admin_setup();
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
            admin_setup();
        }

    }

