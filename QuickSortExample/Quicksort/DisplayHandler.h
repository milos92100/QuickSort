#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Display.h"

using namespace std;

class DisplayHandler {


public:

    static void displayRequestInputType(int &param);

    static vector<int> displayRequestArrayInput(int size);

    static void displayRequestArraySize(int &size);

    static void displayOnSortFinish();

    static void displaySortTime(float time);

    static void displayRequestDelay(int &delay);

    static void wrongInput();

    static void wrongAnswer();

    static void maxSize();

    static void displayElements(vector<int> vec);

    static bool isInputOK(string &s);

    static void clearScreen();


    DisplayHandler(void);

    ~DisplayHandler(void);
};

