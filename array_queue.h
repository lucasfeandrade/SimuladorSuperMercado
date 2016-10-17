#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>
class ArrayQueue {
public:
    ArrayQueue();

    ArrayQueue(std::size_t max);

    ~ArrayQueue();

    void enqueue(const T& data);
    T& front();

    T dequeue();

    T& back();

    void clear();

    std::size_t size();

    std::size_t max_size();

    bool empty();

    bool full();

private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_SIZE = 10u;
};

//! Construtor Default
/*!
    Descricao mais elaborada do construtor.
*/
template <class T>
ArrayQueue<T>::ArrayQueue(){
	size_ = -1;
	max_size_ = DEFAULT_SIZE;
	contents = new T[max_size_];
}

//! Construtor com parametro
/*!
   \param max Define tamanho maximo da fila.
*/
template <class T>
ArrayQueue<T>::ArrayQueue(std::size_t max){
	max_size_ = max;
	size_=-1;
	contents = new T[max_size_];
}

template <class T>
ArrayQueue<T>::~ArrayQueue(){
}

//! Limpa a fila
/*!
    Coloca -1 no valor do size_o.
*/
template <class T>
void ArrayQueue<T>::clear(){
	size_ = -1;
}

//! Checa se a fila esta cheia
/*!
    \return Retorna positivo caso a fila esteja cheia.
*/
template <class T>
bool ArrayQueue<T>::full(){
	return (size_ == max_size_ -1);
}

//! Checa se a fila está vazia
/*!
    \return Retorna positivo caso a fila esteja vazia.
*/
template <class T>
bool ArrayQueue<T>::empty(){
	return (size_ == -1);
}


//! Enfilera dados
/*!
    \param data Argumento const T& a ser enfilerado.
*/
template <class T>
void ArrayQueue<T>::enqueue(const T& data){
	if(full())
		throw std::out_of_range("A pilha já está cheia");
	else{
		size_ = size_ + 1;
		contents[size_] = data;
	}
}


//! Desempilha dado
/*!
    \return O size_o da pilha que foi desenfilerado.
*/
template <class T>
T ArrayQueue<T>::dequeue(){
	if(empty())
		throw std::out_of_range("A fila já está vazia, não é possível retirar");
	else{
	    T firstItem = contents[0];
	    for (int i = 0; i < size_ ; i++) {
		    contents[i] = contents[i+1];
	    }
	    size_ = size_ - 1;
        return firstItem;
	}
}

//! size_o da pilha
/*!
    \return O size_o da pilha caso ela nao esteja vazia.
*/
template <class T>
T& ArrayQueue<T>::back(){
	if(empty())
		throw std::out_of_range("A pilha está vazia, não tem size_o");
	else
		return contents[size_];
}

template <class T>
T& ArrayQueue<T>::front(){
	if(empty())
		throw std::out_of_range("A pilha está vazia, não tem size_o");
	else
		return contents[0];
}

//! size_o Atual
/*!
    \return O valor do size_o atual da fila.
*/
template <class T>
std::size_t ArrayQueue<T>::size(){
    return size_+1;
}

//! size_o maximo
/*!
    \return O size_o maximo da fila.
*/
template <class T>
std::size_t ArrayQueue<T>::max_size(){
    return max_size_;
}


//! size_o maximo
/*!
    \param index é o indice do conteudo a ser visto
    \return O size_o maximo da fila.
*/
template <class T>
T& ArrayQueue<T>::contents(index){
    if (index > size_)
        throw std::out_of_range("A pilha já está cheia");
    return contents[index];
}

}

#endif
