//ami pari na ar pari na
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
#define                pb push_back 
#define                mp make_pair
#define                in insert  
#define                fi first
#define                se second
#define                ll long long 
#define                ld long double
#define                ull unsigned long long 
#define                pi acos(-1)
#define                test() int T,t=1;cin>>T;
#define                all(x) (x).begin(),(x).end()
#define                sz(x) (int)(x.size())
#define                int    long long int
#define bits(x)        __builtin_popcountll(x)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
              
#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif

const ll INF = 1e18 ;
const int N = 3e5 + 10  ;

// Global Variablea
int dx[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy[]={1, -1, 0, 0, 1, -1, 1, -1};

//priority_queue <int, vector<int>, greater<int>> pq;
//---------------------------------------------------------------------------------------------
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
ll Ceil(ll dividend , ll divisor){return (dividend / divisor +  (dividend % divisor ? 1 : 0));}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
long long binpow(long long a, long long b) { if (b == 0) return 1;long long res = binpow(a, b / 2);if (b % 2) return res * res * a; else return res * res;}
int binpowMod(int a, int b , int mod ){ if(b == 0) return 1 ; int ans = 1 ;while(b > 0){if(b & 1) ans = (ans * a) % mod ;a = (a * a) % mod ;b = b >> 1;}return ans % mod;}
//---------------------------------------------------------------------------------------------

int dfs(int vertex, vector<vector<int>>& graph, vector<int> &visited){
   int cnt = 1;
   visited[vertex] = 1 ;
   for(auto child : graph[vertex]){
      if(visited[child] == 0){
          cnt += dfs(child, graph, visited);
      }
   }

   return cnt;
}
void solve(){
   vector<pair<char, char>> adj;
   string str;
   while(1){
      cin >> str;
      if(str[0] == '*') break;
      char u = str[1], v = str[3];
      adj.push_back({u, v});
   }

   cin >> str;
   vector<int> nodes;
   for(auto it  : str){
      if(it != ',') nodes.push_back(it - 'A');
   }

   vector<vector<int>> graph(26);
   for(auto it : adj){
      int u = it.first - 'A', v = it.second - 'A';
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   vector<int> visited(26, 0);
   vector<int> sum(26, 0);

   for(int i = 0; i < sz(nodes); i += 1){
      if(visited[nodes[i]] == 0){
         sum[nodes[i]] = dfs(nodes[i], graph, visited);
      }
   }
   int tree = 0, acorn = 0;
   for(int i = 0; i < sz(nodes); i += 1){
      if(sum[nodes[i]] > 1) tree += 1;
      else if(sum[nodes[i]] == 1) acorn += 1;
   }

   //dbg(tree, acorn);
   cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
}
int32_t main(){   
       ios_base::sync_with_stdio(false);cin.tie(NULL);
       // freopen("input.txt" , "r" , stdin) ;
       // freopen("output.txt" , "w" , stdout) ;
       int testCase = 1 , T = 1;
       cin >> T;            
       while(testCase <= T){
              //cout << "Case #" << testCase << ": ";
              //cout << "Case " << testCase << ": " ;   
              //cout << "Scenario #" << testCase << ": " ;
              solve();
              testCase++; 
       } 

       return 0; 
}      