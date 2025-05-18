/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:51:37 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/05/17 19:51:39 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data{
    private:
        int number;
        std::string str;
        long lnum;
    public:
        Data();
        ~Data();
        Data(const Data &other);
        Data &operator=(const Data &other);

        void setNumber(int number);
        void setString(std::string str);
        void setLnum(long lnumber);

        int getNumber();
        std::string getString();
        long getLnum();
};

#endif