#include <iostream>
#include <easyx.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
struct XY
{
	int x, y;
};
struct mage
{
	IMAGE MG[999];
	XY ip;
};
void sxjc()
{
	cleardevice();
	IMAGE MAP;
	loadimage(&MAP, L"map.jpg");
	mage zaw;
	loadimage(&zaw.MG[0], L"zaw1.jpg");
	loadimage(&zaw.MG[1], L"p1.jpg");
	loadimage(&zaw.MG[2], L"p2.jpg");
	loadimage(&zaw.MG[3], L"2p1.jpg");
	loadimage(&zaw.MG[4], L"2p2.jpg");
	loadimage(&zaw.MG[5], L"kill1.jpg");
	loadimage(&zaw.MG[6], L"kill2.jpg");
	loadimage(&zaw.MG[7], L"BOSS.jpg");
	loadimage(&zaw.MG[8], L"BOSS2.jpg");
	zaw.ip.x = 0, zaw.ip.y = 0;
	int sfk=3;
	int sper = 0;
	int kx = 0, ky = 550;
	int gh = 0; //方向
	int kilop=1;//炮弹
	int kil = 1;//锁
	int kilpor = 0;//方向锁
	int bx, by;
	bx = rand() % 1105 + 1;
	by = rand() % 254 + 200;
	while(true)
	{
		while(!_kbhit())
		{
			if(kx==bx)
			{
				if (ky  < by+95 && ky> by-35 )
				{
					bx = rand() % 1105 + 1;
					by = rand() % 254 + 200;
				}
			}
			if (gh == 0)
			{
				cleardevice();
			Q1:
				BeginBatchDraw();
				putimage(0, 0, &MAP);
				putimage(kx, ky, &zaw.MG[5], SRCPAINT);
				putimage(kx, ky, &zaw.MG[6], SRCAND);
				putimage(0, 550, &zaw.MG[0]);
				putimage(zaw.ip.x, zaw.ip.y, &zaw.MG[1], SRCPAINT);
				putimage(zaw.ip.x, zaw.ip.y, &zaw.MG[2], SRCAND);
				putimage(bx, by, &zaw.MG[7], SRCPAINT);
				putimage(bx, by, &zaw.MG[8], SRCAND);
				EndBatchDraw();
				if (zaw.ip.y < 470 && sper == 0)
				{
					zaw.ip.y++;
				}
				if (sper > 0)
				{
					zaw.ip.y = zaw.ip.y - 1;
					sper--;
				}
				if (sfk == 1 && zaw.ip.y == 470)
				{
					sfk = 3;
				}
			}
			//perL
			if (kilop == 1)
			{
				if (kilpor==1)
				{
					kx--;
				}
				if(kilpor==2)
				{
					kx++;
				}
				if (kx < 0 || kx>1200)
				{
					kx = 0, ky = 550;
					kilop = 0;
					kil = 1;
					kilpor = 0;
				}
			}
			if (gh == 1)
			{
				cleardevice();
			Q2:
				BeginBatchDraw();
				putimage(0, 0, &MAP);
				putimage(kx, ky, &zaw.MG[5], SRCPAINT);
				putimage(kx, ky, &zaw.MG[6], SRCAND);
				putimage(0, 550, &zaw.MG[0]);
				putimage(zaw.ip.x, zaw.ip.y, &zaw.MG[3], SRCPAINT);
				putimage(zaw.ip.x, zaw.ip.y, &zaw.MG[4], SRCAND);
				putimage(bx, by, &zaw.MG[7], SRCPAINT);
				putimage(bx, by, &zaw.MG[8], SRCAND);
				EndBatchDraw();
				if (zaw.ip.y < 470 && sper == 0)
				{
					zaw.ip.y++;
				}
				if (sper > 0)
				{
					zaw.ip.y = zaw.ip.y - 1;
					sper--;
				}
				if (sfk == 1 && zaw.ip.y == 470)
				{
					sfk = 3;
				}
			}
		}
		switch (_getch())
		{
		case'd':
			if (zaw.ip.x + 85 < 1200)
			{
				zaw.ip.x = zaw.ip.x + 10;
			}
			gh = 0;
			goto Q1;
			break;
		case'a':
			if (zaw.ip.x > 0) {
				zaw.ip.x = zaw.ip.x - 10;
			}
			gh = 1;
			goto Q2;
			break;
		case 'k':
			if (kil == 1)
			{
				kx = zaw.ip.x + 14;
				ky = zaw.ip.y + 14;
				if(gh==1&&kilpor==0)
				{
					kilpor = 1;
				}
				if(gh == 0 && kilpor == 0)
				{
					kilpor = 2;
				}
				kilop = 1;
				kil--;
			}
			cout << kilpor << endl;
			goto Q1;
			break;
		case 32:
			if (sfk >1)
			{
				sper = 200;
				sfk--;
			}
			cout << "spert" << endl;
			cout << zaw.ip.x << " " << zaw.ip.y << endl;
			break;
		default:
			goto Q1;
			break;
		}
	}
}
using namespace std;
int main()
{
	mage zaw;
	IMAGE MAP;
	loadimage(&MAP, L"map.jpg");
	initgraph(1200, 750,EX_SHOWCONSOLE);
	putimage(0, 0, &MAP);
	loadimage(&zaw.MG[0], L"zaw1.jpg");
	putimage(0, 550, &zaw.MG[0]);
	mciSendString(L"open lop.mp3",0,0,0);
	mciSendString(L"play lop.mp3",0,0,0);
	getchar();
	while(true)
	 {
		sxjc();
	 }
	getchar();
}