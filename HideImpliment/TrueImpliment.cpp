// This is your true implement of you class
Class ToClientImp{
	
	/*Your code here*/
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