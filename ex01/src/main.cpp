/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:03:45 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 18:20:03 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

void	printTestHeader(const std::string &testName) {
	std::cout << "\n";
	std::cout << YELLOW << "= " << testName << " =" << RESET << std::endl;
	std::cout << "\n";
}

int main (void)
{
	printTestHeader("Test 00. Building");
	{
		Form f("Aspadex Form");

		std::cout << f.getName() << " has the following state: " << f.getFormState()
		<< std::endl;
	}
	printTestHeader("Test 01. Form State");
	{
		Form	f("Ajax Contract");

		std::cout << f << std::endl;
	}
	printTestHeader("Test 02. Signing Forms");
	{
		Form		f("Top Secret");
		Bureaucrat	b("Fred", 60);
		Bureaucrat	d("Salsicha", 75);

		std::cout << f << std::endl;
		b.signForm(f);
		d.signForm(f);
		std::cout << f << std::endl;

	}
}
