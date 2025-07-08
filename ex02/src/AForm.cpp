/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:25:32 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 10:46:31 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

//Default Constructor
AForm::AForm() : _isSigned(false), _gradeToSign(75), _gradeToExecute(125) {
	DEBUG_MSG("A Default AFORM Constructor was called");
}

//Parametric Constructor
AForm::AForm(const std::string &name) : _name(name), _isSigned(false), _gradeToSign(75), _gradeToExecute(125) {
	DEBUG_MSG("A Parametric AFORM Constructor was called");
}

//Copy Constructor
AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	DEBUG_MSG("A Copy AFORM Constructor was called");
}

//Assignment Operator
AForm	&AForm::operator=(const AForm &copy) {
	DEBUG_MSG("A Copy AFORM Assignment Operator was called");
	if (this != &copy) {
		_isSigned = copy._isSigned;
	}
	return *this;
}

//Destructor
AForm::~AForm() {
	DEBUG_MSG("A AFORM Destructor was called");
}

//Exceptions
void	AForm::GradeTooHighException() const {
	throw std::runtime_error(_name + ": grade too high");
}

void	AForm::GradeTooLowException() const {
	throw std::runtime_error(_name + ": grade too low");
}

//getters
std::string			AForm::getName() {return _name;}
bool				AForm::getFormState() {return _isSigned;}
int					AForm::getGradeToSign() {return _gradeToSign;}
int					AForm::getGradeToExecute() {return _gradeToExecute;}

//Sign
void	AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() >= 75) {
		std::cout << b.getName() << " signed " << _name << std::endl;
		_isSigned = true;
	}
	else
		std::cout << b.getName() << " couldn't sign " << _name
		<< " because grade is too low" << std::endl;
}

//Operator Overload
std::ostream &operator<<(std::ostream &out, AForm &f) {
	DEBUG_MSG("A AForm Operator Overload (<<) was called");

	out << "This is the Form " << f.getName() << "'s attributes: " <<  std::endl;
	out << "1. Form's State -> Signed: " << f.getFormState() << std::endl;
	out << "2. Required Grade to Sign: " << f.getGradeToSign() << std::endl;
	out << "3. Required Grade to Execute: " << f.getGradeToExecute() << std::endl;
	return out;
}
