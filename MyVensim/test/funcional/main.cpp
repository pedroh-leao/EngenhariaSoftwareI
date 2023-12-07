#include "funcional_tests.h"
#include <iostream>

using namespace std;

int main(){

    cout << "\nRunning Funcional Test." << endl;
    exponentialFuncionalTest();

    cout << "\nRunning Logistical Test." << endl;
    logisticalFuncionalTest();

    cout << "\nRunning Complex Test." << endl;
    complexFuncionalTest();

    return 0;
}