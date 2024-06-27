#include <exception>

namespace cayley
{
    class InvalidArgumentException : public std::exception
    {
    };

    class OutOfBoundsException : public std::exception
    {
    };

    class OutOfMemoryException : public std::exception
    {
    };

    class NotImplementedException : public std::exception
    {
    };

    class InvalidOperationException : public std::exception
    {
    };
};