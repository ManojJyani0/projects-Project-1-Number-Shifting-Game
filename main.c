#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct pos
{
   // to knows for space posions
   int i,j;
};
// chacking final result 
void chackfinal(int ptr[][4])
{
   int matrix[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0},count=1;
   for (int i = 0; i < 4; i++)
   {
      for(int j=0; j < 4; j++)
      {
         if(matrix[i][j]==ptr[i][j])
         count++;

      }
   }
   if (count==16)
   {
      printf("Congrats...... You win the game.\n\nPress any key to exit.");
      getch();
      exit(0);
   }
   
}
//display matrix or remaning moves.
void display(int ptr[][4],int count,char username[20])
{
   printf("\n\t\t %s\t\t move remaning %d\n",username,count);
   printf("-----------------\n");
   for (int i = 0; i < 4; i++)
   {
      for(int j = 0;j<4;j++)
      if (ptr[i][j]==0)
      {
         printf("|   ");
      }
      else
      {
         if (ptr[i][j]>9)
         {
            printf("|%d ",ptr[i][j]);
         }
         else
            printf("| %d ",ptr[i][j]);
      }
      printf("|\n");
   }
   printf("-----------------\n");
   printf("\n");
}
// chaking posion of space and moving nubers.
struct pos checkPos(int ptr[4][4])
{
   struct pos posion;
   for (int i = 0; i < 4; i++)
   {
      for(int j = 0;j<4;j++)
      if (ptr[i][j]==0)
      {
         posion.i=i;
         posion.j=j;
         return posion;
      }
   }
   
}
void startgame()
{
   int matrix[4][4],count=500;
   char sift,name[20];
   struct pos p;
   // this switch for gereting random matrix
   switch(getch()%5)
    {
        case 1:{
        int ptr[4][4]={1,8,3,7,5,6,2,4,9,10,11,12,14,13,15,0};
        for (int i = 0; i < 4; i++)
        {
            for(int j=0; j < 4; j++)
            {
                matrix[i][j]=ptr[i][j];
            }
        }
        break;}
        case 2:{
        int ptr[4][4]={1,9,7,0,6,2,4,3,10,11,15,12,14,13,8,5};
        for (int i = 0; i < 4; i++)
        {
            for(int j=0; j < 4; j++)
            {
                matrix[i][j]=ptr[i][j];
            }
        }
        break;}
        case 3:{
        int ptr[4][4]={4,3,7,2,6,11,5,1,14,10,15,12,9,13,8,0};
        for (int i = 0; i < 4; i++)
        {
            for(int j=0; j < 4; j++)
            {
                matrix[i][j]=ptr[i][j];
            }
        }
        break;}
        case 4:{
        int ptr[4][4]={15,11,3,4,7,2,6,5,1,14,10,12,9,13,8,0};
        for (int i = 0; i < 4; i++)
        {
            for(int j=0; j < 4; j++)
            {
                matrix[i][j]=ptr[i][j];
            }
        }
        break;}
    }
   printf("\nEnter Your Name :");
   fflush(stdin);
   fgets(name,20,stdin);
   display(matrix,count, name);
   // game program start
   while (count)
   {
      sift=getch();
      switch (sift)
      {
      case 50:
         if (checkPos(matrix).i<3)
         {
            chackfinal(matrix);
            p=checkPos(matrix);
            matrix[p.i][p.j]=matrix[p.i+1][p.j];
            matrix[p.i+1][p.j]=0;
            count--;
            display(matrix,count,name);
            if (!count)
            {
               printf("OOPS..... You lose the game.\n\nPress any key to exit.");
               getch();
               exit(0);
            }           
         }
         
         break;
      case 52:
         if (checkPos(matrix).j>0)
         {
            chackfinal(matrix);
            p=checkPos(matrix);
            matrix[p.i][p.j]=matrix[p.i][p.j-1];
            matrix[p.i][p.j-1]=0;
            count--;
            display(matrix,count,name);
            if (!count)
            {
               printf("OOPS..... You lose the game.\n\nPress any key to exit.");
               getch();
               exit(0);
            }
         }
         break;
      case 54:
         if (checkPos(matrix).j<3)
         {
            chackfinal(matrix);
            p=checkPos(matrix);
            matrix[p.i][p.j]=matrix[p.i][p.j+1];
            matrix[p.i][p.j+1]=0;
            count--;
            display(matrix,count,name);
            if (!count)
            {
               printf("OOPS..... You lose the game.\n\nPress any key to exit.");
               getch();
               exit(0);
            }
         }
         break;
      case 56:
         if (checkPos(matrix).i>0)
         {
            chackfinal(matrix);
            p=checkPos(matrix);
            matrix[p.i][p.j]=matrix[p.i-1][p.j];
            matrix[p.i-1][p.j]=0;
            count--;
            display(matrix,count,name);
            if (!count)
            {
               printf("OOPS..... You lose the game.\n\nPress any key to exit.");
               getch();
               exit(0);
            }
         }
         break;
         case 'e':exit(0);
         case 'E':exit(0);
      }
   }
}

int main()
{
   printf("\t\t\t RULE OF THIS GAME\n\n\n");
   printf("1. You can move only 1 step at a time with the numpad arrow key.\n\t->press 2 to move down.\n\t->press 4 to move left.\n\t->press 6 to move right.\n\t->press 8 to move up.\n");
   printf("2. You can move numbers at an empty position only.\n");
   printf("3. For each valid move : your total number of moves will decrease by 1.");
   printf("4. Winning Situation :\n");
   printf("   --------------------\n");
   printf("   |  1 |  2 |  3 | 4 |\n");
   printf("   |  5 |  6 |  7 | 8 |\n");
   printf("   |  9 | 10 | 11 | 12|\n");
   printf("   | 13 | 14 | 15 |   |\n");
   printf("   --------------------\n");
   printf(" Number in a 4*4 matrix should be in order from 1 to 15\n");
   printf("5. You can exit this game at any time pressing \'E\' or \'e\' \n");
   printf("\tso try to win this game in minimum no of move\n");
   printf("\t\t\t\tHappy Gaming, Good Luck\n");
   printf("\Enter any key to start game........");
   startgame();
   return 0;
}
