/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:13:11 by macastan          #+#    #+#             */
/*   Updated: 2024/04/04 16:13:13 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	std::string	target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _name);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& src);
	~PresidentialPardonForm();

	std::string	getTarget() const;
	void	execute(Bureaucrat const & _executor) const;

};

#endif
