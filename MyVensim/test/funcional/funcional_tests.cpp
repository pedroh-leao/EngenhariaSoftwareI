#include "funcional_tests.h"
#include <assert.h>
#include <cmath>
#include "../../src/Model.h"
#include "MyFlows.h"

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif

void exponentialFuncionalTest(){
    Model &m = Model::createModel();
    System &pop1 = m.createSystem("Pop1", 100), &pop2 = m.createSystem("Pop2", 0);
    Flow &f1 = m.createFlow<Exponential>(&pop1, &pop2);

    m.run(0, 100);
    
    m.reportStatus();

    assert(round(fabs(pop1.getValue() * 10000 - 10000 * 36.6032)) < 1);
    assert(round(fabs(pop2.getValue() * 10000 - 10000 * 63.3968)) < 1);

    delete &m;
}

void logisticalFuncionalTest(){
    Model &m = Model::createModel();
    System &p1 = m.createSystem("P1", 100), &p2 = m.createSystem("P2", 10);
    Flow &f1 = m.createFlow<Logistic>(&p1, &p2);

    m.run(0, 100);

    m.reportStatus();

    assert(round(fabs(p1.getValue() * 10000 - 10000 * 88.2167)) < 1);
    assert(round(fabs(p2.getValue() * 10000 - 10000 * 21.7833)) < 1);

    delete &m;
}

void complexFuncionalTest(){
    Model &m = Model::createModel();

    System &q1 = m.createSystem("Q1", 100);
    System &q2 = m.createSystem("Q2", 0);
    System &q3 = m.createSystem("Q3", 100);
    System &q4 = m.createSystem("Q4", 0);
    System &q5 = m.createSystem("Q5", 0);

    Flow &f = m.createFlow<Complex>(&q1, &q2);
    Flow &g = m.createFlow<Complex>(&q1, &q3);
    Flow &r = m.createFlow<Complex>(&q2, &q5);
    Flow &t = m.createFlow<Complex>(&q2, &q3);
    Flow &u = m.createFlow<Complex>(&q3, &q4);
    Flow &v = m.createFlow<Complex>(&q4, &q1);

    m.run(0, 100);
    
    m.reportStatus();

    assert(round(fabs(q1.getValue() * 10000 - 31.8513 * 10000)) < 1);
    assert(round(fabs(q2.getValue() * 10000 - 18.4003 * 10000)) < 1);
    assert(round(fabs(q3.getValue() * 10000 - 77.1143 * 10000)) < 1);
    assert(round(fabs(q4.getValue() * 10000 - 56.1728 * 10000)) < 1);
    assert(round(fabs(q5.getValue() * 10000 - 16.4612 * 10000)) < 1);

    delete &m;
}