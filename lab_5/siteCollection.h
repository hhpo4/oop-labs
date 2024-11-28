#ifndef SITE_COLLECTION
#define SITE_COLLECTION

#include "site.h"

class SiteCollection {
private:
    Site* sites;
    int maxSites;
    int numSites;

public:
    SiteCollection(unsigned int maxSites, unsigned int numSites);
    ~SiteCollection();

    void operator +=(const Site& site);
    
    void removeSite(int index);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void displayAll() const;
    Site* findFastestSite() const;

    Site* getSites() const;
};

#endif