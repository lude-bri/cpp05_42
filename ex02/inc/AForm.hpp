/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:48:17 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 11:13:11 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

//CLASS
class AForm {

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	AForm();
	AForm(const std::string &name);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	~AForm();

	//Exceptions
	void			GradeTooLowException() const;
	void			GradeTooHighException() const;
	void			FormNotSignedException() const;

	//getters
	std::string		getName();
	bool			getFormState();
	int				getGradeToSign();
	int				getGradeToExecute();

	//Sign
	void			beSigned(Bureaucrat &b);

	//Execute
	virtual void			execute(Bureaucrat const &executor) = 0;
	virtual void			action() = 0; 
};

//operator overload
std::ostream &operator<<(std::ostream &out, AForm &f);
