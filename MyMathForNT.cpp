#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define nl "\n"
#define sp " "

#define fixed(n) fixed << setprecision(n)


using namespace std;

void Fast_IO(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}

// ----------------------------- {code} ----------------------------




struct MyMathForNT{

    MyMathForNT(){}

    ll extended_euclid(ll a, ll b, ll &x, ll &y){
        if(a < 0){
            ll r = extended_euclid(-a, b, x, y);
            x *= -1;
            return r;
        }
        if(b < 0){
            ll r = extended_euclid(a, -b, x, y);
            y *= -1;
            return r;
        }
        if(b == 0){
            x = 1, y = 0;
            return a;
        }
        ll g = extended_euclid(b , a % b, y , x);
        y -= (a / b) * x;
        return g;
    }

    
    ll ldioph(ll a, ll b, ll c, ll &x, ll &y, ll &found){
        ll g = extended_euclid(a, b, x, y);
        if((found = c % g == 0)){
            x *= (c / g), y *= (c / g);
        }
        return g;
    }

    void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
        x += cnt * b;
        y -= cnt * a;
    }

    ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
        ll x, y, found, g = ldioph(a, b, c, x, y, found);
        if (!found) return 0;

        a /= g;
        b /= g;

        ll sign_a = a > 0 ? +1 : -1;
        ll sign_b = b > 0 ? +1 : -1;

        // find the interval of x:
        shift_solution(x, y, a, b, (minx - x) / b);
        if (x < minx)
            shift_solution(x, y, a, b, sign_b);
        if (x > maxx)
            return 0;
        ll lx1 = x;

        shift_solution(x, y, a, b, (maxx - x) / b);
        if (x > maxx)
            shift_solution(x, y, a, b, -sign_b);
        ll rx1 = x;



        // find the interval of y:
        shift_solution(x, y, a, b, -(miny - y) / a);
        if (y < miny)
            shift_solution(x, y, a, b, -sign_a);
        if (y > maxy)
            return 0;
        ll lx2 = x;

        shift_solution(x, y, a, b, -(maxy - y) / a);
        if (y > maxy)
            shift_solution(x, y, a, b, sign_a);
        ll rx2 = x;


        if (lx2 > rx2) swap(lx2, rx2);

        // get intersection:
        ll lx = max(lx1, lx2);
        ll rx = min(rx1, rx2);

        if (lx > rx) return 0;

        return (rx - lx) / abs(b) + 1;
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



