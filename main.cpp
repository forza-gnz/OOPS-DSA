// #if 0

// #include <SFML/Graphics.hpp>
// #include <iostream>
// int main()
// {
    
//       sf::RenderWindow window(sf::VideoMode(800, 600),"Maachuda");
//     float radius = 50.0f;
//       sf::CircleShape shape(radius);
//         sf::Vector2f circlePosition(5,5);

//         shape.setPosition(circlePosition);
//         // set the shape color to green
//         shape.setFillColor(sf::Color(100, 250, 100));
//         shape.setPosition(circlePosition);
//       float vx = 0.03;
//       float vy = 0.03;
     
      
//     // run the program as long as the window is open
//     while (window.isOpen())
//     {   // check all the window's events that were triggered since the last iteration of the loop
//         sf::Event event;
       
//         while (window.pollEvent(event))
//         {
       
//             // "close requested" event: we close the window
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         if((circlePosition.x>=(800 - 2*radius)) || circlePosition.x<=0) vx *= -1;
//         if((circlePosition.y>=(600 - 2*radius)) || circlePosition.y<=0) vy *= -1;
        
//         circlePosition.x += vx;
//         circlePosition.y += vy;

//         shape.setPosition(circlePosition);



// // sf::Vertex line[] =
// // {
// //     sf::Vertex(sf::Vector2f(5.0f, 5.0f)),
// //     sf::Vertex(sf::Vector2f(25.0f, 5.0f)),
// //     sf::Vertex(sf::Vector2f(25.0f, 5.0f)),
// //     sf::Vertex(sf::Vector2f(circlePosition))
// // };
// // std::vector<sf::vertex> raand;

        

//         // clear the window with black color
//         window.clear(sf::Color::Black);

//         // draw everything here...
//         // window.draw(...);
       
        
        
//         window.draw(shape);
//         // window.draw(line,  , sf::Lines);
       
        

//         // end the current frame
//         window.display();
        
//     }
//     return 0;    
  
// }
// #endif


#include <SFML/Graphics.hpp>
 

int main(){

   // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "controlers");
    float radius = 50.0f;
      sf::CircleShape shape(radius);
        sf::Vector2f circlePosition(350,250);

        shape.setPosition(circlePosition);
        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 100));
        shape.setPosition(circlePosition);

        

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
          shape.move(-0.1f,0.0f);
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
          shape.move(0.0f,-0.1f);
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
          shape.move(0.0f,0.1f);
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
          shape.move(0.1f,0.0f);
        }
        

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(shape);

        // end the current frame
        window.display();
    }

    return 0;

}





