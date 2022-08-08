#include "contact.h"

int main()
{
	int Judge = 1;
	int Quantity = 0;//用来记录有多少个成员
	pcon Con = NULL;

	Con = InitCon(Con);//初始化
	if (Con == NULL)//是否初始化成功
		return 0;

	do 
	{
		meau();//菜单
		printf("请输入操作:");
		scanf_s("%d", &Judge);
		switch (Judge)
		{
		case EXIT:
			system("cls");
			printf("退出程序\n"); 
			break;

		case ADD:
			system("cls");
			printf("添加信息\n");
			Add(Con, &Quantity);
			break;

		case SEARCH:
			system("cls");
			printf("搜索信息\n");
			//Search();
			break;

		case DEL:
			system("cls");
			printf("删除信息\n");
			//Delete();
			break;

		case MOD:
			system("cls");
			printf("修改信息\n");
			//Modify();
			break;

		case PRINTF:
			system("cls");
			printf("显示所有信息\n");
			Print(Con);
			break;

		default:
			system("cls");
			printf("输入错误，重新输入\n");
			break;
		}
	} while (Judge);

	////文件操作
	//FILE* pf = fopen("test.txt", "w");
	//if (pf == NULL)
	//{
	//	printf("%s", strerror(errno));
	//	return 0;
	//}

	//fscanf(stdin, "%s", buf);
	//fprintf(stdout, "%s ", buf);

	//fclose(pf);//关闭文件
	//pf = NULL;
	return 0;
}

void meau()
{
	printf("*************\n");
	printf("*  0:退出   *\n");
	printf("*1:添加信息 *\n");
	printf("*2:搜索信息 *\n");
	printf("*3:删除信息 *\n");
	printf("*4:修改信息 *\n");
	printf("*5:显示所有 *\n");
	printf("*  信息     *\n");
	printf("*************\n");
}

pcon InitCon(pcon Head)//初始化
{
	Head = (pcon)malloc(sizeof(con));
	if (Head == NULL)
	{
		printf("空间不足\n");
		return NULL;
	}
	Head->age = 0;
	Head->next = NULL;
	return Head;
}

void Add(pcon Con,int* Quantify)//尾插法
{
	pcon p = Con;
	int Judge = 1;
	while (p->next != NULL)//将指针移动到最后一个
	{
		p = p->next;
	}
	pcon add = NULL;
	while (Judge)
	{
		add = (pcon)malloc(sizeof(con));
		if (add == NULL)
		{
			printf("空间不足\n");
			free(add);
			exit(0);
		}
		(*Quantify)++;
		printf("请输入姓名:");
		scanf_s("%s", add->name,sizeof(add->name));
		printf("请输入性别:");
		scanf_s("%s", add->sex, sizeof(add->sex));
		printf("请输入年龄:");
		scanf_s("%d", &add->age);
		printf("请输入电话:");
		scanf_s("%s", add->tele, sizeof(add->tele));
		add->next = NULL;
		p->next = add;
		p = p->next;

		printf("输入0以结束操作，输入其他数字以继续:");
		scanf_s("%d", &Judge);
	}

}

void Print(const pcon Con)
{
	if (Con->next == NULL)
	{
		printf("列表为空!\n\n");
		return;
	}
	pcon p = Con;
	printf("姓名	性别	年龄	电话\n");
	while (p->next != NULL)
	{
		p = p->next;
		printf("%s	%s	%d	%s\n", p->name, p->sex, p->age, p->tele);
	}
}