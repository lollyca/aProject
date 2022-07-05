//Heloisa Santos
//07/05
//Mini Project 1

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

    cin >> length >> width >> height;
    do 
    {
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
        
        cout << "This package exceeds the 65 cubic foot limit. Please input again." << "\n";
        cin >> length >> width >> height;

        volume = calcVolume (length, width, height);

    } while (volume >= 65);

    
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

        cout << "\n";
        cout << "Enter package dimensions (feet): " << endl;
        cout << "Length: " << length << "\n";
        cout << "Width: " << width << "\n";
        cout << "Height: " << height << "\n";
        cout << "\n";

        cout << "Package Volume: " << volume << " cubic feet" << "\n";

        cout << fixed << setprecision(2) << showpoint;

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
5 5 4

East County Box Company 

Sales Program (version 1.5)

Enter package dimensions (feet): 
Length: 5
Width: 5
Height: 4

This package exceeds the 65 cubic foot limit. Please input again.
5 2 2

Enter package dimensions (feet): 
Length: 5
Width: 2
Height: 2

Package Volume: 20 cubic feet

Shipping Cost ($2.50 per cubic foot)         $    50.00
Sales Tax (0.0775)                           $     3.88

Total                                        $    53.88
*/
