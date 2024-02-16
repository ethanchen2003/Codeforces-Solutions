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
        LL n, k;
        cin >> n >> k;
        if(k >= (n + n - 1) * 2 - 1){
            cout << (k + 2)/2 << "\n";
        }
        else{
            cout << (k + 1)/2 << "\n";
        }
    }

    cout.flush();
    return 0;
}