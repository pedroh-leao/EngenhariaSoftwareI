#include "unit_System.h"
#include "assert.h"
#include "cmath"
#include "../../src/SystemImpl.h"

void unit_System_constructor(){
    System *s = new SystemHandle();
    System *s1 = new SystemHandle("System 1");
    System *s2 = new SystemHandle("System 2", 10);

    assert(s->getName() == "");
    assert(round(fabs(s->getValue() * 10000 - 0 * 10000)) < 1);

    assert(s1->getName() == "System 1");
    assert(round(fabs(s1->getValue() * 10000 - 0 * 10000)) < 1);

    assert(s2->getName() == "System 2");
    assert(round(fabs(s2->getValue() * 10000 - 10 * 10000)) < 1);

    delete s;
    delete s1;
    delete s2;
}

void unit_System_copyConstructor(){
    System *s1 = new SystemHandle("System", 10);
    System *s2 = new SystemHandle(*s1);

    assert(s1->getName() == s2->getName());
    assert(round(fabs(s1->getValue() * 10000 - s2->getValue() * 10000)) < 1);

    delete s1;
    delete s2;
}

void unit_System_destructor(){}

void unit_System_setName(){
    System *s = new SystemHandle();

    s->setName("System");

    assert(s->getName() == "System");

    delete s;
}

void unit_System_getName(){
    System *s = new SystemHandle("System");

    assert(s->getName() == "System");

    delete s;
}

void unit_System_setValue(){
    System *s = new SystemHandle();

    s->setValue(10);

    assert(round(fabs(s->getValue() * 10000 - 10 * 10000)) < 1);

    delete s;
}

void unit_System_getValue(){
    System *s = new SystemHandle("System", 10);

    assert(round(fabs(s->getValue() * 10000 - 10 * 10000)) < 1);

    delete s;
}

void unit_System_equalsOperator(){
    System *s1 = new SystemHandle("System", 10);
    System *s2 = new SystemHandle();

    *s2 = *s1;

    assert(s1->getName() == s2->getName());
    assert(round(fabs(s1->getValue() * 10000 - s2->getValue() * 10000)) < 1);

    delete s1;
    delete s2;
}

void run_unit_tests_System(){
    unit_System_constructor();

    unit_System_copyConstructor();

    unit_System_destructor();

    unit_System_setName();

    unit_System_getName();

    unit_System_setValue();

    unit_System_getValue();

    unit_System_equalsOperator();
}