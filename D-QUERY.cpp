#include<bits/stdc++.h>
#define ull unsigned long long
#define pii pair<long long , long long>
#define mp make_pair 
#define pb push_back
#define MAX	1000010
#define MAX_LOG 17
#define mpp map<ll , ll>
#define hmp hash_map<ll , ll>
#define gcd __gcd
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
const int MAXN = 1e6+5; 
const int MAXV = 5e5;

ll BITree[MAXN+1], n, q, ans[200005];
vector< vector<ll> >v;
mpp pre;

bool compare(const vector< ll >&a , const vector< ll >&b)
{
	if(a[0]==b[0])
	{
		return (a[2]<b[2]);
	}
	return (a[0]<b[0]); 
}

void update(ll i, ll val) {
    for(; i <= n; i += i&-i) {
        BITree[i] += val;
    }
}

ll getSum(ll i) {
    ll sum = 0;
    for(; i > 0; i -= i&-i) {
        sum += BITree[i];
    }
    return sum;
}


int main()
{
    memset(BITree, 0, sizeof(BITree));
    
	scanf("%lld", &n);
	
	ll a[n+1];
	for(ll i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld", &x);
		a[i]=x;
		vector <ll>aux;
		aux.pb(i);
		aux.pb(x);
		aux.pb(0);
		v.pb(aux);
	}
    
	scanf("%lld" ,&q);
	ll query=0;
	while(q--)
	{
		ll x,y;
		scanf("%lld%lld", &x, &y);
		vector <ll>aux;
		aux.pb(y);
		aux.pb(x);
		aux.pb(++query);
		v.pb(aux);
	}
	
	sort(v.begin(), v.end(), compare);
/*	for(int i=0;i<v.size();i++)
	{
		cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
	}
*/  
	for(ll i=0;i<v.size();i++)
	{
		if(v[i][2]==0)
		{
			ll val=v[i][1];
			if(!pre[v[i][1]])
			{
				update(v[i][0], 1);
				pre[v[i][1]]=v[i][0];
			}
			else
			{
				update(pre[v[i][1]], -1);
				update(v[i][0], 1);
				pre[v[i][1]]=v[i][0];
			}
		}
		else
		{
			ll x=v[i][1], y=v[i][0];
			ans[v[i][2]]=getSum(y)-getSum(x);
			ll val=a[x];
			if(pre[val]==x)
			ans[v[i][2]]++;
		//	cout<<getSum(y)-getSum(x-1)<<endl;
		}
	}
	for(ll i=1;i<=query;i++)
	{
		printf("%lld\n" ,ans[i]);
	}
	
	return 0;
}
