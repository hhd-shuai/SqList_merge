#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef int elemType;
typedef struct LNode{
	elemType data;
	struct LNode *next;
}LNode,*LinkList;
LNode *createList(elemType arr[],int n){
	int i,j;
	LNode *L,*r;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("分配内存失败.\n");
		exit(0);
	}
	r = L;
	for(i = 0;i < n;i++){
		LNode *s = (LNode *)malloc(sizeof(LNode));
		if(s == NULL){
			printf("分配内存失败.\n");
			exit(0);
		}
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}
void listPrint(LNode *L){
	LNode *p = L->next;
	while(p){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("\n");
}
//有序合并A,B两个单链表为C，C由A,B两结点组成
void mergeList(LNode *A,LNode *B,LNode **C){
	LNode *p1,*p2,*q,*r;
	p1 = A->next;
	p2 = B->next;
	*C = A;
	(*C)->next = NULL;
	r = *C;
	free(B);
	while(p1 != NULL && p2 != NULL){
		if(p1->data <= p2->data){
			r->next = p1;
			p1 = p1->next;
			r = r->next;
		}
		else{
			r->next = p2;
			p2 = p2->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if(p1 != NULL)
		r->next = p1;
	if(p2 != NULL)
		r->next = p2;
}
int main(){
	elemType a[] = {2,3,5,9,11,18,21,24,26,34,36,38,46};
	elemType b[] = {1,3,5,7,9,11,13,15,17,19,21};
	int len_a,len_b;
	LNode *A,*B,*C;
	len_a = sizeof(a)/sizeof(a[0]);
	len_b = sizeof(b)/sizeof(b[0]);
	A = createList(a,len_a);
	B = createList(b,len_b);
	listPrint(A);
	listPrint(B);
	mergeList(A,B,&C);
	listPrint(C);

	return 0;
}
