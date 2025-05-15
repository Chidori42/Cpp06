/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:16:04 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/05/15 17:15:23 by ael-fagr         ###   ########.fr       */
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
    return (check);
}

void setData(std::string str, char &ch, int &in, float &fl, double &db){
    errno = 0;
    if (str.length() == 1 && !isdigit(str[0]))
    {
        ch = static_cast<char>(str[0]);
        in = static_cast<int>(ch);
        fl = static_cast<float>(ch);
        db = static_cast<double>(ch);
    }
    else
    {
        char *endp = NULL;
        double number = std::strtod(str.c_str(), &endp);
        if (number > INT_MAX || number < INT_MIN)
            std::cout << "Error Out Of Range" << std::endl;
        else if (endp[0] != '\0' && endp[0] != 'f')
            std::cout << "Error invalid input" << std::endl;
        in = static_cast<int>(number);
        ch = static_cast<char>(number);
        fl = static_cast<float>(number);
        db = static_cast<double>(number);
    }
}
void ScalarConverter::convert(std::string str){
    errno = 0;
    std::stringstream ssch;
    std::stringstream ssin;
    std::stringstream ssfl;
    std::stringstream ssdb;
    char ch;
    int in;
    float fl;
    double db;

    if (str.empty())
        DisplayData("Not valid", "Not valid", "Not valid", "Not valid");
    setData(str, ch, in, fl, db);
    ssch << ch;
    ssin << in;
    ssfl << fl;
    ssdb << db;  
    DisplayData(ssch.str(), ssin.str(), ssfl.str(), ssdb.str());
}