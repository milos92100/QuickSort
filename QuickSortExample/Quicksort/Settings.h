#pragma once

class Settings {


public:

    static const int DEFAULT_ARRAY = 2;
    static const int CUSTOM_ARRAY = 1;

    static const int EXIT_PROGRAM = 1;
    static const int RESTART_PROGRAM = 2;

    static const int MAX_ELEMENTS = 3000;

    static const int NO_DELAY = 1;
    static const int MEDIUM_DELAY = 2;
    static const int HIGH_DELAY = 3;

    static const int NO_DELAY_VALUE = 0;
    static const int MEDIUM_DELAY_VALUE = 1000;
    static const int HIGH_DELAY_VALUE = 2000;

    Settings(void);

    ~Settings(void);
};

