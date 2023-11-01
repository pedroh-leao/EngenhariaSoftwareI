#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System{
    string name;
    double value = 0.0;

public:
    System(const string = "", const double = 0.0);
    System(const System&); //constructor for copy
    ~System();

    void setName(const string);
    string getName() const;

    void setValue(const double);
    double getValue() const;

    System& operator=(const System&);
};

#endif