#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"
#include "unit_HandleBody.h"
#include <iostream>

using namespace std;

int main(){

        //run_unit_tests_globals();

        cout << "\nRunning handle/body unit tests." << endl;
        run_unit_test_HandleBody();

        cout << "\nRunning system unit tests." << endl;
        run_unit_tests_System();

        cout << "\nRunning flow unit tests." << endl;
        run_unit_tests_Flow();

        cout << "\nRunning model unit tests." << endl;
        run_unit_tests_Model();

        return 0;
}