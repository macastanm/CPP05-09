/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:12:35 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:12:37 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("undefined")
{
	std::cout << "ShrubberyCreationForm: default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) : AForm("ShrubberyCreationForm", 145, 137), target(_name)
{
	std::cout << "ShrubberyCreationForm " << this->target << " has ben created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	std::cout << "ShrubberyCreationForm " << this->target << " copy constructor called" << std::endl;
	this->target = copy.target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		this->target = src.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->target << " default destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat & _executor) const
{
	if (_executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	if (getSignature() == 0)
		throw NotSigned();
	std::string	fileName = target + "_shrubbery";
	std::ofstream	file;
	file.open(fileName.c_str());
	if (!file.is_open())
	{
		std::cout << "Something is wrong with the file creation." << std::endl;
	}
	else
	{
		file << " └── Have/" << std::endl;
		file << "    ├── a/" << std::endl;
		file << "    │   └── nice/" << std::endl;
		file << "    │       └── day/" << std::endl;
		file << "    │           └── :)" << std::endl;
		file << "    └── Hope everything is good/" << std::endl;
		file << "        ├── and/" << std::endl;
		file << "        │   ├── all" << std::endl;
		file << "        │   ├── your" << std::endl;
		file << "        │   ├── dreams" << std::endl;
		file << "        │   └── come true." << std::endl;
		file << "        └── See/" << std::endl;
		file << "            └── You/" << std::endl;
		file << "                ├── soon" << std::endl;
		file << "                └── bye!" << std::endl;
	}
	file.close();
}