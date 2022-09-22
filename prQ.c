#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Queue
{
   struct Queue *next;
   int data;
   int priority;
};


struct Queue *front;
struct Queue *rear;
char fileName[255];



void enQueue(int, int) ;//function is declared
void deQueue();//function is declared
void printElements();//func to see the queue
void saveFile();//func to save a file
void openFile();//func to open a file

int main(){
   struct Queue *q;
   int ch,data,val,prior;
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
         printf("\nEnter the priority of your element ");
         scanf("%d",&prior);
         enQueue(data, prior);   
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
         if (fileName!=NULL)
         {
            saveFile(fileName);
            printf("\nChanges Saved\n");
         }
         else{
         printf("\nEnter file name ");
         scanf("%s",title); 
         saveFile(title);
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



void printElements(){
   struct Queue *q;
   q=front;
         while (q!=NULL)
         {
            printf("%d, %d \n",q->data, q->priority);
            q=q->next;
         }
}


void openFile(char title[]){
   FILE *f = fopen(title, "r");
   int c, p;
   if (f == NULL)
   {
      printf("File is empty!\n");
      return;
   }
   front=NULL;
   rear=NULL;
   
    while (!feof(f))
    {
        fscanf(f ,"%d, %d \n", &c,&p);
        enQueue(c, p);
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
   while (q!=NULL)
   {
      fprintf(f,"%d, %d \n",q->data, q->priority);
      q=q->next;
   }
   fclose(f);
}



//function to add an element
void enQueue(int data, int prio){
   struct Queue *temp;
   struct Queue *newNode;
   struct Queue *current;
   newNode = malloc(sizeof(struct Queue));
   if(newNode==NULL)
   {
      printf("\nCannot allocate memory");
      return;
   }
   newNode->priority=prio;
   newNode->data=data;//the value is entered in the list
   newNode->next=NULL;
   if(front==NULL)
   {
      front=newNode;
      rear=newNode;
   }
    else
    {
        
        current=front;
        if (current->priority>newNode->priority)
        {
            newNode->next=current;
            front=newNode;
        }
        else{
        while (current->next!=NULL && current->next->priority<newNode->priority)
        {
            
            current=current->next;
        }
        
        newNode->next=current->next;
        current->next=newNode;
        }    
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

