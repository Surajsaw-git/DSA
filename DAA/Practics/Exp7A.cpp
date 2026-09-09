#include <iostream>
using namespace std;

int main()
{
    int n = 9, INF = 999;
    
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

    int key[9], parent[9];
    bool used[9] = {};

    for(int i=0;i<n;i++)
        key[i] = INF;

    key[0] = 0;

    for(int k=0;k<n;k++)
    {
        int u=-1;

        for(int i=0;i<n;i++)
            if(!used[i] && (u==-1 || key[i]<key[u]))
                u=i;

        used[u]=true;

        for(int v=0;v<n;v++)
            if(a[u][v] && !used[v] && a[u][v]<key[v])
            {
                key[v]=a[u][v];
                parent[v]=u;
            }
    }

    int total=0;

    cout<<"Prim MST:\n";

    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" - "<<i<<" = "<<key[i]<<endl;
        total+=key[i];
    }

    cout<<"Total = "<<total;

    return 0;
}
