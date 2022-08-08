#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <errno.h>

typedef struct contact
{
	char name[20];
	int age;
	char sex[5];
	char tele[12];
	struct contact* next;
}con,*pcon;

enum
{
	EXIT,//0,退出
	ADD,//1,添加
	SEARCH,//2,搜索
	DEL,//3,删除
	MOD,//4,修改
	PRINTF//5,打印所有信息
}choice;

void meau();//菜单
pcon InitCon(pcon Head);//初始化
void Add(pcon Con, int* Quantify);
void Print(const pcon Con);