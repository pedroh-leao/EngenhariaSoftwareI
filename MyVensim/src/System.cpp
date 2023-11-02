#include "System.h"

System :: System(const string& name, const double& value){
    this->name = name;
    this->value = value;
}

System :: System(const System& s){
    this->name = s.name;
    this->value = s.value;
}

System :: ~System(){}

void System :: setName(const string& name){
    this->name = name;
}

string System :: getName() const{
    return name;
}

void System :: setValue(const double& value){
    this->value = value;
}

double System :: getValue() const{
    return value;
}

System& System :: operator=(const System& s){
    if(this == &s) return *this;

    this->name = s.name;
    this->value = s.value;

    return *this;
}