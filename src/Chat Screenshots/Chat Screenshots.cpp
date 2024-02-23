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
void dfs(LL curr, vector<int>& v, vector<set<int>>& adj, bool& works, LL par){
    if(v[curr] == 1){
        works = false;
        return;
    }
    if(v[curr] == 2){
        return;
    }
    v[curr] = 1;
    for(auto it: adj[curr]){
        dfs(it, v, adj, works, curr);
    }
    v[curr] = 2;
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
    cin >> tt;
    while(tt--){
        LL n, m;
        cin >> n >> m;
        vector<set<int>> adj(n + 1);
        vector<vector<LL> > a(m, vector<LL> (n));
        vector<int> v(n + 1, 0);
        vector<int> ind(n + 1, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> a[i][j];
            }
            for(int j=2; j<n; j++){
                adj[a[i][j-1]].insert(a[i][j]);
                ind[a[i][j]]++;
            }
        }
        bool works = true;
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                if(v[a[i][j]] != 2){
                    // cout << a[i][j] << " ";
                    dfs(a[i][j], v, adj, works, -1);
                }
            }
        }  

        cout << (works ? "YES\n" : "NO\n");
    }

    cout.flush();
    return 0;
}