#ifndef SITE_H
#define SITE_H

#include <string>
#include <fstream>

class Site {
private:
    std::string name;
    std::string type;
    std::string domain;
    int users;
    int linked;
    double time;
    std::string technologies[50];

public:
    Site();
    Site(const std::string& name, const std::string& type, const std::string& domain, int users, int linked, double time, const std::string technologies[]);

    const std::string& getName() const;
    void setName(const std::string& name);
    const std::string& getType() const;
    void setType(const std::string& type);
    const std::string& getDomain() const;
    void setDomain(const std::string& domain);
    int getUsers() const;
    void setUsers(int users);
    int getLinked() const;
    void setLinked(int linked);
    double getTime() const;
    void setTime(double time);
    const std::string* getTechnologies() const;
    void setTechnologies(const std::string technologies[]);

    bool operator==(const Site& anotherSite);
    friend std::ostream& operator<<(std::ostream& stream, const Site& anotherSite);
    friend std::istream&operator>>(std::istream &stream, Site &anotherSite);
    friend std::ofstream& operator<<(std::ofstream& stream, const Site& anotherSite);
    friend std::ifstream& operator>>(std::ifstream& stream, Site& anotherSite);
};

#endif
