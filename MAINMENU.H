#include<iostream.h>
#include<bios.h>
#include<string.h>
#include<process.h>
#define MAX 4

class Menu
{
    char **a;
    public : void disp(int);
	     void setMenu(char*w,char*x,char*y,char*z)
	     {
		a[0] = new char[strlen(w)+1];
		strcpy(a[0],w);
		a[1] = new char[strlen(x)+1];
		strcpy(a[1],x);
		a[2] = new char[strlen(y)+1];
		strcpy(a[2],y);
		a[3] = new char[strlen(z)+1];
		strcpy(a[3],z);
	     }
	     int arrow();
};

void Menu :: disp(int n)
{
    int i,x=26,y=11;

    for(i=0;i<MAX;i++)
    {
	 if(i==n)
	 {
	     textcolor(BLACK);
	     textbackground(WHITE);
	 }
	 else
	 {
	     textcolor(WHITE);
	     textbackground(5);
	 }
	 gotoxy(x,y);
	 cprintf("        <<< %s >>>        ",a[i]);
	 y=y+2;
    }

    gotoxy(23,21);
    textcolor(BROWN+BLINK);
    textbackground(BLACK);
    cprintf("PLEASE HIT <<< ENTER >>> TO GO ....!");
    textcolor(WHITE);

}

int Menu :: arrow()
{
    int i=0,ch,flag;
    disp(i);

    do
    {
  //     flag=0;
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
	   textbackground(0); //flag=1;
	  // clrscr();
	   break;
	 //  return i;
       //	   action(i);
       }
       disp(i);
    }
    while(ch!=7181);
 //   if(flag==1)
      return i;
}
/*
int Menu :: action(int n)
{
   switch(n)
   {
       case 0 :  return 0;

       case 1 :  return 1;

       case 2 :  return 2;

       default : exit(0);
   }
} */