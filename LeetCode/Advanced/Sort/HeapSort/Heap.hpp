#pragma once
#include <iostream>

#define  MAX_SIZE 12

enum SWAPMODE
{
	MAX,
	MIN
};

template<typename T>
struct  HeapDatabase //�ṹ��Ķ���
{
private:
	int _maxSize;
	int _heapSize;

public:
	T _heap;

	HeapDatabase()
	{
		_maxSize = MAX_SIZE;
		_heapSize = 0;
		//_heap = new T;
	}
	HeapDatabase(int len, const T& heap)
	{
		_maxSize = MAX_SIZE;
		_heapSize = len;
		_heap = heap;
	}
	HeapDatabase(const HeapDatabase& heap)
	{
		_maxSize = heap._maxSize;
		_heapSize = heap._heapSize;
		_heap = heap._heap;
	}

	~HeapDatabase()
	{
		_heapSize = 0, _maxSize = 0;
		if (_heap != nullptr)
			delete _heap;
	}

	int GetHeadSize()
	{
		return _heapSize;
	}
};

template<typename T>
class Heap
{
public:
	Heap()
	{
		m_heapDatabase = new HeapDatabase<T>;
		HeapInit(SWAPMODE::MIN);
	}
	Heap(T arr, int len)
	{
		m_heapDatabase = new HeapDatabase<T>(len, arr);
		//m_heapDatabase->_heap = arr;
		HeapInit(SWAPMODE::MIN);
		//heap = new HeapDatabase(heapSize, m_heapDatabase);
	}

	~Heap()
	{
		if (m_heapDatabase != nullptr)
			delete m_heapDatabase;
	}

public:
	HeapDatabase<T>* m_heapDatabase;

	void HeapInit(SWAPMODE smode);

private:
	void MaxHeapify(int start, int end);
	void MinHeapify(int start, int end);
};

template<typename T>
void Heap<T>::MinHeapify(int start, int end)
{
	//�������ڵ�ָ����ӽڵ�ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {//���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
		if (son + 1 <= end && m_heapDatabase->_heap[son] > m_heapDatabase->_heap[son + 1]) //�ȱȽ������ӽڵ��С��ѡ����С��
			son++;
		if (m_heapDatabase->_heap[dad] < m_heapDatabase->_heap[son]) //������ڵ�С���ӽڵ���������ϣ�ֱ����������
			return;
		else { //��t���Q���Ӄ������^�m�ӹ��c�͌O���c���^
			std::swap(m_heapDatabase->_heap[dad], m_heapDatabase->_heap[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
template<typename T>
void Heap<T>::MaxHeapify(int start, int end)
{
	//�������ڵ�ָ����ӽڵ�ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
		if (son + 1 <= end && m_heapDatabase->_heap[son] < m_heapDatabase->_heap[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
			son++;
		if (m_heapDatabase->_heap[dad] > m_heapDatabase->_heap[son]) //������ڵ�����ӽڵ���������ϣ�ֱ����������
			return;
		else { //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
			std::swap(m_heapDatabase->_heap[dad], m_heapDatabase->_heap[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

template<typename T>
void Heap<T>::HeapInit(SWAPMODE smode)
{
	int len = m_heapDatabase->GetHeadSize();
	//��ʼ�� i�����һ�����ڵ㿪ʼ����
	for (int i = len / 2 - 1; i >= 0; i--)
		( smode == SWAPMODE::MAX ? MaxHeapify(i, len - 1) : MinHeapify(i, len - 1) );
		/*MaxHeapify(i, len - 1);*/
	//�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ������յ�����Ԫ��֮ǰ��Ԫ�أ���ֱ���������
		for (int i = len - 1; i > 0; i--) {
			std::swap(m_heapDatabase->_heap[0], m_heapDatabase->_heap[i]);
			( smode == SWAPMODE::MAX ? MaxHeapify(0, i - 1) : MinHeapify(0, i - 1) );
			/*MaxHeapify(0, i - 1);*/
		}

}







