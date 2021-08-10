

class Node
{
    private:
    int data;
    Node *next;

    public:
    Node(int x) // Constructor
    {
        data = x;
        next = NULL;
    }

    int get_data() 
    {
        return data;
    }

    Node *get_next() 
    {
        return next;
    }

    void make_link(Node* next_node_address)
    {
        next = next_node_address;
    }

};

