#ifndef EXPENSE_H_
#define EXPENSE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
const int mday[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

class expense 
{
						private:
								double amt;
								string purpose;

						public:
										expense();
										void setExpense(double,string);
										double getAmt() { return amt; }
										void print(ostream&);
};

class vecexpense 
{
						private:
										expense *exps;
										int numexp;
										int currexp;
										int factor;

						public:
										vecexpense();
										~vecexpense();
										int addExpense(expense e);
										void print (ostream &);
										class expense getExpense(int n);
};

class daily 
{
						private:
										vecexpense exps;
										int numexp;
										int day;

						public:
										daily();
										int addExpense(double, string);
										void setDay(int d) { day = d; }
										double getDailyExpense();
										void print(ostream&);
};

class monthly 
{
			private:
							daily days[31];
							int maxdays;
							int month;

			public:
						monthly();
						void setMonth(int m);
						void addExpense(int, double, string);
						double getDailyExpense(int);
						double getMonthlyExpense();
						void printOneDay(ostream&, int);
						void print(ostream&);

};

class yearly
{
			private:
							monthly months[12];
							int year;

			public:
						yearly();
						void setYear(int y) { year = y; }
						void addExpense(int, int, double, string);
						double getDailyExpense(int,int);
						double getMonthlyExpense(int);
						double getYearlyExpense();
						int loadDataFromFile(string);
						void printOneDay(ostream&, int, int);
						void printOneMonth(ostream&, int);
						void print(ostream&);
};

#endif
