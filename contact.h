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
	EXIT,//0,�˳�
	ADD,//1,���
	SEARCH,//2,����
	DEL,//3,ɾ��
	MOD,//4,�޸�
	PRINTF//5,��ӡ������Ϣ
}choice;

void meau();//�˵�
pcon InitCon(pcon Head);//��ʼ��
void Add(pcon Con, int* Quantify);
void Print(const pcon Con);