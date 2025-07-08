/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:48:23 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 18:48:36 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	//gradeToSign = 145
	//gradeToExecute = 137
	//
	//SUPER POWER:
	//creates a file <target>_shrubbery in the working directory
	//and writes ASCII trees inside it
private:
	const std::string	_name;
	const std::string	_target;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	//Execute
	void	execute(Bureaucrat const &executor) const;
	void	action() const;
};


//operator overload
std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &f);
