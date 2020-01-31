#include<stdio.h>
#include<string.h>
#include<math.h>

#define int long long

int dp[6005][6005];
int mod = 998244353;

int ncr(int n, int r){
	if(n<r)
		return 0;
	if(!r||!n)
		return 1;
	if(r==1)
		return n;
	if(dp[n][r]!=-1)
		return dp[n][r];
	return dp[n][r]=(ncr(n-1,r)+ncr(n-1,r-1))%mod;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int a, b, c, d, e, f;
	scanf("%lld %lld %lld %lld %lld %lld", &a,&b,&c,&d,&e,&f);
	int p = abs(a-d);
	int q = abs(b-e);
	int r = abs(c-f);
	printf("%lld", (ncr(p+q+r,q+r)%mod)*(ncr(q+r, r)%mod)%mod);
}