#ifndef FLOW_H
#define FLOW_H

#include "System.h"

/**
 * @brief Interface class for flows
 */
class Flow {
public:
    /**
     * @brief Virtual destructor for the interface
     */
    virtual ~Flow() {}

    /**
     * @brief Pure virtual method to execute the equation for the flow
     * @return double containing the result of the equation
     */
    virtual double executeEquation() = 0;

    /**
     * @brief Pure virtual method to set the source system of the flow
     * @param s pointer to the source system of the flow
     */
    virtual void setSource(System* s) = 0;

    /**
     * @brief Pure virtual method to get the source system of the flow
     * @return system pointer that points to the source system of the flow
     */
    virtual System* getSource() const = 0;

    /**
     * @brief Pure virtual method to set the target system of the flow
     * @param s pointer to the target system of the flow
     */
    virtual void setTarget(System* s) = 0;

    /**
     * @brief Pure virtual method to get the target system of the flow
     * @return system pointer that points to the target system of the flow
     */
    virtual System* getTarget() const = 0;

    /**
     * @brief Pure virtual method to define how the '=' operator works for flows
     * @param f flow object that will be copied
     * @return a reference to the copied flow
     */
    virtual Flow& operator=(const Flow& f) = 0;
};

#endif