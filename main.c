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
      scanf("%d",&ch);  
   
      switch (ch)
      {
      case 1: 
         printf("\nEnter them element to include");
         scanf("%d",&data);   
         break;

      case 2:
         val=delq();
         printf("\nThe deleted element is %d");
         break;
      default:
         printf("\nWrong Input");
         break;
      }
   }while (ch!=0);
   return 1;
    
}

//function to add an element
void enQueue(int data){
   struct Queue *temp;
   temp = (struct Queue *)malloc(sizeof(struct Queue));
   if(temp==NULL)
   {
      printf("\nQueue is empty");
      return;
   }
   temp->data=data;//the value is enteredin the list
   temp->next=NULL;
   if(rear==NULL)
   {
      front=temp;
      rear=temp;
   }
   else
   {
      rear->next=temp;
      rear=rear->next;//rear is incremented
   }
   
   
}