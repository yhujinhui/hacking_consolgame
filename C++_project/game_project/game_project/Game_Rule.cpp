#include "Game_Rule.h"
#include "Common.h"
#include "Choice.h"
void gamerule() {
	system("cls");
	setcolor(7, 0);
	gotoxy(50, 6);
	cout << "���� ���" << endl;
	gotoxy(30, 12);
	cout << "1. ������� 1���� 9������ ���� �� ������!" << endl;
	gotoxy(30, 14);

	cout << "2. �������� ����ִ� ���� ������ѽð� �ȿ� ��й�ȣ�� ���߼���." << endl;
	gotoxy(30, 16);
	cout << "3. ���ѽð� �ȿ� 5���� ��й�ȣ�� ���߸� 1�ܰ� ����!" << endl;
	gotoxy(30, 18);
	cout << "4. ���ѽð� �ȿ� 8���� ��й�ȣ�� ���߸� 2�ܰ� ����!" << endl;
	gotoxy(30, 20);
	cout << "5. ���ѽð� �ȿ� 10���� ��й�ȣ�� ���߸� 3�ܰ� ����!" << endl;
	gotoxy(30, 22);
	cout << "6. �ܰ谡 ���������� ��й�ȣ�� ���� ��������ϴ�!" << endl;

	rule_change();
}
//���� ���