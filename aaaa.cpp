#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include <iostream>
using namespace std;

#define x 320
#define y 240

void myline(double x1, double y1, double x2, double y2);
void chengfa(double yt[][3], double js[3][3], double c[][3], int n);
void duichen(double yt[][3]);
void xuanzuan(double yt[][3]);
void pingyi(double yt[][3]);
void fangsuo(double yt[][3]);
void cuoqie(double yt[][3]);
void six(double yt[][3]);
void seven(double yt[][3]);

int main() 
{
	initgraph(640, 480, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	int a;
	double yuantu[12] = { 0,0,10,30,15,15,5,15,15,15,20,0 };
	double yt[5][3] = { 
		0,0,1,
		10,30,1,
		20,0,1,
		15,15,1,
		5,15,1
	};
	while (true) 
	{
		cout << "请选择想要执行的操作:" << endl;
		cout << "1. 关于对称（y=-x）的对称变换" << endl;
		cout << "2.绕着原点逆时针旋转 75 度" << endl;
		cout << "3. 平移（x 方向 52，y 方向 60）" << endl;
		cout << "4. 将原图放大为 2 倍，将原图缩小为 0.5" << endl;
		cout << "5. X 方向错切 15 度" << endl;
		cout << "6.实现关于（10，15）点旋转 90 度" << endl;
		cout << "7.实现关于 y=15x+30 对称" << endl;
		cin >> a;
		switch (a)
		{
		case 1:duichen(yt); break;
		case 2:xuanzuan(yt); break;
		case 3:pingyi(yt); break;
		case 4:fangsuo(yt); break;
		case 5:cuoqie(yt); break;
		case 6:six(yt); break;
		case 7:seven(yt); break;
		default:break;
		}
	}

	system("pause");
	closegraph();
	return 0;
}
void duichen(double yt[][3])
{
	cleardevice();
	line(x, 0, x, 480);
	line(0, y, 640, y);
	double c[6][3];
	for (int i = 0; i < 4; i++)
	{
		myline(yt[i][0] , yt[i][1] , yt[i + 1][0] , yt[i + 1][1] );
	}
	double js[3][3] = {
		0,-1,0,
		-1,0,0,
		0,0,1
	};
	chengfa(yt,js,c,6);
	for (int i = 0; i < 4; i++)
	{
		myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
	}
}
void xuanzuan(double yt[][3])
{
	cleardevice();
	line(x, 0, x, 480);
	line(0, y, 640, y);
	double c[6][3];
	for (int i = 0; i < 4; i++)
	{
		myline(yt[i][0] , yt[i][1] , yt[i + 1][0] , yt[i + 1][1] );
	}
	double i = 75.0 / 180;
	double js[3][3] = {
		cos(i*3.14),sin(i*3.14),0,
		-sin(i*3.14),cos(i*3.14),0,
		0,0,1
	};
	chengfa(yt, js, c, 6);
	for (int i = 0; i < 4; i++)
	{
		myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
	}
}
void pingyi(double yt[][3])
{
	cleardevice();
	line(x, 0, x, 480);
	line(0, y, 640, y);
	double c[6][3];
	for (int i = 0; i < 4; i++)
	{
		myline(yt[i][0] , yt[i][1] , yt[i + 1][0] , yt[i + 1][1] );
	}
	double js[3][3] = {
		1,0,0,
		0,1,0,
		52,60,1
	};
	chengfa(yt, js, c, 6);
	for (int i = 0; i < 4; i++)
	{
		myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
	}
}
void fangsuo(double yt[][3])
{
	cleardevice();
	line(x, 0, x, 480);
	line(0, y, 640, y);
	double c[6][3];
	int m;
	for (int i = 0; i < 4; i++)
	{
		myline(yt[i][0] , yt[i][1] , yt[i + 1][0] , yt[i + 1][1] );
	}
	cout << "请选择（1.放大两倍，2.缩小1/2）"<< endl;
	cin >> m;
	if (m == 1)
	{
		double js[3][3] = {
			2,0,0,
			0,2,0,
			0,0,1
		};
		chengfa(yt, js, c, 6);
		for (int i = 0; i < 4; i++)
		{
			myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
		}
	}
	else
	{
		double js[3][3] = {
			1.0/2,0,0,
			0,1.0/2,0,
			0,0,1
		};
		chengfa(yt, js, c, 6);
		for (int i = 0; i < 4; i++)
		{
			myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
		}
	}
}
void cuoqie(double yt[][3])
{
	cleardevice();
	line(x, 0, x, 480);
	line(0, y, 640, y);
	double c[6][3];
	for (int i = 0; i < 4; i++)
	{
		myline(yt[i][0] , yt[i][1] , yt[i + 1][0] , yt[i + 1][1] );
	}
	double i = 15.0 / 360;
	double js[3][3] = {
		1,0,0,
		tan(i * 3.14),1,0,
		0,0,1
	};
	chengfa(yt, js, c, 5);
	for (int i = 0; i < 4; i++)
	{
		myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
	}
}
void six(double yt[][3])
{
	cleardevice();
	line(x, 0, x, 480);
	line(0, y, 640, y);
	double c1[5][3];
	double c2[5][3];
	double c[5][3];
	for (int i = 0; i < 4; i++)
	{
		myline(yt[i][0] , yt[i][1] , yt[i + 1][0] , yt[i + 1][1] );
	}
	double js[3][3] = {
		1,0,0,
		0,1,0,
		-10,-15,1
	};
	chengfa(yt, js, c1, 5);
	double i = 90.0 / 180;
	double js1[3][3] = {
		cos(i * 3.14),sin(i * 3.14),0,
		-sin(i * 3.14),cos(i * 3.14),0,
		0,0,1
	};
	chengfa(c1, js1, c2, 5);
	double js2[3][3] = {
		1,0,0,
		0,1,0,
		10,15,1
	};
	chengfa(c2, js2, c, 5);
	for (int i = 0; i < 4; i++)
	{
		myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
	}
}
void seven(double yt[][3])
{
	cleardevice();
	line(x, 0, x, 480);
	line(0, y, 640, y);
	double c[6][3];
	double c1[6][3];
	double c2[6][3];
	double c3[6][3];
	for (int i = 0; i < 4; i++)
	{
		myline(yt[i][0] , yt[i][1] , yt[i + 1][0] , yt[i + 1][1] );
	}
	double js[3][3] = {
		1,0,0,
		0,1,0,
		0,-30,1
	};
	chengfa(yt, js, c1, 6);
	double i = atan(1.0/15);
	double js1[3][3] = {
		cos(i),sin(i),0,
		-sin(i),cos(i),0,
		0,0,1
	};
	chengfa(c1, js1, c2, 6);
	double js2[3][3] = {
		-1,0,0,
		0,1,0,
		0,0,1
	};
	chengfa(c2, js2, c3, 6);
	
	double js3[3][3] = {
		cos(-i),sin(-i),0,
		-sin(-i),cos(-i),0,
		0,0,1
	};
	chengfa(c3, js3, c, 6);

	double js4[3][3] = {
		1,0,0,
		0,1,0,
		0,30,1
	};
	chengfa(c, js4, c, 6);
	for (int i = 0; i < 4; i++)
	{
		myline(c[i][0] , c[i][1] , c[i + 1][0] , c[i + 1][1] );
	}
}
void myline(double x1, double y1, double x2, double y2)
{
	line(x + x1, y - y1, x + x2, y - y2);
	//cout << x1 << y1 << x2 << y2 << endl;
}
void chengfa(double yt[][3], double js[3][3],double c[][3],int n)
{
	int i, j;
	double sum;
	for(i=0;i<n;i++)
	{
		
		for (j = 0; j < 3; j++) 
		{
			sum = 0;
			for (int k = 0; k < 3; k++)
			{
				sum = sum + yt[i][k] * js[k][j];
			}
			c[i][j] = sum;
		}
	}
}