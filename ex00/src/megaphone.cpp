/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:03:59 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/22 14:56:11 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	ft_str_to_upper( std::string str );

int main( int argc, const char **argv )
{
	for (size_t i = 1; argv[i]; i++)
		std::cout << ft_str_to_upper(argv[i]);

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << std::endl;

	return (0);
}

std::string	ft_str_to_upper( std::string str )
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		*it = std::toupper(*it);

	return (str);
}
