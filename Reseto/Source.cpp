#include<stdio.h>

int result(int*);

int main()
{
	int a[2];
	int* n = a;
	for (int i = 0; i < 2; i++)
	{
		if (scanf_s("%d", &a[i]) != 1)
		{
			printf("EROR");
			return 1;
		}
		else if (a[i] < 2 && a[i] > 1000)
		{
			printf("EROR");
			return 1;
		}
	}
	if (*n <= *(n + 1))
	{
		printf("EROR");
		return 1;
	}
	printf("%d", result(n));
	return 0;
}

int result(int* x)
{
	int a[1000];
	int N = *x;
	int preK = 0;
	int K = *(x + 1);
	bool save = false;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 500; j++)
		{
			save = true;
			if ((i * j) > N)
			{
				save = false;
				break;
			}
			for (int l = 0; l < preK; l++) //ลบตัวซ้ำ
			{
				if (a[l] == (i * j))
				{
					save = false;
					break;
				}
				//printf("%d ", a[l]); 
			}
			if (save)
			{
				//printf("%d ", (i * j));
				a[preK] = (i * j);
				preK++;
			}
			if (preK == K)
			{
				return (i * j);
				//printf("%d ", (i * j));
			}
			//printf("\n");
		}
	}
}
