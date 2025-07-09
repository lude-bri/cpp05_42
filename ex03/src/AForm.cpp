/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:25:32 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/09 17:56:31 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

//Default Constructor
AForm::AForm() : _isSigned(false), _gradeToSign(75), _gradeToExecute(125) {
	DEBUG_MSG("A Default AForm Constructor was called");
}

//Parametric Constructor
AForm::AForm(const std::string &name) : _name(name), _isSigned(false), _gradeToSign(75), _gradeToExecute(125) {
	DEBUG_MSG("A Parametric AForm Constructor was called");
}

//Copy Constructor
AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	DEBUG_MSG("A Copy AForm Constructor was called");
}

//Assignment Operator
AForm	&AForm::operator=(const AForm &copy) {
	DEBUG_MSG("A Copy AForm Assignment Operator was called");
	if (this != &copy) {
		_isSigned = copy._isSigned;
	}
	return *this;
}

//Destructor
AForm::~AForm() {
	DEBUG_MSG("A AForm Destructor was called");
}

//Exceptions
void	AForm::GradeTooHighException() const {
	throw std::runtime_error(_name + ": grade too high");
}

void	AForm::GradeTooLowException() const {
	throw std::runtime_error(_name + ": grade too low");
}

void	AForm::FormNotSignedException() const {
	throw std::runtime_error(_name + ": form is not signed");
}

//getters
std::string			AForm::getName() const {return _name;}
bool				AForm::getFormState() const {return _isSigned;}
int					AForm::getGradeToSign() const {return _gradeToSign;}
int					AForm::getGradeToExecute() const {return _gradeToExecute;}

//Sign
void	AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		GradeTooLowException();
}

//Execute
void	AForm::execute(Bureaucrat const &executor) const {
	DEBUG_MSG("A AForm execute method was called");
	action();
}

//Operator Overload
std::ostream &operator<<(std::ostream &out, AForm &f) {
	DEBUG_MSG("A AForm Operator Overload (<<) was called");
	
	out << std::endl;
	out << " -----------------FORM-------------------------- " << std::endl;
	out << "This is the Form " << f.getName() << "'s attributes: " <<  std::endl;
	out << "1. Form's State -> Signed: " << f.getFormState() << std::endl;
	out << "2. Required Grade to Sign: " << f.getGradeToSign() << std::endl;
	out << "3. Required Grade to Execute: " << f.getGradeToExecute() << std::endl;
	out << " --------------------------------------------- " << std::endl;
	return out;
}

