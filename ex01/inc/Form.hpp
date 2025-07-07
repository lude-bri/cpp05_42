/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:04:37 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 17:20:03 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"


//Let's Create a Form class that has
//
//A constant name
//A boolean indicating whether it is signed
//A const grade required to sign it
//A const grade required to executed it
//
//ALL PRIVATE

//CLASS
class Form {

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign = 75;
	const int			_gradeToExecute = 120;

};
