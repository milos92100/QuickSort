#include "ProccessHandler.h"
#include "DisplayHandler.h"
#include "Settings.h"
#include "Display.h"

#include <thread>
#include "QuicksortClass.h"


using namespace std;

ProccessHandler::ProccessHandler(void) {
}


ProccessHandler::~ProccessHandler(void) {
}


void ProccessHandler::mainProccess() {

    int array_param = 0;
    int array_size = 0;
    int delay = 0;
    vector<int> my_vec;
    vector<int> def_vec;

    QuicksortClass quickSort = QuicksortClass();


    DisplayHandler::displayRequestInputType(array_param);

    if (array_param == Settings::CUSTOM_ARRAY) {


        DisplayHandler::displayRequestArraySize(array_size);

        DisplayHandler::displayRequestDelay(delay);

        my_vec = DisplayHandler::displayRequestArrayInput(array_size);


        quickSort.inputData(my_vec);

        quickSort.setArraySize(array_size);

        quickSort.setDelay(delay);

        const clock_t begin_time = clock();

        quickSort.sortData();

        float sort_time = float(clock() - begin_time) / CLOCKS_PER_SEC;

        DisplayHandler::displaySortTime(sort_time);

        DisplayHandler::displayOnSortFinish();


    }

    if (array_param == Settings::DEFAULT_ARRAY) {


        DisplayHandler::displayRequestArraySize(array_size);

        DisplayHandler::displayRequestDelay(delay);

        quickSort.inputData(generateRandomVector(array_size));

        quickSort.setArraySize(array_size);

        quickSort.setDelay(delay);

        const clock_t begin_time = clock();

        quickSort.sortData();

        float sort_time = float(clock() - begin_time) / CLOCKS_PER_SEC;

        DisplayHandler::displaySortTime(sort_time);

        DisplayHandler::displayOnSortFinish();


    }
}


vector<int> ProccessHandler::generateRandomVector(int &size) {

    vector<int> temp;


    for (int i = 0; i < size; i++) {

        int num = (rand() % 500);
        temp.push_back(num);
    }

    return temp;


}









