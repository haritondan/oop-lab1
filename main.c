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


int main() {
 
int n;

 printf("Please provide a number to be added");
 scanf("&d",&n);

 Enqueue(n);


}
