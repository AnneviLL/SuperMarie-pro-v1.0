#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>

int main()
{
	IMAGE img(640, 480);
	SetWorkingImage(&img);

	initgraph(640, 480);   // ������ͼ���ڣ���СΪ 640x480 ����
	loadimage(NULL, _T("C:\\Ccccc\\��������\\�زĿ�\\test.jpg"));

	setlinecolor(RED);
	circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100
	SetWorkingImage();

	_getch();              // �����������
	closegraph();          // �رջ�ͼ����
}