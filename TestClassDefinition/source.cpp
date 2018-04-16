#include "DemoClass.h"

class Class2 {
public:
	int k;
	DemoClass c;
	int getI();
};

int Class2::getI()
{
	return c.getI();
}
