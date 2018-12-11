#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#include <stdio.h>


int main(int argc, char** argv) {
	FILE * fp = fopen("demo.txt", "w");

	fprintf(fp, "Hello world!");

	return 0;
}