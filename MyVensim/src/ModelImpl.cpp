#include "ModelImpl.h"
#include "SystemImpl.h"
#include <iostream>

vector<Model *> ModelImpl::models;

ModelImpl :: ModelImpl(const string& name, const int& clock){
    this->name = name;
    this->clock = clock;
}

ModelImpl :: ModelImpl(const ModelImpl& m){
    this->name = m.name;
    systems.insert(systemsBegin(), m.systems.begin(), m.systems.end());
    flows.insert(flowsBegin(), m.flows.begin(), m.flows.end());
}

ModelImpl :: ~ModelImpl(){
    for(systemsIterator it = systemsBegin(); it < systemsEnd(); it++)
        delete *it;

    for(flowsIterator it = flowsBegin(); it < flowsEnd(); it++)
        delete *it;
    

    for(modelsIterator it = modelsBegin(); it < modelsEnd(); it++)
        if(*it == this){
            models.erase(it);
            break;
        }
}

Model& Model :: createModel(const string& name, const int& clock){
    return ModelImpl::createModel(name, clock);
}

Model& ModelImpl :: createModel(const string& name, const int& clock){
    Model* m = new ModelImpl(name, clock);
    add(m);
    return *m;
}

System& ModelImpl :: createSystem(const string& name, const double& value){
    System* s = new SystemImpl(name, value);
    add(s);
    return *s;
}

bool ModelImpl :: add(Model* m){
    int lenBefore = models.size();

    models.push_back(m);

    return (lenBefore != models.size());
}

bool ModelImpl :: add(System* s){
    int lenBefore = systems.size();

    systems.push_back(s);

    return (lenBefore != systems.size());
}

bool ModelImpl :: add(Flow* f){
    int lenBefore = flows.size();

    flows.push_back(f);

    return (lenBefore != flows.size());
}

bool ModelImpl :: remove(System* s){
    for(systemsIterator it = systemsBegin(); it < systemsEnd(); it++){
        if(*it == s){
            systems.erase(it);
            delete s;
            return true;
        }
    }

    return false;
}

bool ModelImpl :: remove(Flow* f){
    for(flowsIterator it = flowsBegin(); it < flowsEnd(); it++){
        if(*it == f){
            flows.erase(it);
            delete f;
            return true;
        }
    }

    return false;
}

bool ModelImpl :: run(int startTime, int finalTime){
    if(startTime > finalTime || startTime < 0) return false;

    clock = startTime;

    System *source, *target;

    vector<double> results;
    vector<double>::iterator itResults;

    int len = flows.size();
    for(int i = 0; i < len; i++)
        results.push_back(0.0);
    
    for(int i = startTime; i < finalTime; i++){
        itResults = results.begin();

        //execute the equations of the flows
        for(flowsIterator itFlows = flowsBegin(); itFlows < flowsEnd(); itFlows++){
            (*itResults) = (*itFlows)->executeEquation();
            itResults++;
        }

        itResults = results.begin();

        for(flowsIterator itFlows = flowsBegin(); itFlows < flowsEnd(); itFlows++){            
            source = (*itFlows)->getSource();
            source->setValue(source->getValue() - (*itResults));

            target = (*itFlows)->getTarget();
            target->setValue(target->getValue() + (*itResults));

            itResults++;
        }

        clock = i;
    }

    clock += 1;

    return true;
}

void ModelImpl :: reportStatus(){
    cout << "\nCurrent Model Status:" << endl;

    for(systemsIterator it = systemsBegin(); it < systemsEnd(); it++)
        cout << (*it)->getName() << ": " << (*it)->getValue() << endl;
}

void ModelImpl :: setName(const string& name){
    this->name = name;
}

string ModelImpl :: getName() const{
    return name;
}

void ModelImpl :: setClock(const int& clock){
    this->clock = clock;
}

int ModelImpl :: getClock() const{
    return clock;
}

ModelImpl& ModelImpl:: operator= (const ModelImpl& m){
    if(this == &m) return *this;

    this->name = m.name;

    systems.clear();
    systems.insert(systemsBegin(), m.systems.begin(), m.systems.end());
    
    flows.clear();
    flows.insert(flowsBegin(), m.flows.begin(), m.flows.end());
    
    return *this;
}

ModelImpl::systemsIterator ModelImpl :: systemsBegin(){
    return systems.begin();
}

ModelImpl::systemsIterator ModelImpl :: systemsEnd(){
    return systems.end();
}

ModelImpl::flowsIterator ModelImpl :: flowsBegin(){
    return flows.begin();
}

ModelImpl::flowsIterator ModelImpl :: flowsEnd(){
    return flows.end();
}

ModelImpl::modelsIterator ModelImpl :: modelsBegin(){
    return models.begin();
}

ModelImpl::modelsIterator ModelImpl :: modelsEnd(){
    return models.end();
}