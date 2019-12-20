#include "process.h"



process::process()
{
}


process::~process()
{
}

void process::reset1(ball & b, pad & player1, pad & player2, int & player1_score, int & player2_score, bool started)
{
	//đưa pad về vị trí ban đầu
	player1.resetPad();
	player2.resetPad();
	//đưa bóng về ví trí ban đầu
	b.resetBall();
	//cung cấp lại tốc độ cảu quả bóng
	b.velocityBall();
	//trò chơi bắt đầu
	started = false;
	//thêm bảng điểm
	COORD coord;
	coord.X = 0;
	coord.Y = height;
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 13);
	cout << "\n    Player 1 score: " << player1_score << "\t\tPlayer 2 score: " << player2_score << '\n';
}

void process::reset2(ball & b, pad & you, pad & comp, int & you_score, int & comp_score, bool started)
{
	//đưa pad về vị trí ban đầu
	you.resetPad();
	comp.resetPad();
	//đưa bóng về ví trí ban đầu
	b.resetBall();
	//cung cấp lại tốc độ cảu quả bóng
	b.velocityBall();
	//trò chơi bắt đầu
	started = false;
	//thêm bảng điểm
	COORD coord;
	coord.X = 0;
	coord.Y = height;
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 13);
	cout << "\n    Your score: " << you_score << "\t\tComputer score: " << comp_score << '\n';
}

void process::menu()
{
	//thêm menu
	bool choose = true;
	while (choose == true) {
		COORD p1;
		p1.X = int(width / 2 - 15);
		p1.Y = int(height / 2 - 3);
		SetConsoleCursorPosition(hOut, p1);
		SetConsoleTextAttribute(hOut, 8);
		cout << "PRESS 1: DOUBLE PLAYER MODE\n";
		COORD p2;
		p2.X = int(width / 2 - 15);
		p2.Y = int(height / 2 + 3);
		SetConsoleCursorPosition(hOut, p2);
		SetConsoleTextAttribute(hOut, 8);
		cout << "PRESS 2: COMPUTER MODE\n";
		gotoXY(width / 2 - 15, height / 2 + 9);
		TextColor(8);
		cout << "PRESS 3: ITEM MODE\n";

		//Xử lý khi người dùng chọn chế độ chơi thứ nhất
		if (GetAsyncKeyState(49)) {
			//xóa menu
			COORD p1;
			p1.X = int(width / 2 - 15);
			p1.Y = int(height / 2 + 3);
			SetConsoleCursorPosition(hOut, p1);
			cout << "                                                ";
			 
			COORD p2;
			p2.X = int(width / 2 - 15);
			p2.Y = int(height / 2 - 3);
			SetConsoleCursorPosition(hOut, p2);
			cout << "                                                ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			//thoát khỏi menu
			choose = false;
			//vẽ khung chế độ thứ nhất
			endDrawBorder1();
			//xử lý chế độ chơi thứ nhất
			control1();
		}

		if (GetAsyncKeyState(50)) {
			//xóa menu
			COORD p1;
			p1.X = int(width / 2 - 15);
			p1.Y = int(height / 2 + 3);
			SetConsoleCursorPosition(hOut, p1);
			cout << "                                                ";

			COORD p2;
			p2.X = int(width / 2 - 15);
			p2.Y = int(height / 2 - 3);
			SetConsoleCursorPosition(hOut, p2);
			cout << "                                                ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			//thoát khỏi menu
			choose = false;
			//vẽ khung chế độ thứ hai
			endDrawBorder2();
			//xử lý chế độ chơi thứ hai
			control2();
		}

		if (GetAsyncKeyState(51))
		{
			gotoXY(width / 2 - 15, height / 2 - 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			choose = false;
			listitem li;
			li.createitem(26);
			li.drawitem();
			
			endDrawBorder3();
			control3(li);
		}
		
		

	}

}

void process::control1()
{
	process MODE1;
	//thêm pad và bóng
	pad player1(width / 2, height - 2);
	pad player2(width / 2, 2);
	ball b(width / 2 - 1, height / 2);
	//cung cấp vận tốc cho trái bóng
	b.velocityBall();
	bool started = false;
	while (true) {
		if (started) {
			//người chơi di chuyển pad
			player1.controlPad1();
			player2.controlPad2();
			//thêm giới hạn của pad( dừng lại khi đụng tường)
			player1.addPlayerBoundaries();
			player2.addPlayerBoundaries();
			//giữ cho trái bóng không di chuyển quá nhanh
			b.controlMaxSpeed();
			//thay đổi vị trí của trái bóng theo vận tốc của nó
			b.setVelBall();
			// kiểm tra và xử lý khi bóng chạm pad của người chơi thứ nhất
			MODE1.checkBallHitPad1(player1, b);
			// kiểm tra và xử lý khi bóng chạm pad của người chơi thứ hai
			MODE1.checkBallHitPad2(player2, b);
			//xử lý khi có người chơi giành chiến thắng và reset về các vị trí ban đầu
			if (b.checkPlayerWin() == 1) {
				++player2_score;
				reset1(b, player1, player2, player1_score, player2_score, started);
			}
			else if (b.checkPlayerWin() == 2) {
				++player1_score;
				reset1(b, player1, player2, player1_score, player2_score, started);
			}
			//xử lý khi bóng chạm tường
			b.checkBallHitWall();
		}
		else {
			//chờ người chơi bắt đầu trận đấu( bấm "space" để bắt đầu)
			COORD p;
			p.X = int(width / 2 - 16);
			p.Y = int(height / 1.5f);
			SetConsoleCursorPosition(hOut, p);
			SetConsoleTextAttribute(hOut, 11);
			cout << "Press the space bar to start . .";
			if (GetAsyncKeyState(VK_SPACE)) {
				COORD p;
				p.X = int(width / 2 - 16);
				p.Y = int(height / 1.5f);
				SetConsoleCursorPosition(hOut, p);
				cout << "                                ";
				started = true;
			}
		}
		// vẽ pad và ball của người chơi
		player1.drawPad();
		player2.drawPad();
		b.drawBall();
		// tốc độ xuất ra màn hình
		Sleep(delay);
	}
}

void process::control2()
{
	process MODE2;
	//thêm pad và bóng
	pad you(width / 2, height - 2);
	pad comp(width / 2, 2);
	ball b(width / 2 - 1, height / 2);
	//cung cấp ận tốc cho trái bóng
	b.velocityBall();
	bool started = false;
	while (true) {
		if (started) {
			//người chơi di chuyển pad
			you.controlPad1();
			// pad của computer tự di chuyển theo trái bóng
			MODE2.setVelCompPad(comp, b);
			//thêm giới hạn của pad( dừng lại khi đụng tường)
			you.addPlayerBoundaries();
			comp.addPlayerBoundaries();
			//giữ cho trái bóng không di chuyển quá nhanh
			b.controlMaxSpeed();
			//thay đổi vị trí của trái bóng theo vận tốc của nó
			b.setVelBall();
			// kiểm tra và xử lý khi bóng chạm pad của người chơi 
			MODE2.checkBallHitPad1(you, b);
			// kiểm tra và xử lý khi bóng chạm pad của computer
			MODE2.checkBallHitPad2(comp, b);
			//xử lý khi có người chơi giành chiến thắng và reset về các vị trí ban đầu
			if (b.checkPlayerWin() == 1) {
				++player2_score;
				reset2(b, you, comp, player1_score, player2_score, started);
			}
			else if (b.checkPlayerWin() == 2) {
				++player1_score;
				reset2(b, you, comp, player1_score, player2_score, started);
			}
			//xử lý khi bóng chạm tường
			b.checkBallHitWall();
		}
		else {
			//chờ người chơi bắt đầu trận đấu( bấm "space" để bắt đầu)
			COORD p;
			p.X = int(width / 2 - 16);
			p.Y = int(height / 1.5f);
			SetConsoleCursorPosition(hOut, p);
			SetConsoleTextAttribute(hOut, 11);
			cout << "Press the space bar to start . .";
			if (GetAsyncKeyState(VK_SPACE)) {
				COORD p;
				p.X = int(width / 2 - 16);
				p.Y = int(height / 1.5f);
				SetConsoleCursorPosition(hOut, p);
				cout << "                                ";
				started = true;
			}
		}
		// Draw all objects
		you.drawPad();
		comp.drawPad();
		b.drawBall();
		// Delay
		Sleep(delay);
	}
}

void process::control3(listitem l_item)
{
	b = new cBall(width / 2 + 1, height - 3);
	process MODE3;
	
	bool win = false;
	bool start = false;
	do
	{
		if (start == true)
		{
			logicitem(l_item);
			
			

		}
		else
		{
			gotoXY(width / 2 - 16, height / 2);
			TextColor(8);
			cout << "Press the SPACE to start game";
			if (GetAsyncKeyState(VK_SPACE))
			{
				gotoXY(width / 2 - 16, height / 2);
				cout << "                             ";
				drawPad2();
				fdrawball();
				start = true;
			}
			
			

		}
	} while (win == false);
}

void process::upscore()
{
	item_score = item_score + 10;
	gotoXY(1, height + 1);
	TextColor(8);
	cout << "Your score: " << item_score;
}

void process::logicitem(listitem &l_item)
{
	pad you(35, height - 2);
	b->fMove();
	you.controlPadItem();
	int ballx = b->fgetX();
	int bally = b->fgetY();
	//Nguoi choi
	if (bally >= you.py - 1)
	{
		if ((ballx >= you.px - 6) && (b->fgetDirection() == DOWNRIGHT))
			b->fchangeDirection(UPLEFT);
		if ((ballx <= you.px + 5) && (b->fgetDirection() == DOWNLEFT))
			b->fchangeDirection(UPRIGHT);
	}

	for (int i = 0; i < 5; i++)
	{
		if (bally >= you.py - 1)
		{
			if ((ballx <= you.px + i) && (ballx >= you.px - i))
			{
				if (b->fgetDirection() == DOWN)
				{
					if (ballx <= you.px)
						b->fchangeDirection(UPLEFT);
					else
						b->fchangeDirection(UPRIGHT);
				}
				else if (b->fgetDirection() == DOWNLEFT)
					b->fchangeDirection(UPLEFT);
				else if (b->fgetDirection() == DOWNRIGHT)
					b->fchangeDirection(UPRIGHT);
			}
		}
	}

	//Tuong trai
	if (ballx == 1)
	{
		if (b->fgetDirection() == DOWNLEFT)
			b->fchangeDirection(DOWNRIGHT);
		else if (b->fgetDirection() == UPLEFT)
			b->fchangeDirection(UPRIGHT);
	}

	//Tuong phai
	if (ballx == width - 3)
	{
		if (b->fgetDirection() == DOWNRIGHT)
			b->fchangeDirection(DOWNLEFT);
		else if (b->fgetDirection() == UPRIGHT)
			b->fchangeDirection(UPLEFT);
	}
	//Tuong tren
	if (bally == 1)
	{
		if (b->fgetDirection() == UPRIGHT)
		{
			b->fchangeDirection(DOWNRIGHT);
		}
		else if (b->fgetDirection() == UPLEFT)
		{
			b->fchangeDirection(DOWNLEFT);
		}
		else if (b->fgetDirection() == UP)
			b->fchangeDirection(DOWN);
	}
	list<item>::iterator i;
	for (i = l_item.li.begin(); i != l_item.li.end(); i++)
	{
		//Phia tren item
		
		if (bally == i->gety() - 1)
		{
			if (ballx == i->getx1() || ballx == i->getx2() || ballx == i->getx3() || ballx == i->getx4())
			{
				if (b->fgetDirection() == DOWN)
				{
					b->fchangeDirection(UP);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNLEFT)
				{
					b->fchangeDirection(UPLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNRIGHT)
				{
					b->fchangeDirection(UPRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
			else if ((ballx == i->getx1() - 1) && (b->fgetDirection() == DOWNRIGHT))
			{
				b->fchangeDirection(UPLEFT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
			else if ((ballx == i->getx4() + 1) && (b->fgetDirection() == DOWNLEFT))
			{
				b->fchangeDirection(UPRIGHT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
		}

		//Phia duoi item
		else if (bally == i->gety() + 1)
		{
			if (ballx == i->getx1() || ballx == i->getx2() || ballx == i->getx3() || ballx == i->getx4())
			{
				if (b->fgetDirection() == UP)
				{
					b->fchangeDirection(DOWN);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == UPLEFT)
				{
					b->fchangeDirection(DOWNLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == UPRIGHT)
				{
					b->fchangeDirection(DOWNRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
			else if ((ballx == i->getx1() - 1) && (b->fgetDirection() == UPRIGHT))
			{
				b->fchangeDirection(DOWNLEFT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
			else if ((ballx == i->getx4() + 1) && (b->fgetDirection() == UPLEFT))
			{
				b->fchangeDirection(DOWNRIGHT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
		}

		//Ben trai item
		else if (ballx == i->getx1() - 1)
		{
			if (bally == i->gety())
			{
				if (b->fgetDirection() == UPRIGHT)
				{
					b->fchangeDirection(UPLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNRIGHT)
				{
					b->fchangeDirection(DOWNLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
		}

		//Ben phai item
		else if (ballx == i->getx4() + 1)
		{
			if (bally == i->gety())
			{
				if (b->fgetDirection() == UPLEFT)
				{
					b->fchangeDirection(UPRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNLEFT)
				{
					b->fchangeDirection(DOWNRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
		}

	}


}

void process::checkBallHitPad1(pad &X, ball &A)
{
	if (int(A.by) >= int(X.py - 1) && int(A.by) <= int(X.py + 1)) {
		if (int(A.bx) > int(X.px - size) && int(A.bx) < int(X.px + size)) {
			A.velY *= (-1.1);
			A.velX += float(A.bx - X.px) / 3;
			A.by = X.py - 1;
		}
	}
}  //xử lý khi trái bóng chạm pad phía dưới sân đấu

void process::checkBallHitPad2(pad &X, ball &A)
{
	if (int(A.by) <= int(X.py + 1) && int(A.by) >= int(X.py - 1)) {
		if (int(A.bx) > int(X.px - size) && int(A.bx) < int(X.px + size)) {
			A.velY *= (-1.1);
			A.velX += float(A.bx - X.px) / 3;
			A.by = X.py + 1;
		}
	}
}  //xử lý khi trái bóng chạm pad phía trên sân đấu

void process::setVelCompPad(pad &X, ball &A)
{
	X.velPX = 0;
	X.velX -= float(X.px - A.bx) / 10.0f;
	X.velX *= 0.85f;
	X.px += X.velX;
}  //cung cấp tốc độ cho thanh pad của máy phụ thuộc vào vận tốc trái bóng





