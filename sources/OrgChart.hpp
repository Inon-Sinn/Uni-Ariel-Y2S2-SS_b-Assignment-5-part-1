#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel
{
    
    class OrgChart{

        private:

        	struct Node {
                string name;
                Node* father;
                Node* brother;
                Node* son;
                Node(const string name, Node* dad, Node* bro, Node* boy)
                    : name(name), father(dad), brother(bro), son(boy) {
                }
            };

            Node* root;

        public:
            // Constructors
            OrgChart() : root(nullptr){}
            ~OrgChart() = default;

            OrgChart& add_root(string){return *this;}
            OrgChart& add_sub(string,string){return *this;}

            friend ostream& operator<<(ostream& out,const OrgChart){return out;}

            class iterator{
                
                private:

                    Node* cur_ptr;

                public:

                    iterator(Node* ptr = nullptr): cur_ptr(ptr){}

                    const string& operator*() const {return cur_ptr->name;}
                    const string* operator->() const {return &(cur_ptr->name);}
                    iterator& operator++() {return *this;}
                    const iterator operator++(int){ return *this;}
                    bool operator==(const iterator&) const {return true;}
                    bool operator!=(const iterator& other) const {return !(*this==other);}

            }; // class iterator

            // methods that make use of the iterator
            iterator begin(){return iterator(root);}
            iterator end(){return iterator(root);}
            iterator begin_level_order(){return iterator(root);}
            iterator end_level_order(){return iterator(root);}
            iterator begin_reverse_order(){return iterator(root);}
            iterator end_reverse_order(){return iterator(root);}
            iterator begin_preorder(){return iterator(root);}
            iterator end_preorder(){return iterator(root);}
            iterator reverse_order(){return iterator(root);}

    }; // class OrgChart

} // namespace ariel
