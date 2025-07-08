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
	bool				_isSigned;
	const int			_gradeToSign = 145;
	const int			_gradeToExecute = 137;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	//Execute
	void	action() const;
};
