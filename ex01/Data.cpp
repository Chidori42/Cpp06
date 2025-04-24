/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:53:41 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/23 23:15:31 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(){

}
Data::~Data(){
    
}
Data::Data(const Data &other){
    setNumber(other.number);
    setLnum(other.lnum);
    setString(other.str);
}
Data &Data::operator=(const Data &other){
    if (this != &other){
        setNumber(other.number);
        setLnum(other.lnum);
        setString(other.str);
    }
    return (*this);
}

void Data::setNumber(int number){
    this->number = number;
}
void Data::setString(std::string str){
    this->str = str;
}
void Data::setLnum(long lnumber){
    this->lnum = lnumber;
}

int Data::getNumber(){
    return (this->number);
}
std::string Data::getString(){
    return (this->str);
}
long Data::getLnum(){
    return (this->lnum);
}