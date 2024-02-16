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
        LL coin, len, curr;
        cin >> coin >> len >> curr;
        LL sum = 1;
        coin--;
        bool works = true;
        for(int i=2; i<=len + 1; i++){
            if(sum > curr){
                works = false;
                break;
            }
            LL val = sum /coin + 1;
            sum += val;
            if(sum > curr){
                works = false;
                break;
            }
        }
        cout << (works ? "YES\n" : "NO\n");
    }

    cout.flush();
    return 0;
}