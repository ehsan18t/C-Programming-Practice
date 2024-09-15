#include <stdio.h>

struct account
{
	int accNo;
	double balance;
	double loan;
} typedef account;

double avgLoan(account all[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += all[i].loan;
	return sum / size;
}

int maxBalanceAcc(account all[], int size)
{
	int max = 0;
	for (int i = 1; i < size; ++i)
		if (all[i].balance > all[max].balance)
			max  = i;
	return all[max].accNo;
}

int main()
{
	account[100] all;
	int n;
	printf("Enter the number of account:");
	scanf("%d", &n);

	// Input
	for (int i = 0; i < n; ++i)
	{
		printf("Enter account %d info:", i);

		printf("ACC No:");
		scanf("%d", &all[i].accNo);

		printf("Balance:");
		scanf("%lf", &all[i].balance);

		printf("Loan:");
		scanf("%lf", &all[i].account);
	}

	printf("Account No. of Max Balance: %d\n", maxBalanceAcc(all, n));
	printf("AVG Loan: %d\n", avgLoan(all, n));

	return 0;
}