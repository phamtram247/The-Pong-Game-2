#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>
using namespace std;
class item
{
private:
	int x1;
	int x2;
	int x3;
	int x4;
	int y;
public:

	item();
	~item();
	item(int, int, int, int, int);
	bool operator==(const item it);
	int getx1();
	int getx2();
	int getx3();
	int getx4();
	int gety();
};

#endif // !_ITEM_H_
