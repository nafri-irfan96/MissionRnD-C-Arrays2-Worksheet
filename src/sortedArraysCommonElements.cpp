/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int compare2(char date1[], char date2[]);
int conversion(int *inp, int len);
int binarySearch(struct transaction *Arr, int st, int end, char *date);


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL)
		return NULL;

	struct transaction *res = (struct transaction*)calloc(ALen, sizeof(struct transaction));

	int i, j = 0;

	for (i = 0; i < ALen; i++){

		int flag = binarySearch(B, 0, BLen - 1, A[i].date);

		if (flag >= 0){
			res[j] = A[i];
			j++;
		}

	}

	if (j > 0)
		return res;
	else
		return NULL;

}


int binarySearch(struct transaction *Arr, int st, int end, char *date){


	if (st > end)
		return -1;

	int mid = (st + end) / 2;
	int flag = (compare2(Arr[mid].date, date));
	if (flag == 0)
	{
		return mid;
	}
	else  if (flag > 0)
		return binarySearch(Arr, st, mid - 1, date);
	else
		return binarySearch(Arr, mid + 1, end, date);

}

int compare2(char date1[], char date2[]){

	int dt1[3][4], dat2[3][4];

	int i, j = 0, k = 0;

	for (i = 0; date1[i] != '\0' && date2[i] != '\0'; i++){

		if (date1[i] != '-' && date2[i] != '-'){
			dt1[j][k] = (int)date1[i] - '0';
			dat2[j][k] = (int)date2[i] - '0';
			k++;
		}
		else
		{
			dt1[j][k] = dat2[j][k] = -1;
			k = 0;
			j++;
		}

	}

	int y1, y2;
	y1 = conversion(dt1[2], 4);
	y2 = conversion(dat2[2], 4);


	if (y1 != y2)
		return y1 > y2 ? 1 : -1;
	else
	{

		int mn1, mn2;
		mn1 = conversion(dt1[1], 2);
		mn2 = conversion(dat2[1], 2);

		if (mn1 != mn2)
			return mn1 > mn2 ? 1 : -1;
		else
		{
			int day1, day2;
			day1 = conversion(dt1[0], 2);
			day2 = conversion(dat2[0], 2);
			if (day1 != day2)
				return day1 > day2 ? 1 : -1;
			else
				return 0;
		}

	}
}

int conversion(int inp[], int len){

	int num = 0, i = 0;

	while (i<len && inp[i] >= 0){
		num = num * 10 + inp[i];
		i++;
	}

	return num;
}