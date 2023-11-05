#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Flow.h"
#include "System.h"

using namespace std;

class Model{
    string name;
    vector<System*> systems;
    vector<Flow*> flows;
    
public:
    Model(const string& = "");
    Model(const Model&); //constructor for copy
    virtual ~Model();

    bool add(System *);
    bool add(Flow*);

    bool remove(System*);
    bool remove(Flow*);

    bool run(int, int);

    void reportStatus();

    void setName(const string&);
    string getName() const;

    Model& operator=(const Model&);

    typedef vector<System*>::iterator systemsIterator;
    typedef vector<Flow *>::iterator flowsIterator;

    systemsIterator systemsBegin();
    systemsIterator systemsEnd();

    flowsIterator flowsBegin();
    flowsIterator flowsEnd();
};

#endif