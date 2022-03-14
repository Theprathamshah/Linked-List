class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL, *ptr = NULL, *p = head;
        map<Node*, Node*> map;
        
        while(p){
            Node* t = new Node(p->val);
            map[p] = t;
            if(not newHead){
                newHead = t;
                ptr = t;
            }
            else{
                ptr->next = t;
                ptr = t;
            }
            p = p->next;
        }
        
        p = head;
        ptr = newHead;
        
        while(p){
            if(p->random){
                ptr->random = map[p->random];
            }
            p = p->next;
            ptr = ptr->next;
        }
        
        return newHead;
    }
};


// Algorithm of copy list with random pointer goes here