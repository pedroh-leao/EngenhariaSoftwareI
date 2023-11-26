#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/**
 * @brief Unit test for System constructor
 */
void unit_System_constructor();

/**
 * @brief Unit test for System copy constructor
 */
void unit_System_copyConstructor();

/**
 * @brief Unit test for System destructor
 */
void unit_System_destructor();

/**
 * @brief Unit test for System setName function
 */
void unit_System_setName();

/**
 * @brief Unit test for System getName function
 */
void unit_System_getName();

/**
 * @brief Unit test for System setValue function
 */
void unit_System_setValue();

/**
 * @brief Unit test for System getValue function
 */
void unit_System_getValue();

/**
 * @brief Unit test for System '=' operator
 */
void unit_System_equalsOperator();

/**
 * @brief Call all the unit tests
*/
void run_unit_tests_System();

#endif