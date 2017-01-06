//
// Created by milos on 6.11.16..
//

#ifndef QUICKSORT_DISPLAY_H
#define QUICKSORT_DISPLAY_H

#include <string>
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class Display {

public:
    Display(int width, int heigth, const string &title);

    ~Display();

    void Clear(float r, float g, float b, float a);

    void drawRect(SDL_Rect rect);

    void drawSortedNumbers(vector<int> &numbers);

    void Update();

    void init();

    bool isClosed();


private:
    SDL_Window *m_window;
    SDL_GLContext m_glContext;
    SDL_Surface *m_screen;
    SDL_Renderer *m_renderer;
    bool m_isClosed = false;
    int m_width;
    int m_height;

    SDL_Rect createRect(int value, int index, int count);

};


#endif //QUICKSORT_DISPLAY_H
