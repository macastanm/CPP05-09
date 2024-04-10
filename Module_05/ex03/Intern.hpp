/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:15:00 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:15:01 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	Intern &operator=(const Intern& src);
	~Intern();

	AForm	*makeForm(std::string _formName, std::string _targetName);
	AForm	*makeShrubberyCreation(std::string _target);
	AForm	*makeRobotomyRequest(std::string _target);
	AForm	*makePresidentialPardon(std::string _target);

	class NotFound : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("This form does not exists");}
	};
};

#endif
