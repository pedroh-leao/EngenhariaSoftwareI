#include "Model.h"

Model :: Model(const string& name){
    this->name = name;
}

Model :: Model(const Model& m){
    this->name = m.name;
    systems.insert(systemsBegin(), m.systems.begin(), m.systems.end());
    flows.insert(flowsBegin(), m.flows.begin(), m.flows.end());
}

Model :: ~Model(){}

bool Model :: add(System* s){
    int lenBefore = systems.size();

    systems.push_back(s);

    if(lenBefore == systems.size()) return false;

    return true;
}

bool Model :: add(Flow* f){
    int lenBefore = flows.size();

    flows.push_back(f);

    if(lenBefore == flows.size()) return false;

    return true;
}

bool Model :: remove(System* s){
    for(systemsIterator it = systemsBegin(); it < systemsEnd(); it++){
        if(*it == s){
            systems.erase(it);
            return true;
        }
    }

    return false;
}

bool Model :: remove(Flow* f){
    for(flowsIterator it = flowsBegin(); it < flowsEnd(); it++){
        if(*it == f){
            flows.erase(it);
            return true;
        }
    }

    return false;
}

bool Model :: run(int startTime, int finalTime){
    if(startTime > finalTime || startTime < 0) return false;

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
    }

    return true;
}

void Model :: reportStatus(){
    cout << "\nCurrent Model Status:" << endl;

    for(systemsIterator it = systemsBegin(); it < systemsEnd(); it++)
        cout << (*it)->getName() << ": " << (*it)->getValue() << endl;
}

void Model :: setName(const string& name){
    this->name = name;
}

string Model :: getName() const{
    return name;
}

Model& Model:: operator= (const Model& m){
    if(this == &m) return *this;

    this->name = m.name;

    systems.clear();
    systems.insert(systemsBegin(), m.systems.begin(), m.systems.end());
    
    flows.clear();
    flows.insert(flowsBegin(), m.flows.begin(), m.flows.end());
    
    return *this;
}

Model::systemsIterator Model :: systemsBegin(){
    return systems.begin();
}

Model::systemsIterator Model :: systemsEnd(){
    return systems.end();
}

Model::flowsIterator Model :: flowsBegin(){
    return flows.begin();
}

Model::flowsIterator Model :: flowsEnd(){
    return flows.end();
}