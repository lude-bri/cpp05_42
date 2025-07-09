/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:29:54 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 17:09:19 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <stdlib.h>

//Default Constructor
RobotomyRequestForm::RobotomyRequestForm() : _isSigned(false), _gradeToSign(72), _gradeToExecute(45) {
	DEBUG_MSG("A Default RobotomyRequestForm Constructor was called");
}

//Parametric Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: _target(target), _isSigned(false), _gradeToSign(72), _gradeToExecute(45) {
	DEBUG_MSG("A Parametric RobotomyRequestForm Constructor was called");
}

//Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
	: _isSigned(false), _name(copy._name), _target(copy._target),
	_gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign)
{
	DEBUG_MSG("A Copy RobotomyRequestForm Constructor was called");
}

//Copy Assignment Operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	DEBUG_MSG("A Copy RobotomyRequestForm Constructor was called");
	if (this != &copy) {
		_isSigned = copy._isSigned;
	}
	return *this;
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	DEBUG_MSG("A Copy RobotomyRequestForm Constructor was called");
}

//getters
std::string			RobotomyRequestForm::getName() const {return _name;}
bool				RobotomyRequestForm::getFormState() const {return _isSigned;}
int					RobotomyRequestForm::getGradeToSign() const {return _gradeToSign;}
int					RobotomyRequestForm::getGradeToExecute() const {return _gradeToExecute;}

//Sign
void	RobotomyRequestForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		GradeTooLowException();
}

//Execute
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!_isSigned)
		FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		GradeTooLowException();
	AForm::execute(executor);
}

void	RobotomyRequestForm::action() const {
	std::cout << "Driiiiilllliiinnngggg......." << std::endl;
	std::srand(time(NULL));
	int result = rand()%100;
	if (result % 2 == 0)
		std::cout << _target << "'s robotomy was a success!" << std::endl;
	else
		std::cout << _target << "'s robotomy was a disaster! Jeez! Lord! Someone help me!" << std::endl;
}

//Operator Overload
std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &f) {
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
