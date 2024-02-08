//Program to implement queue using stack
#include<stdio.h>
#include <stdlib.h>
 
struct Stack{
	int size;
	int top;
	int *s;
}s1,s2;
 
void Create(struct Stack *st){
	printf("\nEnter size of queue required: ");
	scanf("%d",&st->size);
 
	st->s = (int *)malloc(sizeof(int)*st->size);
 
	st->top = -1;
}
 
void Display(struct Stack st){
	int i;
	for(i=st.top;i>=0;i--){
		printf("%d ",st.s[i]);
	}
}
 
void Push(struct Stack *st , int val){
	if(st->top==st->size-1){
		printf("Stack Overflow\n");
	}
	else{
		st->top++;
		st->s[st->top] = val;
	}
}
 
int Pop(struct Stack *st){
	int val;
 
	if(st->top==-1){
		printf("\nStack Underflow\n");
	}
	else{
		val = st->s[st->top];
		st->top--;
	}
    return val;
}
 
int IsEmpty(struct Stack st){
	if(st.top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
 
int IsFull(struct Stack st){
	if(st.top == st.size-1){
		return 1;
	}
	else{
		return 0;
	}
}
 
void Enqueue(struct Stack *st , int val){
	Push(&s1,val);
}
 
int Dequeue(){
	int val =-1;
	if(IsEmpty(s2)){
		if(IsEmpty(s1)){
			printf("\nQueue is Empty\n");
		}
	else{
		while(!IsEmpty(s1)){
			Push(&s2,Pop(&s1));
			}
		}
	}
	val = Pop(&s2);
 
	return val;
}
 
int main(){
 
	Create(&s1);
	Create(&s2);
 
	Enqueue(&s1,12);
 
	Enqueue(&s1,50);
 
	Enqueue(&s1,134);
 
	Enqueue(&s1,56);
 
	Display(s1);
 
	printf("\nElement Deleted: %d",Dequeue());
 
	return 0;
}
