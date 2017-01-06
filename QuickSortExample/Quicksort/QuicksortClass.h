#pragma once

#include <iostream>
#include <vector>
#include "Display.h"


using namespace std;

int const temp_size = 10;


class QuicksortClass {

private:
    vector<int> data;
    int size;
    int delay;

    vector<vector<int>> m_sortResult;

public:

    QuicksortClass(void);

    ~QuicksortClass(void);

    void inputData(vector<int> arr);

    void setArraySize(int s);

    void setDelay(int d);

    void sortData();

    long partition(vector<int> &input, int p, int r);

    void quicksort(vector<int> &input, int p, int r);

    void print(vector<int> input);


};

