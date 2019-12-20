#ifndef BALL_H
#define BALL_H
#include "border.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "console.h"
class ball :public border
{
protected:
	double maxSpeed = 1.8;
	float ballX, ballY;
public:
	float bx, by, velX, velY;
	ball();
	~ball();
	ball(float cx, float cy);
	void drawBall();
	void fdrawball();
	void velocityBall();
	void controlMaxSpeed();
	void setVelBall();
	void resetBall();
	int checkPlayerWin();
	void checkBallHitWall();
};

enum eDir { STOP = 0, UP = 1, UPLEFT = 2, DOWNLEFT = 3, DOWN = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
// Gan gia tri cho cac huong di cua bong de de thao tac


class cBall: public border // Tao class qua bong
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
	void fupSpeed(); // Ham tang toc do bong
};


#endif // !BALL_H


