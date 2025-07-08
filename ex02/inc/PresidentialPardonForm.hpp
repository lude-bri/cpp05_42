/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:48:20 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 18:48:32 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	//gradeToSign = 25
	//gradeToExecute = 5
	//
	//SUPER POWER:
	//Informs that <target> has been pardoned by Zaphod Beeblebrox
private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign = 25;
	const int			_gradeToExecute = 5;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	//Execute
	void		action() const;
};
