#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// ���� ����
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

#define BLANK ' '

#define ESC 0x1b //  ESC ������ ����

#define SPECIAL1 0xe0 // Ư��Ű�� 0xe0 + key ������ �����ȴ�.
#define SPECIAL2 0x00 // keypad ��� 0x00 + key �� �����ȴ�.

#define UP  0x48 // Up key�� 0xe0 + 0x48 �ΰ��� ���� ���´�.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define Z 'z'


#define WIDTH 80
#define HEIGHT 30

int keep_moving = 1;
int Delay = 100; // 100 msec delay, �� ���� ���̸� �ӵ��� ��������.

void removeCursor(void);
void putheart(int x, int y);
void putboss(int x, int y);
void putshieldup(int x, int y);
void putshielddown(int x, int y);
void putshieldleft(int x, int y);
void putshieldright(int x, int y);
void deleteshield(int x, int y);
void gotoxy(int x, int y);
void textcolor(int fg_color, int bg_color);
void draw_box(int x1, int y1, int x2, int y2);
void displayhp(int x, int y, int hp);
void putarrow_up(int x, int y);
void putarrow_down(int x, int y);
void erase(int x, int y);

////////////////////////////////////////////////////////////////////main
void main() {
	static int playerx = 38, playery = 20;
	static int bossx = 31, bossy = 3;
	unsigned char ch = 0;
	int playerhp = 10, bosshp = 36, zcnt = 3;
	int shield = -1, reflect = 0;
	int oldx, oldy, newx, newy;
	newx = oldx = 38;
	newy = oldy = 10;

	removeCursor();
	putheart(playerx, playery);
	putboss(bossx, bossy);
	putshieldup(playerx, playery);

	while (1) {
		displayhp(2, 1, bosshp); // ���� hp ǥ��
		displayhp(2, 28, playerhp); // �÷��̾� hp ǥ��

		if (_kbhit() == 1) {  // Ű���尡 ������ ������
			ch = _getch(); // key ���� �д´�

			if (ch == ESC)// ���α׷� ����
				exit(1);

			if (ch == SPECIAL1 || ch == SPECIAL2) { // ���� Ư��Ű
				// ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = _getch();
				switch (ch) {
				case UP:
					shield = 0;
					putshieldup(playerx, playery);
					Sleep(Delay);
					break;
				case DOWN:
					shield = 1;
					putshielddown(playerx, playery);
					Sleep(Delay);
					break;
				case LEFT:
					shield = 2;
					putshieldleft(playerx, playery);
					Sleep(Delay);
					break;
				case RIGHT:
					shield = 3;
					putshieldright(playerx, playery);
					Sleep(Delay);
					break;
				}
			}
		}
		deleteshield(playerx, playery);

		if (ch == Z) { //ü�� ȸ�� 3ȸ
			if (playerhp < 10 && zcnt > 0) {
				playerhp++;
				zcnt--;
			}
		}

		if (playerhp == 0) { //���ӿ���
			printf("GAME OVER");
			exit(1);
		}

		//from up
		if (shield == 0 && oldy >= playery - 4 && oldy <= playery - 3) { //up���п�������
			reflect = 1;
			shield = -1;
		}

		if (reflect == 1) { //�ݻ�
			if (oldy <= playery - 11) {
				erase(oldx, oldy); // ������ ��ġ�� * �� �����
				bosshp--;
				reflect = 3; //���� ȭ��ǥ ���
			}
			else {
				newy = oldy - 1;
				erase(oldx, oldy); // ������ ��ġ�� * �� �����
				putarrow_down(newx, newy); // ���ο� ��ġ���� * �� ǥ���Ѵ�.

				oldx = newx; // ������ ��ġ�� ����Ѵ�.
				oldy = newy;
				Sleep(Delay); // Delay�� ���̸� �ӵ��� ��������.
			}
		}

		if (reflect == 0) {
			if (reflect == 0 && oldy == playery - 2) { //�÷��̾ ������
				erase(oldx, oldy); // ������ ��ġ�� * �� �����
				oldx = 28;
				oldy = 28;
				playerhp--;
				displayhp(2, 28, playerhp); // �÷��̾� hp ǥ��
				putheart(playerx, playery);
			}
			else if (reflect == 0 && oldx == 28 && oldy == 28) {
				erase(oldx, oldy);
			}
			else { //������
				newy = oldy + 1;
				erase(oldx, oldy); // ������ ��ġ�� * �� �����
				putarrow_up(newx, newy); // ���ο� ��ġ���� * �� ǥ���Ѵ�.

				oldx = newx; // ������ ��ġ�� ����Ѵ�.
				oldy = newy;
				Sleep(Delay); // Delay�� ���̸� �ӵ��� ��������.
			}
		}
	}
}

void removeCursor(void) { // Ŀ���� �Ⱥ��̰� �Ѵ�

	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void putheart(int x, int y) {
	gotoxy(x, y); //player
	textcolor(GREEN1, BLACK);
	printf("��");

	textcolor(GRAY2, BLACK); //player�� ���ΰ� �ִ� ����
	draw_box(x - 4, y - 2, x + 4, y + 2);
}

void putboss(int x, int y) {
	textcolor(WHITE, BLACK);
	gotoxy(x + 6, y); //boss
	printf("������");
	gotoxy(x + 7, y + 1);
	printf("�����");
	gotoxy(x + 6, y + 2);
	printf("������");
	gotoxy(x + 5, y + 3);
	printf("����  ��");
	gotoxy(x + 3, y + 4);
	printf("����");
	gotoxy(x + 2, y + 5);
	printf("����");
	gotoxy(x, y + 6);
	printf("����");
	gotoxy(x - 1, y + 7);
	printf("����");
	gotoxy(x, y + 8);
	printf("���");
}

void putshieldup(int x, int y) {
	gotoxy(x - 4, y - 3); //up
	textcolor(GREEN1, BLACK);
	printf("�ââââ�");
}

void putshielddown(int x, int y) {
	gotoxy(x - 4, y + 3); //down
	textcolor(GREEN1, BLACK);
	printf("�ââââ�");
}

void putshieldleft(int x, int y) {
	gotoxy(x - 6, y - 2); //down
	textcolor(GREEN1, BLACK);
	printf("��");
	gotoxy(x - 6, y - 1);
	printf("��");
	gotoxy(x - 6, y);
	printf("��");
	gotoxy(x - 6, y + 1);
	printf("��");
	gotoxy(x - 6, y + 2);
	printf("��");
}

void putshieldright(int x, int y) {
	gotoxy(x + 6, y - 2); //down
	textcolor(GREEN1, BLACK);
	printf("��");
	gotoxy(x + 6, y - 1);
	printf("��");
	gotoxy(x + 6, y);
	printf("��");
	gotoxy(x + 6, y + 1);
	printf("��");
	gotoxy(x + 6, y + 2);
	printf("��");
}

void deleteshield(int x, int y) {
	gotoxy(x - 4, y - 3); //up
	printf("          ");
	gotoxy(x - 4, y + 3); //down
	printf("          ");
	gotoxy(x - 6, y - 2); //left
	printf(" ");
	gotoxy(x - 6, y - 1);
	printf(" ");
	gotoxy(x - 6, y);
	printf(" ");
	gotoxy(x - 6, y + 1);
	printf(" ");
	gotoxy(x - 6, y + 2);
	printf(" ");
	gotoxy(x + 6, y - 2); //right
	printf(" ");
	gotoxy(x + 6, y - 1);
	printf(" ");
	gotoxy(x + 6, y);
	printf(" ");
	gotoxy(x + 6, y + 1);
	printf(" ");
	gotoxy(x + 6, y + 2);
	printf(" ");
}

void displayhp(int x, int y, int hp) {
	int i;

	gotoxy(x, y);
	textcolor(WHITE, BLACK);
	printf("HP ");
	textcolor(RED1, BLACK);
	for (i = 0; i < hp; i++) { //hp ��ŭ �簢�� ���
		printf("��");
	}
	for (i = 0; i <= hp; i++) { //hp ��ŭ �簢�� ���
		printf(" ");
	}
}

void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;

	for (x = x1; x <= x2; x++) { //���� 2
		gotoxy(x, y1);
		printf("%s", "-");
		gotoxy(x, y2);
		printf("%s", "-");
	}

	for (y = y1; y <= y2; y++) { //���� 2
		gotoxy(x1, y);
		printf("%s", "��");
		gotoxy(x2, y);
		printf("%s", "��");
	}
	gotoxy(x1, y1);
	printf("%s", "��");
	gotoxy(x2, y1);
	printf("%s", "��");
	gotoxy(x1, y2);
	printf("%s", "��");
	gotoxy(x2, y2);
	printf("%s", "��");
}

void gotoxy(int x, int y) { //���� ���ϴ� ��ġ�� Ŀ�� �̵�
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}

void textcolor(int fg_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void putarrow_up(int x, int y)
{
	gotoxy(x, y);
	printf("��");
}

void putarrow_down(int x, int y)
{
	gotoxy(x, y);
	printf("��");
}

void erase(int x, int y)
{
	gotoxy(x, y);
	putchar(BLANK);
}
