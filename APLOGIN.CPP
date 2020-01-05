#include "C:\TC\bin\project\applogin.h"
//#include "C:\TC\bin\project\box.h"
#include "C:\TC\bin\project\mainmenu.h"
#include "C:\TC\bin\project\submenu.h"

class ALL
{
   int x,y,x1,y1,cnt,flag,i;
   public :  ALL()
	     {
	       x=16;y=3;x1=62;y1=23;cnt=0;
	     }
	     void setbox()
	     {
	       x=16;y=3;x1=62;y1=23;
	     }
	     int frame1_Login();
	     void frame2_MainMenu();
	     void frame3_SubMenu(int);
	     void frame3a_Admin();
	     void frame3a_AdminSubMenu(int);
 //	     void frame4_User();
};

int ALL :: frame1_Login()
{
  AppLogin a;
   do
   {
     clrscr();
     Box b(x,y,x1,y1,"LOGIN");
     setbox();
     b.DrawBox();
     b.Line1();
     flag=a.Login();
     if(flag==0)
     {
       a.ProgressBar();
       break;
     }
      cnt++;
    }while(flag==1 && cnt<=2);
    return cnt;
}

void ALL :: frame2_MainMenu()
{
    int i=0;
    Menu m;     Admin ad;
    clrscr();
    ad.SetData(); //  delay(1000);
  //  clrscr();
    m.setMenu("Admin","User ","Rank ","Exit ");
    setbox();
    Box b1(x,y,x1,y1,"MENU ");
    b1.DrawBox();
    b1.Line1();
    i=m.arrow();
    clrscr();
    frame3_SubMenu(i);
   // exit(0);
}

void ALL :: frame3_SubMenu(int i)
{
   switch(i)
   {
     case 0 :   Admin ad;
		if(ad.verify()==0)
		{
		    cout<<"\n\n\t\t\t";
		    textcolor(GREEN+BLINK);
		    cprintf("******* Verified as admin !*******");
		    delay(1000);
		    textcolor(WHITE);
		    frame3a_Admin();
		}
		else
		{
		  cout<<"\n\n\t\t\t";
		  textcolor(RED+BLINK);
		  cprintf("******* Access Denied! *******");
		  delay(1000);
		  textcolor(WHITE);
		  frame2_MainMenu();
		}
     //		exit(0);
		break;

     case 1 :  ad.exam();

     case 2 :  //ad.rank();

     case 3 :    clrscr();// cout<<"In exit"<<i;  delay(1000);
		 exit(0);
   }
}

void ALL :: frame3a_Admin()
{
   Menu m;
   int j;
      clrscr();
      m.setMenu("Create","Modify","Delete","Back  ");
      setbox();
      Box b1(x,y,x1,y1,"Paper");
      b1.DrawBox();
      b1.Line1();
      j=m.arrow();
 //     if(j==3)
   //	exit(0);
      frame3a_AdminSubMenu(j);
   //   frame2_MainMenu();
 //  exit(0);
}

void ALL :: frame3a_AdminSubMenu(int j)
{
   Admin ad;

      if(j==0)
      {
	 clrscr();
	 ad.CREATE();
	// ad.DISP();
      }
      else if(j==1)
      {
	 clrscr();
	 ad.MODIFY();
       //	 ad.DISP();
      }
      else if(j==2)
      {
	 clrscr();
     //	 ad.DISP();
	 ad.DEL();
       //	 ad.DISP();
      }
      else if(j==3)
      {
	ad.SAVE();
      //	clrscr();
	frame2_MainMenu();
	//exit(0);
      }

     frame3a_Admin();
  //   exit(0);
}

void main()
{
      ALL a;
      int i,j,cnt;
      clrscr();

      cnt=a.frame1_Login();

      if(cnt==3)
	 exit(0);

      a.frame2_MainMenu();
//      exit(0);

   getch();
}