int menu(void);
void help(void);
void abtus(void);
int resume(void);
int menu()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..//bgi");

char na[5][20]={"  MENU  ","NEW GAME","   HELP  ","ABOUT US","   EXIT  "};
int i,r=150,ro=180,c=1;
char ch;

while(1)
{
cleardevice();
setbkcolor(1);
setfillstyle(1,4);
bar(235,ro,370,ro+22);
for(i=1,r=175;i<5;i++,r=r+25)
{
setcolor(YELLOW);
settextstyle(1,0,6);
outtextxy(100,50,"0-X(ZERO-CROSS)");

setcolor(WHITE);
settextstyle(1,0,5);
outtextxy(205,125,na[0]);
setcolor(10);
settextstyle(1,0,3);
outtextxy(245,r,na[i]);

}
ch=getch();
if(ch==80)
{
	if(ro>230)
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
	ro=255; c=4;}
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

void help()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"..//bgi");
cleardevice();
char ch;

while(ch!=27)
{
//char ch[150]="  ";
setbkcolor(1);
outtextxy(0,20,"Help : \n");
outtextxy(0,40,"This is a game which can be played by maximum 2 players ");
outtextxy(0,60,"One by One Player 1 & Player 2 has to put (O) or (X),");
outtextxy(0,80,"to the empty blocks ");
outtextxy(0,100,"Arrow key can be used to select relative space ");
outtextxy(0,120,"The player who make 3 same sign in the same line wins the game");
outtextxy(0,140,"    \n ENJOY PLYING THIS WONDERFUL GAME \n ");
ch=getch();
}
}

void abtus()
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

int resume()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..//bgi");

char na[3][50]={"Want To Try Another???"," Yes "," No "};
int i,r=150,ro=205,c=1;
char ch;

while(ch!=27)
{
cleardevice();
setbkcolor(1);
setfillstyle(1,4);
bar(235,ro,370,ro+22);
for(i=1,r=200;i<3;i++,r=r+25)
{
setcolor(GREEN);
settextstyle(1,0,5);
outtextxy(50,125,na[0]);
setcolor(10);
settextstyle(1,0,3);
outtextxy(245,r,na[i]);

}
ch=getch();
if(ch==80)
{
	if(ro>225)
	{
	ro=205; c=1;}
	else
	{
	ro+=25; c++;}
}
else if(ch==72)
{
	if(ro<225)
	{
	ro=230,c=2;}
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
