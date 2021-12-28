#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <utility>
#include <ctime>
#include <cmath>

using namespace sf;
using namespace std;

class Game
{
private:
    //Variables
    RenderWindow *window;
    Event event;
    VideoMode v;
    bool hover = false;
    bool hover1 = false;
    bool hover2 = false;
    bool starting = true;
    Texture bTexture;
    Sprite bSprite;
    vector<Sprite> heart;
    vector<Sprite> eheart;
    Sprite Restart;
    Sprite Restart2;
    Sprite start;
    Sprite start2;
    Sprite exit;
    Sprite exit2;
    Sprite heading;
    Texture texture;
    Texture texture0;
    Texture texture2;
    Texture etexture0;

    Texture reTexture;
    Texture reTexture2;
    Texture stTexture;
    Texture stTexture2;
    Texture exTexture;
    Texture exTexture2;
    Texture heatexture;
    Sprite sprite;
    Sprite startBack;
    Texture startBackText;
    Font font;
    Text points;
    Text Over;
    Text p;
    int po = 0;
    bool isPlayerJumping;
    bool isPlayerGoingUp;
    int ballTouchedGround;
    int ballCatched;
    int life;

    CircleShape circle;
    CircleShape circles;
    vector<pair<CircleShape, float>> circleVector;
    vector<bool> isBallPositionRight;
    float g;
    int maxBalls;
    int m;
    float position;
    int i1 = 0;
    float time, x0, y0, velocity, vx, vy, xprev, yprev, theta;
    bool b = false;

    //Private Functions
    void initVariables();

    void initWindow();
    void initSprite();
    void addNewBall();

public:
    Game();          //Constructor
    virtual ~Game(); //Destructor

    //Public Functions
    bool isRunning();
    void update();
    void initVariables2();
    void pollEvents();
    void updateBallPosition();
    void updateBallPosition2();
    void renderBallPosition();
    void updateSprite();
    void render();
    void initFonts();
    double Convert(double degree);
    void changeDogColor();
};

/* ........................................................................................ */

/*
    Defining All the Private/Public Functions 
    Also the Constructor and Destructor
*/

//Constructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initSprite();
    this->initFonts();
}

//Destructor
Game::~Game()
{
    delete this->window;
}

//Function to initialise Variables
void Game::initVariables()
{
    this->window = NULL;
    this->v.width = 1000;
    this->v.height = 800;
    this->isPlayerJumping = false;
    this->isPlayerGoingUp = false;
    this->ballTouchedGround = -1;
    this->ballCatched = -1;
    this->life = 5;
    this->g = 0.06f;
    this->maxBalls = 2;
    this->m = 2000;
    heart.resize(5);
    eheart.resize(5);
    circles.setRadius(10);
    this->circles.setFillColor(Color(0, 0, 0, 255));
}

//Function to initialise Window
void Game::initWindow()
{
    this->window = new RenderWindow(this->v, "Game Window!!", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);
    if (!bTexture.loadFromFile("Background2.O.jpg"))
    {
        cout << "Load Failed!!" << endl;
    }
    bSprite.setTexture(bTexture);
    bSprite.setPosition(Vector2f(0.f, 0.f));
}

void Game::initSprite()
{
    if (!texture.loadFromFile("DogInverted.png"))
    {
        cout << "Load Failed!!" << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f((window->getPosition().x / 2) - 70, 670.f));
    if (!texture0.loadFromFile("heart.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    if (!etexture0.loadFromFile("emptyHeart.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    // Heart texture
    for (int i = 0; i < heart.size(); i++)
    {
        heart[i].setTexture(texture0);
    }
    for (int i = 0; i < heart.size(); i++)
    {
        eheart[i].setTexture(etexture0);
    }
    // Heart Position
    for (int i = 0; i < heart.size(); i++)
    {
        heart[i].setPosition(Vector2f(70 + (i * 55), 60));
        eheart[i].setPosition(Vector2f(70 + (i * 55), 60));
    }

    if (!reTexture.loadFromFile("restart.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    if (!reTexture2.loadFromFile("restartt.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    Restart2.setTexture(reTexture2);
    Restart2.setPosition(Vector2f(window->getPosition().x - 120, window->getPosition().y + 260));
    Restart.setTexture(reTexture);
    Restart.setPosition(Vector2f(window->getPosition().x - 120, window->getPosition().y + 260));

    if (!stTexture.loadFromFile("startButton.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    if (!stTexture2.loadFromFile("startButton2.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    if (!exTexture.loadFromFile("exitButton.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    if (!exTexture2.loadFromFile("exitButton2.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    if (!heatexture.loadFromFile("heading.png"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    if (!startBackText.loadFromFile("start-back.jpg"))
    {
        cout << "Load Failed!!" << endl;
        cout << "Yrd";
    }
    start.setTexture(stTexture);
    start2.setTexture(stTexture2);
    exit.setTexture(exTexture);
    exit2.setTexture(exTexture2);
    startBack.setTexture(startBackText);
    heading.setTexture(heatexture);
    start.setPosition(Vector2f(window->getPosition().x - 200, window->getPosition().y + 400));
    start2.setPosition(Vector2f(window->getPosition().x - 200, window->getPosition().y + 400));
    exit.setPosition(Vector2f(window->getPosition().x + 100, window->getPosition().y + 398));
    exit2.setPosition(Vector2f(window->getPosition().x + 100, window->getPosition().y + 398));
    heading.setPosition(Vector2f(window->getPosition().x - 290, window->getPosition().y + 60));
}

void Game::initFonts()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Error";
    }
    points.setFont(font);
    Over.setFont(font);

    p.setFont(font);
    points.setString("POINTS: ");
    Over.setString("Game Over!!");

    p.setString("0");
    points.setCharacterSize(24);
    p.setCharacterSize(24);
    Over.setCharacterSize(50);
    points.setFillColor(Color::Black);
    p.setFillColor(Color::Black);
    Over.setFillColor(Color::Red);

    Over.setStyle(Text::Bold);
    points.setPosition(Vector2f(window->getPosition().x + 300, 60));
    Over.setPosition(Vector2f(window->getPosition().x - 100, window->getPosition().y + 200));
    p.setPosition(Vector2f(window->getPosition().x + 400, 60));
}

void Game::initVariables2()
{

    if (i1 % 2 == 0)
    {
        time = 0.06;
        x0 = 10;
        velocity = 470 + (std::rand() % (800));
        // velocity = 800;
        y0 = 40 + (std::rand() % (window->getSize().y / 3));
        theta = -10 + (std::rand() % (80));
        // theta = 0;
        vx = velocity * cos(Convert(theta));
        vy = velocity * sin(Convert(theta));
        xprev = -1;
        yprev = -1;
        b = true;
        circles.setPosition(sf::Vector2f(x0, y0));
        cout << time;
    }
    else
    {
        time = 0.06;
        x0 = window->getSize().x - 20;
        velocity = 470 + (std::rand() % (800));
        // velocity = 300;
        y0 = 40 + (std::rand() % (window->getSize().y / 3));
        theta = -10 + (std::rand() % (80));

        vx = velocity * cos(Convert(theta));
        vy = velocity * sin(Convert(theta));
        xprev = -1;
        yprev = -1;
        b = false;
        circles.setPosition(sf::Vector2f(x0, y0));
    }
    i1++;
}

//Function to return Open/Closed State of Window
bool Game::isRunning()
{
    return this->window->isOpen();
}

//Function to ADD NEW BALL
void Game::addNewBall()
{
    //Creatig a Circle Using built-in function to represent it as a Ball
    this->circle.setRadius(10.f);
    this->circle.setFillColor(Color(0, 0, 0, 255));

    //Setting the position of the Ball(y-coordinate) randomly
    this->position = static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - 5 * (this->sprite.getPosition().y) / 6));

    //Deciding whether Ball will enter from Right or Left Side
    /* If Previously used Random Function(used for deciding the y coordinate of ball)
    returned an even number ball will enter from right side 
    otherwise it will enter from the left side of the screen*/

    if (static_cast<int>(this->position) % 2 == 0)
    {
        this->circle.setPosition(Vector2f(
            this->v.width - this->circle.getGlobalBounds().width,
            this->position));
        this->isBallPositionRight.push_back(true);
    }
    else
    {
        this->circle.setPosition(Vector2f(
            0.f,
            this->position));
        this->isBallPositionRight.push_back(false);
    }
    this->circleVector.emplace_back(this->circle, 0);
}

//Function to continuously UPDATE the BALL'S POSITION(change the x and y coordinates)
void Game::updateBallPosition()
{
    //Checking if specified time has been spend before new ball comes on the screen
    if (m >= 50)
        m = 0;
    else
        m++;

    //Adding new ball if specified time is over and maximum ball limit is not exceeded
    if (po <= 10)
    {
        if ((m == 0) && (this->circleVector.size() < this->maxBalls))
        {
            this->addNewBall();
        }
    }
    //Updating the Position of each ball present on the screen
    for (int i = 0; i < circleVector.size(); i++)
    {
        /* The Position of y coordinate will every time increment by g 
        and x coordinate will increase by the same value */

        circleVector[i].second += g;
        if (this->isBallPositionRight[i])
            this->circleVector[i].first.move(Vector2f(-6.f, this->circleVector[i].second));
        else
            this->circleVector[i].first.move(Vector2f(6.f, this->circleVector[i].second));

        //WHEN THE BALL TOUCHES THE GROUND

        if (this->circleVector[i].first.getPosition().y + this->circleVector[i].first.getGlobalBounds().height >= this->sprite.getGlobalBounds().height + this->sprite.getPosition().y + 20.f)
        {

            this->life--;

            // this->circleVector[i].first.setFillColor(Color(255, 0, 0, 255));
            this->ballTouchedGround = 0;
            this->circleVector.erase(circleVector.begin() + i);
            this->isBallPositionRight.erase(isBallPositionRight.begin() + i);
        }

        //IF THE DOG CATCHES THE BALL

        if ((this->circleVector[i].first.getPosition().y >= this->sprite.getPosition().y - 40.f) &&
            (this->circleVector[i].first.getPosition().y <= this->sprite.getPosition().y + 60.f))
        {
            //IF THE PLAYER IS FACING TOWARDS RIGHT
            if (this->sprite.getScale().x == 1.f)
            {
                if ((this->circleVector[i].first.getPosition().x >= this->sprite.getPosition().x - 20) &&
                    (this->circleVector[i].first.getPosition().x <= this->sprite.getPosition().x + 150))
                {
                    this->ballCatched = 0;
                    this->circleVector.erase(circleVector.begin() + i);
                    this->isBallPositionRight.erase(isBallPositionRight.begin() + i);
                    po++;

                    p.setString(to_string(po));
                }
            }
            //IF THE PLAYER IS FACING TOWARDS LEFT
            if (this->sprite.getScale().x == -1.f)
            {
                if ((this->circleVector[i].first.getPosition().x >= this->sprite.getPosition().x - 150) &&
                    (this->circleVector[i].first.getPosition().x <= this->sprite.getPosition().x + 20))
                {
                    this->ballCatched = 0;

                    this->circleVector.erase(circleVector.begin() + i);
                    this->isBallPositionRight.erase(isBallPositionRight.begin() + i);
                    po++;
                    p.setString(to_string(po));
                }
            }
        }
    }
}

void Game::updateBallPosition2()
{
    if (circles.getPosition().y > 750)
    {

        life--;
        ballTouchedGround = 0;

        if (life == 0)
            return;
        initVariables2();

        return;
    }
    if ((circles.getPosition().y >= this->sprite.getPosition().y - 40.f) &&
        (circles.getPosition().y <= this->sprite.getPosition().y + 60.f))
    {
        //IF THE PLAYER IS FACING TOWARDS RIGHT
        if (this->sprite.getScale().x == 1.f)
        {
            if ((circles.getPosition().x >= this->sprite.getPosition().x - 20) &&
                (circles.getPosition().x <= this->sprite.getPosition().x + 150))
            {
                po++;
                p.setString(to_string(po));
                ballCatched = 0;

                initVariables2();
                return;
            }
        }
        //IF THE PLAYER IS FACING TOWARDS LEFT
        if (this->sprite.getScale().x == -1.f)
        {
            if ((circles.getPosition().x >= this->sprite.getPosition().x - 150) &&
                (circles.getPosition().x <= this->sprite.getPosition().x + 20))
            {
                po++;
                p.setString(to_string(po));
                ballCatched = 0;
                initVariables2();
                return;
            }
        }
    }

    if (circles.getPosition().x >= window->getSize().x - 20)
    {
        double dx = circles.getPosition().x - xprev;
        double dy = circles.getPosition().y - yprev;
        double h = sqrt((dx * dx) + (dy * dy));
        double x = dx / h;
        double theta1 = -acos(x);
        time = 0.05;
        vx = velocity * cos(theta1);
        vy = velocity * sin(theta1);
        theta = theta1;
        // std::cout << theta1 << " " << x << "\n";
        x0 = circles.getPosition().x;
        y0 = circles.getPosition().y;
        b = false;
        // sound.play();
    }

    if (circles.getPosition().x <= 9)
    {
        double dx = xprev - circles.getPosition().x;
        double dy = yprev - circles.getPosition().y;
        double h = sqrt((dx * dx) + (dy * dy));
        double x = dx / h;
        double theta1 = -acos(x);
        time = 0.08;
        vx = velocity * cos(theta1);
        vy = velocity * sin(theta1);
        theta = theta1;
        // std::cout << theta1 << " " << x << "\n";
        x0 = circles.getPosition().x;
        y0 = circles.getPosition().y;
        b = true;
        // sound.play();
    }

    if (circles.getPosition().y <= 10)
    {
        double dx = circles.getPosition().x - xprev;
        double dy = yprev - circles.getPosition().y;
        double h = sqrt((dx * dx) + (dy * dy));
        double x = dx / h;
        double theta1 = -acos(x);
        time = 0.08;
        vx = velocity * cos(theta1);
        vy = velocity * sin(theta1);
        theta = theta1;
        // std::cout << theta1 << " " << x << "\n";
        x0 = circles.getPosition().x;
        y0 = circles.getPosition().y;
        b = true;
        // sound.play();
    }

    if (b)
    {
        float Xnew = x0 + vx * time;
        float Ynew = y0 - (vy * time) + (0.5 * 9.8 * time * time);
        xprev = circles.getPosition().x;
        yprev = circles.getPosition().y;
        // std::cout << time << " " << Xnew << " " << Ynew << "\n";
        // circle.setPosition(sf::Vector2f(Xnew, Ynew));

        circles.move(sf::Vector2f(Xnew - xprev, Ynew - yprev));
        time += 0.02;
    }
    else if (b == false)
    {
        float Xnew = x0 - vx * time;
        float Ynew = y0 - (vy * time) + (0.5 * 9.8 * time * time);
        // std::cout << time << " " << Xnew << " " << Ynew << "\n";
        xprev = circles.getPosition().x;
        yprev = circles.getPosition().y;
        circles.move(sf::Vector2f(Xnew - xprev, Ynew - yprev));
        time += 0.02;
    }
}

//Function to take inputs and update position of the sprite (PLAYER/DOG)
void Game::updateSprite()
{
    // IF LEFT KEY IS PRESSED (PLAYER WANTS TO MOVE TOWARDS THE LEFT)
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        this->sprite.setScale(Vector2f(-1.f, 1.f));
        this->sprite.move(Vector2f(-9.f, 0.f));
        if (this->sprite.getPosition().x - this->sprite.getGlobalBounds().width <= 0)
        {
            this->sprite.setPosition(Vector2f(this->sprite.getGlobalBounds().width, 670.f));
        }
    }

    // IF RIGHT KEY IS PRESSED (PLAYER WANTS TOWARDS MOVE TO THE RIGHT)
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        this->sprite.setScale(Vector2f(1.f, 1.f));
        this->sprite.move(Vector2f(9.f, 0.f));
        if (this->sprite.getPosition().x + this->sprite.getGlobalBounds().width >= this->window->getSize().x)
        {
            this->sprite.setPosition(Vector2f(this->window->getSize().x - this->sprite.getGlobalBounds().width, 670.f));
        }
    }

    // IF UP/SPACEBAR IS PRESSED (PLAYER WANTS TO JUMP)
    if (!this->isPlayerJumping && (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Space)))
    {
        this->sprite.move(Vector2f(0.f, -4.f));
        this->isPlayerJumping = true;
        this->isPlayerGoingUp = true;
    }

    if (this->isPlayerJumping)
    {

        if (this->isPlayerGoingUp)
        {
            this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - 4);
        }
        if (this->sprite.getPosition().y <= 570.f | !(this->isPlayerGoingUp))
        {
            this->isPlayerGoingUp = false;
            this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y + 4);
        }
        if (this->sprite.getPosition().y >= 670.f)
        {
            this->isPlayerJumping = false;
        }
    }
}

//Function to Poll Events
void Game::pollEvents()
{
    while (this->window->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            this->window->close();
            break;
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

//Update Function
void Game::update()
{
    this->pollEvents();
    if (starting)
    {
        if ((Mouse::getPosition(*window).x >= start.getPosition().x && Mouse::getPosition(*window).x <= start.getGlobalBounds().width + start.getPosition().x) && (Mouse::getPosition(*window).y >= start.getPosition().y && Mouse::getPosition(*window).y <= start.getGlobalBounds().height + start.getPosition().y))
        {
            // cout << "yes";
            hover1 = true;
        }
        else
            hover1 = false;
        if ((Mouse::getPosition(*window).x >= exit.getPosition().x && Mouse::getPosition(*window).x <= exit.getGlobalBounds().width + exit.getPosition().x) && (Mouse::getPosition(*window).y >= exit.getPosition().y && Mouse::getPosition(*window).y <= exit.getGlobalBounds().height + exit.getPosition().y))
        {
            // cout << "yes";
            hover2 = true;
        }
        else
            hover2 = false;
        if (Mouse::isButtonPressed(Mouse::Left))
        {

            if ((Mouse::getPosition(*window).x >= start.getPosition().x && Mouse::getPosition(*window).x <= start.getGlobalBounds().width + start.getPosition().x) && (Mouse::getPosition(*window).y >= start.getPosition().y && Mouse::getPosition(*window).y <= start.getGlobalBounds().height + start.getPosition().y))
            {
                starting = false;
                life = 5;
                po = 0;
                p.setString(to_string(po));

                return;
            }
            if ((Mouse::getPosition(*window).x >= exit.getPosition().x && Mouse::getPosition(*window).x <= exit.getGlobalBounds().width + exit.getPosition().x) && (Mouse::getPosition(*window).y >= exit.getPosition().y && Mouse::getPosition(*window).y <= exit.getGlobalBounds().height + exit.getPosition().y))
            {
                window->close();
                return;
            }
        }
    }
    if (starting == false && life != 0)
    {
        this->updateSprite();
        if (po <= 10 || circleVector.size() != 0)
        {
            this->updateBallPosition();
        }
        else
        {
            if (i1 == 0)
                this->initVariables2();
            this->updateBallPosition2();
        }
        changeDogColor();
    }
    else if (starting == false && life == 0)
    {
        if (life == 0)
        {
            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {

                po = 0;
                p.setString(to_string(po));
                life = 5;
            }
            if ((Mouse::getPosition(*window).x >= Restart.getPosition().x && Mouse::getPosition(*window).x <= Restart.getGlobalBounds().width + Restart.getPosition().x) && (Mouse::getPosition(*window).y >= Restart.getPosition().y && Mouse::getPosition(*window).y <= Restart.getGlobalBounds().height + Restart.getPosition().y))
            {
                // cout << "yes";
                hover = true;
            }
            else
                hover = false;
            if (Mouse::isButtonPressed(Mouse::Left))
            {

                if ((Mouse::getPosition(*window).x >= Restart.getPosition().x && Mouse::getPosition(*window).x <= Restart.getGlobalBounds().width + Restart.getPosition().x) && (Mouse::getPosition(*window).y >= Restart.getPosition().y && Mouse::getPosition(*window).y <= Restart.getGlobalBounds().height + Restart.getPosition().y))
                {
                    this->life = 5;

                    po = 0;
                    p.setString(to_string(po));
                }
            }
        }
    }
}

//Render Function
void Game::render()
{
    if (starting)
    {
        window->clear(Color(0, 0, 0));
        window->draw(startBack);
        window->draw(heading);
        if (hover1 == false)
            window->draw(start);
        else
            window->draw(start2);
        if (hover2 == false)
            window->draw(exit);
        else
            window->draw(exit2);
        window->display();
        return;
    }
    if (this->life == 0)
    {
        window->clear(Color(0, 0, 0));
        if (hover == false)
            window->draw(Restart);
        else
            window->draw(Restart2);
        window->draw(Over);
    }
    else
    {
        this->window->clear(Color(255, 0, 0, 255));
        this->window->draw(bSprite);
        this->window->draw(sprite);
        this->window->draw(points);
        this->window->draw(p);
        if (po <= 10 || circleVector.size() != 0)
        {
            for (int i = 0; i < circleVector.size(); i++)
            {
                this->window->draw(this->circleVector[i].first);
            }
        }
        else
        {
            this->window->draw(circles);
        }
        for (int i = 0; i < life; i++)
        {
            window->draw(heart[i]);
        }
        for (int i = life; i < eheart.size(); i++)
        {
            window->draw(eheart[i]);
        }
    }
    this->window->display();
}
double Game::Convert(double degree)
{
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}
void Game::changeDogColor()
{
    if (this->ballCatched != -1)
    {
        this->ballCatched += 1;
        texture2.loadFromFile("GreenDog.png");
        this->sprite.setTexture(texture2);
        if (this->ballCatched == 15)
        {
            sprite.setTexture(this->texture);
            this->ballCatched = -1;
        }
    }

    if (this->ballTouchedGround != -1)
    {
        this->ballTouchedGround += 1;
        if (this->ballTouchedGround % 4 <= 2)
        {

            texture2.loadFromFile("RedDog2.png");
            this->sprite.setTexture(texture2);
        }
        else
        {
            this->sprite.setTexture(texture);
        }
        if (this->ballTouchedGround == 15)
        {
            if (this->life >= 3)
            {
                texture.loadFromFile("DogInverted.png");
                this->sprite.setTexture(texture);
            }
            else if (this->life == 2)
            {
                texture.loadFromFile("DogInverted2.png");
                this->sprite.setTexture(texture);
            }
            else
            {
                texture.loadFromFile("DogInverted3.png");
                this->sprite.setTexture(texture);
            }
            this->ballTouchedGround = -1;
        }
    }
}