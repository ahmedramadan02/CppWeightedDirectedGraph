#ifndef MyException_FILE_H
#define MyException_FILE_H

#include <string>
#include <exception>

class MyException : public std::exception {
private:
    int errorCode; 
    std::string errorMsg;
    std::string message;

    void ConstructMessage();

public:
    explicit MyException(int code ,const std::string& msg): 
        errorMsg(msg),errorCode(code) { ConstructMessage(); }

    const char *what() const throw(){ return this->message.c_str(); }

    ~MyException() throw () {}

};

#endif