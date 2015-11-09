#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>

class Bureaucrat {
    public:
        std::string getName(void) const;
        int     getGrade(void) const;
        void    upgrade(void);
        void    degrade(void);

        Bureaucrat(std::string name, int grade);
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const& bb);
        ~Bureaucrat(void);
        Bureaucrat& operator=(Bureaucrat const& rhs);

        class GradeTooHighException : public std::exception {
            virtual const char* what(void) const throw() {
                return ("Grade too high.");
            }
        };

        class GradeTooLowException : public std::exception {
            virtual const char* what(void) const throw() {
                return ("Grade too low.");
            }
        };

    private:
        std::string const   _name;
        int _grade;
};

std::ostream&   operator<<(std::ostream& o, Bureaucrat const& rhs);

#endif
