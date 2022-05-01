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
	
int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s, t;
	cin >> s >> t;
    
    int m = s.size();
    int n = t.size();

    int dp[3333][3333];
    for(int i = 0; i <= m; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
 
    for(int i = 1; i <= m; i++){
    	for(int j = 1; j <= n; j++){
    		if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
    		else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    	}
    }
    
    string ans = "";
    while(n && m){
    	if(s[m - 1] == t[n - 1]) ans += s[m - 1], m--, n--;
    	else if(dp[m - 1][n] > dp[m][n - 1]) m--;
    	else n--;
    }
    reverse(all(ans));
    cout << ans << endl;

 

    

	return 0;
}
