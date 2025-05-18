/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:16:04 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/05/18 21:33:39 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool is_char= false;
bool is_int = false;
bool is_float = false;
bool is_double = false;

std::stringstream ssch;
std::stringstream ssin;
std::stringstream ssfl;
std::stringstream ssdb;

ScalarConverter::ScalarConverter(){

}
ScalarConverter::~ScalarConverter(){
    
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void)other;
    return(*this);
}

void DisplayData(std::string ch, std::string in, std::string fl, std::string db){
    if (ch != "impossible" && ch != "Non displayable")
        std::cout << "char: '" << ch << "'" << std::endl;
    else
        std::cout << "char: " << ch << std::endl;
    std::cout << "int: " << in << std::endl;
    if (fl != "impossible")
        std::cout << "float: " << fl << "f" << std::endl;
    else
        std::cout << "float: " << fl << std::endl;
    std::cout << "double: " << db << std::endl;
}

bool is_sign(char c){
    return (c == '-' || c == '+');
}

bool HandlePseudoLiterals(double number){
    if (isnan(number) || isinf(number)){
        return (true);
    }
    return (false);
}

void detectRealType(std::string str){
    if (str.find('f') != std::string::npos){
        is_float = true;
    }else if (str.find('.') != std::string::npos){
        is_double = true;
    }else if (str.length() == 1 && !isdigit(str[0])){
        is_char = true;
    }
    else{
        is_int = true;
    }
}

void convetRealType(std::string str){
    char *endp;
    double number = std::strtod(str.c_str(), &endp);

    if (strlen(endp) > 1)
        throw "Error\nInvalid input";
    else if (endp[0] != '\0' && endp[0] != 'f')
        throw "Error\nInvalid input";
    bool isPseudo = HandlePseudoLiterals(number);
    if (is_float || isPseudo){
        float realnum = number;
        if (realnum > 127 || realnum < -128 || isPseudo)
            ssch << "impossible";
        else if (!isprint(realnum))
            ssch << "Non displayable";
        else
            ssch << static_cast<char>(realnum);
        if (number > INT_MAX || number < INT_MIN || isPseudo)
            ssin << "impossible";
        else
            ssin << static_cast<int>(number);
        ssfl << std::fixed << std::setprecision(1) << static_cast<float>(realnum);
        ssdb << std::fixed << std::setprecision(1) << static_cast<double>(realnum);
    }else if (is_double || isPseudo){
        double realnum = number;
        if (realnum > 127 || realnum < -128 || isPseudo)
            ssch << "impossible";
        else if (!isprint(realnum))
            ssch << "Non displayable";
        else
            ssch << static_cast<char>(realnum);
        
        if (number > INT_MAX || number < INT_MIN || isPseudo)
            ssin << "impossible";
        else 
            ssin << static_cast<int>(realnum);
        ssfl << std::fixed << std::setprecision(1) << static_cast<float>(realnum);
        ssdb << std::fixed << std::setprecision(1) << static_cast<double>(realnum);
    }else{
        int realnum = number;
        if (realnum > 127 || realnum < -128)
            ssch << "impossible";
        else if (!isprint(realnum))
            ssch << "Non displayable";
        else
            ssch << static_cast<char>(realnum);

        if (number > INT_MAX || number < INT_MIN){
            ssin << "impossible";
            ssfl << "impossible";
            ssdb << "impossible";
        }
        else{
            ssin << static_cast<int>(realnum);
            ssfl << std::fixed << std::setprecision(1) << static_cast<float>(realnum);
            ssdb << std::fixed << std::setprecision(1) << static_cast<double>(realnum);
        }
    }
}

void setData(std::string str){
    if (str.length() == 1 && !isdigit(str[0])){
        ssch << static_cast<char>(str[0]);
        ssin << static_cast<int>(str[0]);
        ssfl << std::fixed << std::setprecision(1) << static_cast<float>(str[0]);
        ssdb << std::fixed << std::setprecision(1) << static_cast<double>(str[0]);
    }
    else{
        convetRealType(str);
    }
}
void ScalarConverter::convert(std::string str){

    if (str.empty())
        throw "Error\nEmpty input";
    else{
        detectRealType(str);
        setData(str);
        DisplayData(ssch.str(), ssin.str(), ssfl.str(), ssdb.str());
    }
}