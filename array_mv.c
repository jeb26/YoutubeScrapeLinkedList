#include <stdio.h>
#define N 4

void dump_array();

int main(void)
{
	int lst[] = {1021542644 , 2044511900 , 1736498784 , 1031433273};
	int lst2[] = {1021542644 , 1031433273 , 1736498784 , 2044511900};
	int idx[N], idx2[N];

	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(lst2[i] == lst[j])
			{
				idx[i] = j;
			}
		}
	}

	dump_array("lst",lst);
	dump_array("lst2",lst2);
	dump_array("idx",idx);

	return 0;
}

void dump_array(char *array_name, int *a)
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%s[%d]:%d ", array_name, i, a[i]);
	}
	putchar('\n');
}
