#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Deque {
public:
	Deque() {}
	bool Empty() const {
		return deque_f.empty() && deque_b.empty();
	}
	size_t Size() const {
		return deque_f.size() + deque_b.size();
	}

	T&  operator[](size_t index) {
		return index >= deque_f.size() ? deque_b[index - deque_f.size()] : *(deque_f.rbegin() + index);
	}
	const T& operator[](size_t index) const {
		return index >= deque_f.size() ? deque_b[index - deque_f.size()] : *(deque_f.rbegin() + index);
	}
	T& Front() {
		return deque_f.size() == 0 ? *deque_b.begin() : *prev(deque_f.end());
	}
	const T& Front() const {
		return deque_f.size() == 0 ? *deque_b.begin() : *prev(deque_f.end());
	}
	T& Back() {
		return deque_b.size() == 0 ? *deque_f.begin() : *prev(deque_b.end());
	}
	const T& Back() const {
		return deque_b.size() == 0 ? *deque_f.begin() : *prev(deque_b.end());
	}
	void PushFront(T value) {
		deque_f.emplace_back(value);
	}

	void PushBack(T value) {
		deque_b.emplace_back(value);
	}

	T& At(size_t index) {
		if (index >= (deque_f.size() + deque_b.size())) {
			throw out_of_range("");
		}
		return index >= deque_f.size() ? deque_b[index - deque_f.size()] : *(deque_f.rbegin() + index);
	}
	T& At(size_t index) const {
		if (index >= (deque_f.size() + deque_b.size())) {
			throw out_of_range("");
		}
		return index >= deque_f.size() ? deque_b[index - deque_f.size()] : *(deque_f.rbegin() + index);
	}


private:
	vector<T> deque_f;
	vector<T> deque_b;
};

int main() {
	Deque<int> d;
	d.PushFront(1);
	d.PushFront(2);
	d.PushFront(3);


	cout << d.At(0) << endl;;
	return 0;
}
