/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:46:06 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/05/17 16:50:03 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string trim(const std::string& str){
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start])) {
        ++start;
    }

    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }

    return (str.substr(start, end - start));
}

int main(int ac, char **av)
{
    try{
        if (ac != 2)
            throw "Error\nInvalide number of parameters";
        std::string str = av[1];
        if (str.length() > 1)
            str = trim(av[1]);
        ScalarConverter::convert(str);
    }catch (const char *str){
        std::cout << str << std::endl;
    }
    return (0);
}