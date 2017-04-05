#include <iostream>
#include <Stack.h>
#include <Queue.h>
#include <Exception.h>

using namespace std;

Queue<int> LuckyNumbers(int N);

int main() {
	int N, size;
	Queue<int> queue;

	cin >> N;
	while (N != 0) { // Recibo casos mientras sean distintos de cero

		if (N < 2 || N > 1000000)
			throw InvalidNumberException();

		queue = LuckyNumbers(N);

		// Stack para invertir el orden de la cola
		Stack<int> reverseQueue = Stack<int>();
		size = queue.size();

		for (int i = 0; i < size; i++)
		{
			reverseQueue.push(queue.front());
			queue.pop_front();
		}

		// Impresi�n
		cout << N << ": ";
		for (int i = reverseQueue.size(); i > 0; i--)
		{
			cout << reverseQueue.top() << " ";
			reverseQueue.pop();
		}
		cout << endl;
		cin >> N;
	}


	return 0;
}

Queue<int> LuckyNumbers(int N) {
	Queue<int> queue = Queue <int>();

	for (int i = 1; i <= N; i++)
	{
		queue.push_back(i);
	}

	int m = 2; // # elements to remove
	while (m <= queue.size()) { // Mientras # elems a sacar sea <= que el tama�o de la cola
		int count = 0, j = 0, size;

		size = queue.size();

		while (j < size) {
			if (count != 0)
				queue.push_back(queue.front());
			queue.pop_front();
			count = (count + 1) % m;
			j++;
		}
		m++;
	}
	return queue;
}
