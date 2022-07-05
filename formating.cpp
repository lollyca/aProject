#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	double subtotal = 50;
	double salestax = 3.88;
	double total = 53.88;


	cout << setprecision(2) << fixed;
	cout << setw(45) << left << "Shipping Cost ($2.50 per cubic foot) " << setw(2) << left << "$ " << setw(8) << right << subtotal << endl;
	cout << setw(45) << left << "Sales Tax (0.0775) " << setw(2) << left << "$ " << setw(8) << right << salestax << endl << endl;
	cout << setw(45) << left << "Total " << setw(2) << left << "$ " << setw(8) << right << total << endl;

	return 0;
}