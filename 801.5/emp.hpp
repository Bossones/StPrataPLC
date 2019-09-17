#ifndef EMP_HPP__
#define EMP_HPP__

#include <iostream>
#include <string>

class abstr_emp {
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & In,
                const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0; // виртуальный базовый класс
};

class employee : public abstr_emp {
public:
    employee ();
    employee(const std::string & fn, const std::string & In,
                const std::string & j);
    virtual ~employee() {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager: virtual public abstr_emp {
private:
    int inchargeof; // количество управляемых abstr_emp
protected:
    int InChargeOf() const { return inchargeof; } // вывод
    int & InChargeOf() { return inchargeof; } // ввод
public:
    manager();
    manager(const std::string & fn, const std::string & In, const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico = 0);
    manager(const manager & m);
    virtual ~manager() {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink: virtual public abstr_emp {
private:
    std::string reportsto; // кому выводить отчеты
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & In,
            const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual ~fink() {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public manager, public fink {
public:
    highfink () ;
    highfink(const std::string & fn, const std::string & In,
                const std::string & j, const std::string & rpo, int ico = 0) ;
    highfink(const abstr_emp & e, const std::string & rpo, int ico = 0);
    highfink(const fink & f, int ico = 0);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);

    virtual ~highfink() {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

#endif