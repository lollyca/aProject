//Heloisa Santos
//07/04
//Mini Project 1

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int length, width, height, volume;
    float cost, tax, total;
//--------------------------------------------------------------------------------------//
    cout << "Enter package dimensions (feet): ";
    cin >> length >> width >> height;
    cout << "\n";
//--------------------------------------------------------------------------------------//
    cout << "East County Box Company " << endl;
    cout << "\n";
    cout << "Sales Program (version 1.5)" << endl;
    cout << "\n";
    cout << "Enter package dimensions (feet): " << endl;
//--------------------------------------------------------------------------------------//
    cout << "Length: " << length << "\n";
    cout << "Width: " << width << "\n";
    cout << "Height: " << height << "\n";
    cout << "\n";
//--------------------------------------------------------------------------------------//
    volume = length * width * height;
    cout << "Package Volume: " << volume << " cubic feet" << "\n";
//--------------------------------------------------------------------------------------//
    cout << setprecision(2) << fixed;
//--------------------------------------------------------------------------------------//
    cout << "\n";
    cost = volume * 2.5;
    cout << setw(45) << left << "Shipping Cost ($2.50 per cubic foot)" << setw(2) << left << "$" << setw(8) << right << cost << endl;

    cout << "\n";
    tax = cost * 0.0775;
    cout << setw(45) << left << "Sales Tax (0.0775)" << setw(2) << left << "$" << setw(8) << right << tax << endl;
    
    cout << "\n";
    total = cost + tax;
    cout << setw(45) << left << "Total" << setw(2) << left << "$" << setw(8) << right << total << endl;
    cout << "\n";

    return 0;
}

/* Program Output 
Enter package dimensions (feet): 5 2 2

East County Box Company 

Sales Program (version 1.5)      

Enter package dimensions (feet): 
Length: 5
Width: 2
Height: 2

Package Volume: 20 cubic feet

Shipping Cost ($2.50 per cubic foot)         $    50.00

Sales Tax (0.0775)                           $     3.88

Total                                        $    53.88
*/