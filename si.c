#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 20

void insert_bullet();
void bullet_travel();
void remove_bullet();
void bullet_impact();
void print_grid();
void remove_x();
void bomb_drop1();
void bomb_travel();
void bomb_remove();
int bomb_impact();

int r,c;
int drop1,drop2;
int score=0;

char d2d[ROW][COL]={
        "*******************",
        "*    @ @ @ @ @ @  *",
        "*    @ @ @ @ @ @  *",
        "*                 *",
        "*                 *",
        "*                 *",
        "*                 *",
        "*       A         *",
        "*******************"};

int main()
{

    int dead,i,counter=0;
    int ship_pos;
    char ch;
    ship_pos=8;
    print_grid();


   // kbhit();  use this in loop to detect keyboard key stroke set to True or False
    while(counter < 1000)


  {
           Sleep(250);
           srand((unsigned)time(NULL));
           drop1 = rand()% 15;
           //srand((unsigned)time(NULL));
           drop2 = rand()% 16;

       // ch=getch();
        system("cls");

      if(_kbhit())

      {



            switch(ch=_getch())
            {
                case '.':

                    d2d[7][ship_pos]=' ';
                    d2d[7][ship_pos+1]='A';
                    ship_pos++;

                    break;


                case ',':


                    d2d[7][ship_pos]=' ';
                    d2d[7][ship_pos-1]='A';
                    ship_pos--;

                    break;


                case 'l':

                    d2d[7-1][ship_pos] = '^';
                    Beep(400,30);

                    break;

                default:;
            }
      }

        counter++;
        dead = bomb_impact();
        print_grid();
        system("cls");
        if(dead == 1)
        {
            print_grid();
            Beep(200,200);
            break;
        }

        bomb_remove();
        bomb_travel();
        print_grid();
        remove_x();
        bullet_impact();
        remove_bullet();
        bullet_travel();
        bomb_drop1();


}

return 0;
}

void bullet_travel()
{
    for(r=0;r<10;r++)
        {
            for(c=0;c<20;c++)
            {
                if(d2d[r][c]== '^')
                {
                    d2d[r-1][c]='^';
                    d2d[r][c]=' ';
                }

            }
        }
}

void remove_bullet()
{
            for(c=0;c<20;c++)
            {
                if(d2d[1][c]== '^')
                {
                    d2d[1][c]=' ';
                }
            }
}

void bullet_impact()
{
   for(r=0;r<10;r++)
        {
            for(c=0;c<20;c++)
            {
                if(d2d[r][c]== '^' & d2d[r-1][c]=='@')
                {
                    d2d[r-1][c]='x';
                    d2d[r][c]=' ';
                    score+=10;
                }
            }
        }
}

void print_grid()
{
   int i;

    printf("SCORE - %d\n",score);
    for(i=0;i<10;i++)
   {
       printf("%s\n",d2d[i]);
       //Sleep(30);
   }
}
void remove_x()
{
    for(r=0;r<10;r++)
        {
            for(c=0;c<20;c++)
            {
                if(d2d[r][c]== 'x')
                {
                   Beep(150,100);
                    d2d[r][c]=' ';
                }
            }
        }
}
void bomb_drop1()
{
    if(drop1 >= 5 & drop2 <=15)
        {
        d2d[3][drop1+1] ='v';
        Beep(800,30);
    }

}

void bomb_travel()
{
    for(r=7;r>2;r--)
        {
            for(c=18;c>0;c--)
            {
                if(d2d[r][c]== 'v')
                {
                    d2d[r][c]=' ';
                    d2d[r+1][c]='v';
                }
            }
        }
}
void bomb_remove()
{
        for(c=0;c<20;c++)
            {
                if(d2d[7][c]== 'v')
                {
                    d2d[7][c]=' ';
                }
            }
}

int bomb_impact()
{

            int dead=0;
            for(c=0;c<20;c++)
            {
                if(d2d[6][c]== 'v' & d2d[6+1][c]=='A')
                {
                    d2d[6+1][c]='x';
                    d2d[6][c]=' ';
                    dead = 1;
                    return dead;
                }
            }

            return dead;

}
