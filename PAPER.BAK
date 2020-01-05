#include<iostream.h>
#include<bios.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#define MAX 4

class Paper
{
    char **a; int correct;     static int cnt;//,tim;
    public : void disp(int,int);
	     void badge();
	     static void badge_reset()
	     {
		 cnt=0;
	     }
	     static int ret_cnt()
	     {
		return cnt;
	     }
	     void SetOptions(char*w,char*x,char*y,char*z,char c)
	     {
		if(c=='A' || c=='a') correct = 0;
		else if(c=='B' || c=='b') correct = 1;
		else if(c=='C' || c=='c') correct = 2;
		else if(c=='D' || c=='d') correct = 3;
		a[0] = new char[strlen(w)+1];
		strcpy(a[0],w);
		a[1] = new char[strlen(x)+1];
		strcpy(a[1],x);
		a[2] = new char[strlen(y)+1];
		strcpy(a[2],y);
		a[3] = new char[strlen(z)+1];
		strcpy(a[3],z);
	     }
	     void options();
};

int Paper :: cnt = 0;
//int Paper :: tim = 30;

void Paper :: badge()
{
   int x=61,y=9,x1=60+cnt*2;

 //  gotoxy(13,9);  textcolor(YELLOW); cprintf("%d",tim); delay(1000);

   for(;x<=70;x++)
   {
      textcolor(WHITE);
      gotoxy(x,y);
      putch(177);
   }

   for(x=61;x<=x1;x++)
   {
      textbackground(YELLOW);
      gotoxy(x,y);
      putch(32);
   }
   gotoxy(72,9); textcolor(YELLOW); textbackground(BLACK); putch(234);
   textcolor(WHITE);
   textbackground(BLACK);
}


void Paper :: disp(int n,int flag)
{
    int i,x=24,y=14;

    for(i=0;i<MAX;i++)
    {
       gotoxy(x,y);
	 if(i==n)
	 {
	     if(flag==0)
	     {
		textcolor(GREEN);
		textbackground(BLACK);
		cprintf("0");   textbackground(GREEN); textcolor(BLACK);
	     }
	     else if(flag==1)
	     {
		textcolor(RED);
		textbackground(BLACK);
		cprintf("0");   textbackground(RED); textcolor(BLACK);

	     }
	     else if(flag==2)
	     {
		textcolor(YELLOW);
		textbackground(BLACK);
		cprintf("0");   textbackground(15); textcolor(BLACK);
	     }                             //    15            BLACK
	 }
	 else
	 {
	     textcolor(WHITE);
	     textbackground(BLACK);   //       5             15
	     cprintf("o");  textbackground(5); textcolor(15);
	 }

	 gotoxy(x+3,y);
	 cprintf("   %s",a[i]);
	 y=y+2;
    }
   textcolor(WHITE);
   textbackground(BLACK);
}

void Paper :: options()
{
    int i=0,ch;
    disp(i,2);

    do
    {
       ch=bioskey(0);

       if(ch==18432)
	 i--;
       if(ch==20480)
	 i++;
       if(i==MAX)
	 i=0;
       if(i==-1)
	 i=MAX-1;

       if(ch==7181)
       {
	   if(correct==i)
	   {
	     disp(i,0);  cnt++;
	     badge();
	   }
	   else
	    disp(i,1);

	    delay(1000);
	 //   return i;
	   break;
       }
       disp(i,2);
    }
    while(ch!=7181);
 //   return i;
}
