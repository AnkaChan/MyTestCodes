#pragma once
#ifdef TEST_DLL_EXPORTS
#define TEST_DLL_API __declspec(dllexport)
#else
#define TEST_DLL_API __declspec(dllimport)
#endif

 class TEST_DLL_API ClassDll
{
public:
	ClassDll();
	~ClassDll();
	void sayHello();
private:

};


