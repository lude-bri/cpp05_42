/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:48:22 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 15:34:06 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	//gradeToSign = 72
	//gradeToExecute = 45
	//
	//Makes some drilling noises, then informs that <target> has been robotomized
	//succefully 50% of the time. Otherwise, it informs that the robotomy failed
private:

	const std::string	_name;
	const std::string	_target;
	bool				_isSigned;
	const int			_gradeToSign = 72;
	const int			_gradeToExecute = 45;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	//Execute
	void		action() const;
};
