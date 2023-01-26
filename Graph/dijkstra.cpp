#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<pair<int,int>>> &adj,int src,int n)
{
    vector<int>dist(n+1,1e9);
    set<pair<int,int>> s;
    dist[src]=0;
    s.insert({src,0});
    while(!s.empty())
    {
        auto x= *(s.begin());
        s.erase(x);
        for(auto i:adj[x.first])
        {
            if(dist[i.first]>x.second+i.second)
            {
                s.erase({i.first,dist[i.first]});
                dist[i.first]=x.second+i.second;
                s.insert({i.first,dist[i.first]});
            }
        }
    }
    cout<<"Distances from source "<<src<<endl;
    for(int i=1;i<=n;i++)
    cout<<dist[i]<<" ";
}
int main()
{
    int n,m,src;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    cin>>src;
    dijkstra(adj,src,n);
    return 0;
}
