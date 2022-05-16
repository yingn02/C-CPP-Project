#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// 색상 정의
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

#define ESC 0x1b //  ESC 누르면 종료

#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.

#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define Z 'z'


#define WIDTH 80
#define HEIGHT 30

int keep_moving = 1;
int Delay = 100; // 100 msec delay, 이 값을 줄이면 속도가 빨라진다.

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
		displayhp(2, 1, bosshp); // 보스 hp 표시
		displayhp(2, 28, playerhp); // 플레이어 hp 표시

		if (_kbhit() == 1) {  // 키보드가 눌려져 있으면
			ch = _getch(); // key 값을 읽는다

			if (ch == ESC)// 프로그램 종료
				exit(1);

			if (ch == SPECIAL1 || ch == SPECIAL2) { // 만약 특수키
				// 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
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

		if (ch == Z) { //체력 회복 3회
			if (playerhp < 10 && zcnt > 0) {
				playerhp++;
				zcnt--;
			}
		}

		if (playerhp == 0) { //게임오버
			printf("GAME OVER");
			exit(1);
		}

		//from up
		if (shield == 0 && oldy >= playery - 4 && oldy <= playery - 3) { //up방패에닿으면
			reflect = 1;
			shield = -1;
		}

		if (reflect == 1) { //반사
			if (oldy <= playery - 11) {
				erase(oldx, oldy); // 마지막 위치의 * 를 지우고
				bosshp--;
				reflect = 3; //다음 화살표 대기
			}
			else {
				newy = oldy - 1;
				erase(oldx, oldy); // 마지막 위치의 * 를 지우고
				putarrow_down(newx, newy); // 새로운 위치에서 * 를 표시한다.

				oldx = newx; // 마지막 위치를 기억한다.
				oldy = newy;
				Sleep(Delay); // Delay를 줄이면 속도가 빨라진다.
			}
		}

		if (reflect == 0) {
			if (reflect == 0 && oldy == playery - 2) { //플레이어에 닿으면
				erase(oldx, oldy); // 마지막 위치의 * 를 지우고
				oldx = 28;
				oldy = 28;
				playerhp--;
				displayhp(2, 28, playerhp); // 플레이어 hp 표시
				putheart(playerx, playery);
			}
			else if (reflect == 0 && oldx == 28 && oldy == 28) {
				erase(oldx, oldy);
			}
			else { //내려옴
				newy = oldy + 1;
				erase(oldx, oldy); // 마지막 위치의 * 를 지우고
				putarrow_up(newx, newy); // 새로운 위치에서 * 를 표시한다.

				oldx = newx; // 마지막 위치를 기억한다.
				oldy = newy;
				Sleep(Delay); // Delay를 줄이면 속도가 빨라진다.
			}
		}
	}
}

void removeCursor(void) { // 커서를 안보이게 한다

	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void putheart(int x, int y) {
	gotoxy(x, y); //player
	textcolor(GREEN1, BLACK);
	printf("♥");

	textcolor(GRAY2, BLACK); //player를 가두고 있는 상자
	draw_box(x - 4, y - 2, x + 4, y + 2);
}

void putboss(int x, int y) {
	textcolor(WHITE, BLACK);
	gotoxy(x + 6, y); //boss
	printf("■■■■■");
	gotoxy(x + 7, y + 1);
	printf("■■■■");
	gotoxy(x + 6, y + 2);
	printf("■■■■■");
	gotoxy(x + 5, y + 3);
	printf("■■■  ■");
	gotoxy(x + 3, y + 4);
	printf("■■■");
	gotoxy(x + 2, y + 5);
	printf("■■■");
	gotoxy(x, y + 6);
	printf("■■■");
	gotoxy(x - 1, y + 7);
	printf("■■■");
	gotoxy(x, y + 8);
	printf("■■");
}

void putshieldup(int x, int y) {
	gotoxy(x - 4, y - 3); //up
	textcolor(GREEN1, BLACK);
	printf("▣▣▣▣▣");
}

void putshielddown(int x, int y) {
	gotoxy(x - 4, y + 3); //down
	textcolor(GREEN1, BLACK);
	printf("▣▣▣▣▣");
}

void putshieldleft(int x, int y) {
	gotoxy(x - 6, y - 2); //down
	textcolor(GREEN1, BLACK);
	printf("▣");
	gotoxy(x - 6, y - 1);
	printf("▣");
	gotoxy(x - 6, y);
	printf("▣");
	gotoxy(x - 6, y + 1);
	printf("▣");
	gotoxy(x - 6, y + 2);
	printf("▣");
}

void putshieldright(int x, int y) {
	gotoxy(x + 6, y - 2); //down
	textcolor(GREEN1, BLACK);
	printf("▣");
	gotoxy(x + 6, y - 1);
	printf("▣");
	gotoxy(x + 6, y);
	printf("▣");
	gotoxy(x + 6, y + 1);
	printf("▣");
	gotoxy(x + 6, y + 2);
	printf("▣");
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
	for (i = 0; i < hp; i++) { //hp 만큼 사각형 출력
		printf("■");
	}
	for (i = 0; i <= hp; i++) { //hp 만큼 사각형 출력
		printf(" ");
	}
}

void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;

	for (x = x1; x <= x2; x++) { //가로 2
		gotoxy(x, y1);
		printf("%s", "-");
		gotoxy(x, y2);
		printf("%s", "-");
	}

	for (y = y1; y <= y2; y++) { //세로 2
		gotoxy(x1, y);
		printf("%s", "┃");
		gotoxy(x2, y);
		printf("%s", "┃");
	}
	gotoxy(x1, y1);
	printf("%s", "┏");
	gotoxy(x2, y1);
	printf("%s", "┓");
	gotoxy(x1, y2);
	printf("%s", "┗");
	gotoxy(x2, y2);
	printf("%s", "┛");
}

void gotoxy(int x, int y) { //내가 원하는 위치로 커서 이동
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API 함수입니다. 이건 알필요 없어요
}

void textcolor(int fg_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void putarrow_up(int x, int y)
{
	gotoxy(x, y);
	printf("↓");
}

void putarrow_down(int x, int y)
{
	gotoxy(x, y);
	printf("↑");
}

void erase(int x, int y)
{
	gotoxy(x, y);
	putchar(BLANK);
}
