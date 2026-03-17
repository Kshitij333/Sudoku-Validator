#include<stdio.h>
#include<stdlib.h>
void display();
void enter();
void check();
char board[9][9];
int main()
{
//get data from file
char ch;
FILE *ptr=fopen("data.txt","r");
for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
{
  if((ch=fgetc(ptr))!=EOF)
 {
        board[i][j]=ch;
    

 }
 
}
}
while(1)
{
    menu:
printf("MENU\n");
printf("1.Display\n2.Enter Values\n3.Quit\n4.Check\n");
int choice=0;
scanf("%d",&choice);
switch(choice)
{
   case 1:
   display();
   break;
   
   case 2:
   enter();
   break;

   case 3:
   printf("Game terminated\n");
   exit(0);

   case 4:
   printf("Checking\n");
   check();
   break;


}



}
}
void display()
{
for(int i=0;i<9;i++)
{
    for(int j=0;j<9;j++)
    {
        printf("%c",board[i][j]);
        printf("|");

    }
 printf("\n");
}

}
void enter()
{
    int t=0;
    printf("Enter number of boxs to be filled\n");
    scanf("%d",&t);
    while(t--)
    {
    int i=0,j=0;
printf("Enter row and column location\n");

scanf("%d%d",&i,&j);
scanf(" %c",&board[i][j]);
    }




}
void check()
{
//checking row
for(int i=0;i<9;i++)
{
    for(int j=0;j<9;j++)
    {
       char value=board[i][j];
       int y=j;//original value
       for(int k=0;k<9;k++)
       {
        if(value==board[i][k]&&(k!=y))
        {
            //we need to add case that will ignore partial values like 0
          printf("ROW DUPLICATION FOUND AT ROW-%d COL-%d of %c\n",i,k,value);
          goto menu;
        }
       }
       

    }
}
//checking columns
for(int i=0;i<9;i++)
{
    for(int j=0;j<9;j++)
    {
       char value=board[i][j];
       int x=i;//original value
       for(int k=0;k<9;k++)
       {
        if(value==board[k][j]&&(k!=x))
        {
            //we need to add case that will ignore partial values like 0
          printf("COL DUPLICATION FOUND AT ROW-%d COL-%d of %c\n",x,k,value);
          goto menu;
        }
       }
       

    }
}
//checking 3X3
int count[10];
for(int i=1;i<10;i++)
{
    count[i]=0;
}
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(count>0)
        {
        
            printf("Repetition found in 3X3 grid\n");
            goto menu;
        }
        else
        {
            int value=(board[i][j]-'0');
            printf("%d",value);
            count[value]+=1;
        }
    }
}
for(int i=1;i<10;i++)
{
    count[i]=0;
}
for(int i=0;i<3;i++)
{
    for(int j=3;j<6;j++)
    {
        if(count>0)
        {
        
            printf("Repetition found in 2nd  3X3 grid\n");
            goto menu;
        }
        else
        {
            int value=(board[i][j]-'0');
            printf("%d",value);
            count[value]+=1;
        }
    }
}
for(int i=1;i<10;i++)
{
    count[i]=0;
}
for(int i=0;i<3;i++)
{
    for(int j=6;j<9;j++)
    {
        if(count>0)
        {
        
            printf("Repetition found in 3rd 3X3 grid\n");
            goto menu;
        }
        else
        {
            int value=(board[i][j]-'0');
            printf("%d",value);
            count[value]+=1;
        }
    }
}

menu:
return;




}


/*this was intially this was a sudoku solver ...very complex for now it is now sudoku validator but this is  also inefficinet as well*/





