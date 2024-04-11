/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:34:34 by macastan          #+#    #+#             */
/*   Updated: 2024/04/01 12:34:36 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("undefined"), grade(150)
{
	std::cout << "Bureaucrat: default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	std::cout << "Bureaucrat " << this->name << " has ben created with grade: " << this->grade << std::endl;
	if(_grade < 1)
		throw GradeTooHighException();
	if(_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name)
{
	std::cout << "Copy constructor called" << std::endl;
	this->grade = copy.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		this->grade = src.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << ": default destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const {
	return (this->name);
}

int	Bureaucrat::getGrade() const {
	return (this->grade);
}

void	Bureaucrat::incrementGrade() {
	this->grade--;
	if (this->grade < 1)
	{
		throw GradeTooHighException();
	}
}

void	Bureaucrat::decrementGrade() {
	this->grade++;
	if (this->grade > 150)
	{
		throw GradeTooLowException();
	}
}

void	Bureaucrat::signForm(Form& _form)
{
	try {
		_form.beSigned(*this);
		std::cout << this->name << " signed " << _form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << "  couldn’t sign " << _form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& output, const Bureaucrat& copy) {
	output << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl;
	return (output);
}