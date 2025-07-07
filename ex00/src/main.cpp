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
			Bureaucrat b("bob", 150);
			std::cout << b << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
