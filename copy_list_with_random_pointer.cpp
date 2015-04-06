// #138 Copy List with Random Pointer
//
// A linked list is given such that each node contains an additional random
// pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.


#include <iostream>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void print(RandomListNode *node)
{
    while (node) {
        std::cout << node->label << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

class Solution {

  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        RandomListNode *newHead = 0;

        // head
        //
        // node    next
        // +---+   +---+   +---+   +---+   +---+
        // |   |-->|   |-->|   |-->|   |-->|   |
        // +---+   +---+   +---+   +---+   +---+
        //   | (1)   ^ (2)
        //   | ______|
        //   v/
        // +---+   +---+   +---+   +---+   +---+
        // |   |-->|   |-->|   |-->|   |-->|   |
        // +---+   +---+   +---+   +---+   +---+
        // newNode
        //
        // newHead

        // Copy the list and connect the two lists together as above.

        RandomListNode *node = head;
        while (node) {
            RandomListNode *next    = node->next;
            RandomListNode *newNode = new RandomListNode(node->label);
            if (!newHead) {
                newHead = newNode;
            }
            node->next    = newNode; // (1)
            newNode->next = next;    // (2)
            node          = next;
        }

        // Set the random pointers for the nodes in the new lists.

        node = head;
        while (node) {
            RandomListNode *newNode = node->next;

            // Set the random pointer for the new node.

            if (node->random) {
                newNode->random = node->random->next;
            }

            // Go to the next node for the next iteration.

            node = newNode->next;
        }

        // Restore the original list.  We cannot do this in the last step when
        // we assign the random pointers, becaue a node's random pointer could
        // point to a previous node.

        node = head;
        while (node && node->next) {
            RandomListNode *next = node->next;
            node->next = node->next->next;
            node       = next;
        }

        return newHead;
    }
};

int main()
{
    Solution s;
    {
        RandomListNode node1(1);
        print(s.copyRandomList(&node1));
        print(&node1);
    }
    return 0;
}
