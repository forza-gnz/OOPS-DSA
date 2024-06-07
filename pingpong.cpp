#include<SFML/Graphics.hpp>

int main(){

   // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "ping pong ");
   
    // define a 120x50 rectangle
        sf::RectangleShape rectangle1(sf::Vector2f(120.f, 50.f));
    // change the size to 100x100
        rectangle1.setSize(sf::Vector2f(40.0f, 100.f));

        // define a 120x50 rectangle
       sf::RectangleShape rectangle2(sf::Vector2f(120.f, 50.f));
        rectangle2.setPosition(750.f,0.f);
        // change the size to 100x100
        rectangle2.setSize(sf::Vector2f(40.0f, 100.f));
       

        sf::RectangleShape ball(sf::Vector2f(120.f, 50.f));
        ball.setPosition(385.f,285.f);
        // change the size to 100x100
        ball.setSize(sf::Vector2f(30.0f, 30.f));
        float vx = 0.04;
        float vy = 0.01;


       


// run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        
      
        }

        sf::Vector2f position1 = rectangle1.getPosition();
        sf::Vector2f position2 = rectangle2.getPosition();
        sf::Vector2f position3 = ball.getPosition();
       

        if(position3.y<(position1.y+100.0f) && position3.y>(position1.y-30.0f)  && (position1.x+50.0f)>position3.x ){
            vx =(-1)*vx;
        } 
        if(position3.y<(position2.y+100.0f) && position3.y>(position2.y-30.0f)   && (position2.x-30.0f)<position3.x ){
            vx =(-1)*vx;
        } 
        if(position3.y < 0.0f || position3.y > 570.0f){
            vy = (-1)*vy;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        rectangle1.move(0.0f,-0.1f);
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        rectangle1.move(0.0f,0.1f);
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
        rectangle2.move(0.0f,0.1f);
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        rectangle2.move(0.0f,-0.1f);
        }

        position3.x += vx;
        position3.y += vy;

        ball.setPosition(position3.x , position3.y);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(ball);

        // end the current frame
        window.display();
}
            return 0;
    }






