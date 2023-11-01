#include <bits/stdc++.h>
using namespace std;
#include <conio.h>
#include <windows.h>
#include <graphics.h>
string f[20][150];
char s[100] = "00:00:00";
// nhap vao so tu 0->9
char c;
double time_used;
void build()
{
    ifstream fi;
    for (int i = 0; i <= 9; i++)
    {
        char character = char(i + '0');
        char path[] = "x.txt";
        path[0] = character;
        fi.open(path);
        for (int j = 1; j <= 34; j++) // 34 dong
            fi >> f[i][j];
        fi.close();
    }
    fi.open("colon.txt");
    for(int i = 1; i <= 34; i++)
    {
        fi >> f[10][i];
    }
    fi.close();
    fi.open("timeout.txt");
    for(int i = 1; i <= 160; i++)
    {
    	fi>> f[11][i];
	}
	fi.close();
}

// Ve so tu 0->9
void draw1(int x, int y, char c)
{
    int k = f[c - '0'][1].size();
    for (int i = 1; i <= 40; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (f[c - '0'][i][j] == '1')
            {
                putpixel(x + j, y + i, 15);
            }
        }
    }
}

// Ve lai so o o thu i. Luu y thay doi s[i] truoc roi moi ve lai so
void draw2(int i)
{
    setviewport(100 + 50 * (i - 1), 100, 150 + 50 * (i - 1), 135, 1);
    clearviewport();
    draw1(0, 0, s[i]);
    if(i < 8)
    {
        int k = i;
        if(c != 8)
        {
            setviewport(100 + 50 * (i - 1), 136, 150 + 50 * (i - 1), 140, 1);
            clearviewport(); // xoa line o vi tri hien tai

            if(k == 1 || k == 4) k++;
            if(k != 7)
            {
                setviewport(100 + 50 * k, 136, 150 + 50 * k, 140, 1);
                line(2, 2, 38, 2); // ve line o vi tri chuan bi nhap
            }
        }
        else if (c == 8)   // neu an backspace thi xoa line
        {
            if(i == 1 || i == 4) i++;
            setviewport(100 + 50 * (i - 0), 136, 150 + 50 * (i - 0), 140, 1);
            clearviewport();

            if(k == 2 || k == 5) k--;
            setviewport(100 + 50 * (k - 1), 136, 150 + 50 * (k - 1), 140, 1);
            line(2, 2, 38, 2);
        }
    }
}

// ve chu time out ra man hinh
void timeout(){
	setviewport(100, 150, 360, 320, 1);
	int k = f[11][1].size();
	for(int i = 1; i <= 160; i++){
		for(int j = 1; j <= 256; j++){
			if(f[11][i][j] == '8'){
				putpixel(j, i, 15);
			}
			if(f[11][i][j] == '6' || f[11][i][j] == '7'){
				putpixel(j, i, 14);
			}
			if(f[11][i][j] == '4'){
				putpixel(j, i, 12);
			}
			if(f[11][i][j] == '2'){
				putpixel(j, i, 4);
			}
		}
	}
}

void countdown(char s[100])
{
    while (s[0] >= '0')
    {
        while (s[1] >= '0')
        {
            while (s[3] >= '0')
            {
                while (s[4] >= '0')
                {
                    while (s[6] >= '0')
                    {
                        while (s[7] >= '0')
                        {
                            delay(1000-time_used);
                            if (s[7] == '0')
                                break;
                            s[7] = char(s[7] - 1);
                            if(kbhit())// dung dem--> an phim bat ki
                            {
                                s[7]=char(s[7] + 1);
                                getch();// nhan phim bat ki de dung
                                c = getch();// nhan phim bat ki de tiep tuc dem nguoc
                                if(c == 27)
                                	closegraph();
                            }
                            draw2(7);
                        }
                        if (s[6] == '0')
                            break;
                        s[6] = char(s[6] - 1);
                        if(kbhit())// dung dem--> an phim bat ki
                        {
                            s[6]=char(s[6] + 1);
                            getch();// nhan phim bat ki de dung
                            getch();// nhan phim bat ki de tiep tuc dem nguoc
                        }
                        s[7] = '9';
                        draw2(6);
                        draw2(7);
                    }
                    if (s[4] == '0')
                        break;
                    s[4] = char(s[4] - 1);
                    if(kbhit())// dung dem--> an phim bat ki
                    {
                        s[4]=char(s[4] + 1);
                        getch();// nhan phim bat ki de dung
                        getch();// nhan phim bat ki de tiep tuc dem nguoc
                    }
                    s[6] = '5';
                    s[7] = '9';
                    draw2(4);
                    draw2(6);
                    draw2(7);
                }
                if (s[3] == '0')
                    break;
                s[3] = char(s[3] - 1);
                if(kbhit())// dung dem--> an phim bat ki
                {
                    s[3]=char(s[3] + 1);
                    getch();// nhan phim bat ki de dung
                    getch();// nhan phim bat ki de tiep tuc dem nguoc
                }
                s[4] = '9';
                draw2(3);
                draw2(4);
            }
            if (s[1] == '0')
                break;
            s[1] = char(s[1] - 1);
            if(kbhit())// dung dem--> an phim bat ki
            {
                s[1]=char(s[1] + 1);
                getch();// nhan phim bat ki de dung
                getch();// nhan phim bat ki de tiep tuc dem nguoc
            }
            s[3] = '5';
            s[4] = '9';
            draw2(1);
            draw2(3);
            draw2(4);
        }
        if (s[0] == '0')
            break;
        s[0] = char(s[0] - 1);
        if(kbhit())// dung dem--> an phim bat ki
        {
            s[0]=char(s[0] + 1);
            getch();// nhan phim bat ki de dung
            getch();// nhan phim bat ki de tiep tuc dem nguoc
        }
        s[0] = '9';
        draw2(0);
        draw2(1);
    }
}
main()
{
    initwindow(1000, 600);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    build();
    outtextxy(10, 10, "Press ESC to quit");
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    // khoi tao va hien thi bo dem dang 00:00:00
    for (int i = 0; i < 8; i++)
    {
        setbkcolor(BLACK);
        setviewport(100 + 50 * (i - 1), 100, 150 + 50 * (i - 1), 135, 1);
        draw1(0, 0, s[i]);
    }
    int i = 0;
    int hours, minutes, seconds;
    setviewport(100 + 50 * (i - 1), 136, 150 + 50 * (i - 1), 140, 1);
    line(2, 2, 38, 2);
    while (1)
    {
        if (kbhit())
        {
            c = getch();
			setviewport(100, 150, 360, 320, 1); // truoc khi bat dau bo dem tiep theo can xoa timeout
			clearviewport();
            if (c == 27)
                closegraph(); // nhap esc
            if (c == 13)	  // countdown
            {
                countdown(s);
                timeout(); // sau khi ket thuc 1 lan dem nguoc se hien time out
            }
            if (c == 8 && i > 0) // nhap backspace
            {
                i--;
                if (i == 2 || i == 5 || i == 8)
                    i--;
                s[i] = '0';
                draw2(i);
            }
            if (c == 75 && i > 0) // nhap phim mui ten trai
            {
                i--;
                if (i == 2 || i == 5 || i == 8)
                    i--;
                int k = i;
                if(i >= 0)
                {
                    setviewport(100 + 50 * (k - 1), 136, 150 + 50 * (k - 1), 140, 1);
                    line(2, 2, 38, 2); // ve line o vi tri chuan bi nhap
                }
                if (i == 1 || i == 4) k = i + 1;
                setviewport(100 + 50 * k, 136, 150 + 50 * k, 140, 1);
                clearviewport(); // xoa line o vi tri hien tai
            }
            if (c == 77 && i <= 7) // nhap phim mui ten phai
            {
                int k = i;
                setviewport(100 + 50 * (k - 1), 136, 150 + 50 * (k - 1), 140, 1);
                clearviewport(); // xoa line o vi tri hien tai

                if(k == 1 || k == 4) k++;
                if(i < 7)
                {
                    setviewport(100 + 50 * k, 136, 150 + 50 * k, 140, 1);
                    line(2, 2, 38, 2); // ve line o vi tri chuan bi nhap
                }
                i++;
                if (i == 2 || i == 5)
                    i++;
            }
            if (c >= '0' && c <= '9' && i < 8) // Nhap du lieu
            {
                if((i == 3 || i == 6) && c > '5') // Phut va giay khong qua 59
                    continue;
                s[i] = c;
                clock_t start = clock();
                draw2(i);
                clock_t end = clock();
                time_used = (double)(end-start)/CLOCKS_PER_SEC;
                i++;
                if (i == 2 || i == 5 || i == 8)
                    i++;
            }
        }
    }
    getch();
}
