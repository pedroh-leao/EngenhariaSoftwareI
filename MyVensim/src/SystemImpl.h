#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.h"
#include "handleBody.h"

/**
 * @brief Class that defines a system
*/
class SystemBody : public Body{
protected:
    /**
     * @brief System name
    */
    string name;

    /**
     * @brief System value
    */
    double value = 0.0;

public:
    /**
     * @brief System constructor that works as default as well
     * @param name system name
     * @param value system initial value
    */
    SystemBody(const string& name= "", const double& value= 0.0);

    /**
     * @brief Constructor for copy of system
     * @param s system object that will be copied
    */
    SystemBody(const System& s);

    /**
     * @brief Virtual class destructor
    */
    virtual ~SystemBody();

    /**
     * @brief Sets the system name
     * @param name system name
    */
    void setName(const string& name);

    /**
     * @brief Returns the system name
     * @return a string containing the system name
    */
    string getName() const;

    /**
     * @brief Sets the system value
     * @param value system value
    */
    void setValue(const double& value);

    /**
     * @brief Returns the system value
     * @return a double containing the system value
    */
    double getValue() const;
};


class SystemHandle : public System, public Handle<SystemBody>{
public:
/**
     * @brief System constructor that works as default as well
     * @param name system name
     * @param value system initial value
    */
    SystemHandle(const string& name= "", const double& value= 0.0);

    /**
     * @brief Constructor for copy of system
     * @param s system object that will be copied
    */
    SystemHandle(const System& s);

    /**
     * @brief Sets the system name
     * @param name system name
    */
    void setName(const string& name);

    /**
     * @brief Returns the system name
     * @return a string containing the system name
    */
    string getName() const;

    /**
     * @brief Sets the system value
     * @param value system value
    */
    void setValue(const double& value);

    /**
     * @brief Returns the system value
     * @return a double containing the system value
    */
    double getValue() const;

    /**
     * @brief Defines how the '=' operator works for systems
     * @param s system object that will be copied
     * @return a reference to the copied system
    */
    System& operator=(const System& s);

    /**
     * @brief Defines how the '=' operator works for systems
     * @param s system object that will be copied
     * @return a reference to the copied system
    */
    SystemHandle& operator=(const SystemHandle& s);
};

#endif