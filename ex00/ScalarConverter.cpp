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

std::string ScalarConverter::getCharacter(){
    return (this->character);
}
void ScalarConverter::setCharacter(std::string ch){
    this->character = ch;
}
std::string ScalarConverter::getInteger(){
    return (this->integer);
}
void ScalarConverter::setInteger(std::string in){
    this->integer = in;
}
std::string ScalarConverter::getFloating(){
    return (this->floating);
}
void ScalarConverter::setFloating(std::string fl){
    this->floating = fl;
}
std::string ScalarConverter::getDoubl(){
    return (this->doubl);
}
void ScalarConverter::setDoubl(std::string db){
    this->doubl = db;
}

void ScalarConverter::DisplayData(){
    if (getCharacter() != "impossible" && getCharacter() != "Non displayable")
        std::cout << "char: '" << getCharacter() << "'" << std::endl;
    else
        std::cout << "char: " << getCharacter() << std::endl;
    std::cout << "int: " << getInteger() << std::endl;
    if (getFloating() != "impossible" && getFloating() != "Not valid")
        std::cout << "float: " << getFloating() << "f" << std::endl;
    else
    std::cout << "float: " << getFloating() << std::endl;
    std::cout << "double: " << getDoubl() << std::endl;
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

        setCharacter("impossible");
        setInteger("impossible");
        setFloating(fl);
        setDoubl(db);
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
    
    setCharacter(ssch.str());
    setInteger(ssin.str());
    setFloating(ssfl.str());
    setDoubl(ssdb.str());
}