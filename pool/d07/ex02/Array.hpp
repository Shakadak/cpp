#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename A>
class Array {
    public:
        Array<A>(void) : _size(0) {
            _xs = new A [0];
        }

        ~Array<A>(void) {
            delete [] _xs;
            _xs = NULL;
        }

        Array<A>(unsigned int n) : _size(n) {
            _xs = new A [n];
            if (!_xs) {
                _size = 0;
            }
        }

        Array<A>(Array<A> const& src) : _size(src._size) {
            _xs = new A [_size];
            if (!_xs) {
                _size = 0;
            }
            else {
                for (size_t i = 0; i < _size; i++) {
                    _xs[i] = src._xs[i];
                }
            }
        }

        Array<A>&   operator=(Array<A> const& rhs) {
            delete [] _xs;
            _xs = new A [rhs._size];
            if (!_xs) {
                _size = 0;
            }
            else {
                for (size_t i = 0; i < _size; i++) {
                    _xs[i] = rhs._xs[i];
                }
            }
            return (*this);
        }

        A&          operator[](size_t i) {
            if (i >= _size) {
                throw std::exception();
            }
            return (_xs[i]);
        }

        size_t  size(void) const {
            return (_size);
        }

    private:
        size_t  _size;
        A*      _xs;
};

#endif
