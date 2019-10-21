#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int op[20],xc1[20],yc1[20],xc2[20],yc2[20],count=0,lcount=0,fcount=0;
FILE *fp;

union REGS in, out; // Mouse Objects

void matrixtrans(int x,int y,int tx,int ty,int *t)
{
     t[0]=x+tx;
     t[1]=y+ty;
}
void matrixscale(int x1,int y1,int x2,int y2,float s,int *t)
{
	matrixtrans(x2,y2,-x1,-y1,t);

	t[0]=t[0]*s;
	t[1]=t[1]*s;

	matrixtrans(t[0],t[1],x1,y1,t);

}

void matrixrot(int x1,int y1,int x2,int y2,int d,int *t)
{
int u,v;
	matrixtrans(x2,y2,-x1,-y1,t);
	u=t[0];
	v=t[1];
	t[0]=(u*cos(d*3.14/180))-(v*sin(d*3.14/180));
	t[1]=(u*sin(d*3.14/180))+(v*cos(d*3.14/180));

	matrixtrans(t[0],t[1],x1,y1,t);

}


void dda(float x1,float y1,float x2,float y2,int c)
{

 float delx,dely,adelx,adely;
 float len;
 float X,Y;
 int i;

 delx=x2-x1;
 dely=y2-y1;

 adelx=abs(delx);
 adely=abs(dely);

 if(adelx>=adely)
  len=adelx;
 else
  len=adely;


 delx=delx/len;
 dely=dely/len;
 if(delx==0)
 X= x1;
 else
 X= x1 + 0.5 * (abs(delx)/delx);  // sign
 if(dely==0)
 Y = y1;
 else
 Y= y1 + 0.5 * (abs(dely)/dely);
 i=0;

 while(i<=len)
 {
  putpixel((int)X,(int)Y,c);
  X+=delx;
  Y+=dely;
  i++;

 }
}
void triangle(float x1,float y1,float x2,float y2,int c)
{
dda(x1,y2,(x1+x2)/2,y1,c);
dda((x1+x2)/2,y1,x2,y2,c);
dda(x1,y2,x2,y2,c);
}

void rect(float x1,float y1,float w,float h,int c)
{
dda(x1,y1,x1+w,y1,c);
dda(x1,y1,x1,y1-h,c);
dda(x1+w,y1,x1+w,y1-h,c);
dda(x1,y1-h,x1+w,y1-h,c);
}



int getselectedshape(float x,float y)
{
int s;
if(x>=20 && x<=50)
{
	if(y>=70 && y<=100)
	s=1; //line selected
	else if(y>=110 && y<=140)
	s=2; //rectangle selected
	else if(y>=150 && y<=180)
	s=3; //triangle
	else if(y>=190 && y<=220)
	s=4; //circle

}

return s;
}



void createLayer(int cnt,int sr)
{
		rect(560,60+30*(cnt),79,30,1);
		settextstyle(0,0,1);
		setcolor(1);
		if(sr==1)
		outtextxy(570,45+30*(cnt),"Line");
		else if(sr==2)
		outtextxy(570,45+30*(cnt),"Rect");
		else if(sr==3)
		outtextxy(570,45+30*(cnt),"Triangle");
		else if(sr==4)
		outtextxy(570,45+30*(cnt),"Circle");
}

int selectLayer(int y)
{
y=y-30;
	if(y<=30+30*count)
	{
		y=y/30;
		return y;
	}
	else
		return -1;
}

void opArray()
{
int i=0;
	while(i<count)
	{

		  if(op[i]==1)
		  {	dda(xc1[i],yc1[i],xc2[i],yc2[i],1);

			createLayer(i,op[i]);
		  }
		  else if(op[i]==2)
		  {     setcolor(1);
			rectangle(xc1[i],yc1[i],xc2[i],yc2[i]);
			createLayer(i,op[i]);  }
		  else if(op[i]==3)
		  {
		  triangle(xc1[i],yc1[i],xc2[i],yc2[i],1);
		  createLayer(i,op[i]);
		  }

		  else if(op[i]==4)
		  {    setcolor(1);
			circle(xc1[i],yc1[i],abs(sqrt(((yc2[i]-yc1[i])*(yc2[i]-yc1[i]))+((xc2[i]-xc1[i])*(xc2[i]-xc1[i])))));
			createLayer(i,op[i]);	}


	  i++;
	}
}


void layout()
{

settextstyle(0,0,1);
setbkcolor(7);


rect(0,479,639,477,1);
dda(560,0,560,400,1); // scaling toolbox
dda(0,400,650,400,1); // layer tool box
dda(70,0,70,480,1); // toolbox
setcolor(5);
outtextxy(8,50,"TOOLBAR");


setfillstyle(1,1);

bar(0,0,650,30);
setcolor(BLACK);
outtextxy(250,10,"VECTOR GRAPHICS EDITOR");
outtextxy(10,10,"[X]");
rect(20,100,30,30,3);
dda(25,75,45,95,4); // line tool
rect(20,140,30,30,3);
rect(25,135,20,20,4);  // rect tool
rect(20,180,30,30,3);
dda(25,175,45,175,4);  // draw triangle
dda(25,175,35,160,4);
dda(45,175,35,160,4);
rect(20,220,30,30,3);
setcolor(4);
circle(35,205,10);

setcolor(5);

outtextxy(8,235,"SCALE");
rect(20,275,30,20,3);
setcolor(4);
outtextxy(32,260,"-");
rect(20,305,30,20,3);
outtextxy(32,290,"+");

setcolor(5);
outtextxy(8,320,"ROTATE");
rect(20,360,30,20,3);
setcolor(4);
outtextxy(32,345,"-");
rect(20,390,30,20,3);
outtextxy(32,375,"+");


rect(100,450,50,30,3);
outtextxy(110,430,"SAVE");

rect(180,450,50,30,3);
outtextxy(190,430,"LOAD");

setcolor(5);



settextstyle(0,1,0);
setcolor(5);
outtextxy(40,410,"OBJECT");

//setextstyle(0,0,1);
}

void clr()
{
clrscr();
}

void newfile()
{

in.x.ax =2;
int86(51,&in,&out);
layout();
clrscr();
in.x.ax =1;
int86(51,&in,&out);

}

void saving()
{

int i=0;

fp=fopen("Display.txt","w+");

while(i<count)
{

fprintf(fp,"%d %d %d %d %d",op[i],xc1[i],yc1[i],xc2[i],yc2[i]);



fputs(",",fp);

i++;
}



fputs(".",fp);
fclose(fp);
}


void read1()
{
int i=0;
char t,ch;
fp=fopen("Display.txt","r");
	while(1)
	{

       ch=getc(fp);
       if(ch=='.')
       {
       break;
       }
	else
       {
       fseek(fp,-1,1);
		fscanf(fp,"%d %d %d %d %d%c",&op[i],&xc1[i],&yc1[i],&xc2[i],&yc2[i],&t);


	}
i++;
	}
count=i;
//lineto(x,y);
fclose(fp);

}

void main()
{
int gdriver=DETECT,gmode,x1,y1,x2,y2,j; /* */
 int layerflag=-1,layertrue=0,d_x,d_y,objno=-13; /* layertrue */
 int *t;
 float radius;
 //FILE fp*;

 int mousetx,mousety,mouseb,flag=0;
 initgraph(&gdriver,&gmode,"..//bgi");



setcolor(4);
in.x.ax =0; // for finding current mouse position
 in.x.ax =1; // set mouse pos.
 int86(51,&in,&out);

 in.x.ax=3; // get points

 int86(51,&in,&out);

	while(!kbhit())
	{


	  layout();
	if(count!=0) // count=No. of objects
	opArray();
	mouseb=out.x.bx;//left
	mousetx=out.x.cx;//x.pos
	mousety=out.x.dx;//y.pos
	int86(51,&in,&out);

	if(mouseb==1 && flag==0) // Left Click
	{
	 x1=out.x.cx;
	 y1=out.x.dx;
	 if(x1>=560 && y1>=30)
	 {
		flag=0;
		layerflag=selectLayer(y1);
	 }
	 else if(x1<=70 && y1>=30 && y1<=230)
	 {
		objno=getselectedshape(x1,y1);
	 }
	 else if(x1>=20 && x1<=50 && y1>=255 && y1<=275)
	 {
		matrixscale(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],0.5,t);
		xc2[layerflag]=t[0];
		yc2[layerflag]=t[1];
	 }
	 else if(x1>=20 && x1<=50 && y1>=295 && y1<=305)
	 {
		matrixscale(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],2,t);
		xc2[layerflag]=t[0];
		yc2[layerflag]=t[1];
	 }
	 else if(x1>=20 && x1<=50 && y1>=340 && y1<=360)
	 {
		matrixrot(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],-5,t);
		xc2[layerflag]=t[0];
		yc2[layerflag]=t[1];
	 }
	 else if(x1>=20 && x1<=50 && y1>=370 && y1<=390)
	 {
		matrixrot(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],5,t);
		xc2[layerflag]=t[0];
		yc2[layerflag]=t[1];
	 }


	 else if(x1>=0 && x1<=70 && y1>=400)
	 {
	 layerflag=-1;
	 }

	 else if(x1>=100 && x1<=150 && y1>=420 && y1<=450)
	 {
	// clr();
	// read1();
	 saving();

	 }
	 else if(x1>=180 && x1<=230 && y1>=420 && y1<=450)
	 {
	  clr();
	  read1();
	 }


	 else if(x1>=0 && x1<=30 && y1>=0 && y1<=30)
	 {
		exit(0);
	 }
	 else
	 {flag=1;}

	 if(layerflag!=-1) // If any Layer is selected
	 {
			if(op[layerflag]==1)  //for line
			{
			dda(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],2 );
			clr();
			}
			else if(op[layerflag]==2)
			{  setcolor(2);
  			   rectangle(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag]);
			  clr();
			   }

			   else if(op[layerflag]==3)
	{
  	triangle(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],2);
	clr();
	}
			else if(op[layerflag]==4)
			{  setcolor(2);
    			   radius=abs(sqrt(((yc2[layerflag]-yc1[layerflag])*(yc2[layerflag]-yc1[layerflag]))+((xc2[layerflag]-xc1[layerflag])*(xc2[layerflag]-xc1[layerflag]))));
  			   circle(xc1[layerflag],yc1[layerflag],radius);
				clr();
			}

			   else
			{ }
			flag=2; // If any Layer flag has been selected
	 }

	}

	if(mouseb==1 && flag==1) // Left Key
	{
	  x2=out.x.cx;
	  y2=out.x.dx;
	
	  if(objno==1)            //to draw line
	  { dda(x1,y1,x2,y2,1);
	  clr();
	  }
	  else if(objno==2)	//rectangle
	  { setcolor(1);
	    rectangle(x1,y1,x2,y2);
clr();
		}
	  else if(objno==3)
	  {
	  triangle(x1,y1,x2,y2,1);
	  clr();
	  }
	  else if(objno==4)
	  { setcolor(1);
	    radius=abs(sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1))));
	    circle(x1,y1,radius);
		clr();
  }
	
	  else
	  { }


	  }

	
	if(mouseb==0 && flag==1)
	{
	 if(objno==1)
	 { 	op[count]=1;
		xc1[count]=x1;
		yc1[count]=y1;
		xc2[count]=x2;
		yc2[count++]=y2; }
	 else if(objno==2)
	 { 	op[count]=2;
		xc1[count]=x1; yc1[count]=y1; xc2[count]=x2; yc2[count++]=y2;
	 }
	 else if(objno==3)
	 {
	 op[count]=3;
		xc1[count]=x1; yc1[count]=y1; xc2[count]=x2; yc2[count++]=y2;


	 }
	 else if(objno==4)
	 {
		op[count]=4;
		xc1[count]=x1; yc1[count]=y1; xc2[count]=x2; yc2[count++]=y2;
	}
	flag=0;
	}

	if(mouseb==1 && flag==2) // Object  Moving
	{
	  x2=out.x.cx;
	  y2=out.x.dx;

	  d_x=x2-x1;
	  d_y=y2-y1;
	  xc1[layerflag]+=d_x;
	  yc1[layerflag]+=d_y;
	  xc2[layerflag]+=d_x;
	  yc2[layerflag]+=d_y;

	  x1=x2;
	  y1=y2;
	}
	if(mouseb==0 && flag==2)
	{
	  d_x=x2-x1;
	  d_y=y2-y1;
	  matrixtrans(xc1[layerflag],yc1[layerflag],d_x,d_y,t);
	  xc1[layerflag]=t[0];
	  yc1[layerflag]=t[1];
	  matrixtrans(xc2[layerflag],yc2[layerflag],d_x,d_y,t);
	  xc2[layerflag]=t[0];
	  yc2[layerflag]=t[1];


	  if(op[layerflag]==1)
	  {  dda(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],1);
	  clr();
	  }
	  else if(op[layerflag]==2)
	  {  setcolor(1);
	     rectangle(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag]);
		 clr();
		 }
		else if(op[layerflag]==3)
	{
	triangle(xc1[layerflag],yc1[layerflag],xc2[layerflag],yc2[layerflag],1);
	clr();
	}
	  else if(op[layerflag]==4)
	  {  setcolor(1);
	     radius=abs(sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1))));
	     circle(xc1[layerflag],yc1[layerflag],radius);
clr();		 }
	  else
	  { }
	  flag=0;
	}


}
getch();
closegraph();

}

