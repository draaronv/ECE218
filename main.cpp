#include <iostream>
#include <string>
#include <fstream>
#include "expenses.h"
using namespace std;
void running()
{
	fstream data;
	ofstream output_1;
	ofstream output_2;
	output_1.open("organized_view.txt");
	output_2.open("statistics.txt");
	data.open("data1.txt");
	unsigned int x;
	unsigned int y;
	unsigned int z;
	float t;
	string q;
	int i=1;
	yearly person;
	while(data>>x>>y>>z>>t>>q)
	{
		date a(x,y,z);
		expenses b(t,q,a);
		person.set_yearly(b,x,y);
	}
	person.print_yearly(output_1);
	person.total_purpose();
	person.print_daily1(output_2);
	person.print_daily2(output_2);
	output_1.close();
	output_2.close();
	data.close();
	cout<<"Day Calculator"<<endl;
	cout<<"==================="<<endl;
	cout<<"Please enter a day: ";
	int day;
	cin>>day;
	cout<<"Please enter a month: ";
	int month;
	cin>>month;
	cout<<"Please enter Year: ";
	int year;
	cin>>year;
	person.get_expenses(day,month);
	cout<<endl<<endl;
	cout<<"Purpose Calculator"<<endl;
	cout<<"==================="<<endl;
	cout<<"Please enter purpose: ";
	string purp;
	cin>>purp;
	person.get_purposes(purp);
}
int main()
{
	running();
	return 0;
}
