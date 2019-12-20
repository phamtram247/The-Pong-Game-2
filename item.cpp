#include "item.h"

item::item()
{
}

item::~item()
{
}

item::item(int a, int b, int c, int d, int e)
{
	x1 = a;
	x2 = b;
	x3 = c;
	x4 = d;
	y = e;

}

bool item::operator==(item it)
{
	if (it.getx1() == x1 && it.getx2() == x2 && it.getx3() == x3 && it.getx4() == x4 && it.gety() == y)
		return true;
	return false;
}

int item::getx1()
{
	return x1;
}

int item::getx2()
{
	return x2;
}

int item::getx3()
{
	return x3;
}

int item::getx4()
{
	return x4;
}

int item::gety()
{
	return y;
}
