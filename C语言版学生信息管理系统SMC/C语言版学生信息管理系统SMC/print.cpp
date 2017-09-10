#include"print.h"


void printLine()
{
	int i;
	for(i=0;i<80;i++)
		putchar('*');
}




void printTitle(const char*title)
{
	int i;
	int length= strlen(title);//计算标题长度
	putchar('*');
	for(i=0;i<(80-2-length)/2;i++)
		putchar(' ');            //输出空格
	printf("%s",title);          //输出标题
	for(i=i+length-1;i<77;i++)   
		putchar(' ');        //补齐剩余空格
	putchar('*');
}