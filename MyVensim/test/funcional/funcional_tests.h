#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <cmath>
#include "../../src/Model.h"
#include "MyFlows.h"

/**
 * @brief Performs the exponencial funcional test of a model with 2 systems and 1 flow
*/
void exponentialFuncionalTest();

/**
 * @brief Performs the logistical funcional test of a model with 2 systems and 1 flow
*/
void logisticalFuncionalTest();

/**
 * @brief Performs the complex funcional test of a model with 5 systems and 6 flows
*/
void complexFuncionalTest();

#endif