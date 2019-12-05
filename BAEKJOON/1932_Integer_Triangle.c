#include <stdio.h>

#define MAX(a, b)		({__typeof__ (a) _a = (a); \
						__typeof__ (b) _b = (b); \
						_a > _b ? _a : _b; })

#define MAX_N		500
#define MAX_VAL		9999

int tri[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main(void)
{
	int i, j;
	int n;
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= i; j++)
		{
			scanf("%d", &tri[i][j]);
		}
	}

	dp[0][0] = tri[0][0];

	for(i = 1; i < n; i++)
	{
		for(j = 0; j <= i; j++)
		{
			if(j == 0)
			{
				dp[i][j] = dp[i-1][j] + tri[i][j];
			}
			else if(j == i)
			{
				dp[i][j] = dp[i-1][j-1] + tri[i][j];
			}
			else
			{
				dp[i][j] = MAX(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
			}
		}
	}

	int max = dp[n-1][0];
	for(i = 1; i < n; i++)
	{
		max = MAX(dp[n-1][i], max);
	}

	printf("%d\n", max);

	return 0;
}
