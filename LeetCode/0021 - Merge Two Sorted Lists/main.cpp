#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void Print(ListNode* node) {
    while(node != nullptr) {
        cout << node->val;
        if(node->next != nullptr) cout << " -> ";
        node = node->next;
    }
}

ListNode* NewNode(int val) {
    struct ListNode* temp = new ListNode; 
    temp->val = val; 
    temp->next = NULL; 
    return temp; 
}


ListNode* CreateList(vector<int> vect) {
    ListNode* head = NewNode(0);
    ListNode* curr = head;
    for(int i = 0; i < vect.size(); i++) {
        ListNode* temp = NewNode(vect[i]);
        curr->next = temp;
        curr = curr->next;
    } 
    return head->next;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = NewNode(-1);
    ListNode* curr = head;
    while(list1->next != nullptr || list2->next != nullptr) {
        if(list1 == nullptr) {
            curr->next = list2;
            list2 = list2->next;
        }
        if(list2 == nullptr) {
            curr->next = list1;
            list1 = list1->next;
        }
        if(list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    return head->next;
}

int main() {
    vector<int> vect1 = {1, 2, 4};
    vector<int> vect2 = {1, 3, 4};
    ListNode* list1 = CreateList(vect1);
    ListNode* list2 = CreateList(vect2);

    ListNode* head = mergeTwoLists(list1, list2);
    Print(head);
}