/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:29:54 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 15:40:35 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

//Default Constructor
RobotomyRequestForm::RobotomyRequestForm() : _isSigned(false) {
	DEBUG_MSG("A Default RobotomyRequestForm Constructor was called");
}

//Parametric Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : _target(target), _isSigned(false) {
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

//Execute




