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

const int mod = 1e9 + 7;

using namespace std;

vector<long double> ph;
int n;
vector<vector<long double> > dp;
	
int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
	#endif

	cin >> n;

	ph.resize(n);
	dp.resize(n + 1, vector<long double> (n + 1, 0));
	for(int i = 0; i < n; i++) cin >> ph[i];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= i; j++){
			if(i == 0){
				dp[i][j] = 1;
				continue;
			}
			long double p = ph[i - 1];
			dp[i][j] = 0;
			if(j > 0){
				dp[i][j] += p * dp[i - 1][j - 1];
			}
			dp[i][j] += (1 - p) * dp[i - 1][j];
		}
	}
	long double ans = 0;
	for(int heads = (n + 1) / 2; heads <= n; heads++){
		ans += dp[n][heads];
	}

	// take care of precision
	cout << fixed << setprecision(10) << ans << endl;



 

    

	return 0;
}
