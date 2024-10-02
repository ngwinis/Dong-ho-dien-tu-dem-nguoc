#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{ 
	int driver=0, mode = 0;
	initgraph(&driver,&mode,"C:/TC/BGI");
	
	setbkcolor(WHITE); // d?t màu n?n cho c?a s? m?c d?nh
	setviewport(50,50,200,200,1); // t?o m?t c?a s? m?i
//	setfillstyle(1,BLUE); // d?t ki?u và màu tô
//	floodfill(51,51,WHITE); // tô kín c?a s? m?i
	setcolor(RED); // d?t màu v? m?i
	line(100,100,350,100); // v? du?ng n?m ngang trên c?a s? m?i
	getch();
	clearviewport(); // xoá toàn b? nh?ng gì có trong c?a s? hi?n hành
//	line(100,100,350,300); // v? m?t du?ng th?ng khác trên c?a s? hi?n hành
	setviewport(300,50,500,200,1); // t?o m?t c?a s? m?i
//	setfillstyle(1,BLUE); // d?t ki?u và màu tô
//	floodfill(51,51,WHITE); // tô kín c?a s? m?i
	setcolor(RED); // d?t màu v? m?i
	line(350,100,400,100); // v? du?ng n?m ngang trên c?a s? m?i
//	getch();
//	clearviewport();
	getch();
	closegraph();
	return 0;
}
