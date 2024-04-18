/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:00:09 by macastan          #+#    #+#             */
/*   Updated: 2024/04/18 12:00:11 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <ctype.h>
# include <limits>
# include <stdlib.h>
# include <stdint.h>

struct	Data
{
	std::string	strData;
};

class	Serializer
{
private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer &operator=(const Serializer& src);
	~Serializer();

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif