#include "QuicksortClass.h"
#include "ProccessHandler.h"
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

    Display display = Display(800, 600, "Quick Sort Algorithm Example");

    for (int i = 0; i < m_sortResult.size(); i++) {
        display.Clear(0, 0, 0, 0);
        display.drawSortedNumbers(m_sortResult[i]);
        display.Update();
        sleep(delay / 1000);
    }

    while (!display.isClosed()) {

        display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
        display.Update();

    }
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
            // m_sortResult.push_back(input);

            input[r] = tmp;
            m_sortResult.push_back(input);

        }
    }


    return r;
}

void QuicksortClass::quicksort(vector<int> &input, int p, int r) {

    if (p < r) {
        int j = partition(input, p, r);
        quicksort(input, p, j - 1);

        quicksort(input, j + 1, r);
    }
}

void QuicksortClass::print(vector<int> input) {

    for (int i = 0; i < size; i++)

        cout << input.at(i) << " ";
    cout << endl;
}






