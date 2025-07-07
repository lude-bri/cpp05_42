/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:04:37 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 17:56:31 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

//Add a beSigned(const Bureaucrat &b)

//CLASS
class Form {

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign = 75;
	const int			_gradeToExecute = 120;

public:
	Form();
	Form(std::string &name);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	//Exceptions
	void			GradeTooLowException() const;
	void			GradeTooHighException() const;

	//getters
	std::string		getName();
	bool			getFormState();
	int				getGradeToSign();
	int				getGradeToExecute();

	//Sign
	void			beSigned(const Bureaucrat &b);
};

//operator overload
std::ostream &operator<<(std::ostream &out, Form &f);
