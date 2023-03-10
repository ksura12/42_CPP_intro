/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura@student.42wolfsburg.de <ksura@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:29 by ksura             #+#    #+#             */
/*   Updated: 2023/01/11 17:30:07 by ksura@student.42 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <string>

class	Contact
{

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;

	public:
		void		set_contactdetails(void);
		std::string	get_contactdetails(int i);
		void		enter_first_name(void);
		void		enter_last_name(void);
		void		enter_nickname(void);
		void		enter_phone(void);
		void		enter_secret(void);
		Contact(void);
		~Contact(void);

};

#endif
