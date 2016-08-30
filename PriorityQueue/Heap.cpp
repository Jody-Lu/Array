#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Heap {
    public:
        void heapSort(vector<T>& pq) {
            /* N: the length of array we would like to sort.  */
            /* other than the node. */
            int N = pq.size() - 1;
            for(int k = N/2; k >= 1; k--)
                sink(pq, k, N);
            while(N > 1) {
                exch(pq, 1, N);
                sink(pq, 1, --N);
            }
        }

    private:
        void sink(vector<T>& pq, int k, int N) {
            while(2 * k <= N ) {
                int j = 2 * k;
                if(j < N && less(pq, j, j + 1)) j++;
                if(!less(pq, k, j)) break;
                exch(pq, k, j);
                k = j;
            }
        }

        bool less(vector<T>& pq, int i, int j) {
            return pq[i] < pq[j];
        }

        void exch(vector<T>& pq, int i, int j) {
            T tmp = pq[i];
            pq[i] = pq[j];
            pq[j] = tmp;
        }

};


int main() {
    Heap<int> h;
    int a[] = {0, 1, 4, 3, 2, 10 , 12, 7, 6, 6, 6, 45};
    vector<int> arr(a, a + 12);
    h.heapSort(arr);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
