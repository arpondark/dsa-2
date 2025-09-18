#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        for (ListNode* list : lists)
            if (list != nullptr)
                minHeap.push(list);

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            if (minNode->next)
                minHeap.push(minNode->next);
            curr->next = minNode;
            curr = curr->next;
        }
        return dummy.next;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Enter number of linked lists: ";
    cin >> k;

    vector<ListNode*> lists(k, nullptr);

    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter number of elements in list " << i + 1 << ": ";
        cin >> n;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        cout << "Enter " << n << " elements: ";
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            ListNode* newNode = new ListNode(x);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        lists[i] = head;
    }

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}
