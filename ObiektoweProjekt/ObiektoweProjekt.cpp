#include <iostream>
#include <string>
#include <vector>
#include <fstream> //zapis/odczyt z pliku
#include <limits> //czyszczenie bufora wejścia 
#include <sstream> 
#include <algorithm> 
#include <cctype> //toupper
using namespace std;

class Pet {
protected:
    string name;
    int age;

private:
    string ownerName;

public:
    Pet(string name, int age, string ownerName)
        : name(name), age(age), ownerName(ownerName) {}

    virtual ~Pet() {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getOwnerName() const {
        return ownerName;
    }

    void setOwnerName(string newOwnerName) { // potrzebne zabezpieczenie, żeby nie było spacji w nazwie właściciela
        ownerName = newOwnerName;
	}

    virtual string getType() const = 0;
    virtual void show() const = 0;
    virtual void modify() = 0;
    virtual string serialize() const = 0;
};

class Dog : public Pet {
protected:
    bool friendly;

private:
    string favouriteToy;

public:
    Dog(string name, int age, string ownerName, bool friendly, string favouriteToy)
        : Pet(name, age, ownerName), friendly(friendly), favouriteToy(favouriteToy) {
    }

    void bark() const {
        cout << name << ": woof!" <<endl;
    }

    string getFavouriteToy() const {
        return favouriteToy;
    }

    void setFavouriteToy(string newFavouriteToy) {
        favouriteToy = newFavouriteToy;
    }
};

class Poodle : public Dog {
protected:
    string haircut;

private:
    bool showDog;

public:
    Poodle(string name, int age, string ownerName, bool friendly, string favouriteToy,
        string haircut, bool showDog)
        : Dog(name, age, ownerName, friendly, favouriteToy),
        haircut(haircut), showDog(showDog) {
    }

    void groom() {
        cout << name << " has been groomed." <<endl;
    }

    bool isShowDog() const {
        return showDog;
    }

    string getType() const override {
        return "Poodle";
    }

    void show() const override {
        cout << "Type: Poodle\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Friendly: " << friendly << endl;
        cout << "Favourite toy: " << getFavouriteToy() << endl;
        cout << "Haircut: " << haircut << endl;
        cout << "Show dog: " << showDog << endl;
        cout << "Owner name: " << getOwnerName() << endl;
    }

    void modify() override {
        cout << "New age: ";
        cin >> age;
        cout << "Friendly? 1/0: ";
        cin >> friendly;
        cout << "New favourite toy: ";
        string toy;
        cin >> toy;
        setFavouriteToy(toy);
        cout << "New haircut: ";
        cin >> haircut;
        cout << "Show dog? 1/0: ";
        cin >> showDog;
		cout << "New owner name: ";
        string owner;
        cin >> owner;
		setOwnerName(owner);
    }

    string serialize() const override {
        return "Poodle " + name + " " + to_string(age) + " " +
            to_string(friendly) + " " + getFavouriteToy() + " " +
			haircut + " " + to_string(showDog) + " " + getOwnerName();
    }

};

class GoldenRetriever : public Dog {
protected:
    bool likesSwimming;

private:
    int fetchSkill;

public:
    GoldenRetriever(string name, int age, string ownerName, bool friendly,
        string favouriteToy, bool likesSwimming, int fetchSkill)
        : Dog(name, age, ownerName, friendly, favouriteToy),
        likesSwimming(likesSwimming), fetchSkill(fetchSkill) {
    }

    string getType() const override {
        return "GoldenRetriever";
    }

    void show() const override {
        cout << "Type: Golden Retriever\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Friendly: " << friendly << endl;
        cout << "Favourite toy: " << getFavouriteToy() << endl;
        cout << "Likes swimming: " << likesSwimming << endl;
        cout << "Fetch skill: " << fetchSkill << endl;
        cout << "Owner name: " << getOwnerName() << endl;
    }

    void modify() override {
        cout << "New age: ";
        cin >> age;
        cout << "Friendly? 1/0: ";
        cin >> friendly;
        cout << "New favourite toy: ";
        string toy;
        cin >> toy;
        setFavouriteToy(toy);
        cout << "Likes swimming? 1/0: ";
        cin >> likesSwimming;
        cout << "Fetch skill: ";
        cin >> fetchSkill;
		cout << "New owner name: ";
        string owner;
		cin >> owner;
		setOwnerName(owner);
    }

    string serialize() const override {
        return "GoldenRetriever " + name + " " + to_string(age) + " " +
            to_string(friendly) + " " + getFavouriteToy() + " " +
			to_string(likesSwimming) + " " + to_string(fetchSkill) + " " + getOwnerName();
    }
};

class Cat : public Pet {
protected:
    int livesLeft;

private:
    bool likesBoxes;

public:
    Cat(string name, int age, string ownerName, int livesLeft, bool likesBoxes)
        : Pet(name, age, ownerName), livesLeft(livesLeft), likesBoxes(likesBoxes) {
    }

    void meow() const {
        cout << name << " meow!" <<endl;
    }

    void loseLife() {
        if (livesLeft > 0) {
            livesLeft--;
        }
    }

    bool getLikesBoxes() const {
        return likesBoxes;
    }

    void setLikesBoxes(bool value) {
        likesBoxes = value;
    }
};

class DomesticShorthair : public Cat {
protected:
    string furColour;

private:
    bool livesOutdoors;

public:
    DomesticShorthair(string name, int age, string ownerName, int livesLeft,
        bool likesBoxes, string furColour, bool livesOutdoors)
        : Cat(name, age, ownerName, livesLeft, likesBoxes),
        furColour(furColour), livesOutdoors(livesOutdoors) {
    }

    string getType() const override {
        return "DomesticShorthair";
    }

    void show() const override {
        cout << "Type: Domestic Shorthair\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Lives left (out of 9): " << livesLeft << endl;
        cout << "Likes boxes: " << getLikesBoxes() << endl;
        cout << "Fur colour: " << furColour << endl;
        cout << "Lives outdoors: " << livesOutdoors << endl;
        cout << "Owner name: " << getOwnerName() << endl;
    }

    void modify() override {
        cout << "New age: ";
        cin >> age;
        cout << "Lives left: ";
        cin >> livesLeft;
        cout << "Likes boxes? 1/0: ";
        bool boxes;
        cin >> boxes;
        setLikesBoxes(boxes);
        cout << "Fur colour: ";
        cin >> furColour;
        cout << "Lives outdoors? 1/0: ";
        cin >> livesOutdoors;
		cout << "New owner name: ";
        string owner;
		cin >> owner;
		setOwnerName(owner);
    }

    string serialize() const override {
        return "DomesticShorthair " + name + " " + to_string(age) + " " +
            to_string(livesLeft) + " " + to_string(getLikesBoxes()) + " " +
			furColour + " " + to_string(livesOutdoors) + " " + getOwnerName();
    }
};

class Ragdoll : public Cat {
protected:
    bool likesCuddles;

private:
    int floppiness;

public:
    Ragdoll(string name, int age, string ownerName, int livesLeft,
        bool likesBoxes, bool likesCuddles, int floppiness)
        : Cat(name, age, ownerName, livesLeft, likesBoxes),
        likesCuddles(likesCuddles), floppiness(floppiness) {
    }

    string getType() const override {
        return "Ragdoll";
    }

    void show() const override {
        cout << "Type: Ragdoll\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Lives left (out of 9): " << livesLeft << endl;
        cout << "Likes boxes: " << getLikesBoxes() << endl;
        cout << "Likes cuddles: " << likesCuddles << endl;
        cout << "Floppiness: " << floppiness << endl;
        cout << "Owner name: " << getOwnerName() << endl;
    }

    void modify() override {
        cout << "New age: ";
        cin >> age;
        cout << "Lives left: ";
        cin >> livesLeft;
        cout << "Likes boxes? 1/0: ";
        bool boxes;
        cin >> boxes;
        setLikesBoxes(boxes);
        cout << "Likes cuddles? 1/0: ";
        cin >> likesCuddles;
        cout << "Floppiness (on a scale of 1 to 10): ";
        cin >> floppiness;
		cout << "New owner name: "; 
		string owner;
		cin >> owner;
		setOwnerName(owner);
    }

    string serialize() const override {
        return "Ragdoll " + name + " " + to_string(age) + " " +
            to_string(livesLeft) + " " + to_string(getLikesBoxes()) + " " +
			to_string(likesCuddles) + " " + to_string(floppiness) + " " + getOwnerName();
    }
};

class Spider : public Pet {
protected:
    bool venomousToHumans;

private:
    int legSpan;

public:
    Spider(string name, int age, string ownerName, bool venomousToHumans, int legSpan)
        : Pet(name, age, ownerName),
        venomousToHumans(venomousToHumans), legSpan(legSpan) {
    }

    void jump() const {
        cout << name << " jumps!" <<endl;
    }

    int getLegSpan() const {
        return legSpan;
    }

    void setLegSpan(int newLegSpan) {
        legSpan = newLegSpan;
    }
};

class JumpingSpider : public Spider {
protected:
    int jumpDistance;

private:
    bool sentient; // hehe, nawiązanie do Dzieci Czasu - polecam :P

public:
    JumpingSpider(string name, int age, string ownerName, bool venomousToHumans,
        int legSpan, int jumpDistance, bool sentient)
        : Spider(name, age, ownerName, venomousToHumans, legSpan),
        jumpDistance(jumpDistance), sentient(sentient) {
    }

    string getType() const override {
        return "JumpingSpider";
    }

    void show() const override {
        cout << "Type: Jumping Spider\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Venomous to humans: " << venomousToHumans << endl;
        cout << "Leg span: " << getLegSpan() << endl;
        cout << "Jump distance: " << jumpDistance << endl;
        cout << "Sentient: " << sentient << endl;
        cout << "Owner name: " << getOwnerName() << endl;
    }

    void modify() override {
        cout << "New age: ";
        cin >> age;
        cout << "Venomous to humans? 1/0: ";
        cin >> venomousToHumans;
        cout << "Leg span: ";
        int span;
        cin >> span;
        setLegSpan(span);
        cout << "Jump distance: ";
        cin >> jumpDistance;
        cout << "Sentient? 1/0: ";
        cin >> sentient;
		cout << "New owner name: ";
		string owner;
		cin >> owner;
		setOwnerName(owner);
    }

    string serialize() const override {
        return "JumpingSpider " + name + " " + to_string(age) + " " +
            to_string(venomousToHumans) + " " + to_string(getLegSpan()) + " " +
			to_string(jumpDistance) + " " + to_string(sentient) + " " + getOwnerName();
    }
};

class Parrot : public Pet {
protected:
    bool canSing;
    bool canSpeak;

private:
    int vocabularySize;

public:
    Parrot(string name, int age, string ownerName, bool canSing,
        bool canSpeak, int vocabularySize)
        : Pet(name, age, ownerName),
        canSing(canSing), canSpeak(canSpeak), vocabularySize(vocabularySize) {
    }

    void sing() const {
        if (canSing) {
			cout << name << ": la-la-la " <<endl; 
        }
    }

    void speak() const {
        if (canSpeak) {
            cout << name << ": I can speak!" <<endl;
        }
    }

    string getType() const override {
        return "Parrot";
    }

    void show() const override {
        cout << "Type: Parrot\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Can sing: " << canSing << endl;
        cout << "Can speak: " << canSpeak << endl;
        cout << "Vocabulary size: " << vocabularySize << endl;
        cout << "Owner name: " << getOwnerName() << endl;
    }

    void modify() override {
        cout << "New age: ";
        cin >> age;
        cout << "Can sing? 1/0: ";
        cin >> canSing;
        cout << "Can speak? 1/0: ";
        cin >> canSpeak;
        cout << "Vocabulary size: ";
        cin >> vocabularySize;
		cout << "New owner name: ";
		string owner;
		cin >> owner;
		setOwnerName(owner);
    }

    string serialize() const override {
        return "Parrot " + name + " " + to_string(age) + " " +
            to_string(canSing) + " " + to_string(canSpeak) + " " +
			to_string(vocabularySize) + " " + getOwnerName();
    }
};

class ClassNode {
private:
    string name;
    vector<ClassNode*> children;
    ClassNode* parent;

public:
    ClassNode(string name) {
        this->name = name;
        this->parent = nullptr;
    }

    ~ClassNode() {
        for (ClassNode* child : children) {
            delete child;
        }
    }

    string getName() const {
        return name;
    }

    ClassNode* getParent() const {
        return parent;
    }

    vector<ClassNode*> getChildren() const {
        return children;
    }

    void addChild(ClassNode* child) {
        child->parent = this;
        children.push_back(child);
    }

    bool isLeaf() const {
        return children.empty();
    }
};

string trim(const string& text) { // funkcja pomocnicza do usuwania spacji z początku i końca stringa, żeby nie było problemów z wczytywaniem komend
    int start = 0;
    int end = text.length() - 1;

    while (start < text.length() && isspace(text[start])) {
        start++;
    }

    while (end >= start && isspace(text[end])) {
        end--;
    }

    if (start > end) {
        return "";
    }

    return text.substr(start, end - start + 1);
}

string toUpperString(string text) { // funkcja pomocnicza do zamiany stringa na wielkie litery, żeby nie było problemów z wczytywaniem komend niezależnie od tego, czy użytkownik wpisze je wielkimi czy małymi literami
    for (char& ch : text) {
        ch = toupper(ch);
    }

    return text;
}

string normalizeKey(string text) { // funkcja pomocnicza do normalizacji kluczy, czyli usuwania spacji i zamiany na małe litery, żeby nie było problemów z wczytywaniem nazw klas niezależnie od tego, czy użytkownik wpisze je z dużymi literami i spacjami czy bez
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i]; // pobieramy aktualny znak dla każdego znaku w stringu, 

        if (!isspace(ch)) { //sprawdzamy czy nie jest spacją,
            result = result + (char)tolower(ch); // jeśli nie jest, to dodajemy go do wyniku po zamianie na małą liter
        }
    }

    return result;
}

string normalizeClassName(string input) {
    string key = normalizeKey(input);

    if (key == "pet") {
        return "Pet";
    }
    else if (key == "dog") {
        return "Dog";
    }
    else if (key == "poodle") {
        return "Poodle";
    }
    else if (key == "goldenretriever") {
        return "GoldenRetriever";
    }
    else if (key == "cat") {
        return "Cat";
    }
    else if (key == "domesticshorthair") {
        return "DomesticShorthair";
    }
    else if (key == "ragdoll") {
        return "Ragdoll";
    }
    else if (key == "spider") {
        return "Spider";
    }
    else if (key == "jumpingspider") {
        return "JumpingSpider";
    }
    else if (key == "parrot") {
        return "Parrot";
    }

    return "";
}

struct ParsedCommand {
    string command;
    string argument;
};

ParsedCommand parseCommandLine(string line) {
    line = trim(line); // usuwamy spacje z początku i końca, żeby nie było problemów z wczytywaniem komend

    ParsedCommand result; // tworzymy strukturę, która będzie przechowywać rozdzieloną komendę i argument
    result.command = "";
    result.argument = "";

    if (line == "") { // jeśli po usunięciu spacji linia jest pusta, to zwracamy pustą komendę
        return result;
    }

    stringstream ss(line); //stringstream to klasa, która pozwala traktować string jak strumień danych, żeby łatwo rozdzielić komendę od argumentu

    ss >> result.command; // wczytujemy pierwsze słowo jako komendę
    result.command = toUpperString(result.command); // zamieniamy komendę na wielkie litery

    string rest; // wczytujemy resztę linii jako argument, jeśli jest jakiś
    getline(ss, rest); // wczytujemy resztę linii do zmiennej rest

    result.argument = trim(rest); // usuwamy spacje z początku i końca argumentu, żeby nie było problemów z wczytywaniem argumentów

    return result;
}

bool isValidCommand(string command) {
    vector<string> validCommands = {
        "SAVE", "READ", "DIR", "TREE", "SHOW", "DO", "MDO", "CD", "MO", "EXIT"
    };

    for (const string& cmd : validCommands) {
        if (command == cmd) {
            return true;
        }
    }

    return false;
}

ClassNode* buildClassTree() {
    ClassNode* pet = new ClassNode("Pet");

    ClassNode* parrot = new ClassNode("Parrot");

    ClassNode* dog = new ClassNode("Dog");
    ClassNode* poodle = new ClassNode("Poodle");
    ClassNode* goldenRetriever = new ClassNode("GoldenRetriever");

    ClassNode* cat = new ClassNode("Cat");
    ClassNode* domesticShorthair = new ClassNode("DomesticShorthair");
    ClassNode* ragdoll = new ClassNode("Ragdoll");

    ClassNode* spider = new ClassNode("Spider");
    ClassNode* jumpingSpider = new ClassNode("JumpingSpider");

    pet->addChild(parrot);

    pet->addChild(dog);
    dog->addChild(poodle);
    dog->addChild(goldenRetriever);

    pet->addChild(cat);
    cat->addChild(domesticShorthair);
    cat->addChild(ragdoll);

    pet->addChild(spider);
    spider->addChild(jumpingSpider);

    return pet;
}

void printTree(ClassNode* node, int depth = 0) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        cout << "   ";
    }

    cout << node->getName() <<endl;

    for (ClassNode* child : node->getChildren()) {
        printTree(child, depth + 1);
    }
}

ClassNode* findNode(ClassNode* node, string name) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->getName() == name) {
        return node;
    }

    for (ClassNode* child : node->getChildren()) {
        ClassNode* found = findNode(child, name);

        if (found != nullptr) {
            return found;
        }
    }

    return nullptr;
}

void cd(ClassNode* root, ClassNode*& currentNode, string nodeName) {
    string normalizedName = normalizeClassName(nodeName);

    if (normalizedName == "") {
        cout << "Class node not found.\n";
        cout << "Available class names: Pet, Dog, Poodle, GoldenRetriever, Cat, DomesticShorthair, Ragdoll, Spider, JumpingSpider, Parrot.\n";
        return;
    }

    ClassNode* found = findNode(root, normalizedName);

    if (found != nullptr) {
        currentNode = found;
        cout << "Current node: " << currentNode->getName() << endl;
    }
    else {
        cout << "Class node not found." << endl;
    }
}

bool containsType(ClassNode* node, string typeName) {
    if (node == nullptr) {
        return false;
    }

    if (node->getName() == typeName) {
        return true;
    }

    for (ClassNode* child : node->getChildren()) {
        if (containsType(child, typeName)) {
            return true;
        }
    }

    return false;
}

class PetManager {
private:
    vector<Pet*> pets;

public:
    void addPet(Pet* pet) {
        pets.push_back(pet);
    }

    Pet* createPetForCurrentNode(ClassNode* currentNode, string name) {
        if (currentNode == nullptr) {
            cout << "No current node.\n";
            return nullptr;
        }

        if (!currentNode->isLeaf()) {
            cout << "Objects can only be created in leaf classes.\n";
            return nullptr;
        }

        string type = currentNode->getName();

        Pet* created = nullptr;

            if (type == "Poodle") {
                int age;
                bool friendly;
                string toy;
                string haircut;
                bool showDog;
                string owner;

                cout << "Age: ";
                cin >> age;
                cout << "Friendly? 1/0: ";
                cin >> friendly;
                cout << "Favourite toy: ";
                cin >> toy;
                cout << "Haircut: ";
                cin >> haircut;
                cout << "Show dog? 1/0: ";
                cin >> showDog;
                cout << "Owner name: ";
                cin >> owner;

                created = new Poodle(name, age, owner, friendly, toy, haircut, showDog);
            }
            else if (type == "GoldenRetriever") {
                int age;
                bool friendly;
                string toy;
                bool likesSwimming;
                int fetchSkill;
                string owner;

                cout << "Age: ";
                cin >> age;
                cout << "Friendly? 1/0: ";
                cin >> friendly;
                cout << "Favourite toy: ";
                cin >> toy;
                cout << "Likes swimming? 1/0: ";
                cin >> likesSwimming;
                cout << "Fetch skill (int): ";
                cin >> fetchSkill;
                cout << "Owner name: ";
                cin >> owner;

                created = new GoldenRetriever(name, age, owner, friendly, toy, likesSwimming, fetchSkill);
            }
            else if (type == "DomesticShorthair") {
                int age;
                int livesLeft;
                bool likesBoxes;
                string furColour;
                bool livesOutdoors;
                string owner;

                cout << "Age: ";
                cin >> age;
                cout << "Lives left: ";
                cin >> livesLeft;
                cout << "Likes boxes? 1/0: ";
                cin >> likesBoxes;
                cout << "Fur colour: ";
                cin >> furColour;
                cout << "Lives outdoors? 1/0: ";
                cin >> livesOutdoors;
                cout << "Owner name: ";
                cin >> owner;

                created = new DomesticShorthair(name, age, owner, livesLeft, likesBoxes, furColour, livesOutdoors);
            }
            else if (type == "Ragdoll") {
                int age;
                int livesLeft;
                bool likesBoxes;
                bool likesCuddles;
                int floppiness;
                string owner;

                cout << "Age: ";
                cin >> age;
                cout << "Lives left: ";
                cin >> livesLeft;
                cout << "Likes boxes? 1/0: ";
                cin >> likesBoxes;
                cout << "Likes cuddles? 1/0: ";
                cin >> likesCuddles;
                cout << "Floppiness (1-10): ";
                cin >> floppiness;
                cout << "Owner name: ";
                cin >> owner;

                created = new Ragdoll(name, age, owner, livesLeft, likesBoxes, likesCuddles, floppiness);
            }
            else if (type == "JumpingSpider") {
                int age;
                bool venomous;
                int legSpan;
                int jumpDistance;
                bool sentient;
                string owner;

                cout << "Age: ";
                cin >> age;
                cout << "Venomous to humans? 1/0: ";
                cin >> venomous;
                cout << "Leg span: ";
                cin >> legSpan;
                cout << "Jump distance: ";
                cin >> jumpDistance;
                cout << "Sentient? 1/0: ";
                cin >> sentient;
                cout << "Owner name: ";
                cin >> owner;

                created = new JumpingSpider(name, age, owner, venomous, legSpan, jumpDistance, sentient);
            }
            else if (type == "Parrot") {
                int age;
                bool canSing;
                bool canSpeak;
                int vocab;
                string owner;

                cout << "Age: ";
                cin >> age;
                cout << "Can sing? 1/0: ";
                cin >> canSing;
                cout << "Can speak? 1/0: ";
                cin >> canSpeak;
                cout << "Vocabulary size: ";
                cin >> vocab;
                cout << "Owner name: ";
                cin >> owner;

                created = new Parrot(name, age, owner, canSing, canSpeak, vocab);
            }

            if (created == nullptr) {
                cout << "Unknown pet type.\n";
            }

            return created;
    }


    Pet* findPetByName(string name) {
        for (Pet* pet : pets) {
            if (pet->getName() == name) {
                return pet;
            }
        }

        return nullptr;
    }

    void deletePetByName(string name, ClassNode* currentNode) {
        if (!currentNode->isLeaf()) {
            cout << "Objects can only be deleted in leaf classes.\n";
            return;
        }

        for (auto it = pets.begin(); it != pets.end(); ++it) {
            if ((*it)->getName() == name && (*it)->getType() == currentNode->getName()) {
                delete *it;
                pets.erase(it);
                cout << "Pet deleted.\n";
                return;
            }
        }

        cout << "Pet not found in current leaf.\n";
    }

    void modifyPetByName(string name, ClassNode* currentNode) {
        if (!currentNode->isLeaf()) {
            cout << "Objects can only be modified in leaf classes.\n";
            return;
        }

		for (auto it = pets.begin(); it != pets.end(); ++it) { //it = iterator, czyli wskaźnik do elementu wektora, który możemy przesuwać i modyfikować
            if ((*it)->getName() == name && (*it)->getType() == currentNode->getName()) {
                (*it)->modify();
                return;
            }
        }

        cout << "Pet not found in current leaf.\n";
    }

    void showPetByName(string name) {
        Pet* pet = findPetByName(name);

        if (pet != nullptr) {
            pet->show();
        }
        else {
            cout << "Pet not found.\n";
        }
    }

    void showAllPets() {
        for (Pet* pet : pets) {
            cout << pet->getName() << " (" << pet->getType() << ")" << endl;
        }
    }

    void dir(ClassNode* currentNode) {
        bool foundAny = false;

        cout << "Pets visible from current node: " << endl;

        for (Pet* pet : pets) {
            if (containsType(currentNode, pet->getType())) {
                cout << "- " << pet->getName()
                    << " (" << pet->getType() << ")"
                    << ", owner: " << pet->getOwnerName()
                    << endl;

                foundAny = true;
            }
        }

        if (!foundAny) {
            cout << "No pets visible from this node.\n";
        }
    }

    void saveToFile(string filename) {
		ofstream file(filename); // ofstream to klasa do zapisywania danych do pliku

        if (!file) {
            cout << "Could not open file for writing.\n";
            return;
        }

        for (Pet* pet : pets) {
			file << pet->serialize() << endl; // znaki << zapisują dane do pliku, a pet->serialize() zwraca stringa z danymi peta w formacie, który można potem łatwo odczytać
        }

        file.close();
        cout << "Saved to " << filename << endl;
    }

    void readFromFile(string filename) {
		ifstream file(filename); // ifstream to klasa do wczytywania danych z pliku

        if (!file) {
            cout << "Could not open file.\n";
            return;
        }

        clearPets();

        string type;

        while (file >> type) { // tworzenie obiektow zależnie od typu
            if (type == "Poodle") {
                string name, owner, toy, haircut;
                int age;
                bool friendly, showDog;
                file >> name >> age >> friendly >> toy >> haircut >> showDog >> owner;
                addPet(new Poodle(name, age, owner, friendly, toy, haircut, showDog));
            }
            else if (type == "GoldenRetriever") {
                string name, owner, toy;
                int age, fetchSkill;
                bool friendly, likesSwimming;
                file >> name >> age >> friendly >> toy >> likesSwimming >> fetchSkill >> owner;
                addPet(new GoldenRetriever(name, age, owner, friendly, toy, likesSwimming, fetchSkill));
            }
            else if (type == "DomesticShorthair") {
                string name, owner, furColour;
                int age, livesLeft;
                bool likesBoxes, livesOutdoors;
                file >> name >> age >> livesLeft >> likesBoxes >> furColour >> livesOutdoors >> owner;
                addPet(new DomesticShorthair(name, age, owner, livesLeft, likesBoxes, furColour, livesOutdoors));
            }
            else if (type == "Ragdoll") {
                string name, owner;
                int age, livesLeft, floppiness;
                bool likesBoxes, likesCuddles;
                file >> name >> age >> livesLeft >> likesBoxes >> likesCuddles >> floppiness >> owner;
                addPet(new Ragdoll(name, age, owner, livesLeft, likesBoxes, likesCuddles, floppiness));
            }
            else if (type == "JumpingSpider") {
                string name, owner;
                int age, legSpan, jumpDistance;
                bool venomousToHumans, sentient;
                file >> name >> age >> venomousToHumans >> legSpan >> jumpDistance >> sentient >> owner;
                addPet(new JumpingSpider(name, age, owner, venomousToHumans, legSpan, jumpDistance, sentient));
            }
            else if (type == "Parrot") {
                string name, owner;
                int age,vocab;
                bool canSing , canSpeak;
                file >> name >> age>> canSing>> canSpeak>> vocab>>owner;
                addPet(new Parrot(name ,age ,owner ,canSing ,canSpeak ,vocab));
			}


        }

        file.close();
        cout << "Loaded from " << filename << endl;
    }

    void clearPets() {
        for (Pet* pet : pets) {
            delete pet; 
        }

		pets.clear(); // usuwamy wszystkie wskaźniki z wektora po usunięciu obiektów, żeby nie było wiszących wskaźników
    }

    ~PetManager() {
        clearPets();
    }
};


 
void menu() {
    cout << "Command format: COMMAND optional_argument\n\n";

    cout << "Available commands:\n";
    cout << "TREE                  - show class hierarchy\n";
    cout << "DIR                   - list pets visible from current class node\n"; //directory
    cout << "CD [class]            - change current class node\n"; //change directory 
	cout << "SHOW [pet_name]       - show details of a pet, must be visible from current class node\n";
	cout << "MO [pet_name]         - create a new pet in the current leaf class\n"; // make object
	cout << "DO [pet_name]         - delete a pet from the current leaf class\n"; // delete object
	cout << "MDO [pet_name]        - modify a pet from the current leaf class\n"; // modify object
    cout << "SAVE [file_name]      - save pets to a file\n";
    cout << "READ [file_name]      - read pets from a file\n";
    cout << "EXIT                  - exit the program\n\n";

    cout << "Examples:\n";
    cout << "CD golden retriever\n";
    cout << "CD Domestic Shorthair\n";
    cout << "DIR\n";
    cout << "SHOW Fifi\n";
    cout << "SAVE pets.txt\n\n";

    cout << "Notes:\n";
    cout << "- Creating, deleting and modifying pets is possible only in leaf classes.\n";
    cout << "- Leaf classes: Parrot, Poodle, GoldenRetriever, DomesticShorthair, Ragdoll, JumpingSpider.\n";
    cout << "- For yes/no questions, enter 1 for yes and 0 for no.\n";
    cout << "- Use one-word values or underscores instead of spaces, e.g. rubber_ball, Anna_Kowalska.\n\n";
}

void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 
}

int main() {
    ClassNode* root = buildClassTree();
    ClassNode* currentNode = root;
    PetManager manager;
    manager.addPet(new Poodle("Fifi", 3, "Anna", true, "ball", "curly", true));
    manager.addPet(new GoldenRetriever("Max", 5, "Kuba", true, "stick", true, 8));
    manager.addPet(new DomesticShorthair("Mika", 4, "Ola", 9, true, "black", false));
    manager.addPet(new JumpingSpider("Portia", 1, "Tomasz", false, 2, 15, true));

    cout << "Welcome to the Pet Database program!\n";
    cout << "Sample pets have been loaded automatically.\n";
    cout << "Press Enter to start...";
    cin.get();

    string line;

    while (true) {
        system("cls");
        menu();

        cout << "Current class node: " << currentNode->getName();

        if (currentNode->isLeaf()) {
            cout << " (leaf - you can create/delete/modify pets here)";
        }
        else {
            cout << " (not a leaf - DIR and CD available, but not MO/DO/MDO)";
        }

		cout << "\n> "; // wiersz poleceń, gdzie użytkownik wpisuje komendy
        getline(cin, line);

        ParsedCommand parsed = parseCommandLine(line);

        string command = parsed.command;
        string argument = parsed.argument;

        if (!isValidCommand(command)) {
            cout << "Unknown command.\n";
            waitForEnter();
            continue;
        }

        if (command == "TREE") {
            printTree(root);
            waitForEnter();
        }

        else if (command == "SAVE") {
            if (argument == "") {
                cout << "Missing file name.\n";
                cout << "Example: SAVE pets.txt\n";
            }
            else {
                manager.saveToFile(argument);
            }

            waitForEnter();
        }

        else if (command == "READ") {
            if (argument == "") {
                cout << "Missing file name.\n";
                cout << "Example: READ pets.txt\n";
            }
            else {
                manager.readFromFile(argument);
            }

            waitForEnter();
        }

        else if (command == "DIR") {
            manager.dir(currentNode);
            waitForEnter();
        }

        else if (command == "CD") {
            if (argument == "") {
                cout << "Missing class name.\n";
                cout << "Example: CD golden retriever\n";
            }
            else {
                cd(root, currentNode, argument);
            }

            waitForEnter();
        }

        else if (command == "SHOW") {
            if (argument == "") {
                cout << "Missing pet name.\n";
                cout << "Example: SHOW Fifi\n";
            }
            else {
                manager.showPetByName(argument);
            }

            waitForEnter();
        }

        else if (command == "MDO") {
            if (argument == "") {
                cout << "Missing pet name.\n";
                cout << "Example: MDO Max\n";
            }
            else {
                manager.modifyPetByName(argument, currentNode);
            }

            waitForEnter();
        }

        else if (command == "DO") {
            if (argument == "") {
                cout << "Missing pet name.\n";
            }
            else {
                manager.deletePetByName(argument, currentNode);
            }

            waitForEnter();
        }

        else if (command == "MO") {
            if (argument == "") {
                cout << "Missing pet name.\n";
                cout << "Example: MO Portia\n";
            }
            else if (!currentNode->isLeaf()) {
                cout << "Objects can only be created in leaf nodes.\n";
            }
            else {
                Pet* newPet = manager.createPetForCurrentNode(currentNode, argument);

                if (newPet != nullptr) {
                    manager.addPet(newPet);
                    cout << "Pet created and added.\n";
                }
            }

            waitForEnter();
        }

        else if (command == "EXIT") {
            cout << "Exiting program. Goodbye!\n";
            break;
            }
    }

    delete root;

    return 0;
}
