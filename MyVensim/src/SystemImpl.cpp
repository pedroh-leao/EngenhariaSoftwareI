#include "SystemImpl.h"

SystemImpl :: SystemImpl(const string& name, const double& value){
    this->name = name;
    this->value = value;
}

SystemImpl :: SystemImpl(const System& s){
    this->name = s.getName();
    this->value = s.getValue();
}

SystemImpl :: ~SystemImpl(){}

void SystemImpl :: setName(const string& name){
    this->name = name;
}

string SystemImpl :: getName() const{
    return name;
}

void SystemImpl :: setValue(const double& value){
    this->value = value;
}

double SystemImpl :: getValue() const{
    return value;
}

System& SystemImpl :: operator=(const System& s){
    if(this == &s) return *this;

    this->name = s.getName();
    this->value = s.getValue();

    return *this;
}