

#include"print.h"


char hint[80]="请按提示输入！！！";

void menu()
{
	printLine();
	printTitle("学生信息管理系统");
	printLine();
	printTitle("输入指令，执行相应的操作");
	printTitle("1.学生信息录入      2.学生信息查询");
	printTitle("3.学生信息删除      4.学生信息排序");
	printTitle("5.学生信息修改      6.学生信息保存");
	printTitle("7.学生信息显示      8.退出系统    ");
	printLine();
	printTitle(hint);       //提示信息
	printLine();



}


void SetHint(const char *s)
{
	strcpy(hint,s);//设置提示信息
}

void ModelMenu(const char *s)
{
	printLine();
	printTitle(s);
	printLine();

}