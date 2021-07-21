#include<graphics.h>
#include<iostream>
using namespace std;
int main(){
	initwindow(800,600);
	circle(200,300,60);
	rectangle(200,100,250,200);
	ellipse(400,400,0,360,50,25);
	arc(100,00,0,135,50);
	bar(700,200,750,400);
	//setcolor(GREEN);
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	circle(x,y,20);
	outtextxy(x-100,y-50,"CIRCLE");
	while(!kbhit());
	closegraph();
	return 0;
}

