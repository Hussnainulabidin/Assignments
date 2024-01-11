#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int tointeger(string path, int& index, int count)
{
    char newNumber[4];
    if (count > 99)
    {
        newNumber[0] = path[index];
        newNumber[1] = path[index + 1];
        newNumber[2] = path[index + 2];
        newNumber[3] = '\0';
        index += 2;
        return stoi(newNumber);
    }
    if (count > 9)
    {
        newNumber[0] = path[index];
        newNumber[1] = path[index + 1];
        newNumber[2] = '\0';
        index += 1;
        return stoi(newNumber);
    }
    newNumber[0] = path[index];
    newNumber[1] = '\0';
    return stoi(newNumber);
}

string tostring(int path)
{
    string data = "";
    if (path > 99)
    {
        int rem1 = path % 10;
        int div1 = path / 10;
        int rem2 = div1 % 10;
        int div2 = div1 / 10;
        data += div2 + 48;
        data += rem2 + 48;
        data += rem1 + 48;
        return data;
    }
    if (path > 9)
    {
        int rem = path % 10;
        int div = path / 10;
        data += div + 48;
        data += rem + 48;
        return data;
    }
    data += path + 48;
    return data;
}

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node* down;
    Node* up;

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
        down = NULL;
        up = NULL;
    }
};

class Transport_Layer_optimization
{
public:
    Node* head;
    Transport_Layer_optimization()
    {
        head = NULL;
    }
    void ReadFile(string path)
    {
        ifstream read_file;
        read_file.open(path);

        string str;
        string size, metro, bus, walking;
        int count = 0;

        while (getline(read_file, str)) // saving the differnet route path in there sperate string
        {
            if (count == 0)
                size = str;
            else if (count == 1)
                metro = str;
            else if (count == 2)
                bus = str;
            else
                walking = str;
            count += 1;
        }
        Node* current;

        bool metroPathEnd = false;
        bool busPathEnd = false;
        bool walkingPathEnd = false;
        int i = 0, j = 0, k = 0;
        count = 1;
        Node* metroNode = NULL;
        Node* busNode = NULL;
        Node* walkingNode = NULL;
        Node* prevMetroNode = NULL;
        Node* prevBusNode = NULL;
        Node* prevWalkingNode = NULL;
        while (metroPathEnd == false || busPathEnd == false || walkingPathEnd == false)
        {

            if (metroPathEnd == false)
            {
                metroNode = new Node;

                if (tointeger(metro, i, count) != count)
                {
                    if (count > 9)
                        i -= 1;
                    if (count > 99)
                        i -= 2;
                    metroNode->data = -1;
                }
                else
                {
                    metroNode->data = count;
                    i += 2;
                }
                if (i - 1 > 0)
                    if (metro[i - 1] == '\0')
                        metroPathEnd = true;
            }
            if (busPathEnd == false)
            {
                busNode = new Node;

                if (tointeger(bus, j, count) != count)
                {
                    if (count > 9)
                        j -= 1;
                    if (count > 99)
                        j -= 2;
                    busNode->data = -1;
                }
                else
                {
                    busNode->data = count;
                    j += 2;
                }
                if (j - 1 > 0)
                    if (bus[j - 1] == '\0')
                        busPathEnd = true;
            }
            if (walkingPathEnd == false)
            {
                walkingNode = new Node;

                if (tointeger(walking, k, count) != count)
                {
                    if (count > 9)
                        k -= 1;
                    if (count > 99)
                        k -= 2;
                    walkingNode->data = -1;
                }
                else
                {
                    walkingNode->data = count;
                    k += 2;
                }
                if (k - 1 > 0)
                    if (walking[k - 1] == '\0')
                        walkingPathEnd = true;
            }
            current = metroNode;
            if (head == NULL)
            {
                head = current;
            }
            if (head != NULL)
            {
                if (metroNode != NULL)
                {
                    current->prev = prevMetroNode;
                    current->next = NULL;
                    current->up = NULL;
                    current->down = busNode;
                    if (prevMetroNode != NULL)
                        prevMetroNode->next = current;
                }
                current = busNode;
                if (busNode != NULL)
                {
                    current->prev = prevBusNode;
                    current->next = NULL;
                    current->up = metroNode;
                    current->down = walkingNode;
                    if (prevBusNode != NULL)
                        prevBusNode->next = current;
                }
                current = walkingNode;

                if (walkingNode != NULL)
                {
                    current->prev = prevWalkingNode;
                    current->next = NULL;
                    current->up = busNode;
                    if (prevWalkingNode != NULL)
                        prevWalkingNode->next = current;
                    current->down = NULL;
                }
            }
            prevBusNode = busNode;
            prevMetroNode = metroNode;
            prevWalkingNode = walkingNode;
            busNode = NULL;
            metroNode = NULL;
            walkingNode = NULL;
            count += 1;
        }
    }
    void addNode(int layer, int location)
    {
        Node* current = head;
        if (layer == 2)
        {
            current = current->down;
        }
        else if (layer == 3)
        {
            current = current->down->down;
        }

        int index = 1;

        Node* prevNode = NULL;
        do
        {
            if (index == location)
            {
                break;
            }
            prevNode = current;
            current = current->next;
            index++;

        } while (current != NULL);

   
        if (current == NULL)
        {
            Node* newNode = new Node;
            newNode->data = location;
            newNode->next = NULL;
            newNode->up = NULL;
            newNode->down = NULL;
            newNode->prev = prevNode;
            if(prevNode != NULL)
                prevNode->next = newNode;
            if (layer == 1)
            {
                if (prevNode->down != NULL && prevNode->down->next != NULL)
                {
                    prevNode->down->next->up = newNode;
                }
            }
            else if (layer == 2)
            {
                if (prevNode->down != NULL && prevNode->down->next != NULL)
                {
                    prevNode->down->next->up = newNode;
                }
                if (prevNode->up != NULL && prevNode->up->next != NULL)
                {
                    prevNode->up->next->down = newNode;
                }
            }
            else if (layer == 3)
            {
                if (prevNode->up != NULL && prevNode->up->next != NULL)
                {
                    prevNode->up->next->down = newNode;
                }
            }
        }
        else
            current->data = location;
    }
    void DeleteNode(int layer, int location)
    {
        Node* current = head;
        if (layer == 2)
        {
            current = current->down;
        }
        else if (layer == 3)
        {
            current = current->down->down;
        }

        Node* prevNode = NULL;

        int index = 1;
        while (index != location)
        {
            prevNode = current;
            current = current->next;
            index++;
        }
        current->data = -1;
    }
    string GetPath(int start, int end)
    {
        int layer = 1;
        bool foundFastetMode = 0;

        Node* current = head;

        int index = 1;
        do
        {
            if (index == start && current->data != -1)
            {
                layer = 1;
                foundFastetMode = true;
                break;
            }
            current = current->next;
            index++;
        } while (current != NULL);
        if (foundFastetMode == false)
        {
            index = 1;
            current = head->down;
            do
            {
                if (index == start && current->data != -1)
                {
                    layer = 2;
                    foundFastetMode = true;
                    break;
                }
                current = current->next;
                index++;
            } while (current != NULL);
            if (foundFastetMode == false)
            {
                index = 1;
                current = head->down->down;
                do
                {
                    if (index == start && current->data != -1)
                    {
                        layer = 3;
                        foundFastetMode = true;
                        break;
                    }
                    current = current->next;
                    index++;
                } while (current != NULL);
            }
        }
        string style = " -> ";
        string result = "";
        result += tostring(current->data);
        result += '-';
        result += layer + 48;
        char key = 'f';
        bool checkToMove = false;
        // key : movenext = f : movedown = d : moveback = b : moveup : u
        int i = 0;
        if (start < end)
        {
            while (current->data != end)
            {
                checkToMove = false;
                // condition for up movement
                if (layer != 1 && key != 'd')
                {
                    if (current->up != NULL)
                    {
                        // checking if moving up will be wise decision what if end node was not found and the top and below layer is also empty
                        Node* temp = current->up;
                        do
                        {
                            if (temp->data == end)
                            {
                                checkToMove = true;
                                break;
                            }
                            if (temp->down != NULL)
                            {
                                if (temp->down->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            if (temp->up != NULL)
                            {
                                if (temp->up->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            temp = temp->next;
                        } while (temp != NULL);
                        if (current->up->data != -1 && checkToMove)
                        {
                            current = current->up;
                            layer -= 1;
                            result += style;
                            result += tostring(current->data);
                            result += '-';
                            result += layer + 48;
                            key = '\0';
                            continue;
                        }
                    }
                }
                // condition for forward movement
                if (current->next != NULL && key != 'b')
                {
                    // checking if moving forward is wise decision what if found a dead end and not the end position
                    checkToMove = true;
                    Node* temp = current->next;
                    if (temp->down == NULL || temp->down->data == -1)
                    {
                        checkToMove = false;
                        do
                        {
                            // if end is found in the same layer then go straight
                            if (temp->data == end)
                            {
                                checkToMove = true;
                                break;
                            }
                            // if some node has a down path then we can change path for finding the end node also an optimal solution
                            if (temp->down != NULL)
                            {
                                if (temp->down->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            else if (temp->up != NULL)
                            {
                                if (temp->up->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            temp = temp->next;
                        } while (temp != NULL && temp->data != -1);
                        if (checkToMove == false)
                            key = 'f';
                    }
                    if (current->next->data != -1 && checkToMove)
                    {
                        current = current->next;
                        result += style;
                        result += tostring(current->data);
                        result += '-';
                        result += layer + 48;
                        key = '\0';
                        continue;
                    }
                }
                // condition for down movement
                if (current->next == NULL || current->next->data == -1 || key == 'b' || key == 'f')
                {
                    if (current->down != NULL)
                    {
                        if (current->down->data != -1)
                        {
                            current = current->down;
                            layer += 1;
                            result += style;
                            result += tostring(current->data);
                            result += '-';
                            result += layer + 48;
                            key = 'd';
                            continue;
                        }
                    }
                }
                // condition for backward movement
                current = current->prev;
                result += style;
                result += tostring(current->data);
                result += '-';
                result += layer + 48;
                key = 'b';
                continue;
            }
        }
        else if (start > end)
        {
            key = '\0';
            while (current->data != end)
            {
                checkToMove = false;
                // condition for upmovement
                if (layer != 1 && key != 'd')
                {
                    if (current->up != NULL)
                    {
                        Node* temp = current->up;
                        do
                        {
                            if (temp->data == end)
                            {
                                checkToMove = true;
                                break;
                            }
                            if (temp->down != NULL)
                            {
                                if (temp->down->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            if (temp->up != NULL)
                            {
                                if (temp->up->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            temp = temp->prev;
                        } while (temp != NULL);

                        if (current->up->data != -1 && checkToMove)
                        {
                            current = current->up;
                            layer -= 1;
                            result += style;
                            result += tostring(current->data);
                            result += '-';
                            result += layer + 48;
                            key = '\0';
                            continue;
                        }
                    }
                }
                // condition for backward movement
                if (current->prev != NULL && key != 'f')
                {
                    checkToMove = true;
                    Node* temp = current->prev;
                    if (temp->down == NULL || temp->down->data == -1 && temp->up == NULL)
                    {
                        checkToMove = false;
                        do
                        {
                            // if end is found in the same layer then go straight
                            if (temp->data == end)
                            {
                                checkToMove = true;
                                break;
                            }
                            // if some node has a down path then we can change path for finding the end node also an optimal solution
                            if (temp->up != NULL)
                            {
                                if (temp->up->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            else if (temp->down != NULL)
                            {
                                if (temp->down->data != -1)
                                {
                                    checkToMove = true;
                                    break;
                                }
                            }
                            temp = temp->prev;
                        } while (temp != NULL && temp->data != -1);
                        if (checkToMove == false)
                        {
                            key = 'b';
                        }
                    }
                    if (current->prev->data != -1 && checkToMove)
                    {
                        current = current->prev;
                        result += style;
                        result += tostring(current->data);
                        result += '-';
                        result += layer + 48;
                        key = '\0';
                        continue;
                    }
                }
                // condition for downmovement
                if (current->prev == NULL || current->prev->data == -1 || key == 'f' || key == 'b')
                {
                    if (current->down != NULL)
                    {
                        if (current->down->data != -1)
                        {
                            current = current->down;
                            layer += 1;
                            result += style;
                            result += tostring(current->data);
                            result += '-';
                            result += layer + 48;
                            key = 'd';
                            continue;
                        }
                    }
                }
                // condition for forward movement
                current = current->next;
                result += style;
                result += tostring(current->data);
                result += '-';
                result += layer + 48;
                key = 'f';
                continue;
            }
        }
        return result;
    }
};

class Transport_Cost_Calculator
{
public:
    Node* head;
    Transport_Cost_Calculator()
    {
        head = NULL;
    }
    void ReadFile(string path)
    {
        ifstream read_file;
        read_file.open(path);

        string str;
        string size, metro, bus, walking;
        int count = 0;

        while (getline(read_file, str)) // saving the differnet route path in there sperate string
        {
            if (count == 0)
                size = str;
            else if (count == 1)
                metro = str;
            else if (count == 2)
                bus = str;
            else
                walking = str;
            count += 1;
        }
        Node* current;
        int maxSize = stoi(size);

        bool metroPathEnd = false;
        bool busPathEnd = false;
        bool walkingPathEnd = false;
        int i = 0, j = 0, k = 0;
        count = 0;
        Node* metroNode = NULL;
        Node* busNode = NULL;
        Node* walkingNode = NULL;
        Node* prevMetroNode = NULL;
        Node* prevBusNode = NULL;
        Node* prevWalkingNode = NULL;
        char numberString[10];
        int index = 0;

        while (count < maxSize - 1)
        {
            if (metroPathEnd == false)
            {
                metroNode = new Node;
                for (i; metro[i] != ' ' && metro[i] != '\0'; ++i)
                {
                    numberString[index] = metro[i];
                    index++;
                }
                numberString[index] = '\0';
                metroNode->data = stoi(numberString);
                i += 1;
                if (i - 1 > 0)
                    if (metro[i - 1] == '\0')
                        metroPathEnd = true;
            }
            index = 0;
            if (busPathEnd == false)
            {
                busNode = new Node;
                for (j; bus[j] != ' ' && bus[j] != '\0'; ++j)
                {
                    numberString[index] = bus[j];
                    index++;
                }
                numberString[index] = '\0';
                busNode->data = stoi(numberString);
                j += 1;
                if (j - 1 > 0)
                    if (bus[j - 1] == '\0')
                        busPathEnd = true;
            }
            index = 0;
            if (walkingPathEnd == false)
            {
                walkingNode = new Node;

                for (k; walking[k] != ' ' && walking[k] != '\0'; ++k)
                {
                    numberString[index] = walking[k];
                    index++;
                }
                numberString[index] = '\0';
                walkingNode->data = stoi(numberString);
                k += 1;
                if (k - 1 > 0)
                    if (walking[k - 1] == '\0')
                        walkingPathEnd = true;
            }
            index = 0;
            current = metroNode;
            if (head == NULL)
            {
                head = current;
            }
            if (head != NULL)
            {
                if (metroNode != NULL)
                {
                    current->prev = prevMetroNode;
                    current->next = NULL;
                    current->up = NULL;
                    current->down = busNode;
                    if (prevMetroNode != NULL)
                        prevMetroNode->next = current;
                }
                current = busNode;
                if (busNode != NULL)
                {
                    current->prev = prevBusNode;
                    current->next = NULL;
                    current->up = metroNode;
                    current->down = walkingNode;
                    if (prevBusNode != NULL)
                        prevBusNode->next = current;
                }
                current = walkingNode;

                if (walkingNode != NULL)
                {
                    current->prev = prevWalkingNode;
                    current->next = NULL;
                    current->up = busNode;
                    if (prevWalkingNode != NULL)
                        prevWalkingNode->next = current;
                    current->down = NULL;
                }
            }
            prevBusNode = busNode;
            prevMetroNode = metroNode;
            prevWalkingNode = walkingNode;
            busNode = NULL;
            metroNode = NULL;
            walkingNode = NULL;
            count += 1;
        }
    }
    int getMinCostInIncreasingOrder(int count, int end, int layer, Node* temp, int cost)
    {
        if (count == end)
            return cost;
        int costIfChangingLayer1 = 0;
        int changingLayerResult1 = 0;
        int costIfChangingLayer2 = 0;
        int changingLayerResult2 = 0;
        int cost1 = 0;
        int cost2 = 0;
        int cost3 = 0;
        Node* current = temp;
        if (layer == 1)
        {
            costIfChangingLayer1 = 5 + current->down->data;
            costIfChangingLayer2 = 5 + 5 + current->down->down->data;
        }
        else if (layer == 2)
        {
            costIfChangingLayer1 = 5 + current->up->data;
            costIfChangingLayer2 = 5 + current->down->data;
        }
        else if (layer == 3)
        {
            costIfChangingLayer1 = 5 + current->up->data;
            costIfChangingLayer2 = 5 + 5 + current->up->up->data;
        }
        if (layer == 1)
        {
            cost1 = getMinCostInIncreasingOrder(count + 1, end, layer, current->next, current->data);
            if (costIfChangingLayer1 <= costIfChangingLayer2)
                cost2 = getMinCostInIncreasingOrder(count + 1, end, 2, current->down->next, costIfChangingLayer1);
            else
                cost2 = getMinCostInIncreasingOrder(count + 1, end, 3, current->down->down->next, costIfChangingLayer2);
            if (cost1 <= cost2)
            {
                return cost + cost1;
            }
            else if (cost2 < cost1)
            {
                return cost + cost2;
            }
        }
        else if (layer == 2)
        {
            cost1 = getMinCostInIncreasingOrder(count + 1, end, layer, current->next, current->data);
            cost2 = getMinCostInIncreasingOrder(count + 1, end, 1, current->up->next, costIfChangingLayer1);
            cost3 = getMinCostInIncreasingOrder(count + 1, end, 3, current->down->next, costIfChangingLayer2);
            if (cost1 <= cost2 && cost1 <= cost3)
            {
                return cost + cost1;
            }
            else if (cost2 < cost1 && cost2 <= cost3)
            {
                return cost + cost2;
            }
            else
            {
                return cost + cost3;
            }
        }
        else if (layer == 3)
        {
            cost1 = getMinCostInIncreasingOrder(count + 1, end, layer, current->next, current->data);
            if (costIfChangingLayer1 <= costIfChangingLayer2)
                cost2 = getMinCostInIncreasingOrder(count + 1, end, 2, current->up->next, costIfChangingLayer1);
            else
                cost2 = getMinCostInIncreasingOrder(count + 1, end, 1, current->up->up->next, costIfChangingLayer2);
            if (cost1 <= cost2)
            {
                return cost + cost1;
            }
            else if (cost2 < cost1)
            {
                return cost + cost2;
            }
        }
    }
    int GetMinCost(int start, int end)
    {
        int index = 1;
        Node* startNode = head;
        if (start > end)
        {
            int temp = start;
            start = end;
            end = temp;
        }
        while (index != start)
        {
            startNode = startNode->next;
            index++;
        }
        index = 1;
        int count = start;
        int cost = 0;
        int tempCost[3] = { 0 };
        if (start < end)
        {
            int layer = 1;

            while (layer != 4)
            {
                tempCost[layer - 1] = getMinCostInIncreasingOrder(start, end, layer, startNode, 0);
                startNode = startNode->down;
                layer += 1;
            }
            cost = tempCost[0];
            for (int i = 1; i < 3; ++i)
            {
                if (tempCost[i] < cost)
                    cost = tempCost[i];
            }
        }
        return cost;
    }
};