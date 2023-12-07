#include "ModelImpl.h"
#include "SystemImpl.h"
#include <iostream>

vector<Model *> ModelBody::models;

ModelBody :: ModelBody(const string& name, const int& clock){
    this->name = name;
    this->clock = clock;
}

ModelBody :: ModelBody(const ModelBody& m){
    this->name = m.name;
    systems.insert(systemsBegin(), m.systems.begin(), m.systems.end());
    flows.insert(flowsBegin(), m.flows.begin(), m.flows.end());
}

ModelBody :: ~ModelBody(){
    for(Model::systemsIterator it = systemsBegin(); it < systemsEnd(); it++)
        delete *it;

    for(Model::flowsIterator it = flowsBegin(); it < flowsEnd(); it++)
        delete *it;

    // for(Model::modelsIterator it = modelsBegin(); it < modelsEnd(); it++){
    //     if(*it == this){
    //         models.erase(it);
    //         break;
    //     }     
    // }
}

Model& Model :: createModel(const string& name, const int& clock){
    return ModelBody::createModel(name, clock);
}

Model& ModelBody :: createModel(const string& name, const int& clock){
    Model* m = new ModelHandle(name, clock);
    add(m);
    return *m;
}

System& ModelBody :: createSystem(const string& name, const double& value){
    System* s = new SystemHandle(name, value);
    add(s);
    return *s;
}

bool ModelBody :: add(Model* m){
    int lenBefore = models.size();

    models.push_back(m);

    return (lenBefore != models.size());
}

bool ModelBody :: add(System* s){
    int lenBefore = systems.size();

    systems.push_back(s);

    return (lenBefore != systems.size());
}

bool ModelBody :: add(Flow* f){
    int lenBefore = flows.size();

    flows.push_back(f);

    return (lenBefore != flows.size());
}

bool ModelBody :: remove(System* s){
    for(Model::systemsIterator it = systemsBegin(); it < systemsEnd(); it++){
        if(*it == s){
            systems.erase(it);
            delete s;
            return true;
        }
    }

    return false;
}

bool ModelBody :: remove(Flow* f){
    for(Model::flowsIterator it = flowsBegin(); it < flowsEnd(); it++){
        if(*it == f){
            flows.erase(it);
            delete f;
            return true;
        }
    }

    return false;
}

void ModelBody :: eraseModel(Model::modelsIterator m){
    models.erase(m);
}

bool ModelBody :: run(int startTime, int finalTime){
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
        for(Model::flowsIterator itFlows = flowsBegin(); itFlows < flowsEnd(); itFlows++){
            (*itResults) = (*itFlows)->executeEquation();
            itResults++;
        }

        itResults = results.begin();

        for(Model::flowsIterator itFlows = flowsBegin(); itFlows < flowsEnd(); itFlows++){            
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

void ModelBody :: reportStatus(){
    cout << "\nCurrent Model Status:" << endl;

    for(Model::systemsIterator it = systemsBegin(); it < systemsEnd(); it++)
        cout << (*it)->getName() << ": " << (*it)->getValue() << endl;
}

void ModelBody :: setName(const string& name){
    this->name = name;
}

string ModelBody :: getName() const{
    return name;
}

void ModelBody :: setClock(const int& clock){
    this->clock = clock;
}

int ModelBody :: getClock() const{
    return clock;
}

ModelBody& ModelBody:: operator= (const ModelBody& m){
    if(this == &m) return *this;

    this->name = m.name;

    systems.clear();
    systems.insert(systemsBegin(), m.systems.begin(), m.systems.end());
    
    flows.clear();
    flows.insert(flowsBegin(), m.flows.begin(), m.flows.end());
    
    return *this;
}

Model::systemsIterator ModelBody :: systemsBegin(){
    return systems.begin();
}

Model::systemsIterator ModelBody :: systemsEnd(){
    return systems.end();
}

Model::flowsIterator ModelBody :: flowsBegin(){
    return flows.begin();
}

Model::flowsIterator ModelBody :: flowsEnd(){
    return flows.end();
}

Model::modelsIterator ModelBody :: modelsBegin(){
    return models.begin();
}

Model::modelsIterator ModelBody :: modelsEnd(){
    return models.end();
}

//ModelHandle
ModelHandle :: ModelHandle(const string& name, const int& clock){
    pImpl_->setName(name);
    pImpl_->setClock(clock);
}

ModelHandle :: ~ModelHandle(){
    for(Model::modelsIterator it = modelsBegin(); it < modelsEnd(); it++){
        if(*it == this){
            pImpl_->eraseModel(it);
            break;
        }     
    }
}

System& ModelHandle :: createSystem(const string& name, const double& value){
    return pImpl_->createSystem(name, value);
}

bool ModelHandle :: add(System* s){
    return pImpl_->add(s);
}

bool ModelHandle :: add(Flow* f){
    return pImpl_->add(f);
}

bool ModelHandle :: remove(System* s){
    return pImpl_->remove(s);
}

bool ModelHandle :: remove(Flow* f){
    return pImpl_->remove(f);
}

bool ModelHandle :: run(int startTime, int finalTime){
    return pImpl_->run(startTime, finalTime);
}

void ModelHandle :: reportStatus(){
    pImpl_->reportStatus();
}

void ModelHandle :: setName(const string& name){
    pImpl_->setName(name);
}

string ModelHandle :: getName() const{
    return pImpl_->getName();
}

void ModelHandle :: setClock(const int& clock){
    pImpl_->setClock(clock);
}

int ModelHandle :: getClock() const{
    return pImpl_->getClock();
}

Model::systemsIterator ModelHandle :: systemsBegin(){
    return pImpl_->systemsBegin();
}

Model::systemsIterator ModelHandle :: systemsEnd(){
    return pImpl_->systemsEnd();
}

Model::flowsIterator ModelHandle :: flowsBegin(){
    return pImpl_->flowsBegin();
}

Model::flowsIterator ModelHandle :: flowsEnd(){
    return pImpl_->flowsEnd();
}

Model::modelsIterator ModelHandle :: modelsBegin(){
    return pImpl_->modelsBegin();
}

Model::modelsIterator ModelHandle :: modelsEnd(){
    return pImpl_->modelsEnd();
}