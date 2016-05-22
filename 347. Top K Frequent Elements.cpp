struct Node {
    int num, count;
};

class Heap {
    std::vector<Node *> _heap;
    void swap(int i, int j) {
        Node * n = _heap[i];
        _heap[i] = _heap[j];
        _heap[j] = n;
    }
    void upHeapify(int i) {
        int p = floor((i-1) / 2);
        while (p >= 0 && _heap[p]->count < _heap[i]->count) {
            swap(p, i);
            i = p;
            p = floor((i-1) / 2);
        }
    }
    void downHeapify(int i) {
        while (true) {
            int max = _heap[i]->count, p = i;
            int l = (i << 1) + 1;
            int r = l + 1;
            if (l < _heap.size() && _heap[l]->count > max) {
                max = _heap[l]->count;
                p = l;
            }
            if (r < _heap.size() && _heap[r]->count > max) {
                p = r;
            }
            if (p == i) break;
            swap(i, p);
            i = p;
        }
    }
public:
    void insert(Node * n) {
        _heap.push_back(n);
        upHeapify(_heap.size()-1);
    }
    Node * extract() {
        Node * max = _heap[0];
        _heap[0] = _heap[_heap.size()-1];
        _heap.pop_back();
        downHeapify(0);
        return max;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, Node*> num_nodes;
        Heap h;
        vector<int> ret;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i) {
            int x = *i;
            if (num_nodes.find(x) == num_nodes.end()) {
                Node * n = new Node();
                n->num = x;
                n->count = 1;
                num_nodes[x] = n;
            } else {
                num_nodes[x]->count ++;
            }
        }
        for (std::map<int, Node*>::iterator it=num_nodes.begin(); it!=num_nodes.end(); ++it) {
            h.insert(it->second);
        }
        for (int i=0; i<k; i++) {
            Node * n = h.extract();
            ret.push_back(n->num);
        }
        return ret;
    }
};


