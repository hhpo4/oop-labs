#ifndef SEARCHSITE_H
#define SEARCHSITE_H

#include "site.h"
#include "searchSite.h"
#include <string>

using namespace std;

class SearchSite : public Site {
protected:
    string searchTechnology;
    bool hasAI;

public: 
    SearchSite();
    SearchSite(const string& name, const string& type, const string& domain, int users, int linked, double time, const string technologies[], const string& searchTechnology, bool hasAI);

    const string& getSearchTechnology() const;
    void setSearchTechnology(const string& searchTechnology);
    bool getHasAI() const;
    void setHasAI(bool hasAI);

    bool operator==(const SearchSite& anotherSearchSite);

    void display();
    void writeToFile(const string& filename);
    void readFromFile(const string& filename);
    void readFromKeyboard();
};

#endif
