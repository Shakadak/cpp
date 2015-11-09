#include <stdexcept>
#include "Bureaucrat.hpp"

std::string Bureaucrat::getName(void) const {
    return (_name);
}

int Bureaucrat::getGrade(void) const {
    return (_grade);
}

void    Bureaucrat::upgrade(void) {
    if (_grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else {
        _grade -= 1;
    }
}

void    Bureaucrat::degrade(void) {
    if (_grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    else {
        _grade += 1;
    }
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(void) : _name("Noname"), _grade(150) {
}

Bureaucrat::Bureaucrat(Bureaucrat const& bb) : _name(bb._name), _grade(bb._grade) {
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
    *this = Bureaucrat(rhs);
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, Bureaucrat const& rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (o);
}
