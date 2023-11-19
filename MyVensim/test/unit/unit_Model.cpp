#include "unit_Model.h"

void unit_Model_constructor(){
    Model* m = new ModelImpl();
    assert(m->getName() == "");
    assert(m->systemsBegin() == m->systemsEnd());
    assert(m->flowsBegin() == m->flowsEnd());
    
    Model *m1 = new ModelImpl("Model 1");
    assert(m1->getName() == "Model 1");
    assert(m1->systemsBegin() == m1->systemsEnd());
    assert(m1->flowsBegin() == m1->flowsEnd());

    delete m;
    delete m1;
}

void unit_Model_destructor(){}

void unit_Model_add(){
    Model *m = new ModelImpl();
    
    //adding a system
    System *s = new SystemImpl();
    assert(m->add(s));
    assert(m->systemsBegin() != m->systemsEnd());

    //adding a flow
    Flow *f = new Exponential();
    assert(m->add(f));
    assert(m->flowsBegin() != m->flowsEnd());

    delete m;
    delete s;
    delete f;
}

void unit_Model_remove(){
    Model *m = new ModelImpl();
    
    //removing a system
    System *s = new SystemImpl();
    m->add(s);
    assert(m->remove(s));
    assert(m->systemsBegin() == m->systemsEnd());

    //removing a flow
    Flow *f = new Exponential();
    m->add(f);
    assert(m->remove(f));
    assert(m->flowsBegin() == m->flowsEnd());

    delete m;
    delete s;
    delete f;
}

void unit_Model_run(){
    Model *m = new ModelImpl();
    System *s1 = new SystemImpl("s1", 10);
    System *s2 = new SystemImpl("s2", 20);
    Flow *f = new Exponential(s1, s2);

    m->add(s1);
    m->add(s2);
    m->add(f);

    //! to do
    assert(m->run(0, 100));

    delete m;
    delete s1;
    delete s2;
    delete f;
}

void unit_Model_setName(){
    Model *m = new ModelImpl();
    m->setName("Model 1");

    assert(m->getName() == "Model 1");

    delete m;
}

void unit_Model_getName(){
    Model *m = new ModelImpl("Model 1");

    assert(m->getName() == "Model 1");

    delete m;
}

void unit_Model_systemsBegin(){
    Model *m = new ModelImpl();
    System *s = new SystemImpl();
    
    m->add(s);

    assert(*m->systemsBegin() == s);

    delete m;
    delete s;
}

void unit_Model_systemsEnd(){
    Model *m = new ModelImpl();
    System *s = new SystemImpl();
    System *s1 = new SystemImpl();
    
    m->add(s);
    m->add(s1);
    
    assert(*(m->systemsEnd()-1) == s1);
    assert(*(m->systemsEnd()-2) == s);

    delete m;
    delete s;
    delete s1;
}

void unit_Model_flowsBegin(){
    Model *m = new ModelImpl();
    Flow *f = new Exponential();
    
    m->add(f);

    assert(*m->flowsBegin() == f);

    delete m;
    delete f;
}

void unit_Model_flowsEnd(){
    Model *m = new ModelImpl();
    Flow *f = new Exponential();
    Flow *f1 = new Logistic();
    
    m->add(f);
    m->add(f1);

    assert(*(m->flowsEnd()-1) == f1);
    assert(*(m->flowsEnd()-2) == f);

    delete m;
    delete f;
    delete f1;
}

void run_unit_tests_Model(){
    unit_Model_constructor();

    unit_Model_destructor();

    unit_Model_add();

    unit_Model_remove();

    unit_Model_run();

    unit_Model_setName();

    unit_Model_getName();

    unit_Model_systemsBegin();

    unit_Model_systemsEnd();

    unit_Model_flowsBegin();

    unit_Model_flowsEnd();
}