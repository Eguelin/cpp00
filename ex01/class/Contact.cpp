/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:25 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/22 14:17:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Contact::Contact( void )
{
	std::cout << BLACK << "Contact constructor called" << RESET_TEXT << std::endl;

	return ;
}

Contact::~Contact( void )
{
	std::cout << BLACK << "Contact destructor called" << RESET_TEXT << std::endl;

	return ;
}

/* ************************************************************************** */
/*                              Getters & Settres                             */
/* ************************************************************************** */

const std::string	&Contact::get_first_name( void ) const {return(this->_first_name);}

const std::string	&Contact::get_last_name( void ) const {return(this->_last_name);}

const std::string	&Contact::get_nickname( void ) const {return(this->_nickname);}

const std::string	&Contact::get_phone_number( void ) const {return(this->_phone_number);}

const std::string	&Contact::get_darkest_secret( void ) const {return(this->_darkest_secret);}

void	Contact::set_first_name( const std::string str ) {this->_first_name = str;}

void	Contact::set_last_name( const std::string str ) {this->_last_name = str;}

void	Contact::set_nickname( const std::string str ) {this->_nickname = str;}

void	Contact::set_phone_number( const std::string str ) {this->_phone_number = str;}

void	Contact::set_darkest_secret( const std::string str ) {this->_darkest_secret = str;}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

const std::string	Contact::ft_prompt( int data ) const
{
	const std::string prompt[] = {"First name: ",
								"Last name: ",
								"Nickname: ",
								"Phone number: ",
								"Darkest secret: "};

	if (data < FIRST_NAME || data > DARKEST_SECRET)
	{
		std::cerr << RED << "Invalid data" << RESET_TEXT << std::endl;

		return ("");
	}

	return (prompt[data]);
}
