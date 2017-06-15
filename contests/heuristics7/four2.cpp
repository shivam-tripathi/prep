#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <long long> numgg(long n){
vector <long long> vec(n+1,0);

for(int i=2;i<=n;i++)
 for(int k=i;k<=n;k+=i)
   vec[k]++;
return vec;
}


vector<ll> dvisors (ll n) {
	vector<ll>vec;
	for(ll i=1;i*i<=n;i++)
	    {
	        if(n%i==0)
	            vec.push_back(i);
	        if(n%i==0&&n%(n/i)==0)
	            vec.push_back((n/i));
	    }
	return vec;
}

ll n, k, d;
ll dp[1005][2];

ll fin(ll rem, bool co){
    if(rem==0) return co;
    if(rem<0) return 0;
	ll &ret=dp[rem][co];
    if(ret!=-1) return ret;

    long long lim=min(rem,k);
    ret=0;
    for( ll i=1;i<=lim;i++) { ret+=fin(rem-i,((i>=d)||co)); ret%=1000000007; }


    return ret;
}

int main()
{
    memset(dp,-1,sizeof dp);

    cin >> n>> k >> d;
    cout << fin(n,0);

	return 0;
}