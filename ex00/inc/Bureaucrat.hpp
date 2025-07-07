/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:08:08 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 13:31:33 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//LIBRARIES
#include <iostream>

//DEBUG
#ifdef DEBUG
# define DEBUG_MSG(x) std::cout << "[DEBUG]: " << x << std::endl
#else
# define DEBUG_MSG(x)
#endif

//COLORS
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define BLINK    "\033[5m" 
# define REVERSE  "\033[7m"

//CLASSES
class Bureaucrat {

private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	void	operator<<(const Bureaucrat &copy);
	~Bureaucrat();

	//validation
	int			isValid(int grade) const;
	void		verifyGrade(int grade) const;

	//getters
	std::string	getName() const;
	int			getGrade() const;

	//exceptions
	void			GradeTooHighException() const;
	void			GradeTooLowException() const;

	//grades control
	void	plusGrade();
	void	minusGrade();
};
