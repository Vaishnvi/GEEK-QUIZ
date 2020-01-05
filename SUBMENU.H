#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<iomanip.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include "C:\TC\bin\project\paper.h"
#include "C:\TC\bin\project\box.h"
#include<Time.h>
#include<Timer.h>

class Node
{
   public : int srno,score;
	    char ques[1000],A[500],B[500],C[500],D[500];
	    char correct;
	    Node *next;
};

class Admin
{
    static Node *head1,*head2,*head3;
    char *pwd;
    static int pno;
    public :  Admin()
	      {
	     //	 head1=NULL;head2=NULL;head3=NULL;
		 strcpy(pwd,"admin123");
	      }
	      int verify();
	      void SetData();
	      Node* SetData(char *,Node *);
	      void CREATE();
	      Node* create(char *,Node *);
	      void MODIFY();
	      void modify(Node *);
	      void DEL();
	      Node* del(Node *);
	      void SAVE();
	      void save(Node *,char *);
  //	      void DISP();
	      void Disp(Node *);
	      void exam();
};
int Admin :: pno=1;
Node * Admin :: head1;
Node * Admin :: head2;
Node * Admin :: head3;

void Admin :: SetData()
{
    head1=NULL;
    head1=SetData("C:\\TC\\bin\\profiles\\f1.txt",head1);
 //   clrscr();
 //   Disp(head1);        delay(5000);      //    clrscr();
  head2=NULL;
  head2=SetData("C:\\TC\\bin\\profiles\\f2.txt",head2); // clrscr();  Disp(head2);  delay(5000); //clrscr();
  head3=NULL;
  head3=SetData("C:\\TC\\bin\\profiles\\f3.txt",head3);//  clrscr();  Disp(head3);delay(7000);  clrscr();
}

Node* Admin :: SetData(char *a,Node *h)
{
    Node *nw,*last; const int size=100;
    char line[size];
    ifstream inf; int k,i,j,b; char ch;
    inf.open(a);          inf.seekg(0,ios::end);   b=inf.tellg(); // cout<<b;
	   i=194;     inf.seekg(0,ios::beg);
	   //188+6
   while(i<b)
   {
     // k=i+k;
      k=i;
      nw=new Node;
      nw->next=NULL;     // clrscr();

      if(inf.eof()==1) break;

      for(j=0;i<=k+59;i++,j++)
      {	 inf.seekg(i);
      //	 if(inf.eof()==1){ flag=1; break; }
	 inf.get(ch);	 nw->ques[j]=ch;
      }
      nw->ques[j]='\0'; // cout<<nw->ques<<endl;

      for(j=0;i<=k+89;i++,j++)
      {
	 inf.seekg(i);  inf.get(ch);
	 nw->A[j]= ch;
      }
      nw->A[j]='\0';    // cout<<nw->A<<endl;

      for(j=0;i<=k+119;i++,j++)
      {
	  inf.seekg(i);  inf.get(ch);
	  nw->B[j]= ch;
      }
      nw->B[j]='\0';       // cout<<nw->B<<endl;

      for(j=0;i<=k+149;i++,j++)
      {
	  inf.seekg(i);  inf.get(ch);
	  nw->C[j]= ch;
      }
      nw->C[j]='\0';           // cout<<nw->C<<endl;

      for(j=0;i<=k+179;i++,j++)
      {
	  inf.seekg(i);   inf.get(ch);
	  nw->D[j]= ch;
      }
      nw->D[j]='\0';          // cout<<nw->D<<endl;
      inf.seekg(i);     inf.get(ch);
      nw->correct=ch;
      i++;                   // cout<<nw->correct;
      inf.seekg(i);   inf.get(ch);
      nw->score = ch-'0';      // cout<<nw->score;
      i++;inf.seekg(i);
    if(h==NULL)
	 h=nw;
    else
	last->next=nw;
    last=nw;
   if(inf.eof()==1)
      break;
    i=i+6;

//    inf.getline(line,size);
  //  cout<<"Next line";
  //  delay(5000);
   }
   inf.close();
   return h;
}

int Admin :: verify()
{
     char p[100];
     int i;
     cout<<"\n\n\n\t\t\t\t";
     textcolor(GREEN);
     cprintf(" HEYY ADMIN! ");
     cout<<"\n\n\t\t";
     textcolor(RED);
     cprintf("<----- We need your password for verification ----->");
     cout<<"\n\n\n\t\t\t";
     textcolor(3);
     cprintf("Enter password : ");
     textcolor(WHITE);
     cin>>p;
     i=strcmp(pwd,p);
     return i;
}

void Admin :: CREATE()
{
   char ans;
   cout<<"\n Set question paper 1?";  cin>>ans;
   if(ans=='y')
   { head1=NULL;
   head1 = create("C:\\TC\\bin\\profiles\\f1.txt",head1);
   }   //   Disp(head1);
   cout<<"\n Set question paper 2?";  cin>>ans;
   if(ans=='y')
   { head2 = NULL;                                pno=2;
   head2 = create("C:\\TC\\bin\\profiles\\f2.txt",head2);
   }  //   Disp(head2);
   cout<<"\n Set question paper 3?";  cin>>ans;
   if(ans=='y')
   {
   head3=NULL;                                       pno=3;
   head3 = create("C:\\TC\\bin\\profiles\\f3.txt",head2);
   } //  Disp(head3);
}

Node* Admin :: create(char *a,Node *h)
{
    Node *nw,*last;
    char ans;       int qno=0;
    last=NULL;
    ofstream outf(a);

    //.open(a);
   outf<<setw(6)<<setiosflags(ios::left)<<"Srno"<<setw(60)<<setiosflags(ios::left)<<"Question"<<setw(30)<<setiosflags(ios::left)<<"A"<<setw(30)<<setiosflags(ios::left)<<"B"<<setw(30)<<setiosflags(ios::left)<<"C"<<setw(30)<<setiosflags(ios::left)<<"D"<<"C"<<"S";

    do
    {
      //	qno=0;
	nw = new Node;             qno++;
	clrscr();
	cout<<"\n";
	textcolor(GREEN);
	cprintf("**************************** Set Question Paper %d ******************************",pno);
	cout<<"\n\t"<<qno<<" of 5";
	cout<<"\n\n\t\t";
	textcolor(3);
	cprintf("Enter Question : "); gets(nw->ques);
	cout<<"\n\t\t";
	cprintf("Enter option A : "); gets(nw->A);
	cout<<"\n\t\t";
	cprintf("Enter option B : "); gets(nw->B);
	cout<<"\n\t\t";
	cprintf("Enter option C : "); gets(nw->C);
	cout<<"\n\t\t";
	cprintf("Enter option D : "); gets(nw->D);
	cout<<"\n\t\t";
	cprintf("Enter Correct Option : "); cin>>nw->correct;
	cout<<"\n\t\t";
	cprintf("Enter MaxScore : "); cin>>nw->score;

 //	nw->next=NULL;

    //	outf.open(a);
  //	ofstream outf(a);
	outf<<setw(6)<<setiosflags(ios::left)<<nw->srno<<setw(60)<<setiosflags(ios::left)<<nw->ques<<setw(30)<<setiosflags(ios::left)<<nw->A<<setw(30)<<setiosflags(ios::left)<<nw->B<<setw(30)<<setiosflags(ios::left)<<nw->C<<setw(30)<<setiosflags(ios::left)<<nw->D<<nw->correct<<nw->score<<setiosflags(ios::left)<<setw(10);
	nw->next=NULL;

	if(h==NULL)
	  h=nw;
	else
	   last->next=nw;

       last=nw;
       cout<<"\n\n";
       textcolor(RED);
       cprintf("Want to set Next Question ?(y/n)");
       textcolor(WHITE);
       ans=getche();
    }
     while(ans!='n' && qno<=5);
     clrscr();
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t";
     textcolor(GREEN+BLINK);
     cprintf("********* Question Paper Set Successfully ! ********\n");
     delay(2000);
     textcolor(WHITE);
     outf.close();
//     pno++;

     return h;
}

void Admin :: Disp(Node *head)
{
  //  clrscr();
    cout<<"\n IN disp";
    for(;head!=NULL;head=head->next)
      cout<<"\nQues: "<<head->ques<<"\nA:"<<head->A<<"\nB:"<<head->B<<"\nC:"<<head->C<<"\nD:"<<head->D<<"\nCorrect:"<<head->correct<<"\nScore:"<<head->score;

    cout<<"\n OUT disp";
    delay(2000);
}

void Admin :: MODIFY()
{
    int no;
//    clrscr();
    cout<<"\n************ Modification of Question paper ************\n";
    cout<<"\n Enter paper number to modify (1/2/3) :  ";
    cin>>no;
    if(no>=1 && no<=3)
    {
      if(no==1)
      {	modify(head1);
//	Disp(head1);
      }
      else if(no==2)
      {
	modify(head2); }  //  Disp(head2);}
      else if(no==3)
      {	modify(head3); }
   //	Disp(head3);
    }
    else
      cout<<"\n\n Invalid Paper no !";
}

void Admin :: modify(Node *h)
{
   int qno,ch,cnt;
  // char ans;
   Node *p;
   p=h;

   cout<<"\n Which Question number do you want to modify (1/2/3/4/5) ? ";
   cin>>qno;

   for(cnt=1;p!=NULL && cnt<qno;cnt++,p=p->next);

   if(qno>=1 && qno<=5)
   {
	cout<<"\n\t********** MODIFY **********\n\n";
	cout<<"\n\t1. Question ";
	cout<<"\n\t2. Option A";
	cout<<"\n\t3. Option B";
	cout<<"\n\t4. Option C";
	cout<<"\n\t5. Option D";
	cout<<"\n\t6. Correct option ";
	cout<<"\n\t7. Max Score";
	cout<<"\n\t Enter choice : ";
	cin>>ch;

	cout<<"\n"<<p->ques<<endl;

	switch(ch)
	{
	  case 1 : cout<<"\n Enter new question : ";
		   gets(p->ques);
		   break;
	  case 2 : //p->A="\0";
		   cout<<"\n Enter Option A for question : ";
		   gets(p->A);
		   break;
	  case 3 : //p->B="\0";
		   cout<<"\n Enter Option B for question : ";
		   gets(p->B);
		   break;
	  case 4 : //p->C="\0";
		   cout<<"\n Enter Option C for question : ";
		   gets(p->C);
		   break;
	  case 5 : //p->D="\0";
		   cout<<"\n Enter Option D for question : ";
		   gets(p->D);
		   break;
	  case 6 : p->correct=NULL;
		   cout<<"\n Enter Correct option for question : ";
		   cin>>p->correct;
		   break;
	  case 7 : p->score=0;
		   cout<<"\n Enter modified score for question : ";
		   cin>>p->score;
		   break;
	 default : cout<<"\nInvalid choice !";
	}
   }
   else
      cout<<"\n\n Invalid question number !";

//  return p;
}

void Admin :: DEL()
{
    int no;
    cout<<"\n************ Delete a Question paper ************\n";
    cout<<"\n Enter paper number to Delete (1/2/3) :  ";
    cin>>no;
    if(no>=1 && no<=3)
    {
      if(no==1)
      {	head1=del(head1); //  Disp(head1);
      }
      else if(no==2)
      {	head2=del(head2);  // Disp(head2);
      }
      else if(no==3)
      { head3=del(head3);  // Disp(head3);
      }
    }
    else
      cout<<"\n\n Invalid Paper no !";
}

Node* Admin :: del(Node *head)
{
    int cnt;
    Node *p,*nw;  p=head;
    int qno;

	cout<<"\nEnter question number to be deleted (1/2/3/4/5) : ";
	cin>>qno;

	if(qno>=1 && qno<=5)
	{
		for(cnt=1;p!=NULL && cnt<qno-1;p=p->next);

		if(p==head)
		{
			head=p->next;
			free(p);
			cout<<"\n\tDeleted !"; delay(1000);
		}
		else
		{
			p->next=p->next->next;
			free(p->next);
			cout<<"\n\tDeleted !"; delay(1000);
		}
		for(p=head;p->next!=NULL;p=p->next);
		nw=new Node;
		cout<<"\nEnter question to replace the deleted question : ";
		gets(nw->ques);gets(nw->A);gets(nw->B);gets(nw->C);gets(nw->D);cin>>nw->correct;cin>>nw->score;
		nw->next=NULL;
		p->next=nw;
	}
	else
		cout<<"\nInvalid question number !";

   return head;
}

void Admin :: SAVE()
{      //    clrscr();
  // Disp(head1);Disp(head2);Disp(head3);delay(7000);
 //  clrscr();
   save(head1,"C:\\TC\\bin\\profiles\\f1.txt");
   save(head2,"C:\\TC\\bin\\profiles\\f2.txt");
   save(head3,"C:\\TC\\bin\\profiles\\f3.txt");
}

void Admin :: save(Node *h,char*a)
{
   int cnt;

   Node *p; p=NULL; p=h;  clrscr(); Disp(p); delay(1000);
   remove(a);  // SetData(a,p);  clrscr();  Disp(p);  delay(1000);
   ofstream outf1(a);
   outf1<<setw(6)<<setiosflags(ios::left)<<"Srno"<<setw(60)<<setiosflags(ios::left)<<"Question"<<setw(30)<<setiosflags(ios::left)<<"A"<<setw(30)<<setiosflags(ios::left)<<"B"<<setw(30)<<setiosflags(ios::left)<<"C"<<setw(30)<<setiosflags(ios::left)<<"D"<<"C"<<"S";
   for(cnt=1;h!=NULL;h=h->next,cnt++)
     outf1<<setw(6)<<setiosflags(ios::left)<<cnt<<setw(60)<<setiosflags(ios::left)<<h->ques<<setw(30)<<setiosflags(ios::left)<<h->A<<setw(30)<<setiosflags(ios::left)<<h->B<<setw(30)<<setiosflags(ios::left)<<h->C<<setw(30)<<setiosflags(ios::left)<<h->D<<h->correct<<h->score;

   outf1.close();
 //  h=NULL;
}

void Admin :: exam()
{
  // Timer(); double tim;
//  Node *rank;
  char name[100];    char medal[][100] = {"BRONZE","SILVER","GOLD"};
   Paper p; int mark1,pno=0;  Node* arr[]={head1,head2,head3};
   int lno=1; char s[][100]={"COMPUTER WORLD TYCOONS ","   PROGRAMMING BASICS  ","BUGzzz... FIND IF U CAN"};
   cout<<"\n\n\n\n\n\n\n\t\t\t\t*** ABOUT ***";
   cout<<"\n\n\n      Its a 3 level quiz ! Get points to collect badges & go to next level !";
   delay(5000); cout<<"\n\n\n\n\t\t\t Enter your name : "; cin>>name;
//   rank = new Node;
//   ofstream outf("C:\\TC\\bin\\profiles\\rank.txt");
 //  outf<<setiosflags(ios::app|ios::left)<<setw(30)<<name;
   do
   {
     // mark1=0;
      clrscr();
      Paper::badge_reset();
      cout<<"\n\n\n\n\n\n\t\t\t\t  ";
      textcolor(GREEN);
      cprintf("L"); delay(700); cprintf("E"); delay(700); cprintf("V");delay(700);
      cprintf("E"); delay(700); cprintf("L  "); delay(700); cprintf("%d",lno);
      textcolor(RED);  cout<<"\n\n\t\t\t";    cprintf("*** %s ***",s[lno-1]); delay(3000);
      cout<<"\n\n\n\n\t   ";   textcolor(3+BLINK);
      cprintf("Get 5 POINTS to achieve %s BADGE & go to next level !",medal[lno-1]);  delay(5000);
      cout<<"\n\n\n\t\t\t\t ";  textcolor(5);  cprintf("Starts in");  delay(500);
      cout<<"\n\n\t\t\t\t     ";  textcolor(WHITE+BLINK);   cprintf("3"); delay(700);
      cout<<"\b \b"; cprintf("2"); delay(700); cout<<"\b \b"; cprintf("1"); delay(700);
   //   lno++;  pno++;
      do
      {
	clrscr();
	Box b4(11,3,75,23,s[lno-1]);
	b4.DrawBox();
	b4.Line1();
	p.badge();
	textcolor(YELLOW); textbackground(BLACK);
	gotoxy(14,11); cout<<arr[pno]->ques; // start(); tim=time();
      //	gotoxy(13,9); cout<<tim;
	p.SetOptions(arr[pno]->A,arr[pno]->B,arr[pno]->C,arr[pno]->D,arr[pno]->correct);
       //	mark1 = mark1+p.options();
	 p.options();
	arr[pno]=arr[pno]->next;
      }
      while(arr[pno]!=NULL); // stop();
      if(Paper::ret_cnt()==5)
      {
	clrscr();  textcolor(GREEN); textbackground(BLACK);  cout<<"\n\n\n\n\n\n\t\t\t\t";
	cprintf("!! CONGRATS !!");   delay(2000); textcolor(YELLOW); cout<<"\n\n\n\t\t\t\t      ";
	cprintf("%c",1);   delay(1000);  cout<<"\n\n\n\t\t\t";  textcolor(3);
	cprintf("You just achieved %s badge !",medal[lno-1]);   delay(3000);
      }  lno++; pno++;
   //   outf<<setiosflags(ios::app|ios::left)<<setw(3)<<Paper::ret_cnt();
   }
   while(lno<=3 && Paper::ret_cnt()==5);
 //  outf.close();
}
 /*
void Admin :: rank()
{
     cout<<"\n\n\t\t\t\t"; textcolor(GREEN); cprintf("LEADERBOARD");
     cout<<"\n\n\n\tRank\t\tName\t\tPaper 1\t\tPaper 2\t\tPaper3\t\tBadges";
     ifstream inf("C:\\TC\\bin\\profiles\\rank.txt");
     while(inf.eof()!=1)
     {
	 cout<<"\n\t\t\t";
	 i
     }
}

   */

