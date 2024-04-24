#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define str string

#define nl "\n"
#define sp " "
#define EPS (1e-9)

#define sz(x) x.size()
#define vec vector

#define all(p) p.begin(),p.end()
#define rall(p) p.rbegin(),p.rend()
#define Mod(a, b) ((((a) % (b)) + (b)) % (b))
#define fixed(n) fixed << setprecision(n)
#define FastCode ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>  
#define ordered_set tree<long long, null_type,greater_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> 


using namespace std;

ll MOD = 1e9 + 7;
ll MOD2 = 998244353;

ll gcd(ll a,ll b){return ((a==0||b==0)?a+b:(a%b==0)?b:gcd(b,a%b));}
ll lcm(ll a,ll b){return a/gcd(a,b) * b;}
ll fastPower(ll a, ll b,ll m) {
    if(b==0) return 1;
    ll ans = fastPower(a,b/2,m);ans=((ans%m)*(ans%m))%m;
    return ((b&1)?((a%m)*(ans))%m:ans%m);
}
ll myPower(ll a,ll b){
    if(b==0) return 1;
    ll ans = myPower(a,b/2);return ((b&1)? a*ans*ans:ans*ans);
}
ll mod_inv(ll x,ll M = (1e9+7)){return (fastPower(x,M - 2,M))%M;}

ll max(ll a,ll b){return (a>=b) ? a : b;}
ll min(ll a,ll b){return (a>=b) ? b : a;}


int dcmp(ld A, ld B){
    if(fabsl(A - B) >= EPS) {
        if(A > B) return 1;
        else return -1;}
    return 0;
}

void Fast_IO(){
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}

// ----------------------------- {code} ----------------------------


template <typename T = int, int Base = 1> struct SCC
{
    int n, dfsTime;
    vector<vector<int>> adj, comps;
    vector<int> vis, isInStack, compN, lowLink, dfsN;
    stack<int> dfsStack;
    SCC(int numberOfNodes){
        n = numberOfNodes;
        dfsTime = 1;
        adj.assign(n+2, vector<int>());
        vis = isInStack = compN = vector<int>(n+2, 0);
        lowLink = dfsN = vector<int>(n+2, -1);
    }

    void rightEdge(int from, int to){
        adj[from].push_back(to);
    }

    void buildSCC(){
        for(int i = 1; i <= n; i++){
            if(dfsN[i] == -1) buildSCC(i);
        }
    }

    void buildSCC(int node){
        lowLink[node] = dfsN[node] = dfsTime++; isInStack[node] = 1;
        dfsStack.push(node);

        for(auto next_node:adj[node]){
            if(dfsN[next_node] == -1){  
                buildSCC(next_node);
                lowLink[node] = min(lowLink[node], lowLink[next_node]);
            }
            else if(isInStack[next_node]){
                lowLink[node] = min(lowLink[node], dfsN[next_node]);
            }
        }

        // is it a root?
        if(lowLink[node] == dfsN[node]){
            // create a new comp 
            comps.push_back(vector<int>());
            int x = -1;
            while(x != node){
                x = dfsStack.top(); dfsStack.pop(); isInStack[x] = 0;
                comps.back().push_back(x);
                compN[x] = comps.size() - 1;
            }
        }
    }



};


void Solve(){

}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Fast_IO();

    int tc = 1;
    // cin>>tc;
    while (tc--)
    {   
        Solve();
    }
    
    return 0;
}



