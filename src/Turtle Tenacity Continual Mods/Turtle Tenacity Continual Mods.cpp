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
        sort(a.begin(), a.end());
        if(a[1] != a[0]){
            cout << "YES\n";
            continue;
        }
        bool found = false;
        for(int i=1; i<n; i++){
            if(a[i] % a[0] != 0){
                found = true;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }

    cout.flush();
    return 0;
}