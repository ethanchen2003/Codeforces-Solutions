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
        bool works = true;
        LL sum = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        LL each = sum / n;
        LL ctr = 0;
        for(int i=0; i<n; i++){
            ctr += a[i];
            if(ctr < each * (i + 1)){
                works = false;
                break;
            }
        }  
        cout << (works ? "YES\n" : "NO\n"); 
    }

    cout.flush();
    return 0;
}