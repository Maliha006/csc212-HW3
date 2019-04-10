#include "llist.h"
#include "node.h"
#include "node.cpp"

namespace nodespace{
	
	void LList::append(const node::value_type& entry){
            node* temp = new node(entry, NULL);
		if(head_ptr == NULL)
		{
			head_ptr = temp;
			tail_ptr = temp;
			return;
		}
		
            tail_ptr->set_link(temp);
            tail_ptr = temp;
	}
	
	void LList::insert(std::size_t position, const node::value_type& entry){
        
		if(position < 0 || position > list_length)
		{
			throw std::out_of_range("Out of Range");
		}
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
	}

	//returns new list
	LList* LList::copy(){
	
	LList* new_list = new LList();
	new_list->append(head_ptr->data);
		
	node* cursor = head_ptr->link();
		
	while(cursor != NULL)
	{
		LList->append(cursor->data);
		cursor = cursor->link();
	}
	return new_list;
	}

	//additional functions to index into list
	node* LList::operator[] (size_t ind){
	node* temp = head_ptr;
	size_t i = 1;
		
	while(i != ind)
	{
		temp = temp->link();
		i++;
	}
	return temp;
	}

	std::list<std::tuple<node::value_type, int>> frequency(LList data){
		std::tuple<node::value_type, int> cnt_node;
		std::vector<node::value_type>used;
		std::list<std::tuple<node::value_type, int>> list_mode;
		
		node* cursor = data->head_ptr();
		
		while(cursor!= NULL)
		{
			int t = 1;
			
			node* cursor2 = cursor;
		        node::value_type v = cursor->data();
			
			while(cursor2 != NULL)
			{
				if(cursor2->data() == v)
				{
					t++;
				}
				cursor2 = cursor2->link();
			}
			bool not_found = true;
			
			for(int i = 0; i<v.size(); i++)
			{
				if(v[i] == cursor->data())
					not_found = false;
			}
			
			if(not_found)
			{
				cnt_node = make_tuple(cursor->data(), t);
				list_mode.push_back(cnt_node);
			}
			
			cursor = cursor->link();
		}
	}
	
	return list_mode;
}
