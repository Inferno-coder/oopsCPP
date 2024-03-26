class Node {
public:
    Node* links[2];
    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class BitTrie {
public:
    Node* root;
    BitTrie() {
        root = new Node();
    }
    void insert(int num) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (temp->containsKey(bit)) {
                temp = temp->get(bit);
            }
            else {
                temp->put(bit, new Node());
                temp = temp->get(bit);
            }
        }
    }

    int getMax(int num) {
        Node* temp = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (temp->containsKey(1-bit)) {
                maxi |= (1 << i);
                temp = temp->get(1-bit); 
            }
            else {
                temp = temp->get(bit);
            }
        }
        return maxi;
    }
};
