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

struct node{
	ll val;
	ll index;
	ll x;
	ll y;
	ll ident;
};

ll BITree[MAXN+1], n, q, ans[200005];

vector<node>a;

bool compare(const node& a , const node& b)
{
	if(a.val==b.val)
	{
		return (a.ident>b.ident);
	}
	return (a.val>b.val); 
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
	
	
	for(ll i=1;i<=n;i++)
	{
		ll x;
		node aa;
		scanf("%lld", &x);
		aa.val=x;
		aa.index=i;
		aa.ident=0;
		aa.x=0;
		aa.y=0;
		a.pb(aa);
	}
    
	scanf("%lld" ,&q);
	
	for(int i=1;i<=q;i++)
	{
		node aa;
		scanf("%lld%lld%lld", &aa.x, &aa.y, &aa.val);
		aa.index=i;
		aa.ident=1;
		a.push_back(aa);
	}
	
	sort(a.begin(), a.end(), compare);
	
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i].val<<" "<<a[i].index<<" "<<a[i].ident<<" "<<a[i].x<<" "<<a[i].y<<endl;
	}
	
	for(int i=0;i<a.size();i++)
	{
		if(a[i].ident==0)
		{
			update(a[i].index, 1);
		}
		else
		{
			ans[a[i].index]=getSum(a[i].y)-getSum(a[i].x-1);
		}
	}
	
	for(ll i=1;i<=q;i++)
	{
		printf("%lld\n", ans[i]);
	}
	return 0;
}
