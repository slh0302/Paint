#include"Fu.h"
int RAM_COUNT=0;//RAM_COUNT���ڼ��㻭�ߵĴ����Է����ڴ�
int wi=1;//������

//ֱ��
void PAINT_LINE(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shapeT_line,SHAPE * shapeT_check){
	mouse_msg msg={0};
	int x1,y1,x2,y2,width1=0;
	int iswork;
	PIMAGE menu_2=newimage(1100,110);
	for(;shapeT_check->next!=NULL;shapeT_check=shapeT_check->next){
		if(shapeT_check->lin.line_dot[0].x>0);
		else{
			shapeT_line=shapeT_check;
			for(;shapeT_line->next != NULL;shapeT_line=shapeT_line->next){
				shapeT_line->lin.line_dot[0].x=0;//���ñ�־0ʹ�ô����¸������ý���
			}
			shapeT_line=shapeT_check;//�ٴ�����
			break;//��shapeT_1(������)�Ĳ�����ǰͼ���������ݵ����Ὺʼ
		}
	}
	for(;is_run();delay_fps(60)){
		while(mousemsg()){
			msg=getmouse();
		}
		//��ݼ�Y��N
		if(keystate('N')||keystate('n')){
			if(DISPLAY_WIDTH||msg_color) {
				setviewport(0,0,1100,800);
				setfillcolor(WHITE);
				clearviewport();
				setviewport(0,0,1200,800);
			}
			else cleardevice();
			putimage(0,0,menu_1);
		}
		if(keystate('Y')||keystate('y')){
			shapeT_line->next=NULL;
			writeToFile(shapeT_check);
		}
		//�˵���Ӱ��������Ҽ���ʾ
		if(msg_MENU && msg.x>=270&&msg.x<=500&&msg.y<=20&&msg.is_down()&&msg.is_left()){
			menu_2=non_menu();
			msg_MENU=0;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
			}
		}
		if(msg_MENU==0&& msg.is_down()&&msg.is_right()){
			dis_menu(menu_2);
			msg_MENU=1;
		}
		if(keystate(VK_DOWN)||keystate(VK_UP)||keystate(VK_LEFT)||keystate(VK_RIGHT)){
			shapeT_line->next=NULL;
			flushkey();
			break;
		}
		if(msg_MENU && color_of_mousefont( 270,0,530,20,msg.x,msg.y,"(��˴����ز˵����Ҽ��ָ�) ",menu_1)){
			setfont(20,0,"����",0,0,900,0,0,0,menu_1);
			outtextxy(270,0,"(��˴����ز˵����Ҽ��ָ�) ",menu_1);
			putimage(0,0,menu_1);//��1
		}
		//������ɫ
		if(msg_color&&msg.x<1200&&msg.x>1100&&msg.y>0&&msg.y<550 && msg.is_down()){
			msg=getmouse();
			setcolor(getpixel(msg.x,msg.y));
			while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
				}
		}
		//���¿��
		if(DISPLAY_WIDTH&&msg.x<1200&&msg.x>1100&&msg.y>570&&msg.y<610&&msg.is_down()){
			if(msg.y<590) {
				setlinewidth((float)(wi=wi+1));
				setcolor(getcolor());
				while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
				}
			}
			if(msg.y>590&&msg.y<610){
				if(wi==1){
					setlinewidth(1);
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				}
				else{
					setlinewidth((float)(wi=wi-1));
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				} 
			}
		}
		if(DISPLAY_WIDTH) xyprintf(1100,610,"��ɫ��ϸ=%d ",wi);
		while(DISPLAY_WIDTH&&msg.x>1100&&msg.x<1200&&msg.y>550&&msg.y<570&&msg.is_down()) {
			width1=getInteger("��������");
			setlinewidth((float)width1);
			setcolor(getcolor());
			wi=width1;
			setfont(18, 0, "����");
			while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
				}
		}
		//���»���
		if( (msg.is_down() && msg.is_left() &&msg.x<1100&&msg.y>80&&msg.y<800 ) ||( msg.is_down() &&msg.is_left() && (msg_MENU) == 0)){
			if(shapeT_line->lin.line_dot[0].x==0&&shapeT_line->next != NULL);
			else shapeT_line->next=creatlist();
			shapeT_line->lin.line_dot[0].x=x1=msg.x;
			shapeT_line->lin.line_dot[0].y=y1=msg.y;
			iswork=TRUE;
			while(iswork){
				mousepos(&x2,&y2);
				shapeT_line->lin.line_dot[1].x=x2;
				shapeT_line->lin.line_dot[1].y=y2;
				msg=getmouse();
				if(msg.is_up()) iswork=False;
			}
			line(x1,y1,x2,y2);
			shapeT_line->lin.color_line=getcolor();
			shapeT_line->lin.Linewidth=wi;
			RAM_COUNT++;
			if(RAM_COUNT != 0) shapeT_line=shapeT_line->next; //ĩβ��NULL
		}
	}	
}
//��Բ
void PAINT_CIRCLE(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shapeT_cir,SHAPE * shapeT_check){
	//SHAPE * shapeT_check����Ϊ����ⲿ��shapeT_1�����޵�ǰ�滭��ͼ������
	mouse_msg msg={0};
	PIMAGE menu_color,menu_2=newimage(1100,100);
	menu_color=newimage(100,50);
	int x1,y1,x2,y2,width1=0;//RAM_COUNT���ڼ��㻭�ߵĴ����Է����ڴ�
	double r;
	int iswork,FILL=0;
	setfillcolor(WHITE);
	for(;shapeT_check->next!=NULL;shapeT_check=shapeT_check->next){
		if(shapeT_check->circ.semi>0);
		else{
			shapeT_cir=shapeT_check;
			for(;shapeT_cir->next != NULL;shapeT_cir=shapeT_cir->next){	
				shapeT_cir->circ.semi=0;
			}
			shapeT_cir=shapeT_check;
			break;//��shapeT_1(������)�Ĳ�����ǰͼ���������ݵ����Ὺʼ
		}
	}
	for(;is_run();delay_fps(60)){
		while(mousemsg()){
			msg=getmouse();
		}
		//��ݼ�Y��N:Y���棬N����
		if(keystate('N')||keystate('n')){
			if(DISPLAY_WIDTH||msg_color) {
				setviewport(0,0,1100,800);
				setfillcolor(WHITE);
				clearviewport();
				setviewport(0,0,1200,800);
			}
			else cleardevice();
			putimage(0,0,menu_1);
		}
		if(keystate('Y')||keystate('y')){
			shapeT_cir->next=NULL;
			writeToFile(shapeT_check);
		}
		//�˵���Ӱ��������Ҽ���ʾ
		if(msg_MENU && msg.x>=270&&msg.x<=500&&msg.y<=20&&msg.is_down()&&msg.is_left()){
			msg_MENU=0;
			menu_2=non_menu();	
			while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
			}
		}
		if(msg_MENU==0&& msg.is_down()&&msg.is_right()){
			msg_MENU=1;
			dis_menu(menu_2);
		}
		if(keystate(VK_DOWN)||keystate(VK_UP)||keystate(VK_LEFT)||keystate(VK_RIGHT)){
			shapeT_cir->next=NULL;
			flushkey();
			break;
		}
		if(msg_MENU && color_of_mousefont( 270,0,530,20,msg.x,msg.y,"(��˴����ز˵����Ҽ��ָ�) ",menu_1)){
			setfont(20,0,"����",0,0,900,0,0,0,menu_1);
			outtextxy(270,0,"(��˴����ز˵����Ҽ��ָ�) ",menu_1);
			putimage(0,0,menu_1);
		}
		//����������ɫ
		if(FILL==2&&msg_color&&msg.x<1200&&msg.x>1100&&msg.y>0&&msg.y<500 && msg.is_down()){
			msg=getmouse();
			setcolor(getpixel(msg.x,msg.y));
		}
		//���������ɫ
		if(FILL==1&&msg_color&&msg.x<1200&&msg.x>1100&&msg.y>0&&msg.y<500 && msg.is_down()){
			msg=getmouse();
			setfillcolor(getpixel(msg.x,msg.y));
		}
		//��ɫ���
			if(msg_color&&FILL==0){
			setlinewidth(3,menu_color);
			setfillcolor(RGB(211,211,211),menu_color);
			setfont(18,0,"����",menu_color);
			bar(0,0,100,52,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		if(FILL==0&&msg_color&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		if(msg_color&&FILL==0&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���  ��ɫ",menu_color);
			putimage(1100,500,menu_color);
			FILL=1;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		if(msg_color&&FILL==1&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"����  ��ɫ",menu_color);
			putimage(1100,500,menu_color);
			FILL=2;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		if(msg_color&&FILL==2&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			FILL=0;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		//���¿��
		if(DISPLAY_WIDTH&&msg.x<1200&&msg.x>1100&&msg.y>570&&msg.y<610&&msg.is_down()){
			if(msg.y<590) {
				setlinewidth((float)(wi=wi+1));
				setcolor(getcolor());
				while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
				}
			}
			if(msg.y>590&&msg.y<610){
				if(wi==1){
					setlinewidth(1);
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				}
				else{
					setlinewidth((float)(wi=wi-1));
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				} 
			}
		}
		if(DISPLAY_WIDTH) xyprintf(1100,610,"��ɫ��ϸ=%d ",wi);
		while(DISPLAY_WIDTH&&msg.x>1100&&msg.x<1200&&msg.y>550&&msg.y<570&&msg.is_down()) {
			width1=getInteger("��������");
			setlinewidth((float)width1);
			setcolor(getcolor());
			wi=width1;
			setfont(18, 0, "����");
			while(msg.is_down()){
					msg.msg=mouse_msg_up;//��������
				}
		}
		//���»�Բ
		if((msg_MENU&&msg.is_down() && msg.is_left() &&msg.x<1100&&msg.y>100&&msg.y<800)||( msg.is_down() &&msg.is_left() && (msg_MENU) == 0) ){
			if(shapeT_cir->circ.semi==0&&shapeT_cir->next !=NULL);
			else shapeT_cir->next=creatlist();
			shapeT_cir->circ.roll.x=x1=msg.x;
			shapeT_cir->circ.roll.y=y1=msg.y;
			iswork=TRUE;
			while(iswork){
				mousepos(&x2,&y2);
				msg=getmouse();	
				if(msg.is_up()) iswork=False;
			}
			r=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
			shapeT_cir->circ.semi=r=sqrt(r);
			if(getfillcolor() == WHITE) {
				circle(x1,y1,(int)r);
				shapeT_cir->circ.fill_cir_color=-1;//��עΪ-1
			}
			else {
				fillellipse(x1,y1,(int)r,(int)r);
				shapeT_cir->circ.fill_cir_color=getfillcolor();
			}
			shapeT_cir->circ.color_cir=getcolor();
			shapeT_cir->circ.Cirwidth=wi;
			RAM_COUNT++;
			if(RAM_COUNT != 0) shapeT_cir=shapeT_cir->next; //ĩβ��NULL
		}
	}
}
//������
void PAINT_REC(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shapeT_rec,SHAPE * shapeT_check){
	mouse_msg msg={0};
	PIMAGE menu_color,menu_2=newimage(1100,100);
	menu_color=newimage(100,50);
	int x1,y1,x2,y2,width1=0;//RAM_COUNT���ڼ��㻭�ߵĴ����Է����ڴ�
	int iswork,FILL=0;
	setfillcolor(WHITE);
	for(;shapeT_check->next!=NULL;shapeT_check=shapeT_check->next){
		if(shapeT_check->rec.rect_dot[0].x> 0);
		else{
			shapeT_rec=shapeT_check;
			for(;shapeT_rec->next != NULL;shapeT_rec=shapeT_rec->next){	
				shapeT_rec->rec.rect_dot[0].x=0;
			}
			shapeT_rec=shapeT_check;
			break;//��shapeT_1(������)�Ĳ�����ǰͼ���������ݵ����Ὺʼ
		}
	}
	for(;is_run();delay_fps(60)){
		while(mousemsg()){
			msg=getmouse();
		}
		//��ݼ�Y��N:Y���棬N����
		if(keystate('N')||keystate('n')){
			if(DISPLAY_WIDTH||msg_color) {
				setviewport(0,0,1100,800);
				setfillcolor(WHITE);
				clearviewport();
				setviewport(0,0,1200,800);
			}
			else cleardevice();
			putimage(0,0,menu_1);
		}
		if(keystate('Y')||keystate('y')){
			shapeT_rec->next=NULL;
			writeToFile(shapeT_check);
		}
		//�˵���Ӱ��������Ҽ���ʾ
		if(msg_MENU && msg.x>=270&&msg.x<=500&&msg.y<=20&&msg.is_down()&&msg.is_left()){
			msg_MENU=0;
			menu_2=non_menu();	
			while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
			}
		}
		if(msg_MENU==0&& msg.is_down()&&msg.is_right()){
			msg_MENU=1;
			dis_menu(menu_2);
		}
		if(keystate(VK_DOWN)||keystate(VK_UP)||keystate(VK_LEFT)||keystate(VK_RIGHT)){
			shapeT_rec->next=NULL;
			flushkey();
			break;
		}
		if(msg_MENU && color_of_mousefont( 270,0,530,20,msg.x,msg.y,"(��˴����ز˵����Ҽ��ָ�) ",menu_1)){
			setfont(20,0,"����",0,0,900,0,0,0,menu_1);
			outtextxy(270,0,"(��˴����ز˵����Ҽ��ָ�) ",menu_1);
			putimage(0,0,menu_1);//��1
		}
		//������ɫ
		if(msg_color&&FILL==2&&msg.x<1200&&msg.x>1100&&msg.y>0&&msg.y<500 && msg.is_down()){
			msg=getmouse();
			setcolor(getpixel(msg.x,msg.y));
		}
		//���������ɫ
		if(FILL==1&&msg_color&&msg.x<1200&&msg.x>1100&&msg.y>0&&msg.y<500 && msg.is_down()){
			msg=getmouse();
			setfillstyle(SOLID_FILL,getpixel(msg.x,msg.y));
		}
		//��ɫ���
			if(msg_color&&FILL==0){
			setlinewidth(3,menu_color);
			setfillcolor(RGB(211,211,211),menu_color);
			setfont(18,0,"����",menu_color);
			bar(0,0,100,52,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		if(FILL==0&&msg_color&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		if(msg_color&&FILL==0&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
		setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���  ��ɫ",menu_color);
			putimage(1100,500,menu_color);
			FILL=1;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		if(msg_color&&FILL==1&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"����  ��ɫ",menu_color);
			putimage(1100,500,menu_color);
			FILL=2;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		if(msg_color&&FILL==2&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			FILL=0;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		//���¿��
		if(DISPLAY_WIDTH&&msg.x<1200&&msg.x>1100&&msg.y>570&&msg.y<610&&msg.is_down()){
			if(msg.y<590) {
				setlinewidth((float)(wi=wi+1));
				setcolor(getcolor());
				while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
				}
			}
			if(msg.y>590&&msg.y<610){
				if(wi==1){
					setlinewidth(1);
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				}
				else{
					setlinewidth((float)(wi=wi-1));
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				} 
			}
		}
		if(DISPLAY_WIDTH) xyprintf(1100,610,"��ɫ��ϸ=%d ",wi);
		while(DISPLAY_WIDTH&&msg.x>1100&&msg.x<1200&&msg.y>550&&msg.y<570&&msg.is_down()) {
			width1=getInteger("��������");
			setlinewidth((float)width1);
			setcolor(getcolor());
			wi=width1;
			setfont(18, 0, "����");
			while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
				}
		}
		//���»�����
		if((msg_MENU&&msg.is_down() && msg.is_left() &&msg.x<1100&&msg.y>80&&msg.y<800)||( msg.is_down() &&msg.is_left() && (msg_MENU) == 0) ){
			if(shapeT_rec->rec.rect_dot[0].x==0&&shapeT_rec->next !=NULL);
			else shapeT_rec->next=creatlist();
			shapeT_rec->rec.rect_dot[0].x=x1=msg.x;
			shapeT_rec->rec.rect_dot[0].y=y1=msg.y;
			iswork=TRUE;
			while(iswork){
				mousepos(&x2,&y2);
				msg=getmouse();
				shapeT_rec->rec.rect_dot[1].x=x2;
				shapeT_rec->rec.rect_dot[1].y=y2;
				if(msg.is_up()) iswork=False;
			}
			rectangle(x1,y1,x2,y2);
			if(getfillcolor() != WHITE){ 
				bar3d(x1,y1,x2,y2,0,false);
				shapeT_rec->rec.fill_rec_color=getfillcolor();
			}
			else{
				rectangle(x1,y1,x2,y2);
				shapeT_rec->rec.fill_rec_color=-1;
			}
			shapeT_rec->rec.color_rec=getcolor();
			shapeT_rec->rec.Recwidth=wi;
			RAM_COUNT++;
			if(RAM_COUNT != 0) shapeT_rec=shapeT_rec->next; //ĩβ��NULL
		}
	}
}
//�������
void PAINT_POL(int DISPLAY_WIDTH,int msg_MENU,int msg_color,PIMAGE menu_1,SHAPE* shapeT_pol,SHAPE * shapeT_check,PIMAGE MENU_CK){
	mouse_msg msg={0};
	PIMAGE MENU_POL;
	int x1,y1,x2,y2,width1=0; //RAM_COUNT���ڼ��㻭�ߵĴ����Է����ڴ�
	int iswork,FILL=0,NUM_POINTS=3,NUM=0;
	PIMAGE menu_color,menu_2=newimage(1100,100);
	menu_color=newimage(100,50);
	MENU_POL=newimage(300,20);
	setbkcolor(WHITE,MENU_POL);
	setbkmode(TRANSPARENT,MENU_POL);
	setcolor(BLACK,MENU_POL);
	setfillcolor(WHITE);
	setfont(20,0,"����",MENU_POL);
	outtextxy(0,0,"��ǰ����=   ���� ���� �Լ�����",MENU_POL);
	putimage(MENU_CK,560,0,MENU_POL);
	putimage(0,0,MENU_CK);
	for(;shapeT_check->next!=NULL;shapeT_check=shapeT_check->next){
		if(shapeT_check->pol.numpoints>0);
		else{
			shapeT_pol=shapeT_check;
			for(;shapeT_pol->next != NULL;shapeT_pol=shapeT_pol->next){	
				shapeT_pol->pol.numpoints=0;
			}
			shapeT_pol=shapeT_check;
			break;//��shapeT_1(������)�Ĳ�����ǰͼ���������ݵ����Ὺʼ
		}
	}
	for(;is_run();delay_fps(60)){
		while(mousemsg()){
			msg=getmouse();
		}
		//��ݼ�Y��N:Y���棬N����
		if(keystate('N')||keystate('n')){
			if(DISPLAY_WIDTH||msg_color) {
				setviewport(0,0,1100,800);
				setfillcolor(WHITE);
				clearviewport();
				setviewport(0,0,1200,800);
			}
			else cleardevice();
			putimage(0,0,menu_1);
		}
		if(keystate('Y')||keystate('y')){
			shapeT_pol->next=NULL;
			writeToFile(shapeT_check);
		}
		//�˵���Ӱ��������Ҽ���ʾ
		if(msg_MENU && msg.x>=270&&msg.x<=500&&msg.y<=20&&msg.is_down()&&msg.is_left()){
			msg_MENU=0;
			menu_2=non_menu();	
			while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
			}
		}
		if(msg_MENU==0&& msg.is_down()&&msg.is_right()){
			msg_MENU=1;
			dis_menu(menu_2);
		}
		if(keystate(VK_DOWN)||keystate(VK_UP)||keystate(VK_LEFT)||keystate(VK_RIGHT)){
			shapeT_pol->next=NULL;
			outtextxy(560,0,"                                         ",MENU_CK);
			putimage(0,0,MENU_CK);
			delimage(MENU_POL);
			flushkey();
			break;
		}
		if(msg_MENU && color_of_mousefont( 270,0,530,20,msg.x,msg.y,"(��˴����ز˵����Ҽ��ָ�) ",menu_1)){
			setfont(20,0,"����",0,0,900,0,0,0,menu_1);
			outtextxy(270,0,"(��˴����ز˵����Ҽ��ָ�) ",menu_1);
			putimage(0,0,menu_1);//��1
		}
		//������ɫ
		if(msg_color&&FILL==2&&msg.x<1200&&msg.x>1100&&msg.y>0&&msg.y<500 && msg.is_down()){
			msg=getmouse();
			setcolor(getpixel(msg.x,msg.y));
		}
		//���������ɫ
		if(FILL==1&&msg_color&&msg.x<1200&&msg.x>1100&&msg.y>0&&msg.y<500 && msg.is_down()){
			msg=getmouse();
			setfillcolor(getpixel(msg.x,msg.y));
		}
		//��ɫ���
			if(msg_color&&FILL==0){
			setlinewidth(3,menu_color);
			setfillcolor(RGB(211,211,211),menu_color);
			setfont(18,0,"����",menu_color);
			bar(0,0,100,52,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		if(FILL==0&&msg_color&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		if(msg_color&&FILL==0&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���  ��ɫ",menu_color);
			putimage(1100,500,menu_color);
			FILL=1;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		if(msg_color&&FILL==1&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,50,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"����  ��ɫ",menu_color);
			putimage(1100,500,menu_color);
			FILL=2;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		if(msg_color&&FILL==2&& msg.is_down()&&msg.is_left()&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500){
			FILL=0;
			while(msg.is_down()){
				msg.msg=mouse_msg_up;
			}
		}
		if(msg_MENU==0) putimage(560,0,MENU_POL);
		//���¿��
		if(DISPLAY_WIDTH&&msg.x<1200&&msg.x>1100&&msg.y>570&&msg.y<610&&msg.is_down()){
			if(msg.y<590) {
				setlinewidth((float)(wi=wi+1));
				setcolor(getcolor());
				while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
				}
			}
			if(msg.y>590&&msg.y<610){
				if(wi==1){
					setlinewidth(1);
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				}
				else{
					setlinewidth((float)(wi=wi-1));
					setcolor(getcolor());
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				} 
			}
		}
		if(DISPLAY_WIDTH) xyprintf(1100,610,"��ɫ��ϸ=%d ",wi);
		while(DISPLAY_WIDTH&&msg.x>1100&&msg.x<1200&&msg.y>550&&msg.y<570&&msg.is_down()) {
			width1=getInteger("��������");
			setlinewidth((float)width1);
			setcolor(getcolor());
			wi=width1;
			setfont(18, 0, "����");
			while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
				}
		}
		//���»������
		//���±���
		xyprintf(560,0,"��ǰ����=%d ",NUM_POINTS);
		if(msg.x<860&&msg.x>670&&msg.y>0&&msg.y<20&&msg.is_down()){
			if(msg.x<720) {
				NUM_POINTS++;
				while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
				}
			}
			if(msg.x>730&&msg.x<775){
				if(NUM_POINTS==3){
					NUM_POINTS=3;
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				}
				else{
					NUM_POINTS--;
					while(msg.is_down()){
						msg.msg=mouse_msg_up;//��������
					}
				} 
			}
		}
		while(msg.x>780&&msg.x<860&&msg.y>0&&msg.y<20&&msg.is_down()) {
			NUM_POINTS=getInteger("��������");
			if(NUM_POINTS<3) NUM_POINTS=3;
			
		}
		if((msg.is_down() && msg.is_left() &&msg.x<1100&&msg.y>80&&msg.y<800)||( msg.is_down() &&msg.is_left() && (msg_MENU) == 0) ){
			if(shapeT_pol->pol.numpoints==0&&shapeT_pol->next !=NULL);
			else shapeT_pol->next=creatlist();
			shapeT_pol->pol.numpoints=NUM_POINTS;	
			shapeT_pol->pol.dot[0]=x1=msg.x;
			shapeT_pol->pol.dot[1]=y1=msg.y;
			for(NUM=1;NUM<NUM_POINTS;NUM++){
				iswork=TRUE;
				while((msg.is_down() && msg.is_left() &&msg.x<1100&&msg.y>80&&msg.y<800)||( msg.is_down() &&msg.is_left() && (msg_MENU) == 0)){
					msg.msg=mouse_msg_up;//��������
				}
				while(iswork){
					mousepos(&x2,&y2);
					shapeT_pol->pol.dot[NUM*2]=x2;
					shapeT_pol->pol.dot[NUM*2+1]=y2;
					msg=getmouse();
					if(msg.is_down()) iswork=False;
				}
			}	
			while(msg.is_down()){
				msg.msg=mouse_msg_up;//��������
			}
			shapeT_pol->pol.pol_color=getcolor();
			shapeT_pol->pol.pol_width=wi;
			fillpoly(NUM_POINTS,shapeT_pol->pol.dot);
			shapeT_pol->pol.fill_pol_color=getfillcolor();
			RAM_COUNT++;
			if(RAM_COUNT != 0) shapeT_pol=shapeT_pol->next; //ĩβ��NULL
		}
	}
}
//lab07 �Ķ����,ע��ֻ�ǵ�����ӣ�û��������������ʹ��ȫ������ѡ����һ�������
void poly2(){
	closegraph();
	delay_ms(200);
	initgraph(1000,600);
	setbkcolor(WHITE);
	setcolor(BLACK);
	xyprintf(0,8,"S.k���壬polyͼ�Σ�ʹ���ַ����滭");
	int k,i=0;
	int col, ran[4];
	int n,j=0;
	int num[100];
	char b[100];
	char* p=b;
	char a[5];
	k=getInteger("�����Σ���������");
	inputbox_getline("����������","����(x,y),(x,y)...��.",p,100);
	for(n=0;b[n] !='0';n++)
	{
		if( ! ( b[n]<='9' && b[n]>='0' ) && !( b[n] =='(' ) && !(b[n] ==')' )&& !( b[n] ==',' ) )
		{
			xyprintf(0,30,
				"��ʽ��������벻Ҫ���������ַ���ֻ��(x,y),x,y������û�пո���������ö��Ÿ���");
			xyprintf(0,50,
				"���������ʼ�������룡������");
			getch();
			inputbox_getline("��������Ӧ����","����(x,y),(x,y),(x,y)...��.",p,100);
			n=0;                                               //�ص�0����ͷ����ʽ��
		}
	}
	while(*p !=')')
		{
			if(!(*p<='9' && *p>='0'))
			{
						p++;
						continue;
			}
			for(i=0;*p<='9' && *p>='0';i++,p++)
			{
				a[i]=*p;
			}
			num[j]=atoi(a);
			j++;
			p++;
			if(*p=='0') break;
		}
	cleardevice();
	delay_ms(100);
	for(i=0;i<=2;i++)
				{
						randomize();
						ran[i]=random(255);
				}
			randomize();
			col=random(EGERGB(ran[0],ran[1],ran[2]));
			setfillcolor(col);
	xyprintf(0,0,"�ɹ���������������%d����",k);
	fillpoly(k,num);
	getch();
	closegraph();
}
