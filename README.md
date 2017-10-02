# StudentInformationManagementSystem
#### 1.简介：
      这是一个C语言版的学生信息管理系统，里面包括简单的dos页面设计，以及学生信息的插入，查找，保存，读取，删除等功能。
#### 2.代码：
      其中包含4个.h头文件，以及4个.cpp源文件。
      
      
      （1）menu.h
      void  menu();
      void SetHint(const char *s);
      void ModelMenu(const char *s);
      
      menu.cpp
      
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
     
     
     (2)student.h
     #include"main.h"

     void print();
     void Input();
     void Search();
     void Del();
     void Sort();
     void Modi();
     void Save();

     struct Score
     {
	     float Chinese;
	     float Math;
	     float English;
	     float PE;
	     float sum;
       };


      struct  student
     {
	   char num[10];
	   char name[20];
	   char sex[10];
	   int age;
	   Score score;
     }stu[N];
    
     
     student.cpp
     
     #include"student.h"
     #include"menu.h"
     #include"print.h"

     void Input()
     {
	int i=0;
	char l;
	system("cls");
	ModelMenu("录入学生信息");
	i=StNum;
	printf("已输入了%d个学生信息！",i++);
	printf("\n输入第%d个学生的学生序号：",i);
	scanf("%s",&stu[i].num);
	printf("\n输入第%d个软件的学生姓名：",i);
	scanf("%s",&stu[i].name);
	printf("\n输入第%d个学生的性别：",i);
	scanf("%s",&stu[i].sex);
	printf("\n输入第%d个学生的年龄：",i);
	scanf("%d",&stu[i].age);
	printf("\n输入第%d个学生的语文成绩：",i);
	scanf("%f",&stu[i].score.Chinese);
	printf("\n输入第%d个学生的数学成绩：",i);
	scanf("%f",&stu[i].score.Math);
	printf("\n输入第%d个学生的英语成绩：",i);
	scanf("%f",&stu[i].score.English);
	printf("\n输入第%d个学生的体育成绩：",i);
	scanf("%f",&stu[i].score.PE);

	stu[i].score.sum+=stu[i].score.Chinese+stu[i].score.Math+stu[i].score.English+stu[i].score.PE;
	print();
	StNum++;

	printf("是否继续输入？（Y/N）:");
	getchar();
	scanf("%c",&l);
	if(l=='n'||l=='N')
		return;
	else if(l=='y'||l=='Y')
	{
		system("cls");
		Input();
	}


     }

     void Search()
     {
	int i=0,flag=1;
	char str[20];
	char l;
	system("cls");
	ModelMenu("查询学生信息");
	printf("请输入要查找的学生的序号：");
	scanf("%s",&str);

	for(i=0;i<N;i++)
	
		if((strcmp(str,stu[i].num))==0)
		{
			print();
			flag=0;
		}
		if(flag==1)
		printf("无此序号！\n");
		printf("是否继续输入？（Y/N）:");
	getchar();
	scanf("%c",&l);
	if(l=='n'||l=='N')
		return;
	else 
	
		system("cls");
		


	
     }

     void Del()
     {
	int i,j,flag=1;
	char str[20];
	char l;
	system("cls");
	ModelMenu("删除学生信息");
	printf("请输入要删除的学生的序号：");
	scanf("%s",&str);
	for(i=0;i<N;i++)
		if((strcmp(str,stu[i].num))==0)
		{
			print();//
			for(j=i;j<N;j++)
				stu[j]=stu[j+1];
			flag=0;
			printf("删除成功！\n");
			StNum--;
		}
		if(flag==1)
		
			printf("没有这个软件！\n");
			printf("是否继续删除（Y/N）:");
			getchar();
	scanf("%c",&l);
	if(l=='n'||l=='N')
		return;
	else 
	{
		system("cls");
		Del();
	}
		
     }

    void Sort()
    {
	struct student t;
	int i,k,p,x;

	float sum[N],g;
	
	system("cls");
	 SetHint("排序完成");
	 menu();

	for(i=0;i<N;i++)
		stu[i].score.sum=stu[i].score.Chinese+stu[i].score.Math+stu[i].score.English+stu[i].score.PE;
	for(k=0;k<N-1;k++)
	{
		x=k;
		for(p=x+1;p<N;p++)
		{
			x=p;
			g=sum[k];
			sum[k]=sum[x];
			sum[x]=g;
			t=stu[k];
			stu[k]=stu[x];
			stu[x]=t;
		}
	}

     }

     void Modi()
     {
	int i=0,flag=1;
	char str[20];
	char l;
	system("cls");
	ModelMenu("修改学生信息");
	printf("请输入要修改的学生的序号：");
	scanf("%s",&str);
	for(i=0;i<N;i++)
		if((strcmp(str,stu[i].num))==0)
			break;
	if(i!=N)
	{
		printLine();
		print();
		printLine();
		printf("\n请输入修改内容\n");
		printf("请修改学生序号：");
		scanf("%s",&stu[i].num);

		printf("请修改学生姓名：");
		scanf("%s",&stu[i].name);
		printf("请修改学生性别：");
		scanf("%s",&stu[i].sex);
		printf("请修改学生年龄：");
		scanf("%d",&stu[i].age);

		printf("请修改学生的语文成绩：");
		scanf("%f",&stu[i].score.Chinese);
		printf("请修改学生的数学成绩：");
		scanf("%f",&stu[i].score.Math);
		printf("请修改学生的英语成绩：");
		scanf("%f",&stu[i].score.English);
		printf("请修改学生的体育成绩：");
		scanf("%f",&stu[i].score.PE);

		stu[i].score.sum=stu[i].score.Chinese+stu[i].score.Math+stu[i].score.English+stu[i].score.PE;

		printf("修改后的学生信息为：\n");

		printLine();
		print();
		printLine();

	}
	else
		printf("没有这个学生！\n");
	printf("是否继续输入？（Y/N）:");
	getchar();
	scanf("%c",&l);
	if(l=='n'||l=='N')
		return;
	else if(l=='y'||l=='Y')
	{
		system("cls");
		Modi();
	}

     }

     void Save()
     {
	FILE *fp;
	int i;
	fp=fopen("F:\\C++代码\\0A每日练习\\StudentScore.txt","w");
	system("cls");
	SetHint("保存成功");
	menu();
	fprintf(fp,"序号\t姓名\t\t性别\t年龄\t语文\t数学\t英语\t体育\t总成绩\n");
	for(i=N;i>0;i--)
		if(stu[i].age!=0)
		fprintf(fp,"%s\t%s\t\t%s\t%d\t%.lf\t%.lf\t%.lf\t%.lf\t%.lf\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].age,stu[i].score.Chinese,stu[i].score.Math,stu[i].score.English,stu[i].score.PE,stu[i].score.sum);
	   fclose(fp);
     }


     void print()
     {
	int i;
	system("cls");
	ModelMenu("显示全部学生信息");
	printf("序号\t姓名\t\t性别\t年龄\t语文\t数学\t英语\t体育\t总成绩\n");
	for(i=N;i>0;i--)
		if(stu[i].age!=0)
			printf("%s\t%s\t\t%s\t%d\t%.lf\t%.lf\t%.lf\t%.lf\t%.lf\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].age,stu[i].score.Chinese,stu[i].score.Math,stu[i].score.English,stu[i].score.PE,stu[i].score.sum);
	      while(TURE)
		  {
			  char l;
			  printf("是否返回主菜单？（Y/N）:");
			  getchar();
			  scanf("%c",&l);
			  if(l=='Y'||l=='y')
				  return;
		  }
     }
     
     
     
     （3）print.h
     
     #include<stdio.h>
     #include<string.h>
     void printLine();
     void printTitle(const char *title);
     
     print.cpp
     
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
    
     
     
     （4）main.h
     
     #include<stdio.h>
     #include<string.h>
     #include<stdlib.h>
     #define N  1000//最大学生数
     #define TURE 1
     static  int StNum; //已输入学生人数
     
     main.cpp
     
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
    
    
#### 3.运行显示：
![](https://github.com/Zxnaruto/StudentInformationManagementSystem/blob/master/image/%E8%BF%90%E8%A1%8C%E6%95%88%E6%9E%9C01.png)
![](https://github.com/Zxnaruto/StudentInformationManagementSystem/blob/master/image/%E8%BF%90%E8%A1%8C%E6%95%88%E6%9E%9C02.png)
![](https://github.com/Zxnaruto/StudentInformationManagementSystem/blob/master/image/%E8%BF%90%E8%A1%8C%E6%95%88%E6%9E%9C03.png)




