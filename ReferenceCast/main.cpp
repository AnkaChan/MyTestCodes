#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char** argv) {
	std::vector<long long*> vec1(1);
	std::vector<long*> & vec1Ref = (std::vector<long*> &)vec1;

	long long a = 0;
	long long * pA = &a;
	long & aRef = (long&)a;
	vec1Ref.push_back((long*)pA);
	vec1Ref.push_back((long*)pA);
	vec1Ref.push_back((long*)pA);
	vec1Ref.push_back((long*)pA);

	vec1Ref.back() = NULL;
	printf("The size of vec1: %d, the size of vec1Ref: %d.", vec1.size(), vec1Ref.size());
	printf("The last element of vec1: %d, last element of vec1Ref: %d.", vec1.back(), vec1Ref.back());
}