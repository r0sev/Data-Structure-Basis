/* 选择排序 效率比冒泡稍微高一点，因为交换次数少了，有必要才交换 */
void SelectSort(int a[], int n)
{
	int i, j ,min, tmp;

	min = i;

	for (i = 0; i < n - 1; ++i)
	{
		for (j = i+1; j < n; ++j)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}

		if (min != i)		//此处交换次数会少于冒泡
		{
			tmp = a[min];
			a[min] = a[i];
			a[i] = tmp;
		}

	}
}

/* 同样也可以增加count来计算与其他算法的差别 */