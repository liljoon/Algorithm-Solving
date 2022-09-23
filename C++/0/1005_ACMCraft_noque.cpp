#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> build_time;
vector<int> dp;

int solve(int n)
{
	if(dp[n]!= -1)
		return dp[n];
	int max_build = 0;
	for(int i=0;i<adj[n].size();i++)
	{
		max_build = max(max_build, solve(adj[n][i]));
	}
	dp[n] = build_time[n] + max_build;
	return (dp[n]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,k;
		cin>>n>>k;
		build_time = vector<int>(n);
		adj = vector<vector<int> >(n);
		dp = vector<int>(n,-1);
		for(int i=0; i<n; i++)
			cin>>build_time[i];
		for(int i=0;i<k;i++)
		{
			int a,b;
			cin>>a>>b;
			adj[b-1].push_back(a-1);
		}
		int to_build;
		cin>>to_build;
		cout<<solve(to_build - 1)<<endl;
	}
}

