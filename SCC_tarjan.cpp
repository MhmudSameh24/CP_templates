#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define nl "\n"
#define sp " "

#define fixed(n) fixed << setprecision(n)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>  
#define ordered_set tree<long long, null_type,greater_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;

void Fast_IO(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}

// ----------------------------- {code} ----------------------------

template <typename T = int, int Base = 1, bool isUndirected = false> struct SCC
{
    int n, dfsTime;
    vector<vector<int>> adj, comps;
    vector<vector<int>> componentAdj;
    vector<int> vis, isInStack, compN, lowLink, dfsN;
    vector<pair<int, int>> bridges;
    stack<int> dfsStack;
    SCC(int numberOfNodes, vector<vector<int>> &the_adj){
        n = numberOfNodes;
        dfsTime = 0;
        adj = the_adj; // adj.assign(n+2, vector<int>());
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

    void buildSCC(int node, int parent = -1){
        lowLink[node] = dfsN[node] = dfsTime++; isInStack[node] = 1;
        dfsStack.push(node);

        for(auto next_node:adj[node]){
            if(dfsN[next_node] == -1){  
                buildSCC(next_node);
                lowLink[node] = min(lowLink[node], lowLink[next_node]);

                // get the bridges
                if(lowLink[next_node] == dfsN[next_node]) bridges.push_back({node, next_node});
            }
            else if((!isUndirected && isInStack[next_node]) || (isUndirected && next_node != parent)){
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


    void buildComponentGraph(){
        componentAdj.assign(comps.size(), vector<int> ());
        for(int u = Base; u <= n; u++){
            for(auto &v:adj[u]){
                if(compN[u] != compN[v]){ 
                    componentAdj[compN[u]].push_back(compN[v]); 
                    if(isUndirected) componentAdj[compN[v]].push_back(compN[u]);
                }
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



