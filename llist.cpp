#include "llist.h"
#include "node.h"
#include "node.cpp"

namespace nodespace{
	
	void LList::append(const node::value_type& entry){
            node* temp = new node(entry, NULL);
            tail_ptr->set_link(temp);
            tail_ptr = temp;
	}
	
	void LList::insert(std::size_t position, const node::value_type& entry){
        node* cursor = head_ptr;
        std::size_t i = 0;
        
        while(i < position)
        {
            i++;
            cursor = cursor->link();
        }
        
        node::list_insert(cursor, entry);
	}  

	//find first occurrence
	const node* LList::search(const node::value_type& target){
        node* cursor = head_ptr;
        
        while(cursor != NULL)
        {
           if(cursor->data() == target)
           {
               return cursor;
           }
            
           cursor = cursor->link();
        }
        
        return NULL;
	}
	
	const node* LList::locate(std::size_t position){
        assert ( position > 0 && position <= list_length);
        
        node* cursor = head_ptr;
        std::size_t i = 1;
        
        while(cursor != NULL)
        {
            if(i == position)
            {
                return cursor;
            }
            
            i++;
            cursor = cursor->link();
        }
        
        return NULL;
	};

	//remove by value, remove all
	bool LList::remove(const node::value_type& target){
        node* remove = head_ptr;
        node* prev_ptr = head_ptr;
        
        while(remove != NULL)
        {
            if(remove->link()->data == target)
            {
                prev_ptr = remove;
                
                remove = remove->link();
                
                prev_ptr->set_link(remove->link());
                
                delete remove;
                
                return true;
            }
            remove = remove->link();
        }
        
        return false;
	}

	void LList::clear(){
          node* temp = head_ptr;
        
        while(head->ptr != NULL)
        {
            head_ptr = head_ptr->link();
            delete temp;
            temp = head_ptr;
        }
        
        head_ptr = NULL;
        tail_ptr = NULL;
        list_length = 0;
	};

	//returns new list
	LList* LList::copy(){

	};

	//additional functions to index into list
	node* LList::operator[] (size_t ind){

	};

	std::list<std::tuple<node::value_type, int>> frequency(LList data);
}
