#include<bits/stdc++.h>
#define ll long long


const int maxN = 2e5+6;
int tree[4*maxN];
int lazy[4*maxN];
void range_update(int id,int left ,int right ,int lq ,int rq)
{
	if(lazy[id])
	{
		tree[id] = (right-left+1)-tree[id];
		if(left != right)
		{
			lazy[2*id] ^= 1;
			lazy[2*id+1] ^= 1;
		}
		lazy[id] = 0;
	}
	if( left > rq || right < lq)
		return;
	if(left >= lq && right <= rq)
	{
		tree[id] = (right-left+1)-tree[id];
		if(left != right)
		{
			lazy[2*id] ^= 1;
			lazy[2*id+1] ^= 1;
		}
		lazy[id] = 0;
		return;
	}
	int mid = (left+right)>>1;
	range_update(2*id,left,mid,lq,rq);
	range_update(2*id+1,mid+1,right,lq,rq);
	tree[id] = tree[2*id] + tree[2*id+1];
}

int range_query(int id,int left ,int right,int lq ,int rq)
{
	if(lazy[id])
	{
		tree[id] = (right-left+1)-tree[id];
		if(left != right)
		{
			lazy[2*id] ^= 1;
			lazy[2*id+1] ^= 1;
		}
		lazy[id] = 0;
	}
	if( left > rq || right < lq)
		return 0;
	if(left >= lq && right <= rq)
	{
		return tree[id];
	}
	int mid = (left+right)>>1;
	return	range_query(2*id,left,mid,lq,rq)+range_query(2*id+1,mid+1,right,lq,rq);
}

int main()
{
	int n , m; scanf("%d%d",&n,&m);
	while(m--)
	{
		int tp;
		scanf("%d",&tp);
		if(tp == 0)
		{
			int l , r;
			scanf("%d%d",&l,&r);
			range_update(1,0,n-1,l-1,r-1);
			//range_update  
		}
		else
		{
			int l , r;
			scanf("%d%d",&l,&r);
			printf("%d\n",range_query(1,0,n-1,l-1,r-1));
			//query  
		}
	}
    return 0;
}
