#include "process.h"
#include "conio.h"

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void main() {
	Nocursortype();
	process A;
	A.hideConsoleCursor();
	A.drawBorder2();
	A.menu();
	cout << endl << " ";
	system("pause");
}