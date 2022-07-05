//Heloisa Santos
//07/05
//Mini Project 3

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int calcVolume (int l, int w, int h);


int main()
{
    const float small = 1.5 , medium = 2.5, large = 3.0;
    int length, width, height, volume;
    float cost, tax, total, size;
    string volume_size1, volume_size2, volume_size3, volume_size_total;

    cout << "Enter package dimensions (feet): ";
    cin >> length >> width >> height;
    cout << "\n";

    cout << "East County Box Company " << endl;
    cout << "\n";
    cout << "Sales Program (version 1.5)" << endl;
    cout << "\n";
    cout << "Enter package dimensions (feet): " << endl;
    cout << "Length: " << length << "\n";
    cout << "Width: " << width << "\n";
    cout << "Height: " << height << "\n";
    cout << "\n";

    volume = calcVolume (length, width, height);
//----------------------------------------------------------------------------------------------//
    if (volume >= 65) 
    {
        cout << "This package exceeds the 65 cubic foot limit. Please input again." << "\n";
    }
    
    else if (volume < 65)
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
    //----------------------------------------------------------------------------------------------//
        cout << fixed << setprecision(2) << showpoint;
    //----------------------------------------------------------------------------------------------//

        cout << "\n";
        cost = volume * size;
        cost = static_cast<double>(cost);

        stringstream test;
        test << fixed << setprecision(2) << showpoint;
        test << size;
        test >> volume_size2;
        volume_size1 = "Shipping Cost ($";
        volume_size3 = " per cubic foot)";
        volume_size_total = volume_size1 + volume_size2 + volume_size3;
        cout << setw(45) << left << volume_size_total << setw(2) << left << "$" << setw(8) << right << cost << endl;


        tax = cost * 0.0775;
        cout << setw(45) << left << "Sales Tax (0.0775)" << setw(2) << left << "$" << setw(8) << right << tax << endl;

        cout << "\n";
        total = cost + tax;
        cout << setw(45) << left << "Total" << setw(2) << left << "$" << setw(8) << right << total << endl;
        cout << "\n";

    }
    return 0;
}

int calcVolume (int l, int w, int h) 
{
    return l * w * h;
}

/* Program Output

*/
