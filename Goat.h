// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    
    Goat(string a)                          { name = a; age = 0; color = ""; }
    Goat(string a, int b)                   { name = a; age = b; color = ""; }
    Goat(string a, int b, string c)         { name = a; age = b; color = c; }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    bool operator< (const Goat &other) const {
        if (name != other.name)
            return name < other.name;
        return age < other.age;
    }
        void display() const {
        cout << name << " (" << age << ", " << color << ")" << endl;
    }
};

#endif