/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:16:04 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/26 12:47:16 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

std::string intToString(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();
}
std::string intToString(float value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();
}
std::string intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void DisplayData(std::string ch, std::string in, std::string fl, std::string db){
    if (ch != "impossible" && ch != "Non displayable" && ch != "Not valid")
        std::cout << "char: '" << ch << "'" << std::endl;
    else
        std::cout << "char: " << ch << std::endl;
    std::cout << "int: " << in << std::endl;
    if (fl != "impossible" && fl != "Not valid")
        std::cout << "float: " << fl << "f" << std::endl;
    else
        std::cout << "float: " << fl << std::endl;
    std::cout << "double: " << db << std::endl;
}

bool CountCharacter(std::string str, char ch){
    int counter = 0;
    for (size_t i = 0; i < str.length(); i++){
        if (str[i] == ch)
            counter++;
    }
    if (counter > 1)
        return (false);
    return (true);
}

bool is_sign(char c){
    return (c == '-' || c == '+');
}

bool HandlePseudoLiterals(std::string str){
    std::string tab[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
    bool check = false;

    for (size_t i = 0; i < 6; i++){
        if (str == tab[i]){
            check = true;
            break;
        }
    }
    if (check)
    {
        std::string fl = str;
        std::string db = str;
        if (is_sign(str[0]) && str[4] == 'f')
        {
            fl = fl.substr(0, 4);
            db = db.substr(0, 4);
        }
        DisplayData("impossible", "impossible", fl, db);
        return (true);
    }
    return (false);
}

bool CheckString(std::string str){
    for (size_t i = 0; i < str.length(); i++){
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f'
        && !is_sign(str[i]))
            return (false);
        else if ((str[i] == 'f' && str[i + 1] != '\0')
            || (str[i] == 'f' && !isdigit(str[i - 1]) && str[i - 1] != '.'))
            return (false);
        else if ((is_sign(str[i]) && i != 0) 
                || (is_sign(str[i]) && !isdigit(str[i + 1]) && str[i + 1] != '.'))
            return (false);
    }
    return (true);
}

bool parser(std::string str){
    if (HandlePseudoLiterals(str)){
        return (false);
    }
    else if (str.length() == 1
        && isprint(str[0])
        && !isdigit(str[0])){
        DisplayData(str, "impossible", "impossible", "impossible");
        return (false);
    }
    else if (CheckString(str)
        && CountCharacter(str, 'f')
        && CountCharacter(str, '.')
        && CountCharacter(str, '-')
        && CountCharacter(str, '+')){
        return (true);
    }
    else{
        DisplayData("impossible", "impossible", "impossible", "impossible");
        return (false);
    }
}
void ScalarConverter::convert(std::string str){
    errno = 0;
    std::stringstream ssch;
    std::stringstream ssin;
    std::stringstream ssfl;
    std::stringstream ssdb;
    char ch;

    if (!parser(str))
        return ; 
    double number = std::strtod(str.c_str(), NULL);
    ch = static_cast<char>(number);
    if (number < -128 || number > 127)
        ssch << "Not valid";
    else if (std::isprint(ch)) {
        ssch << ch;
    } else {
        ssch << "Non displayable";
    }
    if (errno || number > INT_MAX || number < INT_MIN)
        ssin << "Not valid";
    else
        ssin << intToString(static_cast<int>(number));
    if (errno || number > FLT_MAX || number < -FLT_MAX)
        ssfl << "Not valid";
    else
        ssfl << intToString(static_cast<float>(number));
    if(errno || number > DBL_MAX || number < -DBL_MAX)
        ssdb << "Not valid";
    else
        ssdb << intToString(static_cast<double>(number));
    
    DisplayData(ssch.str(), ssin.str(), ssfl.str(), ssdb.str());
}