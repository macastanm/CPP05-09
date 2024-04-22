/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:31:44 by macastan          #+#    #+#             */
/*   Updated: 2024/04/18 17:31:45 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <ctype.h>
# include <limits>
# include <stdlib.h>
# include <stdint.h>

class	Base
{
public:
	virtual	~Base();
};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif