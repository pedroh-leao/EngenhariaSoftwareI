#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.h"

/**
 * @brief Class that defines a system
*/
class SystemImpl : public System{
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
    SystemImpl(const string& name= "", const double& value= 0.0);

    /**
     * @brief Constructor for copy of system
     * @param s system object that will be copied
    */
    SystemImpl(const System& s);

    /**
     * @brief Virtual class destructor
    */
    virtual ~SystemImpl();

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
};

#endif