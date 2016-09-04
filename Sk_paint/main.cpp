#include"Fu.h"

void main(){

	SHAPE *shapeT;//初始化类型结构体;(shapeT->pol+1)->dot
	shapeT=(SHAPE*)malloc(sizeof(SHAPE));
	int x=0,y=0,i;
	FILE*fin;
	fin=fopen("data.txt","r");
	initgraph(1200,800);
	setinitmode(INIT_DEFAULT );//全屏可写,getwidth(),geiheight()
	setcaption("S.k_paint");
	setcolor(BLACK);
	setbkcolor(WHITE);
	setfont(20,0,"楷体");
	for(;is_run();delay_fps(60)){
	i=menu(fin);
	readfile(i,fin);
	Paint_menu(shapeT);//这里的shapeT仍是shapeT的首地址
	//如果选择一级菜单的返回则跳出循环
	}
	closegraph();
	free(shapeT);
	fclose(fin);
}