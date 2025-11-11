#include <SFML/Graphics.hpp>
#include "../game/quiz.cpp"

int main()
{
    srand(time(NULL));
    window.setSize(Vector2u(w, h));

    Event event;
    while (window.isOpen())
    {
        
        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);

        //vibor rezhima
        if (m1 == 0){ menu(pos); }
        if (m1 == 1) { mode(pos); }
        if (m1 == 2) { player(pos); }
        if (m1 == 3) { Country(pos); }
        if (m1 == 4) { Club(pos); }
        if (m1 == 5) { fonwin(pos); }


        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { window.close(); }
             

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                {
                    
                    //menu
                    if (playsprite.getGlobalBounds().contains(pos.x, pos.y) && (m1 == 0)) { m1 = 1; }
                    if (backsprite.getGlobalBounds().contains(pos.x, pos.y) && (m1 == 1)) { m1 = 0; }
                    if (backsprite.getGlobalBounds().contains(pos.x, pos.y) && ((m1 == 2) || (m1 == 3) || (m1 == 4) || (m1 == 5))) { m1 = 1; Working = 1; TruePlayer = 0; kol_vo = 0; TruePlayer = 0; }
                    if (exitsprite.getGlobalBounds().contains(pos.x, pos.y) && (m1 == 0)) { window.close(); }
                    //mode
                    if (playersprite.getGlobalBounds().contains(pos.x, pos.y) && (m1 == 1)) { m1 = 2; }
                    if (countrysprite.getGlobalBounds().contains(pos.x, pos.y) && (m1 == 1)) { m1 = 3; }
                    if (clubsprite.getGlobalBounds().contains(pos.x, pos.y) && (m1 == 1)) { m1 = 4; }
                    //games
                    if ((m1 == 2) && (win() == 0)) { hod(pos); }
                    if ((m1 == 3) && (win() == 0)) { hod(pos); }
                    if ((m1 == 4) && (win() == 0)) { hod(pos); }
                    
                }
            }
        }

    }
    return 0;
}
