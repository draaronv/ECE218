#ifndef EXPENSES_H_
#define EXPENSES_H_
#include <iostream>
#include <string>


using namespace std;
unsigned const int dsize0=25;
unsigned const int dsize1=32;
unsigned const int dsize2=13;

class pur
{
private:
	float amount;
	string purpose;
public:
	void set_purpose(float amt,string purp);
	float get_amount();
	string get_purpose();
};

class date
{
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
		date();
		date(unsigned int x,unsigned int y,unsigned int z);
		void set_date(unsigned int x,unsigned int y,unsigned int z);
		void print_date(ostream &out);
};

class expenses {
	private:
		class date day;
		float amount;
		string purpose;
	public:
		expenses();
		expenses(float amt, string purpo,date d);
		float get_amount();
		string get_purpose();
		void set_expenses(float amt,string purpo,date d);
		void print_expenses(ostream& out);
};

class daily
{
private:
	class expenses money[dsize0];
	class pur x[dsize0];
	int number;
public:
	daily();
	void total_purpose();
	float total_daily();
	float x_amount(int num);
	string x_purpose(int num);
	void set_daily(class expenses tran);
	void print_daily1(ostream& out);
	void print_daily(ostream& out);
	void print_daily2(ostream& out);
	void print_daily3(ostream& out, int num);
};


class monthly
{
private:
	class daily month[dsize1];
	class pur x[dsize0];
	int number;
public:
	monthly();
	void total_purpose();
	void get_expenses(int day, int mo);
	float x_amount(int num);
	string x_purpose(int num);
	float total_monthly();
	void set_monthly(class expenses tran,int day_num);
	void print_monthly(ostream& out);
	void print_daily1(ostream& out);
	void get_expen(int num);
};

class yearly 
{
private:
	class monthly year[dsize2];
	class pur x[dsize0];
public:
	yearly();
	void total_purpose();
	void get_expenses(int day, int month);
	void get_purposes(string purp);
	float total_monthly();
	float total_yearly();
	void set_yearly(class expenses tran,int month_num,int day_num);
	void print_yearly(ostream& out);
	void print_daily1(ostream& out);
	void print_daily2(ostream& out);
};

#endif
