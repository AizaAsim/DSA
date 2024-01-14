#include <iostream>

using namespace std;

struct nod {
    int info;
    nod *l, *r;
};

class BST {
private:
    nod *r; // Assuming 'r' is the root of the Binary Search Tree

public:
    BST() {
        r = NULL;
    }

    void findAndSearch(int data, nod **foundLoc, int &depth) {
        nod *ptr, *ptrsave;
        ptr = r;
        ptrsave = NULL;
        depth = 0;

        while (ptr != NULL) {
            depth++;

            if (data == ptr->info) {
                *foundLoc = ptr;
                return;
            }

            ptrsave = ptr;

            if (data < ptr->info)
                ptr = ptr->l;
            else
                ptr = ptr->r;
        }

        *foundLoc = NULL;
    }

};

int main() {
    

    BST myBST;
    nod *foundLoc;
    int depth;

   
    myBST.findAndSearch(42, &foundLoc, depth);

  
    if (foundLoc != NULL) {
        cout << "Data found at depth: " << depth << endl;
    } else {
        cout << "Data not found" << endl;
    }

    return 0;
}
