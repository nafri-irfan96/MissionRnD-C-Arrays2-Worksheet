/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if (A == NULL || B == NULL)
		return NULL;


	struct transaction *result;
	int i, j, size = 0, temp = 0;

	result = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
	i = j = 0;
	while (i<ALen && j<BLen)
	{
		if (A[i].amount<B[j].amount)
		{
			result[size++] = A[i];
			i++;
		}
		else
		{
			result[size++] = B[j];
			j++;
		}
		if (A[i].amount == B[j].amount)
		{
			result[size++] = A[i];
			result[size++] = B[j];
			i++;
			j++;
		}
	}
	while (i < ALen)
	{
		result[size++] = A[i];
		i++;
	}
	while (j < BLen)
	{
		result[size++] = B[j];
		j++;
	}
	if (size != 0)
		return result;
	else
		return NULL;
}
