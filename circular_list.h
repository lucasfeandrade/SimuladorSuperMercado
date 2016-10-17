// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

  //! Classe CircularList
  /*!
      Classe lista circular
  */
template<typename T>
class CircularList {
 public:
   //! CircularList()
  /*!
    Construtor default
  */
    CircularList() {
        size_ = 0;
        head = nullptr;
    }

    //! ~CircularList()
    /*!
      Destrutor da lista circular
    */
    ~CircularList() {
        clear();
    }

    //! Limpa a lista
    /*!
        Limpa a lista caso ela não esteja vazia
        \return void
    */
    void clear() {
        Node *current, *last;  // Variavel auxiliar para caminhar.
        current = head;
        int i = 0;
        while ( i < size_ ) {
            last = current;
            current = current->next();
            delete last;
            i++;
        }
        head = nullptr;
        size_ = 0u;
    }

    //! Insere no fim da lista
    /*!
        Insere no indice do tamanho da lista

        \param T& data: dado a ser inserido
    */
    void push_back(const T& data) {
        insert(data, size_);    // utiliza o metodo insert para inserir no fina
    }

    //! Insere no inicio da lista
    /*!
        Insere no inicio da lista caso ela não esteja cheia

        \param T& data: dado a ser inserido
    */
    void push_front(const T& data) {
        Node *newNode = new Node(data, head);
        if (newNode == nullptr )
           throw std::out_of_range("A lista já está cheia");
        head = newNode;
        if (empty()) {
            newNode->next(head);
        } else {
        for ( int i = 0 ; i < size_; ++i )
            newNode = newNode->next();
        }
        size_++;
    }

    // A partir daqui NENHUM CODIGO FOI ALTERADO

    //! Insere na posição
    /*!
        Insere o dado na posição endicada no parametro

        \param T& data: dado a ser inserido
        \param size_t: indice onde o dado será inserido
    */
    void insert(const T& data, std::size_t index) {
        Node *newNode;
        Node *oldNode;
        if (index == 0) {
            push_front(data);
        } else if ( index > size_ ) {
            throw std::out_of_range("Index invalido");
        } else {
            newNode = new Node(data);
            if (newNode == nullptr)
                throw std::out_of_range("Lista Cheia");
            oldNode = head;
            for ( int i = 0 ; i < index -1 ; ++i )
                oldNode= oldNode->next();
            newNode->next(oldNode->next());
            oldNode->next(newNode);
            size_++;
            if (index == size_) {
                newNode->next(head);
            }
        }
    }

    //! Insere em ordem
    /*!
        Insere o dado em ordem na lista

        \param T& data: dado a ser inserido
    */
    void insert_sorted(const T& data) {
        Node *current;
        int posicao = 0;
        if (empty()) {
            push_front(data);
        } else {
            current = head;
            while (posicao < size_ - 1 && data > current->data()) {
                current = current->next();
                posicao++;
            }
            if (data > current->data())
                insert(data, posicao+1);
            else
                insert(data, posicao);
        }
    }

    //! Retorna dado no indice indicado
    /*!

        \param size_t: Indice do dado a ser encontrado
        \return T&: dado no indice indicado
    */
    T& at(std::size_t index) {
        Node *finder = head;
        if (index < 0 || index > size_ -1 )
            throw std::out_of_range("Indice invalido");
        for (auto i = 0; i < index; ++i)
            finder = finder->next();
        return finder->data();
    }

    //! Retorna dado no indice indicado
    /*!

        \param size_t: Indice do dado a ser encontrado
        \return T&: dado no indice indicado
    */
    const T& at(std::size_t index) const {
        Node *finder = head;
        if (index < 0 || index > size_ -1 )
            throw std::out_of_range("Indice invalido");
        for (auto i = 0; i < index; ++i)
            finder = finder->next();
        return finder->data();
    }

    //! Retira da posicao
    /*!
        Retira o dado da posicao indicada pelo parametro

        \param size_t: Indice do elemento a ser retirado
        \return T: dado retirado
    */
    T pop(std::size_t index) {
        Node *last, *eliminate;  // Variável tipo node
        T back;   // Variável tipo T.
        if (index > size_ -1 || index < 0) {
            throw std::out_of_range("Posicao inserida invalida");
        } else if (empty()) {
            throw std::out_of_range("Lista está vazia");
        } else if (index == 0) {
            return pop_front();
        } else {
            last = head;
            for (int i = 0; i< index-1; i++)
                last = last->next();
            eliminate = last -> next();
            back = eliminate-> data();
            last -> next(eliminate ->next());
            size_--;
            delete eliminate;
            return back;
        }
    }

    //! Retira do fim da lista
    /*!
        \return T: dado retirado do fim da lista
    */
    T pop_back() {
        return pop(size_ -1);
    }

    //! Retira do inicio da lista
    /*!
        \return T: dado retirado do inicio da lista
    */
    T pop_front() {
        if (empty())
            throw std::out_of_range("A lista está vazia");
        Node* saiu = head;
        size_--;
        T volta = saiu->data();
        head = saiu->next();
        delete saiu;
        return volta;
    }

    //! Remove dado
    /*!
        Remove o dado caso ele existe
        \parm T&: dado a ser removido da lista
    */
    void remove(const T& data) {
        if (empty())
            throw std::out_of_range("A lista já está vazia");
        pop(find(data));
    }

    //! Método Lista Vazia
    /*!
        /return um boolean positivo caso a lista esteja vazia e negativa caso contrario
    */
    bool empty() const {
        return (size_ == 0);
    }

    //! Método Contem
    /*!
        /param T& data: Informacao à procurar
        /return um boolean positivo caso a lista tenha a informacao e negativo caso contrario
    */
    bool contains(const T& data) const {
        Node *search;
        search = head;
        for (int i = 0; i < size_ -1; i++) {
            if (data == search->data())
                return true;
            search = search->next();
        }
        return false;
    }

    //! Encontra dado
    /*!
        Encontra o dado do parametro caso ele exista e retorna a posicao
        /param T& data: Informacao à procurar
        /return size_t: posicao do dado encontrado
    */
    std::size_t find(const T& data) const {
        Node *finder = head;
        if (empty())
            throw std::out_of_range("A lista esta vazia");
        for (int index = 0; index < size_; index++) {
            if (finder->data() == data) {
                return index;
            }
            finder = finder->next();
        }
    return size_;
    }

    //! Tamanhoo da lista
    /*!
        /return size_t: retorna o tamanho da lista
    */
    std::size_t size() const {
        return size_;
    }

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }
    Node* head{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures

#endif
