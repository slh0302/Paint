#include"Fu.h"

void main(){

	SHAPE *shapeT;//��ʼ�����ͽṹ��;(shapeT->pol+1)->dot
	shapeT=(SHAPE*)malloc(sizeof(SHAPE));
	int x=0,y=0,i;
	FILE*fin;
	fin=fopen("data.txt","r");
	initgraph(1200,800);
	setinitmode(INIT_DEFAULT );//ȫ����д,getwidth(),geiheight()
	setcaption("S.k_paint");
	setcolor(BLACK);
	setbkcolor(WHITE);
	setfont(20,0,"����");
	for(;is_run();delay_fps(60)){
	i=menu(fin);
	readfile(i,fin);
	Paint_menu(shapeT);//�����shapeT����shapeT���׵�ַ
	//���ѡ��һ���˵��ķ���������ѭ��
	}
	closegraph();
	free(shapeT);
	fclose(fin);
}