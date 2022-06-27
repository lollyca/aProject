//Heloisa Santos
//
//Mini Project 1

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const float small = 1.5 , medium = 2.5, large = 3.0;
    int length, width, height, volume;
    float cost, tax, total, size;
//----------------------------------------------------------------------------------------------//
    cout << "Enter package dimensions (feet): " << endl;
    cin >> length;
    cin >> width; 
    cin >> height;
    cout << "\n";
//----------------------------------------------------------------------------------------------//

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

//----------------------------------------------------------------------------------------------//
    volume = length * width * height;
//----------------------------------------------------------------------------------------------//
    if (volume >= 65) 
    {
        cout << "This package exceeds the 65 cubic foot limit. Please input again." << "\n";
    }
    
    if (volume < 65)
    {
        
        if (volume >= 45 && volume < 65) 
        {
            size = large;
        }
        else if (volume >= 15 && volume < 45) 
        {
            size = medium;
        }
        else if (volume < 15) 
        {
            size = small;
        }
    //----------------------------------------------------------------------------------------------//
        cout << "Package Volume: " << volume << " cubic feet" << "\n";
        
        cout << "\n";
        cost = volume * size;
        cout << "Shipping Cost ($"<<size << " per cubic foot)" << setw(16) << "$" << setw(9) << cost << "\n";


        tax = cost * 0.0775;
        cout << "Sales Tax (0.0775)" << setw(34) << "$" << setw(11) << tax << "\n";

        cout << "\n";
        total = cost + tax;
        cout << "Total" << setw(47) << "$" << setw(12) << total << "\n";
        cout << "\n";

    }
    return 0;
}

