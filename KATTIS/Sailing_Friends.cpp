#include<bits/stdc++.h>
using namespace std;

vector<int>vis, v;
vector<vector<int>>adj;
int flag = 0;

void dfs(int node){
	vis[node] = 1;
	if(v[node] == 1) flag = 1;
	for(auto c: adj[node]){
		if(!vis[c])
			dfs(c);
	}
}

void solve(){
    int n, b, m, x, l, r;
    cin>>n>>b>>m;
    v = vector<int>(n+1, 0);
    adj = vector<vector<int>>(n+1);
    vis = vector<int>(n+1, 0);

    for(int i = 0; i < b; i++){
    	cin>>x;
    	v[x] = 1;
    }

    for(int i = 0; i < m; i++){
    	cin>>l>>r;
    	adj[l].push_back(r);
    	adj[r].push_back(l);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		flag = 0;
    		dfs(i);
    		if(flag == 0) cnt++;
    	}
    }
    cout<<cnt<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int test = 1;
    // cin>>test;
    while(test--)
        solve();
}