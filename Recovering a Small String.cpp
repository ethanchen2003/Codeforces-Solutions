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
        vector<LL> ans(3, 1);
        n -= 3;
        for(int i=2; i>=0; i--){
            ans[i] += min(n, (LL)25);
            n -= 25;
            if(n <= 0){
                break;
            }
        }
        for(int i=0; i<3; i++){
            char c = 'a' + (ans[i] - 1);
            cout << c;
        }
        cout << "\n";
    }

    cout.flush();
    return 0;
}