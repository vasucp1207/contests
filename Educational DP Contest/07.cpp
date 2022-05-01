#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>

// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

// const int mod = 1e9 + 7;

using namespace std;

int n, m;
vector<int> g[100005];
vector<int> dp(100005, -1);
vector<int> visit(100005, 0);

int solve(int node){

	if(g[node].size() == 0) return 0;
	int ans = 0;
	if(dp[node] != -1) return dp[node];

	for(int i: g[node]){
		ans = max(ans, 1 + solve(i));
	}

	dp[node] = ans;
	return ans;
}
	
int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> m;

	for(int i = 0; i < 100005; i++){
		g[i].clear();
		dp[i] = -1;
		visit[i] = 0;
 	} 

	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}


	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			ans = max(ans, solve(i));
		}
	}
	cout << ans << endl;

 

    

	return 0;
}
