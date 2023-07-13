/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:07:56 by htsang            #+#    #+#             */
/*   Updated: 2023/07/13 16:47:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	toUpper(unsigned char c)
{
	return (static_cast<char>(std::toupper(c)));
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << toUpper(static_cast<unsigned char>(argv[i][j]));
		}
	}
	std::cout << std::endl;
	return 0;
}
