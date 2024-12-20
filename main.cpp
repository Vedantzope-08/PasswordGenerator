#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>

using namespace std;

string shuffleString(const string& input) {
    string shuffled = input;
    int n = shuffled.length();

    for (int i = 0; i < n; ++i) {
        int randomIndex = rand() % n;  // Generate a random index
        swap(shuffled[i], shuffled[randomIndex]);  // Swap characters
    }

    return shuffled;
}


void ensureLength(string& str) {
    const string symbols = "@#$%^&*!";
    while (str.length() < 8) {
        char randomSymbol = symbols[rand() % symbols.length()];
        int randomPosition = 1 + rand() % (str.length() - 1);  // Random position excluding front and end
        str.insert(str.begin() + randomPosition, randomSymbol);
    }
}

void ensureCapitalLetter(string& str) {
    bool hasCapital = false;


    for (char ch : str) {
        if (isupper(ch)) {
            hasCapital = true;
            break;
        }
    }

    // If no capital letter, add one at a random position (excluding front and end)
    if (!hasCapital) {
        char capitalLetter = 'A' + rand() % 26;  // Random capital letter
        int randomPosition = 1 + rand() % (str.length() - 1);
        str.insert(str.begin() + randomPosition, capitalLetter);
    }
}

void ensureSymbol(string& str) {
    const string symbols = "@#$%^&*!";
    bool hasSymbol = false;

    for (char ch : str) {
        if (symbols.find(ch) != string::npos) {
            hasSymbol = true;
            break;
        }
    }

    if (!hasSymbol) {
        char randomSymbol = symbols[rand() % symbols.length()];
        int randomPosition = 1 + rand() % (str.length() - 1);
        str.insert(str.begin() + randomPosition, randomSymbol);
    }
}

int main() {

    srand(0);


    string firstName, lastName, birthYear;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your birth year: ";
    cin >> birthYear;

    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.1.117", "admin", "0000", "password", 0, NULL, 0);

    int qstate = 0;
    stringstream ss;


    string combined = firstName + lastName + birthYear;

    int p;
    while (true) {

        string password = shuffleString(combined);


        ensureLength(password);


        ensureCapitalLetter(password);


        ensureSymbol(password);


        cout << "Your generated password is: " << password << endl;


        cout << "Press 1 to regenerate, or 0 to save and exit: ";
        cin >> p;

        if (p == 1) {
           \
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        } else if (p == 0) {


 ss << "SELECT 1 FROM data WHERE FName = '" << firstName << "' AND LName = '" << lastName << "'";
    string checkQuery = ss.str();
    const char* checkQ = checkQuery.c_str();
    qstate = mysql_query(conn, checkQ);

    if (qstate == 0) {
        MYSQL_RES* res = mysql_store_result(conn);
        if (mysql_num_rows(res) > 0) {

            ss.str("");
            ss << "UPDATE data SET Pass = '" << password << "' WHERE FName = '" << firstName << "' AND LName = '" << lastName << "'";
            string updateQuery = ss.str();
            const char* updateQ = updateQuery.c_str();
            qstate = mysql_query(conn, updateQ);

            if (qstate == 0) {
                cout << "Password updated successfully!" << endl;
            } else {
                cout << "Failed to update password!" << endl;
            }
        } else {

            ss.str("");
            ss << "INSERT INTO data (FName, LName, Pass) VALUES ('" << firstName << "', '" << lastName << "', '" << password << "')";
            string insertQuery = ss.str();
            const char* insertQ = insertQuery.c_str();
            qstate = mysql_query(conn, insertQ);

            if (qstate == 0) {
                cout << "Password was saved!" << endl;
            } else {
                cout << "Failed to save password!" << endl;
            }
        }
        mysql_free_result(res);
    } else {
        cout << "Error checking for existing record!" << endl;
    }
    break;
        }

        if (p != 1 && p != 0) {
            cout << "Invalid input! Exiting program." << endl;
            break;
        }
    }

    cout << "Thank you for using the password generator!" << endl;
    return 0;
}
