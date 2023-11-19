#ifndef MYFLOWS_H
#define MYFLOWS_H

#include "../../src/FlowImpl.h"

/**
 * @brief Class that defines a flow with an exponential equation
*/
class Exponential : public FlowImpl{
public:
    /**
     * @brief Default constructor
    */
    Exponential() : FlowImpl(){}

    /**
     * @brief Exponential flow constructor that receives pointers to the source and target systems
     * @param source pointer to the source system of the flow
     * @param target pointer to the target system of the flow
    */
    Exponential(System* source, System* target) : FlowImpl(source, target){}

    /**
     * @brief Copy Constructor
    */
    Exponential(const Flow& f) : FlowImpl(f){}

    /**
     * @brief Executes the exponential equation that must be performed by the flow
     * @return double containing the result of the equation
    */
    double executeEquation(){
        return source->getValue() * 0.01;
    }
};

/**
 * @brief Class that defines a flow with a logistic equation
*/
class Logistic : public FlowImpl{
public:
    /**
     * @brief Default constructor
    */
    Logistic() : FlowImpl(){}

    /**
     * @brief Logistic flow constructor that receives pointers to the source and target systems
     * @param source pointer to the source system of the flow
     * @param target pointer to the target system of the flow
    */
    Logistic(System* source, System* target) : FlowImpl(source, target){}

    /**
     * @brief Copy Constructor
    */
    Logistic(const Flow& f) : FlowImpl(f){}

    /**
     * @brief Executes the logistic equation that must be performed by the flow
     * @return double containing the result of the equation
    */
    double executeEquation(){
        double value = target->getValue();
        return 0.01 * value * (1 - value/70);
    }
};

/**
 * @brief Class that defines a flow with a complex equation
*/
class Complex : public FlowImpl{
public:
    /**
     * @brief Default constructor
    */
    Complex() : FlowImpl(){}

    /**
     * @brief Complex flow constructor that receives pointers to the source and target systems
     * @param source pointer to the source system of the flow
     * @param target pointer to the target system of the flow
    */
    Complex(System* source, System* target) : FlowImpl(source, target){}

    /**
     * @brief Copy Constructor
    */
    Complex(const Flow& f) : FlowImpl(f){}

    /**
     * @brief Executes the complex equation that must be performed by the flow
     * @return double containing the result of the equation
    */
    double executeEquation(){
        return source->getValue() * 0.01;
    }
};

#endif