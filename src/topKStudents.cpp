/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K)
{
	struct student **result;
	int  i, j, t;
	result = (struct student**)malloc(sizeof(struct student)*len);
	if (len < K)
		K = len;
	if (K <= 0 || students == NULL || len <= 0)
		return NULL;
	else
	{
		for (i = 0; i <len; i++)
		{
			for (j = 0; j <len - i - 1; j++)
			{
				if (students[j].score < students[j + 1].score)
				{
					t = students[j].score;
					students[j].score = students[j + 1].score;
					students[j + 1].score = t;
				}
			}

		}

		j = K - 1;
		for (i = 0; i < K; i++)
		{
			result[j] = &students[i];
			j--;
		}
		return result;
	}
}