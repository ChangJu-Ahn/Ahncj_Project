#ifndef __NODE_H
#define __NODE_H
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	char LeftData;
	char RightData;
	struct _NODE *Left;
	struct _NODE *Mid;
	struct _NODE *Right;
} NODE;

NODE *HeadNode, *EndNode;

#endif