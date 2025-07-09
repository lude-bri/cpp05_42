/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <lude-bri@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:27:44 by lude-bri          #+#    #+#             */
/*   Updated: 2025/07/08 17:09:10 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

//Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : _isSigned(false), _gradeToSign(145), _gradeToExecute(137) {
	DEBUG_MSG("A Default ShrubberyCreationForm Constructor was called");
}

//Parametric Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
	: _target(target), _isSigned(false), _gradeToSign(145), _gradeToExecute(137) {
	DEBUG_MSG("A Parametric ShrubberyCreationForm Constructor was called");
}

//Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
	: _isSigned(false), _name(copy._name), _target(copy._target),
	_gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign)
{
	DEBUG_MSG("A Copy ShrubberyCreationForm Constructor was called");
}

//Copy Assignment Operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	DEBUG_MSG("A Copy ShrubberyCreationForm Constructor was called");
	if (this != &copy) {
		_isSigned = copy._isSigned;
	}
	return *this;
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	DEBUG_MSG("A Copy ShrubberyCreationForm Constructor was called");
}

//getters
std::string			ShrubberyCreationForm::getName() const {return _name;}
bool				ShrubberyCreationForm::getFormState() const {return _isSigned;}
int					ShrubberyCreationForm::getGradeToSign() const {return _gradeToSign;}
int					ShrubberyCreationForm::getGradeToExecute() const {return _gradeToExecute;}

//Sign
void	ShrubberyCreationForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		GradeTooLowException();
}

//Execute
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {	
	if (!_isSigned)
		FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		GradeTooLowException();
	AForm::execute(executor); // chama as verificações da base
}

void	ShrubberyCreationForm::action() const {
	
	if (_target.empty())
		std::cerr << "Error: There is no valid target" << std::endl;

	std::ofstream file((_target + "_shrubbery").c_str());

	file << GREEN << "    		,@@@@@@@,		" << std::endl;
    file << "  ,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl;
    file << "  ,&%%&%&&%,@@@@@/@@@@@@,8888/88/8o " << std::endl;
	file << " ,%&\"%&&%&&%,@@@\"@@@/@@@88ll88888/88' " << std::endl;
	file << " %&&%&%&/%&&%@@\"@@/ /@@@88888\"88888' " << std::endl;
	file << " %&&%/ %&%%&&@@\" V /@@' `88\"8 `/88' " << std::endl;
	file << " `&%\" ` /%&'    |.|        \" '|8' " << std::endl; 
	file << "     |o|        | |         | | " << std::endl;
    file << "     |.|        | |         | | " << std::endl;
	file << "  \\/ ._l/_/__/  ,l_//__\\/.  l_//_ " << RESET << std::endl;
	file.close();
}

//Operator Overload
std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &f) {
	DEBUG_MSG("A AForm Operator Overload (<<) was called");
	
	out << std::endl;
	out << " -----------------FORM-------------------------- " << std::endl;
	out << "This is the Form " << f.getName() << "'s attributes: " <<  std::endl;
	out << "1. Form's State -> Signed: " << f.getFormState() << std::endl;
	out << "2. Required Grade to Sign: " << f.getGradeToSign() << std::endl;
	out << "3. Required Grade to Execute: " << f.getGradeToExecute() << std::endl;
	out << " --------------------------------------------- " << std::endl;
	return out;
}
