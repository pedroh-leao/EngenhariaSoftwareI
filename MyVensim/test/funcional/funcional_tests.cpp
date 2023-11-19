#include "funcional_tests.h"

void exponentialFuncionalTest(){
    Model *m = new ModelImpl();
    System *pop1 = new SystemImpl("Pop1", 100), *pop2 = new SystemImpl("Pop2", 0);
    Flow *f1 = new Exponential(pop1, pop2);

    m->add(pop1);
    m->add(pop2);
    m->add(f1);

    m->run(0, 100);
    
    m->reportStatus();

    assert(round(fabs(pop1->getValue() * 10000 - 10000 * 36.6032)) < 1);
    assert(round(fabs(pop2->getValue() * 10000 - 10000 * 63.3968)) < 1);

    delete m;
    delete pop1;
    delete pop2;
    delete f1;
}

void logisticalFuncionalTest(){
    Model *m = new ModelImpl();
    System *p1 = new SystemImpl("P1", 100), *p2 = new SystemImpl("P2", 10);
    Flow *f1 = new Logistic(p1, p2);

    m->add(p1);
    m->add(p2);
    m->add(f1);

    m->run(0, 100);

    m->reportStatus();

    assert(round(fabs(p1->getValue() * 10000 - 10000 * 88.2167)) < 1);
    assert(round(fabs(p2->getValue() * 10000 - 10000 * 21.7833)) < 1);

    delete m;
    delete p1;
    delete p2;
    delete f1;
}

void complexFuncionalTest(){
    Model *m = new ModelImpl();

    System *q1 = new SystemImpl("Q1", 100);
    System *q2 = new SystemImpl("Q2", 0);
    System *q3 = new SystemImpl("Q3", 100);
    System *q4 = new SystemImpl("Q4", 0);
    System *q5 = new SystemImpl("Q5", 0);

    Flow *f = new Complex(q1, q2);
    Flow *g = new Complex(q1, q3);
    Flow *r = new Complex(q2, q5);
    Flow *t = new Complex(q2, q3);
    Flow *u = new Complex(q3, q4);
    Flow *v = new Complex(q4, q1);

    m->add(q1);
    m->add(q2);
    m->add(q3);
    m->add(q4);
    m->add(q5);
    m->add(f);
    m->add(g);
    m->add(r);
    m->add(t);
    m->add(u);
    m->add(v);

    m->run(0, 100);
    
    m->reportStatus();

    assert(round(fabs(q1->getValue() * 10000 - 31.8513 * 10000)) < 1);
    assert(round(fabs(q2->getValue() * 10000 - 18.4003 * 10000)) < 1);
    assert(round(fabs(q3->getValue() * 10000 - 77.1143 * 10000)) < 1);
    assert(round(fabs(q4->getValue() * 10000 - 56.1728 * 10000)) < 1);
    assert(round(fabs(q5->getValue() * 10000 - 16.4612 * 10000)) < 1);

    delete m;
    delete q1;
    delete q2;
    delete q3;
    delete q4;
    delete q5;
    delete f;
    delete t;
    delete u;
    delete v;
    delete g;
    delete r;
}