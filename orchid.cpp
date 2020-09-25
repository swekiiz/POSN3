#include<cstdio>
int array[1000001], in, right, left, mid, Size = 1, N;
main()
{
	scanf("%d", &N);
	for(int it = 0;it < N;it++) 
	{
		scanf("%d", &in);
		if(it == 0) 
			array[it] = in;
		else if(in < array[0]) 
			array[0] = in;
		else if(in >= array[Size-1]) 
			array[Size++] = in;
		else 
		{
			left = 0, right = Size - 1;
			while(left <= right)
			{
				mid = (left + right) / 2;
				
				if(array[mid] > in) 
					right = mid - 1;
				else 
					left = mid + 1;
			}
			array[left] = in;
		}
	}
	printf("%d", N - Size);
} 	
