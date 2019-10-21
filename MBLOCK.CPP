int menu1(void);
int level(void);
void abtus1(void);
void help1(void);
int menu1()
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
outtextxy(130,50,"BLOCK SHIFTING");
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

int level()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..//bgi");

char na[7][40]={"LEVEL MENU","LEVEL 1(3 BLOCKS)","LEVEL 2(4 BLOCKS)","LEVEL 3(5 BLOCKS)","LEVEL 4(6 BLOCKS)","LEVEL 5(7 BLOCKS)","     BACK     "};
int i,r=150,ro=180,c=1;
char ch;

while(1)
{
cleardevice();
setbkcolor(1);
setfillstyle(1,4);
bar(220,ro,445,ro+22);
for(i=1,r=175;i<7;i++,r=r+25)
{
setcolor(WHITE);
settextstyle(1,0,5);
outtextxy(205,125,na[0]);
setcolor(10);
settextstyle(1,0,3);
outtextxy(225,r,na[i]);

}
ch=getch();
if(ch==80)
{
	if(ro>280)
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
	ro=305; c=6;}
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
void help1()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"..//bgi");
cleardevice();
char ch;

while(ch!=27)
{
//char ch[150]="  ";
setbkcolor(1);
outtextxy(0,20,"Rules :\n");
outtextxy(0,40,"Player has to move all the blocks from the first to last stick in such");
outtextxy(0,60,"a way that in neither case bigger block should be placed on the smaller one \n");
outtextxy(0,80,"At a time only block can be shifted");
outtextxy(0,100,"Key Information \n :");
outtextxy(0,120,"1.Press Enter to Select or place the block at any place ");
outtextxy(0,140,"2.Left Arrow Key(<--) to move pointer to Left side ");
outtextxy(0,160,"3.Right Arrow Key (-->) to move pointer to Right side ");
outtextxy(0,180,"     \n ENJOY PLAYING THIS WONDERFUL GAME \n       ");
ch=getch();
}
}

void abtus1()
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
