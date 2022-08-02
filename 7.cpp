//Heloisa Santos
//08/02
//Mini Project 7

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>


using namespace std;

//struct is a class with default public access in c++ 
struct package {
   int vol = 0;
   double cost = 0.0;
   int shipping = 0;
   double shipcost = 0.0;
};

string introDisplay (int &count, tm &today);
int calcVolume (int count);
double prepBox (int &volume, int count, vector<package> &shipment);
void paymentMethod(int total);
bool lincValidation (string lincNum);
void paymentMethod (int choice, double total);
double shippingMethod (int volume, vector<package> &shipment);
void displayDate (tm &today, int daysToAdd, ostream &c);
void estimatedDelivery (tm &today,vector<package> &shipment, string costumerName);

const float
SMALL = 1.5,
MEDIUM = 2.5,
LARGE = 3.0;



int main()
{
    int length, width, height, volume, payChoice, shippingChoice, count = 1;
    double cost = 0, tax, total, size, shippingCost = 0, subtotal;
    string vs1, vs2, vs3, vst, lincNum, costumerName;
    char input = 'Y';

    vector<package> shipment; 

    tm today = { };

    costumerName = introDisplay (count, today);
    cout << fixed << setprecision(2) << showpoint;
    
    do 
    {
        
        cost += prepBox (volume, count, shipment);
        count++;
        shippingCost += shippingMethod(volume, shipment);
        cout << "\n";
        cout << "Another container (y/n): ";
        cin >> input;

    } while (input != 'n');

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        /*
        cout << setw(70) << left <<"Container Total" << setw(2) << left << "$" << setw(8) << right << cost << endl;
        cout << setw(70) << left <<"Premium Delivery" << setw(2) << left << "$" << setw(8) << right << shippingCost << endl;
        cout << "\n";
        */
        subtotal = cost + shippingCost;
        cout << setw(70) << left <<"Subtotal" << setw(2) << left << "$" << setw(8) << right << subtotal << endl;
        tax = subtotal * 0.0775;
        cout << setw(70) << left << "Sales Tax - 7.75%" << setw(2) << left << "$" << setw(8) << right << tax << endl;
        cout << "\n";
        total = subtotal + tax;
        cout << setw(70) << left << "Total" << setw(2) << left << "$" << setw(8) << right << total << endl;
        cout << "\n";

        cout << "Payment (1. Cash, 2. Check, 3. Credit): ";
        cin >> payChoice;
        cout << "\n";
        paymentMethod (payChoice, total);
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        estimatedDelivery (today,shipment, costumerName);

        cout << setw(70) << left <<"Subtotal" << setw(2) << left << "$" << setw(8) << right << subtotal << endl;
        tax = subtotal * 0.0775;
        cout << setw(70) << left << "Sales Tax - 7.75%" << setw(2) << left << "$" << setw(8) << right << tax << endl;
        cout << "\n";
        total = subtotal + tax;
        cout << setw(70) << left << "Total" << setw(2) << left << "$" << setw(8) << right << total << endl;
        cout << "\n";
    return 0;

}

string introDisplay (int &count, tm &today) {
    string costumerName, dateDay, dateMonth, dateYear;
    cout << "****East County Cargo Transport**** " << endl;
    cout << "\n";
    cout<< "Cashiering system 2.0" << endl;
    cout << "Starting Transactions - date - ";
    getline(cin, dateMonth,'/');
    getline(cin, dateDay,'/');
    getline(cin, dateYear);
    
    today.tm_mon = stoi(dateMonth) - 1;
    today.tm_mday = stoi(dateDay);
    today.tm_year = stoi(dateYear) - 1900;

    cout << "\n";
    cout << "Starting at Transaction #" << (count) << endl;
    cout << "\n";
    cout << "Enter Customer's name: ";
    getline(cin, costumerName);
    cout << "\n";
    cout << "Customer - " << costumerName << endl;

    return costumerName;
    
}

int calcVolume (int count)
{
    int length, width, height;
    cout << "\n";
    cout << "Enter dimensions for container #" << count << " (in feet):" << endl;
    cout << "Height: ";
    cin >> height;
    cout << "\n";
    cout << "Length: ";
    cin >> length;
    cout << "\n";
    cout << "Width: "; 
    cin >> width;
    cout << "\n";

    return length * width * height;
}

double prepBox (int &volume, int count, vector<package> &shipment) 
{
    int length, width, height;
    float cost, tax, total, size;
    package theBox;
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
        phrase = "Large Package ($3.00 per cu ft):";
    }
    else if (volume >= 15 && volume < 45) 
    {
        size = MEDIUM;
        phrase = "Medium Package ($2.50 per cu ft):";
    }
    else if (volume < 15) 
    {
        size = SMALL;
        phrase = "Small Package ($1.50 per cu ft):";
    }

    cout << "Volume of container #" << count << " is " << volume << " cu ft" << "\n";
    
    cout << fixed << setprecision(2) << showpoint;
    cost = volume * size;

    cout << phrase << setw(4) << right << "$" << cost << endl;
    cout << "\n";

    theBox.cost = cost;
    theBox.vol = volume;
    shipment.push_back (theBox);
    
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

double shippingMethod (int volume, vector<package> &shipment) 
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
        cout << "Standard:" << setw(4) << right << "$" << shippingCost << endl;
        break;
    case FASTG:
        shippingCost = volume * 1.5;
        cout << "Fast Ground ($1.50 per cu ft):" << setw(4) << right << "$" << shippingCost << endl;
        break;
    case AIR:
        shippingCost = volume * 3.0;
        cout << "Air ($3.00 per cu ft):" << setw(4) << right << "$" << shippingCost << endl;
        break;
    }

    shipment.back().shipping = shippingChoice;
    shipment.back().shipcost = shippingCost;

    return shippingCost;
}

void estimatedDelivery (tm &today,vector<package> &shipment, string costumerName) {
    
    int num = 0;

    cout << "__________________________________________________________________________________" << endl;
    cout << "\n";
    cout << "East County Cargo Transport" << endl;
    cout << "\n";
    cout << "123 First Street" << endl;
    cout << "El Cajon, CA  92071" << endl;
    cout << "\n";
    cout << "Customer Receipt - ";
    displayDate(today, 0, cout);
    cout << "\n";
    cout << "\n";
    cout << "Customer Name: " << costumerName << endl;
    cout << "\n";
    for (int i =0; i < shipment.size(); i++) {
        stringstream a;
        a << "Container #" << (i+1) << " - " << shipment[i].vol << " cu ft" << "\n";
        string b;
        getline(a,b);
        cout << setw(70) << left << b << setw(2) << left << "$" << setw(8) << right << shipment[i].cost << endl;
        
        if (shipment [i].shipping == 1) {
            b = "STD";
            num = 14;
        } else if (shipment [i].shipping == 2) {
            b = "FG";
            num = 5;
        } else if (shipment [i].shipping == 3) {
            b = "AIR";
            num = 2;
        }

        a << "Shipping: " << b << " - Est. Delivery - ";
        displayDate(today, num, a);
        getline(a,b);
        cout << setw(70) << left << b << setw(2) << left << "$" << setw(8) << right << shipment[i].shipcost << endl;
        cout << "\n";
    }

}

void displayDate (tm &today, int daysToAdd, ostream &c) {
    //for original date set days to 0
    tm tomorrow = today;
    tomorrow.tm_mday += daysToAdd;
    time_t date = mktime (&tomorrow);
    localtime_s (&tomorrow, &date);
    char CHARARRAY [15];
    strftime(CHARARRAY, 15, "%m/%d/%Y", &tomorrow);
    c << CHARARRAY;
}



/* Program Output 
****East County Cargo Transport****

Cashiering system 2.0
Starting Transactions - date - 05/28/2020

Starting at Transaction #1

Enter Customer's name: Jerry Lewis

Customer - Jerry Lewis

Enter dimensions for container #1 (in feet):
Height: 3

Length: 4

Width: 2

Volume of container #1 is 24 cu ft
Medium Package ($2.50 per cu ft):   $60.00

How is this container to be shipped (choose one):

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot
(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot

Delivery Method: 2

Fast Ground ($1.50 per cu ft):   $36.00

Another container (y/n): y

Enter dimensions for container #2 (in feet):
Height: 9

Length: 2

Width: 3

Volume of container #2 is 54 cu ft
Large Package ($3.00 per cu ft):   $162.00

How is this container to be shipped (choose one):

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot

Delivery Method: 1

Standard:   $0.00

Another container (y/n): y

Enter dimensions for container #3 (in feet):
Height: 1

Length: 2

Width: 4

Volume of container #3 is 8 cu ft
Small Package ($1.50 per cu ft):   $12.00

How is this container to be shipped (choose one):

(1) Standard - (one to two weeks) - No change to the price
(2) Fast Ground - (3 to 5 business days) - Extra $1.50 per cubic foot
(3) Air - (1 to 2 business days) - Only applies to packages under 30 cubic feet - Extra $3.00 per cubic foot

Delivery Method: 3

Air ($3.00 per cu ft):   $24.00

Another container (y/n): n




Subtotal                                                              $   294.00    
Sales Tax - 7.75%                                                     $    22.79

Total                                                                 $   316.79    

Payment (1. Cash, 2. Check, 3. Credit): 320





__________________________________________________________________________________  

East County Cargo Transport

123 First Street
El Cajon, CA  92071

Customer Receipt - 05/28/2020

Customer Name: Jerry Lewis

Container #1 - 24 cu ft                                               $    60.00
Shipping: FG - Est. Delivery - 06/02/2020                             $    36.00

Container #2 - 54 cu ft                                               $   162.00
Shipping: STD - Est. Delivery - 06/11/2020                            $     0.00

Container #3 - 8 cu ft                                                $    12.00
Shipping: AIR - Est. Delivery - 05/30/2020                            $    24.00

Subtotal                                                              $   294.00
Sales Tax - 7.75%                                                     $    22.79

Total                                                                 $   316.79
*/