Sk_paint-----09-03修改版
改进：
1.加入了文件读取错误处理
2.修改了强制类型转换的处理
tips:
1.方向键选择，鼠标点击作图,*多边形为lab7字符多边形
2.在任何地方可按Yy，Nn保存和清屏
3.宽度和颜色只有在画图时选择有用
4.宽度和画图消失隐藏时有一点延迟效果。不是卡机~~~~~~
实验目的
1.1.1.	如何添加及使用EGE库
1.2.	学会如何调试程序
1.3.	掌握EGE的一些函数用法，并且应用循环语句
1.3.1.	理解并掌握if 语句和switch 语句的基本使用方法。
1.3.2.	理解并学会使用逻辑运算符。
1.3.3.	简单的绘画。
1.4.	函数的应用
1.4.1.	了解函数作为简化程序结构的工具的重要性。
1.4.2.	了解函数调用的概念以及为什么要在函数调用中提供参数。
1.4.3.	了解什么是函数原型以及如何编写函数原型。
1.4.4.	理解在函数间传递信息的机制。
1.4.5.	能够创建新的函数，并实现调用。
1.5.	认识把单个程序分为多个单独模块的重要性。
1.5.1.	理解如何用函数来构建模块化的程序。
1.5.2.	能够应用逐步精化作为问题求解的策略。
1.5.3.	学会如何将模块化的程序分文件进行管理。
1.6.	(1) 掌握如何定义数组，初始化数组以及引用数组中的单个元素。
1.7.	(2) 掌握如何使用数组对一组值进行存储、排序及查找。
1.7.1.	(3) 能够将数组作为参数传递给函数。
1.8.	掌握如何定义结构体和声明一个结构体变量。
1.9.	掌握指针的基本操作。
1.10.	理解指针和数组间的关系。
1.11.	能够通过引用调用在函数调用程序之间共享数据。
1.12.	进一步理解文件的概念以及文本文件如何实现永久存储。
1.13.	能够创建、读取、写入和更新文件。
二.	实验内容
2.1.	能画四种以上的图形
2.2.	能读取和保存文件
2.3.	实现字符串的多边形
2.4.	用结构体保存数据
2.5.	调用函数使其能够多次绘图，并且画多种图形
三.	实验环境
3.1.	Vs2010
3.2.	EGE库
3.3.	Windows系统
四.	附录
（附上实验文档，如：问题分析、设计方案、算法、设计图、程序、仿真结果、运行结果、调试心得等，具体内容根据实验要求来定。源代码请附在这里。源代码排版请特别注意，用5 号字体，行间距为单倍行距。注意节省空间，不要浪费纸张。）
4.1.	问题分析
（说明你对这个问题的理解，包括，这个程序要解决什么问题、功能、性能、健壮性等）
4.1.1.	目标
4.1.1.1.	绘图功能选择和实现
4.1.1.2.	文件的读取和保存
4.1.1.3.	结构体的使用
4.1.1.4.	函数相互调用
4.1.2.	功能
4.1.2.1.	功能一：文件读取和保存
使用1.void writeToFile(SHAPE*);
	2.void; readFromFile(FILE*fin)
两个函数读写文件:
1.	开始程序后询问是否读取，是，则调用readFromFile(FILE*fin)，实现读取名为data.txt文件里的数据信息。
2.	在画图及选项中有Y(y)快捷保存，及选项保存，当按键或选该项时调用writeToFile(SHAPE*).
4.1.2.2.	功能二：鼠标绘图，方向键选择
1．点击画图选项功能后，可以在指定的区域内点击确定点以画图。
2．方向键可以控制菜单项目。并且有箭头显示和颜色变化。
3．能清屏和清除当前结构体数据
4.1.2.3.	功能三：隐藏菜单和画板
使用1.  PIMAGE non_menu();
1．	void dis_menu(PIMAGE MENU_5);
2．	点击相应的字体时隐藏菜单，且可在菜单内画图。
3．	右键点击任何地方时恢复菜单。
4．	无菜单时对方向键无反应。
4.1.2.4.	功能四：能选择颜色（填充/线条），和宽度
1. 	void non_SK_WIDTH();
	void SK_WIDTH();
	void Color();
	void barcol(color_t color,int x1,int y1,int size);
	color_t check(color_t color[],int num);
	void Color_deep();
	void non_color();
2．如函数名所示：实现颜色（填充/线条）和宽度的选择和转换。
3．点击下确定。
4.1.2.5.	功能五：使用链表建造结构的数据
1．	每次作图时均会再增加一个链结以扩大数据结构。
4.1.2.6.	功能六：自定义数据
1．采用fprintf和fscanf的文件保存读取，显示可改，可操作。
4.1.3.	性能
4.1.3.1.	文件读取和保存的性能
1．在数次的测试和调试中未发现有大的读取和保存错误。
2．延迟100ms作图
3．在偶尔的几次测试中出现不完整绘图。
4.1.3.2.	鼠标绘图和键盘操作性能
1．	键盘反应时间良好，但鼠标有时会有不及时的响应的问题。
4.1.3.3.	菜单隐藏的性能
1.	菜单隐藏性能较良好，未出现问题。
2.	有1ms的延迟设置。
4.1.3.4.	选择颜色（填充/线条）和宽度性能
1．	经过改良，性能良好。
2．	在未进入画图前无法选择。
4.1.4.	健壮性
（说明这个程序应对错误输入、异常情况的能力，参见下例4.1.3.1。在撰写正文时，请删除例子）
4.1.4.1.	异常输入处理
1．	在文件读取时输入1或0，若输入其他数字是会在屏幕上显示：输入的数字非1与0，错误，未操作！请重输。
2．	在不含颜色（填充/线条）和宽度的文本数据（即未写该类型数据）进行读取时设置了-1默认值便于寻找数据，使其不会出错。
3．	在链表中开头设计shapeT->next=NULL;使得开头重画功能不会出错。
4．	在每次的绘图后，都加入shapeT->next=NULL;使得不出错
5．	使用int RIGHT_LEFT=4,DISPLAY=0,DISPLAY_MENU=1,DISPLAY_WIDTH=0;使得每次的方向键操作明确其目标而稳定运行。
6．	有颜色重复性的检查函数，使其颜色尽量不同
4.2.	设计方案
（在此处，用文字描述整体的设计，包括，分成多少个模块，多少个文件，多少个函数，每个模块、函数、文件的大致功能； 此外，还需要包含一个程序整体的流程图，反映各个模块的执行次序和关系；但是避免绘制细节的流程）
4.3.	重要算法
（在此处，用流程图描绘重要的算法，例如排序、查找等。一般的程序代码不必在此说明）
4.3.1.	算法一：
无
