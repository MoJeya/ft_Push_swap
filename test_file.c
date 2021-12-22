#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int chunk1;
	int chunk2;
	int count1;
	int count2;
	int	list_lenght = 100;
	chunk1 = list_lenght / 4;
	chunk2 = chunk1 + list_lenght / 4;
	count1 = 0;
	count2 = chunk1;
	while(count2 < 100)
	{
		if (count1 == chunk1 && count2 == chunk2)
		{
			printf("true\n");
			chunk1 = chunk2;
			chunk2 +=25;
		}
		printf("count 1 %d\ncount 2 %d\n", count1, count2);
		serach_trough(count1, chunk1);
		serach_trough(count2, chunk2);
		// here comes the
		count1++;
		count2++;
	}

	return (0);
}