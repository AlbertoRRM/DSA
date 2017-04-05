#include <iostream>
using namespace std;

/*
Definicion de algunas excepciones de las distintas
implementaciones de los TADs.

Estructura de Datos y Algoritmos
Facultad de Informatica
Universidad Complutense de Madrid

(c) Marco Antonio Gomez Martin, 2012
*/

#include <string>
#include <iosfwd>

/**
Clase de la que heredan todas las excepciones, y
que proporciona el atributo que almacena el
mensaje de error.
*/
class ExcepcionTAD {
public:
	ExcepcionTAD() {}
	ExcepcionTAD(const std::string &msg) : _msg(msg) {}

	const std::string msg() const { return _msg; }

	friend std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e);

protected:
	std::string _msg;
};

inline std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e) {
	out << e._msg;
	return out;
}

// Macro para declarar las clases de tipo excepcion
// que heredan de ExcepcionConMensaje, para ahorrar
// escribir muchas veces lo mismo...
#define DECLARA_EXCEPCION(Excepcion) \
class Excepcion : public ExcepcionTAD { \
public: \
Excepcion() {}; \
Excepcion(const std::string &msg) : ExcepcionTAD(msg) {} \
};

/**
Excepcion generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(EmptyStackException);

/**
Excepcion generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(FullStackException);

/**
Excepcion generada por algunas de las operaciones de las colas.
*/
DECLARA_EXCEPCION(EmptyQueueException);

/**
Excepcion generada por algunas operaciones de las colas dobles.
*/
DECLARA_EXCEPCION(EmptyDequeException);

/**
Excepcion generada por algunas operaciones de las listas.
*/
DECLARA_EXCEPCION(EmptyListException);

/**
Excepcion generada por accesos incorrectos a las listas
(tanto a un numero de elementos incorrecto como por
mal manejo de los iteradores).
*/
DECLARA_EXCEPCION(InvalidAccessException);

/**
Excepcion generada por algunas operaciones de los
arboles binarios.
*/
DECLARA_EXCEPCION(EArbolVacio);

/**
Excepcion generada por algunas operaciones de los
diccionarios y arboles de busqueda.
*/
DECLARA_EXCEPCION(EClaveErronea);

DECLARA_EXCEPCION(InvalidNumberException);

template <class T>
class Stack {
public:

	/** Tamaño inicial del vector din�mico. */
	static const int TAM_INICIAL = 10;

	/** Constructor; operacion EmptyStack */
	Stack() {
		inicia();
	}

	/** Destructor: elimina el vector. */
	~Stack() {
		libera();
	}

	/**
	Apila un elemento. Operacion generadora.

	@param elem Elemento a apilar.
	*/
	void push(const T &elem) {
		_v[_numElems] = elem;
		_numElems++;
		if (_numElems == _tam)
			amplia();
	}

	/**
	Desapila un elemento. Operacion modificadora parcial,
	que falla si la pila esta vacia.

	pop(Push(elem, p)) = p
	error: pop(EmptyStack)
	*/
	void pop() {
		if (empty())
			throw EmptyStackException();
		--_numElems;
	}

	/**
	Devuelve el elemento en la cima de la pila. Operaci�n
	observadora parcial, que falla si la pila est� vac�a.

	top(Push(elem, p) = elem
	error: top(EmptyStack)

	@return Elemento en la cima de la pila.
	*/
	const T &top() const {
		if (empty())
			throw EmptyStackException();
		return _v[_numElems - 1];
	}

	/**
	Devuelve true si la pila no tiene ning�n elemento.

	empty(EmptyStack) = true
	empty(Push(elem, p)) = false

	@return true si la pila no tiene ning�n elemento.
	*/
	bool empty() const {
		return _numElems == 0;
	}

	/**
	Devuelve el n�mero de elementos que hay en la
	pila.
	size(EmptyStack) = 0
	size(Push(elem, p)) = 1 + size(p)

	@return N�mero de elementos.
	*/
	int size() const {
		return _numElems;
	}

	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
	// A LA CLASE
	// //

	/** Constructor copia */
	Stack(const Stack<T> &other) {
		copia(other);
	}

	/** Operador de asignaci�n */
	Stack<T> &operator=(const Stack<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const Stack<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		for (unsigned int i = 0; i < _numElems; ++i)
			if (_v[i] != rhs._v[i])
				return false;
		return true;
	}

	bool operator!=(const Stack<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void inicia() {
		_v = new T[TAM_INICIAL];
		_tam = TAM_INICIAL;
		_numElems = 0;
	}

	void libera() {
		delete[]_v;
		_v = NULL;
	}

	void copia(const Stack &other) {
		_tam = other._numElems + TAM_INICIAL;
		_numElems = other._numElems;
		_v = new T[_tam];
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}

	void amplia() {
		T *viejo = _v;
		_tam *= 2;
		_v = new T[_tam];

		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = viejo[i];

		delete[]viejo;
	}

private:

	/** Puntero al array que contiene los datos. */
	T *_v;

	/** Tama�o del vector _v. */
	unsigned int _tam;

	/** N�mero de elementos reales guardados. */
	unsigned int _numElems;
};


template <class T>
class Queue {
public:

	/** Constructor; operacion EmptyQueue */
	Queue() : _prim(NULL), _ult(NULL), _numElems(0) {
	}

	/** Destructor; elimina la lista enlazada. */
	~Queue() {
		libera();
		_prim = _ult = NULL;
	}

	/**
	 A�ade un elemento en la parte trasera de la cola.
	 Operaci�n generadora.

	 @param elem Elemento a a�adir.
	 */
	void push_back(const T &elem) {
		Nodo *nuevo = new Nodo(elem, NULL);

		if (_ult != NULL)
			_ult->_sig = nuevo;
		_ult = nuevo;
		// Si la cola estaba vac�a, el primer elemento
		// es el que acabamos de a�adir
		if (_prim == NULL)
			_prim = nuevo;
		_numElems++;
	}

	/**
	 Elimina el primer elemento de la cola.
	 Operaci�n modificadora parcial, que falla si
	 la cola est� vac�a.

	 pop_front(Push_back(elem, EmptyQueue)) = EmptyQueue
	 pop_front(Push_back(elem, xs)) = push_back(elem, pop_front(xs)) si !empty(xs)
	 error: pop_front(EmptyQueue)
	 */
	void pop_front() {
		if (empty())
			throw EmptyQueueException();
		Nodo *aBorrar = _prim;
		_prim = _prim->_sig;
		delete aBorrar;
		--_numElems;
		// Si la cola se qued� vac�a, no hay
		// �ltimo
		if (_prim == NULL)
			_ult = NULL;
	}

	/**
	 Devuelve el primer elemento de la cola. Operaci�n
	 observadora parcial, que falla si la cola est� vac�a.

	 front(Push_back(elem, EmptyQueue)) = elem
	 front(Push_back(elem, xs)) = primero(xs) si !empty(xs)
	 error: front(EmptyQueue)

	 @return El primer elemento de la cola.
	 */
	const T &front() const {
		if (empty())
			throw EmptyQueueException();
		return _prim->_elem;
	}

	/**
	 Devuelve true si la cola no tiene ning�n elemento.

	 empty(EmptyQueue) = true
	 empty(Push_back(elem, p)) = false

	 @return true si la cola no tiene ning�n elemento.
	 */
	bool empty() const {
		return _prim == NULL;
	}

	/**
	 Devuelve el n�mero de elementos que hay en la
	 cola.
	 size(EmptyQueue) = 0
	 size(Push_back(elem, p)) = 1 + size(p)

	 @return N�mero de elementos.
	 */
	int size() const {
		return _numElems;
	}

	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
	// A LA CLASE
	// //

	/** Constructor copia */
	Queue(const Queue<T> &other) : _prim(NULL), _ult(NULL) {
		copia(other);
	}

	/** Operador de asignaci�n */
	Queue<T> &operator=(const Queue<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const Queue<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		Nodo *p1 = _prim;
		Nodo *p2 = rhs._prim;
		while ((p1 != NULL) && (p2 != NULL)) {
			if (p1->_elem != p2->_elem)
				return false;
			p1 = p1->_sig;
			p2 = p2->_sig;
		}

		return (p1 == NULL) && (p2 == NULL);
	}

	bool operator!=(const Queue<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void libera() {
		libera(_prim);
	}

	void copia(const Queue &other) {

		if (other.empty()) {
			_prim = _ult = NULL;
			_numElems = 0;
		}
		else {
			Nodo *act = other._prim;
			Nodo *ant;
			_prim = new Nodo(act->_elem);
			ant = _prim;
			while (act->_sig != NULL) {
				act = act->_sig;
				ant->_sig = new Nodo(act->_elem);
				ant = ant->_sig;
			}
			_ult = ant;
			_numElems = other._numElems;
		}
	}

private:

	/**
	 Clase nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente, que podr�a ser NULL si
	 el nodo es el �ltimo de la lista enlazada.
	 */
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T &elem, Nodo *sig) :
			_elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	/**
	 Elimina todos los nodos de la lista enlazada cuyo
	 primer nodo se pasa como par�metro.
	 Se admite que el nodo sea NULL (no habr� nada que
	 liberar).
	 */
	static void libera(Nodo *prim) {
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}
	}

	/** Puntero al primer elemento. */
	Nodo *_prim;

	/** Puntero al �ltimo elemento. */
	Nodo *_ult;

	/** N�mero de elementos */
	int _numElems;
};

bool dehesapila(int n, Queue<int> queue_out);

int main() {
	int n, val;
	Queue<int> queue_out = Queue<int>();

	cin >> n;

	while (n != 0) {
		while (!queue_out.empty()) { // En caso de que no se haya vaciado en las ejecuciones anteriores.
			queue_out.pop_front();
		}

		for (int i = 0; i < n; i++) {
			cin >> val;
			queue_out.push_back(val);
		}

		if (dehesapila(n, queue_out)) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}

		cin >> n;
	}

	return 0;
}

bool dehesapila(int n, Queue<int> queue_out) {
	Stack<int> pila = Stack<int>();
	Queue<int> queue_in = Queue<int>();
	bool isPossible = true;

	for (int j = 1; j <= n; j++) {
		queue_in.push_back(j);
	}

	while ((!pila.empty() || !queue_in.empty()) && isPossible) {
		
		if (!pila.empty() && pila.top() == queue_out.front()) {
			cout << "Wagon " << queue_out.front() << " out" << endl;
			pila.pop();
			queue_out.pop_front();
		}
		else {
			if (!queue_in.empty()) {
				pila.push(queue_in.front());
				cout << "Wagon " << queue_in.front() << " in" << endl;
				queue_in.pop_front();
			}
			if (queue_in.empty() && pila.top() != queue_out.front())
				isPossible = false;
		}
	}

	while (!pila.empty())
		pila.pop();

	return isPossible;
}
