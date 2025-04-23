/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:10:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/23 02:59:56 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cerrno>
#include <sstream>
#include <iostream>

class ScalarConverter{
    private:
        std::string str;
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &other);

        ScalarConverter &operator=(ScalarConverter const &other);
        std::string getStr();
        void setStr(std::string str);

        void SetData();
        bool CheckString();
        bool CountCharacter(char ch);
        void ImposibleConvert();
        void DisplayData(std::string ch, std::string in, std::string fl, std::string db);
};

#endif