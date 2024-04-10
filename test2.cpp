#include "test.h"

int Test(int v[],int n)
{

	int max = INT_MIN;
	for (int i = 1; i < n; i += 1)
	{
		v[i] = v[i - 1] + v[i];

	}
	cout << endl;
	for (int i = 0; i < n; i += 1)
	{
		int temp = v[i];
		if (i < n - 1)
		{
			int temp2 = v[n - 1];
			for (int j = n - 1; j > i; j -= 1)
			{
				if (v[j] > temp2)
				{
					temp2 = v[j];
				}
			}
			temp = temp2 - temp;
		}

		if (temp > max)
		{
			max = temp;
		}

	}
	cout << max;
	return max;
}
int main()
{
	int a[6] = { -1,4,5,9,-1,-9 };
	int n = 6;
	int re = Test(a, n);

}