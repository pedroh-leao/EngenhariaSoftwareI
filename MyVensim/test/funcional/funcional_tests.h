#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <cmath>
#include "../../src/ModelImpl.h"
#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"
#include "MyFlows.h"

/**
 * @brief Given a model with 2 systems with value 100 and 0, and 1 flow that performs an exponencial equation
 *        When the model runs, the equation is executed from time 0 to 100 and the system values are updated
 *        Then checks if the system 1 value is 36.6032 and system 2 value is 63.3968
*/
void exponentialFuncionalTest();

/**
 * @brief Given a model with 2 systems with value 100 and 10, and 1 flow that performs a logistical equation
 *        When the model runs, the equation is executed from time 0 to 100 and the system values are updated
 *        Then checks if the system 1 value is 88.2167 and system 2 value is 21.7833
*/
void logisticalFuncionalTest();

/**
 * @brief Given a model with 5 systems, q1, q2, q3, q4 and q5, with value 100, 0, 100, 0, 0, and 6 flows,
 *        connecting q1-q2, q1-q3, q2-q5, q2-q3, q4-q1, that perform a complex equation
 *        When the model runs, the equations flows are executed from time 0 to 100 and the system values are updated
 *        Then checks if q1 value is 31.8513, q2 value is 18.4003, q3 value is 77.1143, q4 value is 56.1728 and q5 value is 16.4612
*/
void complexFuncionalTest();

#endif