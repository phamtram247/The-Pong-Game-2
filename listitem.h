#ifndef _LISTITEM_H_
#define _LISTITEM_H_
#include "item.h"
#include <list>
#include "console.h"
class listitem
{
public:
	list<item> li;
	void createitem(int sl);
	void drawitem();
	void deleteitem(item i);
};
#endif // !_LISTITEM_H_
