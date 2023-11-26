#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/**
 * @brief Unit test for Model constructor
 */
void unit_Model_constructor();

/**
 * @brief Unit test for Model destructor
 */
void unit_Model_destructor();

/**
 * @brief Unit test for Model createModel function
*/
void unit_Model_createModel();

/**
 * @brief Unit test for Model createSystem function
*/
void unit_Model_createSystem();

/**
 * @brief Unit test for Model createFlow function
*/
void unit_Model_createFlow();

/**
 * @brief Unit test for Model remove functions
 */
void unit_Model_remove();

/**
 * @brief Unit test for Model run function
 */
void unit_Model_run();

/**
 * @brief Unit test for Model setName function
 */
void unit_Model_setName();

/**
 * @brief Unit test for Model getName function
 */
void unit_Model_getName();

/**
 * @brief Unit test for Model setClock function
 */
void unit_Model_setClock();

/**
 * @brief Unit test for Model getClock function
 */
void unit_Model_getClock();

/**
 * @brief Unit test for Model systemsBegin function
 */
void unit_Model_systemsBegin();

/**
 * @brief Unit test for Model systemsEnd function
 */
void unit_Model_systemsEnd();

/**
 * @brief Unit test for Model flowsBegin function
 */
void unit_Model_flowsBegin();

/**
 * @brief Unit test for Model flowsEnd function
 */
void unit_Model_flowsEnd();

/**
 * @brief Unit test for Model modelsBegin function
 */
void unit_Model_modelsBegin();

/**
 * @brief Unit test for Model modelsEnd function
 */
void unit_Model_modelsEnd();

/**
 * @brief Call all the unit tests
*/
void run_unit_tests_Model();

#endif