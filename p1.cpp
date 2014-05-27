#include <iostream>
#include <iomanip>
#include "io.h"

bool checkIfInt(double input);

int main () {
	
	
	// the amount of money the user commits to pay per month, to later be split into principal and interest using the fractional interest rate
	double monthlyPayment = GetParam("Please enter the monthly payment: ", 1, 100000);
	
	// accepts fractional interest rate
	double interestRate = GetParam("Please enter the interest rate: ", 0, 1);
	
	// makes sure years is entered as an integer
	double years;
	do	
	{
		years = GetParam("Please enter the duration of the loan, in years: ", 1, 100);
	} while(years != int(years)); 
	
	
	PrintHeader();
	
	
	// declaring the things I must calculate using the things I acquired above
	double month, principal, interest, loaned;
	// months to be printed in reverse order, so the first month printed will be the last month
	// which will be numbered (the total years of the loan * 12)
	month = (int)years*12;
	
	// we start at the end of the loan, when the outstanding balance is 0,
	// and work backwards to when it was the initial amount
	loaned = 0;
	
	while ((month) > 0) {
		
		// amount left at the beginning of this month
		// = (amount left at the beginning of next month  +  monthly payment) / (1 + yearly interest/12)
		loaned = (loaned + monthlyPayment)/(1+(interestRate/12));
		
		// amount of monthly payment that is interest equals monthly interest rate * outstanding balance
		interest = (interestRate/12) * loaned;
		
		// amount that goes toward paying off the loan, which happens last, is monthly payment - the interest on the outstanding balance for that month
		principal = monthlyPayment - interest;
		
		PrintMonthlyData (month, principal, interest, loaned);
		
		month--;
		
	}
	
	
		return 0;
}



