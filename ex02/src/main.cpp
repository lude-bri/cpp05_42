/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:43:56 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 16:59:20 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <fstream>

void	printTestHeader(const std::string &testName) {
	std::cout << "\n";
	std::cout << YELLOW << "= " << testName << " =" << RESET << std::endl;
	std::cout << "\n";
}

int main(void) {

	printTestHeader("Test 00. ShrubberyCreationForm");
	{
	  try {
			Bureaucrat gardener("Gardener", 137);
			Bureaucrat novice("Novice", 145);
			ShrubberyCreationForm form("home");

			std::cout << form << std::endl;

			novice.signForm(form);
			gardener.signForm(form);

			novice.executeForm(form);
			gardener.executeForm(form);
			
			// Verificar se o arquivo foi criado
			std::ifstream file("home_shrubbery");
			if (file.good()) {
				std::cout << "File was created!!" << std::endl;
			} else {
				std::cout << "Error: file was not created" << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << "Erro: " << e.what() << std::endl;
		}
	}
	printTestHeader("Test 01. RobotomyRequestForm");
	{
		//SEVERANCE FLOOR!
		Bureaucrat Irving("Irving", 100);
		Bureaucrat Mark("Mark", 1);
		Bureaucrat Dylan("Dylan", 42);
		Bureaucrat Helly("Helly", 55);

		RobotomyRequestForm form("TopSecret");

		//show form
		std::cout << form << std::endl;

		//trying to sign form
		Irving.signForm(form); //no
		Mark.signForm(form); //yes
		Dylan.signForm(form); //yes
		Helly.signForm(form); //yes
		
		//make irving great to sign
		for (int i = 0; i < 99; i++)
			Irving.incrementGrade();

		//new irving grade
		std::cout << Irving << std::endl;

		//try to sign
		Irving.signForm(form);

		std::cout << std::endl;
		//Execute Form
		Irving.executeForm(form);
		Mark.executeForm(form);
		Dylan.executeForm(form);
		Helly.executeForm(form);
	}
	printTestHeader("Test 02. PresidentialPardonForm");
	{
		Bureaucrat Irving("Irving", 100);
		Bureaucrat Mark("Mark", 1);
		Bureaucrat Dylan("Dylan", 42);
		Bureaucrat Helly("Helly", 55);

		PresidentialPardonForm form("TopSecret");
		
		//show form
		std::cout << form << std::endl;

		//trying to sign form
		Irving.signForm(form); //no
		Mark.signForm(form); //yes
		Dylan.signForm(form); //no
		Helly.signForm(form); //no
		
		//make irving great to sign
		for (int i = 0; i < 99; i++)
			Irving.incrementGrade();

		//new irving grade
		std::cout << Irving << std::endl;

		//try to sign
		Irving.signForm(form);

		std::cout << std::endl;
		//Execute Form
		Irving.executeForm(form);
		Mark.executeForm(form);
		Dylan.executeForm(form);
		Helly.executeForm(form);
	}
	printTestHeader("Test 03. ShrubberyCreationForm - Error Cases");
	{
		try {
			
			Bureaucrat littleBoy("Junior", 146);
			ShrubberyCreationForm form("Forest");

			std::cout << form << std::endl;

			littleBoy.executeForm(form);
			littleBoy.signForm(form);

			Bureaucrat boy("Mid", 138);
			boy.signForm(form);
			boy.executeForm(form);
			
		}
		catch (std::exception const &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

