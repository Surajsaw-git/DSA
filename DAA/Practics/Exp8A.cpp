#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u,v,w;
};

int parent[9];

int find(int x)
{
    if(parent[x]==x)
        return x;
    return parent[x]=find(parent[x]);
}

int main()
{
    int n=9;

    int a[9][9] = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    Edge e[20];
    int m=0;

    // Matrix -> edges
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i][j])
                e[m++]={i,j,a[i][j]};

    // Sort by weight
    sort(e,e+m,[](Edge x,Edge y)
    {
        return x.w<y.w;
    });

    for(int i=0;i<n;i++)
        parent[i]=i;

    int total=0, count=0;

    cout<<"Kruskal MST:\n";

    for(int i=0;i<m && count<n-1;i++)
    {
        int x=find(e[i].u);
        int y=find(e[i].v);

        if(x!=y)
        {
            cout<<e[i].u<<" - "<<e[i].v
                <<" = "<<e[i].w<<endl;

            total+=e[i].w;
            parent[x]=y;
            count++;
        }
    }

    cout<<"Total = "<<total;

    return 0;
}
