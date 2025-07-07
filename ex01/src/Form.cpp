/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:04:31 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 17:28:04 by lude-bri         ###   ########.fr       */
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


//Operator Assignmed
//Destructor
//Operator Overload
//Getters
//Exceptions
