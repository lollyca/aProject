//Heloisa Santos
//07/07
//Mini Project 4

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void introDisplay();
int calcVolume ();
double prepBox ();

const float
SMALL = 1.5,
MEDIUM = 2.5,
LARGE = 3.0;


int main()
{
    int length, width, height, volume;
    double cost, tax, total, size;
    string vs1, vs2, vs3, vst;
    char input = 'Y';

    introDisplay();
    cout << fixed << setprecision(2) << showpoint;
    
    do 
    {
        
        cost += prepBox ();
        cout << "Add another package (Y/N): ";
        cin >> input;

    } while (input != 'N');

        cout << "\n";
        cout << setw(45) << left <<"SubTotal" << setw(2) << left << "$" << setw(8) << right << cost << endl;
        tax = cost * 0.0775;
        cout << setw(45) << left << "Sales Tax (0.0775)" << setw(2) << left << "$" << setw(8) << right << tax << endl;

        cout << "\n";
        total = cost + tax;
        cout << setw(45) << left << "Total" << setw(2) << left << "$" << setw(8) << right << total << endl;
        cout << "\n";
    
    return 0;
}

void introDisplay () {
    cout << "East County Box Company " << endl;
    cout << "\n";
    cout << "Sales Program (version 1.5)" << endl;
}

int calcVolume ()
{
    int length, width, height;
    cout << "\n";
    cout << "Enter package dimensions (feet): " << endl;
    cout << "Length: ";
    cin >> length;
    cout << "Width: "; 
    cin >> width;
    cout << "Height: ";
    cin >> height;
    cout << "\n";

    return length * width * height;
}

double prepBox () 
{
    int length, width, height, volume;
    float cost, tax, total, size;
    string vs1, vs2, vs3, vst;

    volume = calcVolume();

    while (volume >= 65) 
    {
        cout << "This package exceeds the 65 cubic foot limit. Please input again." << "\n";
        cout << "\n";
        volume = calcVolume();
    }

    if (volume >= 45 && volume < 65) 
    {
        size = LARGE;
    }
    else if (volume >= 15 && volume < 45) 
    {
        size = MEDIUM;
    }
    else if (volume < 15) 
    {
        size = SMALL;
    }

    cout << "Package Volume: " << volume << " cubic feet" << "\n";
    cost = volume * size;
    stringstream ssize;
    ssize << fixed << setprecision(2) << showpoint;
    ssize << size;
    ssize >> vs2;
    vs1 = "Shipping Cost ($";
    vs3 = " per cubic foot)";
    vst = vs1 + vs2 + vs3;
    cout << setw(45) << left << vst << setw(2) << left << "$" << setw(8) << right << cost << endl;
    cout << "\n";

    return cost;  
}

/* Program Output 
East County Box Company 

Sales Program (version 1.5)

Enter package dimensions (feet):
Length: 5
Width: 2
Height: 2

Package Volume: 20 cubic feet
Shipping Cost ($2.50 per cubic foot)         $    50.00

Add another package (Y/N): Y

Enter package dimensions (feet):
Length: 4
Width: 3
Height: 2

Package Volume: 24 cubic feet
Shipping Cost ($2.50 per cubic foot)         $    60.00

Add another package (Y/N): Y

Enter package dimensions (feet):
Length: 1
Width: 2
Height: 3

Package Volume: 6 cubic feet
Shipping Cost ($1.50 per cubic foot)         $     9.00

Add another package (Y/N): N

SubTotal                                     $   119.00
Sales Tax (0.0775)                           $     9.22

Total                                        $   128.22
*/