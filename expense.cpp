#include "expenses.h"



// Class Purp
void pur::set_purpose(float amt,string purp)
{
	amount=amt;
	purpose=purp;
}

float pur::get_amount()
{
	return amount;
}
string pur::get_purpose()
{
	return purpose;
}



// Date class
date::date()
{
	day=1;
	month=1;
	year=2019;
}

date::date(unsigned int x,unsigned int y,unsigned int z)
{
	month=x;
	day=y;
	year=z;
}

void date::print_date(ostream& out)
{
	out<<month<<"/"<<day<<"/"<<year<<"     ";
}

void date::set_date(unsigned int x, unsigned int y, unsigned int z)
{
	month=x;
	day=y;
	year=z;
}





// Expense Class
expenses::expenses()
{
	amount=1.0;
	purpose="null";
	date day;
}
expenses::expenses(float amt,string purpo,date d)
{
	amount=amt;
	purpose=purpo;
	day=d;
}
float expenses::get_amount()
{
	return amount;
}
string expenses::get_purpose()
{
	return purpose;
}
void expenses::print_expenses(ostream& out)
{
	day.print_date(out);
	out<<amount<<"      "<<purpose;
}
void expenses::set_expenses(float amt, string purpo, date d)
{
	amount=amt;
	purpose=purpo;
	day=d;
}



//Daily class
daily::daily()
{
number=1;
}
void daily::set_daily(class expenses tran)
{
	money[number]=tran;
	number++;
}
float daily::x_amount(int num)
{
	return x[num].get_amount();
}
string daily::x_purpose(int num)
{
	return x[num].get_purpose();
}
float daily::total_daily()
{
	float sum=0.0;
	for(int n=1;n<number;n++)
	{ 
		sum+=money[n].get_amount();
	}
	return sum;
}
void daily::total_purpose()
{
	string p[6]={"grocery", "medical", "meals", "creditcard", "misc", "transport"};
	for(int g=0;g<6;g++)
	{
		float amt=0;
		for(int k=1;k<number;k++)
		{
			if(money[k].get_purpose() == p[g])
			{
				amt+=money[k].get_amount();
			}
		}
		x[g].set_purpose(amt,p[g]);
	}
}
void daily::print_daily(ostream& out)
{
	float sum=0.0;
	for(int n=1;n<number;n++)
	{ 
		out<<n<<": ";
		money[n].print_expenses(out);
		sum+=money[n].get_amount();
		out<<"        $"<<sum<<endl;
	}
	out<<"Daily Total: $"<<sum<<endl<<endl;
}
void daily::print_daily1(ostream& out)
{
	string p[6]={"grocery", "medical", "meals", "creditcard", "misc", "transport"};
	for(int g=0;g<6;g++)
	{
		float amt=0;
		for(int k=1;k<number;k++)
		{
			if(money[k].get_purpose() == p[g])
			{
				amt+=money[k].get_amount();
			}
		}
		out<<p[g]<<"    "<<amt<<endl;
	}
}
void daily::print_daily2(ostream& out)
{
	for(int dw=0;dw<6;dw++)
	{
		out<<x[dw].get_purpose()<<"   "<<x[dw].get_amount()<<endl;
	}

}
void daily::print_daily3(ostream& out,int num)
{
	string p[6]={"grocery", "medical", "meals", "creditcard", "misc", "transport"};
		float amt=0;
		for(int k=1;k<number+1;k++)
		{
			if(money[k].get_purpose() == p[num])
			{
				out<<p[num]<<"    "<<money[k].get_amount()<<endl;
			}
		}
}




// Monthly class
monthly::monthly()
{
	number=1;
}
void monthly::set_monthly(class expenses tran,int day_num)
{
	month[day_num].set_daily(tran);
	number=day_num;
}
float monthly::total_monthly()
{
	float sum=0.0;
	for(int n=1;n<(number+1);n++)
	{ 
		sum+=month[n].total_daily();
	}
	return sum;
}
void monthly::total_purpose()
{
string p[6]={"grocery", "medical", "meals", "creditcard", "misc", "transport"};
for(int g=0;g<6;g++)
{
	float amt=0.0;
	for(int aa=1;aa<number+1;aa++)
	{
		month[aa].total_purpose();
		if(month[aa].x_purpose(g)==p[g])
		{
		amt+=month[aa].x_amount(g);
		}
	}
	x[g].set_purpose(amt,p[g]);
}
}
float monthly::x_amount(int num)
{
	return x[num].get_amount();
}
string monthly::x_purpose(int num)
{
	return x[num].get_purpose();
}
void monthly::print_monthly(ostream &out)
{
	float sum=0.0;
	for(int n=1;n<(number+1);n++)
	{
		sum+=month[n].total_daily();
		out<<"Day "<<n<<endl;
		month[n].print_daily(out);
	}
	out<<"Monthly Total: $"<<sum<<endl<<endl;
}
void monthly::print_daily1(ostream& out)
{
	for(int dw=0;dw<6;dw++)
	{
		out<<x[dw].get_purpose()<<"   "<<x[dw].get_amount()<<endl;
	}
}
void monthly::get_expenses(int day, int mo)
{
	month[day].print_daily(cout);
}
void monthly::get_expen(int num)
{
	for(int hh=1;hh<number+1;hh++)
	{
	month[hh].print_daily3(cout,num);
	}
}

//Yearly class

yearly::yearly()
{
}
void yearly::set_yearly(class expenses tran,int month_num,int day_num)
{
	year[month_num].set_monthly(tran,day_num);
}
float yearly::total_yearly()
{
	float sum=0.0;
	for(int n=1;n<dsize2;n++)
	{ 
		sum+=year[n].total_monthly();
	}
	return sum;
}
void yearly::total_purpose()
{
string p[6]={"grocery", "medical", "meals", "creditcard", "misc", "transport"};
for(int g=0;g<6;g++)
{
	float amt=0.0;
	for(int aa=1;aa<13;aa++)
	{
		year[aa].total_purpose();
		if(year[aa].x_purpose(g)==p[g])
		{
		amt+=year[aa].x_amount(g);
		}
	}
	x[g].set_purpose(amt,p[g]);
}
}
void yearly::print_yearly(ostream &out)
{
	float sum=0.0;
	for(int mm=1;mm<dsize2;mm++)
	{
		out<<"Month "<<mm<<endl;
		year[mm].print_monthly(out);
		sum+=year[mm].total_monthly();
	}
	out<<"Yearly Total: $"<<sum<<endl;
}
void yearly::print_daily1(ostream& out)
{
	for(int dw=1;dw<13;dw++)
	{
		out<<"Month "<<dw<<endl;
		year[dw].print_daily1(out);
		out<<endl;
	}
}
void yearly::print_daily2(ostream& out)
{
	out<<"Entire Year "<<endl;
	for(int dw=0;dw<6;dw++)
	{
		out<<x[dw].get_purpose()<<"   "<<x[dw].get_amount()<<endl;
	}
}
void yearly::get_expenses(int day, int month)
{
	year[month].get_expenses(day,month);
}
void yearly::get_purposes(string purp)
{
	int val;
	string p[6]={"grocery", "medical", "meals", "creditcard", "misc", "transport"};
	for(int h=0;h<6;h++)
	{
		if(purp==p[h])
		{
			val=h;
		}
	}
	for(int ff=1;ff<13;ff++)
	{
		year[ff].get_expen(val);
	}
}