#include<bits/stdc++.h>
using namespace std;
int main()
{
    int V,E;
    cin>>V>>E;
    int s,e,wt;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++)
    {
        cin>>s>>e>>wt;
        adj[s].push_back(make_pair(e,wt));
        adj[e].push_back(make_pair(s,wt));
    }
    vector<int>parent(V,-1);
    vector<bool>mst(V,false);
    vector<int>key(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
    key[0]=0;
    parent[0]=-1;
    q.push({0,0});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        mst[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mst[v]==false && weight<key[v])
            {
                parent[v]=u;
                key[v]=weight;
                q.push({key[v],v});
            }
        }
    }
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<"-"<<i<<endl;
    }
}