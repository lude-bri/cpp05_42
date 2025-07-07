/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:04:47 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/07 14:05:49 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

void	printTestHeader(const std::string &testName) {
	std::cout << "\n";
	std::cout << YELLOW << "= " << testName << " =" << RESET << std::endl;
	std::cout << "\n";
}

int	main (void)
{
	printTestHeader("Test 00. Simple test build");
	{
		try
		{
			Bureaucrat b("Paul", 150);
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	printTestHeader("Test 01. Increment Grade");
	{
		try {
			
			Bureaucrat b("John", 3);

			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	printTestHeader("Test 02. Decrement Grade");
	{
		try {
			
			Bureaucrat b("Ringo", 3);

			b.decrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	printTestHeader("Test 03. Out of Bounds - High Grade");
	{
		try {

			Bureaucrat b("George", 150);

			for (int i = 0; i < 149; i++)
					b.incrementGrade();
			std::cout << b.getGrade() << std::endl; //grade = 1

			//trying to increment again
			b.incrementGrade();
			std::cout << b.getGrade() << std::endl;

		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	printTestHeader("Test 04. Out of Bounds - Low Grade");
	{
		try {

			Bureaucrat b("George", 1);

			for (int i = 0; i < 149; i++)
					b.decrementGrade();
			std::cout << b.getGrade() << std::endl; //grade = 1

			//trying to increment again
			b.decrementGrade();
			std::cout << b.getGrade() << std::endl;

		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;

}
