#include <iostream>
using namespace std;

struct node // Nodes to represent adjacent vertices
{
int id;
node *link;
};

struct gnode // Array of vertices
{
int id;
int visited;
node *eptr;
};

class queue // For BFS
{
int q[10], f, r;
public:
queue() { f=-1; r=-1;}
int empty()
{
if (f==-1) return 1;
else return 0;
}
void enqueue(int x)
{
if (r==10)
{

cout<<"Queue overflows" << endl;
return;
}

q[++r] = x;
if (f==-1) f++;
return;
}
int dequeue()

{
int x;
if (r==-1)
{
cout << "Queue Empty" << endl;
return -1;
}
x=q[f];
if (f==r)
f=r=-1;

else
f--;
return x;
}
};
class graph
{
gnode v[11];
int n;
int count;
public:
void constructGraph()
{
int m, adj;
node *p;
cout << "Enter no. of vertices : ";
cin >> n;
for (int i=1; i<=n; i++)
{
cout << "Enter the id of the vertex (1 to 10) ";
cin >> v[i].id;
v[i].eptr=NULL;
cout << "Enter no. of adjacent vertices for " << v[i].id << " ";
cin >> m;
for (int j=1; j<=m; j++) // Construct the Adjacency List of the vertex i
{
cout << "Enter the id of "<< j << "th adjacent vertex for " << v[i].id << ": ";
p=new node;
cin>>p->id;
p->link = v[i].eptr;
v[i].eptr = p;
}
}
}
void initialize()
{

count = 0;
for (int i=1; i<=n; i++)
{
v[i].visited=0;
}
}
void BFS(int u)
{
queue Q;
node *t;
int w;
initialize();
v[u].visited=1;
Q.enqueue(u);
while (!Q.empty())
{
u=Q.dequeue();
t=v[u].eptr;
while (t!= NULL)
{
w=t->id;
if (v[w].visited == 0)
{
v[w].visited = 1;
cout << v[u].id << " --> " << v[w].id << endl;
Q.enqueue(w);
}
t = t->link;
}
}
}
void DFS(int u)
{
node *t;
int w;
v[u].visited=1;
t=v[u].eptr;
while (t!=NULL)
{
w=t->id;
if (v[w].visited == 0)
{
cout <<v[u].id << " --> " << v[w].id << endl;
DFS(w);
}
t=t->link;
}

}
void display()
{
cout<<"############ Given Graph ###############"
cout <<"No.\tName\tAdjacent Node List " << endl;
for (int i=1; i<=n; i++)
{
cout << i << "\t" << v[i].id << "\t";
node *t=v[i].eptr;
while (t!=NULL)
{
cout << "--> " << t->id;
t=t->link;
}
cout << endl;
}
cout << "Edges used in the traversal are : " << endl;
}
};
int main()
{
graph G;
int v, op;
G.constructGraph();
do
{
cout << "1- BFS 2- DFS 3- Exit \nEnter your option " << endl;
cin >> op;
G.display();
switch (op)
{
case 1:
{
cout << "Enter the index of starting vertex " ;
cin >> v;
G.initialize();
cout<<"############ BFS ###############"
G.BFS(v);
break;
}
case 2:
{
cout << "Enter the index of starting vertex ";
cin >> v;
G.initialize();
cout<<"############ DFS ###############"

G.DFS(v);
break;
}
}
}
while (op=3);
}
