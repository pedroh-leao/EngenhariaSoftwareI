#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "Flow.h"

/**
 * @brief Class that defines a flow, which is a connection between two systems
*/
class FlowImpl : public Flow{
protected:
    /**
     * @brief Pointers to the source and target systems of the flow
    */
    System *source, *target;

public:
    /**
     * @brief Flow default constructor
    */
    FlowImpl();

    /**
     * @brief Flow constructor that receives pointers to the source and target systems
     * @param source pointer to the source system of the flow
     * @param target pointer to the target system of the flow
    */
    FlowImpl(System* source, System* target);

    /**
     * @brief Constructor for copy of flow
     * @param f flow object that will be copied
    */
    FlowImpl(const Flow& f);

    /**
     * @brief Virtual class destructor
    */
    virtual ~FlowImpl();

    /**
     * @brief Sets the pointer to the source system of the flow
     * @param s pointer to the source system of the flow
    */
    void setSource(System* s);

    /**
     * @brief Returns the pointer to the source system of the flow
     * @return system pointer that points to the source system of the flow
    */
    System* getSource() const;

    /**
     * @brief Sets the pointer to the target system of the flow
     * @param s pointer to the target system of the flow
    */
    void setTarget(System* s);

    /**
     * @brief Returns the pointer to the target system of the flow
     * @return system pointer that points to the target system of the flow
    */
    System* getTarget() const;

    /**
     * @brief Executes the equation that must be performed by the flow
     * @return double containing the result of the equation
    */
    virtual double executeEquation() = 0;

    /**
     * @brief Defines how the '=' operator works for flows
     * @param f flow object that will be copied
     * @return a reference to the copied flow
    */
    Flow& operator=(const Flow& f);
};


#endif