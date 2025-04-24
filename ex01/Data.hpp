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