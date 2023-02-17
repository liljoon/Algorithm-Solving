#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,m;
    cin>>n>>m;
    vector<long long> impossible(n);
    vector<vector<pair<long long,long long>>> adj(n);
    for(long long i=0;i<n;i++)
        cin>>impossible[i];
    impossible[n-1] = 0;
    for(long long i=0;i<m;i++)
    {
        long long a,b,t;
        cin>>a>>b>>t;
        if (!impossible[b] && !impossible[a])
        {
            adj[a].push_back({b, t});
            adj[b].push_back({a, t});
        }
    }
    priority_queue<pair<long long,long long>, vector< pair<long long,long long>>, greater<pair<long long,long long>>> pque;
    vector<long long> dist(n, INT64_MAX);
    dist[0] = 0;
    pque.push(make_pair(0, 0));
    while (!pque.empty())
    {
        long long cur_dist = pque.top().first;
        long long cur_node = pque.top().second;
        pque.pop();

        if (cur_dist > dist[cur_node])
            continue;
        
        for(long long i=0;i<adj[cur_node].size();i++)
        {
            long long next_node = adj[cur_node][i].first;
            long long next_dist = cur_dist + adj[cur_node][i].second;

            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pque.push(make_pair(next_dist, next_node));
            }
        }

    }
    if (dist[n-1]==INT64_MAX)
        cout<< -1 <<endl;
    else
        cout<<dist[n - 1]<< "\n";
}