#include "site.h"
#include "searchSite.h"
#include "SiteCollection.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

SiteCollection::SiteCollection(unsigned int maxCommonSites, unsigned int maxSearchSites, unsigned int numCommonSites, unsigned int numSearchSites) {
    this->maxCommonSites = maxCommonSites;
    this->maxSearchSites = maxSearchSites;
    this->numCommonSites = numCommonSites;
    this->numSearchSites = numSearchSites;

    commonSites = new Site[maxCommonSites];
    searchSites = new SearchSite[maxSearchSites];
}

SiteCollection::~SiteCollection() {
    delete[] commonSites;
    delete[] searchSites;

    numCommonSites = 0;
    numSearchSites = 0;
    maxCommonSites = 0;
    maxSearchSites = 0;
}

const int SiteCollection::getNumCommonSites() const {
    return numCommonSites;
}

const int SiteCollection::getNumSearchSites() const {
    return numSearchSites;
}

void SiteCollection::operator+=(const Site& commonSite) {
    if (numCommonSites < maxCommonSites) {
        commonSites[numCommonSites] = commonSite;
        numCommonSites++;
    } else {
        cout << "Error: Maximum number of sites reached." << endl;
    }
}

void SiteCollection::operator+=(const SearchSite& searchSite) {
    if (numSearchSites < maxSearchSites) {
        searchSites[numSearchSites] = searchSite;
        numSearchSites++;
    } else {
        cout << "Error: Maximum number of sites reached." << endl;
    }
}

ostream& operator<<(ostream& stream, const SiteCollection& anotherSiteCollection) {
    for (int i = 0; i < anotherSiteCollection.numCommonSites; i++) {
        stream << anotherSiteCollection.commonSites[i] << endl;
    }
    for (int i = 0; i < anotherSiteCollection.numSearchSites; i++) {
        stream << anotherSiteCollection.searchSites[i] << endl;
    }
    
    return stream;
}

void SiteCollection::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < numCommonSites; i++) {
            file >> commonSites[i];
        }
        for (int i = numCommonSites; i < numSearchSites; i++) {
            file >> searchSites[i];
        }
        file.close();
    } else {
        cout << "Error: Could not open file." << endl;
    }
}

ofstream& operator<<(ofstream& stream, const SiteCollection& anotherSiteCollection) {
    for (int i = 0; i < anotherSiteCollection.numCommonSites; i++) {
        stream << anotherSiteCollection.commonSites[i];
        stream << endl;
    }
    for (int i = 0; i < anotherSiteCollection.numSearchSites; i++) {
        stream << anotherSiteCollection.searchSites[i];
        stream << endl;
    }
    
    return stream;
}

void SiteCollection::findFastestSite() const {
    double fastestSiteTime = commonSites[0].getTime();
    string fastestSiteName = commonSites[0].getName();

    for (int i = 1; i < numCommonSites; i++) {
        if (commonSites[i].getTime() < fastestSiteTime) {
            fastestSiteTime = commonSites[i].getTime();
            fastestSiteName = commonSites[i].getName();
        }
    }

    for (int i = 0; i < numSearchSites; i++) {
        if (searchSites[i].getTime() < fastestSiteTime) {
            fastestSiteTime = searchSites[i].getTime();
            fastestSiteName = searchSites[i].getName();
        }
    }

    cout << "Самый быстрый сайт: " << fastestSiteName << endl;
}
