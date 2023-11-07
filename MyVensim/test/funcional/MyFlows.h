#ifndef MYFLOWS_H
#define MYFLOWS_H

#include "../../src/Flow.h"

class Exponential : public Flow{
public:
    Exponential(System* source, System* target) : Flow(source, target){}

    double executeEquation(){
        return source->getValue() * 0.01;
    }
};

class Logistic : public Flow{
public:
    Logistic(System* source, System* target) : Flow(source, target){}

    double executeEquation(){
        double value = target->getValue();
        return 0.01 * value * (1 - value/70);
    }
};

class Complex : public Flow{
public:
    Complex(System* source, System* target) : Flow(source, target){}

    double executeEquation(){
        return source->getValue() * 0.01;
    }
};

#endif