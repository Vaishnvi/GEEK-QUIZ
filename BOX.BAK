#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<dos.h>

class Box
{
   int x,y,x1,y1;
   char *title;
   public : Box(int a,int b,int c,int d,char *n)
	    {
	       x=a; y=b; x1=c; y1=d;
	       title = new char[strlen(n)+1];
	       strcpy(title,n);
	    }
	    void DrawBox();
	    void Line1();
};

void Box :: Line1()
{
   int i;
   gotoxy(x+1,y+4);
   for(i=x+1;i<x1;i++)
     putch(205);
   gotoxy(x+1,y+2);
   textcolor(BLACK);
   textbackground(3);
   cprintf("******************* %s *******************",title);
   textcolor(WHITE);
   gotoxy(x+5,y+8);
}

void Box :: DrawBox()
{
   int i;
   textcolor(WHITE);
   textbackground(BLUE);
   gotoxy(x,y);
   putch(201);
   gotoxy(x1,y);
   putch(187);
   gotoxy(x,y1);
   putch(200);
   gotoxy(x1,y1);
   putch(188);

   for(i=x+1;i<x1;i++)
   {
      gotoxy(i,y);
      putch(205);
      gotoxy(i,y1);
      putch(205);
   }

   for(i=y+1;i<y1;i++)
   {
      gotoxy(x,i);
      putch(186);
      gotoxy(x1,i);
      putch(186);
   }
}
