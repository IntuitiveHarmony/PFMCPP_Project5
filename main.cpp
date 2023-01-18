/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 copied UDT 1:
 */
#include <iostream>
struct Tree
{ 
    float height = {0.0f};
    int age = {0};
    std::string type = {""};
    std::string location = {""};
    int numberOfBranches = {0};

    Tree();
    ~Tree();
    struct Fruit
    {
        std::string name = {""};
        std::string color = {""};
        bool readyToEat = {false};
        int numberOfSeeds = {0};
        
        Fruit();
        ~Fruit();

        void produceSeeds();
        void fallFromTree();
        void inspireTheoryOfGravity();
        void sweeten(int water);
        void ripen(int time);
    };

    void grow(int water);
    Fruit produceFruit(int grow = 7);
    int photosynthesize(int sunLight = 5, int water = 3, int unkonwnFactor = 7);
};

Tree::Tree()
{
    std::cout << "Tree being constructed!" << std::endl;
}

Tree::Fruit::Fruit()
{
    std::cout << "Fruit being constructed! \nRight now it has " << numberOfSeeds << " seeds." << std::endl;
}

void Tree::grow(int water)
{
    std::cout << "All is well in the shade of the apple tree" << std::endl;
    for(int i = 0; i < water; ++i)
    {
        this->height += 0.1f;
        this->numberOfBranches += 3;
    }
}

Tree::Fruit Tree::produceFruit(int grow)
{
    Tree::Fruit fruit;
    
    if (grow > 0)
    {
        fruit.readyToEat = true;    
    }
    else 
    {      
        fruit.readyToEat = false;
    }
    
    return fruit;
}

int Tree::photosynthesize(int sunLight, int water, int unkonwnFactor)
{
    return (sunLight > 0) ? water * unkonwnFactor : 0;
}

void Tree::Fruit::produceSeeds()
{
    srand(1);
    numberOfSeeds = rand() % 10;
}

void Tree::Fruit::fallFromTree()
{
    std::cout << "yum!" << std::endl;
}

void Tree::Fruit::inspireTheoryOfGravity()
{
    std::cout << "Eureka!" << std::endl;
}

void Tree::Fruit::sweeten(int water)
{
    float sweetness = 0.0f;
    for(int i = 0; i < water; ++i)
    {
       sweetness += 0.3f;     
    }
    std::cout << "The fruit has " << sweetness << " units of sweetness! \n";
}

void Tree::Fruit::ripen(int time)
{
    if(time <= 0)
    {
        this->color = "Green";
    }
    else
    {
        this->color = "Red";
    }
    std::cout << "The fruit's color is " << this->color << std::endl;
}

Tree::~Tree()
{
    std::cout << "Destroying Tree \n";
}

Tree::Fruit::~Fruit()
{
    std::cout << "Destroying Fruit \n";
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 copied UDT 2:
 */
struct PersonTwo
{
    float height = {0.0f};
    int age = {0};
    int numberOfSiblings = {0};
    std::string job = {""};
    std::string address = {""};

    PersonTwo();
    ~PersonTwo();

    struct Eye
    {
        std::string color = {""};
        bool needsGlasses = {false};
        bool hasCataracts = {false};
        std::string typeOfColorBlindness = {""};
        std::string vision = {"20/20"};

        Eye();
        ~Eye();

        bool open(bool awake = true);
        bool close(bool awake = true);
        void see();
        void blink(float dust);
        void lookAtSun();
    };

    bool run(int speed = 7);
    int jump(int crouch = 9, int energy = 4);
    bool playPiano(bool memoryRecal = true, int nerves = 11);
    void printFace(int numOfHeads);
    void celebrateBirthday();
};

PersonTwo::PersonTwo()
{
    std::cout << "PersonTwo being constructed!" << std::endl; 
}

PersonTwo::Eye::Eye()
{
    std::cout << "The eye is being constructed!" << std::endl;
}

bool PersonTwo::run(int speed)
{
    return (speed > 5) ? true : false;
}

int PersonTwo::jump(int crouch, int energy)
{
    return crouch * energy;
}

bool PersonTwo::playPiano(bool memoryRecal, int nerves)
{
    return memoryRecal && nerves > 10 ? true : false; 
}

void PersonTwo::printFace(int numOfHeads)
{
    for(int i = 0; i < numOfHeads; ++i)
    {
        std::cout << "(o_*) ";
    }
    std::cout << "\n";
}

void PersonTwo::celebrateBirthday()
{
    this->age += 1;
}

bool PersonTwo::Eye::open(bool awake)
{
    return awake ? true : false;
}

bool PersonTwo::Eye::close(bool awake)
{
    return awake == false ? true : false;
}

void PersonTwo::Eye::see()
{
    needsGlasses = vision == "20/20" ? false : true;
}

void PersonTwo::Eye::blink(float dust)
{
    std::cout << "I've got something in my eye! \n";
    while(dust >= 0.0f)
    {
        dust -= 0.3f; 
        std::cout << "*blink, \n"; 
        if(dust <= 0.0f)
        {
            std::cout << "*blink. \n";
            std::cout << "That got it. \n\n";
        }    
    }
     
}

void PersonTwo::Eye::lookAtSun()
{
    this->needsGlasses = true;
}

PersonTwo::~PersonTwo()
{
    std::cout << "Destroying PersonTwo \n";
}

PersonTwo::Eye::~Eye()
{
    std::cout << "Destroying Eye \n";
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 copied UDT 3:
 */
struct Computer
{
    bool airplaneMode = {false};
    float storageAmount = {0};
    int RAMAmount = {0};
    std::string manufacturer = {""};
    float screenSize = {0.0f};
    int amountUSBPort = {0};
    
    Computer();
    ~Computer();

    bool connectToInternet(bool paidISP);
    bool save(std::string fileName, bool clickSaveButton);
    void runApp(std::string something);
    void runFizzBuzz(int max);
    void initializeComputer();
    void upgradeRAM();
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl; 
}

bool Computer::connectToInternet(bool paidISP = true)
{
    return paidISP ? true : false;
}

bool Computer::save(std::string fileName, bool clickSaveButton)
{
    return fileName != "" && clickSaveButton ? true : false;
}

void Computer::runApp(std::string text)
{
    std::cout << text << " on " << RAMAmount << " GB of RAM" << std::endl;
}

void Computer::runFizzBuzz(int max)
{
    for(int i = 1; i <= max; ++i)
    {
        if(i % 3 == 0 && i % 5 ==0)
        {
            std::cout << "FizzBuzz" << std::endl;
        } 
        else if(i % 3 == 0)
        {
            std::cout << "Fizz" << std::endl;
        } 
        else if(i % 5 == 0)
        {
            std::cout << "Buzz" << std::endl;
        } 
        else
        {
            std::cout << i << std::endl;   
        }
        
    }
}

void Computer::initializeComputer()
{
    this->storageAmount = 0.0f;
    this->RAMAmount = 0;
    this->manufacturer = "";
    this->screenSize = 0.0f;
    this->amountUSBPort = 0;
    std::cout << "The computer is now initialized and has " << this->RAMAmount << "GB of memory \n\n";
}

void Computer::upgradeRAM()
{
    this->RAMAmount *= 2;
    std::cout << "Memory has been upgraded and is now " << this->RAMAmount << "GB \n";
}

Computer::~Computer()
{
    std::cout << "Destroying Computer \n";
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 new UDT 4:
 with 2 member functions
 */
struct Room
{
    Computer knot;
    PersonTwo jason;
    Tree::Fruit apple;

    Room();
    ~Room();

    void setUpComputer();
    void runShortcut();
};

Room::Room()
{
    std::cout << "The room is being entered \n";
}

void Room::setUpComputer()
{
    knot.storageAmount = 30.31f;
    knot.RAMAmount = 16;
    knot.manufacturer = "Apple";
    knot.screenSize = 13.1f;
    knot.amountUSBPort = 2;
    std::cout << "The " << knot.manufacturer << " computer is now set up. \n\n";
}

void Room::runShortcut()
{
    knot.runFizzBuzz(45);
}

Room::~Room()
{
    std::cout << "The room is now empty \n";
}

/*
 new UDT 5: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 with 2 member functions
 */
struct Luggage
{
    Computer knot;
    Tree::Fruit apple;

    Luggage();
    ~Luggage();

    void activateAirplaneMode();
    void eatApple();
};

Luggage::Luggage()
{
    std::cout << "Luggage Packed \n";
}

void Luggage::activateAirplaneMode()
{
    knot.airplaneMode = true;
}

void Luggage::eatApple()
{
    apple.fallFromTree();
}

Luggage::~Luggage()
{
    std::cout << "Luggage emptied \n";
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Tree tree;
    tree.grow(34);
    tree.produceFruit();
    tree.photosynthesize();
    std::cout << "The tree is " << tree.height << " feet tall and has " << tree.numberOfBranches << " branches! \n";
    
        
    Tree::Fruit fruit;
    fruit.produceSeeds();
    fruit.fallFromTree();
    fruit.inspireTheoryOfGravity();
    fruit.sweeten(345);
    fruit.ripen(0);
    fruit.ripen(4);
    std::cout << "Does the apple have more than 4 seeds? " << (fruit.numberOfSeeds > 4 ? "Yes, it has " : "No, it only has ") << fruit.numberOfSeeds << (fruit.numberOfSeeds == 1 ? " seed. \n\n" : " seeds. \n\n");

    PersonTwo personTwo;
    personTwo.run();
    personTwo.jump();
    personTwo.playPiano();
    personTwo.printFace(3);
    personTwo.celebrateBirthday();
    std::cout << "The person just celebrated a birtday and is now " << personTwo.age << std::endl;
    
    PersonTwo::Eye eye;
    eye.open();
    eye.close();
    eye.see();
    eye.blink(3.4f);
    std::cout << "Before lookAtSun() eye.needsGlasses = " << eye.needsGlasses << std::endl;
    eye.lookAtSun();
    std::cout << "After lookAtSun() eye.needsGlasses = " << eye.needsGlasses << std::endl;
    std::cout << "Is the person awake? Will they play the Piano? " << (eye.open() ? "Yes" : "No") << " and " << (eye.open() && personTwo.playPiano() ? "Yes" : "No") << "\n\n";
    
    Computer computer;
    computer.connectToInternet();
    computer.save("Sweet Cat Video", true);
    computer.runApp("App is running");
    computer.runFizzBuzz(30);
    std::cout << "Is the RAM higher than 8? " << (computer.RAMAmount > 8 ? "Yes" : "No") << "\n\n";

    Room room;
    room.setUpComputer();
    room.runShortcut();
    room.knot.upgradeRAM();

    Luggage luggage;
    luggage.activateAirplaneMode();
    luggage.eatApple();
    luggage.knot.initializeComputer();
    
    std::cout << "good to go!" << std::endl;
}
