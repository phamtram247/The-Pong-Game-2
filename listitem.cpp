#include "listitem.h"

void listitem::createitem(int sl)
{
	int x1 = 3;
	int x2 = 4;
	int x3 = 5;
	int x4 = 6;
	int y = 2;
	for (int i = 0; i < sl; i++)
	{
		item it(x1, x2, x3, x4, y);
		li.push_back(it);
		x1 = x1 + 5;
		x2 = x2 + 5;
		x3 = x3 + 5;
		x4 = x4 + 5;
		if (x1 + 5 >= 70)
		{
			y = y + 2;
			x1 = 3;
			x2 = 4;
			x3 = 5;
			x4 = 6;
		}
	}
}

void listitem::drawitem()
{
	int color = 1;
	list<item>::iterator i;
	for (i = li.begin(); i != li.end(); i++)
	{
		TextColor(color);
		gotoXY(i->getx1(), i->gety());
		cout << "\xDB";
		gotoXY(i->getx2(), i->gety());
		cout << "\xDB";
		gotoXY(i->getx3(), i->gety());
		cout << "\xDB";
		gotoXY(i->getx4(), i->gety());
		cout << "\xDB";	
		color++;
		if (color == 16)
		{
			color++;
		}
	}
}

void listitem::deleteitem(item it)
{
	gotoXY(it.getx1(), it.gety());
	cout << " ";
	gotoXY(it.getx2(), it.gety());
	cout << " ";
	gotoXY(it.getx3(), it.gety());
	cout << " ";
	gotoXY(it.getx4(), it.gety());
	cout << " ";
	list<item>::iterator i;
	for (i = li.begin(); i != li.end(); i++)
	{
		if (i->getx1() == it.getx1() && i->gety() == it.gety())
		{
			li.erase(i);
			break;
		}
	}
}
