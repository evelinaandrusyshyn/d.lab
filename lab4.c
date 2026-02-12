#include <iostream>
#include <limits>
using namespace std;
int main() 
{
    const int n=7;
    const int INF=1e9;
    int graph[n][n]={
        {0,16,0,4,0,0,0},
        {0,0,19,0,8,0,0},
        {0,0,0,0,25,0,0},
        {0,12,0,0,0,6,0},
        {0,0,0,28,0,0,5},
        {0,0,0,0,30,0,0},
        {0,0,0,0,0,9,0}
    };
    int dist[n];
    bool used[n];
    int parent[n];
    for (int i=0; i<n; i++) 
    {
        dist[i] = INF;
        used[i] = false;
        parent[i] = -1;
    }
    dist[0]=0;
    for(int i=0; i<n; i++) 
    {
        int v=-1;
        for(int j=0; j<n; j++)
            if(!used[j] && (v==-1 || dist[j]<dist[v]))
                v=j;
        if(dist[v]==INF) break;
        used[v]=true;
        for (int to=0; to<n; to++) 
        {
            if (graph[v][to]!=0 && dist[v]+graph[v][to]<dist[to]) 
            {
                dist[to]=dist[v]+graph[v][to];
                parent[to]=v;
            }
        }
    }
    char name[]={'a','b','c','d','e','f','g'};
    cout << "Найкоротші відстані від вершини a:\n";
    for(int i=0; i<n; i++) 
    {
        if(dist[i]==INF) cout<<name[i]<<": недосяжна\n";
        else cout<<name[i]<<": "<<dist[i]<<endl;
    }
    int target=6;
    cout<<"\nНайкоротша відстань від a до g="<<dist[target]<<endl;
    cout<<"Шлях: ";
    int path[n], len=0;
    for(int v=target; v!=-1; v=parent[v])
        path[len++]=v;
    for(int i=len-1; i>=0; i--) 
    {
        cout<<name[path[i]];
        if (i>0) cout<<"->";
    }
    cout<<endl;
    return 0;
}
