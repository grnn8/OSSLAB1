class Node { 
    public:
  int key; 
  int value; 
  Node *pre; 
  Node *next; 

  
  Node(int k, int v) 
  { 
    key = k; 
    value = v;
    pre=NULL;next=NULL;
  } 
}; 


class LRUCache {
public:
    public:
  unordered_map<int, Node*> map; 
  int capacity; 
  Node *head=new Node(0, 0); , *tail=new Node(0, 0); ;
        
    LRUCache(int c) {
          capacity = c; 
    
    head->next = tail; 
    tail->pre = head; 
    
    }
    void deleteNode(Node *node) 
  { 
    node->pre->next = node->next; 
    node->next->pre = node->pre; 
  } 

  void addToHead(Node *node) 
  { 
    node->next = head->next; 
    node->next->pre = node; 
    node->pre = head; 
    head->next = node; 
  } 
    
    int get(int key) {
        if (map[key] != NULL) { 
      Node *node = map[key]; 
      int result = node->value; 
      deleteNode(node); 
      addToHead(node); 
      cout<<"Got the value : " << 
        result << " for the key: " << key<<endl; 
      return result; 
    } 
    cout<<"Did not get any value" <<
              " for the key: " << key<<endl; 
    return -1; 
        
    }
    
    void put(int key, int value) {
        cout<<"Going to set the (key, "<< 
      "value) : (" << key << ", " << value << ")"<<endl; 
    if (map[key] != NULL) { 
      Node *node = map[key]; 
      node->value = value; 
      deleteNode(node); 
      addToHead(node); 
    } 
    else { 
      Node *node = new Node(key, value); 
      map[key]= node; 
      if (count < capacity) { 
        count++; 
        addToHead(node); 
      } 
      else { 
        map.erase(tail->pre->key); 
        deleteNode(tail->pre); 
        addToHead(node); 
      } 
    } 
    }
};
