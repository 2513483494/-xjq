#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct _Friend { //dssdssss 8������
	int num;//���
	char name[16]; 	//����
	char sex[6];	//ϵ��
	int year;	//��У���
	char date[15];//��У���
	char area[23];//�о�����
	char info[101];//���
	char success[101];//���50������*2�ֽ�/����=100�ֽڣ��ټ�һ��'\0'��β����һ����101�ֽ�
	struct _Friend* next;
} Friend;

/*���������б�*/

//�˵�����
void menu(void);

//���ļ�������Ϣ�������ı�ȫ��ͷָ��ph
int readf(void);

//����ָ����ָ��ʾĳ����Ϣ
void pri(Friend* p);

//��ʾ������Ϣ pri��������
void display(Friend* head);

//�����������ļ�����
int create(void);

//�õ��ض���ŵĽṹ��ָ��
Friend* seeint(int num);

//�õ��ض������Ľṹ��ָ��
Friend* seechar(char* nam);

//������š���������У����Ϣ�������ظ�У����ţ�seechar() seeint() ��������
int search(void);

//����search()���ص����,��ͨ��seeint()�ҵ�ָ�룬�޸���Ϣ
int modify(void);

//ɾ������
int del(void);

//����
int sort();

//�ļ�����
int savef();

Friend* ph = NULL;


int main()
{
	ph = NULL;
	if (readf()) {
		printf("�ļ���ʼ���ɹ�,��ӭʹ��!\n\n\n\n");
	}
	else {
		printf("\n���ڱ���������Ŀ¼���fridata.txt����������!\n\n\n\n");
		getchar();
		return 0;
	}

	do {
		int choice;
		menu();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			system("cls");
			printf("\n=====�������У����Ϣ=====\n");
			if (ph == NULL) {
				printf("У����ϢΪ�գ��뷵�����˵������Ϣ\n");
			}
			else {
				display(ph);
			}
			break;
		case 2:
			system("cls");
			printf("\n=====���У����Ϣ=====\n");
			if (create()) {
				printf("��Ϣ�ɹ�����\n");
			}
			else {
				printf("��Ϣ�������\n");
			}
			break;
		case 3:
			system("cls");
			printf("\n=====����У����Ϣ=====\n");
			search();
			break;
		case 4:
			system("cls");
			printf("\n=====�޸�У����Ϣ=====\n");
			if (modify())break;
		case 5:
			system("cls");
			printf("\n=====ɾ��У����Ϣ=====\n");
			if (del()) {
				printf("\nɾ���ɹ���\n");
				break;
			}
			else { //bug
				printf("\n�޴������Ϣ��\n");
				break;
			}
		case 6:
			system("cls");
			printf("\n=====�������������=====\n");
			if (sort()) {
				printf("ð������ɹ���\n");
			}
			else {
				printf("������С��2���޷�����ð������");
			}
			break;
		case 0:
			system("cls");
			printf("\n=====����У����Ϣ=====\n\n");
			if (savef()) {
				printf("����ɹ�\n\n");
			}
			else {
				printf("����ʧ��\n\n");
			}
			printf("��ӭ�´�ʹ��,�ټ�!\n");
			if (!ph) {	//�ͷ��ڴ�
				free(ph);
			}
			printf("\n�������������\n");
			getch();
			return 0;

		default:
			system("cls");
			printf("\n�������,������ѡ�����!\n");
			break;
		}

		while (1) {
			printf("\n��������ɷ������˵���\n");
			if (getch()) break;
		}
		system("cls");
	} while (1);

}

//�˵�
void menu()
{
	printf("************************************************\n");
	printf("*************�����ܳ�У�ѹ���ϵͳ*************\n");
	printf("************************************************\n\n");
	printf("\n\n��ѡ�����:\n\n");
	printf("1.���У����Ϣ.\n");
	printf("2.���У����Ϣ.\n");
	printf("3.����У����Ϣ.\n");
	printf("4.�޸�У����Ϣ.\n");
	printf("5.ɾ��У����Ϣ.\n");
	printf("6.�������������.\n");
	printf("0.�˳���������Ϣ.\n");
	printf("\n  ���ѡ���ǣ�");
}





//���ļ�������Ϣ�������ı�ȫ��ͷָ��ph
int readf()
{
	FILE* pf;
	Friend* p, * tail;
	pf = fopen("fridata.txt", "r");
	if (!pf) {
		return 0; //ʧ�ܺ���ִ�����²���
	}
	fgetc(pf);//ָ����λ
	while (!feof(pf)) {
		p = (Friend*)malloc(sizeof(Friend));
		fscanf(pf, "%d%s%s%d%s%s%s%s", &p->num, p->name, p->sex, &p->year,
			p->date, p->area, p->info, p->success);
		//������Ϣ
		if (ph == NULL) {
			ph = p;
			tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}
		fgetc(pf);
		fgetc(pf);
		if (feof(pf)) {
			tail->next = NULL;
		}
	}
	if (!pf) {
		fclose(pf);//�ر��ļ�

	}
	return 1;//�ɹ�
}

//����ָ����ʾĳ����Ϣ
void pri(Friend* p)
{
	if (p) {
		printf("���:%d\t����:%s\tϵ��:%s\t��У���:%d\t��������:%s\t�绰:%s\t�����ʼ�:%s\t��ַ:%s\t\n",
			p->num, p->name, p->sex, p->year, p->date, p->area, p->info, p->success);
	}
	else {
		printf("������Ϣ��Ч");
	}
	return;
}


//��ʾ������Ϣ pri��������
void display(Friend* head)
{
	Friend* p;
	p = head;//���ı䴫��ָ���ֵ
	while (1) {
		pri(p);
		if (p->next) {
			p = p->next;
		}
		else {
			break;
		}

	}
	return;
}

//�õ��ض���ŵĽṹ��ָ��
Friend* seeint(int num)
{
	Friend* p;
	p = ph;
	while (p && (p->num != num)) {
		p = p->next;
	}
	return p;
}

//�õ��ض���ŵĽṹ��ָ��
Friend* seechar(char* nam)
{
	Friend* p;
	p = ph;
	while (p && strcmp(nam, p->name)) {
		p = p->next;
	}
	return p;
}



int create()
{
	Friend* p, * head, * tail;//��ʱ����ָ�롢ͷָ�롢βָ��
	int a = 1;
	head = NULL;
	do {
		p = (Friend*)malloc(sizeof(Friend));
		printf("\n���������:");
		scanf("%d", &p->num);
		//�жϸü�¼�Ƿ����
		if (seeint(p->num)) {
			printf("���Ϊ%d�ļ�¼�Ѵ���!\n", p->num);
			return 0;
		}
		printf("����������:");
		scanf("%s", p->name);
		printf("������ϵ��:");
		scanf("%s", p->sex);
		printf("��������У���:");
		scanf("%d", &p->year);
		printf("������������£�����1998��12��21�գ�:");
		scanf("%s", p->date);
		printf("������绰:");
		scanf("%s", p->area);
		printf("����������ʼ���ַ:");
		scanf("%s", p->info);
		printf("�������ַ:");
		scanf("%s", p->success);
		if (head == NULL) {
			head = p;
			tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}
		tail->next = NULL;
		printf("\n����0�س���ֹ����������ֵ�س�����\n");
		scanf("%d", &a);
	} while (a != 0);
	//����ph��head��״̬����������
	if (head) {
		if (ph) {
			tail->next = ph;
			ph = head;
			return 1;//ph��head����Ϊ��ʱ���ӣ�����1
		}
		else {
			ph = head;
			return 1;//phΪ�ա�head��Ϊ��ʱ��ֵ������1
		}
	}
	else {
		return 0;//ph��headΪ��ʱ����0��ph���ա�headΪ��ʱ����0
	}
}




//������š���������У����Ϣ�������ظ�У�����  seechar seeint ��������
int search()
{
	Friend* p;
	int m = 0, n;
	char nam[16];
	while (m != 1 && m != 2) {
		printf("\n\n��������Լ�����\n1.����Ų���\n2.����������\n");
		scanf("%d", &m);
	}
	if (m == 1) {
		printf("������Ҫ���������:");
		scanf("%d", &n);
		if (seeint(n)) {
			pri(seeint(n));
		}
		else {
			printf("���޴���");
		}
	}
	if (m == 2) {
		printf("������Ҫ����������:");
		scanf("%s", nam);
		if (seechar(nam)) {
			pri(seechar(nam));
		}
		else {
			printf("���޴���");
		}
	}/*Ϊ����modify��׼�� */
	if (seeint(n)) {
		p = seeint(n);
		return p->num;
	}
	if (seechar(nam)) {
		p = seechar(nam);
		return p->num;
	}
}


int modify()
{
	int choice; //�û�ѡ�����
	Friend* p = seeint(search());
	if (p == NULL) {
		printf("�����ڴ���ŵļ�¼!\n");
		return 1;
	}
	printf("0.�޸����.\n");
	printf("1.�޸�����.\n");
	printf("2.�޸�ϵ��.\n");
	printf("3.�޸���У���.\n");
	printf("4.�޸ĳ�������.\n");
	printf("5.�޸ĵ绰.\n");
	printf("6.�޸ĵ����ʼ���ַ:.\n");
	printf("7.�޸ĵ�ַ.\n");
	printf("��ѡ��Ҫ�޸ĵ���Ϣ:");
	scanf("%d", &choice);
	switch (choice) {
	case 0:
		printf("���������:");
		scanf("%d", &p->num);
		break;
	case 1:
		printf("����������:");
		scanf("%s", p->name);
		break;
	case 2:
		printf("������ϵ��:");
		scanf("%s", p->sex);
		break;
	case 3:
		printf("��������У���:");
		scanf("%d", &p->year);
		break;
	case 4:
		printf("������������£�����1998��12��21�գ�:");
		scanf("%s", p->date);
		break;
	case 5:
		printf("������绰:");
		scanf("%s", p->area);
		break;
	case 6:
		printf("����������ʼ���ַ:");
		scanf("%s", p->info);
		break;
	case 7:
		printf("�������ַ:");
		scanf("%s", p->success);
		break;
	default:
		printf("�������������ѡ�����!\n");
	}
	return 1;
}

int del()
{
	Friend* see, * p, * pre;//pΪ��Ӧ��ŵ�ָ�룬pre�Ƕ�Ӧ��ŵ�ǰһ����ָ��
	int num;
	printf("������Ҫɾ����Ϣ�����:\n");
	scanf("%d", &num);
	if (!seeint(num)) {
		return 0;
	}
	p = ph;//��ͷ��ʼ����
	if (!p) return 0;//����Ϊ�����˳�
	//��һ��ΪҪɾ������ɾ������
	if (p->num == num) {
		if (!p->next) {
			ph = NULL;
			free(p);
			return 1;
		}
		else {
			ph = p->next;
			free(p);
			return 1;
		}
	}
	//�ڶ����Լ�֮��ΪҪɾ������ɾ������
	while (p->num != num) {
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	free(p);
	return 1;
}

int sort()
{
	Friend* c = ph, * head, * prr, * pre, * p, * temp;
	int n, count, i;
	while (c) {
		count++;
		c = c->next;
	}
	if (count <= 1) {
		return 0;
	}//�����������ż���
	head = (Friend*)malloc(sizeof(Friend));
	head->next = ph;//�������ͷ���ӿս��
	n = count * (count - 1) / 2;//��������������
	for (i = 1; i <= n; i++) {
		prr = head;//prr���ڵ�һ����� ��Ϊ�գ�
		pre = head->next;	//pre���ڵڶ������
		p = head->next->next;//p���ڵ��������
		while (1) {
			//�Ƚ�pre��ָ��p��ָ�Ĵ�С����������
			if ((pre->num) > (p->num)) {
				temp = p->next;
				prr->next = p;
				p->next = pre;
				pre->next = temp;
				//�ص�ԭ����˳��
				temp = pre;
				pre = p;
				p = temp;
			}

			//����ָ����λ
			if (!p->next) break;//�������һ���������ֹ
			p = p->next;
			pre = pre->next;
			prr = prr->next;
		}

	}
	ph = head->next;//ɾ���ս��
	free(head);
	printf("���������Ϊ%d,\n", count);
	return 1;
}


//���ڴ��е���Ϣ�����ļ�
int savef()
{
	FILE* pf;
	Friend* p;
	pf = fopen("fridata.txt", "w");
	if (!pf) {
		return 0; //ʧ�ܺ���ִ������
	}
	p = ph;//��ͷ��ʼ
	while (p) {
		fprintf(pf, " %d\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t", p->num, p->name,
			p->sex, p->year, p->date, p->area, p->info, p->success);
		p = p->next;
	}
	if (!pf) {
		fclose(pf);
	}
	return 1;
}

