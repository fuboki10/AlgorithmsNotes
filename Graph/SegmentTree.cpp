    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int N=1e5+10;
    int n,a[N];
    // Size= 4*N as we assume there're children to the leaves
    int seg[4*N],lazy[4*N];
     
     
    void propagate(int ind)
    {
    	/*
    	 * There was a mistake in propagate function explanation.
    	 * Once I got a new lazy I update my lazy and seg values,
    	 * when I propagate my lazy I relax it to my children lazy and seg too.
    	 * So the lazy carry the updates to my children not to me as we described.
    	 * It's a matter of placing "propagate" call in the traversing function,
    	 * so I edited it to be placed as we discussed in the session
    	 */
    	seg[ind*2+1]|=lazy[ind];
    	seg[ind*2+2]|=lazy[ind];
    	lazy[ind*2+1]|=lazy[ind];
    	lazy[ind*2+2]|=lazy[ind];
    	lazy[ind]=0;
    }
     
    // I use the array a[N] as 1-based, so l=1, r=n
    void Build(int ind=0, int l=1, int r=n)
    {
    	if(l==r)
    	{
    		seg[ind]=a[l];
    		return;
    	}
    	int mid=l+(r-l)/2;
    	/* Note:
    	 * at 0-based segment tree => leftChild=ind*2+1, rightChild=ind*2+2
    	 * at 1-based segment tree => leftChild=ind*2, rightChild=ind*2+1
    	 */
    	Build(ind*2+1,l,mid);
    	Build(ind*2+2,mid+1,r);
    	seg[ind]=seg[ind*2+1]|seg[ind*2+2];
    }
     
    void UpdateIndex(int qind,int qv, int ind=0, int l=1, int r=n)
    {
    	if(qind<l || qind>r)	return;
    	if(l==r)
    	{
    		seg[ind]|=qv;
    		return;
    	}
    	int mid=l+(r-l)/2;
    	UpdateIndex(qind,qv,ind*2+1,l,mid);
    	UpdateIndex(qind,qv,ind*2+2,mid+1,r);
    	seg[ind]=seg[ind*2+1]|seg[ind*2+2];
    }
     
    void UpdateRange(int qx, int qy, int qv, int ind=0, int l=1, int r=n)
    {
    	if(r<qx || l>qy)	return;
    	if(l>=qx && r<=qy)
    	{
    		seg[ind]|=qv;
    		lazy[ind]|=qv;
    		return;
    	}
    	int mid=l+(r-l)/2;
    	propagate(ind);
    	UpdateRange(qx,qy,qv,ind*2+1,l,mid);
    	UpdateRange(qx,qy,qv,ind*2+2,mid+1,r);
    	seg[ind]=seg[ind*2+1]|seg[ind*2+2];
    }
     
    int getAns(int qx, int qy, int ind=0, int l=1, int r=n, bool isRangeProblem=0)
    {
    	if(r<qx || l>qy)	return 0;
    	if(l>=qx && r<=qy)	return seg[ind];
    	int mid=l+(r-l)/2;
    	if(isRangeProblem)	propagate(ind);
    	int r1=getAns(qx,qy,ind*2+1,l,mid,isRangeProblem);
    	int r2=getAns(qx,qy,ind*2+2,mid+1,r,isRangeProblem);
    	return r1|r2;
    }
     
    int main()
    {
     
    }
     