/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/10 17:25:58 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class	PhoneBook {

	Contact contactlist[8];
	
public:

	int			addcontact(int index);
	void		search(int list);
	std::string	format_contact(std::string str);
	void		all_details(int i);
	// void	exit_book(void);
	PhoneBook(void);
	~PhoneBook(void);

};

#endif
