#ifndef FLOW_H
#define FLOW_H

#include "System.h"

/**
 * @brief Class that defines a flow, which is a connection between two systems
*/
class Flow{
protected:
    /**
     * @brief Pointers to the source and target systems of the flow
    */
    System *source, *target;

public:
    /**
     * @brief Flow default constructor
     * @param
     * @return
    */
    Flow();

    /**
     * @brief Flow constructor that receives pointers to the source and target systems
     * @param source pointer to the source system of the flow
     * @param target pointer to the target system of the flow
     * @return
    */
    Flow(System* source, System* target);

    /**
     * @brief Constructor for copy of flow
     * @param f flow object that will be copied
     * @return
    */
    Flow(const Flow& f);

    /**
     * @brief Virtual class destructor
     * @param
     * @return
    */
    virtual ~Flow();

    /**
     * @brief Sets the pointer to the source system of the flow
     * @param s pointer to the source system of the flow
     * @return
    */
    void setSource(System* s);

    /**
     * @brief Returns the pointer to the source system of the flow
     * @param
     * @return system pointer that points to the source system of the flow
    */
    System* getSource() const;

    /**
     * @brief Sets the pointer to the target system of the flow
     * @param s pointer to the target system of the flow
     * @return
    */
    void setTarget(System* s);

    /**
     * @brief Returns the pointer to the target system of the flow
     * @param
     * @return system pointer that points to the target system of the flow
    */
    System* getTarget() const;

    /**
     * @brief Executes the equation that must be performed by the flow
     * @param
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