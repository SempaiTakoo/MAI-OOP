#pragma once

#include "iterator.h"
#include "const_iterator.h"
#include "allocator.h"
#include <functional>


template <class T, class Allocator = std::allocator<T>>
class Stack {
   private:
    struct Node;
    using NodeAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
    using NodePointer = std::unique_ptr<Node, std::function<void(Node*)>>;

    struct Node {
        T value;
        NodePointer prev;
        explicit Node(const T& value)
            : value(value), prev(nullptr) {}
    };

    size_t size;
    NodePointer first;
    Node* top;

   public:
    using iterator = iterators::Iterator<Node, T>;
    using const_iterator = const_iterators::ConstIterator<Node, T>;

    Stack() : size(0), first(nullptr, NodeDeleter{nullptr}), top(nullptr) {}

    const_iterator cbegin() const { return const_iterator(first.get()); }

    const_iterator cend() const { return const_iterator(nullptr); }

    iterator begin() { return iterator(first.get()); }

    iterator end() { return iterator(nullptr); }

    void push(const T& value) {
        Node* newNode = allocateNode(value);
        newNode->prev = std::move(first);
        first = NodePointer(newNode, NodeDeleter{&nodeAllocator});
        if (size == 0) {
            top = first.get();
        }
        size++;
    }

    void pop() {
        if (size == 0) {
            throw std::logic_error("Can't pop from an empty Stack");
        }
        first = std::move(first->prev);
        size--;
    }

    T& peak() {
        if (size == 0) {
            throw std::logic_error("Stack is empty");
        }
        return first->value;
    }

    size_t length() const { return size; }

    bool empty() const { return size == 0; }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            clear();
            for (const auto& value : other) {
                push(value);
            }
        }
        return *this;
    }

    void clear() {
        first = nullptr;
        top = nullptr;
        size = 0;
    }

   private:
    NodeAllocator nodeAllocator;

    struct NodeDeleter {
        NodeAllocator* allocator;

        void operator()(Node* ptr) const {
            if (ptr != nullptr) {
                std::allocator_traits<NodeAllocator>::destroy(*allocator, ptr);
                allocator->deallocate(ptr, 1);
            }
        }
    };

    Node* allocateNode(const T& value) {
        Node* newNode = nodeAllocator.allocate(1);
        std::allocator_traits<NodeAllocator>::construct(nodeAllocator, newNode, value);
        return newNode;
    }
};
