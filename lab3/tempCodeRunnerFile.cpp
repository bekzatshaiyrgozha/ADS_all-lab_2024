void deletevalue(int value){
        if(head == nullptr){
            cout<<"errror:";
            return;
        }
        if(head->data ==value){
            node* temp = head;
            head = head->next;
            delete temp ;
            return;

        }
        node* current = head;
        while(current->next != nullptr && current->next->data==value){
            current = current->next;
        }
        if(current == nullptr){
            cout<<"not";
            return;
        }
        node* temp = current->next;
        current->next= temp->next;
        delete temp;



    }