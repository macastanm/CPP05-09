/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:59:51 by macastan          #+#    #+#             */
/*   Updated: 2024/04/18 11:59:53 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	thisData;
	thisData.strData = "This data has data members";

	std::cout << "This is the data adress: " << &thisData << std::endl;
	std::cout << "This is the data member: " << thisData.strData << std::endl;
	std::cout << "Let's serialize the data" << std::endl;
	uintptr_t	serialized = Serializer::serialize(&thisData);
	std::cout << "This is the serialize data adress: " << serialized << std::endl;
	std::cout << "Now deserialize the data" << std::endl;
	Data*	deserialized = Serializer::deserialize(serialized);
	std::cout << "This is the deserialize data adress: " << deserialized << std::endl;
	std::cout << "This is the deserialize data member: " << deserialized->strData << std::endl;
	std::cout << "Testes ended" << std::endl;
}
