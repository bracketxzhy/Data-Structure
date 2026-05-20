#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeap
{
private:
  vector<int> heap;

  int parent(int i)
  {
    return (i - 1) / 2;
  }

  int left(int i)
  {
    return 2 * i + 1;
  }

  int right(int i)
  {
    return 2 * i + 2;
  }

  void heapifyUp(int i)
  {
    while (i > 0 && heap[i] > heap[parent(i)])
    {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }
  }

  void heapifyDown(int i)
  {
    int n = heap.size();

    while (true)
    {
      int largest = i;
      int l = left(i);
      int r = right(i);

      if (l < n && heap[l] > heap[largest])
        largest = l;
      if (r < n && heap[r] > heap[largest])
        largest = r;

      if (largest == i)
        break;

      swap(heap[i], heap[largest]);
      i = largest;
    }
  }

public:
  void insert(int x)
  {
    heap.push_back(x);
    heapifyUp(heap.size() - 1);
  }

  int extractMax()
  {
    if (heap.empty())
    {
      throw runtime_error("Heap is empty");
    }

    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
    {
      heapifyDown(0);
    }

    return maxValue;
  }

  void print()
  {
    for (int x : heap)
    {
      cout << x << " ";
    }
    cout << endl;
  }
};

int main()
{
  MaxHeap h;

  h.insert(50);
  h.insert(30);
  h.insert(40);
  h.insert(10);
  h.insert(60);

  h.print();

  cout << h.extractMax() << endl;

  h.print();

  return 0;
}