#include "Framework/Framework.h"

#include "Utils/Utils.h"
#include <iostream>

int main()
{
    Framework frame;

    frame.Init();

    return frame.Run();
}