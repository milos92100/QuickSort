#include <iostream>
#include "ProccessHandler.h"
#include "Display.h"
#include <GL/glew.h>

using namespace std;

int main() {

    //ProccessHandler::mainProccess();

    Display display = Display(800, 600, "Test");

    while (!display.isClosed()) {
        glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        display.Update();
    }

    return 0;

}


