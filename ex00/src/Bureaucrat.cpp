/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:10:49 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 13:26:11 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

//Default constructor
Bureaucrat::Bureaucrat() {
	std::cout << "A default Bureaucrat was build" << std::endl;
}

//Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	DEBUG_MSG("Bureaucrat's Constructor was called\n");

	//verify grade
	verifyGrade(grade);
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	DEBUG_MSG("Bureaucrat's Copy Constructor was called\n");
	*this = copy;
}

//Copy operator = assignment
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	DEBUG_MSG("Bureaucrat's Operator Assignment = was called\n");
	return *this;
}

//Copy operator << assignment
void Bureaucrat::operator<<(const Bureaucrat &copy) const {
	DEBUG_MSG("Bureaucrat's Operator Assignment << was called\n");
	std::cout << _name << ", bureaucrat grade " << _grade << std::endl;
}

//Destructor
Bureaucrat::~Bureaucrat(){
	DEBUG_MSG("Bureaucrat's Destructor was called\n");
}

//Validation of grade outbounds
int		Bureaucrat::isValid(int grade) const {
	return (grade >= 1 && grade <= 150);
}

void	Bureaucrat::verifyGrade(int grade) const {
	try {
		//verificar se grade esta valido
	}
	catch (std::exception &e) {
		//handle exception
	}
}
