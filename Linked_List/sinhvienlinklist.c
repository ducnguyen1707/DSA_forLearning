#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char ID[10];
	char Name[50];
	float R1, R2, R3;
}Student;

struct Node{
	Student Element;
	struct Node* Next;
};

typedef struct Node* List;

List getList() {
	List pL;
	pL= (struct Node*)malloc(sizeof(struct Node));
	pL->Next =Null;
	
}
