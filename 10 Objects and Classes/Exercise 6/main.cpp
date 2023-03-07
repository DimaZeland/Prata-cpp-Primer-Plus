#include "Move.h"
int main()
{
	Move Obj(5,10);
	Obj.showmove();
	Move Obj2(11, 16);
	Obj2.showmove();
	Obj2 = Obj2.add(Obj);
	Obj2.showmove();
	Obj2.reset();
	Obj2.showmove();
	system("pause");
	return 0;
}
