#include"Fu.h"
int menu(FILE*fin)
{
	int x1=1,y1=0,k;
	xyprintf(x1,y1,"��ӭʹ��S.k���壡");
	xyprintf(x1,y1+20,"�Ƿ��ȡ�ϴα����ļ�:");
	xyprintf(x1,y1+40,"����1Ϊ�ǣ�����0Ϊ��");
	k=getInteger("������1����0����ѡ��");
	while(k != True && k != False)
	{
		xyprintf(x1,y1+60,"��������ַ�1��0������δ������������");
		k=getInteger("���������룡");
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
		xyprintf(0,60,"�ļ������ڣ�����δ���������������������ֱ�ӽ��뻭����棡��������");
		getch();//�޸����ļ������ڵĲ���
		delay_ms(200);
	}
}
void Paint_menu(SHAPE* shapeT)
{
	SHAPE* shapeT_1,*shapeT_M;//*shapeT_MΪ�м����
	//�����ļ�����
	//FILE*fout;
	int m_File=0;
	int x=0,y=0,KEY_x=0,KEY_y=1,CONST_X=0;//���ü�ͷ����֮ǰ��ת�����곣����
	mouse_msg msg={0};
	//menu
	int i=0,fillcolor=0;
	int RIGHT_LEFT=4,DISPLAY=0,DISPLAY_MENU=1,DISPLAY_WIDTH=0;//�����ͷ��ָ�������Χ�Լ��Ƿ���ʾ
	//��ֱֹ���ػ�
	shapeT->next=NULL;
	shapeT_1=(SHAPE*)malloc(sizeof(SHAPE));
	shapeT_M=(SHAPE*)malloc(sizeof(SHAPE));
	shapeT_M=shapeT_1=shapeT;
	//DISPLAY_MENU ==1ʱ�м��̲���
	PIMAGE menu_color,menu_1,menu_2=newimage(1100,100);
	menu_color=newimage(100,50);
	menu_1=newimage(1100,100);
	setbkcolor(WHITE,menu_1);
	setcolor(BLACK,menu_1);
	setfont(20,0,"����",menu_1);
	outtextxy(0,0,"��ӭ������S.k��ͼ����------(��˴����ز˵����Ҽ��ָ�)",menu_1);
	outtextxy(x,y+20,"1.ѡ��ͼ��",menu_1);
	outtextxy(550,38,"tips�������ѡ���������ͼ,*�����Ϊlab7�ַ������",menu_1);
	outtextxy(x+121,y+20,"ѡ����ɫ",menu_1);
	outtextxy(x+221,y+20,"ѡ����",menu_1);
	outtextxy(x+321,y+20,"�����ȡ",menu_1);
	setlinewidth(5,menu_1);
	setcolor(BLACK,menu_1);
	line(0,97,1100,97,menu_1);
	line(1098,0,1098,100,menu_1);
	putimage(0,0,menu_1);
	for(;is_run();delay_fps(60))
	{
		//����һЩ��ʼ��
		while(mousemsg()){
			msg=getmouse();
		}
		flushkey();
		//���¼��̴���	
		//�˵����Ĵ���
		if(DISPLAY_MENU && color_of_mousefont( 270,0,530,20,msg.x,msg.y,"(��˴����ز˵����Ҽ��ָ�) ",menu_1)){
			setfont(20,0,"����",0,0,900,0,0,0,menu_1);
			outtextxy(270,0,"(��˴����ز˵����Ҽ��ָ�) ",menu_1);
			putimage(0,0,menu_1);//��1
		}
		//�˵���Ӱ��������Ҽ���ʾ
		if(DISPLAY_MENU && msg.x>=270&&msg.x<=500&&msg.y<=20&&msg.is_down()&&msg.is_left()){
			DISPLAY_MENU=0;
			menu_2=non_menu();
		}
		if(DISPLAY_MENU==0&& msg.is_down()&&msg.is_right()){
			DISPLAY_MENU=1;
			dis_menu(menu_2);
		}
		//���ּ�ͷ��Ӧ
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
				}//����������ô��һ��if��Զִ��
				else {
					arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
					putimage(0,0,menu_1);
					flushkey();
				}
			}
		}	
		//����һ���˵���һ������
		if(DISPLAY_MENU &&(KEY_x==1) && KEY_y<3 &&keystate(VK_RETURN))//KEY_yȷ��ֻ������
		{
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_y++;
			arrow(KEY_x*100,KEY_y*20,DOWN,menu_1);
			KEY_y++;
			CONST_X=KEY_x*100;//��¼�¼�ͷ��λ��
			while(keystate(VK_RETURN)){
				outtextxy(0,60,"2.�� �� ",menu_1);
				outtextxy(120,60,"�� Բ",menu_1);
				outtextxy(220,60,"�� �� ",menu_1);
				outtextxy(311,60," �����",menu_1);
				outtextxy(422,60,"*�����",menu_1);
				RIGHT_LEFT=5;
				KEY_x=1;
				arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);//���³�ʼ��	
				flushkey();
				putimage(0,0,menu_1);
			}
		}
		//�����˵���һ����������ʾ�����嵱ǰ�ڻ�ʲô
		if(DISPLAY_MENU &&KEY_y==3&&RIGHT_LEFT==5&&CONST_X==100){
			switch(KEY_x){
			case 1:	color_of_keyfont(0,KEY_y*20,"2.�� ��",LIGHTBLUE,80);break;
			case 2:	color_of_keyfont(120,KEY_y*20,"�� Բ",LIGHTBLUE,80);break;
			case 3:	color_of_keyfont(220,KEY_y*20,"�� ��",LIGHTBLUE,80);break;
			case 4:	color_of_keyfont(321,KEY_y*20,"�����",LIGHTBLUE,80);break;
			case 5:	color_of_keyfont(422,KEY_y*20,"*�����",LIGHTBLUE,80);break;
			}
		}
		//����
		if(DISPLAY_MENU && CONST_X==100&&KEY_x==1 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN)){
			PAINT_LINE(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1);
			shapeT_1=shapeT_M;//���еı���ֵ
			for(;shapeT->next !=NULL;shapeT=shapeT->next);
			flushkey();
		}
		//��Բ
		if(DISPLAY_MENU&& CONST_X==100&&KEY_x==2 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN)){
			PAINT_CIRCLE(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1);
			shapeT_1=shapeT_M;//shapeT_1���еı���ֵ,shapeT_Mʹ��shapeT_1ÿ�ξ�Ϊ�ͷ��ĩβ
			for(;shapeT->next !=NULL;shapeT=shapeT->next);//�ص�����ĩ��
			//������shapeT_1���Ǵӿ�ʼŪ;
			flushkey();
		}
		//������
		if( DISPLAY_MENU&& CONST_X==100&&KEY_x==3 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN) ){
			PAINT_REC(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1);
			shapeT_1=shapeT_M;
			for(;shapeT->next !=NULL;shapeT=shapeT->next);//�ص�����ĩ��
			flushkey();
		}
		//�������
		if( DISPLAY_MENU&& CONST_X==100&&KEY_x==4 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN) ){
			PAINT_POL(DISPLAY_WIDTH,DISPLAY_MENU,DISPLAY,menu_1,shapeT,shapeT_1,menu_1);
			shapeT_1=shapeT_M;
			for(;shapeT->next !=NULL;shapeT=shapeT->next);//�ص�����ĩ��
			flushkey();
		}
		if( DISPLAY_MENU&& CONST_X==100&&KEY_x==5 && KEY_y==3 &&RIGHT_LEFT==5&&keystate(VK_RETURN) ){
			poly2();//ע��ֻ�ǵ����Ĺ���
		}
		//��ն����˵�
		if(DISPLAY_MENU &&keystate(VK_UP)&&KEY_y>1)
		{
			outtextxy(0,KEY_y*20,"                                                                             ",menu_1);
			KEY_y--;
			non_arrow(CONST_X,KEY_y*20,UP,menu_1);
			KEY_y--;
			RIGHT_LEFT=4;//���ʱ����һ���˵��ҳ��ȱ仯
			KEY_x=1;
			flushkey();
			putimage(0,0,menu_1);
		}
		//����һ���˵��ڶ�������
		if(DISPLAY_MENU &&(KEY_x==2) && KEY_y<3 &&keystate(VK_RETURN))
		{
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_y++;
			arrow(KEY_x*100,KEY_y*20,DOWN,menu_1);
			KEY_y++;
			CONST_X=KEY_x*100;
			while(keystate(VK_RETURN)){
				outtextxy(0,60,"2.��ʾ��ɫ",menu_1);
				outtextxy(120,60,"������ɫ",menu_1);
				outtextxy(220,60,"ȡ����ʾ",menu_1);
				RIGHT_LEFT=3;
				KEY_x=1;
				arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);//���³�ʼ��
				flushkey();
				putimage(0,0,menu_1);
			}
		}
		//���˵��ڶ�����������ʾ�����嵱ǰ�ڸ�ʲô
		if(DISPLAY_MENU &&CONST_X==200&&KEY_y==3&&RIGHT_LEFT==3&&CONST_X==200){
			switch(KEY_x){
			case 1:	color_of_keyfont(0,KEY_y*20,"2.��ʾ��ɫ",CYAN,100);break;
			case 2:	color_of_keyfont(120,KEY_y*20,"������ɫ",CYAN,80);break;
			case 3:	color_of_keyfont(220,KEY_y*20,"ȡ����ʾ",CYAN,80);break;
			}
		}
		//����display�ı��ж������˳�
		if(DISPLAY_MENU &&CONST_X==200&&(DISPLAY=1)&&RIGHT_LEFT==3&&KEY_y==3&&KEY_x>=1 &&KEY_x<=2&&keystate(VK_RETURN))
		{
			if(KEY_x==1){
				outtextxy(0,60,"2.��������",menu_1);
				Color();
				fillcolor=1;
			}
			if(KEY_x==2){
				Color_deep();	
				fillcolor=1;
			}
		}
		//��������ɫ����ʧ
		if(DISPLAY_MENU&&CONST_X==200 &&DISPLAY==1&&RIGHT_LEFT==3&&KEY_y==3 &&KEY_x==3&&keystate(VK_RETURN)){
			DISPLAY=0;
			non_color();
			fillcolor=0;
		}
		if(fillcolor==1&&!(msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500)){
			setlinewidth(5,menu_color);
			setfillcolor(RGB(211,211,211),menu_color);
			bar(0,0,100,50,menu_color);
			setfont(18,0,"����",menu_color);
			setbkcolor(BLACK,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		if((fillcolor==1&&msg.x>1100&&msg.x<1200&&msg.y<550&&msg.y>500) ){
			setlinewidth(3,menu_color);
			setfillcolor(WHITE,menu_color);
			rectangle(0,0,100,48,menu_color);
			setbkcolor(WHITE,menu_color);
			setcolor(BLACK,menu_color);
			setfontbkcolor(RGB(211,211,211),menu_color);
			outtextxy(5,18,"���or����",menu_color);
			putimage(1100,500,menu_color);
		}
		//����һ������������
		if(DISPLAY_WIDTH==0 &&DISPLAY_MENU &&(KEY_x==3) && KEY_y<3 &&keystate(VK_RETURN)){
			//DISPLAY_WIDTH=1;//ʹ����ʾ
			outtextxy(x+221,y+20,"ȡ�����",menu_1);
			putimage(0,0,menu_1);
			SK_WIDTH();
			DISPLAY_WIDTH=1;
			while(keystate(VK_RETURN)){
				flushkey();
			}
		}
		if( DISPLAY_MENU &&(KEY_x==3) && KEY_y<3 &&keystate(VK_RETURN)){
			if(DISPLAY_WIDTH==1){
				outtextxy(x+221,y+20,"ѡ����",menu_1);
				putimage(0,0,menu_1);
				non_SK_WIDTH();
				DISPLAY_WIDTH=0;
				while(keystate(VK_RETURN)){
					flushkey();
				}
			}
		}
		//����һ�����ĸ�����
		if(DISPLAY_MENU &&(KEY_x==4) && KEY_y<3 &&keystate(VK_RETURN))
		{
			non_arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);
			KEY_y++;
			arrow(KEY_x*100,KEY_y*20,DOWN,menu_1);
			KEY_y++;
			CONST_X=KEY_x*100;//��¼�¼�ͷ��λ��
			while(keystate(VK_RETURN)){
				outtextxy(0,60,"2.�����ļ�",menu_1);
				outtextxy(120,60,"������ʾ",menu_1);
				outtextxy(220,60,"��ջ���",menu_1);
				outtextxy(321,60,"��y����ݱ��棬��n������,������ʾ�ָ�Ϊ����ǰ",menu_1);
				RIGHT_LEFT=3;
				KEY_x=1;
				arrow(KEY_x*100,KEY_y*20,LEFT,menu_1);//���³�ʼ��	
				flushkey();
				putimage(0,0,menu_1);
			}
		}
		//�����˵����ĸ���������ʾ�����嵱ǰ�ڸ�ʲô
		if(DISPLAY_MENU &&KEY_y==3&&RIGHT_LEFT==3&&CONST_X==400){
			switch(KEY_x){
			case 1:	color_of_keyfont(0,KEY_y*20,"2.�����ļ�",LIGHTRED,100);break;
			case 2:	color_of_keyfont(120,KEY_y*20,"������ʾ",LIGHTRED,80);break;
			case 3:	color_of_keyfont(220,KEY_y*20,"��ջ���",LIGHTRED,80);break;
			}
		}
		//���ĸ������˵��ĵ�1���Ĺ���ʵ��,
		/*ע�ͣ�
		��������˳�򴢴�
		*/
		if(DISPLAY_MENU && CONST_X==400 &&KEY_x==1 && KEY_y==3 &&keystate(VK_RETURN)){
			writeToFile(shapeT_1);
			while(keystate(VK_RETURN)){
				flushkey();
			}
		}
		//���ĸ������˵��ĵ�4���Ĺ���ʵ�֣�Y��N��
		if(keystate('N')||keystate('n')){
			if(DISPLAY_WIDTH|| DISPLAY) {
				setviewport(0,0,1100,800);
				setfillcolor(WHITE);
				clearviewport();
				outtextxy(x+221,y+20,"ѡ����",menu_1);
				fillcolor=0;
				setviewport(0,0,1200,800);
			}
			else cleardevice();
			putimage(0,0,menu_1);
		}
		if(keystate('Y')||keystate('y')){
			writeToFile(shapeT_1);
		}
		//���ĸ������˵��ĵ�3���Ĺ���ʵ��
		if(DISPLAY_MENU && CONST_X==400 &&KEY_x==3 && KEY_y==3 &&keystate(VK_RETURN)){
			shapeT=creatlist();
			shapeT->next=NULL;
			shapeT_1=shapeT_M=shapeT;
			while(keystate(VK_RETURN)){
				flushkey();//���Ӳ��У�
			}
		}
		//���ĸ������˵��ĵ�2���Ĺ���ʵ��
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
					setlinewidth(1);//�������������ɫ���߿�
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
			shapeT_1=shapeT_M;//�ص������ͷ
		}
	}
	delimage(menu_1);
	delimage(menu_2);
	free(shapeT_1);
	free(shapeT_M);
}
//������ͷ
void arrow(int x,int y,int direcT,PIMAGE MENU)
{
	if(direcT==LEFT) outtextxy(x,y,"��",MENU);
	if(direcT==RIGHT) outtextxy(x,y,"��",MENU);
	if(direcT == DOWN) outtextxy(x,y,"��",MENU);
}
//�����ͷ
void non_arrow(int x,int y,int direcT,PIMAGE MENU)
{
	if(direcT==LEFT||direcT==RIGHT) outtextxy(x,y,"��",MENU);
	if(direcT==UP) outtextxy(x,y,"��",MENU);
}
//������ʾѡɫ���ʹ�ϸѡ����
void Color()
{
	barcol(BLACK,1100,450,50);
	int i=0;
	color_t checkcolor[20]={0};
	randomize();
	for(;i<9;i++)//�������ĸ�
	{
		setfillcolor(hsl2rgb(float(randomf() * 360), 1.0f, 0.5f));//
		checkcolor[i]=getfillcolor();
		setfillcolor( check(checkcolor,i) );//������ͬ��ɫ
		bar(1100,i*50,1200,50+i*50);//����y֮�����50��������
	}
}
//����ɫ����
void barcol(color_t color,int x1,int y1,int size)
{
	setfillcolor(color);
	bar(x1,y1,x1+100,y1+size);
}
//�����ɫ���ظ��ԣ�
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
//��������ɫ
void Color_deep()
{
	int i=0;
	color_t checkcolor[20]={0};
	randomize();
	for(;i<10;i++)
	{
		setfillcolor(EGERGB(random(255) ,random(255) ,random(255)));//
		checkcolor[i]=getfillcolor();
		setfillcolor( check(checkcolor,i) );//������ͬ��ɫ
		bar(1100,i*50,1200,50+i*50);
	}
}
//������ɫ
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
//�����˵�
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
	putimage(0,0,MENU_5);//��д�����ͻȻͣһ��
	setviewport(0,0,1200,800);
}
//�����Ӧ,������Ӧ
bool color_of_mousefont(int left, int top, int right,int bottom,int MSG_X, int MSG_Y,LPCSTR text,PIMAGE	MENU)
{
	if(MSG_X>=left&&MSG_X<=right&&MSG_Y<=bottom&&MSG_Y>=top){return true;}
	else{
		setfont(20,0,"����",MENU);
		outtextxy(left,top,text,MENU);
		putimage(0,0,MENU);
		return false;
	}
}
void color_of_keyfont(int left, int top,LPCSTR text,color_t color,int size)
{
	PIMAGE MENU_3;//Ϊ����ɫ����
	MENU_3=newimage(size,20);
	setbkcolor(WHITE,MENU_3);
	setcolor(color,MENU_3);//��������ɫ�ı�
	setfont(20,0,"����",0,0,0,0,1,0,MENU_3);
	outtextxy(0,0,text,MENU_3);
	putimage(left,top,MENU_3);
	delimage(MENU_3);
}
//�ڴ����
SHAPE * creatlist()
	//���������ͼ�򴴽�һ��SHAPE
{
	SHAPE *h;
	h=(SHAPE*)malloc(sizeof(SHAPE));
	return h;
}
//��ȡ�ļ�
void writeToFile(SHAPE*shapeT_F){
	FILE*fout;
	SHAPE*shapeT_files;
	shapeT_files=(SHAPE*)malloc(sizeof(SHAPE));
	shapeT_files=shapeT_F;
	fout=fopen("data.txt","w");//δ�����꿪ʼ��
	fprintf(fout,"%s\n","�밴��ͼ��Ӣ�ĵ���������ĸ+�ո�+����+(�뾶+�߿�(>=0)+����ɫ(0��16777215)+���ɫ)�ķ�ʽ�޸�,�������߿���ɫ����Ĭ�Ϻ�ɫ����ϸ");
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
		if(shapeT_files->lin.line_dot[0].x>0){//����+��ϸ+������ɫ
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
	fclose(fout);//���˺�Ҫ���Ϲر�
}
void readFromFile(FILE*fin){
	char name[4];
	int a[10];//�ݴ�����
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
			setlinewidth(1);//�������������ɫ���߿�
			setcolor(0);
			setfillcolor(TRANSPARENT);
		}
		if( ! ( strcmp(name,"lin") ) ){
			fscanf(fin,"%d %d %d %d %d %d\n",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
			if(a[4]>=0) setlinewidth((float)a[4]);
			if(a[5]>=0) 	setcolor(a[5]);
			line(a[0],a[1],a[2],a[3]);
			setlinewidth(1);//����Ҫ�޸�
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
			setlinewidth(1);//����Ҫ�޸�
			setcolor(0);
			setfillcolor(TRANSPARENT);
		}
	}	
}
//���ϸѡ��
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
	setfont(18,0,"����");
	xyprintf(1100,610,"��ɫ��ϸ=");
	outtextxy(1100,590,"�������");
	outtextxy(1100,570,"�������");
	outtextxy(1100,552,"�Լ�ѡ��");
	xyprintf(1100,630,"�ǻ�ͼ��Ч");
	xyprintf(1100,650,"��ͼΪʾ��");
	for(int i=1;i<4;i++){
		barcol(BLACK,1100,680+40*(i-1),8*i);
	}//��ʱûЧ��
}/**/
