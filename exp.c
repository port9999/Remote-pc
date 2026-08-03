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
<_________________________________________>
#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
int e;
Position previous;
Position next;
};
void Insert(int x, List l, Position p)
{
Position TmpCell;
TmpCell = (struct Node *) malloc(sizeof(struct Node));
if (TmpCell == NULL)
printf("Memory out of space\n");
else
{
TmpCell->e = x;
TmpCell->previous = p;
TmpCell->next = p->next;
if (p->next != NULL)
p->next->previous = TmpCell;
p->next = TmpCell;
}
}
int isLast(Position p)
{
return (p->next == NULL);
}
Position Find(int x, List l)
{
Position p = l->next;
while (p != NULL && p->e != x)
p = p->next;
return p;
}
void Delete(int x, List l)
{
Position p, p1, p2;
p = Find(x, l);
if (p != NULL)
{
p1 = p->previous;
p2 = p->next;
p1->next = p->next;
if (p2 != NULL) /* if the node is not the last
node */
p2->previous = p->previous;
free(p);
}
else
printf("Element does not exist!!!\n");
}
void Display(List l)
{
Position p = l->next;
printf("The list elements are :: ");
while (p != NULL)
{
printf("%d -> ", p->e);
p = p->next;
}
printf("\n");
}
int main()
{
int x, pos, ch, i;
List l;
List p;
l = (struct Node *) malloc(sizeof(struct Node));
l->previous = NULL;
l->next = NULL;
printf("DOUBLY LINKED LIST IMPLEMENTATION OF LIST ADT\n\n");
do
{
printf("\n\n1. INSERT\t 2. DELETE\t 3. FIND\t 4. PRINT\t 5.
QUIT\n\n");
printf("Enter the choice :: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
p = l;
printf("Enter the element to be inserted :: ");
scanf("%d", &x);
printf("Enter the position of the element :: ");
scanf("%d", &pos);
for (i = 1; i < pos; i++)
p = p->next;
Insert(x, l, p);
break;
case 2:
printf("Enter the element to be deleted :: ");
scanf("%d", &x);
Delete(x, l);
break;
case 3:
printf("Enter the element to be searched :: ");
scanf("%d", &x);
p = Find(x, l);
if (p == NULL)
printf("Element does not exist!!!\n");
else
printf("Element exists!!!\n");
break;
case 4:
Display(l);
break;
default:
break;
}
} while (ch < 5);
return 0;
}
_______________________________________________
#include<stdio.h>
#include<conio.h>
#define max 5
static int stack[max];
int top = -1;
void push(int x)
{
 stack[++top] = x;
}
int pop()
{
 return (stack[top--]);
}
void view()
{
 int i;
 if (top < 0)
 printf("\n Stack Empty \n");
 else
 {
 printf("\n Top-->");
 for (i = top; i >= 0; i--)
 {
 printf("%4d", stack[i]);
 }
 printf("\n");
 }
}
void main()
{
 int ch = 0, val;
 clrscr();
 while (ch != 4)
 {
 printf("\n STACK OPERATION \n");
 printf("1.PUSH ");
 printf("2.POP");
 printf("3.VIEW ");
 printf("4.QUIT \n");
 printf("Enter Choice : ");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
 if (top < max - 1)
 {
 printf("\nEnter Stack element : ");
 scanf("%d", &val);
 push(val);
 }
 else
 printf("\n Stack Overflow \n");
 break;
 case 2:
 if (top < 0)
 printf("\n Stack Underflow \n");
 else
 {
 val = pop();
 printf("\n Popped element is %d\n", val);
 }
 break;
 case 3:
 view();
 break;
 case 4:
 exit(0);
 default:
 printf("\n Invalid Choice \n");
 }
 }
}
