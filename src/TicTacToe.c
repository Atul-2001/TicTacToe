/*
Hello Everyone, This is very basic tic-tac-toe game using 3X3 board.
It has 2 basic features: 1. Play with friend & 2. Play with computer.
You can get this game with its source code on github.com   URL: github.com/Atul-2001/TicTacToe
*/

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

char sq[10];//= {'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};
int count=0;

int checkWin();    //To check the status of game and find the winner.
void board();      // Display the board on the screen
int random();      // Generate random number for computer to play his move
void delay();      // Creates a delay timer
int checkStatus(); // Check that which move has to be performed by the computer
int firstMove();   // first move performed by computer
int secondMove();  // second move performed by computer
int thirdMove();   // third move performed by computer
int fourthMove();  // fourth move performed by computer
void gotoxy(int x,int y);  // function to move cursor at given position. position is given in x and y coordinates

int main(void)
{
    static int player=1,status,choice,player_choice,mode,comp_choice,comp_move;
    static char sign,play_again,i;

    SetConsoleTitle("'Tic Tac Toe'  -by Atul Suryavanshi");

    while(1)
    {
        system("cls");
      gotoxy(50,2);
      printf("Tic Tac Toe");
      gotoxy(40,4);
      printf("With whom you want to play");
      gotoxy(40,5);
      printf(" 1. Computer ");
      gotoxy(40,6);
      printf(" 2. Friend ");
      gotoxy(40,7);
      printf(" 0. Exit ");
      gotoxy(40,9);
      printf("Select valid option(1/2): ");
      scanf("%d",&mode);    // Choose mode of Game to play.
      if(mode==1)
      {
         player=1;
         goto startGame;
      }
      else if(mode==2)
      {
         goto start2;
      }
      else if(mode==0)
      {
          exit(0);
      }
      else
      {
          gotoxy(40,10);
          printf("Please enter correct option\n");
          delay(1);
      }
    }

    start2:                                                                       // Choose which player will play first.
    while(1)
    {
        system("cls");
        gotoxy(50,2);
        printf("Tic Tac Toe");
        gotoxy(29,4);
        printf("Who want to play first(1/2) and if you want to exist press 0: ");
        scanf("%d",&player_choice);

        if(player_choice==1 || player_choice==2)
        {
            player=player_choice;
            break;
        }
        else if(player_choice==0)
        {
            exit(0);
        }
        else
        {
            gotoxy(40,6);
            printf("Please enter correct option");
            delay(1);
        }
    }

    startGame:
    do
    {
    board();

    player=(player%2)?1:2;

    if(mode==1 && player==2)                                 //Decision making process by computer
    {
        printf("Player J.A.R.V.I.S, enter your choice: ");

        while (1)
        {
            comp_choice=random();
            if(sq[comp_choice]=='X' || sq[comp_choice]=='0')
            {
                 continue;
            }
            else
            {
                break;
            }

        }

            comp_move=checkStatus(comp_choice);
            printf("%d",comp_move);
            choice=comp_move;
            delay(1);

    }
    else if (mode==1 && player==1)
    {
        printf("Player %d, enter your choice ",player);
        scanf("%d",&choice);
    }
    else if(mode==2)
    {
        printf("Player %d, enter your choice: ",player);
        scanf("%d",&choice);
    }
    sign=(player==1)?'X':'0';

    if(choice==1 && sq[1]=='\0')
    {
        sq[1]=sign;
    }
    else if(choice==2 && sq[2]=='\0')
    {
        sq[2]=sign;
    }
    else if(choice==3 && sq[3]=='\0')
    {
        sq[3]=sign;
    }
    else if(choice==4 && sq[4]=='\0')
    {
        sq[4]=sign;
    }
    else if(choice==5 && sq[5]=='\0')
    {
        sq[5]=sign;
    }
    else if(choice==6 && sq[6]=='\0')
    {
        sq[6]=sign;
    }
    else if(choice==7 && sq[7]=='\0')
    {
         sq[7]=sign;
    }
    else if(choice==8 && sq[8]=='\0')
    {
        sq[8]=sign;
    }
    else if(choice==9 && sq[9]=='\0')
    {
        sq[9]=sign;
    }
    else
    {
        gotoxy(46,19);
        printf("Invalid move!");
        player--;
        count--;
        getch();
        fflush(stdin);
    } /* code */

     player++;

     status=checkWin();

     count++;
    } while (status==-1);

    board();

    if(status==1)
    {
        gotoxy(46,20);
        printf("==>\aPlayer %d is winner",--player);
    }
    else
    {
        gotoxy(50,20);
        printf("==>\aGame draw");
    }

    getch();

    char ch;
    gotoxy(42,22);
    printf("Do you want to play again(Y/N): ");
    while(1)
    {
      fflush(stdin);
      ch = getche();
      if(ch == 'Y' || ch == 'y')
      {
         for(i = 0; i <= 9; i++)
         {
             sq[i] = '\0';
         }

         system("TicTacToe.exe");
      }
      else if(ch == 'N' || ch == 'n')
      {
          exit(0);
      }
    }

    return 0;

}


int checkWin()
{
    if((sq[1]!='\0' && sq[2]!='\0' && sq[3]!='\0') && (sq[1]==sq[2] && sq[2]==sq[3]))
    {
        return 1;
    }
    else if((sq[4]!='\0' && sq[5]!='\0' && sq[6]!='\0') && (sq[4]==sq[5] && sq[5]==sq[6]))
    {
        return 1;
    }
    else if((sq[7]!='\0' && sq[8]!='\0' && sq[9]!='\0') && (sq[7]==sq[8] && sq[8]==sq[9]))
    {
        return 1;
    }
    else if((sq[1]!='\0' && sq[4]!='\0' && sq[7]!='\0') && (sq[1]==sq[4] && sq[4]==sq[7]))
    {
        return 1;
    }
    else if((sq[2]!='\0' && sq[5]!='\0' && sq[8]!='\0') && (sq[2]==sq[5] && sq[5]==sq[8]))
    {
        return 1;
    }
    else if((sq[3]!='\0' && sq[6]!='\0' && sq[9]!='\0') && (sq[3]==sq[6] && sq[6]==sq[9]))
    {
        return 1;
    }
    else if((sq[1]!='\0' && sq[5]!='\0' && sq[9]!='\0') && (sq[1]==sq[5] && sq[5]==sq[9]))
    {
        return 1;
    }
    else if((sq[3]!='\0' && sq[5]!='\0' && sq[7]!='\0') && (sq[3]==sq[5] && sq[5]==sq[7]))
    {
        return 1;
    }
    else if(sq[1]!='\0' && sq[2]!='\0' && sq[3]!='\0' && sq[4]!='\0' && sq[5]!='\0' && sq[6]!='\0' && sq[7]!='\0' && sq[8]!='\0' && sq[9]!='\0')
    {
        return 0;
    }
    else
    {
        return -1;
    }

}


void board()
{
    system("cls");

    gotoxy(50,2);
    printf("Tic Tac Toe");
    gotoxy(43,6);
    printf("Player 1(X) - Player 2(0)");

    gotoxy(47,8);
    printf("     |     |     ");
    gotoxy(47,9);
    printf("  %c  |  %c  |  %c  ",sq[1],sq[2],sq[3]);
    gotoxy(47,10);
    printf("_____|_____|_____");
    gotoxy(47,11);
    printf("     |     |     ");
    gotoxy(47,12);
    printf("  %c  |  %c  |  %c  ",sq[4],sq[5],sq[6]);
    gotoxy(47,13);
    printf("_____|_____|_____");
    gotoxy(47,14);
    printf("     |     |     ");
    gotoxy(47,15);
    printf("  %c  |  %c  |  %c  ",sq[7],sq[8],sq[9]);
    gotoxy(47,16);
    printf("     |     |     ");
    gotoxy(44,18);

}


int random()
{
    int n;
    srand(time(0));

    n=rand()%10;

    return n;
}


void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}


int checkStatus(int x)
{
    int val=0;
    if(count==1)
    {
         val=firstMove();
    }
    else if(count==3)
    {
        val=secondMove();
    }
    else if(count==5)
    {
        val=thirdMove();
    }
    else if(count==7)
    {
        val=fourthMove();
    }
    else
    {
        val=x;
    }

    return val;
}


int firstMove()
{
    int position=0;

    if(sq[5]=='X')
    {
       while(1)
       {
         position=random();
        if (position==1 || position==3 || position==7 || position==9)
        {
            break;
        }
        else
        {
            continue;
        }
       }

    }
    else
    {
        position=5;
    }

    return position;
}


int secondMove()
{
    int position=0;
    if(sq[5]=='0')
    {
    if((sq[6]=='X' && sq[4]=='X') || (sq[2]=='X' && sq[8]=='X'))
    {
        while(1)
        {
            position=random();
            if(position==1 || position==3 || position==7 || position==9)
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    else if(sq[6]=='X' && sq[2]=='X')
    {
        position=3;
    }
    else if(sq[6]=='X' && sq[8]=='X')
    {
         position=9;
    }
    else if(sq[4]=='X' && sq[2]=='X')
    {
         position=1;
    }
    else if(sq[4]=='X' && sq[8]=='X')
    {
         position=7;
    }
    else if(sq[1]=='X' && sq[7]=='X')
    {
         position=4;
    }
    else if(sq[1]=='X' && sq[3]=='X')
    {
        position=2;
    }
    else if(sq[3]=='X' && sq[9]=='X')
    {
        position=6;
    }
    else if(sq[9]=='X' && sq[7]=='X')
    {
        position=8;
    }
    else if(((sq[1]=='X') && (sq[9]=='X')) || ((sq[3]=='X') && (sq[7]=='X')))
    {
        while(1)
        {
            position=random();
            if(position==2 || position==4 || position==6 || position==8)
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    else if(sq[1]=='X' && sq[2]=='X')
    {
       position=3;
    }
    else if(sq[2]=='X' && sq[3]=='X')
    {
       position=1;
    }
    else if(sq[1]=='X' && sq[4]=='X')
    {
       position=7;
    }
    else if(sq[4]=='X' && sq[7]=='X')
    {
       position=1;
    }
    else if(sq[7]=='X' && sq[8]=='X')
    {
       position=9;
    }
    else if(sq[8]=='X' && sq[9]=='X')
    {
       position=7;
    }
    else if(sq[3]=='X' && sq[6]=='X')
    {
       position=9;
    }
    else if(sq[6]=='X' && sq[9]=='X')
    {
       position=3;
    }
    else if(sq[1]=='X' && sq[6]=='X')
    {
        position=3;
    }
    else if(sq[7]=='X' &&sq[6]=='X')
    {
        position=9;
    }
    else if(sq[3]=='X' &&sq[4]=='X')
    {
        position=1;
    }
    else if(sq[9]=='X' && sq[4]=='X')
    {
        position=7;
    }
    else if(sq[1]=='X' && sq[8]=='X')
    {
        position=7;
    }
    else if(sq[3]=='X' && sq[8]=='X')
    {
        position=9;
    }
    else if(sq[7]=='X' && sq[2]=='X')
    {
        position=1;
    }
    else if(sq[9]=='X' && sq[2]=='X')
    {
        position=3;
    }
    }
    else if(sq[5]=='X')
    {
       if(sq[1]=='X' && sq[9]!='0')
       {
           position=9;
       }
       else if(sq[1]=='X' && sq[9]=='0')
       {
           while(1)
         {
            position=random();
            if(position==3 || position==7)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
       else if(sq[9]=='X' && sq[1]!='0')
       {
           position=1;
       }
       else if(sq[9]=='X' && sq[1]=='0')
       {
           while(1)
         {
            position=random();
            if(position==3 || position==7)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
       else if(sq[3]=='X' && sq[7]!='0')
       {
           position=7;
       }
       else if(sq[3]=='X' && sq[7]=='0')
       {
           while(1)
         {
            position=random();
            if(position==1 || position==9)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
       else if(sq[7]=='X' && sq[3]!='0')
       {
           position=3;
       }
       else if(sq[7]=='X' && sq[3]=='0')
       {
           while(1)
         {
            position=random();
            if(position==1 || position==9)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
       else if(sq[2]=='X' && sq[8]!='0')
       {
           position=8;
       }
       else if(sq[2]=='X' && sq[8]=='0')
       {
           while(1)
         {
            position=random();
            if(position==7 || position==9)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
       else if(sq[4]=='X' && sq[6]!='0')
       {
           position=6;
       }
       else if(sq[4]=='X' && sq[6]=='0')
       {
           while(1)
         {
            position=random();
            if(position==3 || position==9)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
       else if(sq[8]=='X' && sq[2]!='0')
       {
           position=2;
       }
       else if(sq[8]=='X' && sq[2]=='0')
       {
           while(1)
         {
            position=random();
            if(position==1 || position==3)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
       else if(sq[6]=='X' && sq[4]!='0')
       {
           position=4;
       }
       else if(sq[6]=='X' && sq[4]=='0')
       {
           while(1)
         {
            position=random();
            if(position==1 || position==7)
            {
                break;
            }
            else
            {
                continue;
            }
         }
       }
    }
    return position;
}


int thirdMove()
{
    int position=0;
     if(sq[5]=='0')
     {
         //s[1]=='X'
             if(sq[1]=='X' && sq[2]=='X' && sq[3]=='0' && sq[7]=='\0')
             {
                   position=7;
             }
             else if(sq[1]=='X' && sq[2]=='X' && sq[3]=='0' && sq[7]=='X')
             {
                   position=4;
             }
             else if(sq[1]=='X' && sq[3]=='X' && sq[2]=='0' && sq[8]=='\0')
             {
                 position=8;
             }
             else if(sq[1]=='X' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X')
             {
                    while(1)
                   {
                       position=random();
                       if(position==4 || position==6)
                       {
                          break;
                       }
                       else
                       {
                          continue;
                       }
                    }
             }
             else if(sq[1]=='X' && sq[4]=='X' && sq[7]=='0' && sq[3]=='\0')
             {
                position=3;
             }
             else if(sq[1]=='X' && sq[4]=='X' && sq[7]=='0' && sq[3]=='X')
             {
                position=2;
             }
             else if(sq[1]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='\0')
             {
                position=7;
             }
             else if(sq[1]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X')
             {
                position=4;
             }
             else if(sq[1]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='\0')
             {
                position=6;
             }
             else if(sq[1]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='X')
             {
                while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
             }
             else if(sq[1]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='\0')
             {
                 position=3;
             }
             else if(sq[1]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X')
             {
                 position=2;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[2]=='0' && sq[8]=='\0')
             {
                 position=8;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[2]=='0' && sq[8]=='X')
             {
                 position=7;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[4]=='0' && sq[6]=='\0')
             {
                 position=6;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[4]=='0' && sq[6]=='X')
             {
                 position=3;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[6]=='0' &&  sq[4]=='\0')
             {
                 position=4;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[6]=='0' &&  sq[4]=='X')
             {
                 position=7;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[8]=='0' &&  sq[2]=='\0')
             {
                  position=2;
             }
             else if(sq[1]=='X' && sq[9]=='X' && sq[8]=='0' &&  sq[2]=='X')
             {
                 position=3;
             }

         //sq[2]=='X'
           else if(sq[2]=='X' && sq[3]=='X' && sq[1]=='0' && sq[9]=='\0')
           {
               position=9;
           }
           else if(sq[2]=='X' && sq[3]=='X' && sq[1]=='0' && sq[9]=='X')
           {
               position=6;
           }
           else if(sq[2]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='\0')
           {
               position=9;
           }
           else if(sq[2]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X')
           {
                 while(1)
                 {
                    position=random();
                    if(position==3 || position==7)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
           }
           else if(sq[2]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='\0')
           {
               position=7;
           }
           else if(sq[2]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X')
           {
                 while(1)
                 {
                    position=random();
                    if(position==1 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
           }
           else if(sq[2]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='\0')
           {
               position=9;
           }
           else if(sq[2]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X')
           {
               position=8;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[1]=='0' && sq[9]=='\0')
           {
               position=9;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[1]=='0' && sq[9]=='X')
           {
               position=7;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[3]=='0' && sq[7]=='\0')
           {
               position=7;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[3]=='0' && sq[7]=='X')
           {
                position=9;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='\0')
           {
               position=3;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X')
           {
               position=1;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='\0')
           {
               position=1;
           }
           else if(sq[2]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X')
           {
                position=7;
           }
           else if(sq[2]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='\0')
           {
               position=7;
           }
           else if(sq[2]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X')
           {
               position=8;
           }

         //sq[3]=='X'
            else  if(sq[3]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='\0')
            {
                position=9;
            }
            else if(sq[3]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X')
            {
                position=6;
            }
            else if(sq[3]=='X' && sq[6]=='X' && sq[9]=='0' && sq[1]=='\0')
            {
                position=1;
            }
            else if(sq[3]=='X' && sq[6]=='X' && sq[9]=='0' && sq[1]=='X')
            {
                position=2;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[2]=='0' && sq[8]=='\0')
            {
                position=8;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[2]=='0' && sq[8]=='X')
            {
                position=9;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='\0')
            {
                position=6;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='X')
            {
                position=9;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[6]=='0' && sq[4]=='\0')
            {
                position=4;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[6]=='0' && sq[4]=='X')
            {
                position=1;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[8]=='0' && sq[2]=='\0')
            {
                position=2;
            }
            else if(sq[3]=='X' && sq[7]=='X' && sq[8]=='0' && sq[2]=='X')
            {
                position=1;
            }
            else if(sq[3]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='\0')
            {
                position=1;
            }
            else if(sq[3]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X')
            {
                position=2;
            }
            else if(sq[3]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='\0')
            {
                position=4;
            }
            else if(sq[3]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X')
            {
                 while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
            }

        //sq[4]=='X'
            else if(sq[4]=='X' && sq[6]=='X' && sq[9]=='0' && sq[1]=='\0')
            {
                position=1;
            }
            else if (sq[4]=='X' && sq[6]=='X' && sq[9]=='0' && sq[1]=='X')
            {
                position=7;
            }
             else if(sq[4]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='\0')
            {
                position=7;
            }
            else if (sq[4]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X')
            {
                position=1;
            }
             else if(sq[4]=='X' && sq[6]=='X' && sq[1]=='0' && sq[9]=='\0')
            {
                position=9;
            }
            else if (sq[4]=='X' && sq[6]=='X' && sq[1]=='0' && sq[9]=='X')
            {
                position=3;
            }
             else if(sq[4]=='X' && sq[6]=='X' && sq[7]=='0' && sq[3]=='\0')
            {
                position=3;
            }
            else if (sq[4]=='X' && sq[6]=='X' && sq[7]=='0' && sq[3]=='X')
            {
                position=9;
            }
            else if(sq[4]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='\0')
            {
                position=9;
            }
            else if(sq[4]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X')
            {
                position=8;
            }
            else if(sq[4]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='\0')
            {
                position=3;
            }
            else if(sq[4]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X')
            {
                while(1)
                 {
                    position=random();
                    if(position==1 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
            }
            else if(sq[4] && sq[9]=='X' && sq[7]=='0' && sq[3]=='\0')
            {
                position=3;
            }
            else if(sq[4] && sq[9]=='X' && sq[7]=='0' && sq[3]=='X')
            {
                position=6;
            }

         //sq[6]=='X'
             else if(sq[6]=='X' && sq[7]=='X' && sq[9]=='0' && sq[1]=='\0')
             {
                 position=1;
             }
             else if(sq[6]=='X' && sq[7]=='X' && sq[9]=='0' && sq[1]=='X')
             {
                 position=4;
             }
             else if(sq[6]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='\0')
             {
                 position=1;
             }
             else if(sq[6]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X')
             {
                 while(1)
                 {
                    position=random();
                    if(position==3 || position==7)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
             }
             else if(sq[6]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='\0')
             {
                 position=7;
             }
             else if(sq[6]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X')
             {
                 position=8;
             }

         //sq[7]=='X'
             else if(sq[7]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='\0')
             {
                 position=1;
             }
             else if(sq[7]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X')
             {
                 position=4;
             }
             else if(sq[7]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='\0')
             {
                 position=2;
             }
             else if(sq[7]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X')
             {
                 while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
             }

         //sq[8]=='X'
             else if(sq[8]=='X' && sq[9]=='X' && sq[7]=='0' && sq[3]=='\0')
             {
                 position=3;
             }
             else if(sq[8]=='X' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X')
             {
                 position=6;
             }
     //end of condition sq[5]=='0'
     }
     else if(sq[5]=='X')
     {
         //sq[1]=='0'
         //sq[2]=='X'
         if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[3]=='X')
         {
             position=7;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X')
         {
             position=3;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             position=7;
         }

         //sq[3]=='X'
         else if(sq[1]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='X')
         {
             position=6;
         }

         //sq[4]=='X'
         else if(sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='\0')
         {
             position=3;
         }
         else if(sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             position=7;
         }

         //sq[6]=='X'
         else if(sq[1]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='\0')
         {
             position=7;
         }
         else if(sq[1]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X')
         {
             position=3;
         }

         //sq[7]=='X'
         else if(sq[1]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[1]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='X')
         {
             position=8;
         }

         //sq[8]=='X'
         else if(sq[1]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='\0')
         {
             position=3;
         }
         else if(sq[1]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X')
         {
             position=7;
         }

         //sq[9]=='X'
         else if(sq[1]=='0' && sq[9]=='X' && sq[3]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[3]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[4]=='X')
         {
             position=6;
         }


         //sq[3]=='0'
         //sq[1]=='X'
         else if(sq[3]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X')
         {
             position=4;
         }

         //sq[2]=='X'
          else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X')
         {
             position=9;
         }

         //sq[4]=='X'
         else if(sq[3]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='\0')
         {
             position=9;
         }
         else if(sq[3]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X')
         {
             position=1;
         }

         //sq[6]=='X'
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X')
         {
             position=1;
         }

         //sq[7]=='X'
         else if(sq[3]=='0' && sq[7]=='X' && sq[1]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[1]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[6]=='X')
         {
             position=4;
         }

         //sq[8]=='X'
         else if(sq[3]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='\0')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             position=9;
         }

         //sq[9]=='X'
         else if(sq[3]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='X')
         {
             position=8;
         }


         //sq[7]=='0'
         //sq[1]=='X'
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[3]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[8]=='X')
         {
             position=2;
         }

         //sq[2]=='X'
         else if(sq[7]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='\0')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             position=1;
         }

         //sq[3]=='X'
         else if(sq[7]=='0' && sq[3]=='X' && sq[1]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[1]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[9]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[9]=='0' && sq[8]=='X')
         {
             position=2;
         }

         //sq[4]=='X'
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X')
         {
             position=1;
         }

         //sq[6]=='X'
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[3]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[9]=='X')
         {
             position=1;
         }

         //sq[8]=='X'
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[9]=='X')
         {
             position=1;
         }

         //sq[9]=='X'
         else if(sq[7]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='X')
         {
             position=6;
         }


         //sq[9]=='0'
         //sq[1]=='X'
         else if(sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[9]=='0' && sq[1]=='X' && sq[7]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[9]=='0' && sq[1]=='X' && sq[7]=='0' && sq[4]=='X')
         {
             position=6;
         }

         //sq[2]=='X'
         else if(sq[9]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='\0')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X')
         {
             position=3;
         }

         //sq[3]=='X'
         else if(sq[9]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='X')
         {
             position=2;
         }

         //sq[4]=='X'
         else if(sq[9]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='\0')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             position=7;
         }

         //sq[6]=='X'
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[3]=='X')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }

         //sq[7]=='X'
         else if(sq[9]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='X')
         {
             position=4;
         }

         //sq[8]=='X'
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[7]=='X')
         {
             position=3;
         }
    //End of condition sq[5]=='X'
     }
    return position;
}


int fourthMove()
{
    int position=0;

    if(sq[5]=='0')
    {
        //sq[1]=='X'
        if(sq[1]=='X' && sq[2]=='X' && sq[3]=='0' && sq[7]=='X' && sq[4]=='0' && sq[6]=='\0')
        {
            position=6;
        }
        else if(sq[1]=='X' && sq[2]=='X' && sq[3]=='0' && sq[7]=='X' && sq[4]=='0' && sq[6]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==8 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[1]=='X' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X' && sq[4]=='0' && sq[6]=='\0')
        {
            position=6;
        }
        else if(sq[1]=='X' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X' && sq[4]=='0' && sq[6]=='X')
        {
            position=9;
        }
        else if(sq[1]=='X' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X' && sq[6]=='0' && sq[4]=='\0')
        {
            position=4;
        }
        else if(sq[1]=='X' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X' && sq[6]=='0' && sq[4]=='X')
        {
            position=7;
        }
        else if(sq[1]=='X' && sq[4]=='X' && sq[7]=='0' && sq[3]=='X' && sq[2]=='0' && sq[8]=='\0')
        {
            position=8;
        }
        else if(sq[1]=='X' && sq[4]=='X' && sq[7]=='0' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==6 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[1]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X' && sq[4]=='0' && sq[9]=='X')
        {
            position=8;
        }
        else if(sq[1]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X' && sq[4]=='0' && sq[2]=='X')
        {
            position=8;
        }
        else if(sq[1]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X' && sq[4]=='0' && sq[8]=='X')
        {
            position=9;
        }
        else if(sq[1]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='X' && sq[2]=='0' && sq[8]=='\0')
        {
            position=8;
        }
        else if(sq[1]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='X' && sq[2]=='0' && sq[8]=='X')
        {
            position=9;
        }
        else if(sq[1]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='X' && sq[8]=='0' && sq[2]=='\0')
        {
            position=2;
        }
        else if(sq[1]=='X' && sq[7]=='X' && sq[4]=='0' && sq[6]=='X' && sq[8]=='0' && sq[2]=='X')
        {
            position=3;
        }
        else if(sq[1]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X' && sq[2]=='0' && sq[9]=='X')
        {
            position=6;
        }
        else if(sq[1]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X' && sq[2]=='0' && sq[6]=='X')
        {
            position=9;
        }
        else if(sq[1]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X' && sq[2]=='0' && sq[4]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==6 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[2]=='0' && sq[8]=='X' && sq[7]=='0' && sq[3]=='\0')
        {
            position=3;
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[2]=='0' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X')
        {
            position=6;
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[4]=='0' && sq[6]=='X' && sq[3]=='0' && sq[7]=='\0')
        {
            position=7;
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[4]=='0' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X')
        {
            position=8;
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X' && sq[7]=='0' && sq[3]=='\0')
        {
            position=3;
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X' && sq[7]=='0' && sq[3]=='X')
        {
            position=2;
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X' && sq[3]=='0' && sq[7]=='\0')
        {
            position=7;
        }
        else if(sq[1]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X' && sq[3]=='0' && sq[7]=='X')
        {
            position=4;
        }

        //sq[2]=='X'
        else if(sq[2]=='X' && sq[3]=='X' && sq[1]=='0' && sq[9]=='X' && sq[6]=='0' && sq[4]=='\0')
        {
            position=4;
        }
        else if(sq[2]=='X' && sq[3]=='X' && sq[1]=='0' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==7 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[2]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[3]=='\0')
        {
            position=3;
        }
        else if(sq[2]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X')
        {
            position=6;
        }
        else if(sq[2]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X' && sq[3]=='0' && sq[7]=='\0')
        {
            position=7;
        }
        else if(sq[2]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X')
        {
            position=8;
        }
        else if(sq[2]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[1]=='\0')
        {
            position=1;
        }
        else if(sq[2]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[1]=='X')
        {
            position=4;
        }
        else if(sq[2]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X' && sq[1]=='0' && sq[9]=='\0')
        {
            position=9;
        }
        else if(sq[2]=='X' && sq[6]=='X' && sq[3]=='0' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X')
        {
            position=8;
        }
        else if(sq[2]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X' && sq[8]=='0' && sq[3]=='X')
        {
            position=6;
        }
        else if(sq[2]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X' && sq[8]=='0' && sq[6]=='X')
        {
            position=3;
        }
        else if(sq[2]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X' && sq[8]=='0' && sq[4]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==3 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[3]=='\0')
        {
            position=3;
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X')
        {
            position=6;
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[1]=='\0')
        {
            position=1;
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[1]=='X')
        {
            position=4;
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X' && sq[1]=='0' && sq[9]=='\0')
        {
            position=9;
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X' && sq[1]=='0' && sq[9]=='X')
        {
            position=6;
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[7]=='\0')
        {
            position=7;
        }
        else if(sq[2]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[7]=='X')
        {
            position=4;
        }
        else if(sq[2]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X' && sq[8]=='0' && sq[1]=='X')
        {
            position=4;
        }
        else if(sq[2]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X' && sq[8]=='0' && sq[4]=='X')
        {
            position=1;
        }
        else if(sq[2]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X' && sq[8]=='0' && sq[6]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==1 || position==4)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }

        //sq[3]=='0'
        else if(sq[3]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X' && sq[6]=='0' && sq[2]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==7 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[3]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X' && sq[6]=='0' && sq[8]=='X')
        {
            position=7;
        }
        else if(sq[3]=='X' && sq[4]=='X' && sq[1]=='0' && sq[9]=='X' && sq[6]=='0' && sq[7]=='X')
        {
            position=8;
        }
        else if(sq[3]=='X' && sq[6]=='X' && sq[9]=='0' && sq[1]=='X' && sq[2]=='0' && sq[8]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==4 || position==7)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[3]=='X' && sq[6]=='X' && sq[9]=='0' && sq[1]=='X' && sq[2]=='0' && sq[8]=='\0')
        {
            position=8;
        }
        else if(sq[3]=='X' && sq[7]=='X' && sq[2]=='0' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X')
        {
            position=4;
        }
        else if(sq[3]=='X' && sq[7]=='X' && sq[2]=='0' && sq[8]=='X' && sq[9]=='0' && sq[4]=='X')
        {
            position=1;
        }
        else if(sq[3]=='X' && sq[7]=='X' && sq[2]=='0' && sq[8]=='X' && sq[9]=='0' && sq[6]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==1 || position==4)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[3]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[2]=='0' && sq[4]=='X')
        {
            position=7;
        }
        else if(sq[3]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[2]=='0' && sq[7]=='X')
        {
            position=4;
        }
        else if(sq[3]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[2]=='0' && sq[6]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==4 || position==7)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[3]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X' && sq[2]=='0' && sq[8]=='\0')
        {
            position=8;
        }
        else if(sq[3]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X' && sq[2]=='0' && sq[8]=='X')
        {
            position=7;
        }
        else if(sq[3]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X' && sq[8]=='0' && sq[2]=='\0')
        {
            position=2;
        }
        else if(sq[3]=='X' && sq[9]=='X' && sq[6]=='0' && sq[4]=='X' && sq[8]=='0' && sq[2]=='X')
        {
            position=1;
        }

        //sq[4]=='X'
        else if(sq[4]=='X' && sq[6]=='X' && sq[1]=='0' && sq[7]=='X' && sq[1]=='0' && sq[9]=='\0')
        {
            position=9;
        }
        else if(sq[4]=='X' && sq[6]=='X' && sq[1]=='0' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X')
        {
            position=8;
        }
        else if(sq[4]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X' && sq[8]=='0' && sq[2]=='\0')
        {
            position=2;
        }
        else if(sq[4]=='X' && sq[7]=='X' && sq[1]=='0' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==3 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[4]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X' && sq[9]=='0' && sq[1]=='\0')
        {
            position=1;
        }
        else if(sq[4]=='X' && sq[8]=='X' && sq[7]=='0' && sq[3]=='X' && sq[9]=='0' && sq[1]=='X')
        {
            position=2;
        }
        else if(sq[4]=='X' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X' && sq[6]=='0' && sq[2]=='X')
        {
            position=1;
        }
        else if(sq[4]=='X' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X' && sq[6]=='0' && sq[1]=='X')
        {
            position=2;
        }
        else if(sq[4]=='X' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X' && sq[6]=='0' && sq[8]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==1 || position==2)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }

        //sq[6]=='X'
        else if(sq[6]=='X' && sq[7]=='X' && sq[9]=='0' && sq[1]=='X' && sq[4]=='0' && sq[2]=='X')
        {
            position=3;
        }
        else if(sq[6]=='X' && sq[7]=='X' && sq[9]=='0' && sq[1]=='X' && sq[4]=='0' && sq[3]=='X')
        {
            position=2;
        }
        else if(sq[6]=='X' && sq[7]=='X' && sq[9]=='0' && sq[1]=='X' && sq[4]=='0' && sq[8]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==2 || position==3)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[6]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[7]=='\0')
        {
            position=7;
        }
        else if(sq[6]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[7]=='X')
        {
            position=4;
        }
        else if(sq[6]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[7]=='0' && sq[3]=='\0')
        {
            position=3;
        }
        else if(sq[6]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[7]=='0' && sq[3]=='X')
        {
            position=2;
        }
        else if(sq[6]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X' && sq[8]=='0' && sq[2]=='\0')
        {
            position=2;
        }
        else if(sq[6]=='X' && sq[9]=='X' && sq[3]=='0' && sq[7]=='X' && sq[8]=='0' && sq[2]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==1 || position==4)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }

        //sq[7]=='X'
        else if(sq[7]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[4]=='0' && sq[6]=='\0')
        {
            position=6;
        }
        else if(sq[7]=='X' && sq[8]=='X' && sq[9]=='0' && sq[1]=='X' && sq[4]=='0' && sq[6]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==2 || position==3)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
        else if(sq[7]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X' && sq[4]=='0' && sq[6]=='\0')
        {
            position=6;
        }
        else if(sq[7]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X' && sq[4]=='0' && sq[6]=='X')
        {
            position=3;
        }
        else if(sq[7]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X' && sq[6]=='0' && sq[4]=='\0')
        {
            position=4;
        }
        else if(sq[7]=='X' && sq[9]=='X' && sq[8]=='0' && sq[2]=='X' && sq[6]=='0' && sq[4]=='X')
        {
            position=1;
        }

        //sq[8]=='X'
        else if(sq[8]=='X' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X' && sq[6]=='0' && sq[4]=='\0')
        {
            position=4;
        }
        else if(sq[8]=='X' && sq[9]=='X' && sq[7]=='0' && sq[3]=='X' && sq[6]=='0' && sq[4]=='X')
        {
            while(1)
                 {
                    position=random();
                    if(position==1 || position==2)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
        }
    //End of the condition sq[5]=='0'
    }
    else if(sq[5]=='X')
    {
        //sq[1]=='0'
        //sq[2]=='X'
         if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[3]=='X' && sq[7]=='0' &&  sq[4]=='X')
         {
             position=6;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X' && sq[6]=='0' && sq[7]=='X')
         {
             position=3;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             position=7;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==3 || position==7)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='\0')
         {
             position=7;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X')
         {
             position=3;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X' && sq[3]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X' && sq[3]=='0' && sq[9]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X' && sq[7]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X' && sq[7]=='0' && sq[4]=='X')
         {
             position=6;
         }

         //sq[3]=='X'
         else if(sq[1]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='X'  && sq[6]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[1]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='X'  && sq[6]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[1]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='X'  && sq[6]=='0' && sq[9]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[4]=='X'
         else if(sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='0' && sq[6]=='\0')
         {
             position=9;
         }
         else if(sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[7]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[7]=='0' && sq[9]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[6]=='X'
         else if(sq[1]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[1]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='X')
         {
             position=8;
         }

         //sq[7]=='X'
         else if(sq[1]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[1]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }


         //sq[8]=='X'
         else if(sq[1]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='X')
         {
             position=6;
         }

         //sq[9]=='X'
         else if(sq[1]=='0' && sq[9]=='X' && sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[1]=='0' && sq[9]=='X' && sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }


         //sq[3]=='0'
         //sq[1]=='X'
         else if(sq[3]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[2]=='X'
          else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='\0')
         {
             position=9;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X' && sq[4]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X' && sq[1]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X' && sq[1]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X' && sq[9]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X' && sq[9]=='0' && sq[6]=='X')
         {
             position=4
             ;
         }

         //sq[4]=='X'
         else if(sq[3]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X' && sq[1]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X' && sq[1]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[6]=='X'
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X' && sq[9]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X' && sq[9]=='0' && sq[8]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X' && sq[9]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X' && sq[8]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==1 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='\0')
         {
             position=1;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X' && sq[1]=='0' && sq[2]=='\0')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X' && sq[1]=='0' && sq[2]=='X')
         {
             position=8;
         }

         //sq[7]=='X'
         else if(sq[3]=='0' && sq[7]=='X' && sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[3]=='0' && sq[7]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[8]=='X'
         else if(sq[3]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X')
         {
             position=4;
         }

         //sq[9]=='X'
         else if(sq[3]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[3]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[3]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }


         //sq[7]=='0'
         //sq[1]=='X'
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[3]=='X' && sq[2]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='\0')
         {
             position=3;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[1]=='X' && sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[2]=='X'
         else if(sq[7]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='X')
         {
             position=6;
         }

         //sq[3]=='X'
         else if(sq[7]=='0' && sq[3]=='X' && sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[3]=='X' && sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[4]=='X'
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[1]=='X' && sq[9]=='0' && sq[3]=='\0')
         {
             position=3;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='\0')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[2]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[2]=='0' && sq[8]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==1 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='X' && sq[2]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==1 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X' && sq[1]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X' && sq[1]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X' && sq[1]=='0' && sq[3]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[6]=='X'
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X' && sq[9]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X' && sq[9]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='\0')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X' && sq[8]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[3]=='X' && sq[9]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[3]=='X' && sq[9]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='\0')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             position=9;
         }

         //sq[8]=='X'
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X' && sq[9]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X' && sq[9]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X' && sq[9]=='0' && sq[3]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X' && sq[1]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X' && sq[1]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X' && sq[6]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X' && sq[6]=='0' && sq[9]=='X')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==1 || position==9)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='\0')
         {
             position=1;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             position=9;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='\0')
         {
             position=4;
         }
         else if(sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='X')
         {
             position=6;
         }

         //sq[9]=='X'
         else if(sq[7]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[7]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[7]=='0' && sq[9]=='X' && sq[1]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }


         //sq[9]=='0'
         //sq[1]=='X'
         else if(sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[6]=='X'  && sq[4]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[6]=='X'  && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[9]=='0' && sq[1]=='X' && sq[3]=='0' && sq[6]=='X'  && sq[4]=='0' && sq[7]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[9]=='0' && sq[1]=='X' && sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='\0')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[1]=='X' && sq[7]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             position=8;
         }

         //sq[2]=='X'
         else if(sq[9]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='X')
         {
             position=4;
         }

         //sq[3]=='X'
         else if(sq[9]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[9]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[4]=='X'
         else if(sq[9]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='X')
         {
             position=2;
         }

         //sq[6]=='X'
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X' && sq[7]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X' && sq[7]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='\0')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X' && sq[8]=='0' && sq[7]=='X')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='\0')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[3]=='X' && sq[7]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X' && sq[3]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X' && sq[3]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X' && sq[3]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X' && sq[2]=='0' && sq[7]=='X')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==3 || position==7)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[7]=='X'
         else if(sq[9]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[2]=='X')
         {
             position=8;
         }
         else if(sq[9]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[8]=='X')
         {
             position=2;
         }
         else if(sq[9]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==2 || position==8)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }

         //sq[8]=='X'
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X' && sq[3]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[1]=='X' && sq[3]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X' && sq[7]=='0' && sq[4]=='X')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X' && sq[7]=='0' && sq[6]=='X')
         {
             position=4;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[3]=='X' && sq[7]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==4 || position==6)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='\0')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[4]=='X' && sq[6]=='0' && sq[3]=='X')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X' && sq[4]=='0' && sq[3]=='X')
         {
             position=7;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X' && sq[4]=='0' && sq[7]=='X')
         {
             position=3;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[6]=='X' && sq[4]=='0' && sq[1]=='X')
         {
             while(1)
                 {
                    position=random();
                    if(position==3 || position==7)
                     {
                         break;
                     }
                    else
                     {
                         continue;
                     }
                 }
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='\0')
         {
             position=6;
         }
         else if(sq[9]=='0' && sq[8]=='X' && sq[2]=='0' && sq[7]=='X' && sq[3]=='0' && sq[6]=='X')
         {
             position=4;
         }
    //End of condition sq[5]=='X'
    }
    return position;
}
