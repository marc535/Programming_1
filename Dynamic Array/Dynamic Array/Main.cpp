#define DYNAMIC_ARRAY_CHUNK_SIZE 5
#define DYNAMIC_ARRAY_INITIAL_CAPACITY 5
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

class DynamicArray
{
private:
	int *mArray = nullptr;
	unsigned int mCapacity;
	unsigned int mSize;
	void increaseCapacity()
	{
		if (mSize > mCapacity)
		{
			mCapacity += DYNAMIC_ARRAY_CHUNK_SIZE;
			int *cArray = new int[mCapacity];
			for (int i = 0; i < mSize; i++)
			{
				cArray[i] = mArray[i];
			}
			delete[] mArray;
			mArray = new int[mCapacity];
			for (int i = 0; i < mSize; i++)
			{
				mArray[i] = cArray[i];
			}
			delete[] cArray;
			cArray = nullptr;
		}
	}
public:
	DynamicArray()
	{
		mCapacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;
		mSize = 0;
		mArray = new int[mCapacity];
	}
	~DynamicArray()
	{
		delete[] mArray;
		mArray = nullptr;
		mSize = 0;
		mCapacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;
	}

	bool empty() const { if (mSize == 0) { return true; } else { return false; } }
	unsigned int size() const { return mSize; }

	void push_back(int value)
	{
		mSize += 1;
		increaseCapacity();
		mArray[mSize - 1] = value;
	}
	void push_front(int value)
	{
		mSize += 1;
		increaseCapacity();
		int *cArray = new int[mCapacity];
		for (int i = 0; i < mSize; i++)
		{
			cArray[i] = mArray[i + 1];
		}
		for (int i = 0; i < mSize; i++)
		{
			mArray[i + 1] = cArray[i];
		}
		delete[] cArray;
		cArray = nullptr;
		mArray[0] = value;
	}
	void insert(unsigned int index, int value)
	{

	}
};

int main()
{


	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}