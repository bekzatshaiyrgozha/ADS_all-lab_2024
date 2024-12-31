#include <iostream>
using namespace std;

// Бинарлы іздеу ағашының түйіні
struct Node
{
    int data;    // Түйіннің дерегі
    Node *left;  // Сол жақ баласы
    Node *right; // Оң жақ баласы

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Бинарлы іздеу ағашына жаңа түйін қосу
Node *insert(Node *root, int data)
{
    // Егер ағаш бос болса, жаңа түйін құру
    if (root == nullptr)
    {
        return new Node(data);
    }

    // Егер дерек ағаштың сол жағында орналасуы керек болса
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    // Егер дерек ағаштың оң жағында орналасуы керек болса
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Бинарлы іздеу ағашында іздеу операциясы
bool search(Node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return search(root->left, key); // Сол жаққа қарай іздеу
    }
    else
    {
        return search(root->right, key); // Оң жаққа қарай іздеу
    }
}

// Ағашты ин-ордер (inorder) арқылы шығару
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);       // Сол жақ subtree
    cout << root->data << " "; // Негізгі түйін
    inorder(root->right);      // Оң жақ subtree
}

int main()
{
    Node *root = nullptr; // Ағаштың түбірі бос

    // Ағашқа мәндерді қосу
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Ағаштың ин-ордер бойынша шығару: ";
    inorder(root); // Ин-ордер арқылы ағашты шығару
    cout << endl;

    // Ағаштан мән іздеу
    int key = 40;
    if (search(root, key))
    {
        cout << key << " ағаштан табылды." << endl;
    }
    else
    {
        cout << key << " ағаштан табылмады." << endl;
    }

    return 0;
}
