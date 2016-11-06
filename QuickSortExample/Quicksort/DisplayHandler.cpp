#include "DisplayHandler.h"
#include "ProccessHandler.h"
#include "Settings.h"
#include <thread>
#include <unistd.h>

using namespace std;

DisplayHandler::DisplayHandler(void) {
}


DisplayHandler::~DisplayHandler(void) {
}


/*

Displays the screen for requesting the input type.
The user can input a new array or use an existing.

*/
void DisplayHandler::displayRequestInputType(int &param) {

    string temp = "0";

    DisplayHandler::clearScreen();

    cout << "------------------------------------------------" << endl;
    cout << "| " << Settings::CUSTOM_ARRAY << " Uneti novi niz     " << Settings::DEFAULT_ARRAY <<
         " Koristi postojeci niz |" << endl;
    cout << "------------------------------------------------ " << endl;
    cout << "Uneti odgovor : ";
    cin >> temp;

    if (isInputOK(temp)) {

        switch (stoi(temp)) {

            case Settings::CUSTOM_ARRAY :
                param = Settings::CUSTOM_ARRAY;
                break;


            case Settings::DEFAULT_ARRAY:
                param = Settings::DEFAULT_ARRAY;
                break;


            default:
                wrongAnswer();
                displayRequestInputType(param);
                break;
        }

    } else {

        wrongInput();
        displayRequestInputType(param);

    }

}


/*
Displays the request for the vector input.

*/
vector<int> DisplayHandler::displayRequestArrayInput(int size) {

    string element;
    vector<int> vec;

    DisplayHandler::clearScreen();

    cout << "----------------------------------------------" << endl;
    cout << "| Unesite brojeve koje zelite da sortirate    |" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < size; i++) {

        cout << "Unesite element : ";
        cin >> element;

        while (!isInputOK(element)) {
            wrongInput();
            displayElements(vec);
            cout << "Unesite element : ";
            cin >> element;
        }

        vec.push_back(stoi(element));
        displayElements(vec);

    }


    return vec;

}

void DisplayHandler::displayRequestArraySize(int &size) {

    string str_s = "0";

    DisplayHandler::clearScreen();

    cout << "-----------------------------------------------" << endl;
    cout << "|           Unesite broj elementata           |" << endl;
    cout << "-----------------------------------------------" << endl;
    cin >> str_s;

    if (isInputOK(str_s)) {

        if (stoi(str_s) < Settings::MAX_ELEMENTS) {

            size = stoi(str_s);

            DisplayHandler::clearScreen();

            cout << "------------------------------------------------" << endl;
            cout << "| Broj usepsno unesen elementata (" << size << ")|" << endl;
            cout << "------------------------------------------------" << endl;
            //Sleep(2000);windows
            sleep(2);
        } else {
            maxSize();
            displayRequestArraySize(size);

        }

    } else {
        wrongInput();
        displayRequestArraySize(size);
    }

}

//Shows the form for the delay input request
void DisplayHandler::displayRequestDelay(int &delay) {

    string str_command = "0";


    DisplayHandler::clearScreen();

    cout << "-----------------------------------------------" << endl;
    cout << "|           Izaberite kašnjenje   :            |" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << " " << Settings::NO_DELAY << ".    Bez kasnjenja    ( 0  sekundi)" << endl;
    cout << " " << Settings::MEDIUM_DELAY << ".    Srednje kasnjenje    ( 1  sekunda)" << endl;
    cout << " " << Settings::HIGH_DELAY << ".    Veliko kasnjenje    ( 2  sekunde)" << endl;
    cout << " " << endl;
    cout << "Uneti ka�njenje : ";
    cin >> str_command;

    if (isInputOK(str_command)) {

        switch (stoi(str_command)) {

            case Settings::NO_DELAY:
                delay = Settings::NO_DELAY_VALUE;
                break;

            case Settings::MEDIUM_DELAY:
                delay = Settings::MEDIUM_DELAY_VALUE;
                break;

            case Settings::HIGH_DELAY:
                delay = Settings::HIGH_DELAY_VALUE;
                break;

            default:
                wrongAnswer();
                displayRequestDelay(delay);
                break;
        }


    } else {
        wrongInput();
        displayRequestDelay(delay);
    }


}


void DisplayHandler::displaySortTime(float time) {
    cout << "-------------------------------------------" << endl;
    cout << "|  Vreme izvršavanja :" << time << " s      |" << endl;
    cout << "-------------------------------------------" << endl;
}

void DisplayHandler::displayOnSortFinish() {

    string str_command = "0";

    cout << "-------------------------------------------" << endl;
    cout << "|    1-Izadji         2-Novo sortiranje   |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Unesite komandu : ";
    cin >> str_command;

    if (isInputOK(str_command)) {
        switch (stoi(str_command)) {

            case Settings::EXIT_PROGRAM:
                exit;
                break;

            case Settings::RESTART_PROGRAM:
                ProccessHandler::mainProccess();
                break;

            default:
                wrongAnswer();
                displayOnSortFinish();
                break;
        }


    } else {

        wrongInput();
        displayOnSortFinish();
    }


}


//Displays the wrong input message
void DisplayHandler::wrongInput() {

    DisplayHandler::clearScreen();

    cout << "Uneli ste pogresan znak,pokusajte ponovo" << endl;

    sleep(2);


}

void DisplayHandler::clearScreen() {
#ifdef OS_WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

//Displays the max size message
void DisplayHandler::maxSize() {

    DisplayHandler::clearScreen();

    cout << "| Maksimalni broj elelemata je : " << Settings::MAX_ELEMENTS << "|" << endl;;

    sleep(2);
}

//Displays when the user entered an nonexisting answer
void DisplayHandler::wrongAnswer() {

    DisplayHandler::clearScreen();

    cout << "Uneli ste nepostojeci odgovor" << endl;

    sleep(2);

}

bool DisplayHandler::isInputOK(string &s) {

    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();

}

void DisplayHandler::displayElements(vector<int> vec) {


    DisplayHandler::clearScreen();
    cout << "----------------------------------------------" << endl;
    cout << "| Unesite brojeve koje zelite da sortirate    |" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;

    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

    cout << endl;
    cout << endl;
}

