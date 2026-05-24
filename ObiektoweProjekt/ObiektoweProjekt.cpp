#include <iostream>
#include <string>
#include <vector>
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
        cout << name << ": woof!" << endl;
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
        cout << name << " has been groomed." << endl;
    }

    bool isShowDog() const {
        return showDog;
    }

    string getType() const override {
        return "Poodle";
    }

    void show() const override {
        cout << "Type: Poodle\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Friendly: " << friendly << "\n";
        cout << "Favourite toy: " << getFavouriteToy() << "\n";
        cout << "Haircut: " << haircut << "\n";
        cout << "Show dog: " << showDog << "\n";
        cout << "Owner name: " << getOwnerName() << "\n";
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
            haircut + " " + to_string(showDog);
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
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Friendly: " << friendly << "\n";
        cout << "Favourite toy: " << getFavouriteToy() << "\n";
        cout << "Likes swimming: " << likesSwimming << "\n";
        cout << "Fetch skill: " << fetchSkill << "\n";
        cout << "Owner name: " << getOwnerName() << "\n";
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
            to_string(likesSwimming) + " " + to_string(fetchSkill);
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
        cout << name << " meow!" << endl;
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
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Lives left (out of 9): " << livesLeft << "\n";
        cout << "Likes boxes: " << getLikesBoxes() << "\n";
        cout << "Fur colour: " << furColour << "\n";
        cout << "Lives outdoors: " << livesOutdoors << "\n";
        cout << "Owner name: " << getOwnerName() << "\n";
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
            furColour + " " + to_string(livesOutdoors);
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
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Lives left (out of 9): " << livesLeft << "\n";
        cout << "Likes boxes: " << getLikesBoxes() << "\n";
        cout << "Likes cuddles: " << likesCuddles << "\n";
        cout << "Floppiness: " << floppiness << "\n";
        cout << "Owner name: " << getOwnerName() << "\n";
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
            to_string(likesCuddles) + " " + to_string(floppiness);
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
        cout << name << " jumps!" << endl;
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
    bool sentient; // hehe, Children of Time reference - great book, would recommend

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
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Venomous to humans: " << venomousToHumans << "\n";
        cout << "Leg span: " << getLegSpan() << "\n";
        cout << "Jump distance: " << jumpDistance << "\n";
        cout << "Sentient: " << sentient << "\n";
        cout << "Owner name: " << getOwnerName() << "\n";
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
            to_string(jumpDistance) + " " + to_string(sentient);
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
			cout << name << ": la-la-la " << endl; 
        }
    }

    void speak() const {
        if (canSpeak) {
            cout << name << ": I can speak!" << endl;
        }
    }

    string getType() const override {
        return "Parrot";
    }

    void show() const override {
        cout << "Type: Parrot\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Can sing: " << canSing << "\n";
        cout << "Can speak: " << canSpeak << "\n";
        cout << "Vocabulary size: " << vocabularySize << "\n";
        cout << "Owner name: " << getOwnerName() << "\n";
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
            to_string(vocabularySize);
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

    cout << node->getName() << endl;

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

void changeDirectory(ClassNode* root, ClassNode*& currentNode, string nodeName) {
    ClassNode* found = findNode(root, nodeName);

    if (found != nullptr) {
        currentNode = found;
        cout << "Current node: " << currentNode->getName() << endl;
    }
    else {
        cout << "Class node not found.\n";
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

    Pet* findPetByName(string name) {
        for (Pet* pet : pets) {
            if (pet->getName() == name) {
                return pet;
            }
        }

        return nullptr;
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

        for (Pet* pet : pets) {
            if (containsType(currentNode, pet->getType())) {
                cout << pet->getName()
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

    ~PetManager() {
        for (Pet* pet : pets) {
            delete pet;
        }
    }
};

/*

Program ma umożliwiać poruszanie się w strukturze klas z linii komend. Nazwy komend
które należy zaimplementować to:
● CD [nazwa węzła(klasy)]- zmiana węzła w strukturze
● MO [obiekt] - tworzy obiekt o nazwie „obiekt” dla bieżącego liścia– należy podać
parametry obiektu
● DO [obiekt] - usuwa obiekt o nazwie „obiekt”dla bieżącego liścia
● MDO [obiekt] - modyfikacja obiektu o nazwie „obiekt”dla bieżącego liścia
● DIR - wyświetla informacje o obiektach widocznych z danego poziomu - domyślnie
tylko informacje o nazwach obiektów (wyświetla listę wszystkich obiektów należących
do liści, które dziedziczą z danej klasy
● SHOW [obiekt] – wyświetla szczegółowe informacje o obiekcie
● SAVE – zapis zbioru do pliku
● READ – odczyt zbioru z pliku
● TREE - wyświetla całą strukturę przedstawioną na rysunku np. w formie wcięć

*/


int main() {
    ClassNode* root = buildClassTree();
    ClassNode* currentNode = root;

    PetManager manager;

    manager.addPet(new Poodle("Fifi", 3, "Anna", true, "ball", "curly", true));
    manager.addPet(new GoldenRetriever("Max", 5, "Kuba", true, "stick", true, 8));
    manager.addPet(new DomesticShorthair("Mika", 4, "Ola", 9, true, "black", false));
    manager.addPet(new Ragdoll("Luna", 2, "Marta", 9, true, true, 10));
    manager.addPet(new JumpingSpider("Portia", 1, "Tomasz", false, 2, 15, true));
    manager.addPet(new Parrot("Polly", 6, "Karolina", true, true, 50));

    cout << "TREE:\n";
    printTree(root);

    cout << "\nDIR from Pet:\n";
    manager.dir(currentNode);

    cout << "\nCD Dog:\n";
    changeDirectory(root, currentNode, "Dog");

    cout << "\nDIR from Dog:\n";
    manager.dir(currentNode);

    cout << "\nCD Cat:\n";
    changeDirectory(root, currentNode, "Cat");

    cout << "\nDIR from Cat:\n";
    manager.dir(currentNode);

    cout << "\nCD Poodle:\n";
    changeDirectory(root, currentNode, "Poodle");

    cout << "\nDIR from Poodle:\n";
    manager.dir(currentNode);

    delete root;

    return 0;
}
