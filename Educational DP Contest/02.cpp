#include<bits/stdc++.h>

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
#define popcount(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){
	
	ll n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vector<ll> dp(n, 1e17);
	dp[n - 1] = 0;
	
	for(int i = n - 2; i >= 0; i--){
		for(int j = 1; j <= k; j++){
			if(i + j < n){
				dp[i] = min(dp[i], dp[i + j] + abs(a[i] - a[i + j]));
			}
		}
	}
	
	cout << dp[0] << endl;

	return 0;
}
