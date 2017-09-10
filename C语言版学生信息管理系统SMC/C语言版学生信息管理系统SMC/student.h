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

