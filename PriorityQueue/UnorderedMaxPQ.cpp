#include <iostream>

using namespace std;

template<class T>
class UnorderedMaxPQ {
    public:
        UnorderedMaxPQ(int capacity) {
            pq = new T[capacity + 1];
            N = 0;
        }
        
        bool isEmpty() { return N == 0; }
        
        void insert(T x) { 
            pq[++N] = x; 
            swim(N);
        }
        T delMax() {
            T max = pq[1];
            exch(1, N--);
            sink(1);
            pq[N + 1] = NULL;
            return max;
        }

        void print_pq() {
            for(int i = 1; i <= N; i++)
                cout << pq[i] << " ";
            cout << endl;
        }
        /*
        void heapSort() {
            for(int k = N/2; k >= 1; k--)
                sink(k);
            while(N > 1) {
                exch(1, N);
                sink(1);
                N--;
            }
        }
        */

        /* O(n)
        T delMax() {
            int max = 0;
            for(int i = 1; i < N; i++) {
                if(pq[max] < pq[i]) max = i;
            }
            exch(max, N - 1);
            return pq[--N];
        }
        */

    private:
        void swim(int k) {
            while(k > 1 && pq[k/2] < pq[k]) {
                exch(k, k/2);
                k /= 2;
            }
        }

        void sink(int k) {
            while(2 * k <= N) {
                int j = 2 * k;
                if(j < N && pq[j] < pq[j + 1]) j++;
                if(!(pq[k] < pq[j])) break;
                exch(k, j);
                k = j;
            }
        }

        void exch(int i, int j) {
            T tmp = pq[i];
            pq[i] = pq[j];
            pq[j] = tmp;
        }
        T* pq;
        int N;

};

int main() {
    UnorderedMaxPQ<int> pq(10);
    pq.insert(2);
    pq.insert(3);
    pq.insert(1);
    pq.print_pq();
    pq.heapSort();
    
    return 0;
}
