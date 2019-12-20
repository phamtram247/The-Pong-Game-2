#include "ball.h"



ball::ball()
{
}


ball::~ball()
{
}

ball::ball(float cx, float cy)
{
	bx = cx;
	by = cy;
	ballX = bx;
	ballY = by;
	velX = velY = 0;
}

void ball::drawBall()
{
	COORD coord;
	coord.X = int(ballX);
	coord.Y = int(ballY);
	SetConsoleCursorPosition(hOut, coord);
	cout << ' ';
	coord.X = int(bx);
	coord.Y = int(by);
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 12);
	cout << '0';
	SetConsoleTextAttribute(hOut, 15);
	ballX = bx;
	ballY = by;
}  //vẽ trái bóng

void ball::velocityBall()
{
	velX = float(rand() % 3) - 1.5f;
	velY = 1;
}  //Khởi tạo vận tốc trái bóng

void ball::controlMaxSpeed()
{
	if (velX < -maxSpeed) {
		velX = -maxSpeed;
	}
	else if (velX > maxSpeed) {
		velX = maxSpeed;
	}
}  //Cài đặt vận tốc nhanh nhất của trái bóng

void ball::setVelBall()
{
	bx += velX;
	by += velY;
}  //Thay đổi tọa độ trái bóng theo vận tốc

void ball::resetBall()
{
	bx = float(width / 2 - 1);
	by = float(height / 2);
}  //đưa trái bóng trở lại vị trí giữa sân khi có người chơi giành chiến thắng

int ball::checkPlayerWin()
{
	if (int(by) >= height) {
		return 1;
	}
	else if (int(by) <= 0) {
		return 2;
	}
	else return 0;
}  //kiểm tra trái bóng đã chạm vào vị trí cao nhất hoặc thấp nhất (tương ứng với việc có người giành chiến thắng)

void ball::checkBallHitWall()
{
	if (int(bx) <= 1) {
		velX *= -1;
		bx = 1;
		velX = 1.0f;
	}
	else if (int(bx) >= width - 3) {
		velX *= -1;
		bx = float(width - 3);
		velX = -1.0f;
	}
}  //xử lí khi trái banh đụng trúng tường trái và tường phải


cBall::cBall(int posX, int posY)
{
	originalX = posX; // Khoi tao gia tri ban dau cua x (do nguoi dung hoac dung ham san co tao ra)
	originalY = posY; // Khoi tao gia tri ban dau cua x (do nguoi dung hoac dung ham san co tao ra)
	x = posX;
	y = posY;
	direction = UP;
}

void ball::fdrawball()
{
	gotoXY(width / 2 + 1, height - 3);
	TextColor(10);
	cout << "O";
}

void cBall::fReset()
{
	x = originalX; // Dua qua bong ve vi tri ban dau
	y = originalY;
	speed = 100; // Toc do ve ban dau
}

void cBall::fchangeDirection(eDir dir)
{
	direction = dir;
}

int cBall::fgetX()
{
	return x;
}

int cBall::fgetY()
{
	return y;
}

eDir cBall::fgetDirection()
{
	return direction;
}

void cBall::frandomDirection()
{
	direction = (eDir)(rand() % 6 + 1); // Tao ra huong di ngau nhien nho ham random 
}

void cBall::fMove()
{
	// Game la mot he toa do nguoc voi truc x la truc hoanh, y la truc tung nhung goc toa do nam o tren cung
	TextColor(10);
	switch (direction)
	{
	case STOP:
		break;
	case UP:
		gotoXY(x, y);
		cout << " ";
		y--; // Di chuyen len tren nen giam tung do
		gotoXY(x, y);
		cout << "O";
		break;
	case UPLEFT:
		gotoXY(x, y);
		cout << " ";
		x--; // Di chuyen ve phia tren ben trai nen hoanh do va hoanh do giam
		y--;
		gotoXY(x, y);
		cout << "O";
		break;
	case DOWNLEFT:
		gotoXY(x, y);
		cout << " ";
		x--; // Di chuyen ve ben trai nen giam hoanh, phia duoi nen tang tung do
		y++;
		gotoXY(x, y);
		cout << "O";
		break;
	case DOWN:
		gotoXY(x, y);
		cout << " ";
		y++; // Di chuyen xuong duoi nen tang tung do
		gotoXY(x, y);
		cout << "O";
		break;
	case UPRIGHT:
		gotoXY(x, y);
		cout << " ";
		x++; // Di chuyen ve ben phai nen tang hoanh do
		y--; // Di chuyen len tren nen giam tung do
		gotoXY(x, y);
		cout << "O";
		break;
	case DOWNRIGHT:
		gotoXY(x, y);
		cout << " ";
		x++; // Di chuyen ve ben phai nen tang hoanh do
		y++; // Di chuyen xuong duoi nen tang tung do
		gotoXY(x, y);
		cout << "O";
		break;
	default:
		break;
	}
	Sleep(speed);
}



void cBall::fupSpeed()
{
	speed = (speed * 90) / 100;
}
