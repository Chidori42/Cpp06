/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:16:04 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/21 17:06:16 by ael-fagr         ###   ########.fr       */
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
    std::cout << "float: nonf" << std::endl;
    std::cout << "double: non" << std::endl;
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

    double number = std::atof(getStr().c_str());
    char ch = static_cast<char>(number);
    int in = static_cast<int>(number);
    float fl = static_cast<float>(number);
    double db = static_cast<double>(number);

    std::stringstream ss;
    ss << ch;
    if (!std::isprint(ch))
        DisplayData("Non displayabl", std::to_string(in), std::to_string(fl), std::to_string(db));
    else
        DisplayData(ss.str(), std::to_string(in), std::to_string(fl), std::to_string(db));
}