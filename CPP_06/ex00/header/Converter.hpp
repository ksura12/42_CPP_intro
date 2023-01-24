/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/24 13:58:47 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_CLASS_HPP
# define CONVERTER_CLASS_HPP

# include <iostream>
# include <iomanip> 
# include <limits>
# include <cstdlib>
# include <cerrno>
#include "colors.h"


typedef enum e_type {
	TYPE_INVALID = -1,
	TYPE_CHAR = 0,
	TYPE_INT = 1,
	TYPE_FLOAT = 2,
	TYPE_DOUBLE = 3
}			t_type;

class	Converter
{

		
	public:
		Converter(char const *);
		Converter(Converter const & input);
		Converter & operator=(Converter const & input);
		~Converter(void);

		int					getDataType();
		void				getTypeString(std::ostream & o) const;
		bool				getSpecialType() const;
		int					getPrecision() const;
		void				getChar(std::ostream & o) const;
		void				getInt(std::ostream & o) const;
		void				getFloat(std::ostream & o) const;
		void				getDouble(std::ostream & o) const;
		void				convert();
		
	private:
		std::string const	_UserInput;
		char				_myChar;
		int					_myInt;
		float				_myFloat;
		double				_myDouble;
		int					_precision;
		bool				_charOverflow;
		bool				_intOverflow;
		bool				_floatOverflow;
		bool				_doubleOverflow;
		int				_specialType;

		
		bool				isNumber();
		bool				isInt();
		bool				isFloat();
		bool				isDouble();
		void				initConvert();
		int					_type;
		std::string			_typeAsString;


};

std::ostream & operator<<(std::ostream & o, Converter const & obj);

#endif