#include<iostream>
using namespace std;

struct node
{
int data;
node* link;
};

struct Head
{
int count;
node* link;
};

void create(struct Head* head)
{
head->count=0;
head->link=NULL;
}

void insertnode(struct Head* head,struct node* ppre,int datain)
{
struct node* pnew=new node;
pnew->data=datain;
pnew->link=NULL;

if(ppre==NULL)
{
if(head->link==NULL)//first node
{
head->link=pnew;
pnew->link=NULL;
}
else //as first node
{
pnew->link=head->link;
head->link=pnew;

}
head->count+=1;

}

else//middle or end
{

pnew->link=ppre->link;
ppre->link=pnew;

head->count+=1;

}
}

struct node* search(struct Head* head,int target)
{
struct node* ploc,
struct node*ppre=NULL;
ploc=head->link;
 if(ploc->link==NULL)
{
cout<<"empty list";
}
else
{
while(ploc!=NULL && target>ploc->data)
{
ppre=ploc;
ploc=ploc->link;
}
return ppre;
}
}

void deletenode(struct Head* head,struct node* ppre)
{
if(ppre==NULL)
{
if(head->link==NULL)
{
cout<<"empty list";
}
else if(head->count==1)
{
head->link=NULL;
}
else
{
head->link=head->link->link;
}
head->count-=1;
}

else
{
ppre->link=ppre->link->link;
head->count-=1;
}
}


struct node* locate(struct Head* head,int target)
{
struct node* ploc,*ppre=NULL;
ploc=head->link;
 if(ploc->link==NULL)
{
cout<<"empty list";
}
else
{
while(ploc!=NULL && target!=ploc->data)
{
ppre=ploc;
ploc=ploc->link;
}
return ppre;
}
}


void display(struct Head* head)
{
struct node* ploc;
ploc=head->link;

while(ploc!=NULL)
{
cout<<"elements:";
cout<<ploc->data;
ploc=ploc->link;
}
}

int main()
{
int ch,data;
struct Head head;
struct node* ppre=NULL;

create(&head);

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
deletenode(&head,ppre);
break;

case 3:
display(&head);
break;

case 4:
cout<<"exit";
break;
}
}
while(ch!=5);
}

 
