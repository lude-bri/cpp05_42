/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:27:44 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 15:39:15 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

//Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : _isSigned(false) {
	DEBUG_MSG("A Default ShrubberyCreationForm Constructor was called");
}

//Parametric Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target), _isSigned(false) {
	DEBUG_MSG("A Parametric ShrubberyCreationForm Constructor was called");
}

//Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
	: _isSigned(false), _name(copy._name), _target(copy._target),
	_gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign)
{
	DEBUG_MSG("A Copy ShrubberyCreationForm Constructor was called");
}

//Copy Assignment Operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	DEBUG_MSG("A Copy ShrubberyCreationForm Constructor was called");
	if (this != &copy) {
		_isSigned = copy._isSigned;
	}
	return *this;
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	DEBUG_MSG("A Copy ShrubberyCreationForm Constructor was called");
}

//Execute
