#ifndef SITE_H
#define SITE_H

#include <string>
#include <fstream>

using namespace std;

class Site {
private:
    string name;
    string type;
    string domain;
    int users;
    int linked;
    double time;
    string technologies[50];

public:
    Site();
    Site(const string& name, const string& type, const string& domain, int users, int linked, double time, const string technologies[]);

    const string& getName() const;
    void setName(const string& name);
    const string& getType() const;
    void setType(const string& type);
    const string& getDomain() const;
    void setDomain(const string& domain);
    int getUsers() const;
    void setUsers(int users);
    int getLinked() const;
    void setLinked(int linked);
    double getTime() const;
    void setTime(double time);
    const string* getTechnologies() const;
    void setTechnologies(const string technologies[]);

    bool operator==(const Site& anotherSite);
    friend ostream& operator<<(ostream& stream, const Site& anotherSite);
    friend istream&operator>>(istream &stream, Site &anotherSite);
    friend ofstream& operator<<(ofstream& stream, const Site& anotherSite);
    friend ifstream& operator>>(ifstream& stream, Site& anotherSite);
};

#endif
