
// Zulaikha Aisyah & Aisyah Sofea & Nurul Irwani
// CSC126 Group Project
// Group Project Title : La La Land Themepark

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void getNamePackage(string &, char &);
void getData(char, char &, int &, double &, double &, double &, double &, char &, double &, int &, double &);
void display(char, string, char, int, double);
void summary(string[], char[], int[], double[], int);

int age, quantityArr[50], quantity;
double sum = 0;
double price, totalPrice, totalPriceArr[50], addOn1, addOn2, addOn3;
string name, nameArr[50];
char package, packageArr[50], nationality, add, towel, tube, goggle;

int main()
{
    char answer;
    cout << "Have customer? (Y/N): ";
    cin >> answer;
    answer = toupper(answer);

    int i = 0;
    while (answer == 'Y')
    {
        quantity = 0;
        totalPrice = 0;
        sum = 0;

        getNamePackage(name, package);
        nameArr[i] = name;
        packageArr[i] = package;

        getData(package, nationality, age, price, addOn1, addOn2, addOn3, add, sum, quantity, totalPrice);
        quantityArr[i] = quantity;
        totalPriceArr[i] = totalPrice;

        display(add, name, package, quantity, totalPrice);

        cout << "\n\nHave customer (Y/N): ";
        cin >> answer;
        answer = toupper(answer);
        i++;
    }
    summary(nameArr, packageArr, quantityArr, totalPriceArr, i);
}

void getNamePackage(string &name, char &package)
{
    cout << setw(53) << "Ticket Price (RM)" << endl;
    cout << setw(15) << "Nationality" << setw(33) << "Malaysian" << setw(25) << "Non-Malaysian" << endl;
    cout << setw(15) << "-----------" << setw(35) << "--------------" << setw(25) << "----------------------------" << endl;
    cout << setw(15) << "Age (years)" << setw(25) << "<=60" << setw(10) << ">60" << setw(15) << "<=60" << setw(10) << ">60" << endl;
    cout << setw(15) << "Package A (Themepark only)" << setw(15) << "80.00" << setw(10) << "65.00" << setw(15) << "100.00" << setw(10) << "85.00" << endl;
    cout << setw(15) << "Package B (Waterpark only)" << setw(15) << "40.00" << setw(10) << "35.00" << setw(15) << "70.00" << setw(10) << "55.00" << endl;
    cout << setw(15) << "Package C (Both)" << setw(25) << "110.00" << setw(10) << "95.00" << setw(15) << "150.00" << setw(10) << "140.00" << endl;
    cout << setw(15) << "*Kids age 7 and below are free of charge" << endl;

    cout << setw(45) << "\n\nAdd On Facility" << setw(20) << "Price (RM)" << endl;
    cout << setw(15) << "---------------" << setw(20) << "----------" << endl;
    cout << setw(10) << "Towel" << setw(23) << "10.00" << endl;
    cout << setw(10) << "Tube" << setw(23) << "15.00" << endl;
    cout << setw(10) << "Goggle" << setw(23) << "9.00" << endl;

    cout << "\n\nPlease enter your name : ";
    cin.ignore();
    getline(cin, name);
    cout << "Please enter package : ";
    cin >> package;
    package = toupper(package);
}

void getData(char package, char &nationality, int &age, double &price, double &addOn1, double &addOn2, double &addOn3, char &add, double &sum, int &i, double &totalPrice)
{
    if (package != 'A' && package != 'B' && package != 'C')
    {
        cout << "Please enter correct package.";
        return;
    }

    do
    {
        if (package == 'A')
        {
            cout << "\nDo you have Malaysian id? (Y/N) : ";
            cin >> nationality;
            nationality = toupper(nationality);

            cout << "Please enter age : ";
            cin >> age;

            if (nationality == 'Y')
            {
                if (age <= 7)
                    price = 0;
                else if (age <= 60)
                    price = 80;
                else
                    price = 65;
            }
            else
            {
                if (age <= 7)
                    price = 0;
                else if (age <= 60)
                    price = 100;
                else
                    price = 85;
            }
        }
        else if (package == 'B')
        {
            cout << "\nDo you have Malaysian id? (Y/N) : ";
            cin >> nationality;
            nationality = toupper(nationality);

            cout << "Please enter age : ";
            cin >> age;

            if (nationality == 'Y')
            {
                if (age <= 7)
                    price = 0;
                else if (age <= 60)
                    price = 40;
                else
                    price = 35;
            }
            else
            {
                if (age <= 7)
                    price = 0;
                else if (age <= 60)
                    price = 70;
                else
                    price = 55;
            }
        }
        else if (package == 'C')
        {
            cout << "\nDo you have Malaysian id? (Y/N) : ";
            cin >> nationality;
            nationality = toupper(nationality);

            cout << "Please enter age : ";
            cin >> age;

            if (nationality == 'Y')
            {
                if (age <= 7)
                    price = 0;
                else if (age <= 60)
                    price = 110;
                else
                    price = 95;
            }
            else
            {
                if (age <= 7)
                    price = 0;
                else if (age <= 60)
                    price = 150;
                else
                    price = 140;
            }
        }

        cout << "\nDo you want to add on towel? (Y/N) : ";
        cin >> towel;
        towel = toupper(towel);
        addOn1 = (towel == 'Y') ? 10 : 0;

        cout << "Do you want to add on tube? (Y/N) : ";
        cin >> tube;
        tube = toupper(tube);
        addOn2 = (tube == 'Y') ? 15 : 0;

        cout << "Do you want to add on goggle? (Y/N) : ";
        cin >> goggle;
        goggle = toupper(goggle);
        addOn3 = (goggle == 'Y') ? 9 : 0;

        cout << "\nDo you want to add more person? Insert Y to continue otherwise to print receipt : ";
        cin >> add;
        add = toupper(add);

        sum = sum + (price + addOn1 + addOn2 + addOn3);
        totalPrice = sum * 1.1;
        i++;
    } while (add == 'Y');
}

void display(char add, string name, char package, int i, double totalPrice)
{
    if (add != 'Y')
    {
        cout << "\nOFFICIAL RECEIPT" << endl;
        cout << "Customer's name : " << name << endl;
        cout << "Package : " << package << endl;
        cout << "Quantity : " << i << endl;
        cout << "Total price (incl 10% tax) : RM " << fixed << setprecision(2) << totalPrice << endl;
        cout << "Thank you for your visit! Please come again." << endl;
    }
}

void summary(string nameArr[], char packageArr[], int quantityArr[], double totalPriceArr[], int size)
{
    cout << "\n--------------SUMMARY REPORT----------------------- " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Customer no : " << (i + 1) << endl;
        cout << "Customer's name : " << nameArr[i] << endl;
        cout << "Package : " << packageArr[i] << endl;
        cout << "Quantity : " << quantityArr[i] << endl;
        cout << "Total price (incl 10% tax) : RM " << fixed << setprecision(2) << totalPriceArr[i] << endl;
        cout << endl;
    }
}
