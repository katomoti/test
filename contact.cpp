#include "contact.h"

int main()
{
	int Judge = 1;
	int Quantity = 0;//������¼�ж��ٸ���Ա
	pcon Con = NULL;

	Con = InitCon(Con);//��ʼ��
	if (Con == NULL)//�Ƿ��ʼ���ɹ�
		return 0;

	do 
	{
		meau();//�˵�
		printf("���������:");
		scanf_s("%d", &Judge);
		switch (Judge)
		{
		case EXIT:
			system("cls");
			printf("�˳�����\n"); 
			break;

		case ADD:
			system("cls");
			printf("�����Ϣ\n");
			Add(Con, &Quantity);
			break;

		case SEARCH:
			system("cls");
			printf("������Ϣ\n");
			//Search();
			break;

		case DEL:
			system("cls");
			printf("ɾ����Ϣ\n");
			//Delete();
			break;

		case MOD:
			system("cls");
			printf("�޸���Ϣ\n");
			//Modify();
			break;

		case PRINTF:
			system("cls");
			printf("��ʾ������Ϣ\n");
			Print(Con);
			break;

		default:
			system("cls");
			printf("���������������\n");
			break;
		}
	} while (Judge);

	////�ļ�����
	//FILE* pf = fopen("test.txt", "w");
	//if (pf == NULL)
	//{
	//	printf("%s", strerror(errno));
	//	return 0;
	//}

	//fscanf(stdin, "%s", buf);
	//fprintf(stdout, "%s ", buf);

	//fclose(pf);//�ر��ļ�
	//pf = NULL;
	return 0;
}

void meau()
{
	printf("*************\n");
	printf("*  0:�˳�   *\n");
	printf("*1:�����Ϣ *\n");
	printf("*2:������Ϣ *\n");
	printf("*3:ɾ����Ϣ *\n");
	printf("*4:�޸���Ϣ *\n");
	printf("*5:��ʾ���� *\n");
	printf("*  ��Ϣ     *\n");
	printf("*************\n");
}

pcon InitCon(pcon Head)//��ʼ��
{
	Head = (pcon)malloc(sizeof(con));
	if (Head == NULL)
	{
		printf("�ռ䲻��\n");
		return NULL;
	}
	Head->age = 0;
	Head->next = NULL;
	return Head;
}

void Add(pcon Con,int* Quantify)//β�巨
{
	pcon p = Con;
	int Judge = 1;
	while (p->next != NULL)//��ָ���ƶ������һ��
	{
		p = p->next;
	}
	pcon add = NULL;
	while (Judge)
	{
		add = (pcon)malloc(sizeof(con));
		if (add == NULL)
		{
			printf("�ռ䲻��\n");
			free(add);
			exit(0);
		}
		(*Quantify)++;
		printf("����������:");
		scanf_s("%s", add->name,sizeof(add->name));
		printf("�������Ա�:");
		scanf_s("%s", add->sex, sizeof(add->sex));
		printf("����������:");
		scanf_s("%d", &add->age);
		printf("������绰:");
		scanf_s("%s", add->tele, sizeof(add->tele));
		add->next = NULL;
		p->next = add;
		p = p->next;

		printf("����0�Խ����������������������Լ���:");
		scanf_s("%d", &Judge);
	}

}

void Print(const pcon Con)
{
	if (Con->next == NULL)
	{
		printf("�б�Ϊ��!\n\n");
		return;
	}
	pcon p = Con;
	printf("����	�Ա�	����	�绰\n");
	while (p->next != NULL)
	{
		p = p->next;
		printf("%s	%s	%d	%s\n", p->name, p->sex, p->age, p->tele);
	}
}