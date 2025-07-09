/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:48:20 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 16:23:07 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	//gradeToSign = 25
	//gradeToExecute = 5
	//
	//SUPER POWER:
	//Informs that <target> has been pardoned by Zaphod Beeblebrox
private:

	const std::string	_name;
	const std::string	_target;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	//getters
	std::string		getName() const;
	bool			getFormState() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	
	//Execute
	void		execute(Bureaucrat const &executor) const;
	void		action() const;
};

//operator overload
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &f);
