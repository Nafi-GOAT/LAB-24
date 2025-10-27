//
//Mehraj Hasan Nafi|Lab24
//IDE: VS code
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <cstdlib>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int main_menu();
void add_goat(set<Goat> &trip, string names[], string colors[]);
void delete_goat(set<Goat> &trip);
void display_trip(const set<Goat> &trip);

// Function to display the main menu and get user choice

int main_menu() {
    int num;

    cout << "\n--- Goat MANAGER 3001---\n";
    cout << "1. Add a goat \n";
    cout << "2. Delete a goat\n";
    cout << "3. List of goat\n";
    cout << "4. Quit\n";
    cout << "Enter your choice: ";
    cin >> num;

        while (num < 1 || num > 4) {
       cout << "Invalid number choice, please re-enter: ";
        cin >> num;
    }
return num;
}


void add_goat(set<Goat> &trip, string names[], string colors[]) {
   
    int nameI = rand() % SZ_NAMES;
    int colorI = rand() % SZ_COLORS;
    int age = rand() % (MAX_AGE + 1);

    Goat g(names[nameI], age, colors[colorI]); 
    auto result = trip.insert(g);

    if (result.second)
        cout << "New goat added: ";
    else
        cout << "Duplicate goat ignored: ";

    g.display();
}

 void display_trip(const set<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats in the trip." << endl;
        return;
    }

    int a = 1;
    for (const Goat &g : trip) {
        cout << "[ " << a++ << " ] ";
        g.display();
    }
}

void delete_goat(set<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats to delete.\n";
        return;
    }

    display_trip(trip);

    cout << "Enter goat name to delete: ";
    string name;
    cin >> name;

    
    bool found = false;
    for (auto it = trip.begin(); it != trip.end(); ++it) {
        if (it->getName() == name) {
            cout << "Deleting goat: ";
            it->display();
            trip.erase(it);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No goat found with name \"" << name << "\".\n";
}
int main() {
    srand(time(0));
    set<Goat> trip;
    string names[SZ_NAMES], colors[SZ_COLORS];

    // Load names
    ifstream fin("names.txt");
    int i = 0;
    while (i < SZ_NAMES && fin >> names[i]) i++;
    fin.close();

    // Load colors
    ifstream fin1("colors.txt");
    i = 0;
    while (i < SZ_COLORS && fin1 >> colors[i]) i++;
    fin1.close();

    bool again = true;


 while (again) {
        int num = main_menu();
        cout << endl;
 
        switch (num) {
            case 1:
                add_goat(trip, names, colors);
                cout << endl;
                break;

            case 2:
                delete_goat(trip);
                cout << endl;
                break;

            case 3:
                display_trip(trip);
                cout << endl;
                break;

            case 4:
                again = false;
                break;
        }
    }

    return 0;
}

