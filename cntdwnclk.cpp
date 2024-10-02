#include <bits/stdc++.h>
#include <graphics.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib\\libbgi.a"); // Điều chỉnh đường dẫn tới libbgi.a của Dev-C++
    
    int minutes, seconds; // Thời gian đếm ngược (s)
	cin >> minutes >> seconds;
    
	while(minutes >= 0){
		while (seconds >= 0) {
			cleardevice();
			char countdown[10];
			sprintf(countdown, "%02d", seconds);
			outtextxy(150, 150, countdown);
			delay(1000); // Đợi 1 giây trước khi cập nhật đồng hồ đếm ngược
			seconds--;
		}
		seconds = 59;
		minutes--;
	}
    
    closegraph();
    return 0;
}
