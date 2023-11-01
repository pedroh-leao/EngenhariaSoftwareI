#include "Model.h"

Model :: Model(){}

Model :: Model(const Model& m){
    this->name = m.getName();
    this->systems.insert(this->systems.begin(), m.systems.begin(), m.systems.end());
    this->flows.insert(this->flows.begin(), m.flows.begin(), m.flows.end());
}

Model :: ~Model(){}

bool Model :: add(System* s){
    //!conferir como fazer a verificacao para retornar true or false
    systems.push_back(s);
    return true;
}

bool Model :: add(Flow* f){
    //!conferir como fazer a verificacao para retornar true or false
    flows.push_back(f);
    return true;
}

bool Model :: remove(System* s){
    for(systemsIterator it = systems.begin(); it < systems.end(); it++){
        if(*it == s){
            systems.erase(it);
            return true;
        }
    }

    return false;
}

bool Model :: remove(Flow* f){
    for(flowsIterator it = flows.begin(); it < flows.end(); it++){
        if(*it == f){
            flows.erase(it);
            return true;
        }
    }

    return false;
}

bool Model :: run(int tempoInicial, int tempoFinal){
    //!conferir como fazer a verificacao para retornar true or false
    System *source, *target;

    vector<double> results;
    vector<double>::iterator itResults;

    int len = flows.size();
    for(int i = 0; i < len; i++)
        results.push_back(0.0);
    
    for(int i = tempoInicial; i <= tempoFinal; i++){
        itResults = results.begin();

        //execute the equations of the flows
        for(flowsIterator itFlows = flows.begin(); itFlows < flows.end(); itFlows++){
            (*itResults) = (*itFlows)->executeEquation();
            itResults++;
        }

        itResults = results.begin();

        for(flowsIterator itFlows = flows.begin(); itFlows < flows.end(); itFlows++){            
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
    cout << "\nEstado Atual do Modelo:\n" << endl;

    for(systemsIterator it = systems.begin(); it < systems.end(); it++)
        cout << (*it)->getName() << ": " << (*it)->getValue() << endl;
}

void Model :: setName(string name){
    this->name = name;
}

string Model :: getName() const{
    return this->name;
}

Model& Model:: operator= (const Model& m){
    if(this == &m) return *this;

    this->name = m.name;

    this->systems.clear();
    this->systems.insert(this->systems.begin(), m.systems.begin(), m.systems.end());
    
    this->flows.clear();
    this->flows.insert(this->flows.begin(), m.flows.begin(), m.flows.end());
    
    return *this;
}