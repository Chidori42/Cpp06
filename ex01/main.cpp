/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:46:06 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/23 03:00:56 by ael-fagr         ###   ########.fr       */
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

    return str.substr(start, end - start);
}

int main(int ac, char **av)
{
    if (ac == 2){
        ScalarConverter convert;
        std::string str = trim(av[1]);
        convert.setStr(str);
        if (convert.CheckString()
            && convert.CountCharacter('f')
            && convert.CountCharacter('.')
            && convert.CountCharacter('-')
            && convert.CountCharacter('+'))
        {
            convert.SetData();
        }
        else
            convert.ImposibleConvert();
    }
    return (0);
}