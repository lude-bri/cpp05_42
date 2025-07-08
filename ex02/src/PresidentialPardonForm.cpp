/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:29:38 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 15:40:00 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

//Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : _isSigned(false) {
	DEBUG_MSG("A Default PresidentialPardonForm Constructor was called");
}

//Parametric Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : _target(target), _isSigned(false) {
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

//Execute
