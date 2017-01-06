//
// Created by milos on 6.11.16..
//

#include <iostream>
#include "Display.h"
#include <GL/glew.h>
#include <cmath>
#include <SDL2/SDL.h>


Display::Display(int width, int heigth, const string &title) {

    m_width = width;
    m_height = heigth;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height,
                                SDL_WINDOW_OPENGL);

    m_screen = SDL_GetWindowSurface(m_window);
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    m_glContext = SDL_GL_CreateContext(m_window);

    GLenum status = glewInit();

    if (status != GLEW_OK) {
        cerr << "Glew failed to initialize" << endl;
    }

    glClearColor(0, 0, 0, 255);
    glClear(GL_COLOR_BUFFER_BIT);

}

Display::~Display() {
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Display::isClosed() {
    return m_isClosed;
}


void Display::Clear(float r, float g, float b, float a) {
    //glClearColor(r, g, g, a);
    //glClear(GL_COLOR_BUFFER_BIT);
    SDL_Delay(10);
}


void Display::drawRect(SDL_Rect rect) {


}

void Display::drawSortedNumbers(vector<int> &numbers) {

    int count = numbers.size();

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer); // fill the scene with white
    SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255); // the rect color (solid red)

    for (int i = 0; i < count; i++) {

        SDL_Rect rect = createRect(numbers[i], i, count);

        SDL_RenderFillRect(m_renderer, &rect);

    }
    SDL_RenderPresent(m_renderer); // copy to screen

}

SDL_Rect Display::createRect(int value, int index, int count) {

    SDL_Rect rect;

    rect.x = (m_width / count) * (index);
    rect.y = abs(value - m_height);
    rect.h = value;
    rect.w = m_width / count;

    return rect;
}

void Display::init() {

    while (!isClosed()) {

        Clear(0.0f, 0.0f, 0.0f, 1.0f);


        Update();
    }
}

void Display::Update() {

    SDL_GL_SwapWindow(m_window);

    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            m_isClosed = true;
        }
    }
}