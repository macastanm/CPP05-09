/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:18:06 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:18:07 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <iterator>
# include <fstream>
# include <string>
# include <cstdlib>

class	BitcoinExchange
{
private:
	std::string	fileName;
	std::map<std::string, float>	dataCSV;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange	&operator=(const BitcoinExchange& src);
	~BitcoinExchange();
	BitcoinExchange(std::string _fileName);

	void	organizeDataBase();
	class errorFileOpen : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Something is wrong with the file");}
	};
	void	organizeDataFile();
	class errorFileEmpty : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("This file is empty");}
	};
	class errorFileWrong : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("The file is wrong");}
	};
	int	checkLine(std::string line);
	int	checkData(std::string dataToCheck);
	int	checkValue(std::string valueToCheck);
	int	checkYear(std::string yearToCheck);
	int	checkMonth(std::string monthToCheck);
	int	checkDay(std::string dayToCheck, int month, int year);
	bool	leapYear(int year);
	void	searchOutput(std::string data, float value);
};

#endif