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
	ModelMenu("显示全部软件信息");
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