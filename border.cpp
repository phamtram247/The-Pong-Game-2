#include "border.h"
#include "console.h"


border::border()
{
}


border::~border()
{
}

void border::hideConsoleCursor()
{
	srand(unsigned int(time(NULL)));
	SMALL_RECT DisplayArea = { 0, 0, width, height + 3 };
	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
	//thay đổi thích thước console	
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = false;
	SetConsoleCursorInfo(hOut, &ConCurInf);
	//ẩn vị trí con trỏ
}

void border::drawBorder()
{
	SetConsoleTextAttribute(hOut, 7);
	for (int i = 0; i < width - 1; ++i)
		cout << '\xB';
	for (int i = 0; i < height - 1; ++i) {
		cout << endl << "\xB";
		for (int i = 0; i < width - 3; ++i)
			cout << ' ';
		cout << "\xB";
	}
	cout << '\n';
	for (int i = 0; i < width - 1; ++i)
		cout << '\xB';
	cout << "\n                                        \n";
	for (int i = 0; i < width - 1; ++i)
		cout << '\xB';

}    //vẽ tường

void border::drawBorder2()
{
	SetConsoleTextAttribute(hOut, 7);
	for (int i = 0; i < width - 1; ++i)
		cout << '\xDB';
	for (int i = 0; i < height - 1; ++i) {
		cout << endl << "\xDB";
		for (int i = 0; i < width - 3; ++i)
			cout << ' ';
		cout << "\xDB";
	}
	cout << '\n';
	for (int i = 0; i < width - 1; ++i)
		cout << '\xDB';
	cout << "\n                                        \n";
	//for (int i = 0; i < width - 1; ++i)
		//cout << '\xDB';

}

void border::endDrawBorder1()
{
	COORD coord;
	coord.X = 0;
	coord.Y = height;
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 13);
	cout << "\n    Player 1 score: " << player1_score << "\t\tPlayer 2 score: " << player2_score << '\n';
}  //thêm bảng điểm ở chế độ 2 người chơi

void border::endDrawBorder2()
{
	COORD coord;
	coord.X = 0;
	coord.Y = height;
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 13);
	cout << "\n    Your score: " << you_score << "\t\tComputer score: " << comp_score << '\n';
}   //thêm bảng điểm ở chế dộ chơi với máy

void border::endDrawBorder3()
{
	gotoXY(1, height + 1);
	TextColor(8);
	cout << "Your score: " << item_score;
}
