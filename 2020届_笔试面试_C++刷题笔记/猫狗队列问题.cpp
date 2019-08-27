#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

/*
ʵ��һ��è�����еĽṹ��Ҫ�����£�
�û����Ե���add������cat���dog���ʵ����������У�
�û����Ե���pollAll�����������������е�ʵ�����ն����Ƚ��ȳ���˳�����ε�����
�û����Ե���pollDog��������������dog��ʵ�����ն����Ƚ��ȳ���˳�����ε�����
�û����Ե���pollCat��������������cat��ʵ�����ն����Ƚ��ȳ���˳�����ε�����
�û����Ե���isEmpty()�����������������е�ʵ���Ƿ�Ϊ�գ�
�û����Ե���isDogEmpty()��������������dog��ʵ���Ƿ�Ϊ�գ�
�û����Ե���isCatEmpty()��������������cat��ʵ���Ƿ�Ϊ�գ�

˼�룺����������дһ������ʱ���������PetCount��ʹ�京��һ�����ڼ�¼�Ⱥ�˳��ļ�����count��
ÿ����ӵ�ʱ��������ͽ����Ӧ�Ķ��У��������һ�޶���ʱ��������ӵ�ʱ�����Ҫ��Ƚ��Ⱥ�ʱ�伴�ɡ�
*/

class Pet {
	string type;
public:
	Pet(string type) {
		this->type = type;
	}
	string getPetType() {
		return this->type;
	}
};

class Dog :public Pet {
public:
	Dog() :Pet("Dog") {}
	Dog(string type) : Pet(type) {}
};

class Cat :public Pet {
public:
	Cat() : Pet("Cat") {}
	Cat(string type) : Pet(type) {}
};

/*
����Pet* pet;ʹ��ָ���ԭ���ǣ�C++�и��༴ʹ�����������࣬Ҳ�����ٴ�ת�������࣬��Ϊ���ݻᱻ�ضϡ�
ֻ��ʹ��ָ�����ʵ�����ת������һ�ָ�����ķ�ʽ�Ƕ�������Count�࣬�ֱ�洢è�������ࡣ
*/
class PetCount {
	Pet* pet;
	int count; // ÿ��������Ե�ʱ���
public:
	PetCount(Pet* pet, int cnt) {
		this->pet = pet;
		this->count = cnt;
	}
	Pet* getPet() {
		return pet;
	}
	int getCount() {
		return this->count;
	}
	string getPetType() {
		return pet->getPetType();
	}
};

class DogCatQueue {
	queue<PetCount>catq;
	queue<PetCount>dogq;
	int count; // ���г����ܵ�ʱ���
public:
	DogCatQueue() :count(0) {}
	void add(Pet *pet) {
		if (pet->getPetType().find("dog") )
		{
			dogq.push(PetCount(pet, ++count)); // pet������������new�����ģ�������������ʱ����
		}
		else
		{
			catq.push(PetCount(pet, ++count));
		}
	}
	//void add(Dog *d) {
	//	dogq.push(PetCount(d, ++count));
	//}
	//void add(Cat *c) {
	//	catq.push(PetCount(c, ++count));
	//}
	bool empty() {
		return dogq.empty() && catq.empty();
	}
	bool DogEmpty() { return dogq.empty(); }
	bool CatEmpty() { return catq.empty(); }

	Cat *pollCat() {
		Cat* r = static_cast<Cat*>(catq.front().getPet());
		catq.pop();
		return r;
	}
	Dog *pollDog() {
		Dog*r = static_cast<Dog*>(dogq.front().getPet());
		dogq.pop();
		return r;
	}
	Pet* pollAll() {
		if (empty())return nullptr;
		else if (DogEmpty())return pollCat();
		else if (CatEmpty())return pollDog();
		cout << dogq.front().getPetType() << " Count = " << dogq.front().getCount() << endl;
		cout << catq.front().getPetType() << " Count = " << catq.front().getCount() << endl;
		return (dogq.front().getCount() < catq.front().getCount()) ? (Pet*)pollDog() : (Pet*)pollCat();
	}
};

int main10011011112120020200(void)
{
	DogCatQueue myqueue;
	Dog *dog1 = new Dog("dog1");
	Cat *cat1 = new Cat("cat1");
	Dog *dog2 = new Dog("dog2");
	Cat *cat2 = new Cat("cat2");
	Dog *dog3 = new Dog("dog3");
	Cat *cat3 = new Cat("cat3");

	myqueue.add(dog1);
	myqueue.add(cat1);
	myqueue.add(dog2);
	myqueue.add(cat2);
	myqueue.add(dog3);
	myqueue.add(cat3);

	for (int i = 0; (!myqueue.CatEmpty() || !myqueue.DogEmpty()); ++i)
	{
		cout << myqueue.pollAll()->getPetType() << endl;
	}

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}