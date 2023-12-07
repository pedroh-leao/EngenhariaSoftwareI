#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "Flow.h"
#include "handleBody.h"

/**
 * @brief Class that defines a flow, which is a connection between two systems
*/
class FlowBody : public Body{
protected:
    /**
     * @brief Pointers to the source and target systems of the flow
    */
    System *source, *target;

public:
    /**
     * @brief Flow default constructor
    */
    FlowBody();

    /**
     * @brief Flow constructor that receives pointers to the source and target systems
     * @param source pointer to the source system of the flow
     * @param target pointer to the target system of the flow
    */
    FlowBody(System* source, System* target);

    /**
     * @brief Constructor for copy of flow
     * @param f flow object that will be copied
    */
    FlowBody(const Flow& f);

    /**
     * @brief Virtual class destructor
    */
    virtual ~FlowBody();

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
};

template <class T> 
class FlowHandle : public Flow, public Handle<T>{
public:
    /**
     * @brief Flow default constructor
    */
    FlowHandle(){
        Handle<T>::pImpl_->setSource(NULL);
        Handle<T>::pImpl_->setTarget(NULL);
    }

    /**
     * @brief Flow constructor that receives pointers to the source and target systems
     * @param source pointer to the source system of the flow
     * @param target pointer to the target system of the flow
    */
    FlowHandle(System* source, System* target){
        Handle<T>::pImpl_->setSource(source);
        Handle<T>::pImpl_->setTarget(target);
    }

    /**
     * @brief Constructor for copy of flow
     * @param f flow object that will be copied
    */
    FlowHandle(const Flow& f){
        Handle<T>::pImpl_->setSource(f.getSource());
        Handle<T>::pImpl_->setTarget(f.getTarget());
    }

    /**
     * @brief Sets the pointer to the source system of the flow
     * @param s pointer to the source system of the flow
    */
    void setSource(System* s){Handle<T>::pImpl_->setSource(s);}

    /**
     * @brief Returns the pointer to the source system of the flow
     * @return system pointer that points to the source system of the flow
    */
    System* getSource() const{return Handle<T>::pImpl_->getSource();}

    /**
     * @brief Sets the pointer to the target system of the flow
     * @param s pointer to the target system of the flow
    */
    void setTarget(System* s){Handle<T>::pImpl_->setTarget(s);}

    /**
     * @brief Returns the pointer to the target system of the flow
     * @return system pointer that points to the target system of the flow
    */
    System* getTarget() const{return Handle<T>::pImpl_->getTarget();}

    /**
     * @brief Executes the equation that must be performed by the flow
     * @return double containing the result of the equation
    */
    double executeEquation(){return Handle<T>::pImpl_->executeEquation();}

    /**
     * @brief Defines how the '=' operator works for flows
     * @param f flow object that will be copied
     * @return a reference to the copied flow
    */
    Flow& operator=(const Flow& f){
        if(this == &f) return *this;

        Handle<T>::pImpl_->setSource(f.getSource());
        Handle<T>::pImpl_->setTarget(f.getTarget());

        return *this;
    }
};

#endif