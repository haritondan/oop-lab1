#include <stdio.h>
#include <stdbool.h>
 
 
 int A[10];
 int front = -1;
 int rear = -1;


bool isEmpty(){
   if (front == -1 && rear == -1){
   return true;
   }
   else{
      return false;
   }
}


int Enqueue(int x){
   if (rear == sizeof(A) - 1){
   printf("Queue is full");
   }
   else if (isEmpty())
   {
      front = rear = 0;
   }
   else {
      rear = rear + 1;
   }
   A[rear]= x;
}

int Dequeue(){
   if (isEmpty())
   {
      return 0;
   }
   else if(front==rear){
      front = rear = -1;
   }
   else {
      front = front + 1;
   }
   
}

int main() {
 
int n;

 printf("Please provide a number to be added /n");
 scanf("%d",&n);

 Enqueue(n);
 for (int i = 0; i < 10; i++){
 printf("%d",A[i]);
 }


return 0;
}
