#ifndef GAME_SITE_H
#define GAME_SITE_H

#include "site.h"

class GameSite : public Site {
    protected: 
        string gameName;
        int year;
    public:
        GameSite();
        GameSite(const string& name, const string& type, const string& domain, int users, int linked, double time, const string technologies[], const string& gameName, int year);

        void display();
        void writeToFile(const string& filename);
        void readFromFile(const string& filename);
        void readFromKeyboard();
};

#endif