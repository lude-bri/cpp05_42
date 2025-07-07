/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:10:49 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 13:07:47 by lude-bri         ###   ########.fr       */
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
	*this = copy;
}

//Copy operator = assignment
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	return *this;
}

//Copy operator << assignment
void Bureaucrat::operator<<(const Bureaucrat &copy) const {
	std::cout << _name << ", bureaucrat grade " << _grade << std::endl;
}

//Destructor
Bureaucrat::~Bureaucrat(){}

int		Bureaucrat::isValid(int grade) {
	return (grade >= 1 && grade <= 150);
}
