/* Budgeter Pro
*  Bryson McBreen
*  5-3-22
*  Purpose:
*		Allows users to input things like their salary, rent, car payments, and more, then helps them 
*	plan out how to spend their money for the month.
*/
#include "Includes.h"

int main() {
	int colorMode = 0, choice, percent = 100, tempPerc = 0;
	double pay = 0, rent = 0, car = 0, util = 0, exp = 0, inc = 0, income = 0, expenses = 0, spending = 0,
		food = 0, cloth = 0, tv = 0, other = 0, tempNum, newSpending = 0;
	string expTypes[6] = { "Monthly Paycheck", "Monthly Rent", "Monthly Car Payment", 
		"Monthly (average) Utilities Bill", "Other Expenses", "Other Income" };
	string spnTypes[4] = { "Food & Dining", "Clothing", "Entertainment", "Other" };
	bool redo;
	string color = "Dark Mode";
	
	do {
		// Reset Screen + variables
		system("cls");
		percent = 100;
		redo = false;

		homeScreen();
		cin >> choice;

		switch (choice) {
		case 1:
			for (int i = 0; i < 6; i++) {
				system("cls");
				calcBudgetScreen(pay, rent, car, util, exp, inc, i, expTypes);
				switch (i) {
				case 0:
					cin >> pay;
					break;
				case 1:
					cin >> rent;
					break;
				case 2:
					cin >> car;
					break;
				case 3:
					cin >> util;
					break;
				case 4:
					cin >> exp;
					break;
				case 5:
					cin >> inc;
					break;
				}
			}
			income = pay + inc;
			expenses = rent + car + util + exp;
			spending = income - expenses;
			newSpending = spending;
			for (int i = 0; i < 4; i++) {
				system("cls");
				spendingBudgetScreen(income, expenses, newSpending, percent, food, cloth, tv, other, i, spnTypes);
				cin >> tempPerc;
				percent = percent - tempPerc;
				tempNum = spending / 100;
				tempNum = tempNum * tempPerc;
				newSpending = spending - tempNum;
				switch (i) {
				case 0:
					food = tempNum;
					break;
				case 1:
					cloth = tempNum;
					break;
				case 2:
					tv = tempNum;
					break;
				case 3:
					other = tempNum;
					break;
				}
			}
			system("cls");
			budgetDone(income, expenses, spending, percent, food, cloth, tv, other);
			break;
		case 2:
			// Display the About Screen and send them back when they are ready
			system("cls");
			about();
			cin >> choice;
			redo = true;
			break;
		case 3:
			// User has chosen to close the program
			break;
		}
	} while (redo);
}