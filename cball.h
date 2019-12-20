#ifndef __CBALL_H__
#define __CBALL_H__

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
// Gan gia tri cho cac huong di cua bong de de thao tac


class cBall // Tao class qua bong
{
private:
	int speed = 100; // Bien tang toc do bong
	int x, y; // Toa do x, y cua qua bong
	int originalX, originalY; // Toa do ban dau
	eDir direction; // Huong cua qua bong 
public:
	cBall(int posX, int posY); // Ham khoi tao qua bong, truyen vao tham so x va y do nguoi dung hoac dung ham san co de tao
	void fReset(); // Reset vi tri qua bong sau khi game ket thuc
	void fchangeDirection(eDir dir); // Thay doi huong di cua qua bong
	int fgetX(); // Ham tra ve toa do x
	int fgetY(); // Ham tra ve toa do y
	eDir fgetDirection(); // Ham tra ve huong di
	void frandomDirection(); // Ham tao ra huong di ngau nhien tiep theo cho qua bong
	void fMove(); // Ham de qua bong di chuyen
	void gotoXY(int column, int line); // Ham di chuyen con tro den vi tri mong muon
	void TextColor(int color); // Ham doi mau chu
	void fupSpeed(); // Ham tang toc do bong
};

#endif
