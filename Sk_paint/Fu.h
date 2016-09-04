#include"graphics.h"
#include<math.h>
#include<time.h>
#define True 1
#define False 0
#define LEFT  2
#define RIGHT 3
#define DOWN  4
#define UP  5

typedef struct{
	int x;
	int y;
}poinT;
typedef struct{
	poinT roll;
	double semi;
	int color_cir;
	int fill_cir_color;
	int Cirwidth;
}cirT;
typedef struct{
	int dot[50];
	int numpoints;
	int pol_color;
	int fill_pol_color;
	int pol_width;
}polyT;
typedef struct{
	poinT rect_dot[2];
	int color_rec;
	int fill_rec_color;
	int Recwidth;
}recT;
typedef struct{
	poinT line_dot[2];
	int color_line;
	int Linewidth;
}lineT;
typedef struct node{
	cirT circ;
	polyT pol;
	lineT  lin;
	recT rec;
	struct node*next;
	}SHAPE;
//以下tool中函数声明
SHAPE * creatlist();
int menu(FILE*fin);
void readfile(int k,FILE*fin);
void Paint_menu(SHAPE*);
void arrow(int x,int y,int,PIMAGE MENU);
void non_arrow(int x,int y,int direcT,PIMAGE MENU);
bool color_of_mousefont(int left, int top,  int right,int bottom,int MSG_X, int MSG_Y,LPCSTR text,PIMAGE MENU);
void color_of_keyfont(int left, int top,LPCSTR text,color_t color,int size);
PIMAGE non_menu();
void dis_menu(PIMAGE MENU_5);
//以下宽度
void non_SK_WIDTH();
void SK_WIDTH();
//以下保存文件函数
void writeToFile(SHAPE*);
void readFromFile(FILE*fin);
//以下color
void Color();
void barcol(color_t color,int x1,int y1,int size);
color_t check(color_t color[],int num);
void Color_deep();
void non_color();
//以下PAINT中声明
void PAINT_CIRCLE(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shapeT_cir,SHAPE * shapeT_check);
void PAINT_LINE(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shape,SHAPE * shapeT_check);
void PAINT_REC(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shapeT_rec,SHAPE * shapeT_check);
void PAINT_POL(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shapeT_pol,SHAPE * shapeT_check,PIMAGE MENU_CK);
void poly2();