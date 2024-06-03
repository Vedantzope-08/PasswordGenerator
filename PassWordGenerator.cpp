#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

string randchar()
{
    vector<string> words;
    for (int i = 33; i <= 64; i++)
    {
        char c = i;
        string a;
        a += c;
        words.push_back(a);
    }

    int index = rand() % 32;

    return words[index];
}

string generateRandomString()
{
    const int length = 10;
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string randomString;

    for (int i = 0; i < length; ++i)
    {
        int index = rand() % alphabet.length();
        randomString += alphabet[index];
    }

    return randomString;
}

int main()
{
    srand(time(0)); 

    string fname, lname, dd, mm, yy;

    cout << "Enter your First name: ";
    cin >> fname;

    cout << "Enter your Last name: ";
    cin >> lname;

    cout << "Enter your Birthdate: ";
    cin >> dd;

    cout << "Enter your Birthmonth: ";
    cin >> mm;

    cout << "Enter your Birthyear: ";
    cin >> yy;

    int i = 1;
    do
    {
        string randchar_str = randchar();
        string randomStr = generateRandomString();

        string pass;
        int n = rand() % 11 + 1;

        switch (n)
        {
        case 1:
            pass = fname + lname + randchar_str + yy;
            break;
        case 2:
            pass = fname + lname + randchar_str + dd + mm;
            break;
        case 3:
            pass = lname + fname + randchar_str + yy;
            break;
        case 4:
            pass = fname + lname + randchar_str + dd + mm;
            break;
        case 5:
            pass = fname + lname + randchar_str + dd + yy;
            break;
        case 6:
            pass = fname + randchar_str + lname + yy;
            break;
        case 7:
            pass = fname + lname + randchar_str + mm + yy;
            break;
        case 8:
            pass = lname + randchar_str + fname + yy;
            break;
        case 9:
            pass = randomStr + randchar_str + yy;
            break;
        case 10:
            pass = randomStr + randchar_str + dd + mm;
            break;
        case 11:
            pass = randomStr + randchar_str + mm + dd;
            break;
        }

        cout << "Generated Password: " << pass << endl << endl;

        int p;
        cout << "To generate another password, enter 1. To exit, enter 0: ";
        cin >> p;

        if (p == 1)
        {
            // Clear screen (platform dependent)
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        }
        else if(p==0)
        {
        	remove("Pass.txt");      	
        	ofstream my_file("Pass.txt");
        	my_file<<pass;
            break;
        }
    } while (i < 2);

    return 0;
}

