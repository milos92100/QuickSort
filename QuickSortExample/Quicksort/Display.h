//
// Created by milos on 6.11.16..
//

#ifndef QUICKSORT_DISPLAY_H
#define QUICKSORT_DISPLAY_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

class Display {

public:
    Display(int width, int heigth, const string &title);

    ~Display();

    void Update();

    bool isClosed();


private:
    SDL_Window *m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed = false;

};


#endif //QUICKSORT_DISPLAY_H
