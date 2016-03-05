/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len)
{
	int i = 0, pos, j;
	struct student max, t;
	int k, l;
	if (students != NULL&&len > 0)
	{
		
		for (j = 0; j <= len - 2; j++)
		{
			max.score = students[j].score;
			pos = j;
			for (i = j + 1; i <= len - 1; i++)
			if (students[i].score > max.score)
				{
					max.score = students[i].score;
					pos = i;
				}
			t.score = students[j].score;
			students[j].score = students[pos].score;
			students[pos].score = t.score;
		}
	}
	else
	return NULL;
}