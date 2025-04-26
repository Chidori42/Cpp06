/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:16:04 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/26 09:36:07 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){

}
ScalarConverter::~ScalarConverter(){
    
}
ScalarConverter::ScalarConverter(ScalarConverter const &other){
    setStr(other.str);
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other){
    if (this != &other)
    {
        setStr(other.str);
    }
    return (*this);
}
std::string ScalarConverter::intToString(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();
}
std::string ScalarConverter::intToString(float value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();
}
std::string ScalarConverter::intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}
std::string ScalarConverter::getStr(){
    return (this->str);
}
void ScalarConverter::setStr(std::string str){
    this->str = str;
}

void ScalarConverter::DisplayData(std::string ch, std::string in, std::string fl, std::string db){
    std::cout << "char: " << ch << std::endl;
    std::cout << "int: " << in << std::endl;
    std::cout << "float: " << fl << "f" << std::endl;
    std::cout << "double: " << db << std::endl;
}

void ScalarConverter::ImposibleConvert(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
bool ScalarConverter::CountCharacter(char ch){
    int counter = 0;
    for (size_t i = 0; i < getStr().length(); i++){
        if (getStr()[i] == ch)
            counter++;
    }
    if (counter > 1)
        return (false);
    return (true);
}
bool ScalarConverter::HandlePseudoLiterals(){
    std::string tab[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
    bool check = false;

    for (size_t i = 0; i < 6; i++){
        if (getStr() == tab[i]){
            check = true;
            break;
        }
    }
    if (check)
    {
        std::string fl = getStr();
        std::string db = getStr();
        if ((getStr()[0] == '+' || getStr()[0] == '-') && getStr()[4] == 'f')
        {
            fl = fl.substr(0, 4);
            db = db.substr(0, 4);
        }
        else if (getStr()[3] == 'f'){
            fl = fl.substr(0, 3);
            db = db.substr(0, 3);
        }
        DisplayData("impossible", "impossible", fl, db);
        return (true);
    }
    return (false);
}
bool ScalarConverter::CheckString(){
    for (size_t i = 0; i < getStr().length(); i++){
        if (!isdigit(getStr()[i]) && getStr()[i] != '.' && getStr()[i] != 'f'
            && getStr()[i] != '-' && getStr()[i] != '+')
            return (false);
        else if (getStr()[i] == 'f' && getStr()[i + 1] != '\0')
            return (false);
        else if ((getStr()[i] == '-' || getStr()[i] == '+') && i != 0)
            return (false);
    }
    return (true);
}
void ScalarConverter::SetData(){
    errno = 0;
    std::stringstream ssch;
    std::stringstream ssin;
    std::stringstream ssfl;
    std::stringstream ssdb;
    char ch;

    double number = std::strtod(getStr().c_str(), NULL);
    ch = static_cast<char>(number);
    if (std::isprint(ch)) {
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