# FirstUseGitHub
#### 1.简介：
      这是一个C语言版的学生信息管理系统，里面包括简单的dos页面设计，以及学生信息的插入，查找，保存，读取，删除等功能。
#### 2.代码：
      其中包含4个.h头文件，以及4个.cpp源文件
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


