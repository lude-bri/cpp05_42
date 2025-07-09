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
#include "../inc/Intern.hpp"

void	printTestHeader(const std::string &testName) {
	std::cout << "\n";
	std::cout << YELLOW << "= " << testName << " =" << RESET << std::endl;
	std::cout << "\n";
}

int main(void) {

	printTestHeader("Test 00. Main's subject");
	{
		Intern someRandomIntern;
		AForm *rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	printTestHeader("Test 01. All form types");
    {
        Intern		intern;
        Bureaucrat	boss("Boss", 1);

        AForm* forms[3];
	
        forms[0] = intern.makeForm("shrubbery creation", "home");
        forms[1] = intern.makeForm("robotomy request", "Bender");
        forms[2] = intern.makeForm("presidential pardon", "Alice");

        for (int i = 0; i < 3; i++) {
            if (forms[i]) {
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                delete forms[i];
            }
        }
    }
    printTestHeader("Test 02. Invalid forms");
    {
        Intern intern;
        AForm* invalid;

        const std::string testCases[6] = {
            "",
            "unknown",
            "creation",
            "SHrubbery CREATION",
            "robotomy",
            "presidential"
        };

        for (size_t i = 0; i < 6; i++) {
            invalid = intern.makeForm(testCases[i], "target");
            if (invalid) {
                std::cout << "ERROR: Should not have created " << testCases[i] << std::endl;
                delete invalid;
            }
        }
    }
	printTestHeader("Test 03. Copy Intern");
    {
        Intern original;
       
		//test copy constructor
		Intern copy(original); 
        
		//test assignment operator
		Intern assigned;
        assigned = original;

        AForm* form1 = original.makeForm("shrubbery creation", "original");
        AForm* form2 = copy.makeForm("robotomy request", "copy");
        AForm* form3 = assigned.makeForm("presidential pardon", "assigned");

        if (form1) delete form1;
        if (form2) delete form2;
        if (form3) delete form3;
    }
    return 0;
}
