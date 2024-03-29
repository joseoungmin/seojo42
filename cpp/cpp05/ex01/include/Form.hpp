#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string	name;
		bool				sign;
		const int			gradeForSign;
		const int			gradeForExecute;
		Form(const Form &other);
		Form& operator=(const Form& other);

	public:
		Form();
		Form(std::string name, int gradeForSign, int GradeForExecute);
		~Form();

		const std::string	getName() const;
		bool				getSign() const;
		int					getGradeForSign() const;
		int					getGradeForExecute() const;
		void				beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form &obj);

#endif