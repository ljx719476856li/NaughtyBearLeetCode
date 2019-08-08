#include <iostream>
#include <queue>
using namespace std;

class Pet
{
public:
	Pet() :m_sType("Pet") {}

	string GetType()
	{
		return m_sType;
	}

protected:
	string m_sType;
};
class Cat :public Pet
{
public:
	Cat() { m_sType = "Cat"; }
};
class Dog : public Pet
{
public:
	Dog() { m_sType = "Dog"; }
};

class PetEnterQueue
{
public:
	PetEnterQueue(const Pet& pet, int count) : m_pet(pet), m_iCount(count) {}

	int GetCount() {return m_iCount;}
	Pet* GetPet() {return &m_pet;}
	string GetPetType() { return m_pet.GetType(); }

private:
	Pet m_pet;
	int m_iCount;
};

class DogCatQueue
{
public:
	Pet m_nullPet;
	queue<PetEnterQueue> m_dog;
	queue<PetEnterQueue> m_cat;
	int m_iCount;

	DogCatQueue():m_iCount(0) {}

	void Add(Pet pet); //��cat���dog��� ʵ�����������
	Pet* PollAll(); //�����������е�ʵ�����ս����� ���Ⱥ�˳�����ε���
	Dog* PollDog(); //��������dog���ʵ������ �����е��Ⱥ�˳�����ε���
	Cat* PollCat(); // ��������cat���ʵ �����ս����е��Ⱥ�˳�����ε���

	bool isEmpty(); //���������� ����dog��cat��ʵ��
	bool isDogEmpty(); //���������Ƿ���dog ���ʵ��
	bool isCatEmpty(); //���������Ƿ���cat���ʵ��

};

void DogCatQueue::Add(Pet pet)
{
	if (pet.GetType()._Equal("Dog"))
		m_dog.push(PetEnterQueue(pet, m_iCount++));
	else if (pet.GetType()._Equal("Cat"))
		m_cat.push(PetEnterQueue(pet, m_iCount++));
	else
		return;
}

Pet* DogCatQueue::PollAll()
{
	Pet* res;
	if (!m_cat.empty() && !m_dog.empty())
	{
		if (m_cat.front().GetCount() < m_dog.front().GetCount())
		{
			res = m_cat.front().GetPet();
			m_cat.pop();
		}
		else
		{
			res = m_dog.front().GetPet();
			m_dog.pop();
		}
	}
	else if (!m_cat.empty())
	{
		res = m_cat.front().GetPet();
		m_cat.pop();
	}
	else if (!m_dog.empty())
	{
		res = m_dog.front().GetPet();
		m_dog.pop();
	}
	else
		throw "err, queue is empty!";

	return res;
}

Cat* DogCatQueue::PollCat()
{
	if (isCatEmpty())
		throw "err, queue is empty!";
	
	Cat* cat = static_cast<Cat*>(m_cat.front().GetPet());
	m_cat.pop();
	return cat;
}

Dog* DogCatQueue::PollDog()
{
	if (isDogEmpty())
		throw "err, queue is empty!";

	Dog* dog = static_cast<Dog*>(m_dog.front().GetPet());
}
	
bool DogCatQueue::isEmpty()
{
	return m_cat.empty() && m_dog.empty();
}	
bool DogCatQueue::isDogEmpty()
{
	return m_dog.empty();
}	
bool DogCatQueue::isCatEmpty()
{
	return m_cat.empty();
}

int main()
{
	DogCatQueue test;
	Pet* dog1 = new Dog();
	Pet* cat1 = new Cat();
	Pet* dog2 = new Dog();
	Pet* cat2 = new Cat();
	Pet* dog3 = new Dog();
	Pet* cat3 = new Cat();

	test.Add(*dog1);
	test.Add(*cat1);
	test.Add(*dog2);
	test.Add(*cat2);
	test.Add(*dog3);
	test.Add(*cat3);

	test.Add(*dog1);
	test.Add(*cat1);
	test.Add(*dog2);
	test.Add(*cat2);
	test.Add(*dog3);
	test.Add(*cat3);

	test.Add(*dog1);
	test.Add(*cat1);
	test.Add(*dog2);
	test.Add(*cat2);
	test.Add(*dog3);
	test.Add(*cat3);

	while (!test.isEmpty())
	{
		string type = test.PollAll()->GetType();
	}

	return 0;
}
