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


void solve(int n){
    vector<vector<int>> graph(n + 1);
    vector<int> cnt(n + 1, 0);
    vector<int> deg(n + 1, 0);

    for(int i = 1; i <= n; i += 1){
        int u;
        cin >> u;
        int x;
        cin >> x;
        cnt[i] = x;
        int d;
        cin >> d;
        for(int j = 0; j < d; j += 1){
            int v;
            cin >> v;
            graph[v].push_back(u);
            deg[u]++;
        }
    }


    queue<int> q;
    for(int i = 1; i <= n; i += 1){
        if(deg[i] == 0ll){
            q.push(i);
        }
    }

    int movesNeed = 0;
    while((int)q.size() > 0){
        int vertex = q.front();
        q.pop();

        if(sz(graph[vertex]) != 0){
            int par = graph[vertex][0];
            deg[par]--;

            if(deg[par] == 0) q.push(par);

            int diff = cnt[vertex] - 1;
            cnt[par] += diff;
            movesNeed += abs(diff);
        }
    }

    cout << movesNeed << '\n';
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
            int n;
            cin >> n;
            if(n == 0) break;
            solve(n);
            //testCase++; 
       } 

       return 0; 
}      