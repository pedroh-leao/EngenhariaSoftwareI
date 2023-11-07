#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Flow.h"
#include "System.h"

using namespace std;

class Model{
protected:
    string name;
    vector<System*> systems;
    vector<Flow*> flows;

private:
    //prohibiting the copying of models
    Model(const Model&); //constructor for copy
    Model& operator=(const Model&);
    
public:
    Model(const string& = "");
    
    virtual ~Model();

    bool add(System *);
    bool add(Flow*);

    bool remove(System*);
    bool remove(Flow*);

    bool run(int, int);

    void reportStatus();

    void setName(const string&);
    string getName() const;

    typedef vector<System*>::iterator systemsIterator;
    typedef vector<Flow *>::iterator flowsIterator;

    systemsIterator systemsBegin();
    systemsIterator systemsEnd();

    flowsIterator flowsBegin();
    flowsIterator flowsEnd();
};

#endif