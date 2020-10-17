#include "expense.h"

vecexpense::vecexpense()
{
		exps = NULL;
		numexp = 0;
		currexp = -1;
		factor = 1;

}

vecexpense::~vecexpense()
{
		if (exps != NULL) 
		{
				delete []exps;
		}
}

int vecexpense::addExpense(expense e)
{
	expense *tempArray;
	tempArray = new expense[numexp+1];
	for (int i = 0; i < numexp; i++) 
	{
		tempArray[i] = exps[i];
	}
	tempArray[numexp] = e;
	delete []exps;
	exps = tempArray;
	numexp++;
	return numexp;
}

void vecexpense::print (ostream &out )
{
			for(int i = 0; i < numexp; i++)
			{
					exps[i].print(out);
			}
}

expense vecexpense::getExpense(int n)
{
	return exps[n];
}

expense::expense()
{
	amt = 0.0;
	purpose = "null";
}

void expense::setExpense(double a, string p)
{
	amt = a;
	purpose = p;
}

void expense::print(ostream &out)
{
	out << "Expense:" << endl;
	out << "\tAmount=$" << fixed << setprecision(2) << setfill('0') << amt << endl;
	out << "\tPurpose=" << purpose << endl;
}

daily::daily()
{
	numexp = 0;
	day = -1;
}

int daily::addExpense(double a, string p)
{
		class expense xtemp;
		xtemp.setExpense(a,p);
		numexp=exps.addExpense(xtemp);
		return numexp;
}

double daily::getDailyExpense()
{
double total = 0.0;
int i;
for(i=0;i<numexp;i++) 
{
	class expense xtemp;
	xtemp=exps.getExpense(i);
	total += xtemp.getAmt();
}
return total;
}

void daily::print(ostream &out) 
{
	int i;
	out << "Daily=======================\n";
	out << "Day = " << day << endl;
	out << "# of Expenses = " << numexp << endl;
	for(i=0;i<numexp;i++) 
	{
		class expense xtemp;
		xtemp=exps.getExpense(i);
		xtemp.print(out);
	}
	cout << "Daily=======================\n";
}

monthly::monthly()
{
	month = -1;
	maxdays = 0;
}

void monthly::setMonth(int m)
{
month = m;
maxdays = mday[month];
int i;
for(i=0;i<maxdays;i++)
{
		days[i].setDay(i+1);
}
}

void monthly::addExpense(int d, double a, string p) 
{
if ((d>0)&&(d<=maxdays)) 
{
	days[d-1].addExpense(a,p);
}

else 
{
	cerr << "monthly::addExpense: day out of range\n";
}
}

double monthly::getDailyExpense(int d) 
{
double total = 0.0;
if ((d>0)&&(d<=maxdays)) 
{
	total = days[d-1].getDailyExpense();
}
return total;
}

double monthly::getMonthlyExpense() 
{
double total = 0.0;
int i;
for(i=1;i<=maxdays;i++) 
{
	total += getDailyExpense(i);
}
return total;
}

void monthly::printOneDay(ostream &out, int d) 
{
if ((d>0)&&(d<=maxdays)) 
{
	days[d-1].print(out);
} 
else 
{
	cerr << "monthly::printOneDay: day out of range\n";
}
}

void monthly::print(ostream &out) 
{
int i;
out << "Monthly==============================\n";
out << "Month = " << month << endl;
out << "# of Days = " << maxdays << endl;
for(i=1;i<=maxdays;i++) 
{
	printOneDay(out, i);
}
out << "Monthly==============================\n";
}
	

yearly::yearly()
{
year = -1;
int i;
for(i=0;i<12;i++) 
{
	months[i].setMonth(i+1);
}
}

void yearly::addExpense(int m, int d, double a, string p)
{
if ((m>0)&&(m<=12))
{
	months[m-1].addExpense(d,a,p);
}
else
{
	cerr << "yearly::addExpense: month out of range\n";
}
}

double yearly::getDailyExpense(int m, int d)
{
double total = 0.0;
if ((m>0)&&(m<=12))
{
		total = months[m-1].getDailyExpense(d);
}
return total;
}

double yearly::getMonthlyExpense(int m) 
{
double total = 0.0;
if ((m>0)&&(m<=12))
{
	total = months[m-1].getMonthlyExpense();
}
return total;

}

double yearly::getYearlyExpense()
{
double total = 0.0;
int i;
for(i=1;i<=12;i++)
{
	total += getMonthlyExpense(i);
}
return total;
}

int yearly::loadDataFromFile(string fname)
{
int count = 0;
ifstream fin(fname);
if (fin.fail()) 
{
	cerr << "Error reading file\n";
	return count;
}
int m,d,y;
double a;
string p;
while(1) 
{
	fin >> m >> d >> y >> a >> p;
	if (fin.fail()) 
	{
		break;
	}
	addExpense(m,d,a,p);
	count++;
}
setYear(y);
fin.close();
return count;
}

void yearly::printOneDay(ostream &out, int m, int d)
{
if ((m>0)&&(m<=12)) 
{
	months[m-1].printOneDay(out,d);
}
else
{
	cerr << "yearly::printOneDay: month out of range\n";
}
}

void yearly::printOneMonth(ostream &out, int m)
{
if ((m>0)&&(m<=12)) 
{
		months[m-1].print(out);
}
else 
{
		cerr << "yearly::printOneMonth: month out of range\n";
}

}

void yearly::print(ostream &out) 
{
int i;
out << "Yearly==============================\n";
out << "year = " << year << endl;
for (i=1;i<=12;i++) 
{
		printOneMonth(out,i);
}
out << "Yearly==============================\n";
}
