/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:48:15 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 11:29:27 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

//Default constructor
Bureaucrat::Bureaucrat() {
	std::cout << "A default Bureaucrat was build" << std::endl;
}

//Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	DEBUG_MSG("Bureaucrat's Constructor was called");
	_grade = isValid(grade);

	std::cout << "Bureaucrat " << _name << "'s grade is " << getGrade() << std::endl;
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	DEBUG_MSG("Bureaucrat's Copy Constructor was called");
	*this = copy;
}

//Copy operator = assignment
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	DEBUG_MSG("Bureaucrat's Operator Assignment = was called");
	return *this;
}

//Copy operator << assignment
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return out;
}

//Destructor
Bureaucrat::~Bureaucrat(){
	DEBUG_MSG("Bureaucrat's Destructor was called");
}

//Validation of grade outbounds
int		Bureaucrat::isValid(int grade) const {
	if (grade < 1)
		GradeTooHighException();
	if (grade > 150)
		GradeTooLowException();
	return grade;
}

//getters
std::string	Bureaucrat::getName() const {
	// std::cout << "Bureaucrat name's is : " << _name << std::endl;
	return (_name);
}

int	Bureaucrat::getGrade() const { 
	// std::cout << "Bureaucrat grade's is : " << _grade << std::endl;
	return (_grade);
}


//Exceptions LOW
void		Bureaucrat::GradeTooLowException() const {
	throw std::runtime_error(_name + ": grade is too low");
}

//Exceptions HIGH 
void		Bureaucrat::GradeTooHighException() const {
	throw std::runtime_error(_name + ": grade is too high");
}

//grades control
void	Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		GradeTooHighException();
	else
		--_grade;
}

void	Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		GradeTooLowException();
	else
		++_grade;
}

//Sign Form
void	Bureaucrat::signForm(AForm &f) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << _name << " couldn't sign " << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

//Execute Form
void	Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << _name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
