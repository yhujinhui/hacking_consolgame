
#include"Choice.h"
Game_Play *gp = new Game_Play();
void writereview() {

	system("cls");
	int key=0;
	gotoxy(15, 13);
	cout << "���� �����ڿ��� ����� �Ѹ��� : ";
	FILE* review;
	fopen_s(&review, "review.txt", "w");
	string write;
	getline(cin, write);
	char *c = new char[write.length() + 1];
	strcpy(c, write.c_str());
	fputs(c, review);
	delete[] c;
	fclose(review);
	//gotoxy(20, 37);
	
		readreview();
	
	//return name;
}
void readreview() {
	int key=0;
	system("cls");
	//gotoxy(30, 5);
	gotoxy(20, 37);
	cout << "�������� �ƹ�Ű�� ��������...";
	
	char review[50];
	char name[30];
	FILE* re=fopen("review.txt", "r");
	FILE* na=fopen("name.txt", "r");
	//string write;
	//getline(cin, write);
	fgets(review, sizeof(review), re);
	fgets(name, sizeof(name), na);

	
	gotoxy(30, 5);
	cout << name<<"���� ����� �Ѹ��� : ";
	gotoxy(30, 7);
	cout << review<<"\n";	
	fclose(re);
	fclose(na);

	if (key == _getch()) {
		title();
		title_change();
	}
}

int title_menuchoice() {
	int x = 52, y = 18;
	gotoxy(x - 2, y);
	setcolor(7, 0);
	cout << "> ���� ����" << endl;// 18
	gotoxy(x, y + 2);
	cout << "���� ���" << endl;//20
	gotoxy(x, y + 4);
	cout << "���丮 ����" << endl;//22
	gotoxy(x, y + 6);
	cout << "�����ڿ��� ����� �Ѹ���" << endl;//22
	gotoxy(x, y + 8);
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
			if (y < 26) {
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

int intro_skip(int i,int t) {

	int x = 100, y = 30;
	gotoxy(x - 2, y);
	cout << "> skip" << endl;//25
	//while (1) {//����

	int n;
	
	while (1) {
		if (n = keycontrol()) {
			if (n == ENTER) {
				//cout << "T" << endl;
				return 1;
			}
		}
		Sleep(t);
		//if (n != keycontrol()) {
			cout << "1";
			return 0;
		//}
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
	
	while (1)
	{
		title();
		int title_menucode = title_menuchoice();
		if (title_menucode == 0) {//���� ����
			//gp->game_screen();
			gp->ending3();
		}
		if (title_menucode == 2) {//���� ���
			gamerule();
		}
		if (title_menucode == 4) {//���丮 ����
			system("cls");
			intro1();
		}
		if (title_menucode == 6) {//��ŷ����
			system("cls");
			writereview();
		}
		if (title_menucode == 8) {//��ŷ����
			exit(0);
		}
		system("cls");
	}
}
//title���� ��ȯ

int intro_change(int i,int t) {
	while (1)
	{
		int intro = intro_skip(i,t);

		if (intro == 1) {//���� ����
			cout << 1;
			title();
			title_change();
		}
		else if (intro == 0) {
			cout << "1";
			break;
		}
		return intro;
	}
}
//��Ʈ�� ��ŵ���� ��ȯ

int rule_menuchoice() {
	int x = 100, y = 25;
	gotoxy(x - 2, y);
	cout << "> ���� ����" << endl;//25
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
//////////���ӹ�� �޴� ����
void rule_change() {
	//Game_Play *gp=new Game_Play();
	int rule_menucode = rule_menuchoice();
	while (1)
	{

		if (rule_menucode == 0) {//���� ����
			break;
		}
		if (rule_menucode == 2) {//���� ����
			gp->game_screen();
			break;
		}
	}

}
//���ӹ��ȭ�鿡�� ��ȯ
void gamerule()
{
	system("cls");
	setcolor(7, 0);
	gotoxy(50, 6);
	cout << "<���� ���>" << endl;
	gotoxy(30, 12);
	cout << "1. ������� 1���� 9������ ���� �� ������!" << endl;
	gotoxy(30, 14);
	cout << "2. �������� ����ִ� ���� ��� ��й�ȣ�� ���߼���." << endl;
	gotoxy(30, 16);
	cout << "3. 1���� ������ �̷���� 5���� ��й�ȣ�� ���߸� 1�ܰ� ����!" << endl;
	gotoxy(30, 18);
	cout << "4. 2���� ������ �̷���� 5���� ��й�ȣ�� ���߸� 1�ܰ� ����!" << endl;
	gotoxy(30, 20);
	cout << "5. 3���� ������ �̷���� 3���� ��й�ȣ�� ���߸� 3�ܰ� ����!" << endl;
	gotoxy(30, 22);
	cout << "6. �ܰ谡 ���������� ��й�ȣ�� ���� ��������ϴ�!" << endl;

	rule_change();
}
//���� ���

void intro1() {
	int key;
	string name = Info_Input();
	system("cls");
	gotoxy(27, 10);
	cout << "���������� ������� ����ϰ� �ູ�ϰ� ��� �ִ� ��� ��," << endl;
	gotoxy(35, 12);
	cout << "��ħ ���� �� �տ� ���� �� ���� �� �־���." << endl;
	//Sleep(3000);
	if(key=_getch())
		intro2(name);
}
string Info_Input() {
	
	gotoxy(35, 13);
	cout << "�̸��� �Է����ּ���: ";
	FILE* namefile;
	fopen_s(&namefile, "name.txt", "w");
	string name;
	getline(cin, name);
	char *c = new char[name.length() + 1];
	strcpy(c, name.c_str());
	fputs(c, namefile);
	delete[] c;
	fclose(namefile);
	return name;
}
void intro2(string name) {
	system("cls");
	int key;
	gotoxy(24, 8);
	cout << "To. " << name << endl;
	gotoxy(24, 10);
	//setcolor(9, 0);
	cout << "�̸� " << name << ", ���� 17��, �̸������������а���б� ���� ��," << endl;
	gotoxy(24, 12);
	cout << "�� �ʸ� 5�� ������ �˰� �־���." << endl;
	gotoxy(24, 14);
	cout << "�ʿ� ���� ������ �� ������ �ð��� ��� ���� �����ϵ��� ����." << endl;
	gotoxy(24, 16);
	cout << "�� ��, ���� ������ ���� ū ���� �� �ɷ� �˰� �ִ�. ���� ���� ���� �ʳ�?" << endl;
	gotoxy(24, 18);
	cout << "���� �ϴ� ������ �޾Ƶ帰�ٸ� ���� �����ְڴ�. " << endl;
	gotoxy(24, 20);
	cout << "���� ���� �������� �����ε� �� ���� ���� ǳ���ϰ� �쵵�� �����ָ�" << endl;
	gotoxy(55, 22);
	cout << "��" << endl;
	gotoxy(55, 24);
	cout << "��" << endl;
	gotoxy(55, 26);
	cout << "��" << endl;
	if (key = _getch())
		intro3();
}
void intro3() {	
	system("cls");
	time_t timer;
	struct tm *t;
	timer = time(NULL);
	t = localtime(&timer);
	int key;
	gotoxy(18, 8);
	cout << "�� ������ �ٷ� �̸������������а���б��� ������ ��ŷ�϶�°Ŵ�. " << endl;
	gotoxy(18, 10);
	cout << "��Ȯ�� �����ڸ�"<<t->tm_mon+1<<"�� "<< t->tm_mday<<"���� ���賯 ����. " << endl;
	gotoxy(18, 12);
	cout << "��� �л����� ������ ���� ���ϵ��� ��ŷ���ֱ⸸ �ϸ� �ȴ�." << endl;
	gotoxy(18, 14);
	cout << "��� �ʸ� �̸������������а���б��� �ٴϰ� �� �͵� " << endl;
	gotoxy(18, 16);
	cout << t->tm_mon+1<<"�� "<<t->tm_mday<<"�� ���賯�� ��ŷ�� �ϱ� ���� ���� ������ ��ȹ�̶�� �� �� ����, ��������" << endl;
	gotoxy(18, 18);
	cout << "������ ���� ���̴�. �� �����غ��Ŷ�. " << endl;
	gotoxy(18, 20);
	cout << "���� �������� ���� �������� ���谡 �޷ȴٴ� �͵� �� ������ �����Ѵ�. " << endl;
	gotoxy(18, 22);
	cout << "�׷� ���� ������ " << endl;
	gotoxy(80, 24);
	cout << "From. ��ȣ��";
	if (key = _getch())
		intro4();
}
void intro4() {
	system("cls");
	int key;
	time_t timer;
	struct tm *t;
	timer = time(NULL);
	t = localtime(&timer);
	//setcolor(7, 0);
	gotoxy(45, 10);
	cout << "������ �ʴٰ� �����ߴ�. " << endl;
	gotoxy(19, 12);
	cout << "�׷��� �ᱹ �̸������������а���б��� ������ ��ŷ�ϱ�� �Ͽ���. �����١� " << endl;
	gotoxy(30, 14);
	cout << "�ٷ� ������ "<<t->tm_mon+1<<"�� "<<t->tm_mday<<"��, ������ ��ŷ�ϱ� 5�� ���̴١� " << endl;
	if (key = _getch())
	{

		while (1)
		{
			title();
			title_change();
			system("cls");
		}
	}
}
void title() {
	int x = 13, y = 6;
	system("cls");
	setcolor(1, 0);
	gotoxy(x, y);
	cout << "��    ��" << endl;
	gotoxy(x, y + 1);
	cout << "��    ��" << endl;
	gotoxy(x, y + 2);
	cout << "�����" << endl;
	gotoxy(x, y + 3);
	cout << "��    ��" << endl;
	gotoxy(x, y + 4);
	cout << "��    ��" << endl;
	////////////////////////////
	gotoxy(x + 8, y);
	cout << "    ��" << endl;
	gotoxy(x + 8, y + 1);
	cout << "  ��  ��" << endl;
	gotoxy(x + 8, y + 2);
	cout << "  ����" << endl;
	gotoxy(x + 8, y + 3);
	cout << "  ��  ��" << endl;
	gotoxy(x + 8, y + 4);
	cout << "  ��  ��" << endl;
	////////////////////////////
	gotoxy(x + 16, y);
	cout << "  ����" << endl;
	gotoxy(x + 16, y + 1);
	cout << "  ��" << endl;
	gotoxy(x + 16, y + 2);
	cout << "  ��" << endl;
	gotoxy(x + 16, y + 3);
	cout << "  ��" << endl;
	gotoxy(x + 16, y + 4);
	cout << "  ����" << endl;
	////////////////////////////
	gotoxy(x + 24, y);
	cout << "  ��" << endl;
	gotoxy(x + 24, y + 1);
	cout << "  ��  ��" << endl;
	gotoxy(x + 24, y + 2);
	cout << "  ���" << endl;
	gotoxy(x + 24, y + 3);
	cout << "  ���" << endl;
	gotoxy(x + 24, y + 4);
	cout << "  ��  ��" << endl;
	////////////////////////////
	gotoxy(x + 32, y);
	cout << "  ��" << endl;
	gotoxy(x + 32, y + 1);
	cout << "  ��" << endl;
	gotoxy(x + 32, y + 2);
	cout << "  ��" << endl;
	gotoxy(x + 32, y + 3);
	cout << "  ��" << endl;
	gotoxy(x + 32, y + 4);
	cout << "  ��" << endl;

	gotoxy(x + 36, y);
	cout << "  ��    ��" << endl;
	gotoxy(x + 36, y + 1);
	cout << "  ��    ��" << endl;
	gotoxy(x + 36, y + 2);
	cout << "  ���  ��" << endl;
	gotoxy(x + 36, y + 3);
	cout << "  ��  ���" << endl;
	gotoxy(x + 36, y + 4);
	cout << "  ��    ��" << endl;
	gotoxy(x + 46, y);
	cout << "    ���" << endl;
	gotoxy(x + 46, y + 1);
	cout << "  ��" << endl;
	gotoxy(x + 46, y + 2);
	cout << "  �����" << endl;
	gotoxy(x + 46, y + 3);
	cout << "  ��    ��" << endl;
	gotoxy(x + 46, y + 4);
	cout << "  ���  ��" << endl;

	gotoxy(x + 62, y);
	cout << "    ���" << endl;
	gotoxy(x + 62, y + 1);
	cout << "  ��" << endl;
	gotoxy(x + 62, y + 2);
	cout << "  �����" << endl;
	gotoxy(x + 62, y + 3);
	cout << "  ��    ��" << endl;
	gotoxy(x + 62, y + 4);
	cout << "  ���  ��" << endl;

	gotoxy(x + 72, y);
	cout << "  �����" << endl;
	gotoxy(x + 72, y + 1);
	cout << "  ��    ��" << endl;
	gotoxy(x + 72, y + 2);
	cout << "  ��    ��" << endl;
	gotoxy(x + 72, y + 3);
	cout << "  ��    ��" << endl;
	gotoxy(x + 72, y + 4);
	cout << "  �����" << endl;
	gotoxy(x + 84, y);
	cout << "  ��" << endl;
	gotoxy(x + 84, y + 1);
	cout << "  ��" << endl;
	gotoxy(x + 84, y + 2);
	cout << "  ��" << endl;
	gotoxy(x + 84, y + 3);
	cout << "   " << endl;
	gotoxy(x + 84, y + 4);
	cout << "  ��" << endl;
	//gotoxy(20, 10);//��

}//
//hacking go!
///////////////////////////////////////////////////////////////
int cnt1 = 0;//game_DO ī��Ʈ




