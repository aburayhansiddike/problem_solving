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


vector<vector<int>> dp;
int rec(int idx, int ch, vector<vector<int>> &arr){
    if(idx >= sz(arr)) return 0;

    if(dp[idx][ch] != -1ll) return dp[idx][ch];
    
    int mx = 0;
    if(ch == 0){
        mx = max(mx, arr[idx][ch] + rec(idx + 1, 1, arr));
        mx = max(mx, arr[idx][ch] + rec(idx + 1, 2, arr));
    }else if(ch == 1){
        mx = max(mx, arr[idx][ch] + rec(idx + 1, 0, arr));
        mx = max(mx, arr[idx][ch] + rec(idx + 1, 2, arr));
    }else{
        mx = max(mx, arr[idx][ch] + rec(idx + 1, 0, arr));
        mx = max(mx, arr[idx][ch] + rec(idx + 1, 1, arr));
    }
    return dp[idx][ch] = mx;
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0; i < n; i += 1){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    dp.resize(n, vector<int>(3, -1ll));

    int mx = 0;
    mx = max(mx, rec(0, 0, arr));
    mx = max(mx, rec(0, 1, arr));
    mx = max(mx, rec(0, 2, arr));
    cout << mx << '\n';

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