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
vector<LL> LIS(const std::vector<LL>& nums) {
   if (nums.empty()) return {};

    std::vector<LL> tails, predecessors(nums.size());
    int length = 0; // Length of LNDS

    for (int i = 0; i < nums.size(); ++i) {
        auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]);
        int index = it - tails.begin();

        if (it == tails.end()) {
            tails.push_back(nums[i]);
            length++;
        } else {
            *it = nums[i];
        }

        predecessors[i] = index > 0 ? std::distance(tails.begin(), std::lower_bound(tails.begin(), tails.end(), nums[i])) - 1 : -1;
    }

    // Reconstructing the subsequence
    std::vector<LL> lnds(length);
    for (int i = nums.size() - 1, j = length - 1; j >= 0; --i) {
        if (predecessors[i] == j - 1) {
            lnds[j] = nums[i];
            j--;
        }
    }
    for(auto it: lnds){
        cout << it << " ";
    }
    cout << "\n";
    return lnds;
}
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
    while(tt--){
        LL n;
        cin >> n;
        vector<LL> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        vector<LL> temp = lnds(a);
    }

    cout.flush();
    return 0;
}