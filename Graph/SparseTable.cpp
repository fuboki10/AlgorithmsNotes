#include <bits/stdc++.h>
     
using namespace std;

const int MAXN = 1e5 + 10;
const int K = floor(log2(MAXN)) + 1;

int log[MAXN+1];
int ST[MAXN][K + 1];

void computeLog()
{
	log[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	    log[i] = log[i/2] + 1;
}

void build(int array[], int N)
{
	for (int i = 0; i < N; i++)
		ST[i][0] = array[i];

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= N; i++)
			ST[i][j] = f(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}

int getSum(int L, int R)
{
	int sum = 0;
	for (int j = K; j >= 0; j--) {
	    if ((1 << j) <= R - L + 1) {
	        sum += ST[L][j];
	        L += 1 << j;
	    }
	}
}

int getAns(int L, int R)
{
	int j = log[R - L + 1];
	int ans = f(ST[L][j], ST[R - (1 << j) + 1][j]);
	return ans;
}


int main()
{
	
	return 0;
}