#include "unit_Flow.h"
#include "assert.h"
#include "cmath"
#include "../../src/FlowImpl.h"
#include "../../src/SystemImpl.h"
#include "../funcional/MyFlows.h"

void unit_Flow_constructor(){
    Flow *flowExp = new FlowHandle<Exponential>();

    assert(flowExp->getSource() == NULL);
    assert(flowExp->getTarget() == NULL);

    Flow *flowLog = new FlowHandle<Logistic>();

    assert(flowLog->getSource() == NULL);
    assert(flowLog->getTarget() == NULL);

    Flow *flowComplex = new FlowHandle<Complex>();

    assert(flowComplex->getSource() == NULL);
    assert(flowComplex->getTarget() == NULL);

    delete flowExp;
    delete flowLog;
    delete flowComplex;
}

void unit_Flow_constructorWithSystems(){
    System *s1 = new SystemHandle();
    System *s2 = new SystemHandle();

    Flow *flowExp = new FlowHandle<Exponential>(s1, s2);

    assert(flowExp->getSource() == s1);
    assert(flowExp->getTarget() == s2);

    Flow *flowLog = new FlowHandle<Logistic>(s1, s2);

    assert(flowLog->getSource() == s1);
    assert(flowLog->getTarget() == s2);

    Flow *flowComplex = new FlowHandle<Complex>(s1, s2);

    assert(flowComplex->getSource() == s1);
    assert(flowComplex->getTarget() == s2);

    delete flowExp;
    delete flowLog;
    delete flowComplex;
    delete s1;
    delete s2;
}

void unit_Flow_copyConstructor(){
    System *s1 = new SystemHandle();
    System *s2 = new SystemHandle();

    Flow *flowExp1 = new FlowHandle<Exponential>(s1, s2);
    Flow *flowExp2 = new FlowHandle<Exponential>(*flowExp1);

    assert(flowExp2->getSource() == s1);
    assert(flowExp2->getTarget() == s2);

    Flow *flowLog1 = new FlowHandle<Logistic>(s1, s2);
    Flow *flowLog2 = new FlowHandle<Logistic>(*flowLog1);

    assert(flowLog2->getSource() == s1);
    assert(flowLog2->getTarget() == s2);

    Flow *flowComplex1 = new FlowHandle<Complex>(s1, s2);
    Flow *flowComplex2 = new FlowHandle<Complex>(*flowComplex1);

    assert(flowComplex2->getSource() == s1);
    assert(flowComplex2->getTarget() == s2);

    delete flowExp1;
    delete flowExp2;
    delete flowLog1;
    delete flowLog2;
    delete flowComplex1;
    delete flowComplex2;
    delete s1;
    delete s2;
}

void unit_Flow_destructor(){}

void unit_Flow_setSource(){
    System *s1 = new SystemHandle();

    Flow *flowExp = new FlowHandle<Exponential>();
    flowExp->setSource(s1);
    assert(flowExp->getSource() == s1);

    Flow *flowLog = new FlowHandle<Logistic>();
    flowLog->setSource(s1);
    assert(flowLog->getSource() == s1);

    Flow *flowComplex = new FlowHandle<Complex>();
    flowComplex->setSource(s1);
    assert(flowComplex->getSource() == s1);

    delete flowExp;
    delete flowLog;
    delete flowComplex;
    delete s1;
}

void unit_Flow_getSource(){
    System *s1 = new SystemHandle();
    System *s2 = new SystemHandle();

    Flow *flowExp = new FlowHandle<Exponential>(s1, s2);
    assert(flowExp->getSource() == s1);

    Flow *flowLog = new FlowHandle<Logistic>(s1, s2);
    assert(flowLog->getSource() == s1);

    Flow *flowComplex = new FlowHandle<Complex>(s1, s2);
    assert(flowComplex->getSource() == s1);

    delete flowExp;
    delete flowLog;
    delete flowComplex;
    delete s1;
    delete s2;
}

void unit_Flow_setTarget(){
    System *s1 = new SystemHandle();

    Flow *flowExp = new FlowHandle<Exponential>();
    flowExp->setTarget(s1);
    assert(flowExp->getTarget() == s1);

    Flow *flowLog = new FlowHandle<Logistic>();
    flowLog->setTarget(s1);
    assert(flowLog->getTarget() == s1);

    Flow *flowComplex = new FlowHandle<Complex>();
    flowComplex->setTarget(s1);
    assert(flowComplex->getTarget() == s1);

    delete flowExp;
    delete flowLog;
    delete flowComplex;
    delete s1;
}

void unit_Flow_getTarget(){
    System *s1 = new SystemHandle();
    System *s2 = new SystemHandle();

    Flow *flowExp = new FlowHandle<Exponential>(s1, s2);
    assert(flowExp->getTarget() == s2);

    Flow *flowLog = new FlowHandle<Logistic>(s1, s2);
    assert(flowLog->getTarget() == s2);

    Flow *flowComplex = new FlowHandle<Complex>(s1, s2);
    assert(flowComplex->getTarget() == s2);

    delete flowExp;
    delete flowLog;
    delete flowComplex;
    delete s1;
    delete s2;
}

void unit_Flow_executeEquation(){
    System *s1 = new SystemHandle("s1", 10);
    System *s2 = new SystemHandle("s2", 20);

    Flow *flowExp = new FlowHandle<Exponential>(s1, s2);
    assert(round(fabs(flowExp->executeEquation() * 10000 - 0.1 * 10000)) < 1);

    Flow *flowLog = new FlowHandle<Logistic>(s1, s2);
    assert(round(fabs(flowLog->executeEquation() * 10000 - 0.1429 * 10000)) < 1);

    Flow *flowComplex = new FlowHandle<Complex>(s1, s2);
    assert(round(fabs(flowComplex->executeEquation() * 10000 - 0.1 * 10000)) < 1);

    delete flowExp;
    delete flowLog;
    delete flowComplex;
    delete s1;
    delete s2;
}

void unit_Flow_equalsOperator(){
    System *s1 = new SystemHandle();
    System *s2 = new SystemHandle();

    Flow *flowExp1 = new FlowHandle<Exponential>(s1, s2);
    Flow *flowExp2 = new FlowHandle<Exponential>();
    *flowExp2 = *flowExp1;

    assert(flowExp2->getSource() == s1);
    assert(flowExp2->getTarget() == s2);
    
    Flow *flowLog1 = new FlowHandle<Logistic>(s1, s2);
    Flow *flowLog2 = new FlowHandle<Logistic>();
    *flowLog2 = *flowLog1;

    assert(flowLog2->getSource() == s1);
    assert(flowLog2->getTarget() == s2);

    Flow *flowComplex1 = new FlowHandle<Complex>(s1, s2);
    Flow *flowComplex2 = new FlowHandle<Complex>();
    *flowComplex2 = *flowComplex1;

    assert(flowComplex2->getSource() == s1);
    assert(flowComplex2->getTarget() == s2);

    delete flowExp1;
    delete flowExp2;
    delete flowLog1;
    delete flowLog2;
    delete flowComplex1;
    delete flowComplex2;
    delete s1;
    delete s2;
}

void run_unit_tests_Flow(){
    unit_Flow_constructor();

    unit_Flow_constructorWithSystems();

    unit_Flow_copyConstructor();

    unit_Flow_destructor();

    unit_Flow_setSource();

    unit_Flow_getSource();

    unit_Flow_setTarget();

    unit_Flow_getTarget();

    unit_Flow_executeEquation();
    
    unit_Flow_equalsOperator();
}