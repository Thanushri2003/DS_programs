#include<iostream>
using namespace std;

#define infinite 999
int n;
char graph[10];
int wtgraph[10][10];

int minwt(int weight[],bool mstset[])
{
int min=infinite,minindex=0;
for(int i=0;i<n;i++)
{
if(mstset[i]==false && weight[i]<min)
{
min=weight[i];
minindex=i;

}

}
return minindex;
}

void printmst(int parent[])
{
cout<<"edge   weight"<<endl;
for(int i=1;i<n;i++)
{
cout<<graph[parent[i]]<<"to"<<graph[i]<<"  "<<wtgraph[i][parent[i]];
cout<<endl;
}
}

void mst()
{
int parent[10];
int weight[10];
bool mstset[10];


int u;
for(int i=0;i<n;i++)
{
weight[i]=infinite;
mstset[i]=false;
}

parent[0]=-1;
weight[0]=0;

for(int count=0;count<n-1;count++)
{
   u=minwt(weight,mstset);
   mstset[u]=true;
   for(int v=0;v<n;v++)
  {
   if(wtgraph[u][v]!=0 && mstset[v]==false && weight[v]>wtgraph[u][v])
{
parent[v]=u;
weight[v]=wtgraph[u][v];
}
}
}
printmst(parent);
}

int main()
{
cout<<"enter no of ver:";
cin>>n;

for(int i=0;i<n;i++)
{cout<<"enter vertex"<<i+1<<":";
cin>>graph[i];
}


for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{if(i!=j)
{
cout<<"enter weight of:"<<graph[i]<<"to"<<graph[j];
cin>>wtgraph[i][j];
}
}
}
mst();
}





