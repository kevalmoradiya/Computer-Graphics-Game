#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include "MENU.CPP"
#include<stdlib.h>
#include "MBLOCK.CPP"


void show(int,int,int,int);
void move(int [],int [],int);
int Block(void);
int OX(void);
int mmenu(void);
int sgame(void);
void abtus2(void);

void main()
{

int gd=DETECT,gm,i,k,p,v;
initgraph(&gd,&gm,"..//bgi");
cleardevice();

ram :

i=mmenu();
if(i==1)
{
k=sgame();
if(k==1)
{
p=OX();
goto ram;
}
else if(k==2)
{
v=Block();
goto ram;
}
else if(k==3)
{
goto ram;
}
}
else if(i==2)
{
abtus2();
goto ram;
}
else if(i==3)
{
closegraph();
exit(0);
}


}


void abtus2()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..//bgi");
cleardevice();
char ch;

while(ch!=27)
{
//char ch[150]="About us";
setbkcolor(1);
outtextxy(50,50,"Created by \n 1.Jaydeep Padariya \n 2.Shyam Vasani \n 3.Keval Moradiya");
outtextxy(50,100,"Maharaja Sayajirav University, Baroda(Vadodara)-390 005");
ch=getch();
}
}




int mmenu()
{

char na[4][25]={" MAIN MENU ","GAME SELECTION","   ABOUT US ","      EXIT  "};
int i,r=150,ro=180,c=1;
char ch;

while(1)
{
cleardevice();
setbkcolor(1);
setfillstyle(1,4);
bar(220,ro,430,ro+22);
for(i=1,r=175;i<4;i++,r=r+25)
{
setcolor(WHITE);
settextstyle(1,0,5);
outtextxy(190,125,na[0]);
setcolor(10);
settextstyle(1,0,3);
outtextxy(230,r,na[i]);

}
ch=getch();
if(ch==80)
{
	if(ro>220)
	{
	ro=180; c=1;}
	else
	{
	ro+=25; c++;}
}
else if(ch==72)
{
	if(ro<200)
	{
	ro=230; c=3;}
	else
	{
	ro-=25; c--;
	}
}
else if(ch==13)
{
return c;
}
}
}

int sgame()
{

char na[4][35]={" GAME MENU ","1.O-X(ZERO-CROSS) ","2.BLOCK SHIFTING ","      BACK   "};
int i,r=150,ro=180,c=1;
char ch;

while(1)
{
cleardevice();
setbkcolor(1);
setfillstyle(1,4);
bar(200,ro,450,ro+22);
for(i=1,r=175;i<4;i++,r=r+25)
{
setcolor(WHITE);
settextstyle(1,0,5);
outtextxy(180,125,na[0]);
setcolor(10);
settextstyle(1,0,3);
outtextxy(220,r,na[i]);

}
ch=getch();
if(ch==80)
{
	if(ro>220)
	{
	ro=180; c=1;}
	else
	{
	ro+=25; c++;}
}
else if(ch==72)
{
	if(ro<200)
	{
	ro=230; c=3;}
	else
	{
	ro-=25; c--;
	}
}
else if(ch==13)
{
return c;
}
}
}





int OX()
{
mnu:
int o;
char ch=0;
o=menu();

if(o==2)
{
help();
goto mnu;
}
if(o==3)
{
abtus();
goto mnu;
}
if(o==4)
{
return 0;
}
more :
if(o==1)
{
int a[3][3];
int w=0,gd=DETECT,gb,x=1,y=200,z=150,p=0,q=0,r=1,v=0;
char na[7]="PLAYER",ma;
initgraph(&gd,&gb,"..//bgi");
for(int i=0;i<3;i++)
{	for(int j=0;j<3;j++)
	{a[i][j]=-1;}
}
while(ch!=27)
{
w=0;
setbkcolor(1);
setcolor(YELLOW);
settextstyle(1,0,3);
outtextxy(50,50,"PRESS Esc TO GO TO CURRENT GAME MENU....");

setcolor(RED);
rectangle(199,149,351,301);
setfillstyle(1,YELLOW);
bar(200,150,350,300);
setcolor(RED);
line(200,200,350,200);
line(200,250,350,250);
line(250,150,250,300);
line(300,150,300,300);
for(i=0;i<5;i++)
{
rectangle(i,i,635+i,475+i);
}
setfillstyle(1,GREEN);
bar(y,z,y+50,z+50);
settextstyle(1,0,7);
outtextxy(150,350,na);
if(r==1)
outtextxy(400,350,"1");
else
outtextxy(400,350,"2");


for(int i=0;i<3;i++)
{	for(int j=0;j<3;j++)
	{
	if(a[i][j]==1)
	{setcolor(BLACK);
	 circle(225+j*50,175+i*50,20);
	 w++;
	}
	else if(a[i][j]==2)
	{ setcolor(BLUE);
	 line(205+j*50,155+i*50,245+j*50,195+i*50);
	   line(245+j*50,155+i*50,205+j*50,195+i*50);
	   w++;
	}
	}
}
ch=getch();

if(ch==80)
{	 if(z==250)
	{z=150; p=0;}
	else
	{z=z+50; p++;}
}
else if(ch==72)
{
	if(z==150)
	{z=250; p=2;}
	else
	{z=z-50; p--;}
}
else if(ch==75)
{
	if(y==200)
	{y=300; q=2;}
	else
	{y=y-50; q--;}
}
else if(ch==77)
{	if(y==300)
	{y=200; q=0;}
	else
	{y=y+50; q++;}
}
else if(ch==10 || ch==13)
{  if(r==1 && a[p][q]==-1)
	{a[p][q]=1;
	circle(y+25,z+25,20);
	r=2;
	}
    else if(r==2 && a[p][q]==-1)
    { a[p][q]=2;r=1;
    setcolor(BLUE);
    line(y+5,z+5,y+45,z+45);
    line(y+45,z+5,y+5,z+45);
    }
}
ma=r+48;
for(int u=0;u<3;u++)
{   for(int j=0;j<3;j++)
     {	if(r==1)
	   { if(a[u][j]!=2)
		{ break;}
	   }
	else if(r==2)
	{  if(a[u][j]!=1)
		{ break;}
	}

     }
	if(j==3)
	{
	v=1;
	for(i=10;i<=100;i++)
       {      	line(225,174+50*u,225+i,174+50*u);
	line(225,175+50*u,225+i,175+50*u);
		line(225,176+50*u,225+i,176+50*u);
	delay(20);
	}

	break;
	}
}
for(int t=0;t<3;t++)
{   for(int j=0;j<3;j++)
     {	if(r==1)
	   { if(a[j][t]!=2)
		{ break;}
	   }
	else if(r==2)
	{  if(a[j][t]!=1)
		{ break;}
	}
     }
	if(j==3)
	{
	v=1;
		for(i=10;i<=100;i++)
       {          line(224+50*t,175,224+50*t,175+i);
	line(225+50*t,175,225+50*t,175+i);
       line(226+50*t,175,226+50*t,175+i);
	delay(20);
	}


	break;
	}
}
if(a[0][0]==1 && a[1][1]==1 &&a[2][2]==1)
{v=1;

	for(i=10;i<=100;i++)
       {   	line(225,174,225+i,174+i);
	line(225,175,225+i,175+i);
		line(225,176,225+i,176+i);
	delay(20);
	}
}
else if(a[0][0]==2 && a[1][1]==2 &&a[2][2]==2)
{v=1;
	for(i=10;i<=100;i++)
       {setcolor(14);
	line(225,174,225+i,174+i);
	line(225,175,225+i,175+i);
		line(225,176,225+i,176+i);
	delay(20);
	}

}
if(a[0][2]==1 && a[1][1]==1 &&a[2][0]==1)
{v=1;
	for(i=10;i<=100;i++)
       {   	line(325,174,325-i,174+i);
	line(325,175,325-i,175+i);
		line(325,176,325-i,176+i);
	delay(20);
	}


}
else if(a[0][2]==2 && a[1][1]==2 &&a[2][0]==2)
{ v=1;
	for(i=10;i<=100;i++)
       {setcolor(10);
	line(325,174,325-i,174+i);
	line(325,175,325-i,175+i);
		line(325,176,325-i,176+i);
	delay(20);
	}


}
cleardevice();
if(v==1)
{ setcolor(GREEN);
if(r==2)
outtextxy(80,200,"PLAYER 1 WON...");
else if(r==1)
outtextxy(80,200,"PLAYER 2 WON...");
getch();
int p;
p=resume();
if(p==1)
{
goto more;
}
else
{
goto mnu;
}
break;
}
if(v!=1 && w==9)
{
char re[30]="No Result...";
char ra[30]="Ok,Try 1 More...";
setcolor(GREEN);
outtextxy(60,165,re);
outtextxy(60,217,ra);
getch();
closegraph();
goto more;
}

if(ch==27)
{
goto mnu;
}

cleardevice();
}
}
getch();
closegraph();
}

int Block()
{
int x1=-1,y1=0,v=1,j;
int *a,*b,*c,size,a1=1,b1=0,x=0,y=0,f=0,mv,dj;
int gd=DETECT,gm;
char ch=0;
lebel :
mv=0;ch=0;

mv=menu1();
if(mv==1)
{
dj=level();
	if(dj==1)
	{
	size=3;
	}
	else if(dj==2)
	{
	size=4;
	}
	else if(dj==3)
	{
	size=5;
	}
	else if(dj==4)
	{
	size=6;
	}
	else if(dj==5)
	{
	size=7;
	}
	else if(dj==6)
	{
	mv=0;ch=0;
	goto lebel;
	}
}
else if(mv==2)
{
help1();
mv=0;ch=0;
goto lebel;
}
else if(mv==3)
{
abtus1();
mv=0;ch=0;
goto lebel;
}
else if(mv==4)
{
return 0;
}
size+=2;
label :
a=new int[size];
b=new int[size];
c=new int[size];

y1=size;

for(int i=0;i<(size-1);i++)
{
 a[i]=i; b[i]=0; c[i]=0;
 }
  a[size-1]=-1; b[size-1]=-1; c[size-1]=-1;

  initgraph(&gd,&gm,"..//bgi");
while(ch!=27)
{
setbkcolor(6);
setcolor(YELLOW);
settextstyle(1,0,3);
outtextxy(50,375,"PRESS Esc TO GO TO CURRENT GAME MENU....");
  setfillstyle(1,GREEN);
  bar(50+(a1-1)*160,150,200+((a1-1)*160),150+(size-1)*20);
  if(b1!=0)
 { setcolor(RED);
  rectangle(50+(b1-1)*160,150,200+((b1-1)*160),150+(size-1)*20);
 }
  for(i=0;i<size;i++)
  {
  show(a[i],0,i,size);

  show(b[i],1,i,size);

  show(c[i],2,i,size);
  }
   ch=getch();
  if(ch==75)
  {
	if(a1!=1)
	{a1--; }
	else if(a1==1)
	{a1=3;}
  }
  else if(ch==77)
  {	if(a1!=3)
	{a1++;}
	else if(a1==3)
	{a1=1;}
  }

 else if(ch==10 || ch==13)
 {
	if(x==0)
	{x=a1;b1=a1;}
	else if(x!=0)
	{y=a1; f=1;}
}
  if(x==y && f==1)
  {b1=0;}

if(x!=y && f==1)
{ x1=0;
 if(x==1)
 {    for(i=1;i<(size-1);i++)
	{
	   if(a[i]>0)
	   {x1=a[i];
	   break;
	   }
	}
  }
else if(x==2)
 {     	for(i=1;i<(size-1);i++)
	{
	   if(b[i]>0)
	   {x1=b[i];
	   break;
	   }
	}
  }
  else if(x==3)
 { 	for(i=1;i<(size-1);i++)
	{
	   if(c[i]>0)
	   {x1=c[i];
	   break;
	   }
	}

}
  y1=size;
  if(y==1)
  {     for(j=1;j<(size-2);j++)
	{
	  if(a[j]==0 && a[j+1]!=0 && a[j+1]!=-1)
	  {
		y1=a[j+1];
	  break;
	  }
	}
  }
else if(y==2)
  {     for(j=(size-2);j>0;j--)
	{
	  if(b[j]==0)
	  {	if(j!=(size-2))
		{y1=b[j+1];}
	  break;
	  }
	}
  }
else if(y==3)
  {     for(j=(size-2);j>0;j--)
	{
	  if(c[j]==0)
	  {	if(j!=(size-2))
		{y1=c[j+1];}
	  break;
	  }
	}
   }
   if(x1<y1 && j!=0 && i!=(size-1))
   { 	if(x==1)
	{a[i]=0;}
	else if(x==2)
	{b[i]=0;}
	 else if(x==3)
	{c[i]=0;}
	if(y==1)
	{a[j]=x1;}
	else if(y==2)
	{b[j]=x1;}
	else if(y==3)
	{c[j]=x1;}


   }
}


for(i=1;i<(size-1);i++)
{  if(c[i]!=i)
  {v=0; break;}
}
if(v==1)
{setcolor(YELLOW);
settextstyle(1,0,7);
outtextxy(50,50,"YOU MADE IT....");
getch();
if(size<7)
{
cleardevice();
settextstyle(1,0,6);
outtextxy(50,50,"TRY NEXT LEVEL....");
getch();
size+=1;
goto label;
}
else
{
mv=0;ch=0;
goto lebel;
}


break;}
if(f==1)
{f=0;x=0;y=0;b1=0;x1=0;v=1;}
cleardevice();
}
if(ch==27)
{
mv=0;ch=0;
goto lebel;
}


getch();
closegraph();



}

void show(int x,int y,int z,int s)
{
if(x==0)
{
line(125+(160*y),150+20*z,125+(160*y),170+20*z);
}
else if(x>0)
{setfillstyle(1,1);
setcolor(CYAN);
bar(125-10*(x)+160*y,150+z*20,125+10*(x)+160*y,170+z*20);
setcolor(RED);
rectangle(125-10*(x)+160*y,150+z*20,125+10*(x)+160*y,170+z*20);
}
else if(x==-1)
{
line(50+160*y,150+((s-1)*20),200+160*y,150+((s-1)*20));
}
}

