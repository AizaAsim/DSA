#include <iostream>
using namespace std;

class Neighbor {
    bool **arr;
    int n = 5;
    int index1, index2;

public:
    Neighbor() {
        arr = new bool*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new bool[n];
            for (int j = 0; j < n; j++) {
                arr[i][j] = false;
            }
        }
    }

    void setter() {
        arr[0][1] = arr[1][0] = arr[1][2] = arr[2][1] = arr[3][1] = arr[2][4] = arr[4][2] = arr[4][1] = arr[3][2] = arr[4][3] = true;
    }

    bool check(int in1, int in2) {
        index1 = in1;
        index2 = in2;
        for (int i = 0; i < n; i++) {
            if (arr[index1][i] && arr[index2][i]) {
                return true;
            }
        }
        return false; 
    }

    void display(int in1, int in2) {
        if (check(in1, in2)) {
            cout << "City " << index1 << " & City " << index2 << " are neighbors" << endl;
        } else {
            cout << "City " << index1 << " & City " << index2 << " are not neighbors" << endl;
        }
    }
~Neighbor(){
  for(int i=0;i<n;i++)
  {
    delete arr[i];
  }
  delete []arr;
}
};

int main() {
    Neighbor n1;
    n1.setter();
    n1.display(2, 4);
}
