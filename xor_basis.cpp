#include <bits/stdc++.h>

#define ll long long
#define int long long
#define ld long double

#define nl "\n"
#define sp " "
#define EPS (1e-12)

#define all(p) p.begin(), p.end()
#define fixed(n) fixed << setprecision(n)

using namespace std;

void Fast_IO()
{
// ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int>
struct XOR_Basis{
    int n;
    vector<T> Matrix;
    vector<int> bit_last_inx;

    XOR_Basis(int __n){
        n = __n;
        Matrix.assign(n, 0);
        bit_last_inx.assign(n, -1);
    }
    
    int get_msb(T x){ // most significant bit
        for(int i = sizeof(x) * 8 - 1; i >= 0; i--){
            if((x >> i) & 1) return i;
        }
        return -1;
    }
    void add_element(T x){
        T min_to_add = x;
        int msb = -1;
        for(int i = n - 1; i >= 0; i--){
            min_to_add = min(min_to_add, min_to_add ^ Matrix[i]);
            if(msb == -1 && ((min_to_add >> i) & 1)) msb = i;
        }
        if(min_to_add){
            Matrix[msb] = min_to_add;
        }
    }

    void add_element(T x, int inx){
        for(int i = n - 1; i >= 0; i--){
            if(!((x >> i) & 1)) continue;
            if(bit_last_inx[i] < inx){
                swap(Matrix[i], x);
                swap(inx, bit_last_inx);
            }
            x ^= Matrix[i];
        }
    }

    T get_max_sum(){
        T ans = 0;
        for(int i = n - 1; i >= 0; i--){
            ans = max(ans, ans ^ Matrix[i]);
        }
        return ans;
    }

    T get_max_sum(int inx){
        T ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(bit_last_inx[i] >= inx) ans = max(ans, ans ^ Matrix[i]);
        } 
        return ans;
    }

    int get_rank_of_matrix(){
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (Matrix[i] != 0);
        }
        return ans;
    }

    bool can_make(T x){
        T min_to_add = x;
        for(int i = n - 1; i >= 0; i--){
            min_to_add = min(min_to_add, min_to_add ^ Matrix[i]);
        }
        return min_to_add == 0;
    }

};


void Solve(){
    
    
}

// static bool start = []() {preCalc(); return true; }();
signed main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Fast_IO();

	int tc = 1;
	cin >> tc;


	while (tc--)
	{
		Solve();
	}

	return 0;
}
