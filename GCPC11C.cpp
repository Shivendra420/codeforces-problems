#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=b;i>=a;i--)
#define gcd(a,b) __gcd(a,b)
#define MOD 1000000007
#define scll(t) scanf("%lld",&t)
#define sclf(t) scanf("%lf", &t)
#define scst(t) scanf("%s", &t)
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<b?a:b)
#define MEM(a,b) memset(a, (b), sizeof(a))
#define all(v) v.begin(), v.end()
const double pi=acos(-1.0);
typedef pair<ll, ll> PII;
typedef vector<ll> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<ll,ll> MPII;
typedef set<ll> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

template <typename T> inline void write(T x)
{
	ll i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x/= 10;
	}while(x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

void read(ll &x)
{
    bool neg=false;
    register ll c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}






ll t,n,h,in[10001],total=0,cnt=0;
bool vis[10001];
vector<int>inp[10001];

int s,e;
struct node
{
	int start;
	int end;
};
typedef struct node node;



stack<int> q;
queue<int> q2;
stack<int> st;
int DFS(vector<int> a[], int i, int visited[], int processing[] , node v[])
{
	int x=0;
	processing[i]=1;
	v[i].start=s++;
	for(int m=0;m<a[i].size();m++)
	{
		int nvnv=a[i].at(m);
		if(visited[nvnv]==0 && processing[nvnv]==0)
		{
			x=DFS(a,nvnv,visited,processing,v);
			if(x==-1)
			return -1;
		}
		else
		{
			if(v[nvnv].start<v[i].start && processing[nvnv]==1)
			return -1;
		}
	}
	visited[i]=1;
	processing[i]=0;
	v[i].end=s++;
	q.push(i);
	return 1;
}

int  do_DFS(vector<int> a[],int n)
{
	s=1;
	int visited[10005];
	int processing[10005];
	node v[10005];
	queue<int> emptyq;
	swap(q2,emptyq);
	stack<int> emptys;
	swap(q,emptys);
	int x=0;
	memset(visited,0,sizeof(visited));
	memset(processing,0,sizeof(processing));
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			x=DFS(a,i,visited,processing,v);
			if(x==-1)
			{
				printf("recheck hints\n");
				return -1;
			}
		}
	}
	return 1;
}


void func(ll node){
//	cnt++;
	vis[node]=true;
	for(ll i=0;i<inp[node].size();i++){
		if(!vis[inp[node][i]]){
			func(inp[node][i]);
		}
	}
	st.push(node);
}
map<pair<ll, ll> , ll>mpp;
int main()
{
	read(t);
	while(t--){
		for(ll i=0;i<10001;i++){
			inp[i].clear();
		}
		cnt=0;
		MEM(in,0);
		MEM(vis,false);
		
		
		cin>>n>>h;
		mpp.clear();
		if(h==0){
		//	cout<<"hello\n";
			if(n==1)cout<<"1\n";
			else cout<<"missing hints\n";
		}
		else{
			for(ll i=0;i<h;i++){
				ll a,b;
				cin>>a>>b;
				if(!mpp[mp(a,b)]){
				inp[a].pb(b);
				mpp[mp(a,b)]=1;
				in[b]++;
				}
			}
		//	cout<<"m = "<<m<<endl;
			
			int nbn = do_DFS(inp,n);
			if(nbn==1){
			
				ll indeg=0,start;
				
				for(ll i=1;i<=n;i++){
					if(!in[i]){
						indeg++;
						start=i;
					}
				}
		//		cout<<"indeg = "<<indeg<<endl;
				if(indeg>1) cout<<"missing hints\n";
				else {
					func(start);
					ll arr[10001],pos=-1;
					while(!st.empty()){
						arr[++pos]=st.top();
						st.pop();
					}
					ll flag=0;
					for(ll i=0;i<n-1;i++){
						if(!mpp[mp(arr[i], arr[i+1])]){
							cout<<"missing hints\n";
							flag=1;
							break;
						}
					}
					if(flag==0){
						for(ll i=0;i<n;i++){
							cout<<arr[i]<<" ";
						}
						cout<<"\n";
					}
				}
			}
		}
	}
	return 0;
}




















