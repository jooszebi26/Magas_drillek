#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void error(string s){
    throw runtime_error(s);
}

void error(string s1, string s2){
    throw runtime_error(s1+s2);
}

struct Person{
    Person(){}
    Person(string ff, string ll, int aa);

    string first_n() const {return firstName;}
    string last_n() const {return lastName;}
    int age () const {return person_age;}
    
    private:
    string firstName;
    string lastName;
    int person_age;

};

Person:: Person(string ff, string ll, int aa): firstName{ff}, lastName{ll}, person_age{aa}{
    if(aa < 0 || 150 < aa) error("Person(): invalid age");

    string name = ff + ll;
    for(char c : name){
        if(c == ';' || c == ':' || c == '[' || c == ']' || c=='*' || c== '&'
        || c == '^' || c== '%' || c=='$' || c=='#' || c== '@' || c=='!'){
            error("bad char");
        }

    }
}

ostream& operator <<(ostream& os, const Person& person){
    return os << "Name: " <<person.first_n() << " "<< 
    person.last_n() <<  endl <<"Age: "<< person.age() << endl; 
}

istream& operator >>(istream& is, Person& person){
    string first;
    string last;
    int age;

    is >> first >> last >> age;

    if(!is) error("Cannot read Person");

    person = Person(first, last, age);
    return is;
}

int main (){
    try{
        vector<Person> vector_p;
        cout<< "Enter a name with age. When you done write: fine"<<endl;
        for(Person p; cin >> p;){
            if(p.first_n() == "fine") break;
            vector_p.push_back(p);
        }

        for(Person p: vector_p){
            cout << p << endl;
        }

    }catch(std:: exception& e){
        std::cerr << "Exception: " << e.what() << endl;
        return 1;
    }catch(...){
        std::cerr << "Unkown error!" << endl;
        return 2;
    }
}