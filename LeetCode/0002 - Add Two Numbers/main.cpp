#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode operator=(const ListNode& other) {
        this->next = other.next;
        this->val = other.val;
    }
};

ListNode* CreateListNode(vector<int> v) {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    for(int i = 0; i < v.size(); i++) {
        ListNode* temp = new ListNode(v[i]);
        curr->next = temp;
        curr = curr->next;
    }
    return head->next;
}

void Print(ListNode* n) {
    while(n != nullptr) {
        cout << n->val;
        if(n->next != nullptr) cout << ", ";
        n = n->next;
    }
    cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    ListNode* head = new ListNode(0);
    ListNode* sum = head;

    int carryover = 0;
    while(l1 != nullptr || l2 != nullptr) {
        int value = 0;

        if(l1 != nullptr) {
            value += l1->val;
            l1 = l1->next;
        }

        if(l2 != nullptr) {
            value += l2->val;
            l2 = l2->next;
        }

        value += carryover;

        carryover = value/10;
        ListNode* temp = new ListNode(value%10);
        sum->next = temp;
        sum = sum->next;
    }

    if(carryover) {
        ListNode* temp =  new ListNode(1);
        sum->next = temp;
    }

    return head->next;
}

int main() {
    ListNode* l1 = CreateListNode({2, 4, 3});
    ListNode* l2 = CreateListNode({5, 6, 4});
    Print(l1);
    Print(l2);

    ListNode* ans = addTwoNumbers(l1, l2);
    Print(ans);

    return 0;
}