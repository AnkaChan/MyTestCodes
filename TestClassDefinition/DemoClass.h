class DemoClass
{
public:
	DemoClass() {
		i = 0;
		buf = new char[100];
	};
	~DemoClass() {
		delete buf;
	};

	int getI() {
		return i;
	}

	char * getBuf() {
		return buf;
	}
private:
	int i;
	char * buf;

};