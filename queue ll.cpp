#include<iostream>
using namespace std;
struct Node
{
int data;
struct Node* link;
};

struct head
{
int count;
struct Node* front;
struct Node* rear;

};

void createqueue(struct head *p)
{
p->front=NULL;
p->rear=NULL;
p->count=0;
}



void enqueue(int datain,struct head *p)
{
struct Node* pnew=new Node;
pnew->data=datain;
pnew->link=NULL;

if(p->front==NULL)//first ele insert
{
p->front=pnew;
p->rear=pnew;
}
else
{
p->rear->link=pnew;//linking first pnew
p->rear=pnew;//rear denoting pnew
}
p->count+=1;
}

void dequeue(struct head* p)
{
if(p->front==NULL)
{
cout<<"empty list"<<endl;
}

else
{
cout<<"removed ele",p->front->data;
p->front=p->front->link;
p->count-=1;
}
}

void display(struct head* p)
{
if(p->front==NULL)
{
cout<<"empty list no ele's";
}
else
{
while(p->front!=NULL)
{
cout<<p->front->data<<" ";
p->front=p->front->link;
p->count-=1;
}
}
}
void queuecount(struct head* p)
{
cout<<"count num:"<<p->count<<endl;
}

int main()
{
int data,choice;
struct head p;
createqueue(&p);
do
{
cout<<"1.enqueue"<<endl;
cout<<"2.dequeue"<<endl;
cout<<"3.display"<<endl;
cout<<"4.count"<<endl;
cout<<"enter choice";
cin>>choice;
switch(choice)
{
case 1:
cout<<"enter ele:";
cin>>data;
enqueue(data,&p);
break;

case 2:
dequeue(&p);
break;

case 3:
display(&p);
break;

case 4:
queuecount(&p);
break;
}
}
while(choice!=5);
}







