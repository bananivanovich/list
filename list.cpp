#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
};


ListNode* Process(ListNode* head, unsigned k) {
    int len = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        len++;
        curr = curr->next;
    }

    if (len == 0 || (int)k > len) {
        return head;
    }

    
    int pos = len - k;

    
    if (pos == 0) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    
    curr = head;
    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }

    
    ListNode* del = curr->next;
    curr->next = curr->next->next;
    delete del;

    return head;
}


ListNode* create(int n) {
    if (n <= 0) return nullptr;
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val; 
        
        
        ListNode* newhead = new ListNode{val, nullptr};
        
        if (head == nullptr) {
            head = newhead;
            tail = newhead;
        } else {
            tail->next = newhead;
            tail = newhead;
        }
    }
    return head;
}


void print(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->value;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}


void free(ListNode* head) {
    while (head != nullptr) {
        ListNode* b = head;
        head = head->next;
        delete b;
    }
}

int main() 
{
    int n;

    std::cin >> n;
    ListNode* head = create(n);
    print(head);

    unsigned k;
    std::cin >> k;
    head = Process(head, k);
    print(head);

    free(head);
    
    return 0;
}