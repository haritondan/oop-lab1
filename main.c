#include <stdio.h>
#include <stdbool.h>


struct Queue
{
   struct Queue *next;
   int data;
};

struct Queue *front;
struct Queue *rear;

void addq(int);//function is declared
int delq();//delq function id is declared

int main(){
   int ch,data,val;
   do{
      printf("\nEnter 1 to add an element in the Queue");
      printf("\nEnter 2 to delete an element front the Queue");
      printf("\nEnter your choice");
      scanf("%d",&ch;  
   
      switch (ch)
      {
      case 1: 
         printf("\nEnter them element to include");
         scanf("%d",&data);   
         break;

      case 2:
         printf("\n")
      
      default:
         break;
      }
   }

    
}