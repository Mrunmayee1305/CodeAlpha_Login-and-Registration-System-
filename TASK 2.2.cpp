#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Choose a strong password:";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "Oops! Username and password can't be empty." << endl;
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << "," << password << endl;
    file.close();
     
}

void loginUser() {
    string username, password;
    cout << "\nEnter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    bool success = false;
    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string storedUsername = line.substr(0, commaPos);
            string storedPassword = line.substr(commaPos + 1);

            if (storedUsername == username && storedPassword == password) {
                success = true;
                break;
            }
        }
    }

    if (success) {
        cout << "Welcome back, " << username << "! You're logged in!" << endl;
    } else {
        cout << "Sorry, wrong username or password. Try again!" << endl;
    }
}

int main() {
    cout << "Hey there! Welcome to our system!" << endl;
    registerUser();
    loginUser();
    cout << "See you soon!" << endl;
    return 0;
}
