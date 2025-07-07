/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:04:31 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 17:33:19 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

//Default Constructor
Form::Form() : _isSigned(false) {
	DEBUG_MSG("A Default Form was build\n");
}

//Parametric Constructor
Form::Form(std::string &name) : _name(name), _isSigned(false) {
	DEBUG_MSG("A Form was build\n");
}

//Copy Constructor
Form::Form(const Form &copy) 
	: _name(copy._name), _isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	DEBUG_MSG("A Form Copy Constructor was build\n");
}

//Operator Assignmed
//Destructor
//Operator Overload
//Getters
//Exceptions
