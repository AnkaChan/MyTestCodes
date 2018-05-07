// This is your true implement of you class
Class ToClientImp{
	public:
	ToClientImp() {};
	void fun1();
	
	/*Your code here*/
}
void ToClientImp::fun1(){
	
}


ToClient::ToClient(){
	pImplement = new ToClientImp;
	
};

ToClient::~ToClient(){
	deleted pImplement;
}

void ToClient::func1(){
	pImplement->.....
	// Complier now knows the Implement of ToClientImp
	
}