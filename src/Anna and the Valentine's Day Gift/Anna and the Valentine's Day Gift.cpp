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
        LL n, m;
        cin >> n >> m;
        vector<LL> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        vector<LL> zero;
        LL ctr = 0;
        for(int i=0; i<n; i++){
            LL val = a[i];
            LL ctr_0 = 0;
            bool lead = false;
            while(val > 0){
                if(lead == false && val % 10 == 0){
                    ctr_0++;
                }
                else{
                    lead = true;
                }
                ctr++;
                val/=10;
            }
            zero.pb(ctr_0);
        }
        sort(zero.begin(), zero.end());
        for(int i=zero.size()-1; i>=0; i-=2){
            ctr -= zero[i];
        }
        cout << (ctr >= m + 1 ? "Sasha\n": "Anna\n");

    }
    

    cout.flush();
    return 0;
}