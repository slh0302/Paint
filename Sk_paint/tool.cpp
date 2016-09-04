#include"Fu.h"
int menu(FILE*fin)
{
	int x1=1,y1=0,k;
	xyprintf(x1,y1,"欢迎使用S.k画板！");
	xyprintf(x1,y1+20,"是否读取上次保存文件:");
	xyprintf(x1,y1+40,"输入1为是，输入0为否？");
	k=getInteger("请输入1或者0做出选择");
	while(k != True && k != False)
	{
		xyprintf(x1,y1+60,"输入的数字非1与0，错误，未操作！请重输");
		k=getInteger("请重新输入！");
	}
	if(k==True){
		if(fin==NULL) return 2;
		else return 1; 
	}
	return 0;
}
void readfile(int k,FILE*fin)
{
	if(k==True)
	{
		delay_ms(100);
		readFromFile(fin);
	}
	else if(k==False)
	{ 
		cleardevice();
		delay_ms(100);
	}	
	else if(k==2){
		xyprintf(0,60,"文件不存在，错误，未操作！任意键继续，并将直接进入画板界面！！！！！");
		getch();//修改了文件不存在的操作
		delay_ms(200);
	}
}
void Paint_menu(SHAPE* shapeT)
{
	SHAPE* shapeT_1,*shapeT_M;//*shapeT_M为中间变量
	//以下文件定义
	//FILE*fout;
	int m_File=0;
	int x=0,y=0,KEY_x=0,KEY_y=1,CONST_X=0;//设置箭头在行之前的转换坐标常量等
	mouse_msg msg={0};
	//menu
	int i=0,fillcolor=0;
	int RIGHT_LEFT=4,DISPLAY=0,DISPLAY_MENU=1,DISPLAY_WIDTH=0;//定义箭头能指到的最大范围以及是否显示
	//防止直接重画
	shapeT->next=NULL;
	shapeT_1=(SHAPE*)malloc(sizeof(SHAPE));
	shapeT_M=(SHAPE*)malloc(sizeof(SHAPE));
	shapeT_M=shapeT_1=shapeT;
	//DISPLAY_MENU ==1时有键盘操作
	PIMAGE menu_color,menu_1,menu_2=newimage(1100,100);
	menu_color=newimage(100,50);
	menu_1=newimage(1100,100);
	setbkcolor(WHITE,menu_1);
	setcolor(BLACK,menu_1);
	setfont(20,0,"楷体",menu_1);
	outtextxy(0,0,"欢迎您进入S.k画图界面------(点此处隐藏菜单栏右键恢复)",menu_1);
	outtextxy(x,y+20,"1.选择图案",menu_1);
	outtextxy(550,38,"tips：方向键选择，鼠标点击作图,*多边形为lab7字符多边形",menu_1);
	outtextxy(x+121,y+20,"选择颜色",menu_1);
	outtextxy(x+221,y+20,"选择宽度",menu_1);
	outtextxy(x+321,y+20,"保存读取",menu_1);
	setlinewidth(5,menu_1);
	setcolor(BLACK,menu_1);
	line(0,97,1100,97,menu_1);
	line(1098,0,1098,100,menu_1);
	putimage(0,0,menu_1);
	for(;is_run();delay_fps(60))
	{
		//以下一些初始化
		while(mousemsg()){
			msg=getmouse();
		}
		flushkey();
		//以下键盘处理	
		//菜单栏的处理
		if(DISPLAY_MENU && color_of_mousefont( 270,0,530,20,msg.x,msg.y,"(点此处隐藏菜单栏右键恢复) ",menu_1)){
			setfont(20,0,"楷体",0,0,900,0,0,0,menu_1);
			outtextxy(270,0,"(点此处隐藏菜单栏右键恢复) ",menu_1);
			putimage(0,0,menu_1);//少1
		}
		//菜单栏影藏左键，右键显示
		if(DISPLAY_MENU && msg.x>=270&&msg.x<=500&&msg.y<=20&&msg.is_down()&&msg.is_left()){
			DISPLAY_MENU=0;
			menu_2=non_menu();
		}
		if(DISPLAY_MENU==0&& msg.is_down()&&msg.is_right()){
			DISPLAY_MENU=1;
			dis_menu(menu_2);
		}
		//出现箭头响应
		if(DISPLAY_MENU &&KEY_x==0&&(keystate(VK_LEFT)||keystate(VK_RIGHT))){
			KEY_x++;
			while(keystate(VK_LEFT)||keystate(VK_RIGHT)){
				arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
				putimage(0,0,menu_1);
				flushkey();
			}
		}
		if(DISPLAY_MENU &&KEY_x>0 &&KEY_x<RIGHT_LEFT&& keystate(VK_RIGHT)){
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_x++;
			while(keystate(VK_RIGHT)){
				arrow(KEY_x*100,KEY_y*20,RIGHT,menu_1);
				putimage(0,0,menu_1);
				flushkey();
			}
		}
		if(DISPLAY_MENU &&KEY_x>0 && keystate(VK_LEFT)){
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_x=KEY_x-1;
			while(keystate(VK_LEFT)){
				if(KEY_x==0) {
					putimage(0,0,menu_1);
					flushkey();
				}//如果不清除那么第一个if永远执行
				else {
					arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
					putimage(0,0,menu_1);
					flushkey();
				}
			}
		}	
		//以下一级菜单第一个部分
		if(DISPLAY_MENU &&(KEY_x==1) && KEY_y<3 &&keystate(VK_RETURN))//KEY_y确保只画两行
		{
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_y++;
			arrow(KEY_x*100,KEY_y*20,DOWN,menu_1);
			KEY_y++;
			CONST_X=KEY_x*100;//记录下箭头的位置
			while(keystate(VK_RETURN)){
				outtextxy(0,60,"2.画 线 ",menu_1);
				outtextxy(120,60,"画 圆",menu_1);
				outtextxy(220,60,"矩 形 ",menu_1);
				outtextxy(311,60," 多边形",menu_1);
				outtextxy(422,60,"*多边形",menu_1);
				RIGHT_LEFT=5;
				KEY_x=1;
				arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);//重新初始化	
				flushkey();
				putimage(0,0,menu_1);
			}
		}
		//二级菜单第一个的字体显示，看清当前在画什么
		if(DISPLAY_MENU &&KEY_y==3&&RIGHT_LEFT==5&&CONST_X==100){
			switch(KEY_x){
			case 1:	color_of_keyfont(0,KEY_y*20,"2.画 线",LIGHTBLUE,80);break;
			case 2:	color_of_keyfont(120,KEY_y*20,"画 圆",LIGHTBLUE,80);break;
			case 3:	color_of_keyfont(220,KEY_y*20,"矩 形",LIGHTBLUE,80);break;
			case 4:	color_of_keyfont(321,KEY_y*20,"多边形",LIGHTBLUE,80);break;
			case 5:	color_of_keyfont(422,KEY_y*20,"*多边形",LIGHTBLUE,80);break;
			}
		}
		//画线
		if(DISPLAY_MENU && CONST_X==100&&KEY_x==1 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN)){
			PAINT_LINE(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1);
			shapeT_1=shapeT_M;//所有的被赋值
			for(;shapeT->next !=NULL;shapeT=shapeT->next);
			flushkey();
		}
		//画圆
		if(DISPLAY_MENU&& CONST_X==100&&KEY_x==2 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN)){
			PAINT_CIRCLE(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1);
			shapeT_1=shapeT_M;//shapeT_1所有的被赋值,shapeT_M使得shapeT_1每次均为最开头到末尾
			for(;shapeT->next !=NULL;shapeT=shapeT->next);//回到链结末端
			//但参数shapeT_1仍是从开始弄;
			flushkey();
		}
		//画矩形
		if( DISPLAY_MENU&& CONST_X==100&&KEY_x==3 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN) ){
			PAINT_REC(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1);
			shapeT_1=shapeT_M;
			for(;shapeT->next !=NULL;shapeT=shapeT->next);//回到链结末端
			flushkey();
		}
		//画多边形
		if( DISPLAY_MENU&& CONST_X==100&&KEY_x==4 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN) ){
			PAINT_POL(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1,menu_1);
			shapeT_1=shapeT_M;
			for(;shapeT->next !=NULL;shapeT=shapeT->next);//回到链结末端
			flushkey();
		}
		if( DISPLAY_MENU&& CONST_X==100&&KEY_x==5 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN) ){
			poly2();//注意只是单独的功能
		}
		//清空二级菜单
		if(DISPLAY_MENU &&keystate(VK_UP)&&KEY_y>1)
		{
			outtextxy(0,KEY_y*20,"                                                                             ",menu_1);
			KEY_y--;
			non_arrow(CONST_X,KEY_y*20,UP,menu_1);
			KEY_y--;
			RIGHT_LEFT=4;//清空时返回一级菜单且长度变化
			KEY_x=1;
			flushkey();
			putimage(0,0,menu_1);
		}
		//以下一级菜单第二个部分
		if(DISPLAY_MENU &&(KEY_x==2) && KEY_y<3 &&keystate(VK_RETURN))
		{
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_y++;
			arrow(KEY_x*100,KEY_y*20,DOWN,menu_1);
			KEY_y++;
			CONST_X=KEY_x*100;
			while(keystate(VK_RETURN)){
				outtextxy(0,60,"2.显示颜色",menu_1);
				outtextxy(120,60,"换成深色",menu_1);
				outtextxy(220,60,"取消显示",menu_1);
				RIGHT_LEFT=3;
				KEY_x=1;
				arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);//重新初始化
				flushkey();
				putimage(0,0,menu_1);
			}
		}
		//二菜单第二个的字体显示，看清当前在干什么
		if(DISPLAY_MENU &&CONST_X==200&&KEY_y==3&&RIGHT_LEFT==3&&CONST_X==200){
			switch(KEY_x){
			case 1:	color_of_keyfont(0,KEY_y*20,"2.显示颜色",CYAN,100);break;
			case 2:	color_of_keyfont(120,KEY_y*20,"换成深色",CYAN,80);break;
			case 3:	color_of_keyfont(220,KEY_y*20,"取消显示",CYAN,80);break;
			}
		}
		//利用display改变判断条件退出
		if(DISPLAY_MENU &&CONST_X==200&&(DISPLAY=1)&&RIGHT_LEFT==3&&KEY_y==3&&KEY_x>=1 &&KEY_x<=2&&keystate(VK_RETURN))
		{
			if(KEY_x==1){
				outtextxy(0,60,"2.试试手气",menu_1);
				Color();
				fillcolor=1;
			}
			if(KEY_x==2){
				Color_deep();	
				fillcolor=1;
			}
		}
		//以下让颜色区消失
		if(DISPLAY_MENU&&CONST_X==200 &&DISPLAY==1&&RIGHT_LEFT==3&&KEY_y==3 &&KEY_x==3&&keystate(VK_RETURN)){
			DISPLAY=0;
			non_color();
			fillcolor=0;
		}
		if(fillcolor==1&&!(msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500)){
			setlinewidth(5,menu_color);
			setfillcolor(RGB(211,211,211),menu_color);
			bar(0,0,100,50,menu_color);
			setfont(18,0,"楷体",menu_color);
			setbkcolor(BLACK,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"填充or线条",menu_color);
			putimage(1100,500,menu_color);
		}
		if((fillcolor==1&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500) ){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,48,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"填充or线条",menu_color);
			putimage(1100,500,menu_color);
		}
		//以下一级第三个部分
		if(DISPLAY_WIDTH==0 &&DISPLAY_MENU &&(KEY_x==3) && KEY_y<3 &&keystate(VK_RETURN)){
			//DISPLAY_WIDTH=1;//使他显示
			outtextxy(x+221,y+20,"取消宽度",menu_1);
			putimage(0,0,menu_1);
			SK_WIDTH();
			DISPLAY_WIDTH=1;
			while(keystate(VK_RETURN)){
				flushkey();
			}
		}
		if( DISPLAY_MENU &&(KEY_x==3) && KEY_y<3 &&keystate(VK_RETURN)){
			if(DISPLAY_WIDTH==1){
				outtextxy(x+221,y+20,"选择宽度",menu_1);
				putimage(0,0,menu_1);
				non_SK_WIDTH();
				DISPLAY_WIDTH=0;
				while(keystate(VK_RETURN)){
					flushkey();
				}
			}
		}
		//以下一级第四个部分
		if(DISPLAY_MENU &&(KEY_x==4) && KEY_y<3 &&keystate(VK_RETURN))
		{
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_y++;
			arrow(KEY_x*100,KEY_y*20,DOWN,menu_1);
			KEY_y++;
			CONST_X=KEY_x*100;//记录下箭头的位置
			while(keystate(VK_RETURN)){
				outtextxy(0,60,"2.保存文件",menu_1);
				outtextxy(120,60,"重新显示",menu_1);
				outtextxy(220,60,"清空缓存",menu_1);
				outtextxy(321,60,"按y键快捷保存，按n键清屏,重新显示恢复为清屏前",menu_1);
				RIGHT_LEFT=3;
				KEY_x=1;
				arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);//重新初始化	
				flushkey();
				putimage(0,0,menu_1);
			}
		}
		//二级菜单第四个的字体显示，看清当前在干什么
		if(DISPLAY_MENU &&KEY_y==3&&RIGHT_LEFT==3&&CONST_X==400){
			switch(KEY_x){
			case 1:	color_of_keyfont(0,KEY_y*20,"2.保存文件",LIGHTRED,100);break;
			case 2:	color_of_keyfont(120,KEY_y*20,"重新显示",LIGHTRED,80);break;
			case 3:	color_of_keyfont(220,KEY_y*20,"清空缓存",LIGHTRED,80);break;
			}
		}
		//第四个二级菜单的第1个的功能实现,
		/*注释：
		按照链表顺序储存
		*/
		if(DISPLAY_MENU && CONST_X==400 &&KEY_x==1 && KEY_y==3 &&keystate(VK_RETURN)){
			writeToFile(shapeT_1);
			while(keystate(VK_RETURN)){
				flushkey();
			}
		}
		//第四个二级菜单的第4个的功能实现：Y和N键
		if(keystate('N')||keystate('n')){
			if(DISPLAY_WIDTH|| DISPLAY) {
				setviewport(0,0,1100,800);
				setfillcolor(WHITE);
				clearviewport();
				outtextxy(x+221,y+20,"选择宽度",menu_1);
				fillcolor=0;
				setviewport(0,0,1200,800);
			}
			else cleardevice();
			putimage(0,0,menu_1);
		}
		if(keystate('Y')||keystate('y')){
			writeToFile(shapeT_1);
		}
		//第四个二级菜单的第3个的功能实现
		if(DISPLAY_MENU && CONST_X==400 &&KEY_x==3 && KEY_y==3 &&keystate(VK_RETURN)){
			shapeT=creatlist();
			shapeT->next=NULL;
			shapeT_1=shapeT_M=shapeT;
			while(keystate(VK_RETURN)){
				flushkey();//不加不行？
			}
		}
		//第四个二级菜单的第2个的功能实现
		if(DISPLAY_MENU && CONST_X==400 &&KEY_x==2 && KEY_y==3 &&RIGHT_LEFT==3&&keystate(VK_RETURN)){	
			for(;shapeT_1->next !=NULL;shapeT_1=shapeT_1->next){
				if(shapeT_1->circ.roll.x > 0&& shapeT_1->circ.roll.y>0){
					if(shapeT_1->circ.Cirwidth>=0)  setlinewidth((float)shapeT_1->circ.Cirwidth);
					if(shapeT_1->circ.color_cir>=0) setcolor(shapeT_1->circ.color_cir);
						if(shapeT_1->circ.fill_cir_color>=0) {
							setfillcolor(shapeT_1->circ.fill_cir_color);
							fillellipse(shapeT_1->circ.roll.x,shapeT_1->circ.roll.y,(int)shapeT_1->circ.semi,(int)shapeT_1->circ.semi);
							}
						else circle(shapeT_1->circ.roll.x,shapeT_1->circ.roll.y,(int)shapeT_1->circ.semi);
					setlinewidth(1);//检测有无输入颜色和线宽
					setcolor(0);
				}
				if(shapeT_1->lin.line_dot[0].x>0&&shapeT_1->lin.line_dot[0].y>0) {
					if(shapeT_1->lin.Linewidth>=0) setlinewidth((float)shapeT_1->lin.Linewidth);
					if(shapeT_1->lin.color_line>=0) 	setcolor(shapeT_1->lin.color_line);
					line(shapeT_1->lin.line_dot[0].x,shapeT_1->lin.line_dot[0].y,shapeT_1->lin.line_dot[1].x,shapeT_1->lin.line_dot[1].y);
					setlinewidth(1);
					setcolor(0);
				}
				if(shapeT_1->pol.numpoints>0){
					if(shapeT_1->pol.pol_width>=0) setlinewidth((float)shapeT_1->pol.pol_width);
					if(shapeT_1->pol.pol_color>=0) 	setcolor(shapeT_1->pol.pol_color);
					if(shapeT_1->pol.fill_pol_color>=0)  setfillcolor(shapeT_1->pol.fill_pol_color);
					fillpoly(shapeT_1->pol.numpoints,shapeT_1->pol.dot);
					setlinewidth(1);
					setcolor(0);
					}
				}
				if(shapeT_1->rec.rect_dot[0].x>0&&shapeT_1->rec.rect_dot[0].y>0){
					if(shapeT_1->rec.Recwidth>=0) setlinewidth((float)shapeT_1->rec.Recwidth);
					if(shapeT_1->rec.color_rec>=0) setcolor(shapeT_1->rec.color_rec);
					if(shapeT_1->rec.fill_rec_color>=0) {
					setfillcolor(shapeT_1->rec.fill_rec_color);
					bar3d(shapeT_1->rec.rect_dot[0].x,shapeT_1->rec.rect_dot[0].y,shapeT_1->rec.rect_dot[1].x,shapeT_1->rec.rect_dot[1].y
						,0,false);
					}
				else rectangle(shapeT_1->rec.rect_dot[0].x,shapeT_1->rec.rect_dot[0].y,shapeT_1->rec.rect_dot[1].x,shapeT_1->rec.rect_dot[1].y);
				setlinewidth(1);
				setcolor(0);				
				setfillcolor(TRANSPARENT);
				}
			shapeT_1=shapeT_M;//回到链表的头
		}
	}
	delimage(menu_1);
	delimage(menu_2);
	free(shapeT_1);
	free(shapeT_M);
}
//产生箭头
void arrow(int x,int y,int direcT,PIMAGE MENU)
{
	if(direcT==LEFT) outtextxy(x,y,"←",MENU);
	if(direcT==RIGHT) outtextxy(x,y,"←",MENU);
	if(direcT == DOWN) outtextxy(x,y,"↓",MENU);
}
//清除箭头
void non_arrow(int x,int y,int direcT,PIMAGE MENU)
{
	if(direcT==LEFT||direcT==RIGHT) outtextxy(x,y,"　",MENU);
	if(direcT==UP) outtextxy(x,y,"　",MENU);
}
//以下显示选色区和粗细选择区
void Color()
{
	barcol(BLACK,1100,450,50);
	int i=0;
	color_t checkcolor[20]={0};
	randomize();
	for(;i<9;i++)//正好少四个
	{
		setfillcolor(hsl2rgb(float(randomf() * 360), 1.0f, 0.5f));//
		checkcolor[i]=getfillcolor();
		setfillcolor( check(checkcolor,i) );//查找相同颜色
		bar(1100,i*50,1200,50+i*50);//两个y之间相差50！！！！
	}
}
//纯颜色矩形
void barcol(color_t color,int x1,int y1,int size)
{
	setfillcolor(color);
	bar(x1,y1,x1+100,y1+size);
}
//检查颜色的重复性！
color_t check(color_t color[],int num)
{
	int i;
	randomize();
	if(num==0) 
	{
		return color[num];
	}
	for(i=0;i<num;i++)
	{
		while(color[i]==color[num])
		{
			color[num]/=random(20)+1;
		}
	}
	return color[num];
}
//以下深颜色
void Color_deep()
{
	int i=0;
	color_t checkcolor[20]={0};
	randomize();
	for(;i<10;i++)
	{
		setfillcolor(EGERGB(random(255) ,random(255) ,random(255)));//
		checkcolor[i]=getfillcolor();
		setfillcolor( check(checkcolor,i) );//查找相同颜色
		bar(1100,i*50,1200,50+i*50);
	}
}
//消除颜色
void non_color(){
	PIMAGE MENU_2;
	MENU_2=newimage(100,550);
	setbkcolor(WHITE,MENU_2);
	getimage(MENU_2,1100,0,1200,550);
	setviewport(1100,0,1200,550);
	setfillcolor(WHITE);
	clearviewport();
	for ( int alpha=0xFF,da=1;is_run(); delay_ms(1) )
	{
		alpha -= da;
		clearviewport();
		if(alpha<=0) break;
		putimage_alphatransparent(NULL, MENU_2, 1100, 0, BLACK, (unsigned char)alpha);
	}
	setviewport(0,0,1200,800);
	delimage(MENU_2);
}
//消除菜单
PIMAGE non_menu(){
	PIMAGE MENU_4,MENU_T=newimage(1100,100);
	MENU_4=newimage(1100,100);
	setbkcolor(WHITE,MENU_4);
	getimage(MENU_4,0,0,1100,100);
	MENU_T=MENU_4;
	setviewport(0,0,1100,100);
	setfillcolor(WHITE);
	clearviewport();
	for ( int alpha=0xFF,da=1;is_run(); delay_ms(1) )
	{
		alpha -= da;
		clearviewport();
		if(alpha<=0) break;
		putimage_alphatransparent(NULL, MENU_4, 0, 0, BLACK, (unsigned char)alpha);
	}
	setviewport(0,0,1200,800);
	return MENU_T;
	delimage(MENU_4);
	delimage(MENU_T);
}
void dis_menu(PIMAGE MENU_5){
	setviewport(0,0,1100,100);
	clearviewport();
	for ( int alpha=0,da=1;is_run(); delay_ms(1) )
	{
		alpha += da;
		clearviewport();
		if(alpha>=0xFF) break;
		putimage_alphatransparent(NULL, MENU_5, 0, 0, BLACK, (unsigned char)alpha);
	}
	putimage(0,0,MENU_5);//不写这里会突然停一下
	setviewport(0,0,1200,800);
}
//鼠标响应,键盘响应
bool color_of_mousefont(int left, int top, int right,int bottom,int MSG_X, int MSG_Y,LPCSTR text,PIMAGE	MENU)
{
	if(MSG_X>=left&&MSG_X<=right&&MSG_Y<=bottom&&MSG_Y>=top){return true;}
	else{
		setfont(20,0,"楷体",MENU);
		outtextxy(left,top,text,MENU);
		putimage(0,0,MENU);
		return false;
	}
}
void color_of_keyfont(int left, int top,LPCSTR text,color_t color,int size)
{
	PIMAGE MENU_3;//为了颜色不变
	MENU_3=newimage(size,20);
	setbkcolor(WHITE,MENU_3);
	setcolor(color,MENU_3);//这里有颜色改变
	setfont(20,0,"楷体",0,0,0,0,1,0,MENU_3);
	outtextxy(0,0,text,MENU_3);
	putimage(left,top,MENU_3);
	delimage(MENU_3);
}
//内存分配
SHAPE * creatlist()
	//如果单击画图则创建一个SHAPE
{
	SHAPE *h;
	h=(SHAPE*)malloc(sizeof(SHAPE));
	return h;
}
//读取文件
void writeToFile(SHAPE*shapeT_F){
	FILE*fout;
	SHAPE*shapeT_files;
	shapeT_files=(SHAPE*)malloc(sizeof(SHAPE));
	shapeT_files=shapeT_F;
	fout=fopen("data.txt","w");//未加入光标开始处
	fprintf(fout,"%s\n","请按照图形英文的首三个字母+空格+坐标+(半径+线宽(>=0)+线颜色(0到16777215)+填充色)的方式修改,不输入线宽颜色，即默认黑色，最细");
	for(;shapeT_files->next !=NULL;shapeT_files=shapeT_files->next){
		if(shapeT_files->circ.semi>0){
			fprintf(fout,"%s %d %d %.2f %d %d %d\n","cir",
				shapeT_files->circ.roll.x,shapeT_files->circ.roll.y,shapeT_files->circ.semi,
				shapeT_files->circ.Cirwidth,shapeT_files->circ.color_cir,shapeT_files->circ.fill_cir_color);
		}
		if(shapeT_files->pol.numpoints>0){
			fprintf(fout,"%s %d ","pol",shapeT_files->pol.numpoints);
			for(int poly_dot=0;shapeT_files->pol.dot[poly_dot]>0;poly_dot++){
				fprintf(fout,"%d ",shapeT_files->pol.dot[poly_dot]);
			}
			fprintf(fout,"%d %d %d",shapeT_files->pol.pol_width,shapeT_files->pol.pol_color,shapeT_files->pol.fill_pol_color);
			fprintf(fout,"\n");
		}
		if(shapeT_files->lin.line_dot[0].x>0){//坐标+粗细+线条颜色
			fprintf(fout,"%s %d %d %d %d %d %d\n","lin",
				shapeT_files->lin.line_dot[0].x,shapeT_files->lin.line_dot[0].y,shapeT_files->lin.line_dot[1].x,shapeT_files->lin.line_dot[1].y,
				shapeT_files->lin.Linewidth,shapeT_files->lin.color_line);
		}
		if(shapeT_files->rec.rect_dot[0].x>0){
			fprintf(fout,"%s %d %d %d %d %d %d %d\n","rec",
				shapeT_files->rec.rect_dot[0].x,shapeT_files->rec.rect_dot[0].y,shapeT_files->rec.rect_dot[1].x,shapeT_files->rec.rect_dot[1].y,
				shapeT_files->rec.Recwidth,shapeT_files->rec.color_rec,shapeT_files->rec.fill_rec_color);
		}
	}
	fclose(fout);//用了后要马上关闭
}
void readFromFile(FILE*fin){
	char name[4];
	int a[10];//暂存数据
	float b;
	int poly_num,POLY_DATA[50];
	for(;fscanf(fin,"%3s[a-z]",name) != EOF;){
		if( ! ( strcmp(name,"cir") ) ){
			fscanf(fin,"%d %d %f %d %d %d\n",&a[0],&a[1],&b,&a[2],&a[3],&a[4]);
			if(a[2]>=0) setlinewidth((float)a[2]);
			if(a[3]>=0) setcolor(a[3]);
			if(a[4]>=0) {
				setfillcolor(a[4]);
				fillellipse(a[0],a[1],(int)b,(int)b);
			}
			else circle(a[0],a[1],(int)b);
			setlinewidth(1);//检测有无输入颜色和线宽
			setcolor(0);
			setfillcolor(TRANSPARENT);
		}
		if( ! ( strcmp(name,"lin") ) ){
			fscanf(fin,"%d %d %d %d %d %d\n",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
			if(a[4]>=0) setlinewidth((float)a[4]);
			if(a[5]>=0) 	setcolor(a[5]);
			line(a[0],a[1],a[2],a[3]);
			setlinewidth(1);//这里要修改
			setcolor(0);
		}
		if( ! ( strcmp(name,"pol") )){
			fscanf(fin,"%d ",&poly_num);
			for(int poly_dot=0;poly_dot<2*poly_num;poly_dot++){
				fscanf(fin,"%d ",&POLY_DATA[poly_dot]);
			}
			fscanf(fin,"%d %d %d\n",&a[0],&a[1],&a[2]);
			if(a[0]>=0) setlinewidth((float)a[0]);
			if(a[1]>=0) 	setcolor(a[1]);
			if(a[2]>=0)  setfillcolor(a[2]);
			fillpoly(poly_num,POLY_DATA);
			setlinewidth(1);
			setcolor(0);
			setfillcolor(TRANSPARENT);
		}
		if( ! ( strcmp(name,"rec") )){
			fscanf(fin,"%d %d %d %d %d %d %d\n",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
			if(a[4]>=0) setlinewidth((float)a[4]);
			if(a[5]>=0) setcolor(a[5]);
			if(a[6]>=0) {
				setfillcolor(a[6]);
				bar3d(a[0],a[1],a[2],a[3],0,false);
			}
			else rectangle(a[0],a[1],a[2],a[3]);
			setlinewidth(1);//这里要修改
			setcolor(0);
			setfillcolor(TRANSPARENT);
		}
	}	
}
//宽粗细选择
void non_SK_WIDTH(){
	PIMAGE MENU_W;
	MENU_W=newimage(100,250);
	setbkcolor(WHITE,MENU_W);
	getimage(MENU_W,1100,550,1200,800);
	setviewport(1100,550,1200,800);
	setfillcolor(WHITE);
	clearviewport();
	for ( int alpha=0xFF,da=1;is_run(); delay_ms(1) )
	{
		alpha -= da;
		clearviewport();
		if(alpha<=0) break;
		putimage_alphatransparent(NULL, MENU_W, 1100, 550, BLACK, (unsigned char)alpha);
	}
	setviewport(0,0,1200,800);
	delimage(MENU_W);
}
void SK_WIDTH(){
	setfont(18,0,"楷体");
	xyprintf(1100,610,"颜色粗细=");
	outtextxy(1100,590,"点击减少");
	outtextxy(1100,570,"点击增加");
	outtextxy(1100,552,"自己选择");
	xyprintf(1100,630,"非画图无效");
	xyprintf(1100,650,"下图为示例");
	for(int i=1;i<4;i++){
		barcol(BLACK,1100,680+40*(i-1),8*i);
	}//暂时没效果
}/**/
