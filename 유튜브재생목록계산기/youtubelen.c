#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void question();
void start();
void easter_egg();

int main(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("ㅣ[유튜브 재생목록 길이 계산기]                                       ㅣ\n");
	printf("ㅣ모든 것이 귀찮은 당신에게 빠른 계산을 도와드립니다.                 ㅣ\n");
	printf("ㅣ                                                                    ㅣ\n");
	printf("ㅣ                                                                    ㅣ\n");
	printf("ㅣ[명령어] (대소문자 상관없음)                                        ㅣ\n");
	printf("ㅣS : START - 계산기를 실행합니다.                                    ㅣ\n");
	printf("ㅣQ : QUIT - 프로그램을 종료합니다.                                   ㅣ\n");
	printf("ㅣ                                                                    ㅣ\n");
	printf("ㅣ※잘못된 명령어를 입력하면 오류가 발생하오니 주의해주십시오.        ㅣ\n");
	printf("ㅣ※시간을 잘못 입력했을 경우,                                        ㅣ\n");
	printf("ㅣ잘못 입력한 값 만큼 -1을 곱하여 입력하시면 됩니다.                  ㅣ\n");
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	question();

	return 0;
}

void question() {
	char user;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\n명령어를 입력하세요: ");
	scanf(" %c", &user);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n");

	if (user == 'S' || user == 's')
		start();
	else if (user == 'Q' || user == 'q')
		exit(0);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("잘못된 명령어입니다.");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		question();

}

void start() {
	int i = 0, v = 0, total_s = 0;
	int uh = -1, um = -1, us = -1;
	int h = 0, m = 0, s = 0;
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("동영상의 개수를 입력하세요:"); //동영상 개수
	scanf(" %d", &v);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (v == 72)
		easter_egg();
	if (v >= 50) {
		printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //권유
		printf("동영상이 너무 많은 경우 이 사이트를 이용해보세요.\n");
		printf("아래 사이트에 접속한 후 \n재생목록의 링크를 복사하여 사이트에 붙여넣으세요.\n\n");
		printf("https://ytplaylist-len.herokuapp.com/");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("\n");
	}
	printf(" \nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //시간
	printf("[시간끼리 더하기] (더 이상 입력하지 않으려면 99 입력)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("예시) 1:23:34 면 1 입력 \n");
	for (i = 0; uh != 99; i++) {
		printf("재생목록의 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d", i+1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("번째 영상의 분, 초를 제외한\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("'시간'만 입력하세요: \n");
		scanf(" %d", &uh);
		if (uh == 99)
			h -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		h += uh;
	}
	printf(" \nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //분
	printf("[분끼리 더하기] (더 이상 입력하지 않으려면 99 입력)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("예시) 1:23:34 면 23 입력 \n");
	for (i = 0; um != 99; i++) {
		printf("재생목록의 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("번째 영상의 시간, 초를 제외한\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("'분'만 입력하세요: \n");
		scanf(" %d", &um);
		if (um == 99)
			m -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		m += um;
	}
	printf(" \nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //초
	printf("[초끼리 더하기] (더 이상 입력하지 않으려면 99 입력)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("예시) 1:23:34 면 34 입력 \n");
	for (i = 0; us != 99; i++) {
		printf("재생목록의 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("번째 영상의 시간, 분를 제외한\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("'초'만 입력하세요: \n");
		scanf(" %d", &us);
		if (us == 99)
			s -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		s += us;
	}
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //계산 결과
	printf("[계산 결과]\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("입력한 동영상의 개수: %d\n", v);
	printf("입력한 동영상의 총 길이는\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%d시간 : %d초\n", h, h*3600);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("%d분 : %d초\n", m, m*60);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("%d초 : %d초\n\n", s, s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	total_s = h * 3600 + m * 60 + s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("합계 : %d초\n\n", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("따라서 입력하신 총 재생목록의 길이는\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("%d시간", total_s / 3600); 
	total_s %= 3600; 
	printf("%d분", total_s / 60); 
	total_s %= 60;
	printf("%d초", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("입니다.\n\n");
	Sleep(1500);
	printf("계산기를 종료했습니다.\n");
	Sleep(1500);
	printf("다음 작업을 선택하실 수 있습니다.\n\n");
	Sleep(2000);
	main();
}

void easter_egg() {
	int i = 0, v = 0, total_s = 0;
	int uh = -1, um = -1, us = -1;
	int h = 0, m = 0, s = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("동영상이 너무 많은 경우 이 사이트를 이용해보세요.\n"); //권유
	printf("아래 사이트에 접속한 후 \n재생목록의 링크를 복사하여 사이트에 붙여넣으세요.\n\n");
	printf("https://ytplaylist-len.herokuapp.com/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf(" \nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //시간
	printf("[시간끼리 더하기] (더 이상 입력하지 않으려면 99 입력)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("예시) 1:23:34 면 1 입력 \n");
	for (i = 0; uh != 99; i++) {
		printf("재생목록의 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("번째 영상의 분, 초를 제외한\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("'시간'만 입력하세요: \n");
		scanf(" %d", &uh);
		if (uh == 99)
			h -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		h += uh;
	}
	printf(" \nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //분
	printf("[분끼리 더하기] (더 이상 입력하지 않으려면 99 입력)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("예시) 1:23:34 면 23 입력 \n");
	for (i = 0; um != 99; i++) {
		printf("재생목록의 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("번째 영상의 시간, 초를 제외한\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("'분'만 입력하세요: \n");
		scanf(" %d", &um);
		if (um == 99)
			m -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		m += um;
	}
	printf(" \nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //초
	printf("[초끼리 더하기] (더 이상 입력하지 않으려면 99 입력)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("예시) 1:23:34 면 34 입력 \n");
	for (i = 0; us != 99; i++) {
		printf("재생목록의 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("번째 영상의 시간, 분를 제외한\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("'초'만 입력하세요: \n");
		scanf(" %d", &us);
		if (us == 99)
			s -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		s += us;
	}
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //계산 결과
	printf("[계산 결과]\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("입력한 동영상의 개수: %d\n", v);
	printf("입력한 동영상의 총 길이는\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("%d시간 : %d초\n", h, h * 3600);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("%d분 : %d초\n", m, m * 60);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("%d초 : %d초\n\n", s, s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	total_s = h * 3600 + m * 60 + s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("합계 : %d초\n\n", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("따라서 입력하신 총 재생목록의 길이는\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("%d시간", total_s / 3600);
	total_s %= 3600;
	printf("%d분", total_s / 60);
	total_s %= 60;
	printf("%d초", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("입니다.\n\n");
	Sleep(1500);
	printf("계산기를 종료했습니다.\n");
	Sleep(1500);
	printf("다음 작업을 선택하실 수 있습니다.\n\n");
	Sleep(2000);
	main();
}