/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:10:49 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 12:46:24 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

//Default constructor
Bureaucrat::Bureaucrat() {
	std::cout << "A default Bureaucrat was build" << std::endl;
}

//Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	//verify grade
	try {
		if (isValid(grade))
			_grade = grade;
	}
	catch (std::exception &e) {
		//continue implementing
	}
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	
}



int		Bureaucrat::isValid(int grade) {
	return (grade >= 1 && grade <= 150);
}
