#include "game.h"
#include <bits/stdc++.h>

int main()
{
    Game game;
    while (game.isRunning())
    {

        // Update
        game.update();
        // Render
        game.render();
    }

    return 0;
}