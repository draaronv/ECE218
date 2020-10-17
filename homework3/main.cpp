#include <iostream>
#include <string>
#include "expense.h"
using namespace std;


main() {

	cout << "Program Started\n";

	yearly y;
	/*
	y.setYear(1999);
	y.addExpense(1,1,10.5,"test");
	y.addExpense(1,1,1.5,"test");
	y.addExpense(1,2,11.5,"test");
	y.addExpense(2,1,15.5,"test");
	*/

	cout << "y size = " << sizeof(y) << endl;
	y.loadDataFromFile("data1.txt");
	y.printOneDay(cout,1,1);
	y.printOneMonth(cout,1);

	cout << y.getDailyExpense(1,1) << endl;
	int i;
	for(i=1;i<=12;i++) {
		cout << "month=" << i << ",total=" << y.getMonthlyExpense(i) << endl;
	}
	cout << y.getYearlyExpense() << endl;
	return 0;
}


