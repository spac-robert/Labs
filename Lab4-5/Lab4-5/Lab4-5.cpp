#include <iostream>
#include "Repo.h"
#include "Test.h"
#include "UI.h"
using namespace std;

int main()
{
    tests();
    UI ui;
    ui.run();
    return 0;
}
