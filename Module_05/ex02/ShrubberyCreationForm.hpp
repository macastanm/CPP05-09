/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:12:31 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:12:32 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

class	ShrubberyCreationForm : public AForm
{
private:
	std::string	target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _name);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();

	std::string	getTarget() const;
	void	execute(Bureaucrat const & _executor) const;

};

#endif
