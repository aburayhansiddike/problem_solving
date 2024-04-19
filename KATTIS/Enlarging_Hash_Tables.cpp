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


void solve(){
    string key, text;
    getline(cin >> ws, key);
    getline(cin >> ws, text);

    string rule = "";
    set<char> ace;
    for(int i = 0; i < sz(key); i += 1){
        if(key[i] == ' ') continue;
        if(ace.find(key[i]) == ace.end()){
            ace.insert(key[i]);
            rule += key[i];
        }
    }

    for(char c = 'a'; c <= 'z'; c++){
        if(c == 'q') continue;
        if(ace.find(c) == ace.end()){
            rule += c;
        }
    }
    vector<int> row(26), col(26);
    dbg(rule);
    vector<vector<char>>v(5, vector<char>(5));
    int temp = 0, idx = 0;
    while(temp < 5){
        for(int j = 0; j < 5; j += 1) v[temp][j] = rule[idx++];
        temp += 1;
    }

    for(int i = 0; i < 5; i += 1){
        for(int j = 0; j < 5; j += 1){
            char c = v[i][j];
            row[c - 'a'] = i;
            col[c - 'a'] = j;
        }
    }

    string str = "";
    for(int i = 0; i < sz(text); i += 1){
        if(text[i] == ' ') continue;
        str += text[i];
    }
    string ans = "";
    string tempStr = "";
    for(int i = 0; i < sz(str); i += 1){

        tempStr += str[i];
        if(i == sz(str) - 1 and sz(tempStr) == 1) tempStr += "x";

        if(sz(tempStr) == 2){
            if(tempStr.front() == tempStr.back()){
                tempStr.pop_back();
                tempStr += "x";
                i -= 1;
            }
            if(row[tempStr[0] - 'a'] == row[tempStr[1] - 'a']){
                ans += v[row[tempStr[0] - 'a']][(col[tempStr[0] - 'a'] + 1) % 5];
                ans += v[row[tempStr[1] - 'a']][(col[tempStr[1] - 'a'] + 1) % 5];
            }else if(col[tempStr[0] - 'a'] == col[tempStr[1] - 'a']){
                ans += v[(row[tempStr[0] - 'a'] + 1) % 5][col[tempStr[0] - 'a']];
                ans += v[(row[tempStr[1] - 'a'] + 1) % 5][col[tempStr[1] - 'a']];
            }else{
                ans += v[row[tempStr[0] - 'a']][col[tempStr[1] - 'a']];
                ans += v[row[tempStr[1] - 'a']][col[tempStr[0] - 'a']];
            }
            tempStr.clear();
        }
    }

    for(int i = 0; i < sz(ans); i += 1){
        cout << (char)toupper(ans[i]);
    }
    cout << '\n';
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