#ifndef MODEL_H
#define MODEL_H

#include "System.h"
#include "Flow.h"
#include "FlowImpl.h"

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
     * Pure virtual method to create a new Model
    */
    static Model& createModel(const string& name= "", const int& clock= 0);

    /**
     * @brief Pure virtual method to create a new System and add it to the model
    */
    virtual System& createSystem(const string& name= "", const double& value= 0.0) = 0;

    
    /**
     * @brief Pure virtual method to create a new Flow and add it to the model
    */
   template <typename T_FLOW>
    Flow& createFlow(System* source= NULL, System* target= NULL){
        Flow* f = new T_FLOW(source, target);
        add(f);
        return *f;
    }

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
     * @brief Sets a typedef for a iterator of vector<Model*>
    */
    typedef vector<Model*>::iterator modelsIterator;

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

    /**
     * @brief Pure virtual method to get the iterator of the beginning of the models vector
     * @return iterator of the beginning of the models vector
    */
    virtual modelsIterator modelsBegin() = 0;

    /**
     * @brief Pure virtual method to get the iterator of the end of the models vector
     * @return iterator of the end of the models vector
    */
    virtual modelsIterator modelsEnd() = 0;

protected:
    /**
     * @brief Pure virtual method to add a flow to the model
     * @param f pointer to a flow
     * @return bool representing whether the operation completed successfully
     */
    virtual bool add(Flow* f) = 0;

    /**
     * @brief Pure virtual method to add a model to the models vector
     * @param f pointer to a model
     * @return bool representing whether the operation completed successfully
     */
    static bool add(Model* m);
};

#endif
