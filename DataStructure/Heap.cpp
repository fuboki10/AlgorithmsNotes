class Heap
{
	std::vector<int> heap;
public:
	int left_child(int i){
		return 2*i+1;
	}
	int right_child(int i)
	{
		return 2*i+1;
	}
	int parent(int i){
		return (i-1)/2;
	}
	void SiftDown(int i){
		int minidx = i;
		int left = left_child(i);
		if (left < data_.size() && data_[left] < data_[minidx])
		{
			minidx = left;
		}
			int right = right_child(i);
		if (right < data_.size() && data_[right] < data_[minidx])
		{
			minidx = right;
		}
		if (i != minidx)
		{
			swaps_.push_back({i,minidx});
			swap(data_[i],data_[minidx]);
			SiftDown(minidx);
		}
 	}
	void SiftUp(int i){
		while (i > 0 && heap[parent(i)] > heap[i])
		{
			swap(heap[parent(i)],heap[i]);
			i = parent(i);
		}
	}
	void insert(int data)
	{
		heap.push_back(data);
		SiftUp(heap.size() - 1);
	}
	void remove(int i)
	{
		heap[i] = INF;
		SiftUp(i);
		extractMin();
	}
	int extractMin()
	{
		int result = heap[0];
		heap[0] = heap[data.size() - 1];
		data.pop_back();
		SiftDown(0);
		return result;
	}
};