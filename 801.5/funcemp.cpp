#include "emp.hpp"

//abstr_emp::

std::ostream & operator<<(std::ostream & os, const abstr_emp & e) {
    os << "Fullname: " << e.fname << " " << e.lname << std::endl;
    os << "Job: " << e.job;
    return os;
}

void abstr_emp::ShowAll() const {
    std::cout << *this << std::endl;
}

void abstr_emp::SetAll() {
    std::cout << "Enter firstname: ";
    std::getline(std::cin, fname);
    std::cout << "Enter lastname: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

abstr_emp::abstr_emp() : fname("no name"), lname("no name"), job("no job") {}

abstr_emp::abstr_emp(const std::string & fn, const std::string & In, const std::string & j) :
                        fname(fn), lname(In), job(j) {}

abstr_emp::~abstr_emp() {}

//employee::

employee::employee() {}

employee::employee(const std::string & fn, const std::string & In, const std::string & j) :
                    abstr_emp(fn, In, j) {}

void employee::ShowAll() const {
    abstr_emp::ShowAll();
}

void employee::SetAll() {
    abstr_emp::SetAll();
}

//manager::

manager::manager() : abstr_emp() {}

manager::manager(const std::string & fn, const std::string & In, const std::string & j, int ico) :
                    abstr_emp(fn, In, j), inchargeof(ico) {}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager & m) : abstr_emp(m) {
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const {
    std::cout << *this << std::endl;
    std::cout << "In charge of is: " << inchargeof << std::endl;
}

void manager::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter inchargeof: ";
    std::cin >> inchargeof;
    while(std::cin.get() != '\n')
        continue;
}

//fink::

fink::fink() : reportsto("no name") {}

fink::fink(const std::string & fn, const std::string & In, const std::string & j, const std::string & rpo) :
            abstr_emp(fn, In, j), reportsto(rpo) {}

fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const {
    std::cout << *this << std::endl;
    std::cout << "Reports to: " << reportsto << std::endl;
}

void fink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter reports to: ";
    std::getline(std::cin, reportsto);
}

//highfink::

highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const std::string & fn, const std::string & In, const std::string & j, 
                    const std::string & rpo, int ico) : abstr_emp(fn, In, j), manager(fn, In, j, ico), 
                    fink(fn, In, j, rpo) {}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e), manager(e, ico),
                    fink(e, rpo) {}

highfink::highfink(const fink & f, int ico) : abstr_emp(f), fink(f), manager(dynamic_cast<const abstr_emp &>(f), ico) {}

highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m), fink(dynamic_cast<const abstr_emp &>(m), rpo) {}

highfink::highfink(const highfink & h) : abstr_emp(h), fink(h), manager(h) {}

void highfink::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "In charge of is : " << InChargeOf() << std::endl;
    std::cout << "Reports to: " << ReportsTo() << std::endl;
}

void highfink::SetAll() {
    abstr_emp::SetAll();
    int & tempInCh = InChargeOf();
    std::string & tempRpo = ReportsTo();
    std::cout << "Enter ReportsTo: ";
    std::getline(std::cin, tempRpo);
    std::cout << "Enter InChargeOf: ";
    std::cin >> tempInCh;
    while(std::cin.get() != '\n')
        continue; 
}