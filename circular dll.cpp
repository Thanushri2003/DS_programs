
#include<iostream>
using namespace std;

struct Node
{
int data;
Node* flink;
Node* blink;
};

struct Head
{
int count;
Node* front;
Node* rear;
};

void createList(Head* head)
{
head->count=0;
head->front=NULL;
head->rear=NULL;
}
void insertCLL(Head* head,Node* ppre,int dataIn)
{
Node* pnew=new Node;
pnew->data=dataIn;
if(ppre==NULL)//as first node
{
if(head->front==NULL)//empty list
{
head->front=pnew;
head->rear=pnew;
pnew->blink=pnew;
pnew->flink=pnew;

}
else //adding before 1st node
{
pnew->flink=head->front;
pnew->blink=head->rear;
head->front->blink=pnew;  
head->front=pnew;
head->rear->flink=pnew;
}
}
else//mid or end
{
if(ppre->flink==head->front)//end
{
ppre->flink=pnew;
pnew->blink=ppre;
pnew->flink=head->front;
head->rear=pnew;
head->front->blink=pnew;
}
else//mid
{
pnew->flink=ppre->flink;
ppre->flink->blink=pnew;
ppre->flink=pnew;
pnew->blink=ppre;
}
}
head->count+=1;
}


void deleteCLL(Head* head,Node* ppre)
{
if(ppre==NULL)
{
if(head->count==0)//empty
{
cout<<"Empty list"<<endl;
}
else
{
if(head->count==1)//1 node
{
head->front=NULL;
head->rear=NULL;
}
else
{
head->front=head->front->flink;
head->rear->flink=head->front;
head->front->blink=head->rear;
}
}
}
else//mid or end
{
if(ppre->flink->flink==head->front)//end
{
ppre->flink=head->front;
head->rear=ppre;
}
else//mid
{
ppre->flink=ppre->flink->flink;
ppre->flink->blink=ppre;
}
}
head->count-=1;
}


Node* locateList(Head* head,int target)
{
int countCLL=1;
Node* ppre=NULL;
Node* ploc=head->front;
while(countCLL<=head->count && target>ploc->data)
{
ppre=ploc;
ploc=ploc->flink;
countCLL++;
}
return ppre;
}


void display(Head* head)
{
int countCLL=1;
Node* ploc=head->front;
while(countCLL<=head->count)
{
cout<<ploc->data<<"\t";
ploc=ploc->flink;
countCLL++;
}
cout<<endl;
}


int main()
{
Head head;
Node* ppre=NULL;
createList(&head);
int data,choice;
cout<<"1.Insert 2.Delete 3.Display 4.Exit"<<endl;
do
{
cout<<"Enter your choice?";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter data to insert?";
cin>>data;
ppre=locateList(&head,data);
insertCLL(&head,ppre,data);
break;
case 2:
cout<<"Enter data to delete?";
cin>>data;
ppre=locateList(&head,data);
deleteCLL(&head,ppre);
break;
case 3:
cout<<"List:"<<endl;
display(&head);
break;
case 4:
break;
}
}while(choice!=4);
}
.
