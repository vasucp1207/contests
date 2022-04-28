#include<bits/stdc++.h>

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
 
int main() {
 
	ll n, cap;
	cin >> n >> cap;
	
	vector<ll> wt(n), vl(n);
	for(int i = 0; i < n; i++){
		cin >> wt[i] >> vl[i];
	}
	
	ll dp[n + 1][cap + 1];
	for(ll i = 0; i <= cap; i++){
		dp[0][i] = 0;
	}
	for(ll i = 0; i <= n; i++){
		dp[i][0] = 0;
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= cap; j++){
			if(wt[i - 1] > j){
				dp[i][j] = dp[i - 1][j];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], vl[i - 1] + dp[i - 1][j - wt[i - 1]]);
			}
		}
	}
	
	cout << dp[n][cap] << endl;
	
	
 
	return 0;
}
