#ifndef SITE_COLLECTION
#define SITE_COLLECTION

#include "site.h"
#include "searchSite.h"

using namespace std;

class SiteCollection {
private:
    unsigned int maxCommonSites;
    unsigned int maxSearchSites;
    unsigned int numCommonSites;
    unsigned int numSearchSites;
    Site* commonSites;
    SearchSite* searchSites;

public:
    SiteCollection(unsigned int maxCommonSites, unsigned int maxSearchSites, unsigned int numCommonSites, unsigned int numSearchSites);
    ~SiteCollection();

    const int getNumCommonSites() const;
    const int getNumSearchSites() const;

    void operator +=(const Site& commonSite);
    void operator +=(const SearchSite& searchSite);
    
    void findFastestSite() const;
    void loadFromFile(const string& filename);

    friend ofstream& operator<<(ofstream& stream, const SiteCollection& anotherSiteCollection);
    friend ostream& operator<<(ostream& stream, const SiteCollection& anotherSiteCollection);
};

#endif