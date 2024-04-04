/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:35:43 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 14:35:45 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Form
{
private:
	std::string	name;
	bool		signature;
	int			gradeSign;
	int			gradeExecute;

public:
	Form();
	Form(std::string _name, bool _sing, int _gradeS, int _gradeE);
	Form(const Form& copy);
	Form &operator=(const Form& src);
	~Form();

	void	beSigned(Bureaucrat& _bureaucrat);
	void	signForm();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Bureaucrat grade is too high");}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Bureaucrat grade is too low");}
	};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& copy);

#endif