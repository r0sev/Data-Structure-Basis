void BubbleSort(int a[], int n)
{
		int j, tmp = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n - i - 1 ; ++j)
			{
				/* code */
				if (a[j+1] > a[j])
				{
					tmp = a[j+1];
					a[j+1] = a[j];
					a[j] = tmp;
				}
			}
		}
}


//倒着运行的冒泡
void BubbleSort(int a[], int n)
{
		int j, tmp = 0;
		//加入count来查看执行次数
		//int count1 = 0, count2 = 0;
		for (int i = 0; i < n-1; ++i)
		{
			for (int j = n - 1; j < i ; --j)
			{
				//比较次数：count1++;
				if (a[j] < a[j-1])
				{
					//交换次数：count2++;
					tmp = a[j];
					a[j] = a[j-1];
					a[j-1] = tmp;
				}
			}
		}
}

//优化版的冒泡:比较次数会减少

void BubbleSort(int a[], int n)
{
		int j, tmp = 0;
		int flag;
		//加入count来查看执行次数
		//int count1 = 0, count2 = 0;
		flag = 1;
		for (int i = 0; i < n-1; ++i)
		{
			for (int j = n - 1 && flag; j < i ; --j)
			{
				flag = 0;		//优化比较次数,尤其是元素基本有序时
				//比较次数：count1++;
				if (a[j] < a[j-1])
				{
					//交换次数：count2++;
					tmp = a[j];
					a[j] = a[j-1];
					a[j-1] = tmp;
					flag = 1;
				}
			}
		}
}
