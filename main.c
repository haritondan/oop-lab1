#include <stdio.h>
#include <stdlib.h>


struct Queue
{
   struct Queue *next;
   int data;
};


struct Queue *front;
struct Queue *rear;

void enQueue(int);//function is declared
int deQueue();//delq function id is declared

int main(){
   struct Queue *q;
   int ch,data,val;
   do{
      printf("\nEnter 1 to add an element in the Queue");
      printf("\nEnter 2 to delete an element from the Queue");
      printf("\nEnter 3 to see the Queue");
      printf("\nEnter your choice");
      scanf("%d",&ch);  
   
      switch (ch)
      {
      case 1: 
         printf("\nEnter them element to include");
         scanf("%d",&data);
         enQueue(data);   
         break;

      case 2:
         printf("\nEnter them element to delete");
         scanf("%d",&val);
         val = deQueue();
          
         break;
      case 3:
         q=front;
         while (q!=NULL)
         {
            printf("%d",q->data);
            q=q->next;
         }
         
         break;
      default:
         printf("\nWrong Input\n");
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
      printf("\nQueue is full");
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
//to delete an element
int deQueue()
{
   struct Queue *temp;
   int data=0;
   if(front==NULL)
   {
      printf("\nQueue is empty\n");
      return 0;
   }
   data=front->data;
   temp=front;
   if(front==NULL)
   {
      front==NULL;
      rear=NULL;
   }
   else
   {
      front=front->next;
      free(temp);
      
   }
   return data;
}

