#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
inventory();
}
void inventory()
{
    FILE *fp;
    char ch[50];
    fp=fopen("inventories.txt","r+");
    while( fgets(ch,30,fp)!= NULL )
        {

}
}
