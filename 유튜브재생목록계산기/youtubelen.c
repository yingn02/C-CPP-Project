#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void question();
void start();
void easter_egg();

int main(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	printf("太[嶸ぅ粽 營儅跡煙 望檜 啗骯晦]                                       太\n");
	printf("太賅萇 匙檜 敝雛擎 渡褐縑啪 緒艇 啗骯擊 紫諦萄董棲棻.                 太\n");
	printf("太                                                                    太\n");
	printf("太                                                                    太\n");
	printf("太[貲滄橫] (渠模僥濠 鼻婦橈擠)                                        太\n");
	printf("太S : START - 啗骯晦蒂 褒чм棲棻.                                    太\n");
	printf("太Q : QUIT - Щ煎斜極擊 謙猿м棲棻.                                   太\n");
	printf("太                                                                    太\n");
	printf("太≦澀跤脹 貲滄橫蒂 殮溘ж賊 螃盟陛 嫦儅ж螃棲 輿曖п輿褊衛螃.        太\n");
	printf("太≦衛除擊 澀跤 殮溘ц擊 唳辦,                                        太\n");
	printf("太澀跤 殮溘и 高 虜躑 -1擊 培ж罹 殮溘ж衛賊 腌棲棻.                  太\n");
	printf(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	question();

	return 0;
}

void question() {
	char user;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\n貲滄橫蒂 殮溘ж撮蹂: ");
	scanf(" %c", &user);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n");

	if (user == 'S' || user == 's')
		start();
	else if (user == 'Q' || user == 'q')
		exit(0);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("澀跤脹 貲滄橫殮棲棻.");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		question();

}

void start() {
	int i = 0, v = 0, total_s = 0;
	int uh = -1, um = -1, us = -1;
	int h = 0, m = 0, s = 0;
	printf(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("翕艙鼻曖 偃熱蒂 殮溘ж撮蹂:"); //翕艙鼻 偃熱
	scanf(" %d", &v);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	if (v == 72)
		easter_egg();
	if (v >= 50) {
		printf(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //掏嶸
		printf("翕艙鼻檜 傘鼠 號擎 唳辦 檜 餌檜お蒂 檜辨п爾撮蹂.\n");
		printf("嬴楚 餌檜お縑 蕾樓и �� \n營儅跡煙曖 葭觼蒂 犒餌ж罹 餌檜お縑 稱罹厥戲撮蹂.\n\n");
		printf("https://ytplaylist-len.herokuapp.com/");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("\n");
	}
	printf(" \n天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //衛除
	printf("[衛除郭葬 渦ж晦] (渦 檜鼻 殮溘ж雖 彊戲溥賊 99 殮溘)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("蕨衛) 1:23:34 賊 1 殮溘 \n");
	for (i = 0; uh != 99; i++) {
		printf("營儅跡煙曖 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d", i+1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("廓簞 艙鼻曖 碟, 蟾蒂 薯諼и\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("'衛除'虜 殮溘ж撮蹂: \n");
		scanf(" %d", &uh);
		if (uh == 99)
			h -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		h += uh;
	}
	printf(" \n天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //碟
	printf("[碟郭葬 渦ж晦] (渦 檜鼻 殮溘ж雖 彊戲溥賊 99 殮溘)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("蕨衛) 1:23:34 賊 23 殮溘 \n");
	for (i = 0; um != 99; i++) {
		printf("營儅跡煙曖 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("廓簞 艙鼻曖 衛除, 蟾蒂 薯諼и\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("'碟'虜 殮溘ж撮蹂: \n");
		scanf(" %d", &um);
		if (um == 99)
			m -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		m += um;
	}
	printf(" \n天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //蟾
	printf("[蟾郭葬 渦ж晦] (渦 檜鼻 殮溘ж雖 彊戲溥賊 99 殮溘)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("蕨衛) 1:23:34 賊 34 殮溘 \n");
	for (i = 0; us != 99; i++) {
		printf("營儅跡煙曖 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("廓簞 艙鼻曖 衛除, 碟蒂 薯諼и\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("'蟾'虜 殮溘ж撮蹂: \n");
		scanf(" %d", &us);
		if (us == 99)
			s -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		s += us;
	}
	printf(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //啗骯 唸婁
	printf("[啗骯 唸婁]\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("殮溘и 翕艙鼻曖 偃熱: %d\n", v);
	printf("殮溘и 翕艙鼻曖 識 望檜朝\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%d衛除 : %d蟾\n", h, h*3600);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("%d碟 : %d蟾\n", m, m*60);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("%d蟾 : %d蟾\n\n", s, s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	total_s = h * 3600 + m * 60 + s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("м啗 : %d蟾\n\n", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("評塭憮 殮溘ж褐 識 營儅跡煙曖 望檜朝\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("%d衛除", total_s / 3600); 
	total_s %= 3600; 
	printf("%d碟", total_s / 60); 
	total_s %= 60;
	printf("%d蟾", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("殮棲棻.\n\n");
	Sleep(1500);
	printf("啗骯晦蒂 謙猿ц蝗棲棻.\n");
	Sleep(1500);
	printf("棻擠 濛機擊 摹鷗ж褒 熱 氈蝗棲棻.\n\n");
	Sleep(2000);
	main();
}

void easter_egg() {
	int i = 0, v = 0, total_s = 0;
	int uh = -1, um = -1, us = -1;
	int h = 0, m = 0, s = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	printf("翕艙鼻檜 傘鼠 號擎 唳辦 檜 餌檜お蒂 檜辨п爾撮蹂.\n"); //掏嶸
	printf("嬴楚 餌檜お縑 蕾樓и �� \n營儅跡煙曖 葭觼蒂 犒餌ж罹 餌檜お縑 稱罹厥戲撮蹂.\n\n");
	printf("https://ytplaylist-len.herokuapp.com/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf(" \n天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //衛除
	printf("[衛除郭葬 渦ж晦] (渦 檜鼻 殮溘ж雖 彊戲溥賊 99 殮溘)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("蕨衛) 1:23:34 賊 1 殮溘 \n");
	for (i = 0; uh != 99; i++) {
		printf("營儅跡煙曖 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("廓簞 艙鼻曖 碟, 蟾蒂 薯諼и\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("'衛除'虜 殮溘ж撮蹂: \n");
		scanf(" %d", &uh);
		if (uh == 99)
			h -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		h += uh;
	}
	printf(" \n天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //碟
	printf("[碟郭葬 渦ж晦] (渦 檜鼻 殮溘ж雖 彊戲溥賊 99 殮溘)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("蕨衛) 1:23:34 賊 23 殮溘 \n");
	for (i = 0; um != 99; i++) {
		printf("營儅跡煙曖 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("廓簞 艙鼻曖 衛除, 蟾蒂 薯諼и\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("'碟'虜 殮溘ж撮蹂: \n");
		scanf(" %d", &um);
		if (um == 99)
			m -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		m += um;
	}
	printf(" \n天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //蟾
	printf("[蟾郭葬 渦ж晦] (渦 檜鼻 殮溘ж雖 彊戲溥賊 99 殮溘)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("蕨衛) 1:23:34 賊 34 殮溘 \n");
	for (i = 0; us != 99; i++) {
		printf("營儅跡煙曖 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("廓簞 艙鼻曖 衛除, 碟蒂 薯諼и\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("'蟾'虜 殮溘ж撮蹂: \n");
		scanf(" %d", &us);
		if (us == 99)
			s -= 99;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		s += us;
	}
	printf(" 天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //啗骯 唸婁
	printf("[啗骯 唸婁]\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("殮溘и 翕艙鼻曖 偃熱: %d\n", v);
	printf("殮溘и 翕艙鼻曖 識 望檜朝\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("%d衛除 : %d蟾\n", h, h * 3600);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("%d碟 : %d蟾\n", m, m * 60);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("%d蟾 : %d蟾\n\n", s, s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	total_s = h * 3600 + m * 60 + s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("м啗 : %d蟾\n\n", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("評塭憮 殮溘ж褐 識 營儅跡煙曖 望檜朝\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("%d衛除", total_s / 3600);
	total_s %= 3600;
	printf("%d碟", total_s / 60);
	total_s %= 60;
	printf("%d蟾", total_s);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("殮棲棻.\n\n");
	Sleep(1500);
	printf("啗骯晦蒂 謙猿ц蝗棲棻.\n");
	Sleep(1500);
	printf("棻擠 濛機擊 摹鷗ж褒 熱 氈蝗棲棻.\n\n");
	Sleep(2000);
	main();
}