/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:04:31 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 18:37:23 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

//Default Constructor
Form::Form() : _isSigned(false), _gradeToSign(75), _gradeToExecute(120) {
	DEBUG_MSG("A Default Form was build");
}

//Parametric Constructor
Form::Form(const std::string &name) : _name(name), _isSigned(false), _gradeToSign(75), _gradeToExecute(120) {
	DEBUG_MSG("A Form was build");
}

//Copy Constructor
Form::Form(const Form &copy) 
	: _name(copy._name), _isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	DEBUG_MSG("A Form Copy Constructor was called");
}

//Operator Assignment
Form	&Form::operator=(const Form &copy) {
	DEBUG_MSG("A Form Assignment Operator was called");

	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return *this;
}

//Destructor
Form::~Form() {
	DEBUG_MSG("A Form Destructor was called");
}

//Operator Overload
std::ostream &operator<<(std::ostream &out, Form &f) {
	DEBUG_MSG("A Form Operator Overload (<<) was called");

	out << "This is the Form " << f.getName() << "'s attributes: " <<  std::endl;
	out << "1. Form's State -> Signed: " << f.getFormState() << std::endl;
	out << "2. Required Grade to Sign: " << f.getGradeToSign() << std::endl;
	out << "3. Required Grade to Execute: " << f.getGradeToExecute() << std::endl;
	return out;
}

//Getters
std::string		Form::getName() { return _name; }
bool			Form::getFormState() { return _isSigned; }
int				Form::getGradeToSign() {return _gradeToSign; }
int				Form::getGradeToExecute() {return _gradeToExecute; }

//Exceptions
void	Form::GradeTooLowException() const {
	throw std::runtime_error(_name + ": grade is too low");
}

void	Form::GradeTooHighException() const {
	throw std::runtime_error(_name + ": grade is too high");
}

//Sign
void	Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		GradeTooLowException();
}
