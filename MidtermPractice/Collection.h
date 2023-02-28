#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T>
class Collection {
private:
    std::vector<T*> items;

public:
    Collection() {}

    Collection(const Collection& other) {
        for (T* item : other.items) {
            items.push_back(new T(*item));
        }
    }

    Collection& operator=(const Collection& other) {
        if (this != &other) {
            for (T* item : items) {
                delete item;
            }
            items.clear();

            for (T* item : other.items) {
                items.push_back(new T(*item));
            }
        }
        return *this;
    }

    Collection(Collection&& other) noexcept {
        items = std::move(other.items);
        other.items.clear();
    }

    Collection& operator=(Collection&& other) noexcept {
        if (this != &other) {
            for (T* item : items) {
                delete item;
            }
            items = std::move(other.items);
            other.items.clear();
        }
        return *this;
    }

    ~Collection() {
        for (T* item : items) {
            delete item;
        }
    }

    void add(T* item) {
        items.push_back(item);
    }

    void remove(int index) {
        if (index < 0 || index >= items.size()) {
            throw std::out_of_range("Invalid index");
        }
        delete items[index];
        items.erase(items.begin() + index);
    }

    T* retrieve(int index) {
        if (index < 0 || index >= items.size()) {
            throw std::out_of_range("Invalid index");
        }
        return items[index];
    }

    void modify(int index, T* item) {
        if (index < 0 || index >= items.size()) {
            throw std::out_of_range("Invalid index");
        }
        delete items[index];
        items[index] = item;
    }

    void print() {
        for (T* item : items) {
            std::cout << *item << std::endl;
        }
    }

    void clear() {
        for (T* item : items) {
            delete item;
        }
        items.clear();
    }

    void remove_if(std::function<bool(const T*)> condition) {
        items.erase(std::remove_if(items.begin(), items.end(), condition), items.end());
    }

    Collection<T> filter(std::function<bool(const T*)> condition) {
        Collection<T> result;
        for (T* item : items) {
            if (condition(item)) {
                result.add(new T(*item));
            }
        }
        return result;
    }
};
