#include "Application.hpp"

#include <iostream>

int main()
{
    try
    {
        Application app;
        app.run();
    }
    catch(std::exception& e)
    {
        std::cerr << "SmallGameFramework detected an error: " << e.what() << std::endl;
        std::cerr << "Due to this error the SmallGameFramework unfortunately needs to terminate." << std::endl;
    }
}