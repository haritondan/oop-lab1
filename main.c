#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue
{
   struct Queue *next;
   int data;
};


struct Queue *front;
struct Queue *rear;

bool search(int);
void enQueue(int);//function is declared
void deQueue();//function is declared
void saveFile();//func to save a file
void openFile();//func to open a file

int main(){
   struct Queue *q;
   int ch,data,val;
   char title[255];
   do{
      printf("\nEnter 1 to add an element in the Queue");
      printf("\nEnter 2 to delete an element from the Queue");
      printf("\nEnter 3 to see the Queue");
      printf("\nEnter 4 to open your Queue from a file");
      printf("\nEnter 5 to save your Queue in a file");
      printf("\nEnter 6 to search for a specific value");
      printf("\nEnter 0 to exit\n");
      printf("\nEnter your choice ");
      scanf("%d",&ch);  
   
      switch (ch)
      {
      case 1: 
         printf("\nEnter the element to include ");
         scanf("%d",&data);
         enQueue(data);   
         break;

      case 2:
      
         deQueue();
          
         break;
      case 3:
         q=front;
         while (q!=NULL)
         {
            printf("%d ",q->data);
            q=q->next;
         }
         break;
      case 4:
         printf("\nEnter file name ");
         scanf("%s",title); 
         openFile(title);  
         break;   
      case 5:
         printf("\nEnter file name ");
         scanf("%s",title); 
         saveFile(title);  
         break;
      case 6:
         printf("\nEnter a value ");
         scanf("%d", &val);
         search(val);
         if (search(val)==true)
         {
            printf("\nTrue\n");
         }else{
            printf("\nFalse\n");
         }

          
         break;
      case 0:
         return 0;   
      default:
         printf("\nWrong Input\n");
         break;
      }
   }while (ch!=0);
   return 1;


}

bool search(int val){
   struct Queue *curr;
   curr=front;
   while (curr!=NULL)
   {
      if (curr->data==val)
      {
         return true;
      }
      curr=curr->next;
   }
   return false;
};

void openFile(char title[]){
   
   FILE *f = fopen(title, "r");
   int c;
   if (f == NULL)
   {
      printf("File is empty!\n");
      return;
   }
   front=NULL;
   rear=NULL;
   
    while (!feof(f))
    {
        fscanf(f ,"%d ", &c);
        enQueue(c);
    }
   printf("\n");
   fclose(f);
}

void saveFile(char title[]){
   struct Queue *q;
   q=front;
   FILE *f = fopen(title, "w");
   if (f == NULL)
   {
      printf("Error creating file!\n");
   }
   while (q!=NULL)
   {
      fprintf(f,"%d ",q->data);
      q=q->next;
   }
   fclose(f);
}




//function to add an element
void enQueue(int data){
   struct Queue *temp;
   temp = malloc(sizeof(struct Queue));
   if(temp==NULL)
   {
      printf("\nCannot allocate memory");
      return;
   }
   temp->data=data;//the value is entered in the list
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
void deQueue()
{
   struct Queue *temp;
   temp=front;
   if(front==NULL)
   {
      printf("\nQueue is empty\n");
      return;
   }
   else
   {
      front=front->next;
      free(temp);
      
   }
   
}

