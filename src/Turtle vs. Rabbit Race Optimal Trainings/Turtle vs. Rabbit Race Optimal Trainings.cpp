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
        LL n;
        cin >> n;
        vector<LL> a(n + 1), pre(n + 1);
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] + a[i];
        }
        LL q;
        cin >> q;
        for(int i=0; i<q; i++){
            LL l, u;
            cin >> l >> u;
            LL r = n;
            LL strt = l-1;
            while(l < r){
                LL m = l + (r - l + 1)/2;
                if(pre[m] - pre[strt] > u){
                    r = m-1;
                }
                else{
                    l = m;
                }
            }
            LL first = pre[l] - pre[strt];
            LL miss = ((u - first) * (u - first + 1))/2;
            if(l == n){
                cout << l << " ";
                continue;
            }
            LL sec = pre[l + 1] - pre[strt];
            LL neg = ((sec - u) * (sec - u + 1))/2;
            if(miss < neg){
                cout << l << " ";
            }
            else{
                cout << l + 1 << " " ;
            }
        }
        cout << "\n";
    }

    cout.flush();
    return 0;
}