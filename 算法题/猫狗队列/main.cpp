//实现一种狗猫队列的结构，要求如下：
//用户可以调用add方法将cat类或dog类的实例放入队列中；
//用户可以调用pollAll方法，将队列中所有的实例按照进队列的先后顺序依次弹出；
//用户可以调用pollDog方法，将队列中dog类的实例按照进队列的先后顺序依次弹出；
//用户可以调用pollCat方法，将队列中cat类的实例按照进队列的先后顺序依次弹出；
//用户可以调用isEmpty方法，检查队列中是否还有dog或cat的实例；
//用户可以调用isDogEmpty方法，检查队列中是否有dog类的实例；
//用户可以调用isCatEmpty方法，检查队列中是否有cat类的实例。

#include<queue>
#include<vector>
#include<exception>

using namespace std;

class Pet
{
private:
	string type;
public:
	Pet(string type)
	{
		this->type = type;
	}

	string getPetType()
	{
		return type;
	}
};

class Dog :public Pet
{
public:
	Dog():Pet("dog")
	{
	}
};

class Cat :public Pet
{
public:
	Cat():Pet("cat")
	{
	}
};

class PetEnterQueue
{
private:
	Pet* pet;
	long count;

public:
	PetEnterQueue(Pet *pet, long count) 
	{
		this->pet = pet;
		this->count = count;
	}

	Pet* getPet() {
		return pet;
	}

	long getCount() {
		return count;
	}

	string getEnterPetType() {
		return pet->getPetType();
	}
};

class DogCatQueue {
private:
	queue<PetEnterQueue> dogQ;
	queue<PetEnterQueue> catQ;
	long count;

public:
	DogCatQueue() 
	{
		count = 0;
	}

	void add(Pet* pet) {
		if (pet->getPetType()=="dog") {
			dogQ.push(PetEnterQueue(pet, count++));
		}
		else if (pet->getPetType()=="cat") {
			catQ.push(PetEnterQueue(pet, count++));
		}
		else {
			throw exception("err, not dog or cat");
		}
	}

	Pet* pollAll() {
		if (!dogQ.empty() && !catQ.empty()) {
			if (dogQ.front().getCount() < catQ.front().getCount()) {
				Pet* res = dogQ.front().getPet();
				dogQ.pop();
				return res;
			}
			else {
				Pet* res = catQ.front().getPet();
				catQ.pop();
				return res;
			}
		}
		else if (!dogQ.empty()) {
			Pet* res = dogQ.front().getPet();
			dogQ.pop();
			return res;
		}
		else if (!catQ.empty()) {
			Pet* res = catQ.front().getPet();
			catQ.pop();
			return res;
		}
		else {
			throw exception("err, queue is empty!");
		}
	}

	Dog* pollDog() {
		if (!isDogQueueEmpty()) {
			Dog* res = (Dog*)dogQ.front().getPet();
			dogQ.pop();
			return res;
		}
		else {
			throw exception("Dog queue is empty!");
		}
	}

	Cat* pollCat() {
		if (!isCatQueueEmpty()) {
			Cat* res = (Cat*)catQ.front().getPet();
			catQ.pop();
			return res;
		}
		else
			throw exception("Cat queue is empty!");
	}

	bool isEmpty() 
	{
		return dogQ.empty() && catQ.empty();
	}

	bool isDogQueueEmpty() 
	{
		return dogQ.empty();
	}

	bool isCatQueueEmpty() {
		return catQ.empty();
	}
};


void main() 
{
	DogCatQueue test = DogCatQueue();

	Pet dog1 = Dog();
	Pet cat1 = Cat();
	Pet dog2 = Dog();
	Pet cat2 = Cat();
	Pet dog3 = Dog();
	Pet cat3 = Cat();

	test.add(&dog1);
	test.add(&cat1);
	test.add(&dog2);
	test.add(&cat2);
	test.add(&dog3);
	test.add(&cat3);

	while (!test.isDogQueueEmpty()) {
		printf("%s\n",test.pollDog()->getPetType().c_str());
	}
	while (!test.isEmpty()) {
		printf("%s\n",test.pollAll()->getPetType().c_str());
	}
	system("pause");
}
