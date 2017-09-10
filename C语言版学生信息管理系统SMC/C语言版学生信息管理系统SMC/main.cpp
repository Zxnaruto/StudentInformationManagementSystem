#include"main.h"
#include"menu.h"

extern void Input();
extern void Search();
extern void Del();
extern void Sort();
extern void Modi();
extern void Save();
extern void print();



void main()
{
	int as;                                   //输入数字
	
	do
	{
		menu();
		printf("Input >");
		SetHint("请按提示输入！！！");

		scanf("%d",&as);
		if(as<1||as>8)
			as=0;
		switch(as)
		{
			case 0: SetHint("输入错误,请按提示输入！！！");break;
			case 1:Input();break;
			case 2:Search();break;
			case 3:Del();break;
			case 4:Sort();break;
			case 5:Modi();break;
			case 6:Save();break;
			case 7:print();break;
			case 8:break;
			default: menu();
		}
		system("cls");

	}while(as!=8);
}