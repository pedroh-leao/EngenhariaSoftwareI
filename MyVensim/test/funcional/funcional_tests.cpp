#include "funcional_tests.h"

void exponentialFuncionalTest(){
    Model m;
    System pop1("Pop1", 100), pop2("Pop2", 0);
    Exponential f1(&pop1, &pop2);

    m.add(&pop1);
    m.add(&pop2);
    m.add(&f1);

    m.run(1, 100);
    
    m.reportStatus();

    assert(fabs(round(pop1.getValue() * 10000) - 10000 * 36.6032) < 0.0001);
    assert(fabs(round(pop2.getValue() * 10000) - 10000 * 63.3968) < 0.0001);
}

void logisticalFuncionalTest(){
    Model m;
    System p1("P1", 100), p2("P2", 10);
    Logistic f1(&p1, &p2);

    m.add(&p1);
    m.add(&p2);
    m.add(&f1);

    m.run(1, 100);

    m.reportStatus();

    assert(fabs(round(p1.getValue() * 10000) - 10000 * 88.2167) < 0.0001);
    assert(fabs(round(p2.getValue() * 10000) - 10000 * 21.7833) < 0.0001);
}

void complexFuncionalTest(){
    Model m;
    System q1("Q1", 100), q2("Q2", 0), q3("Q3", 100), q4("Q4", 0), q5("Q5", 0);
    MyFlow f(&q1, &q2), g(&q1, &q3), r(&q2, &q5), t(&q2, &q3), u(&q3, &q4), v(&q4, &q1);

    m.add(&q1);
    m.add(&q2);
    m.add(&q3);
    m.add(&q4);
    m.add(&q5);
    m.add(&f);
    m.add(&g);
    m.add(&r);
    m.add(&t);
    m.add(&u);
    m.add(&v);

    m.run(1, 100);
    
    m.reportStatus();

    assert(fabs(round(q1.getValue() * 10000) - 10000 * 31.8513) < 0.0001);
    assert(fabs(round(q2.getValue() * 10000) - 10000 * 18.4003) < 0.0001);
    assert(fabs(round(q3.getValue() * 10000) - 10000 * 77.1143) < 0.0001);
    assert(fabs(round(q4.getValue() * 10000) - 10000 * 56.1728) < 0.0001);
    assert(fabs(round(q5.getValue() * 10000) - 10000 * 16.4612) < 0.0001);
}