/*Name: Madhav Verma
Roll No: 25/DA/039*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:

    int data;  
    
    
    int index;  

    Node *left, *right;

    
    Node(int d, int i) {
        data = d;
        index = i;
        left = right = nullptr;
    }

    
    Node(Node* l, Node* r) {
        data = l->data + r->data;
        
        
        index = min(l->index, r->index); 
        left = l;
        right = r;
    }
};


class Compare {
public:
    bool operator() (Node* a, Node* b) {
        // smaller freq first
        if (a->data != b->data)
            return a->data > b->data;  
        // when freq are equal
        return a->index > b->index;    
    }
};


void preOrder(Node* root, vector<string> &ans, string curr) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        
        if (curr == "") curr = "0"; 
        ans.push_back(curr);
        return;
    }

    preOrder(root->left, ans, curr + '0');
    preOrder(root->right, ans, curr + '1');
}

vector<string> huffmanCodes(string &s, vector<int> freq) {
    
    int n = s.length();
    
  
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < n; i++) {
        
        Node* tmp = new Node(freq[i], i); 
        pq.push(tmp);
    }

   
    if (n == 1)
        return {"0"};

    
    while (pq.size() >= 2) {
        
        // Left node
        Node* l = pq.top();
        pq.pop();
        
        // Right node
        Node* r = pq.top();
        pq.pop();
           
         
        Node* newNode = new Node(l, r); 
        pq.push(newNode);
    }

    Node* root = pq.top();
    vector<string> ans;
    preOrder(root, ans, "");
    return ans;
}

int main() {
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    vector<string> ans = huffmanCodes(s, freq);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}