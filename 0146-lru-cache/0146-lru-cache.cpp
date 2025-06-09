class Node {
public:
	int key, val;
	Node* next;
	Node* prev;
    
   
	Node() {
		key = val = -1;
		next = prev = NULL;
	}

	Node(int k, int value) {
		key = k;
		val = value;
		next = prev = NULL;
	}
};


class LRUCache {
private:

	map <int, Node*> mpp; 
	int cap; 
	Node* head; 
	Node* tail; 

	
	void deleteNode(Node* node) {

		
		Node* prevNode = node-> prev;
		Node* nextNode = node-> next;

		
		prevNode-> next = nextNode;
		nextNode-> prev = prevNode;
	}

	
	void insertAfterHead(Node* node) {

		Node* nextNode = head-> next;
		head-> next = node;
		nextNode-> prev = node;
		node-> prev = head;
		node-> next = nextNode;
	}

public:
	
	LRUCache(int capacity) {
		cap = capacity;
		mpp.clear();

		head = new Node();
		tail = new Node();

		head-> next = tail;
		tail-> prev = head;
	}

	
	int get(int key_) {
		
		if(mpp.find(key_) == mpp.end())
			return -1;

		Node* node = mpp[key_]; // Get the node
		int val = node->val; // Get the value

		// Delete the node
		deleteNode(node);
		/* Insert this node to front
		as it was recently used */
		insertAfterHead(node);

		// Return the stored value
		return val;
	}

	/* Method to update value is key exists,
	otherwise insert the key-value pair */
	void put(int key_, int value) {

		// Update the value if key is already present
		if(mpp.find(key_) != mpp.end()) {
		    
			Node* node = mpp[key_]; // Get the node
			node->val = value; // Update the value
            
			// Delete the node
			deleteNode(node);
			
			/* Insert this node to front
			as it was recently used */
			insertAfterHead(node);
			
			return;
		}

		// Check if the capacity limit has reached
		if(mpp.size() == cap) {

			// Get the least recently used node
			Node* node = tail->prev;

			// Delete node from map
			mpp.erase(node-> key);

			// Delete node from doubly linked list
			deleteNode(node);
		}

		// Create a new node
		Node* newNode = new Node(key_, value);
		
		// Insert it in map
		mpp[key_] = newNode;

		// Insert in doubly linked list
		insertAfterHead(newNode);
	}
};

