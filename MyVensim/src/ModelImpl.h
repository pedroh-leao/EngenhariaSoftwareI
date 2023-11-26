#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"

/**
 * @brief Class that defines a model, which is composed of systems and flows
*/
class ModelImpl : public Model{
protected:
    /**
     * @brief Model name
    */
    string name;

    /**
     * @brief Model clock that saves the time the model is in
    */
    int clock;

    /**
     * @brief A vector containing pointers to the model systems
    */
    vector<System*> systems;

    /**
     * @brief A vector containing pointers to the model flows
    */
    vector<Flow*> flows;

    /**
     * @brief A static vector containing pointers to the models created
    */
    static vector<Model*> models;

private:
    //prohibiting the copying of models

    /**
     * @brief Constructor for copy of model
     * @param m model object that will be copied
     * @return
    */
    ModelImpl(const ModelImpl& m);

    /**
     * @brief Defines how the '=' operator works for models
     * @param m model object that will be copied
     * @return a reference to the copied model
    */
    ModelImpl& operator=(const ModelImpl& m);

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
     * @brief Adds a model to the models vector
     * @param f pointer to a model
     * @return bool representing whether the operation completed successfully
     */
    static bool add(Model* m);
    
public:
    /**
     * @brief Model constructor that works as default as well
     * @param name model name
     * @param clock model clock value
    */
    ModelImpl(const string& name= "", const int& clock= 0);
    
    /**
     * @brief Virtual class destructor
    */
    virtual ~ModelImpl();

    /**
     * Creates a new Model
    */
    static Model& createModel(const string& name= "", const int& clock= 0);

    /**
     * @brief Creates a new System and add it to the model
    */
    System& createSystem(const string& name= "", const double& value= 0.0);

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
    */
    void reportStatus();

    /**
     * @brief Sets the model name
     * @param name model name
    */
    void setName(const string& name);

    /**
     * @brief Returns the model name
     * @return string containing the model name
    */
    string getName() const;

    /**
     * @brief Sets the model clock
     * @param clock model clock
    */
    void setClock(const int& clock);

    /**
     * @brief Returns the model clock
     * @return int containing the value of model clock
    */
   int getClock() const;

    /**
     * @brief Returns the iterator of the beginning of the systems vector
     * @return systemsIterator being the iterator of the beginning of the vector
    */
    systemsIterator systemsBegin();

    /**
     * @brief Returns the iterator of the end of the systems vector
     * @return systemsIterator being the iterator of the end of the vector
    */
    systemsIterator systemsEnd();

    /**
     * @brief Returns the iterator of the beginning of the flows vector
     * @return flowsIterator being the iterator of the beginning of the vector
    */
    flowsIterator flowsBegin();

    /**
     * @brief Returns the iterator of the end of the flows vector
     * @return flowsIterator being the iterator of the end of the vector
    */
    flowsIterator flowsEnd();

    /**
     * @brief Returns the iterator of the beginning of the models vector
     * @return modelsIterator iterator of the beginning of the models vector
    */
    modelsIterator modelsBegin();

    /**
     * @brief Returns the iterator of the end of the models vector
     * @return modelsIterator iterator of the end of the models vector
    */
    modelsIterator modelsEnd();
};

#endif