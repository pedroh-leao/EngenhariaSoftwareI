#include "unit_Model.h"
#include <assert.h>
#include <cmath>
#include <vector>
#include <iterator>
#include "../../src/Model.h"
#include "../funcional/MyFlows.h"

void unit_Model_constructor(){
    Model& m = Model::createModel();
    assert(m.getName() == "");
    assert(m.systemsBegin() == m.systemsEnd());
    assert(m.flowsBegin() == m.flowsEnd());
    
    Model &m1 = Model::createModel("Model 1");
    assert(m1.getName() == "Model 1");
    assert(m1.systemsBegin() == m1.systemsEnd());
    assert(m1.flowsBegin() == m1.flowsEnd());

    Model &m2 = Model::createModel("Model 2", 10);
    assert(m2.getName() == "Model 2");
    assert(m2.getClock() == 10);
    assert(m2.systemsBegin() == m2.systemsEnd());
    assert(m2.flowsBegin() == m2.flowsEnd());

    delete &m;
    delete &m1;
    delete &m2;
}

void unit_Model_destructor(){}

void unit_Model_createModel(){
    Model &m = Model::createModel();

    assert(m.modelsBegin() != m.modelsEnd());
    assert(*m.modelsBegin() == &m);
    
    delete &m;
}

void unit_Model_createSystem(){
    Model &m = Model::createModel();
    System &s = m.createSystem();

    assert(m.systemsBegin() != m.systemsEnd());
    assert(*m.systemsBegin() == &s);

    delete &m;
}

void unit_Model_createFlow(){
    Model &m = Model::createModel();
    Flow &f = m.createFlow<Logistic>();

    assert(m.flowsBegin() != m.flowsEnd());
    assert(*m.flowsBegin() == &f);

    delete &m;
}

void unit_Model_remove(){
    Model &m = Model::createModel();
    
    //removing a system
    System &s = m.createSystem();
    
    assert(m.remove(&s));
    assert(m.systemsBegin() == m.systemsEnd());

    //removing a flow
    Flow &f = m.createFlow<Exponential>();
    
    assert(m.remove(&f));
    assert(m.flowsBegin() == m.flowsEnd());

    delete &m;
}

void unit_Model_run(){
    Model &m = Model::createModel();
  
    m.run(0, 100);
    assert(m.getClock() == 100);

    delete &m;
}

void unit_Model_setName(){
    Model &m = Model::createModel();
    m.setName("Model 1");

    assert(m.getName() == "Model 1");

    delete &m;
}

void unit_Model_getName(){
    Model &m = Model::createModel("Model 1");

    assert(m.getName() == "Model 1");

    delete &m;
}

void unit_Model_setClock(){
    Model &m = Model::createModel();

    m.setClock(5);
    assert(m.getClock() == 5);

    delete &m;
}

void unit_Model_getClock(){
    Model &m = Model::createModel("Model 1", 5);

    assert(m.getClock() == 5);

    delete &m;
}

void unit_Model_systemsBegin(){
    Model &m = Model::createModel();
    System &s = m.createSystem();
    
    assert(*m.systemsBegin() == &s);

    delete &m;
}

void unit_Model_systemsEnd(){
    Model &m = Model::createModel();
    System &s = m.createSystem();
    System &s1 = m.createSystem();
    
    assert(*(m.systemsEnd()-1) == &s1);
    assert(*(m.systemsEnd()-2) == &s);

    delete &m;
}

void unit_Model_flowsBegin(){
    Model &m = Model::createModel();
    Flow &f = m.createFlow<Exponential>();

    assert(*m.flowsBegin() == &f);

    delete &m;
}

void unit_Model_flowsEnd(){
    Model &m = Model::createModel();
    Flow &f = m.createFlow<Exponential>();
    Flow &f1 = m.createFlow<Logistic>();
    
    assert(*(m.flowsEnd()-1) == &f1);
    assert(*(m.flowsEnd()-2) == &f);

    delete &m;
}

void unit_Model_modelsBegin(){
    Model &m = Model::createModel();

    assert(*m.modelsBegin() == &m);

    delete &m;
}

void unit_Model_modelsEnd(){
    Model &m = Model::createModel();
    Model &m1 = Model::createModel();
    
    assert(*(m.modelsEnd()-1) == &m1);
    assert(*(m.modelsEnd()-2) == &m);

    assert(*(m1.modelsEnd()-1) == &m1);
    assert(*(m1.modelsEnd()-2) == &m);

    delete &m;
    delete &m1;
}

void run_unit_tests_Model(){
    unit_Model_constructor();

    unit_Model_destructor();

    unit_Model_createModel();

    unit_Model_createSystem();

    unit_Model_createFlow();

    unit_Model_remove();

    unit_Model_run();

    unit_Model_setName();

    unit_Model_getName();

    unit_Model_systemsBegin();

    unit_Model_systemsEnd();

    unit_Model_flowsBegin();

    unit_Model_flowsEnd();

    unit_Model_modelsBegin();

    unit_Model_modelsEnd();
}