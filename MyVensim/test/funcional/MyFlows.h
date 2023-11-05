#ifndef MYFLOWS_H
#define MYFLOWS_H

#include "../../src/Flow.h"

class Exponential : public Flow{
public:
    Exponential() {}
    Exponential(System* source, System* target) : Flow(source, target){}
    Exponential(const Exponential& ex) : Flow(ex){}
    virtual ~Exponential() {}

    double executeEquation(){
        return getSource()->getValue() * 0.01;
    }
};

class Logistic : public Flow{
public:
    Logistic() {}
    Logistic(System* source, System* target) : Flow(source, target){}
    Logistic(const Logistic& lg) : Flow(lg){}
    virtual ~Logistic() {}

    double executeEquation(){
        double value = getTarget()->getValue();
        return 0.01 * value * (1 - value/70);
    }
};

class Complex : public Flow{
public:
    Complex() {}
    Complex(System* source, System* target) : Flow(source, target){}
    Complex(const Complex& mf) : Flow(mf){}
    virtual ~Complex() {}

    double executeEquation(){
        return getSource()->getValue() * 0.01;
    }
};

#endif