// #23 Merge k Sorted Lists
//
// Merge k sorted linked lists and return it as one sorted list. Analyze and
// describe its complexity.


#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head)
{
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

struct Comparator {

    bool operator()(const ListNode *lhs, const ListNode *rhs)
    {
        if (lhs->val > rhs->val) {
            return true;
        }
        return false;
    }
};

class Solution {
    // Time complexity: O(lgk*n); Space complexity: O(k)

  public:
    ListNode *mergeKLists(const std::vector<ListNode *>& lists)
    {
        typedef std::priority_queue<ListNode *,
                                    std::vector<ListNode *>,
                                    Comparator> Heap;
        ListNode  *head = 0;
        ListNode **p    = &head;

        Heap heap;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }

        while (!heap.empty()) {
            ListNode *node = heap.top();
            heap.pop();

            *p = node;
            p = &node->next;

            if (node->next) {
                heap.push(node->next);
            }
        }
        return head;
    }
};

class Solution_Okn {
    // Time complexity: O(k*n); Space complexity: O(1)

  public:
    ListNode *mergeKLists(std::vector<ListNode *>& lists)
    {
        ListNode *head = 0;
        ListNode **p = &head;

        while (1) {
            int count = 0;
            int index = 0;
            for (int i = 0; i < lists.size(); ++i) {
                if (!lists[i]) {
                    continue;
                }
                if (0 == count) {
                    index = i;
                } else if (0 < count) {
                    if (lists[i] < lists[index]) {
                        index = i;
                    }
                }
                ++count;
            }
            if (2 > count) {
                break;
            }
            *p = lists[index];
            p = &lists[index]->next;
            lists[index] = lists[index]->next;
        }
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                *p = lists[i];
                break;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<ListNode *> list;
    ListNode node1(2);
    ListNode node2(-1);
    list.push_back(&node1);
    list.push_back(0);
    list.push_back(&node2);

    Solution s;
    print(s.mergeKLists(list));

    return 0;
}
