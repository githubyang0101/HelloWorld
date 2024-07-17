struct Node {
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void reverseList(Node* head)
{
   Node* pre=NULL;
   Node* cur=head;
   while(cur!=NULL)
   {
        Node* temp = cur->next;
        cur->next =pre;
        pre= cur;
        cur=temp;
   }
   head=pre; 
}