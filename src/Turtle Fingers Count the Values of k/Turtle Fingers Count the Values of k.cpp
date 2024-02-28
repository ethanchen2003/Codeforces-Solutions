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
        LL l, a, b;
        cin >> a >> b >> l;
        LL ans = 0;
        set<LL> cnt;
        for(int i=1; i<= l ; i *= a){
            if(l % i == 0){
                LL val = l / i;
                for(int j=1; j<= l; j *= b){
                    if(val % j == 0){
                        LL v = val/j;
                        if(cnt.count(v) == 0){
                            ans++;
                            cnt.insert(v);
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    cout.flush();
    return 0;
}