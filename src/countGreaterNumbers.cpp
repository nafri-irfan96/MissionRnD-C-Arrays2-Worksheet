/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

int compare(char date1[], char date2[]);
int convert(int *inp, int len);
int bin_search(struct transaction *Arr, int start, int end, char *date);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct date{

	int d;
	int m;
	int y;
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int result;
	result = bin_search(Arr, 0, len - 1, date);

	if (result < 0)
		return 0;

	return len - result - 1;
}
int bin_search(struct transaction *Arr, int start, int end, char *date)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	int temp = (compare(Arr[mid].date, date));
	if (temp == 0)
	{
		int temp2 = bin_search(Arr, mid + 1, end, date);
		if (temp2 > 0)
			return temp2;
		else
			return mid;
	}
	else  if (temp > 0)
		return bin_search(Arr, start, mid - 1, date);
	else
		return bin_search(Arr, mid + 1, end, date);

}

int compare(char date1[], char date2[]){
	int i, j = 0, k = 0;
	int dt1[3][4], dt2[3][4];
	for (i = 0; date1[i] != '\0' && date2[i] != '\0'; i++)
	{
		if (date1[i] != '-' && date2[i] != '-')
		{
			dt1[j][k] = (int)date1[i] - '0';
			dt2[j][k] = (int)date2[i] - '0';
			k++;
		}
		else
		{
			dt1[j][k] = dt2[j][k] = -1;
			k = 0;
			j++;
		}
	}
	int yr1, yr2;
	yr1 = convert(dt1[2], 4);
	yr2 = convert(dt2[2], 4);
	
	
	if (yr1 != yr2)
		return yr1 > yr2 ? 1 : -1;
	else
	{
		int mn1, mn2;
		mn1 = convert(dt1[1], 2);
		mn2 = convert(dt2[1], 2);

		if (mn1 != mn2)
			return mn1 > mn2 ? 1 : -1;
		else
		{
			int day1, day2;
			day1 = convert(dt1[0], 2);
			day2 = convert(dt2[0], 2);

			if (day1 != day2)
				return day1 > day2 ? 1 : -1;
			else
				return 0;
		}

	}
}

int convert(int inp[], int len){

	int num = 0, i = 0;

	while (i<len && inp[i] >= 0){
		num = num * 10 + inp[i];
		i++;
	}

	return num;
}
