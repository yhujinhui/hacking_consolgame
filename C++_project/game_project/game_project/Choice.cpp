#include"main.h"
#include"Choice.h"
#include"Common.h"
#include"Game_Rule.h"
int title_menuchoice() {
	int x = 52, y = 18;
	gotoxy(x - 2, y);
	setcolor(6, 0);
	cout << "> ���� ����" << endl;//18
	//setcolor(7, 0);
	gotoxy(x, y + 2);
	cout << "���� ���" << endl;//20
//	setcolor(7, 0);
	gotoxy(x, y + 4);
	cout << "���� ����" << endl;//22

	while (1) {//����
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (y > 18) {//y�� 22���� 18���� �̵�

				gotoxy(x - 2, y);
				cout << " ";
				y -= 2;
				gotoxy(x - 2, y);
				cout << ">";

			}
			break;
		}
		case DOWN: {
			if (y < 22) {
				gotoxy(x - 2, y);
				cout << " ";
				y += 2;
				gotoxy(x - 2, y);
				cout << ">";
			}
			break;
		}
		case ENTER: {
			return y - 18;//0 2 4
		}
		}
	}
}
//�޴� ����
int rule_menuchoice() {
	int x = 100, y = 25;
	gotoxy(x - 2, y);
	cout << "> �� ����" << endl;//25
	gotoxy(x, y + 2);
	cout << "���� ����" << endl;//27

	while (1) {//����
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (y > 25) {//y�� 22���� 18���� �̵�

				gotoxy(x - 2, y);
				cout << " ";
				y -= 2;
				gotoxy(x - 2, y);
				cout << ">";

			}
			break;
		}
		case DOWN: {
			if (y < 27) {
				gotoxy(x - 2, y);
				cout << " ";
				y += 2;
				gotoxy(x - 2, y);
				cout << ">";
			}
			break;
		}
		case ENTER: {
			return y - 25;//0 2
		}
		}
	}
}
//���ӹ�� �޴� ����
int intro_skip() {
	int x = 100, y = 30;
	gotoxy(x - 2, y);
	cout << "> skip" << endl;//25

	while (1) {//����
		int n = keycontrol();
		
		if(n=ENTER) {
			intro_change();
			return 0;//0 
		}
	}
}
//��Ʈ�� ��ŵ ����
int keycontrol() {
	char temp = _getch();
	switch (temp) {
	case 72: return UP;//����Ű ��
	case 80: return DOWN;//����Ű �Ʒ�
	case 13: return ENTER;//����
	}
}
//����Ű �� ���� �ƽ�Ű�ڵ�
void title_change() {
	int title_menucode = title_menuchoice();
	if (title_menucode == 0) {//���� ����

	}
	if (title_menucode == 2) {//���� ���
		gamerule();
	}
	if (title_menucode == 4) {//���� ����
		exit(0);
	}
}
//title���� ��ȯ
void rule_change() {
	int rule_menucode = rule_menuchoice();
	if (rule_menucode == 0) {//������
		
	}
	if (rule_menucode == 2) {//���� ����
		system("cls");
	}

	system("pause>null");//�ƹ�Ű�� �����ּ���(����)
}
//���ӹ��ȭ�鿡�� ��ȯ
void intro_change() {
	int intro = intro_skip();
	if (intro == 0) {//skip
		title();
		title_menuchoice();
	}

	system("pause>null");//�ƹ�Ű�� �����ּ���(����)
}
//��Ʈ�� ��ŵ���� ��ȯ