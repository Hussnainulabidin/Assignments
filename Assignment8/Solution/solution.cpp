#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class NodeTask
{
public:
    int taskID;
    string description;
    int priorityLevel;
    string assigneeID;
    bool completed;

    NodeTask* parent;
    NodeTask* left;
    NodeTask* right;
    string color;
    NodeTask(int taskid, string desc, int priority, string ID)
    {
        this->taskID = taskid;
        this->description = desc;
        this->priorityLevel = priority;
        this->assigneeID = ID;
        this->completed = false;

        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
        this->color = "R";
    }
};

class Node
{
public:
    string firstName;
    string lastName;
    string address;
    string dateOfBirth;
    string assigneeID;
    int intID;

    string color;
    Node* left;
    Node* right;
    Node* parent;

    Node(string First, string Last, string Address, string DOB, string ID)
    {
        this->firstName = First;
        this->lastName = Last;
        this->dateOfBirth = DOB;
        this->address = Address;
        this->assigneeID = ID;

        this->left = NULL;
        this->right = NULL;
        color = "R";
    }
    void changeColor()
    {
        if (this->color == "B")
            this->color = "R";
        else
            this->color = "B";
    }
};

class taskManagementSystem
{
public:
    Node* root;
    NodeTask* rootTask;
    int count;

    taskManagementSystem()
    {
        root = NULL;
        rootTask = NULL;
        count = 0;
    }
    string createID()
    {
        count += 1;
        int rem = 0;
        int num = count;
        string id = "";
        while (num != 0)
        {
            rem = num % 10;
            num = num / 10;
            id += rem + 48;
        }
        int n = id.length();
        for (int i = 0; i < n / 2; i++)
            swap(id[i], id[n - i - 1]);
        return id;
    }
    void addAssignee(string firstName, string lastName, string address, string DOB)
    {
        Node*& currentRoot = root;
        string id = "A00" + this->createID();
        Node* newNode = new Node(firstName, lastName, address, DOB, id);
        newNode->intID = count;
        if (root == NULL)
        {
            newNode->changeColor();
            newNode->parent = NULL;
            root = newNode;
        }
        else
        {
            Node* current = root;
            while (current->right != NULL)
            {
                current = current->right;
            }
            current->right = newNode;
            newNode->parent = current;

            if (current->color == "R") // parent color is red and newNode is also red
            {
                char key0 = '\0';
                char key1 = 'R';
                char key2 = 'R';

                if (newNode->parent->parent != NULL)
                {
                    if (newNode->parent->parent->parent != NULL)
                    {
                        key0 = 'R';
                    }
                }
                this->adjacentRed(newNode, key0, key1, key2, currentRoot);
            }
        }
    }
    void DeleteAssignee(string assigneeID)
    {
        Node* current = NULL;
        inorderFindAssignee(root, assigneeID, current);
        if (current == NULL)
            return;
        NodeTask* checkTask = NULL;
        inorderFindTask(rootTask, current->assigneeID, checkTask);

        if (checkTask != NULL)
            return;
        if (current->right == NULL && current->left == NULL)
        {
            if (current == root)
            {
                rootTask = NULL;
                return;
            }
            if (current->color == "R")
            {
                if (current->parent->right == current)
                {
                    current->parent->right = NULL;
                }
                else
                {
                    current->parent->left = NULL;
                }
            }
            else
            {
                current->color = "DB";
                checkDoubleBlackCases(current->parent, current, root);
            }
        }
        else
        {
            // Find Inorder predecessor
            replaceRootWithPredecessor(current, root);
        }
    }

    void displaybyID(stringstream& actualOutput, string ID)
    {
        int id = stoiID(ID);
        Node* current = root;
        while (current != NULL)
        {
            if (current->intID == id)
            {
                actualOutput << "Name: " << current->firstName << " " + current->lastName << ", Address: " << current->address << ", DOB: " << current->dateOfBirth << ", Assignee ID: " << current->assigneeID << endl;
                break;
            }
            if (current->intID < id)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        return;
    }
    void displaybyname(stringstream& actualOutput, string firstName, string lastName)
    {
        Node* current = root;
        actualOutput;
        inorderDisplaybyname(root, firstName, lastName, actualOutput);
    }
    void AssigneeWithNoTask(stringstream& actualOutput)
    {
        inorderAssigneeWithNoTask(root, actualOutput);
    }
    void DisplayAssignee(stringstream& actualOutput)
    {
        inorderDisplayAssignee(root, actualOutput);
    }
    void AssigneeInOrder(stringstream& actualOutput)
    {
        inorderAssigneeInOrder(root, actualOutput);
    }

    void addTask(int id, string desc, int priority, string assigneeId)
    {
        NodeTask*& currentRoot = rootTask;
        NodeTask* newNode = new NodeTask(id, desc, priority, assigneeId);
        if (rootTask == NULL)
        {
            newNode->color = "B";
            rootTask = newNode;
        }
        else
        {
            char key0 = '\0';
            char key1 = '\0';
            char key2 = '\0';
            NodeTask* current = rootTask;
            int i = 0;
            while (current != NULL)
            {
                i++;
                if (i == 10)
                    break;
                if (current->priorityLevel > priority)
                {
                    if (current->left == NULL)
                    {
                        key1 = 'L';
                        current->left = newNode;
                        break;
                    }
                    key0 = key2;
                    key2 = 'L';

                    current = current->left;
                }
                else
                {
                    if (current->right == NULL)
                    {
                        key1 = 'R';
                        current->right = newNode;
                        break;
                    }
                    key0 = key2;
                    key2 = 'R';
                    current = current->right;
                }
            }
            newNode->parent = current;
            if (current->color == "R") // parent color is red and newNode is also red
            {
                this->adjacentRed(newNode, key0, key1, key2, currentRoot);
            }
        }
    }
    void deleteTask(int id)
    {
        cout << id << endl;
        NodeTask* current = NULL;
        inorderFindTask(rootTask, id, current);
        if (current == NULL)
        {
            return;
        }
        if (current->right == NULL && current->left == NULL)
        {
            if (current == rootTask)
            {
                rootTask = NULL;
                return;
            }
            if (current->color == "R")
            {
                if (current->parent->right == current)
                {
                    current->parent->right = NULL;
                }
                else
                {
                    current->parent->left = NULL;
                }
            }
            else
            {
                cout << "Double Black is Formed" << endl;
                current->color = "DB";
                current->assigneeID = "NIL";
                checkDoubleBlackCases(current->parent, current, rootTask);
            }
        }
        else
        {
            // Find Inorder predecessor
            cout << "Find Pred" << endl;
            replaceRootWithPredecessor(current, rootTask);
        }
    }

    void findTasksByAssignee(string assigneeID, stringstream& actualOutput)
    {
        string Name = "";
        inorderGetAssigneeName(root, Name, assigneeID);
        actualOutput << "Tasks Assigned to \"" << Name << " (" << assigneeID << ")\":" << endl;
        inorderTasksByAssignee(rootTask, assigneeID, actualOutput);
    }
    void findHighestPriorityTask(stringstream& actualOutput)
    {
        if (rootTask == NULL)
            return;
        NodeTask* current = rootTask;
        while (current->left != NULL)
        {
            current = current->left;
        }
        inorderfindHighestPriorityTask(rootTask, current->priorityLevel, actualOutput);
    }
    void updateTaskPriority(int taskID, int newPriority)
    {
        NodeTask* findNode = NULL;
        inorderFindTask(rootTask, taskID, findNode);
        if (findNode->completed == true)
            return;
        if (findNode != NULL)
        {
            NodeTask* newNode = new NodeTask(findNode->taskID, findNode->description, findNode->priorityLevel, findNode->assigneeID);
            deleteTask(taskID);
            newNode->priorityLevel = newPriority;
            addTask(newNode->taskID, newNode->description, newNode->priorityLevel, newNode->assigneeID);
        }
    }
    void completeTask(int id)
    {
        inorderCompleteTask(rootTask, id);
    }
    void ShiftTask(string assigneeID_1, string assigneeID_2)
    {
        inorderShiftTask(rootTask, assigneeID_1, assigneeID_2);
    }
    void printTaskQueue(stringstream& actualOutput)
    {
        inorderprintTaskQueue(rootTask, actualOutput);
    }
    void countTotalTasks(stringstream& actualOutput)
    {
        int count = 0;
        inordercountTotalTasks(rootTask, count);
        actualOutput << "Total Tasks in the System: " << count << endl;
    }
    void displayCompletedTasks(stringstream& actualOutput)
    {
        actualOutput << "Completed Tasks:" << endl;
        inorderdisplayCompletedTasks(rootTask, actualOutput);
    }
    void searchTasksByPriorityRange(int p1, int p2, stringstream& actualOutput)
    {
        actualOutput << "Tasks within Priority Range (" << p1 << " to " << p2 << "):" << endl;
        inordersearchTasksByPriorityRange(rootTask, p1, p2, actualOutput);
    }
    void PrintTreeInorder(stringstream& actualOutput)
    {
        inorderPrintTreeInorder(rootTask, actualOutput);
    }

    template <class X>
    void inorderDisplay(X* current)
    {
        if (current != NULL)
        {
            inorderDisplay(current->left);
            cout << current->priorityLevel << "   " << current->color << endl;
            inorderDisplay(current->right);
        }
    }

private:
    template <class X>
    void replaceRootWithPredecessor(X*& root, X*& ROOT)
    {
        X* current = root->left;
        if (current == NULL)
        {
            current = root->right;
            swapData(root, current);
            while (current->left != NULL)
            {
                swapData(current, current->right);
                current->left = current->right->left;
                current->right->left = NULL;
                current = current->right;
            }
            if (current->color == "R")
            {
                current->parent->right = NULL;
            }
            else
            {
                current->color = "DB";
                current->assigneeID = "NIL";
                checkDoubleBlackCases(current->parent, current, ROOT);
                current->parent->right = NULL;
            }
        }
        if (current->right == NULL) // if child of root has no right child
        {
            swapData(root, current);
            while (current->left != NULL)
            {
                swapData(current, current->left);
                current->right = current->left->right;
                current->left->right = NULL;
                current = current->left;
            }
            if (current->color == "R")
            {
                current->parent->left = NULL;
            }
            else
            {
                current->color = "DB";
                current->assigneeID = "NIL";
                checkDoubleBlackCases(current->parent, current, ROOT);
                current->parent->left = NULL;
            }
        }
        else
        {
            // find predecessor
            while (current->right != NULL)
            {
                current = current->right;
            }
            X* currentParent = current->parent; // Parent of predecessor
            swapData(root, current);            // Swaping the Data of predecessor with the Node to be deleted
            if (current->left != NULL)          // if Left is not NUll of predecessor connecting all its left Child with its parent without changing color
            {
                while (current->left != NULL)
                {
                    swapData(current, current->left);
                    current->right = current->left->right;
                    current->left->right = NULL;
                    current = current->left;
                }
                current->parent->left = NULL;
                delete current;
            }
            else // if predecessor has no left child
            {
                if (current->color == "B")
                {
                    current->color = "DB";
                    current->assigneeID = "NIL";
                    checkDoubleBlackCases(currentParent, current, ROOT);
                }
                currentParent->right = NULL;
            }
        }
    }
    template <class X>
    void checkDoubleBlackCases(X*& Parent, X*& current, X*& root)
    {
        X* sibling;
        X* siblingFarChild = NULL;
        X* siblingNearChild = NULL;
        if (Parent->right == current)
        {
            sibling = Parent->left;
            if (sibling != NULL)
            {
                siblingFarChild = sibling->left;
                siblingNearChild = sibling->right;
            }
        }
        else
        {
            sibling = Parent->right;
            if (sibling != NULL)
            {
                siblingFarChild = sibling->right;
                siblingNearChild = sibling->left;
            }
        }
        if (sibling != NULL) // if predecessor sibling is not NULL
        {
            if (sibling->color == "B") // if predecessor sibling color is black
            {
                if (siblingFarChild == NULL && siblingNearChild == NULL)
                {
                    cout << "Case1" << endl;
                    Case1(Parent, current, sibling, root);
                }
                else if (siblingFarChild == NULL && siblingNearChild != NULL)
                {
                    if (siblingNearChild->color == "R")
                    {
                        cout << "Case 3 was Formed" << endl;
                        Case3(Parent, current, sibling, siblingFarChild, siblingNearChild, root);
                    }
                }
                else if (siblingFarChild != NULL && siblingNearChild == NULL)
                {
                    if (siblingFarChild->color == "R")
                    {
                        Case4(Parent, current, sibling, siblingFarChild, siblingNearChild, root);
                    }
                }
                else if (siblingFarChild != NULL && siblingNearChild != NULL)
                {
                    if (siblingFarChild->color == "B" && siblingNearChild->color == "B")
                    {
                        Case1(Parent, current, sibling, root);
                    }
                    else if (siblingFarChild->color == "B" && siblingNearChild->color == "R")
                    {
                        Case3(Parent, current, sibling, siblingFarChild, siblingNearChild, root);
                    }
                    else if (siblingFarChild->color == "R" && siblingNearChild->color == "B")
                    {
                        cout << "Case4" << endl;
                        Case4(Parent, current, sibling, siblingFarChild, siblingNearChild, root);
                    }
                    else if (siblingFarChild->color == "R" && siblingNearChild->color == "R")
                    {
                        Case4(Parent, current, sibling, siblingFarChild, siblingNearChild, root);
                    }
                }
            }
            else
            {
                Case2(Parent, current, sibling, root);
            }
        }

        if (root->color == "R")
            root->color = "B";
        if (current->color == "DB")
        {
            checkDoubleBlackCases(current->parent, current, root);
        }
        else if (Parent->color == "DB")
        {
            if (Parent == root)
            {
                Parent->color = "B";
            }
            else
            {
                cout << "Again" << endl;
                checkDoubleBlackCases(Parent->parent, Parent, root);
            }
        }
        if (Parent->left == current && current->assigneeID == "NIL")
        {
            Parent->left = NULL;
        }
        else if (Parent->right == current && current->assigneeID == "NIL")
        {
            cout << current->assigneeID << endl;
            Parent->right = NULL;
        }
    }

    template <class X>
    void Case1(X*& Parent, X*& current, X*& sibling, X*& root)
    {
        current->color = 'B';
        if (Parent->color == "R")
        {
            Parent->color = "B";
        }
        else
        {
            Parent->color = "DB";
        }
        sibling->color = 'R';
    }
    template <class X>
    void Case2(X*& Parent, X*& current, X*& sibling, X*& root)
    {
        swapColor(Parent, sibling);
        if (Parent->left == current)
        {
            leftRightRotataion(sibling, '\0', root, false);
        }
        else
        {
            RightleftRotataion(sibling, '\0', root, false);
        }
    }
    template <class X>
    void Case3(X*& Parent, X*& current, X*& sibling, X*& siblingFarChild, X*& siblingNearChild, X*& root)
    {
        swapColor(sibling, siblingNearChild);
        X* temp = siblingNearChild;
        if (sibling->right == siblingNearChild)
        {
            leftRightRotataion(siblingNearChild, '\0', root, false);
            siblingFarChild = siblingNearChild->left;
            siblingNearChild = siblingNearChild->right;
        }
        else
        {
            cout << "Right Left" << endl;
            RightleftRotataion(siblingNearChild, '\0', root, false);
            siblingFarChild = siblingNearChild->right;
            siblingNearChild = siblingNearChild->left;
        }
        cout << "->" << siblingFarChild->assigneeID << endl;
        Case4(Parent, current, temp, siblingFarChild, siblingNearChild, root);
    }
    template <class X>
    void Case4(X*& Parent, X*& current, X*& sibling, X*& siblingFarChild, X*& siblingNearChild, X*& root)
    {
        swapColor(sibling, Parent);

        if (Parent->right == current)
        {
            LeftLeftRotataion(siblingFarChild, '\0', root);
        }
        else
        {
            RightRightRotataion(siblingFarChild, '\0', root);
        }
        current->color = 'B';
        siblingFarChild->color = "B";
    }

    template <class X>
    void swapColor(X*& one, X*& two)
    {
        string temp = one->color;
        one->color = two->color;
        two->color = temp;
    }
    void swapData(NodeTask*& one, NodeTask*& two)
    {
        one->assigneeID = two->assigneeID;
        one->description = two->description;
        one->priorityLevel = two->priorityLevel;
        one->taskID = two->taskID;
    }
    void swapData(Node*& one, Node*& two)
    {
        one->firstName = two->firstName;
        one->lastName = two->lastName;
        one->assigneeID = two->assigneeID;
        one->address = two->address;
        one->intID = two->intID;
        one->dateOfBirth = two->dateOfBirth;
    }

    template <class X>
    void adjacentRed(X*& current, char key0, char key1, char key2, X*& currentRoot)
    {
        // Key2 is Grandparent dirsction towards Parent
        // Key1 is Parent Dirstion towards new Node
        X* changeNode = NULL;
        X* uncle = NULL;
        if (key2 == 'R')
        {
            uncle = current->parent->parent->left;
        }
        else if (key2 == 'L')
        {
            uncle = current->parent->parent->right;
        }
        if (uncle == NULL || uncle->color == "B")
        {
            if (key1 == key2)
            {
                if (key2 == 'R' && key1 == 'R')
                {
                    this->RightRightRotataion(current, key0, currentRoot);
                    string tempColor = current->parent->left->color;
                    current->parent->left->color = current->parent->color;
                    current->parent->color = tempColor;
                    changeNode = current->parent;
                }
                if (key1 = 'L' && key2 == 'L')
                {
                    this->LeftLeftRotataion(current, key0, currentRoot);
                    string tempColor = current->parent->right->color;
                    current->parent->right->color = current->parent->color;
                    current->parent->color = tempColor;
                    changeNode = current->parent;
                }
            }
            else
            {
                if (key2 == 'L' && key1 == 'R')
                {
                    this->leftRightRotataion(current, key0, currentRoot, true);
                    string tempColor = current->color;
                    current->color = current->right->color;
                    current->right->color = tempColor;
                    changeNode = current;
                }
                else if (key1 == 'L' && key2 == 'R')
                {
                    this->RightleftRotataion(current, key0, currentRoot, true);
                    string tempColor = current->color;
                    current->color = current->left->color;
                    current->left->color = tempColor;
                    changeNode = current;
                }
            }
        }
        else if (uncle != NULL && uncle->color == "R") // If uncle is Red
        {
            current->parent->color = "B";
            if (key2 == 'R')
            {
                current->parent->parent->left->color = "B";
            }
            else
            {
                current->parent->parent->right->color = "B";
            }
            if (current->parent->parent != currentRoot)
            {
                current->parent->parent->color = "R";
            }
            changeNode = current->parent->parent;
        }
        if (changeNode->parent != NULL)
        {
            if (changeNode->parent->color == "R" && changeNode->color == "R")
            {
                key0 = key1 = key2 = '\0';
                X* parent = changeNode->parent;
                X* grandParent = changeNode->parent->parent;
                X* grandGrandParent = NULL;
                if (grandParent != NULL)
                    grandGrandParent = changeNode->parent->parent->parent;
                if (parent->left == changeNode)
                    key1 = 'L';
                else
                {
                    key1 = 'R';
                }
                if (grandParent != NULL)
                {
                    if (grandParent->left == parent)
                        key2 = 'L';
                    else
                        key2 = 'R';
                }
                if (grandGrandParent != NULL)
                {
                    if (grandGrandParent->left == grandParent)
                        key0 = 'L';
                    else
                        key0 = 'R';
                }
                adjacentRed(changeNode, key0, key1, key2, currentRoot);
            }
        }
        return;
    }
    template <class X>
    void RightRightRotataion(X*& current, char key0, X*& currentRoot)
    {
        X* parentLeft = current->parent->left;    // Saving P left
        X* grandParent = current->parent->parent; // Saving GP
        X* grandGrandParent = NULL;
        if (grandParent != NULL)
            grandGrandParent = current->parent->parent->parent;

        if (grandParent != NULL)
            if (grandGrandParent != NULL)
            {
                if (grandGrandParent->right == grandParent)
                    key0 = 'R';
                else
                    key0 = 'L';
                if (key0 == 'R')
                    grandGrandParent->right = current->parent;
                else
                    grandGrandParent->left = current->parent;
            }
        current->parent->parent = grandGrandParent;
        grandParent->parent = current->parent;
        grandParent->right = parentLeft;     // Ataching P left to GP right
        if (parentLeft != NULL)
            parentLeft->parent = grandParent;
        current->parent->left = grandParent; // Attaching GP to P left

        if (grandParent == currentRoot)
        {
            currentRoot = current->parent;
        }
    }
    template <class X>
    void LeftLeftRotataion(X*& current, char key0, X*& currentRoot)
    {
        X* parentRight = current->parent->right;  // Saving P left
        X* grandParent = current->parent->parent; // Saving GP
        X* grandGrandParent = NULL;
        if (grandParent != NULL)
        {
            grandGrandParent = current->parent->parent->parent;
        }
        if (grandParent != NULL)
            if (grandGrandParent != NULL)
            {
                if (grandGrandParent->right == grandParent)
                    key0 = 'R';
                else
                    key0 = 'L';
                if (key0 == 'R')
                    grandGrandParent->right = current->parent;
                else
                    grandGrandParent->left = current->parent;
            }

        current->parent->parent = grandGrandParent;
        grandParent->parent = current->parent;
        grandParent->left = parentRight;
        current->parent->right = grandParent;

        if (grandParent == currentRoot)
        {
            currentRoot = current->parent;
        }
    }
    template <class X>
    void leftRightRotataion(X*& current, char key0, X*& currentRoot, bool check)
    {
        X* parent = current->parent;
        X* currentleft = current->left;
        X* currentright = current->right;
        X* grandParent = current->parent->parent; // Saving GP
        X* grandGrandParent = NULL;
        if (grandParent != NULL)
            grandGrandParent = current->parent->parent->parent;

        current->left = parent;
        parent->parent = current;
        parent->right = currentleft;
        if (currentleft != NULL)
            currentleft->parent = parent;

        if (grandParent != NULL)
            grandParent->left = current;
        current->parent = grandParent;
        if (check == true)
        {
            if (current->parent->parent != NULL)
                if (current->parent->parent->parent != NULL)
                {
                    if (key0 == 'R')
                        grandGrandParent->right = current;
                    else
                        grandGrandParent->left = current;
                }
            current->parent = grandGrandParent;
            current->right = grandParent;
            grandParent->parent = current;

            grandParent->left = currentright;
            if (currentright != NULL)
                currentright->parent = grandParent;
            if (grandParent == currentRoot)
            {
                currentRoot = current;
            }
        }
        else
        {
            if (parent == currentRoot)
            {
                currentRoot = current;
            }
        }
    }
    template <class X>
    void RightleftRotataion(X*& current, char key0, X*& currentRoot, bool check)
    {
        cout << endl;
        X* parent = current->parent;

        X* currentleft = current->left;
        X* currentright = current->right;

        X* grandParent = current->parent->parent; // Saving GP
        X* grandGrandParent = NULL;
        if (grandParent != NULL)
            grandGrandParent = grandParent->parent;

        current->right = parent;
        parent->parent = current;
        parent->left = currentright;
        if (currentright != NULL)
            currentright->parent = parent;

        if (grandParent != NULL)
            grandParent->right = current;
        current->parent = grandParent;
        if (check == true)
        {
            if (grandParent != NULL)
                if (grandGrandParent != NULL)
                {
                    if (key0 == 'R')
                        grandGrandParent->right = current;
                    else
                        grandGrandParent->left = current;
                }
            current->parent = grandGrandParent;
            current->left = grandParent;
            grandParent->parent = current;

            grandParent->right = currentleft;
            if (currentleft != NULL)
                currentleft->parent = grandParent;
            if (grandParent == currentRoot)
            {
                currentRoot = current;
            }
        }
        else
        {
            if (parent == currentRoot)
            {
                currentRoot = current;
            }
        }
    }

    void inorderCompleteTask(NodeTask* current, int id) // Complete Task by Task ID
    {
        if (current != NULL)
        {
            if (current->taskID == id)
            {
                current->completed = true;
                return;
            }
            inorderCompleteTask(current->left, id);
            inorderCompleteTask(current->right, id);
        }
    }
    void inorderFindAssignee(Node* current, string assigneeID, Node*& node) // Find Assignee by AssigneeID
    {
        if (current != NULL)
        {
            if (current->assigneeID == assigneeID)
            {
                node = current;
                return;
            }
            inorderFindAssignee(current->left, assigneeID, node);
            inorderFindAssignee(current->right, assigneeID, node);
        }
    }
    void inorderFindTask(NodeTask* current, int id, NodeTask*& node) // Find Task bt Task ID
    {
        if (current != NULL)
        {

            inorderFindTask(current->left, id, node);
            if (current->taskID == id)
            {
                node = current;
            }
            inorderFindTask(current->right, id, node);
        }
    }
    void inorderFindTask(NodeTask* current, string assigneeID, NodeTask*& node) // Find Task By Assignee ID
    {
        if (current != NULL)
        {
            if (current->assigneeID == assigneeID)
            {
                node = current;
            }
            inorderFindTask(current->left, assigneeID, node);
            inorderFindTask(current->right, assigneeID, node);
        }
    }
    void inorderShiftTask(NodeTask* current, string assigneeID_1, string assigneeID_2) // Shift Task of one Assignee to Another
    {
        if (current != NULL)
        {
            if (current->assigneeID == assigneeID_1)
            {
                current->assigneeID = assigneeID_2;
            }
            inorderShiftTask(current->left, assigneeID_1, assigneeID_2);
            inorderShiftTask(current->right, assigneeID_1, assigneeID_2);
        }
    }
    void inorderGetAssigneeName(Node* current, string& Output, string assigneeID) // Find Assignee name by assignee ID
    {
        if (current != NULL)
        {
            if (current->assigneeID == assigneeID)
            {
                Output += current->firstName;
                return;
            }
            inorderGetAssigneeName(current->left, Output, assigneeID);
            inorderGetAssigneeName(current->right, Output, assigneeID);
        }
    }
    void inordercountTotalTasks(NodeTask* current, int& count)
    {
        if (current != NULL)
        {
            inordercountTotalTasks(current->left, count);
            count += 1;
            inordercountTotalTasks(current->right, count);
        }
    }

    void inorderfindHighestPriorityTask(NodeTask* current, int p, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderfindHighestPriorityTask(current->left, p, Output);
            if (current->priorityLevel == p)
            {
                string Name = "";
                inorderGetAssigneeName(root, Name, current->assigneeID);
                Output << "Highest Priority Task: Task ID: " << current->taskID << ", Description: " << current->description << ", Priority: " << current->priorityLevel << ", Assignee: " + Name + " (" << current->assigneeID << ")" << endl;
            }
            inorderfindHighestPriorityTask(current->right, p, Output);
        }
    }
    void inorderPrintTreeInorder(NodeTask* current, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderPrintTreeInorder(current->left, Output);
            string color = "";
            if (current->color == "R")
                color = "red";
            else
                color = "black";
            Output << current->taskID << " (" << color << ")" << endl;
            inorderPrintTreeInorder(current->right, Output);
        }
    }
    void inorderdisplayCompletedTasks(NodeTask* current, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderdisplayCompletedTasks(current->left, Output);
            if (current->completed == true)
            {
                string Name = "";
                inorderGetAssigneeName(root, Name, current->assigneeID);
                Output << "Task ID: " << current->taskID << ", Description: " << current->description << ", Priority: " << current->priorityLevel << ", Assignee: " + Name + " (" << current->assigneeID << ")" << endl;
            }
            inorderdisplayCompletedTasks(current->right, Output);
        }
    }
    void inorderAssigneeInOrder(Node* current, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderAssigneeInOrder(current->left, Output);
            string color = "";
            if (current->color == "B")
                color = "black";
            else
                color = "red";
            Output << current->assigneeID << " (" << color << ")" << endl;
            inorderAssigneeInOrder(current->right, Output);
        }
    }
    void inorderDisplayAssignee(Node* current, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderDisplayAssignee(current->left, Output);
            Output << "Name: " << current->firstName << " " << current->lastName << ", Address: " << current->address << ", DOB: " + current->dateOfBirth << ", Assignee ID: " << current->assigneeID << endl;
            inorderDisplayAssignee(current->right, Output);
        }
    }
    void inorderTasksByAssignee(NodeTask* current, string assigneeID, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderTasksByAssignee(current->left, assigneeID, Output);
            if (current->assigneeID == assigneeID)
            {
                string Name = "";
                inorderGetAssigneeName(root, Name, current->assigneeID);
                Output << "Task ID: " << current->taskID << ", Description: " << current->description << ", Priority: " << current->priorityLevel << ", Assignee: " + Name + " (" << current->assigneeID << ")" << endl;
            }
            inorderTasksByAssignee(current->right, assigneeID, Output);
        }
    }
    void inorderDisplaybyname(Node* current, string firstName, string LastName, stringstream& Output)
    {
        if (current != NULL)
        {
            if (current->firstName == firstName && current->lastName == LastName)
            {
                Output << "Name: " << current->firstName << " " << current->lastName << ", Address: " << current->address << ", DOB: " + current->dateOfBirth << ", Assignee ID: " << current->assigneeID << endl;
            }
            inorderDisplaybyname(current->left, firstName, LastName, Output);
            inorderDisplaybyname(current->right, firstName, LastName, Output);
        }
    }
    void inorderAssigneeWithNoTask(Node* current, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderAssigneeWithNoTask(current->left, Output);
            NodeTask* findTask = NULL;
            inorderFindTask(rootTask, current->assigneeID, findTask);
            if (findTask == NULL)
            {
                Output << "Name: " << current->firstName << " " + current->lastName << ", Address: " << current->address << ", DOB: " << current->dateOfBirth << ", Assignee ID: " << current->assigneeID << endl;
            }

            inorderAssigneeWithNoTask(current->right, Output);
        }
    }
    void inorderprintTaskQueue(NodeTask* current, stringstream& Output)
    {
        if (current != NULL)
        {
            inorderprintTaskQueue(current->left, Output);
            if (current->completed == false)
            {
                string Name = "";
                inorderGetAssigneeName(root, Name, current->assigneeID);
                Output << "Task ID: " << current->taskID << ", Description: " << current->description << ", Priority: " << current->priorityLevel << ", Assignee: " + Name + " (" << current->assigneeID << ")" << endl;
            }
            inorderprintTaskQueue(current->right, Output);
        }
    }
    void inordersearchTasksByPriorityRange(NodeTask* current, int p1, int p2, stringstream& Output)
    {
        if (current != NULL)
        {
            inordersearchTasksByPriorityRange(current->left, p1, p2, Output);
            if (current->completed == false && current->priorityLevel >= p1 && current->priorityLevel <= p2)
            {
                string Name = "";
                inorderGetAssigneeName(root, Name, current->assigneeID);
                Output << "Task ID: " << current->taskID << ", Description: " << current->description << ", Priority: " << current->priorityLevel << ", Assignee: " + Name + " (" << current->assigneeID << ")" << endl;
            }
            inordersearchTasksByPriorityRange(current->right, p1, p2, Output);
        }
    }

    int stoiID(string ID)
    {
        int num = 1;
        int ans = 0;
        for (int i = ID.length() - 1; i > 2; --i)
        {
            ans += num * (ID[i] - 48);
            num *= 10;
        }
        return ans;
    }
    string to_string(int data)
    {
        std::stringstream ss;
        ss << data;
        return ss.str();
    }
};


