//Heloisa Santos
//07/06
//Mini Project 3

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void introDisplay();
int calcVolume(int l, int w, int h);

const float
SMALL = 1.5,
MEDIUM = 2.5,
LARGE = 3.0;


int main()
{
    int length, width, height, volume;
    float cost, tax, total, size;
    string vs1, vs2, vs3, vst;
//----------------------------------------------------------------------------------------------//
    introDisplay();
//----------------------------------------------------------------------------------------------//
    cout << "\n";
    cout << "Enter package dimensions (feet): " << endl;
    cout << "Length: ";
    cin >> length;
    cout << "Width: "; 
    cin >> width;
    cout << "Height: ";
    cin >> height;
    cout << "\n";
//----------------------------------------------------------------------------------------------//
    volume = calcVolume(length, width, height);
//----------------------------------------------------------------------------------------------//
    while (volume >= 65) 
    {
        cout << "This package exceeds the 65 cubic foot limit. Please input again." << "\n";
        cout << "\n";
        cout << "Enter package dimensions (feet): " << endl;
        cout << "Length: ";
        cin >> length;
        cout << "Width: "; 
        cin >> width;
        cout << "Height: ";
        cin >> height;
        cout << "\n";
        volume = calcVolume(length, width, height);
    }
//-----------------------------------------------------------------------------------------------------------------------------//  
    if (volume < 65)
    {
        
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
        
//-----------------------------------------------------------------------------------------------------------------------------//
        cout << "\n";
        cost = volume * size;
        stringstream ssize;
        ssize << fixed << setprecision(2) << showpoint;
        ssize << size;
        ssize >> vs2;
        vs1 = "Shipping Cost ($";
        vs3 = " per cubic foot)";
        vst = vs1 + vs2 + vs3;
        cout << setw(45) << left << vst << setw(2) << left << "$" << setw(8) << right << cost << endl;


        tax = cost * 0.0775;
        cout << setw(45) << left << "Sales Tax (0.0775)" << setw(2) << left << "$" << setw(8) << right << tax << endl;

        cout << "\n";
        total = cost + tax;
        cout << setw(45) << left << "Total" << setw(2) << left << "$" << setw(8) << right << total << endl;
        cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------//

    }
    return 0;
}
int calcVolume (int l, int w, int h) 
{
    int v = l * w * h;
    return v;
}

void introDisplay () {
    cout << "East County Box Company " << endl;
    cout << "\n";
    cout << "Sales Program (version 1.5)" << endl;
}

/* Program Output 
East County Box Company

Sales Program (version 1.5)

Enter package dimensions (feet):
Length: 5
Width: 5
Height: 4

This package exceeds the 65 cubic foot limit. Please input again.

Enter package dimensions (feet): 
Length: 5
Width: 3
Height: 4

Package Volume: 60 cubic feet

Shipping Cost ($3.00 per cubic foot)         $      180
Sales Tax (0.0775)                           $    13.95

Total                                        $   193.95
*/
 