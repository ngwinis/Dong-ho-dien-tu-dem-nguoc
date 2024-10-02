#include <iostream>
using namespace std;
#include <conio.h>
#include <windows.h>
#include <graphics.h>
using namespace std;
void countdown(int hours,int minutes,int seconds)
{
	while(hours>=0){
		while(minutes >= 0){
		while (seconds >= 0) {
			cleardevice();
			char countdown[10];
			sprintf(countdown, "%02d:%02d:%02d",hours,minutes, seconds);
			outtextxy(10, 10, "Press ESC to quit");
			outtextxy(150, 150, countdown);
			delay(1000); // Đợi 1 giây trước khi cập nhật đồng hồ đếm ngược
			seconds--;
		}
		seconds = 59;
		minutes--;
	}
	minutes=59;
	hours--;
	}
}
main()
{
    initwindow(800,600);
    settextstyle(DEFAULT_FONT,HORIZ_DIR, 2);
    outtextxy(10, 10, "Press ESC to quit");
    char c;
    int x1=150;	
    int y1=150;
    settextstyle(DEFAULT_FONT,HORIZ_DIR, 2);
    char s[100]="00:00:10";
    outtextxy(x1, y1, s);
    int i=0;
    int hours,minutes,seconds;
    while (1)
    {
//        if(kbhit())
//        {
            c = getchar();
            if(c == 27) closegraph();
    		if(c==13)
    		{
    			hours=10*(s[0]-'0') +s[1]-'0';
    			minutes=10*(s[3]-'0') +s[4]-'0';
    			seconds=10*(s[6]-'0')+s[7]-'0';
				countdown(hours,minutes,seconds); 
				continue;
			}
			if(c==8)
			{
				i--;
				if(i==2||i==5||i==8) i--;
				s[i]='0';
			}
            if(c>='0'&&c<='9'&&i<8){
				s[i]=c;
	            i++;
	            if(i==2||i==5||i==8) i++;
			}
            cleardevice();
            outtextxy(10, 10, "Press ESC to quit");
            outtextxy(x1, y1, s);
//        }
    }
    getch();
}
