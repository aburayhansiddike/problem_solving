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

vector<int> graph[N];
vector<int> visited(N, 0);
vector<vector<int>> dp(N, vector<int>(30, -1ll));

void getPair(int vertex, vector<pair<int, int>> &p){
    visited[vertex] = 1;
    for(auto child : graph[vertex]){
        if(visited[child] == 0){
            p.push_back({vertex, child});
            getPair(child, p);
        }
    }
}

int dfs(int vertex, int val, int k){

    int temp = INF, cnt = 0;
    for(int i = 1; i <= k; i += 1){
        if(i != val and dp[vertex][i] != -1ll){
            cnt += 1ll;
            temp = min(temp, dp[vertex][i]);
        }
    }

    if(cnt + 1 == k) return temp;

    for(int i = 1; i <= k; i += 1){
        if(i != val and dp[vertex][i] == -1ll){
            int sum = 0;
            for(auto child: graph[vertex]){
                sum += dfs(child,  i, k);
            }
            // if(vertex == 1){
            //     cout << i << ' ' << sum << '\n';
            // }
            dp[vertex][i] = sum + i;
        }
    }

    int mn =INF;
    for(int i = 1; i <= k; i += 1){
        if(i != val){
            mn = min(mn, dp[vertex][i]);
        }
    }
    return mn;

}
void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n - 1; i += 1){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(n == 1){
        cout << "1\n";
        return;
    }

    if(k == 1){
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> p;
    getPair(1, p);

    for(int i = 1; i <= n; i += 1) graph[i].clear();
    for(auto it : p) graph[it.first].push_back(it.second);

    int mn = dfs(1ll, -1ll, k);
    cout << mn << '\n';
}
int32_t main(){   
       ios_base::sync_with_stdio(false);cin.tie(NULL);
       // freopen("input.txt" , "r" , stdin) ;
       // freopen("output.txt" , "w" , stdout) ;
       int testCase = 1 , T = 1;
       //cin >> T;            
       while(testCase <= T){
              //cout << "Case #" << testCase << ": ";
              //cout << "Case " << testCase << ": " ;   
              //cout << "Scenario #" << testCase << ": " ;
              solve();
              testCase++; 
       } 

       return 0; 
}      