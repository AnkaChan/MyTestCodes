#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;

class Father
{
public:
	virtual void Hello() {
		printf("Father say hello.\n");
	}

private:
};

class Son : public Father
{
public:
	void Hello() {
		printf("Son say hello.\n");
	}
private:

};

void sayHello(Father * pF) {
	pF->Hello();
}

int main(int argc, char** argv) {
	Father f;
	Son s;

	sayHello(&f);
	sayHello(&s);

	getchar();
}