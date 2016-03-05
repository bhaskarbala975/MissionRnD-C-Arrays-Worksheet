/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i,j,temp=0;
	if (Arr != NULL&&len > 0)
	{
		if (num > Arr[len - 1])
		{
			Arr[len] = num;
			len = len + 1;
			return Arr;
		}
		else
		{



			for (i = 0; i < len; i++)
			{
				if (Arr[i]<num&&Arr[i + 1]>num)
				{
					temp = i + 1;
					break;
				}
			}
			for (j = len + 1; j > temp; j--)
			{
				Arr[j] = Arr[j - 1];
			}
			Arr[temp] = num;
			return Arr;
		}
	}
	else
	return NULL;
}