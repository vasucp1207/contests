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

ll n, cap;
vector<ll> wt(105), vl(105);
ll dp[105][100005];

ll solve(ll item, ll val){
	
	if(val == 0) return 0;	
	if(item < 0) return 1e17;

	if(dp[item][val] != -1) return dp[item][val];
	
	ll ans;
	ans = solve(item - 1, val);
	
	if(val - vl[item] >= 0)
		ans = min(ans, wt[item] + solve(item - 1, val - vl[item]));
	
	dp[item][val] = ans;
	return ans;
}
 
int main() {
 
	cin >> n >> cap;
	
	for(int i = 0; i < n; i++){
		cin >> wt[i] >> vl[i];
	}
	
	memset(dp, -1, sizeof(dp));
	
	ll ans = 0;
	for(int i = 1e5; i >= 0; i--){
		if(solve(n - 1, i) <= cap){
			cout << i << endl;
			break;
		}
	}
	
	
 
	return 0;
}
