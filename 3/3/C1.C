#include<stdio.h>
#include<string.h>
#include<math.h>

#define ll long long

ll dp[6001][6001];
ll mod = 998244353;

ll ncr(ll n, ll r){
	if(n < r)
		return 0;
	if(!r || !n)
		return 1;
	if(r == 1)
		return n;
	if(dp[n][r] != -1)
		return dp[n][r];
	return dp[n][r] = (ncr(n-1, r) + ncr(n-1, r-1)) % mod;
}
int main(){
	memset(dp, -1, sizeof(dp));
	ll a, b, c, d, e, f;
	scanf("%lld %lld %lld %lld %lld %lld", &a ,&b, &c, &d, &e, &f);
	ll p = abs(a-d);
	ll q = abs(b-e);
	ll r = abs(c-f);
	printf("%lld", (ncr(p + q + r, q + r) % mod) * (ncr(q + r, r) % mod) % mod);
}