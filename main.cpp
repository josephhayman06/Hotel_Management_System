#include <iostream>
#include <string>

using namespace std;

struct Manager {
    string username;
    string password;
};

struct Receptionist {
    string username;
    string password;
};

const int MAX_RECEPTIONIST = 5;
const int MAX_MANAGERS = 5;

Manager managers[MAX_MANAGERS];
Receptionist receptionists[MAX_RECEPTIONIST];

int managerCount = 0;
int receptionistCount = 0;


void signUp(int choice) {
    cin.ignore();

    if (choice == 1) {
        if (managerCount < MAX_MANAGERS) {
            cout << "Enter username: ";
            getline(cin, managers[managerCount].username);

            cout << "Enter password: ";
            getline(cin, managers[managerCount].password);

            managerCount++;
            cout << "Manager registered successfully!\n";
        }
        else {
            cout << "Manager limit reached!\n";
        }
    }
    else if (choice == 2) {
        if (receptionistCount < MAX_RECEPTIONIST) {
            cout << "Enter username: ";
            getline(cin, receptionists[receptionistCount].username);

            cout << "Enter password: ";
            getline(cin, receptionists[receptionistCount].password);

            receptionistCount++;
            cout << "Receptionist registered successfully!\n";
        }
        else {
            cout << "Receptionist limit reached!\n";
        }
    }
    else {
        cout << "Invalid choice!\n";
    }
}


void logIn(int choice) {
    cin.ignore();

    cout << "Enter username: ";
    string username;
    getline(cin, username);

    cout << "Enter password: ";
    string password;
    getline(cin, password);

    if (choice == 1) {
        for (int i = 0; i < managerCount; i++) {
            if (username == managers[i].username && password == managers[i].password) {
                cout << "Manager login successful!\n";
                return;
            }
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < receptionistCount; i++) {
            if (username == receptionists[i].username && password == receptionists[i].password) {
                cout << "Receptionist login successful!\n";
                return;
            }
        }
    }
    cout << "Invalid username or password!\n";
}

int main() {
    while (true) {
        cout << "\n1. Login\n";
        cout << "2. Sign Up\n";
        cout << "Enter your choice: ";

        int n;
        cin >> n;

        if (n == 1) {
            cout << "1. Login as a Manager\n";
            cout << "2. Login as a Receptionist\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            logIn(choice);
        }
        else if (n == 2) {
            cout << "1. Sign up as a Manager\n";
            cout << "2. Sign up as a Receptionist\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            signUp(choice);
        }
        else {
            cout << "Invalid input! Try again.\n";
        }
    }

    return 0;
}
