#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Flow.h"
#include "System.h"

using namespace std;

/**
 * @brief Class that defines a model, which is composed of systems and flows
*/
class Model{
protected:
    /**
     * @brief Model name
    */
    string name;

    /**
     * @brief A vector containing pointers to the model systems
    */
    vector<System*> systems;

    /**
     * @brief A vector containing pointers to the model flows
    */
    vector<Flow*> flows;

private:
    //prohibiting the copying of models

    /**
     * @brief Constructor for copy of model
     * @param m model object that will be copied
     * @return
    */
    Model(const Model& m);

    /**
     * @brief Defines how the '=' operator works for models
     * @param m model object that will be copied
     * @return a reference to the copied model
    */
    Model& operator=(const Model& m);
    
public:
    /**
     * @brief Model constructor that works as default as well
     * @param name model name
     * @return
    */
    Model(const string& name= "");
    
    /**
     * @brief Virtual class destructor
     * @param
     * @return
    */
    virtual ~Model();

    /**
     * @brief Adds a pointer to a system in the systems vector
     * @param s pointer to a system
     * @return bool representing whether the operation completed successfully
    */
    bool add(System* s);

    /**
     * @brief Adds a pointer to a flow in the flows vector
     * @param f pointer to a flow
     * @return bool representing whether the operation completed successfully
    */
    bool add(Flow* f);

    /**
     * @brief Removes the system pointer 's' of the systems vector
     * @param s pointer to a system
     * @return bool representing whether the operation completed successfully
    */
    bool remove(System* s);
    
    /**
     * @brief Removes the flow pointer 'f' of the flows vector
     * @param f pointer to a flow
     * @return bool representing whether the operation completed successfully
    */
    bool remove(Flow* f);

    /**
     * @brief Executes the model, performing flow operations and updating system values
     * @param startTime when the execution of the model starts
     * @param finalTime when the execution of the model ends
     * @return bool representing whether the execution completed successfully
    */
    bool run(int startTime, int finalTime);

    /**
     * @brief Shows the current model status, the systems values
     * @param
     * @return
    */
    void reportStatus();

    /**
     * @brief Sets the model name
     * @param name model name
     * @return
    */
    void setName(const string& name);

    /**
     * @brief Returns the model name
     * @param 
     * @return string containing the model name
    */
    string getName() const;

    /**
     * @brief Sets a typedef for a iterator of vector<System*>
    */
    typedef vector<System*>::iterator systemsIterator;

    /**
     * @brief Sets a typedef for a iterator of vector<Flow*>
    */
    typedef vector<Flow *>::iterator flowsIterator;

    /**
     * @brief Returns the iterator of the beginning of the systems vector
     * @param
     * @return systemsIterator being the iterator of the beginning of the vector
    */
    systemsIterator systemsBegin();

    /**
     * @brief Returns the iterator of the end of the systems vector
     * @param
     * @return systemsIterator being the iterator of the end of the vector
    */
    systemsIterator systemsEnd();

    /**
     * @brief Returns the iterator of the beginning of the flows vector
     * @param
     * @return flowsIterator being the iterator of the beginning of the vector
    */
    flowsIterator flowsBegin();

    /**
     * @brief Returns the iterator of the end of the flows vector
     * @param
     * @return flowsIterator being the iterator of the end of the vector
    */
    flowsIterator flowsEnd();
};

#endif