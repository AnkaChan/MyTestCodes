// This is the only InterFace functions you want to let user to see 

Class ToClientImp；

class ToClient{
	public:
	void func1();
	void fun2c();
	
	ToClient();
	~ToClient();
	
	private:
	//The class of true implement of this class, which cannot be seen by user
	ToClientImp； * pImplement；
	
}