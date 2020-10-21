#include "MyException.hpp"

void MyException::ConstructMessage()
{
    message = std::to_string(errorCode) + " " + errorMsg;
}