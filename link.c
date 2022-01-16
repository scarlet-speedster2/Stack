#include<stdio.h>
#include<stdlib.h>

typedef struct stack {

	int data;
	struct stack* next;
}stack;

stack* create_node(int d){

	stack* new = (stack*) malloc(sizeof(stack));
	if(!new){
	       printf("overflow..");
	}	       

	new ->data = d;
	new ->next = NULL;

	return new;
}

void push(stack** s,int d){

	stack* n = create_node(d);
	n->next = *s;
	*s = n;
}

void pop(stack** s){

	stack* t = *s;
	if(!*s){
		printf("Cannot pop\n");
		return;
	}
	*s = (*s)->next;
	printf("%d is removed",t->data);
}

void peak(stack* s){
	if(!s){
		printf("Cannnot Peak\n");
		return;
	}
	printf("Top = %d\n",s->data);
}

void main(){

	stack* ss = NULL;
	push(&ss,10);
	push(&ss,20);
	peak(ss);
	pop(&ss);
	peak(ss);
}
