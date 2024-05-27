/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:18:00 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:18:02 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : fileName(0) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : fileName(copy.fileName), dataCSV(copy.dataCSV) {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src)
	{
		fileName = src.fileName;
		dataCSV.clear();
		dataCSV = src.dataCSV;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string _fileName) : fileName(_fileName) {}

void	BitcoinExchange::organizeDataBase() {
	std::ifstream	dataOG;
	std::string		dataLine;
	size_t			i = 0;
	std::string		data;
	std::string		exchangeStr;
	float			exchange;

	dataOG.open("data.csv");
	if (!dataOG.is_open())
	{
		std::cout << "data.csv: ";
		throw errorFileOpen();
	}
	while (std::getline(dataOG, dataLine))
	{
		i = dataLine.find(",");
		data = dataLine.substr(0, i);
		exchangeStr = dataLine.substr(i + 1, dataLine.size());
		exchange = std::atof(exchangeStr.c_str());
		dataCSV[data] = exchange;
	}
	dataCSV.erase("date");
	dataOG.close();
	/*std::map<std::string, float>::iterator it = dataCSV.begin();
	while (it != dataCSV.end())
	{
		std::cout << it->first << " and " << it->second << std::endl;
		it++;
	}
	std::cout << std::endl << fileName << std::endl;*/
}

void	BitcoinExchange::organizeDataFile() {
	std::ifstream	fileOG;
	std::string		fileLine;

	fileOG.open(fileName.c_str());
	if (!fileOG.is_open())
	{
		std::cout << fileName << ": ";
		throw errorFileOpen();
	}
	if (!std::getline(fileOG, fileLine))
	{
		std::cout << fileName << ": ";
		throw errorFileEmpty();
	}
	if (fileLine != "date | value")
	{
		std::cout << fileName << ": ";
		throw errorFileWrong();
	}
	while (std::getline(fileOG, fileLine))
	{
		printResult(fileLine);
	}
}

int	BitcoinExchange::printResult(std::string line) {
	if (line.size() < 14 || line.find("|") == std::string::npos)
	{
		std::cout << "Error: bad input => " << line;
		if (line.size() == 0)
			std::cout << "Empty line";
		std::cout  << std::endl;
		return (1);
	}
	size_t	i = 0;
	i = line.find("|");

	std::string	tempData;
	tempData = line.substr(0, i - 1);
	if (checkData(tempData) == 1)
	{
		return (1);
	}

	std::string	tempValue;
	tempValue = line.substr(i + 2, line.size());
	for (size_t j = 0; j < tempValue.size(); j++)
	{
		if (!isdigit(tempValue[j]) && tempValue[j] != '-')
		{
			std::cout << "Error: bad value input => " << tempValue << std::endl;
			return (1);
		}
	}
	float		value;
	value = std::atof(tempValue.c_str());
	if (value < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return (1);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number" << std::endl;
		return (1);
	}
	std::cout << line << std::endl;
	return (0);
}

int	BitcoinExchange::checkData(std::string dataToCheck) {
	if (dataToCheck.find("-") == std::string::npos || dataToCheck.size() != 10)
	{
		std::cout << "Error: bad data input => " << dataToCheck << std::endl;
		return (1);
	}
	for (size_t i = 0; i < dataToCheck.size(); i++)
	{
		if (!isdigit(dataToCheck[i]) && dataToCheck[i] != '-')
		{
			std::cout << "Error: bad data input => " << dataToCheck << std::endl;
			return (1);
		}
	}
	std::string	yearStr;
	std::string	monthStr;
	std::string	dayStr;
	int			year;
	int			month;
	yearStr = dataToCheck.substr(0, 4);
	monthStr = dataToCheck.substr(5, 2);
	dayStr = dataToCheck.substr(8, 2);
	if (checkYear(yearStr) == -1)
	{
		std::cout << "Error: bad year => " << yearStr << std::endl;
		return (1);
	}
	else
		year = checkYear(yearStr);
	if (checkMonth(monthStr) == -1)
	{
		std::cout << "Error: bad month => " << monthStr << std::endl;
		return (1);
	}
	else
		month = checkMonth(monthStr);
	if (checkDay(dayStr, month, year) == -1)
	{
		std::cout << "Error: bad day => " << dayStr << std::endl;
		return (1);
	}
	return (0);
}

int	BitcoinExchange::checkYear(std::string yearToCheck) {
	int	year = std::atoi(yearToCheck.c_str());

	if (year < 2009 || year > 2022)
	{
		return (-1);
	}
	return (year);
}

int	BitcoinExchange::checkMonth(std::string monthToCheck) {
	int	month = std::atoi(monthToCheck.c_str());

	if (month < 1 || month > 12)
	{
		return (-1);
	}
	return (month);
}

int	BitcoinExchange::checkDay(std::string dayToCheck, int month, int year) {
	int	day = std::atoi(dayToCheck.c_str());

	if (month == 2)
	{
		if (leapYear(year) == true && (day < 1 || day > 29))
			return (-1);
		else if (day < 1 || day > 28)
			return (-1);
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
		return (-1);
	else if (day < 1 || day > 31)
		return (-1);
	return (0);
}

bool	BitcoinExchange::leapYear(int year) {
	if (year == 2012 || year == 2016 || year == 2020)
		return (true);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return(true);
	return (false);
}