#ifndef SITE_COLLECTION
#define SITE_COLLECTION

#include "site.h"
#include "searchSite.h"

using namespace std;

class SiteCollection {
private:
    unsigned int maxCommonSites;
    unsigned int maxSearchSites;
    unsigned int maxGameSites;
    unsigned int numCommonSites;
    unsigned int numSearchSites;
    unsigned int numGameSites;
    Site** commonSites;

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