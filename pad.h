#ifndef PAH_H
#define PAH_H
#include "ball.h"
class pad :public ball
{
protected:
	float padX, padY;
	int size = 4;
public:
	float px, py, velPX;
	pad();
	~pad();
	pad(float cx, float cy);
	void drawPad();
	void drawPad2();
	void controlPadItem();
	void controlPad1();
	void controlPad2();
	void addPlayerBoundaries();
	void resetPad();
};



#endif // !PAH_H


