#define TEST_DLL_EXPORTS
#include "TestDll.h"

#include <stdio.h>

ClassDll::ClassDll()
{
}

ClassDll::~ClassDll()
{
}

void ClassDll::sayHello()
{
	printf("Hello from dll!\n");
}


