#include "QuicksortClass.h"
#include <thread>
#include <unistd.h>

using namespace std;

QuicksortClass::QuicksortClass(void) {
}

QuicksortClass::~QuicksortClass(void) {
}

void QuicksortClass::inputData(vector<int> vec) {

    data = vec;
}

void QuicksortClass::setArraySize(int s) {
    size = s;
}

void QuicksortClass::setDelay(int d) {
    delay = d;
}

void QuicksortClass::sortData() {

    cout << "Sort started . . .";
    //Sleep(1000);windows
    sleep(1);
    cout << "Unos: ";
    print(data);
    quicksort(data, 0, size - 1);
    cout << "Sortiran niz: ";
    print(data);
}


long QuicksortClass::partition(vector<int> &input, int p, int r) {

    int pivot = input[r];

    while (p < r) {
        while (input[p] < pivot)
            p++;

        while (input[r] > pivot)
            r--;

        if (input[p] == input[r])
            p++;
        else if (p < r) {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;

        }
    }


    return r;
}

void QuicksortClass::quicksort(vector<int> &input, int p, int r) {
    if (p < r) {
        // Sleep(delay);windows
        sleep(delay / 1000);
        //print(input);
        int j = partition(input, p, r);
        quicksort(input, p, j - 1);

        print(input);

        quicksort(input, j + 1, r);

        //  Sleep(delay);windows
        sleep(delay / 1000);
        print(input);

    }
}

void QuicksortClass::print(vector<int> input) {
    for (int i = 0; i < size; i++)
        cout << input.at(i) << " ";
    cout << endl;
}




