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

			// Tentativa de assinatura com grau insuficiente
			novice.signForm(form);

			// Assinatura válida
			gardener.signForm(form);

			// Execução com grau insuficiente
			novice.executeForm(form);

			// Execução válida
			gardener.executeForm(form);

			// Criar o arquivo
			form.action();

			// Verificar se o arquivo foi criado
			std::ifstream file("home_shrubbery");
			if (file.good()) {
				std::cout << "Arquivo criado com sucesso!" << std::endl;
			} else {
				std::cout << "Erro: arquivo não criado!" << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << "Erro: " << e.what() << std::endl;
		}
	}
	// printTestHeader("Test 01. ");
	// printTestHeader("Test 02. ");
	// printTestHeader("Test 03. ");
	// printTestHeader("Test 04. ");
}

