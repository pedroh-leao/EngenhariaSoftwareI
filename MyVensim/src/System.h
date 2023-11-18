#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

/**
 * @brief Interface class for systems
 */
class System {
public:
    /**
     * @brief Virtual destructor for the interface
     */
    virtual ~System() {}

    /**
     * @brief Pure virtual method to set the system name
     * @param name system name
     */
    virtual void setName(const string& name) = 0;

    /**
     * @brief Pure virtual method to get the system name
     * @return a string containing the system name
     */
    virtual string getName() const = 0;

    /**
     * @brief Pure virtual method to set the system value
     * @param value system value
     */
    virtual void setValue(const double& value) = 0;

    /**
     * @brief Pure virtual method to get the system value
     * @return a double containing the system value
     */
    virtual double getValue() const = 0;

    /**
     * @brief Pure virtual method to define how the '=' operator works for systems
     * @param s system object that will be copied
     * @return a reference to the copied system
     */
    virtual System& operator=(const System& s) = 0;
};

#endif