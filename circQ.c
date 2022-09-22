#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Queue
{
   struct Queue *next;
   int data;
};


struct Queue *front;
struct Queue *rear;
char fileName[255];



void enQueue(int);//function is declared
void deQueue();//function is declared
void printElements();//func to see the queue
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
         printElements();
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
      case 0:
         return 0;   
      default:
         printf("\nWrong Input\n");
         break;
      }
   }while (ch!=0);
   return 1;


}



void printElements(){
   struct Queue *q;
   q=front;
   if (q==NULL){
      return;
   }
         while (q!=NULL && q!=rear)
         {
            printf("%d ",q->data);
            q=q->next;
         }
      printf("%d ",q->data);
}

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
   strcpy(fileName, title);
}

void saveFile(char title[]){
   struct Queue *q;
   q=front;
   FILE *f = fopen(title, "w");
   if (f == NULL)
   {
      printf("Error creating file!\n");
   }
   if (q==NULL){
      return;
   }
    while (q!=NULL && q!=rear)
         {
            fprintf(f,"%d ",q->data);
            q=q->next;
         }
      fprintf(f,"%d ",q->data);
   fclose(f);
}







//function to add an element
void enQueue(int value)
{
   struct Queue *temp;
   temp = malloc(sizeof(struct Queue));
    temp->data = value;
    if (front == NULL)
        front = temp;
    else
        rear->next = temp;
  
    rear = temp;
    rear->next = front;
}

//to delete an element
void deQueue()
{
   
    if (front == NULL) {
        printf("Queue is empty");
        return;
    }
  
    // If this is the last node to be deleted
    
    if (front == rear) {
        free(front);
        front = NULL;
        rear = NULL;
    }
    else // There are more than one nodes
    {
        struct Queue* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
  
}

