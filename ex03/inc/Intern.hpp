/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:25:46 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/09 16:35:31 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

//In this exercise we must implement the Intern class
//The intern has no name, no grade and no unique characteristics
//
//The intern has only one key ability: the makeForm()
//takes two string as parameters: the first represent a name of a form
//and the second represent the target of the form
//it returns a pointer to a AForm object
//(corresponding to the form name passed as parameter)
//with its target initialized to the second parameter
//
//it should print 'Intern creates <form>'
//if the provided name does not exist, print an explicit error message

class Intern {

private:

	typedef AForm *(Intern::*MemFun)(const std::string &name) const;
	
	static const MemFun functions[3];
	static const std::string formNames[3];

	AForm *buildShrubbery(const std::string &target) const;
	AForm *buildRobotomy(const std::string &target) const;
	AForm *buildPresidential(const std::string &target) const;

public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern();

	//the only ability
	AForm	*makeForm(const std::string &form, const std::string &target);

};
