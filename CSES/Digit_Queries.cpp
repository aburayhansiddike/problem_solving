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

//---------------------------------------------------------------------------------------------
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
ll Ceil(ll dividend , ll divisor){return (dividend / divisor +  (dividend % divisor ? 1 : 0));}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
long long binpow(long long a, long long b) { if (b == 0) return 1;long long res = binpow(a, b / 2);if (b % 2) return res * res * a; else return res * res;}
int binpowMod(int a, int b , int mod ){ if(b == 0) return 1 ; int ans = 1 ;while(b > 0){if(b & 1) ans = (ans * a) % mod ;a = (a * a) % mod ;b = b >> 1;}return ans % mod;}
//---------------------------------------------------------------------------------------------

vector<int > digit(20 , 0ll) ;
void solve(){
      int n ;
      cin >> n ;
      int last = 0ll ;
      for(int i = 1 ; i <= 17 ;  i += 1){
          if(n >= digit[i]){
              last = i ;
              n -= digit[i] ;
          }
      }

      int ans = 0ll ;
      if(n == 0){
          ans = (binpow(10 , last) - 1ll) % 10 ;
      }else {
            int base = binpow(10 , last) - 1ll + (n / (last + 1ll))  ;
            int extra = n % (last + 1ll) ;
            if(extra == 0){
                ans = base % 10 ;
            }else{
                 base += 1ll ;
                 string temp = to_string(base) ;
                 ans = temp[extra - 1] - '0' ;
            }
      }

      cout << ans << '\n' ;
}
void preCal(){
       int base = 9 ;
       for(int i = 1 ; i <= 17 ; i += 1){
              digit[i] = base * i ;
              base *= 10 ; 
       }
}
int32_t main(){   
       ios_base::sync_with_stdio(false);cin.tie(NULL);
       // freopen("input.txt" , "r" , stdin) ;
       // freopen("output.txt" , "w" , stdout) ;
       preCal() ;             
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
