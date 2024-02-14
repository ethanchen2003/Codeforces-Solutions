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
        vector<LL> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int left = 0;
        int right = n-1;
        for(int i=1; i<n; i++){
            if(a[i] != a[i-1]){
                left = i;
                break;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(a[i] != a[i+1]){
                right = i;
                break;
            }
        }
        LL ans = 0;
        if(a[0] == a[n-1]){
            if(right == n-1 && left == 0){
                ans = 0;
            }
            else{
                ans = right - left + 1;
            }
        }
        else{
            ans = min((LL)right + 1, (LL) n - left);
        }
        cout << ans << "\n";
    }

    cout.flush();
    return 0;
}