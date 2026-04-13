#include <iostream>
#include <string>

class Note {
    private:
        std::string* text;

    public:

    Note(std::string text) {
        this->text = new std::string(text);
    }

    Note(const Note& note) {
        this->text = new std::string(*(note.text));
    }

    ~Note() {
        delete text;
    }

    void display() {
        std::cout << *text << "\n";
    }
};


int main() {

    Note first_note("Hallo");
    Note second_note(first_note); // is possible because a Note is basically just a string pointer, so you can use the pointer as value

    first_note.display();
    second_note.display();

    /*
     Error when closing the programm, because the second note just has the same pointer.
     -> the compiler tries to free the same pointer twice
    
    Solution:
    defined constructor that creates it's own allocated memory
     */

} 