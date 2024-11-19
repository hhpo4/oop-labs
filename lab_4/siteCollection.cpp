#include "site.h"
#include "SiteCollection.h"
#include <fstream>
#include <iostream>
#include <string>

SiteCollection::SiteCollection(unsigned int maxSites, unsigned int numSites) {
    this->maxSites = maxSites;
    this->numSites = numSites;
    sites = new Site[maxSites];
}

SiteCollection::~SiteCollection() {
    delete[] sites;
}

void SiteCollection::addSite(const Site& site) {
    if (numSites < maxSites) {
        sites[numSites++] = site;
    } else {
        std::cout << "Error: Maximum number of sites reached." << std::endl;
    }
}

void SiteCollection::removeSite(int index) {
    if (index >= 0 && index < numSites) {
        std::string siteName = sites[index].getName();

        for (int i = index; i < numSites - 1; i++) {
            sites[i] = sites[i + 1];
        }
        numSites--;

        std::cout << "сайт '" << siteName << "' был удален." << std::endl;
    } else {
        std::cout << "Error: Invalid index." << std::endl;
    }
}

void SiteCollection::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < numSites; i++) {
            sites[i].readFromFile(file);
        }
        file.close();
    } else {
        std::cout << "Error: Could not open file." << std::endl;
    }
}

void SiteCollection::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < numSites; i++) {
            sites[i].writeToFile(filename);
        }
        file.close();
    } else {
        std::cout << "Error: Could not open file." << std::endl;
    }
}

void SiteCollection::displayAll() const {
    for (int i = 0; i < numSites; i++) {
        sites[i].printToScreen();
        std::cout << std::endl;
    }
}

Site* SiteCollection::findFastestSite() const {
    Site* fastestSite = &sites[0];

    for (int i = 1; i < numSites; i++) {
        if (sites[i].getTime() < fastestSite->getTime()) {
            fastestSite = &sites[i];
        }
    }
    
    return fastestSite;
}

Site* SiteCollection::getSites() const {
    return sites;
}