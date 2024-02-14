#include<bits/stdc++.h>
using namespace std;
typedef int64_t LL;
typedef vector<int> vi;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
 
//var 
 
int main(){
    #ifndef ONLINE_JUDGE
        //for getting input from input.txt
        freopen("input.txt", "r", stdin);
        //for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
 
    LL tt;
    cin >> tt;
    while(tt--){
        LL n, x, y;
        cin >> n >> x >> y;
        vector<LL> a(n);
        map<pii, vector<LL>> m;
        for(int i=0; i<n; i++){
            cin >> a[i];
            m[{a[i] % x, a[i] % y}].pb(i);
        }
        LL ans = 0;
        for(int i=0; i< n; i++){
            LL mod_x = a[i] % x;
            LL mod_y = a[i] % y;
            if(mod_x == 0){
                mod_x = x;
            }
            LL val = m[{x - mod_x , mod_y}].size();
            ans += val;
            if(val && ((2 * mod_x) % x )== 0){
                ans--;
            }
        }
        cout << ans/2 << "\n";
    }
 
    cout.flush();
    return 0;
}