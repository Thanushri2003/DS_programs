#include<iostream>
using namespace std;
struct Node
{
int data;
struct Node* flink;
struct Node* blink;
};

struct head
{
int count;
struct Node* front;
struct Node* rear;
};

void createlist(struct head* head)
{

head->front=NULL;
head->rear=NULL;
head->count=0;

}

void insertnode(struct head* head,struct Node* ppre,int datain)
{
struct Node* pnew=new Node;
pnew->data=datain;
pnew->flink=NULL;
pnew->blink=NULL;

if(ppre==NULL)//first node
{
 if(head==NULL)//empty
 {
 head->front=pnew;
 head->rear=pnew;
 pnew->flink=NULL;
 pnew->blink=NULL;
 }
 
 else //before first node

 {
 pnew->blink=NULL;
 pnew->flink=head->front;
 head->front=pnew;
 }
}

else//middle or end
{
if(ppre->flink==NULL)//end
{
pnew->flink=NULL;
pnew->blink=ppre;
ppre->flink=pnew;
head->rear=pnew;
}

else//middle
{
 pnew->blink=ppre;        
pnew->flink=ppre->flink;
ppre->flink->blink=pnew;
ppre->flink=pnew;
}
}
head->count+=1;
}

void deletenode(struct Node* ppre,struct head* head)
{

if(head==NULL)
{
cout<<"EMPTY LIST";
}
else if(ppre==NULL)
{
if(head->count==1)
{
head->front=NULL;
head->rear=NULL;
}

else
{
head->front->flink->blink=NULL;
head->front=head->front->flink;
}
}

else
{
if(ppre->flink=NULL)//END
{
ppre->flink=NULL;
}
else
{
ppre->flink=ppre->flink->flink;
ppre->flink->flink->blink=ppre;
}
}


}
struct Node* search(struct head* head,int target)
{
struct Node* ploc,*ppre=NULL;
ploc=head->front;
while(ploc!=NULL && target>ploc->data)
{

ppre=ploc;
ploc=ploc->flink;
}
return ppre;
}

struct Node* locate(struct head* head,int target)
{
struct Node* ploc,*ppre=NULL;
ploc=head->front;
while(ploc!=NULL && target!=ploc->data)
{

ppre=ploc;
ploc=ploc->flink;
}
return ppre;
}

void display(struct head* head)
{
struct Node* ploc;
ploc=head->front;
if(ploc==NULL)
{
    cout<<"empty list";
}
else
{
while(ploc!=NULL)
{
cout<<ploc->data;
ploc=ploc->flink;
}
}
}



int main()
{
int ch,data;
struct head head;
struct Node* ppre=NULL;

createlist(&head);

cout<<"1.insert\n2.delete\n3.display\n4.exit";

do
{
cout<<"\nenter choice:";
cin>>ch;

switch(ch)
{
case 1:
cout<<"\nenter ele to insert:";
cin>>data;
ppre=search(&head,data);
insertnode(&head,ppre,data);
break;

case 2:
cout<<"\nenter ele to delete:";
cin>>data;
ppre=locate(&head,data);
deletenode(ppre,&head);
break;

case 3:
display(&head);
break;

case 4:
cout<<"exit";
break;
}
}
while(ch!=4);
}


 





 
 





