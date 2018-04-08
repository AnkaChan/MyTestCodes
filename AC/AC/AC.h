#ifndef _AC_H_
#define _AC_H_

#define REQUEST_INPUTS(N) \
if (argc < N){\
	printf("Need %d input files.\n", N);\
	return -1;\
}\

#ifdef PRINT_NODE_TRUE 
#define PRINT_NODE(a) printf(a);
#else
#define PRINT_NODE(a)
#endif

#endif