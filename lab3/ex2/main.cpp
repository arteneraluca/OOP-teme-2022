#include "Canvas.h"
#include <stdlib.h>

int main() {
	Canvas c1(20, 20);
	c1.DrawCircle(5, 5, 4, '*');
	c1.FillCircle(15, 15, 4, '~');
	c1.DrawRect(3, 15, 9, 19, '-');
	c1.FillRect(15, 3, 19, 9, '&');
	c1.SetPoint(10, 10, 't');
	c1.DrawLine(11, 2, 12, 17, '$');
	c1.DrawLine(12, 2, 14, 6, '#');
	c1.Print();
	system("pause");
	return 0;
}