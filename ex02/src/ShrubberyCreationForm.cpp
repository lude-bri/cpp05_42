/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:27:44 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 15:33:33 by lude-bri         ###   ########.fr       */
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
//Copy Assignment Operator
//Destructor
//Execute
