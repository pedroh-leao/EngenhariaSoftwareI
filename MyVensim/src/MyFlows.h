#ifndef MYFLOWS_H
#define MYFLOWS_H

#include "Flow.h"

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

class MyFlow : public Flow{
public:
    MyFlow() {}
    MyFlow(System* source, System* target) : Flow(source, target){}
    MyFlow(const MyFlow& mf) : Flow(mf){}
    virtual ~MyFlow() {}

    double executeEquation(){
        return getSource()->getValue() * 0.01;
    }
};

#endif