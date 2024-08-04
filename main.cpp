#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <algorithm>

using namespace std;

vector<string> inventory;

void towns(bool first){
    cout << "\033c" << "You walk for many more miles, through many" << (first  ? "" : " more") << " towns." << endl;
    sleep(2);
    if(first) cout << "Eventually, you find the place you were looking for. Do you enter? (yes/no)" << endl;
    else cout << "You find another perfect town. Do you enter? (yes/no)" << endl;
    string answer;
    cin >> answer;
    if(answer == "yes") {
        cout << "You decide to enter." << endl;
        cout << "You walk through the town and see many people." << endl;
        cout << "Do you talk to them? (yes/no)" << endl;
        cin >> answer;
        if(answer == "yes") {
            cout << "You decide to talk to the people." << endl;
            cout << "You meet many interesting people." << endl;
            cout << "Do you stay in the town? (yes/no)" << endl;
            cin >> answer;
            if(answer == "yes") {
                cout << "You decide to stay in the town." << endl;
                cout << "You live peacefully in the town for the rest of your life." << endl;
            }else{
                cout << "You decide not to stay in the town." << endl;
                cout << "You continue your journey." << endl;
                towns(false);
            }
        }
    }else{
        cout << "You decide not to enter." << endl;
        cout << "You continue your journey." << endl;
        towns(false);
    }
}

int main() {
cout << "\033c" << "The phone is ringing. Do you answer it? (yes/no)" << endl;
string answer;
cin >> answer;
if(answer == "no") {
    cout << "You let the phone ring." << endl;
    cout << "It was your mother calling. She wanted to know if you wanted to visit her. Do you go? (yes/no)" << endl;
}else{
cout << "You answer the phone. It's your mother asking you to visit her. Do you go? (yes/no)" << endl;
}

cin >> answer;

bool choseVisit = false;

if(answer == "no") {
    cout << "You tell your mother you can't visit her." << endl;
    cout << "She is disappointed." << endl;
}else{
cout << "You decide to visit your mother." << endl;
choseVisit = true;
}

sleep(3);

cout << "\033c";

cout << "A FEW HOURS LATER..." << endl;

cout << "You are hungry. Do you go to the store or a restaurant? (store/restaurant)" << endl;

cin >> answer;

string foodChoice = answer;

cout << "\033c";

if(answer == "store") {
    cout << "You decide to go to the store to get food." << endl;
    cout << "What do you buy?" << endl;
    string item;
    cin >> item;
    cout << "You see a knife on sale. Do you buy it? (yes/no)" << endl;
    cin >> answer;
    if(answer == "yes") {
        cout << "You decide to buy the knife." << endl;
        inventory.push_back("knife");
    }else{
        cout << "You decide not to buy the knife." << endl;
    }
    inventory.push_back(item);
}else{
    cout << "You decide to go to a restaurant to eat." << endl;
    cout << "What do you order?" << endl;
    string food;
    cin >> food;
    cout << "As you are walking, you see a store that sells knives. Do you buy one? (yes/no)" << endl;
    cin >> answer;
    if(answer == "yes") {
        cout << "You decide to buy the knife." << endl;
        inventory.push_back("knife");
    }else{
        cout << "You decide not to buy the knife." << endl;
    }
}

cout << "\033c";

if(choseVisit == false){
    cout << "You return to your house and you call your mother." << endl;
    sleep(1);
    cout <<  "A postal worker answers the phone. He says your mother is dead." << endl;
    sleep(2);
    cout << "You decide to go to her house. Do you take the bus or walk? (bus/walk)" << endl;
    sleep(2);
}else{
cout << "The next morning, you wake up and head to your mother's house. How do you get there? (bus/walk)" << endl;
}

    cin >> answer;
    if(answer == "bus") {
        cout << "You decide to take the bus." << endl;
    }else{
        cout << "You decide to walk." << endl;
    }

cout << "\033c";

sleep(2);

cout << "As you are walking " << ( answer == "bus" ? "to the bus stop" : "to her house" ) <<  ", you are hit by a car." << endl;

sleep(5);

cout << "You wake up in a strange bedroom." << endl;
sleep(2);
cout << "In walks a man and explains that he accidentally hit you with his car and brought you to his house to recover." << endl;
sleep(2);
cout << "Do you want to antagonize him or thank him? (antagonize/thank)" << endl;

cin >> answer;

bool ant = false;

bool leftGroup = false;

if(answer == "antagonize") {
    cout << "You decide to antagonize him." << endl;
    cout << "He gets angry and leaves the room." << endl;
    ant = true;
}else{
    cout << "You thank him and he helps you recover." << endl;
}

sleep(ant ? 5 : 2);

cout << "On the day you leave, the man asks you for help. Do you help him? (yes/no)" << endl;
cin >> answer;

if (answer == "yes") {
    cout << "You decide to help him." << endl;
    cout << "You leave the house and continue your odyssey." << endl;
}else{
    cout << "You decide not to help him, which makes him angry." << endl;

    bool hasKnife = find(inventory.begin(), inventory.end(), "knife") != inventory.end();

    cout << "\033c";

    cout << "He chases you out of his house. Do you stay and fight or run away? (fight/run)" << endl;
    if(hasKnife) cout << "You have a knife, which gives you a better chance of winning the fight." << endl;

    cin >> answer;

    if (answer == "fight"){
    cout << "\033c";
      double chance = hasKnife ? 0.8 : 0.5;

        if (rand() % 100 < chance * 100)
        {
            cout << "You win the fight and escape." << endl;
        }
        else
        {
            cout << "You lose the fight and are dragged back into the house." << endl;
            cout << "You are never seen again." << endl;
            return 0;
        }
    } else {
    cout << "\033c";
    sleep(3);
    cout << "Eventually, you are find a group of outcasts and join them, leaving your old life behind." << endl;
    sleep(2);
    cout << "You are now member of a group of outcasts, living in the woods." << endl;
    sleep(2);
    cout << "Suddenly remember why you were here: " << (choseVisit ? "to visit your mother" : "your mother's death") << endl;
    sleep(2);
    cout << "Do you leave the group and continue your journey? (yes/no)" << endl;
    cin >> answer;
    if(answer == "yes") {
        cout << "You decide to leave the group." << endl;
        cout << "You continue your journey." << endl;
        leftGroup = true;
    }else{
        cout << "You decide to stay with the group." << endl;
        cout << "You live with the group for the rest of your life." << endl;
        return 0;
    }
    }
}

sleep(4);

cout << "\033c";

cout << "After a long journey, you make it to your mother's house." << endl;

if(choseVisit){
    cout << "You knock on the door and your mother answers." << endl;
    sleep(1);
    cout << "She is happy to see you." << endl;
    sleep(1);
    cout << "You spend the week with your parents." << endl;
}else{
    cout << "You knock on the door and no one answers. Do you go in? (yes/no)" << endl;
    cin >> answer;
    if(answer == "no") {
        cout << "\033c";
        cout << "You decide not to go in." << endl;
        cout << "You leave the house and return home." << endl;
    }else{
    sleep(2);
    cout << "\033c";
    cout << "You open the door and everything looks the same." << endl;
    sleep(2);
    cout << "You go to your mother's room and find her sitting in her chair." << endl;
    sleep(2);
    cout << "She ridicules you for not visiting her until you thought she was dead." << endl;
    sleep(2);
    cout << "Do you leave the house? (yes/no)" << endl;
    cin >> answer;
    if (answer == "no")
    {
    if(choseVisit){
        cout << "You decide to stay with your mother." << endl;
        cout << "You live with your mother for the rest of her life." << endl;
    }else{
        cout << "You decide to stand up to your mother." << endl;
        cout << "She gets angry attacks you." << endl;
        sleep(2);
        cout << "Do you fight back? (yes/no)" << endl;
        cin >> answer;
        if (answer == "yes")
        {
            bool hasKnife = find(inventory.begin(), inventory.end(), "knife") != inventory.end();
            double chance = hasKnife ? 0.8 : 0.5;
            if(hasKnife) cout << "You have a knife, which gives you a better chance of winning the fight." << endl;
            if (rand() % 100 < chance * 100)
            {
                cout << "You win the fight and escape." << endl;
            }
            else
            {
                cout << "You lose the fight and are dragged back into the house." << endl;
                cout << "You are never seen again." << endl;
                return 0;
            }
        }
        else
        {
            cout << "You decide not to fight back." << endl;
            cout << "You leave the house and continue your odyssey." << endl;
        }
    }
    }
    }
    }

    cout << "\033c";
    cout << "You leave the house and continue your odyssey." << endl;
    cout << "What do you want to do? \n 1. go home \n 2. move in \n 3. continue" << (leftGroup ? "\n 4. rejoin the outcasts" : "") << endl;
    cin >> answer;
    if(answer == "1") {
        cout << "You decide to go home." << endl;
        cout << "You return home and live the rest of your life in peace." << endl;
    }else{
    if(answer == "2") {
        cout << "You decide to move in." << endl;
        cout << "You live with your parents for the rest of their lives." << endl;
        sleep(3);
        cout << "You inherit the house and live there for the rest of your life." << endl;
    }else{
    if(answer == "4") {
        cout << "You decide to rejoin the outcasts." << endl;
        cout << "You live with the outcasts for the rest of your life." << endl;
    }else{
        cout << "You decide to continue your odyssey." << endl;
        sleep(2);
        towns(true);
    }   
    }    
    }

return 0;
}
