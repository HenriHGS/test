#include <iostream>
#include <memory>

template <typename T> class SmartPtr {
private:
  T *_ptr;
  size_t *_count;

public:
  SmartPtr(T *ptr = nullptr) : _ptr(ptr) {
    if (_ptr) {
      _count = new size_t(1);
    } else {
      _count = new size_t(0);
    }
  }
  ~SmartPtr() {
    (*this->_count)--;
    if (*this->_count == 0) {
      delete this->ptr;
      delete this->_count;
    }
  }
  SmartPtr(const SmartPtr &ptr) {
    if (this != &ptr) {
      this->_ptr = ptr._ptr;
      this->_count = ptr._count;
      (*this->_count)++;
    }
  }
  SmartPtr &operator=(const SmartPtr &ptr) {
    if (this->_ptr == ptr._ptr) {
      return *this;
    }
    if (this->_ptr) {
      if (*this->_count)
        --;
      if (this->_count == 0) {
        delete this->_ptr;
        delete this->_count;
      }
    }
    this->_ptr = ptr._ptr;
    this->_count = ptr._count;
    (*this->_count)++;
    return *this;
  }
  T &operator*() {
    assert(this->_ptr == nullptr);
    return *(this->_ptr);
  }
  T *operator->() {
    assert(this->_ptr == nullptr);
    return this->_ptr;
  }

  size_t use_count() { return *this->count; }
};