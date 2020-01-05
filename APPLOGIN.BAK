#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>

class AppLogin
{
   char uname[100],pwd[100];
   public : AppLogin()
	    {
	       strcpy(uname,"exam");
	       strcpy(pwd,"exam123");
	    }
	    int Login();
	    void ProgressBar();
};

void AppLogin :: ProgressBar()
{
   int x,y=19;

   for(x=27;x<=60;x++)
   {
      textcolor(WHITE);
      gotoxy(x,y);
      putch(177);
   }

   for(x=27;x<=60;x++)
   {
      textbackground(GREEN);
      gotoxy(x,y);
      putch(32);
      delay(100);
      gotoxy(49,y-2);
      cout<<x+40<<"% Loading";
   }
   textcolor(WHITE);
   textbackground(BLACK);
}

int AppLogin :: Login()
{
   int x=22,y=11;
   char u[100],p[100];
   int i=0;
   static int cnt=1;

   textcolor(WHITE);
   textbackground(BLACK);
   gotoxy(x,y);
   printf("Enter username : ");
   cin>>u;
   gotoxy(x,y+2);
   cout<<"Enter password : ";
   while((p[i]=getch())!=13)
   {
      if(p[i]==8 && i>0)
      {
	 cout<<"\b \b";
	 i--;
      }
      else if(p[i]!=8)
      {
	 cout<<"*";
	 i++;
      }
   }
   p[i]='\0';

   if(strcmpi(uname,u)==0 && strcmp(pwd,p)==0)
	 return 0;
       //	ProgressBar();
   else
   {
	textcolor(RED+BLINK);
	gotoxy(23,18);
	if(cnt==1)
	   cprintf("Try again...Only 2 attempts left!");
	else if(cnt==2)
	   cprintf("Try again...Only 1 attempt left!");
	else
	   cprintf("******** ACCESS DENIED ********");
	cnt++;
	textcolor(WHITE);
	delay(3000);
	return 1;
   }
}