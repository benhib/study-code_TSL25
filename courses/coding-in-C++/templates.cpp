
template <typename T, typename U>
class Pair {
    private:
        T first;
        U second;
    public:
        void setFirst(const T first) {
            this->first = first;
        }

        void setSecond(const U second) {
            this->second = second;
        }

        T getFirst() const{
            return this->first;
        }

        U getSecond() const{
            return this->second;
        }

        Pair(T first, U Second) : first(first), second(second) {};
};