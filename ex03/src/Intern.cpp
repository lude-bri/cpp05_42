/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:25:38 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/09 17:47:27 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Intern.hpp"

//Default Constructor
Intern::Intern() {
	DEBUG_MSG("An Intern Default Constructor was called");
}

//Copy Constructor
Intern::Intern(const Intern &copy) {
	DEBUG_MSG("An Intern Copy Constructor was called");
}

//Copy Assignment Operator
Intern &Intern::operator=(const Intern &copy) {
	DEBUG_MSG("An Intern Copy Assignment Operator was called");
	return *this;
}

//Default Destructor
Intern::~Intern() {
	DEBUG_MSG("An Intern Default Destructor was called");
}

const Intern::MemFun Intern::functions[3] = {
	&Intern::buildShrubbery,
	&Intern::buildRobotomy,
	&Intern::buildPresidential
};

const std::string Intern::formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

AForm* Intern::buildShrubbery(const std::string& target) const { return new ShrubberyCreationForm(target);}
AForm* Intern::buildRobotomy(const std::string& target) const { return new RobotomyRequestForm(target); }
AForm* Intern::buildPresidential(const std::string& target) const { return new PresidentialPardonForm(target);}

//the only ability
AForm	*Intern::makeForm(const std::string &form, const std::string &target) {

	DEBUG_MSG("An Intern makeForm Method was called");

	for (int i = 0; i < 3; i++) {
		if (form == formNames[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return ((this->*functions[i])(target));
		}
	}
	std::cerr << "Error: Unkown name" << std::endl;
	return NULL;
}
