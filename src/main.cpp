#include "Core/Application.hpp"

#include <iostream>

int main()
{
    try
    {
        auto app = Application{};
        app.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "SmallGameFramework detected an error: " << e.what() << '\n';
        std::cerr << "Due to this error the SmallGameFramework unfortunately needs to terminate." << std::endl;
    }
}
