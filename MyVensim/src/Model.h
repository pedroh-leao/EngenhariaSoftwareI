#ifndef MODEL_H
#define MODEL_H

#include "System.h"
#include "Flow.h"

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Interface class for models
 */
class Model {
public:
    /**
     * @brief Virtual destructor for the interface
     */
    virtual ~Model() {}

    /**
     * @brief Pure virtual method to add a system to the model
     * @param s pointer to a system
     * @return bool representing whether the operation completed successfully
     */
    virtual bool add(System* s) = 0;

    /**
     * @brief Pure virtual method to add a flow to the model
     * @param f pointer to a flow
     * @return bool representing whether the operation completed successfully
     */
    virtual bool add(Flow* f) = 0;

    /**
     * @brief Pure virtual method to remove a system from the model
     * @param s pointer to a system
     * @return bool representing whether the operation completed successfully
     */
    virtual bool remove(System* s) = 0;

    /**
     * @brief Pure virtual method to remove a flow from the model
     * @param f pointer to a flow
     * @return bool representing whether the operation completed successfully
     */
    virtual bool remove(Flow* f) = 0;

    /**
     * @brief Pure virtual method to execute the model
     * @param startTime when the execution of the model starts
     * @param finalTime when the execution of the model ends
     * @return bool representing whether the execution completed successfully
     */
    virtual bool run(int startTime, int finalTime) = 0;

    /**
     * @brief Pure virtual method to show the current model status
     */
    virtual void reportStatus() = 0;

    /**
     * @brief Pure virtual method to set the model name
     * @param name model name
     */
    virtual void setName(const string& name) = 0;

    /**
     * @brief Pure virtual method to get the model name
     * @return string containing the model name
     */
    virtual string getName() const = 0;

    /**
     * @brief Pure virtual method to set the model clock
     * @param clock model clock
    */
    virtual void setClock(const int& clock) = 0;

    /**
     * @brief Pure virtual method to get the model clock
     * @return int containing the value of model clock
    */
   virtual int getClock() const = 0;

    /**
     * @brief Sets a typedef for a iterator of vector<System*>
    */
    typedef vector<System*>::iterator systemsIterator;

    /**
     * @brief Sets a typedef for a iterator of vector<Flow*>
    */
    typedef vector<Flow*>::iterator flowsIterator;

    /**
     * @brief Pure virtual method to get the iterator of the beginning of the systems vector
     * @return iterator of the beginning of the systems vector
     */
    virtual systemsIterator systemsBegin() = 0;

    /**
     * @brief Pure virtual method to get the iterator of the end of the systems vector
     * @return iterator of the end of the systems vector
     */
    virtual systemsIterator systemsEnd() = 0;

    /**
     * @brief Pure virtual method to get the iterator of the beginning of the flows vector
     * @return iterator of the beginning of the flows vector
     */
    virtual flowsIterator flowsBegin() = 0;

    /**
     * @brief Pure virtual method to get the iterator of the end of the flows vector
     * @return iterator of the end of the flows vector
     */
    virtual flowsIterator flowsEnd() = 0;
};

#endif
