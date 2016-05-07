//
// Created by Ivo Georgiev on 5/3/16.
//

#ifndef UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
#define UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H

// Naive partial implementation of a custom iterator.
// After Jeet Sukumaran https://github.com/jeetsukumaran

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>

namespace CS2312 {

    template <typename T>
    class fixed_array {

    public:

        typedef std::size_t size_type;

        class iterator {

        public:
            // so made up type classes that I didn't make and he hasn't specified what exactly they are

            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

// Empty functions need filled
        // these functions allow the data to be altered.
            iterator(pointer ptr)
            {
                __ptr = ptr;
            }
            self_type operator++()
            {
                // move my raw pointer forward one. Raw pointer to what?
                // I have T* which is a type he's called star
                // I return whatever this is now pointing to
                __ptr++;
                return *this;
            }
            self_type operator++(int junk)
            {
                self_type p = *this;
                __ptr++;
                return p;
            }
            reference operator*()
            {
                // send back only the data that the pointer is point to.
                // but it doesn't like that because iterator doesn't have a field data.
                // iterator_catagory;
                return *__ptr;
            }
            pointer operator->()
            {
                // pointing at something. The book doesn't even mention these
                return this->__ptr;
            }
            bool operator==(const self_type& rhs) const
            {
                // compare what this is point to to what the hrs has
                if (__ptr == rhs.__ptr)
                    return true;
                else
                    return false;
            }
            bool operator!=(const self_type& rhs) const
            {
                // compare again and look for them not to be equal
                if (__ptr == rhs.__ptr)
                    return false;
                else
                    return true;
            }

        private:
            // Something I understand a pointer
            pointer __ptr;

        };

        class const_iterator {

        public:

            typedef const_iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

// empty functions need filled
        // these functions do not allow the data to be altered
            const_iterator(pointer ptr)
            {
                __ptr = ptr;
            }
            self_type operator++()
            {
                __ptr++;
                return *this;
            }
            self_type operator++(int junk)
            {
                for (int i=0; i<junk; i++)
                {
                    __ptr++;
                }
                return *this;
            }
            const value_type& operator*() const
            {
                return *__ptr;
            }
            const value_type* operator->() const
            {
                return this->__ptr;
            }
            bool operator==(const self_type& rhs) const
            {
                if (__ptr == rhs.__ptr)
                    return true;
                else
                    return false;
            }
            bool operator!=(const self_type& rhs) const
            {
                if (__ptr == rhs.__ptr)
                    return false;
                else
                    return true;
            }

        private:

            pointer __ptr;

        };

// Even more empty functions
        fixed_array(size_type size)
        {
            __size = size;
            __data = new T[__size];
        }

        fixed_array(std::initializer_list<T> list)
        {
            // vector was in the header files.
            std::vector<T> myvector(list);
            __size = myvector.size();
            __data = new T[__size];
            for (int i=0; i < __size; i++)
            {
                __data[i] = myvector[i];
            }
        }

        ~fixed_array()
        {

        }

        size_type size() const
        {
            return __size;
        }

        T& operator[](size_type index)
        {
            return __data[index];
        }

        const T& operator[](size_type index) const
        {
            return __data[index];
        }

        iterator begin()
        {
            return iterator(__data);
        }

        iterator end()
        {
            return iterator(__data + __size);
        }

        const_iterator begin() const
        {
            return const_iterator(__data);
        }

        const_iterator end() const
        {
            return const_iterator(__data + __size);
        }

    private:

        T* __data;
        size_type __size;

    };

}

#endif //UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
