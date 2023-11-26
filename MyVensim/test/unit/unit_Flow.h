#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/**
 * @brief Unit test for Flow default constructor
 */
void unit_Flow_constructor();

/**
 * @brief Unit test for Flow constructor with pointers to source and target systems
 */
void unit_Flow_constructorWithSystems();

/**
 * @brief Unit test for Flow copy constructor
 */
void unit_Flow_copyConstructor();

/**
 * @brief Unit test for Flow destructor
 */
void unit_Flow_destructor();

/**
 * @brief Unit test for Flow setSource function
 */
void unit_Flow_setSource();

/**
 * @brief Unit test for Flow getSource function
 */
void unit_Flow_getSource();

/**
 * @brief Unit test for Flow setTarget function
 */
void unit_Flow_setTarget();

/**
 * @brief Unit test for Flow getTarget function
 */
void unit_Flow_getTarget();

/**
 * @brief Unit test for Flow executeEquation function
 */
void unit_Flow_executeEquation();

/**
 * @brief Unit test for Flow '=' operator
 */
void unit_Flow_equalsOperator();

/**
 * @brief Call all the unit tests
*/
void run_unit_tests_Flow();

#endif