/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:29:38 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 17:06:47 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

//Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : _isSigned(false), _gradeToSign(25), _gradeToExecute(5) {
	DEBUG_MSG("A Default PresidentialPardonForm Constructor was called");
}

//Parametric Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: _target(target), _isSigned(false), _gradeToSign(25), _gradeToExecute(5) {
	DEBUG_MSG("A Parametric PresidentialPardonForm Constructor was called");
}

//Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
	: _isSigned(false), _name(copy._name), _target(copy._target),
	_gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign)
{
	DEBUG_MSG("A Copy PresidentialPardonForm Constructor was called");
}

//Copy Assignment Operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	DEBUG_MSG("A Copy PresidentialPardonForm Constructor was called");
	if (this != &copy) {
		_isSigned = copy._isSigned;
	}
	return *this;
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	DEBUG_MSG("A Copy PresidentialPardonForm Constructor was called");
}

//getters
std::string			PresidentialPardonForm::getName() const {return _name;}
bool				PresidentialPardonForm::getFormState() const {return _isSigned;}
int					PresidentialPardonForm::getGradeToSign() const {return _gradeToSign;}
int					PresidentialPardonForm::getGradeToExecute() const {return _gradeToExecute;}

//Sign
void	PresidentialPardonForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		GradeTooLowException();
}

//Execute
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!_isSigned)
		FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		GradeTooLowException();
	AForm::execute(executor);
}

void	PresidentialPardonForm::action() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

//Operator Overload
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &f) {
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
