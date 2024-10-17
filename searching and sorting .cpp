//NEHMYA BIRUK(04601) AND HENOK TESFAYE(04583)

#include <iostream>

using namespace std;
struct nodeType{
	int info;
	nodeType *next;
};
nodeType *head;
//Function to create a list

void createList()
{
	nodeType *temp,*ptr;
	temp=new nodeType();
	if(temp==NULL)
	{
		cout<<"\nOut of Memory Space:\n";
	}
	cout<<"\nEnter the data value for the node:\n";
	cin>>temp->info;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}

// Function to insert an
// element at the end
void insertAtEnd(){
	nodeType *temp,*ptr;
	temp=new nodeType();
	
	if(temp==NULL){
		cout<<"\nOut of Memory Space:\n";
		return;
	}
	cout<<"\nEnter the list element:\n";
	cin>>temp->info;
	temp->next=NULL;
	
	if(head==NULL){
		head=temp;
	}
	else{
		ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
// Function to insert an element
// at head position
void insertAtBegining()
{
	nodeType *temp=new nodeType();
	cout<<"\nEnter the item:\n";
	cin>>temp->info;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else{
		temp->next=head;
		head=temp;
	}
}
// Function to insert a element
// at a specified position
void insert_pos(){
	int pos,pcount=-1;
	nodeType *temp, *ptr;
	temp=new nodeType();
	cout<<"\nEnter the position for the new node to be inserted:\n";
	cin>>pos;
	cout<<"\nEnter list element:\n";
	cin>>temp->info;
	
	if(pos==0){
		temp->next=head;
		head=temp;
	}
	else{
		ptr=head;
		while(ptr!=NULL &&pcount!=pos){
			pcount=pcount+1;
			ptr= ptr->next;
			
		}
		
		if(pos!=pcount)
			cout<<"\nPosition "<<pos<<" not found:[Handle with care]\n";
		else{
			temp->next=ptr->next;
			ptr->next=temp;
		}
		
	}
	
}
// Function to print the
// singly linked list
void printList(){
	nodeType *ptr;
	ptr=head;
	cout<<"\n\nThe list elements are:\n"<<endl;
	while(ptr!=NULL){
		cout<<ptr->info<<"\t";
		ptr=ptr->next;
	}
	cout<<endl<<endl<<endl;
}
// Function to print the
// singly linked list
void display()
{
	nodeType *ptr;
	if(head==NULL)
	{
		cout<<"\nList is empty:\n";
		return;
	}
	else
	{
		ptr=head;
		cout<<"\nThe List elements are:\n";
		while(ptr!=NULL)
		{
			cout<<ptr->info<<" ";
			ptr=ptr->next ;
		}
	}
}

// Function to insert at specified position

void insert_pos1(){
	nodeType *ptr,*temp;
	int i,pos;
	temp=new nodeType();
	if(temp==NULL){
		cout<<"\nOut of Memory Space:\n";
		return;
	}
	cout<<"\nEnter the position for the new node to be inserted:\n";
	cin>>pos;
	cout<<"\nEnter the data value of the node:\n";
	cin>>temp->info;
	temp->next=NULL;
	if(pos==0){
		temp->next=head;
		head=temp;
	}
	else{
		for(i=0,ptr=head;i<pos-1;i++) {
			ptr=ptr->next;
			if(ptr==NULL){
				cout<<"\nPosition not found:[Handle with care]\n";
				return;
			}
		}
		temp->next =ptr->next ;
		ptr->next=temp;
	}
}
// Function to delete the head element
// of the list
void delete_begin(){
	nodeType *temp;
	temp=head;
	if(temp==NULL)
		cout<<"The list is empty\n.";
	else{
		head=head->next;
		cout<<"\nThe deleted element is :"<<temp->info;
		delete[] temp;
	}
}
// Function to delete
//the tail of the list
void delete_End(){
	nodeType *ptr,*temp;
	if(head==NULL){
		cout<<"nList is Empty:";
	}
	else if(head->next==NULL){
		ptr=head;
		head=NULL;
		cout<<"\nThe deleted element is:t"<<ptr->info;
		delete[] ptr;
	}
	else{
		ptr=head;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		cout<<"\nThe deleted element is:"<<ptr->info;
		delete[] ptr;
	}
	
}
// Function to delete element
//at specified position
void delete_pos(){
	nodeType *ptr,*temp;
	int i,pos;
	if(head==NULL){
		cout<<"\nOut of Memory Space:\n";
		return;
	}
	cout<<"\nEnter the position for the new node to be inserted:\n";
	cin>>pos;
	if(pos==0){
		ptr=head;
		head=head->next;
		cout<<"\nThe deleted element is:"<<ptr->info;
		delete []ptr;
	}
	else{
		for(i=0,ptr=head;i<pos;i++) {
			temp=ptr;
			ptr=ptr->next;
			if(ptr==NULL){
				cout<<"\nPosition not found:[Handle with care]\n";
				return;
			}
		}
		temp->next=ptr->next ;
		cout<<"\nThe deleted element is:"<<ptr->info;
		delete [] ptr;
	}
}
// Function to search for a node
void   Searching() {
	int value;
	cout << "Enter the value to search for: ";
	cin >> value;
	nodeType *ptr = head;
	int pos = 0;
	bool found = false;
	while (ptr != NULL) {
		if (ptr->info == value) {
			found = true;
			cout << "Value found at position " << pos << endl;
		}
		ptr = ptr->next;
		pos++;
	}
	if (!found) {
		cout << "Value not found in the list" << endl;
	}
}
// Function to update a node
void Updated() {
	int oldValue, newValue;
	cout << "Enter the value of the node to update: ";
	cin >> oldValue;
	cout << "Enter the new value: ";
	cin >> newValue;
	nodeType *ptr = head;
	bool found = false;
	while (ptr != NULL) {
		if (ptr->info == oldValue) {
			found = true;
			ptr->info = newValue;
			cout << "Node updated successfully" << endl;
			break;
		}
		ptr = ptr->next;
	}
	if (!found) {
		cout << "Node with the given value not found" << endl;
	}
}
// Function to count the length of the list
void length() {
	int count = 0;
	nodeType *ptr = head;
	while (ptr != NULL) {
		count++;
		ptr = ptr->next;
	}
	cout << "The length of the list is: " << count << endl;
}
// Function to reverse the linked list
void  revers() {
	nodeType *prev = NULL, *current = head, *next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	cout << "List reversed successfully" << endl;
}
// Function to sort the linked list in ascending order
void sortList_node() {
	nodeType *ptr1, *ptr2;
	int temp;
	ptr1 = head;
	while (ptr1 != NULL) {
		ptr2 = ptr1->next;
		while (ptr2 != NULL) {
			if (ptr1->info > ptr2->info) {
				temp = ptr1->info;
				ptr1->info = ptr2->info;
				ptr2->info = temp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	cout << "List sorted successfully" << endl;
}
nodeType *head2 = nullptr; // Initialize head2 as nullptr
// Function to concatenate two lists
void concatenatetwoLists() {
	nodeType *ptr1 = head, *ptr2 = head2;
	while (ptr1->next != NULL) {
		ptr1 = ptr1->next;
	}
	ptr1->next = head2;
	while (ptr2 != NULL) {
		ptr2 = ptr2->next;
	}
	head = ptr1;
	cout << "Lists concatenated successfully" << endl;
}
// Function to merge two sorted lists into a third sorted list
void mergeSorted() {
	nodeType *ptr1 = head, *ptr2 = head2, *ptr3 = head;
	while (ptr1 != NULL && ptr2 != NULL) {
		if (ptr1->info <= ptr2->info) {
			ptr3->info = ptr1->info;
			ptr1 = ptr1->next;
		} else {
			ptr3->info = ptr2->info;
			ptr2 = ptr2->next;
		}
		ptr3 = ptr3->next;
	}
	while (ptr1 != NULL) {
		ptr3->info = ptr1->info;
		ptr1 = ptr1->next;
		ptr3 = ptr3->next;
	}
	while (ptr2 != NULL) {
		ptr3->info = ptr2->info;
		ptr2 = ptr2->next;
		ptr3 = ptr3->next;
	}
	cout << "Merged lists successfully" << endl;
}
int main()
{
	
	int choice;
	while(1){
		cout<<"\n               MENU          \n";
		cout<<"\n 1.Create     \n";
		cout<<"\n 2.Display    \n";
		cout<<"\n 3.Insert at the beginning    \n";
		cout<<"\n 4.Insert at the end  \n";
		cout<<"\n 5.Insert at specified position       \n";
		cout<<"\n 6.Delete from beginning      \n";
		cout<<"\n 7.Delete from the end        \n";
		cout<<"\n 8.Delete from specified position     \n";
		cout<<"\n 9. Searching a node\n";
		cout<<"\n 10. Updating a node\n";
		cout<<"\n 11. Counting the length of the list\n";
		cout<<"\n 12. Reversing the list\n";
		cout<<"\n 13. Sorting the list using pointer manipulation\n";
		cout<<"\n 14. Concatenating two lists\n";
		cout<<"\n 15. Merging two sorted lists into a third sorted list\n";
		cout<<"\n 16.Exit       \n";
		cout<<"\n--------------------------------------\n";
		cout<<"\nEnter your choice:\t";
		cin>>choice;
		switch(choice)
		{
		case 1:
			createList();
			break;
		case 2:
			//display();
			printList();
			break;
		case 3:
			insertAtBegining();
			break;
		case 4:
			insertAtEnd();
			break;
		case 5:
			insert_pos1();
			break;
		case 6:
			delete_begin();
			break;
		case 7:
			delete_End();
			break;
		case 8:
			delete_pos();
			break;
			
			case 9://Searching a node using linear search algorithem
			Searching();
			break;
		case 10:
			Updated();//Updating a node
			break;
		case 11:
			length();//Counting the length of the list
			break;
		case 12:
			revers();//Reversing the list
			break;
			case 13: // Sorting the list using pointer manipulation and bubble sort
			sortList_node();
			break;
			case 14: // Concatenating two lists
			concatenatetwoLists();
			break;
			
			case 15: // Merging two sorted lists into a third sorted list
			mergeSorted();
			break;
		case 16:
			exit(0);
			break;
			default:
				cout<<"\n Wrong Choice:\n";
				break;
		}
	}
	return 0;
}
