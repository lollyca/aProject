//Heloisa Santos
//07/22
//Mini Project 6

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void introDisplay();
int calcVolume (int count);
double prepBox (int &volume, int count);
void paymentMethod(int total);
bool lincValidation (string lincNum);
void paymentMethod (int choice, double total);
double shippingMethod (int volume);

const float
SMALL = 1.5,
MEDIUM = 2.5,
LARGE = 3.0;

int main()
{
    int length, width, height, volume, payChoice, shippingChoice, count =1;
    double cost = 0, tax, total, size, shippingCost = 0, subtotal;
    string vs1, vs2, vs3, vst, lincNum;
    char input = 'Y';


    introDisplay();
    cout << fixed << setprecision(2) << showpoint;
    
    do 
    {
        
        cost += prepBox (volume, count);
        count++;
        shippingCost += shippingMethod(volume);
        cout << "\n";
        cout << "Another container (Y/N): ";
        cin >> input;

    } while (input != 'N');

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << setw(70) << left <<"Container Total" << setw(2) << left << "$" << setw(8) << right << cost << endl;
        cout << setw(70) << left <<"Premium Delivery" << setw(2) << left << "$" << setw(8) << right << shippingCost << endl;
        cout << "\n";
        subtotal = cost + shippingCost;
        cout << setw(70) << left <<"Subtotal" << setw(2) << left << "$" << setw(8) << right << subtotal << endl;
        tax = subtotal * 0.0775;
        cout << setw(70) << left << "Sales Tax - 7.75%" << setw(2) << left << "$" << setw(8) << right << tax << endl;
        cout << "\n";
        total = subtotal + tax;
        cout << setw(70) << left << "Total" << setw(2) << left << "$" << setw(8) << right << total << endl;
        cout << "\n";
        cout << "\n";
        cout << "\n";

        cout << "Payment (1. Cash, 2. Check, 3. Credit): ";
        cin >> payChoice;
        cout << "\n";
        paymentMethod (payChoice, total);
        cout << "\n";

    return 0;

}

void introDisplay () {
    cout << "East County Box Company " << endl;
    cout << "\n";
    cout << "Sales Program (version 1.5)" << endl;
}

int calcVolume (int count)
{
    int length, width, height;
    cout << "\n";
    cout << "Enter dimensions for container #" << count << " (in feet):" << endl;
    cout << "Length: ";
    cin >> length;
    cout << "\n";
    cout << "Width: "; 
    cin >> width;
    cout << "\n";
    cout << "Height: ";
    cin >> height;
    cout << "\n";

    return length * width * height;
}

double prepBox (int &volume, int count) 
{
    int length, width, height;
    float cost, tax, total, size;
    string vs, vst, phrase;

    volume = calcVolume(count);

    while (volume >= 65) 
    {
        cout << "This package exceeds the 65 cubic foot limit. Please input again." << "\n";
        cout << "\n";
        volume = calcVolume(count);
    }

    if (volume >= 45 && volume < 65) 
    {
        size = LARGE;
        phrase = "Large Package ($3.00 per cu ft)";
    }
    else if (volume >= 15 && volume < 45) 
    {
        size = MEDIUM;
        phrase = "Medium Package ($2.50 per cu ft)";
    }
    else if (volume < 15) 
    {
        size = SMALL;
        phrase = "Small Package ($1.50 per cu ft)";
    }

    cout << "Volume of container #" << count << " is " << volume << " cu ft" << "\n";
    
    cout << fixed << setprecision(2) << showpoint;
    cost = volume * size;

    cout << setw(70) << left << phrase << setw(2) << left << "$" << setw(8) << right << cost << endl;
    cout << "\n";

    return cost;  
}

bool lincValidation (string lincNum) 
{
    const int length = 8;
    bool valid = true;
    if (lincNum.length() != length) 
    {
        valid = false;
    } else if (! isalpha(lincNum[0]))
    {
        valid = false;
    }
    else 
        for (int i = 1; i < length; i++) 
        {
            if (! isdigit(lincNum[i]))
                valid = false;
        }
    return valid;
    
}

void paymentMethod (int choice, double total)
{
    
    const int
    CASH = 1,
    CHECK = 2,
    CREDIT = 3;

    int lastDig;
    double userCash, change;
    char cardStyle = 'M';
    string lincNum;

    switch (choice)
    {
    case CASH:
        cout << setw(70) << left << "Accepted:" << setw(2) << left << "$";
        cin >> userCash;
        while (userCash < total) 
        {
            cout << "Did the user enter same or more cash than the bill";
            cout << "\n";
            cout << setw(70) << left << "Accepted:" << setw(2) << left << "$";
            cin >> userCash;
        }
        change = userCash - total;
        cout << setw(70) << left << "Change:" << setw(2) << left << "$" << setw(8) << right << change << endl;
        break;
    case CHECK:
        cout << setw(70) << left << "Enter Driver License No:";
        cin >> lincNum;
        while (! lincValidation (lincNum)) 
        {
            cout << "Is the Driver's license in the correct format (A9999999)";
            cout << "\n";
            cout << setw(70) << left << "Enter Driver License No:";
            cin >> lincNum;
        }
        cout << setw(70) << left << "Accepted Payment:" << setw(2) << left << "$" << setw(8) << right << total << endl;
        break;
    case CREDIT:
        cout << "Visa (V) or Mastercard (M): "; 
        cin >> cardStyle;
        cout << "\n";
        cout << "Enter Last Four Digits of Card: ";
        cin >> lastDig;
        cout << "\n";

        if (cardStyle == 'V') {
            string visa1, visa2, visaT;

            visa1 = "Accepted Visa ending in ";
            visa2 = " for the amount of:";
            visaT = visa1 + to_string(lastDig) + visa2;
            cout << setw(70) << left << visaT << setw(2) << left << "$" << setw(8) << right << total << endl;
        }
        if (cardStyle == 'M') {
            string master1, master2, masterT;
            master1 = "Accepted Mastercard ending in ";
            master2 = " for the amount of:";
            masterT = master1 + to_string(lastDig) + master2;
            cout << setw(70) << left << masterT << setw(2) << left << "$" << setw(8) << right << total << endl;
            
        }
        break;
    }
}

double shippingMethod (int volume) 
{
    const int
    STANDARD = 1,
    FASTG = 2,
    AIR = 3;

    int shippingChoice;
    double shippingCost;


    if (volume < 30) {
        cout << "How is this container to be shipped (choose one):" << endl;
        cout << "\n";
        cout << "(1) Standard - (one to two weeks) - No change to the price" << endl;
        cout << "(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot" << endl;
        cout << "(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot" << endl;
        cout << "\n";
        cout << "Delivery Method: ";
        cin >> shippingChoice;
        cout << "\n";
    } else {
        cout << "How is this container to be shipped (choose one):" << endl;
        cout << "\n";
        cout << "(1) Standard - (one to two weeks) - No change to the price" << endl;
        cout << "(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot" << endl;
        cout << "\n";
        cout << "Delivery Method: ";
        cin >> shippingChoice;
        cout << "\n";
    }

    
    switch (shippingChoice)
    {
    case STANDARD:
        shippingCost = volume * 0.0;
        cout <<setw(70) << left << "Standard:" << setw(2) << left << "$" << setw(8) << right << shippingCost << endl;
        break;
    case FASTG:
        shippingCost = volume * 1.5;
        cout <<setw(70) << left << "Fast Ground ($1.50 per cu ft):" << setw(2) << left << "$" << setw(8) << right << shippingCost << endl;
        break;
    case AIR:
        shippingCost = volume * 3.0;
        cout <<setw(70) << left << "Air ($3.00 per cu ft):" << setw(2) << left << "$" << setw(8) << right << shippingCost << endl;
        break;

    }

    return shippingCost;
}

/* Program Output 
East County Box Company 

Sales Program (version 1.5)

Enter dimensions for container #1 (in feet):
Length: 3

Width: 4

Height: 2

Volume of container #1 is 24 cu ft
Medium Package ($2.50 per cu ft)                                      $    60.00

How is this container to be shipped (choose one):

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot
(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot

Delivery Method: 2

Fast Ground ($1.50 per cu ft):                                        $    36.00

Another container (Y/N): Y

Enter dimensions for container #2 (in feet):
Length: 9

Width: 2

Height: 3

Volume of container #2 is 54 cu ft
Large Package ($3.00 per cu ft)                                       $   162.00

How is this container to be shipped (choose one):

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot

Delivery Method: 1

Standard:                                                             $     0.00

Another container (Y/N): Y

Enter dimensions for container #3 (in feet):
Length: 1

Width: 2

Height: 4

Volume of container #3 is 8 cu ft
Small Package ($1.50 per cu ft)                                       $    12.00

How is this container to be shipped (choose one):

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot
(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot

Delivery Method: 3

Air ($3.00 per cu ft):                                                $    24.00

Another container (Y/N): N




Container Total                                                       $   234.00
Premium Delivery                                                      $    60.00

Subtotal                                                              $   294.00
Sales Tax - 7.75%                                                     $    22.79

Total                                                                 $   316.79



Payment (1. Cash, 2. Check, 3. Credit): 3

Visa (V) or Mastercard (M): V

Enter Last Four Digits of Card: 1234

Accepted Visa ending in 1234 for the amount of:                       $   316.79
*/