using namespace std;
#include<iostream>


void insertNodes(int, char, struct Node*);
struct Node
{
int data;
struct Node* flink; // Right child
struct Node* blink; // Left child
}*head;
void insertNodes(int i, char child, struct Node* parent)
{
int value;
cout << "Enter the value of the parent " << i++ << ": ";
cin >> value;
if (value == 0)
{
parent = NULL;
return;
}
struct Node* temp = new Node;
temp->data = value;
temp->blink = NULL;
temp->flink = NULL;
if (child == 'l')
{
parent->blink = temp;
}
else if (child == 'r')
{
parent->flink = temp;
}
else
head = temp;

parent = temp;
insertNodes(2 * i, 'l', parent);
insertNodes(2 * i + 1, 'r', parent);
}

void intraversal(struct Node* parent)

{
if (parent == NULL)
return;
else
{
intraversal(parent->blink); //Left child
cout << parent->data << "\t";
intraversal(parent->flink); //Right child
}
}

void pretraversal(struct Node* parent)

{
if (parent == NULL)
return;
else
{
cout << parent->data << "\t";
pretraversal(parent->blink); //Left child

pretraversal(parent->flink); //Right child
}
}

void posttraversal(struct Node* parent)

{
if (parent == NULL)
return;
else
{

posttraversal(parent->blink); //Left child
posttraversal(parent->flink); //Right child
cout << parent->data << "\t";
}
}



int main()
{
int ch;
head = NULL;
insertNodes(1, 'x', head);
cout<<"1.in\n2.pre\n3.post";
do
{
cout<<"enter traversal:";
cin>>ch;

switch(ch)
{
case 1:
   intraversal(head);
   break;
case 2:
   pretraversal(head);
   break;
case 3:
   posttraversal(head);
   break;


}
}
while(ch!=4);
}
