#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Display.h"

using namespace std;

class ProccessHandler {
public:

    static void mainProccess();

    static vector<int> generateRandomVector(int &size);

    ProccessHandler(void);

    ~ProccessHandler(void);

};

