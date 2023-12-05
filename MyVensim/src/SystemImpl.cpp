#include "SystemImpl.h"

SystemBody :: SystemBody(const string& name, const double& value){
    this->name = name;
    this->value = value;
}

SystemBody :: SystemBody(const System& s){
    this->name = s.getName();
    this->value = s.getValue();
}

SystemBody :: ~SystemBody(){}

void SystemBody :: setName(const string& name){
    this->name = name;
}

string SystemBody :: getName() const{
    return name;
}

void SystemBody :: setValue(const double& value){
    this->value = value;
}

double SystemBody :: getValue() const{
    return value;
}

//SystemHandle:

SystemHandle :: SystemHandle(const string& name, const double& value){
    pImpl_->setName(name);
    pImpl_->setValue(value);
}

SystemHandle :: SystemHandle(const System& s){
    pImpl_->setName(s.getName());
    pImpl_->setValue(s.getValue());
}

SystemHandle :: ~SystemHandle(){}

void SystemHandle :: setName(const string& name){
    pImpl_->setName(name);
}

string SystemHandle :: getName() const{
    return pImpl_->getName();
}

void SystemHandle :: setValue(const double& value){
    pImpl_->setValue(value);
}

double SystemHandle :: getValue() const{
    return pImpl_->getValue();
}

System& SystemHandle :: operator=(const System& s){
    if(this == &s) return *this;

    pImpl_->setName(s.getName());
    pImpl_->setValue(s.getValue());

    return *this;
}