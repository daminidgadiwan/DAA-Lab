#include <stdio.h>

int a[100], subset[100];
int ans[100][100], len[100];
int count = 0;
int n, target;

void backtrack(int index, int sum, int k)
{
	if (sum == target)
	{
		len[count] = k;
		for (int i = 0; i < k; i++)
			ans[count][i] = subset[i];
		count++;
		return;
	}

	if (index >= n)
		return;

	subset[k] = a[index];
	backtrack(index + 1, sum + a[index], k + 1);

	backtrack(index + 1, sum, k);
}
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &target);

	backtrack(0, 0, 0);

	if (count == 0)
	{
		printf("-1");
	}
	else
	{
		for (int i = count - 1; i >= 0; i--)
		{
			for (int j = 0; j < len[i]; j++)
			{
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
