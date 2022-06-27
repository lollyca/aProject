//Heloisa Santos
//
//Mini Project 1

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int length, width, height, volume;
    float cost, tax, total;

    cout << "Enter package dimensions (feet): " << endl;
    cin >> length >> width >> height;
    cout << "\n";

    cout << "East County Box Company " << endl;
    cout << "\n";
    cout << "Sales Program (version 1.5)" << endl;
    cout << "\n";
    cout << "Enter package dimensions (feet): " << endl;

    cout << "\n";
    cout << "Length: " << length << "\n";
    cout << "Width: " << width << "\n";
    cout << "Height: " << height << "\n";
    cout << "\n";

    volume = length * width * height;
    cout << "Package Volume: " << volume << " cubic feet" << "\n";
    
    cout << "\n";
    cost = volume * 2.5;
    cout << "Shipping Cost ($2.50 per cubic foot)" << setw(16) << "$" << setw(8) << cost << "\n";

    cout << "\n";
    tax = cost * 0.0775;
    cout << "Sales Tax (0.0775)" << setw(34) << "$" << setw(11) << tax << "\n";
    
    cout << "\n";
    total = cost + tax;
    cout << "Total" << setw(47) << "$" << setw(12) << total << "\n";
    cout << "\n";

    return 0;
}

/* Program Output 
Assignment 2a
*/