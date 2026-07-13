#include <stdio.h> 
#include <stdlib.h> 
struct node { 
 int data; 
 struct node *next; 
} *head = NULL; 
// Insert at beginning 
void add(int num) { 
 struct node *temp = (struct node *)malloc(sizeof(struct node)); 
 temp->data = num; 
 temp->next = head; 
 head = temp; 
} 
// Insert at end 
void append(int num) { 
 struct node *temp = (struct node *)malloc(sizeof(struct node)); 
 temp->data = num; 
 temp->next = NULL; 
 if (head == NULL)
{ 
 head = temp; 
 } else 
{ 
 struct node *right = head; 
 while (right->next != NULL)
right = right->next; 
 right->next = temp; 
 } 
} 
// Delete a node 
int delete(int num) { 
 struct node *temp = head, *prev = NULL; 
 while (temp != NULL) { 
 if (temp->data == num) { 
 if (temp == head) { 
 head = temp->next; 
 } else { 
 prev->next = temp->next; 
 } 
 free(temp); 
 return 1; 
 } 
 prev = temp; 
 temp = temp->next; 
 } 
 return 0; 
} 
// Display list 
void display() { 
 struct node *r = head; 
 if (r == NULL) { 
 prinƞ("List is Empty\n"); 
 return; 
 } 
 prinƞ("Element(s) in the list are: ");
 while (r != NULL) { 
 prinƞ("%d ", r->data); 
 r = r->next; 
 } 
 prinƞ("\n"); 
} 
// Count nodes 
int count() { 
 struct node *n = head; 
 int c = 0; 
 while (n != NULL) { 
 n = n->next; 
 c++; 
 } 
 return c; 
} 
// Main funcƟon
int main() { 
 int choice, num; 
 while (1) { 
  prinƞ("\nList OperaƟons\n"); 
 prinƞ("===============\n"); 
 prinƞ("1. Insert\n"); 
 prinƞ("2. Display\n"); 
 prinƞ("3. Size\n"); 
 prinƞ("4. Delete\n"); 
 prinƞ("5. Exit\n"); 
 prinƞ("Enter your choice: ");
 
 if (scanf("%d", &choice) <= 0) { 
 prinƞ("Enter only an Integer\n"); 
 exit(0); 
 } 
 
 switch (choice) { 
 case 1: 
 prinƞ("Enter the number to insert: ");
 scanf("%d", &num); 
 append(num); 
 break; 
 case 2: 
 display(); 
 break; 
 case 3: 
 prinƞ("Size of the list is %d\n", count()); 
 break; 
 case 4:
 if (head == NULL) { 
 prinƞ("List is Empty\n"); 
 } else { 
 prinƞ("Enter the number to delete: ");
 scanf("%d", &num); 
 if (delete(num)) 
 prinƞ("%d deleted successfully\n", num); 
 else 
 prinƞ("%d not found in the list\n", num); 
 } 
 break; 
 case 5: 
 return 0; 
 default: 
 prinƞ("Invalid opƟon\n"); 
 } 
 } 
 return 0; 
}
