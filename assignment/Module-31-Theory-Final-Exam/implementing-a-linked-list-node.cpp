class Node
{
public:
    int value;
    Node* next;
};

class Node
{
public:
    float number;
    char character;
    Node* next;
    Node* next_to_next;

    // This is constructor. Or, if we use another class to make linked list, we can write our code without this constructor.
    Node(float num, char ch)
    {
        number = num;
        character = ch;
        next = NULL;
        next_to_next = NULL;
    }
};

