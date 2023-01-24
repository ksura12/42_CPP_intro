/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:47:30 by ksura             #+#    #+#             */
/*   Updated: 2023/01/24 14:07:32 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Converter.hpp"

Converter::Converter(char const * userInput) : _UserInput(static_cast<std::string>(userInput))
{
	if (DEBUG)
		std::cout << YELLOW << "[Converter] default constructor called" 
			<< COLOR_DEFAULT << std::endl;
	initConvert();
}

Converter::Converter(Converter const & input) : _UserInput(input._UserInput)
{
	if (DEBUG)
		std::cout << YELLOW << "[Converter] copy constructor called" 
			<< COLOR_DEFAULT << std::endl;
	*this = input;
}

Converter & Converter::operator=(Converter const & input)
{
	if (DEBUG)
		std::cout << YELLOW << "[Converter] assignmet constructor called" 
			<< COLOR_DEFAULT << std::endl;
	(void) input;
	return (*this);
}

Converter::~Converter(void)
{
	if (DEBUG)
		std::cout << YELLOW << "[Converter] deconstructor called" 
			<< COLOR_DEFAULT << std::endl;
}

void	Converter::initConvert(void)
{
	_type = -2;
	_myChar = ' ';
	_myInt = 0;
	_myFloat = 0.0f;
	_myDouble = 0.0;
	_precision = 1;
	_charOverflow	= false;
	_intOverflow	= false;
	_floatOverflow	= false;
	_doubleOverflow	= false;
	_specialType	= false;
}

void	Converter::convert()
{
	_type = getDataType();
	long int	tmpLongInt;

	switch (_type)
	{
	case TYPE_CHAR:
		_typeAsString = "char\n";
		_myChar = _UserInput[0];
		_myInt = static_cast<int>(_myChar);
		_myDouble = static_cast<double>(_myChar);
		_myFloat = static_cast<float>(_myChar);
		break;
	case TYPE_INT:
		_typeAsString = "int\n";
		tmpLongInt = atol(_UserInput.c_str());
		if (_UserInput.length() > 11 || tmpLongInt > std::numeric_limits<int>::max() || tmpLongInt < std::numeric_limits<int>::min())
		{
			_charOverflow = true;
			_intOverflow = true;
			_floatOverflow = true;
			_doubleOverflow = true;
		}
		if (tmpLongInt > std::numeric_limits<char>::max() || tmpLongInt < std::numeric_limits<char>::min())
			_charOverflow = true;
		_myInt = atoi(_UserInput.c_str());
		_myChar = static_cast<char>(_myInt);
		_myFloat = static_cast<float>(_myInt);
		_myDouble = static_cast<double>(_myInt);
		break;
	case TYPE_FLOAT:
		_typeAsString = "float\n";
		_myFloat = static_cast<float>(std::strtod(_UserInput.c_str(), NULL));
		if (errno == ERANGE)
		{
			_charOverflow = true;
			_intOverflow = true;
			_floatOverflow = true;
		}
		tmpLongInt = static_cast<long>(_myFloat);
		if (_UserInput.length() > 11 || tmpLongInt > std::numeric_limits<int>::max() || tmpLongInt < std::numeric_limits<int>::min())
			_intOverflow = true;
		if (tmpLongInt > std::numeric_limits<char>::max() || tmpLongInt < std::numeric_limits<char>::min())
			_charOverflow = true;
		_myChar = static_cast<char>(_myFloat);
		_myInt = static_cast<int>(_myFloat);
		_myDouble = static_cast<double>(_myFloat);
		break;
	case TYPE_DOUBLE:
		_typeAsString = "double\n";
		_myDouble = std::strtod(_UserInput.c_str(), NULL);
		if (errno == ERANGE)
		{
			_charOverflow = true;
			_intOverflow = true;
			_floatOverflow = true;
			_doubleOverflow = true;
			break;
		}
		tmpLongInt = static_cast<long>(_myDouble);
		if (_UserInput.length() > 11 || tmpLongInt > std::numeric_limits<int>::max() || tmpLongInt < std::numeric_limits<int>::min())
			_intOverflow = true;
		if (tmpLongInt > std::numeric_limits<char>::max() || tmpLongInt < std::numeric_limits<char>::min())
			_charOverflow = true;
		_myFloat = static_cast<float>(_myDouble);
		_myChar = static_cast<char>(_myDouble);
		_myInt = static_cast<int>(_myDouble);
		break;
	case TYPE_INVALID:
		_typeAsString = "invalid type\n";
		break;
	default:
		_typeAsString = "ERROR\n";
		break;
	}
}

int		Converter::getDataType()
{
	if (_UserInput.length() == 0)
		return (TYPE_INVALID);
	if (_UserInput.length() == 1)
	{
		if (isdigit(_UserInput[0]) == true)
			return (TYPE_INT);
		return (TYPE_CHAR);
	}
	if (isInt() == true)
		return (TYPE_INT);
	if (isFloat() == true)
		return (TYPE_FLOAT);
	if (isDouble() == true)
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

bool	Converter::isNumber()
{
	if (_UserInput[0] != '-' && _UserInput[0] != '+' && !isdigit(_UserInput[0]))
		return false;
	bool	point = false;
	int		pointpos = -1;
	for(unsigned long i = 1; _UserInput[i]; i++)
	{
		if (_UserInput[i] == '.')
		{
			if (point == false)
			{
				point = true;
				pointpos = static_cast<int>(i);
			}
			else
				return false;
		}
		else if (isdigit(_UserInput[i]) == false && (_UserInput[i] != 'f'
			|| (_UserInput[i] == 'f' && (_UserInput.length() - 1) > i)))
			return false;
	}
	if (point)
		_precision = static_cast<int>(_UserInput.length()) - pointpos - 1;
	return true;
}

bool	Converter::isInt()
{
	if (_UserInput[0 != '-' && _UserInput[0] != '+' && !isdigit(_UserInput[0])])
		return false;
	for (unsigned long i = 1; _UserInput[i]; i++)
	{
		if (!isdigit(_UserInput[i]))
			return false;
	}
	return true;
}

bool	Converter::isFloat()
{
	std::string const specialType[4] = {"inff", "-inff", "+inff", "nanf"};
	
	for (int i = 0; i < 4; i++)
	{
		if (_UserInput == specialType[i])
		{
			_specialType = true;
			return true;
		}
	}
	if (isNumber() && _UserInput[_UserInput.length() - 1] == 'f')
	{
		if (_precision > 1)
			_precision--;
		return true;
	}
	return false;
}

bool	Converter::isDouble()
{
	std::string const specialType[4] = {"inff", "-inff", "+inff", "nanf"};
	
	for (int i = 0; i < 4; i++)
	{
		if (_UserInput == specialType[i])
		{
			_specialType = true;
			return true;
		}
	}
	if (!isNumber())
		return false;
	return true;
}

void	Converter::getChar(std::ostream & o) const
{
	if (_type == TYPE_INVALID)
	{
		o << RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_specialType == true || _charOverflow == true)
		o << RED << "not possible" << COLOR_DEFAULT;
	else if (!isprint(_myChar))
		o << MAGENTA << "not displayable" << COLOR_DEFAULT;
	else
		o << GREEN << "'" << _myChar << "'" << COLOR_DEFAULT;

}


void	Converter::getInt(std::ostream & o) const
{
	if (_type == TYPE_INVALID)
	{
		o << RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_specialType == true || _intOverflow == true)
		o << RED << "not possible" << COLOR_DEFAULT;
	else
		o << GREEN << _myInt << COLOR_DEFAULT;

}

void	Converter::getFloat(std::ostream & o) const
{
	if (_type == TYPE_INVALID)
	{
		o << RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_floatOverflow == true)
		o << RED << "not possible" << COLOR_DEFAULT;
	else
		o << GREEN << _myFloat << "f" << COLOR_DEFAULT;

}

void	Converter::getDouble(std::ostream & o) const
{
	if (_type == TYPE_INVALID)
	{
		o << RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_doubleOverflow == true)
		o << RED << "not possible" << COLOR_DEFAULT;
	else
		o << GREEN << _myDouble << COLOR_DEFAULT;

}

void	Converter::getTypeString(std::ostream & o) const
{
	if(_specialType == TYPE_INVALID)
	{
		o << RED << _typeAsString << COLOR_DEFAULT;
		return ;
	}
	o << BLUE << _typeAsString << COLOR_DEFAULT;
}

bool	Converter::getSpecialType() const
{
	return (_specialType);
}

int	Converter::getPrecision() const
{
	return (_precision);
}

std::ostream & operator<<(std::ostream & o, Converter const & obj)
{
	o << "type	: "; obj.getTypeString(o);
	if (obj.getSpecialType())
		o << BLUE << ".....special type....\n" << COLOR_DEFAULT;
	
	std::cout << std::fixed << std::setprecision(obj.getPrecision());
	o << "char	: ";		obj.getChar(o);		o << std::endl;
	o << "int	: ";		obj.getInt(o);		o << std::endl;
	o << "float	: ";		obj.getFloat(o);	o << std::endl;
	o << "double	: ";	obj.getDouble(o);	o << std::endl;
	return (o);
}