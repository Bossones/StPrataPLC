#ifndef WORKER_HPP__
#define WORKER_HPP__

#include <string>

class Worker {
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const char * s, const long & n) : fullname(s), id(n) {}

    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Teacher : virtual public Worker {
private:
    unsigned int yearsOfTeaching;
protected:
    virtual void Data() const override;
    virtual void Get() override;
public:
    Teacher() : Worker(), yearsOfTeaching(0) {}
    Teacher(const char * s, const long & n, const unsigned int & y) : Worker(s, n), yearsOfTeaching(y) {}

    virtual ~Teacher() override {}
    virtual void Set() override;
    virtual void Show() const override;
};

#endif