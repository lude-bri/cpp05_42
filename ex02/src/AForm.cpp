/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:25:32 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 10:31:25 by lude-bri         ###   ########.fr       */
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
//Destructor

//Exceptions
//getters
//Sign

