/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:10:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/19 19:43:17 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &other);

        ScalarConverter &operator=(ScalarConverter const &other);
        // bool IsFloat(std::string str);
        // bool IsDouble(std::string str);
        // bool IsInt(std::string str);
        // bool IsChar(std::string str);
        void ConvertType(std::string str);
};

#endif