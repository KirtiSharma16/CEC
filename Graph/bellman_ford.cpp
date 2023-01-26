#include<bits/stdc++.h>
using namespace std;
void bellman(vector<vector<int>> &adj,int src,int n)
{
    vector<int> dist(n,1e9);
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto x:adj)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            if(dist[u]!=1e9 && (dist[u]+wt<dist[v]))
            dist[v]=dist[u]+wt;
        }
    }
    for(auto x:adj)
    {
        int u=x[0];
        int v=x[1];
        int wt=x[2];
        if(dist[u]!=1e9 && (dist[u]+wt<dist[v]))
        {
            cout<<"Negative edge weight cycle";
            return;
        }
    }
    for(auto i:dist)
    cout<<i<<" ";
}
int main()
{
    int n,m,src;
    cin>>n>>m;
    vector<vector<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj.push_back({u,v,wt});
    }
    cin>>src;
    bellman(adj,src,n);
    return 0;
}
