/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:10:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/26 11:19:36 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <string>
#include <cctype>
#include <iomanip>
#include <climits>
#include <float.h>
#include <cmath>
// #include <limits.h>
#include <cerrno>
#include <sstream>
#include <iostream>

class ScalarConverter{
    private:
        std::string str;
        std::string character;
        std::string integer;
        std::string floating;
        std::string doubl;
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &other);

        ScalarConverter &operator=(ScalarConverter const &other);
        std::string getStr();
        void setStr(std::string str);
        std::string getCharacter();
        void setCharacter(std::string ch);
        std::string getInteger();
        void setInteger(std::string in);
        std::string getFloating();
        void setFloating(std::string fl);
        std::string getDoubl();
        void setDoubl(std::string db);

        std::string intToString(double value);
        std::string intToString(float value);
        std::string intToString(int value);
    
        void SetData();
        bool CheckString();
        bool CountCharacter(char ch);
        bool HandlePseudoLiterals();
        void DisplayData();
};

#endif