#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct nod {
   int info;
   struct nod *n;
   struct nod *p;
}*start, *last;
int count = 0;
class circulardoublylist {
   public:
      nod *create_node(int);
      void insert_begin();
      void insert_end();
      void insert_pos();
      void delete_pos();
      void search();
      void update();
      void display();
      circulardoublylist() {
         start = NULL;
         last = NULL;
      }
};

nod* circulardoublylist::create_node(int v) {
   count++;
   struct nod *t;
   t = new(struct nod);
   t->info = v;
   t->n = NULL;
   t->p = NULL;
   return t;
}
void circulardoublylist::insert_begin() {
   int v;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   struct nod *t;
   t = create_node(v);
   if (start == last && start == NULL) {
      cout<<"Element inserted in empty list"<<endl;
      start = last = t;
      start->n = last->n = NULL;
      start->p = last->p = NULL;
   } else {
      t->n = start;
      start->p = t;
      start = t;
      start->p = last;
      last->n = start;
      cout<<"Element inserted"<<endl;
   }
}
void circulardoublylist::insert_end() {
   int v;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   struct nod *t;
   t = create_node(v);
   if (start == last && start == NULL) {
      cout<<"Element inserted in empty list"<<endl;
      start = last = t;
      start->n= last->n = NULL;
      start->p = last->p= NULL;
   } else {
      last->n= t;
      t->p= last;
      last = t;
      start->p = last;
      last->n= start;
   }
}
void circulardoublylist::insert_pos() {
   int v, pos, i;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   cout<<endl<<"Enter the position of element inserted: ";
   cin>>pos;
   struct nod *t, *s, *ptr;
   t = create_node(v);
   if (start == last && start == NULL) {
      if (pos == 1) {
         start = last = t;
         start->n = last->n = NULL;
         start->p = last->p = NULL;
      } else {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
   } else {
      if (count < pos) {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
      s = start;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->n;
         if (i == pos - 1) {
            ptr->n = t;
            t->p= ptr;
            t->n= s;
            s->p = t;
            cout<<"Element inserted"<<endl;
            break;
         }
      }
   }
}
void circulardoublylist::delete_pos() {
   int pos, i;
   nod *ptr, *s;
   if (start == last && start == NULL) {
      cout<<"List is empty, nothing to delete"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of element to be deleted: ";
   cin>>pos;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = start;
   if(pos == 1) {
      count--;
      last->n = s->n;
      s->n->p = last;
      start = s->n;
      free(s);
      cout<<"Element Deleted"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->n;
      ptr = s->p;
   }
   ptr->n = s->n;
   s->n->p = ptr;
   if (pos == count) {
      last = ptr;
   }
   count--;
   free(s);
   cout<<"Element Deleted"<<endl;
}
void circulardoublylist::update() {
   int v, i, pos;
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to update"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of node to be updated: ";
   cin>>pos;
   cout<<"Enter the new value: ";
   cin>>v;
   struct nod *s;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = start;
   if (pos == 1) {
      s->info = v;
      cout<<"Node Updated"<<endl;
      return;
   }
   for (i=0;i < pos - 1;i++) {
      s = s->n;
   }
   s->info = v;
   cout<<"Node Updated"<<endl;
}
void circulardoublylist::search() {
   int pos = 0, v, i;
   bool flag = false;
   struct nod *s;
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to search"<<endl;
      return;
   }
   cout<<endl<<"Enter the value to be searched: ";
   cin>>v;
   s = start;
   for (i = 0;i < count;i++) {
      pos++;
      if (s->info == v) {
         cout<<"Element "<<v<<" found at position: "<<pos<<endl;
         flag = true;
      }
      s = s->n;
   }
   if (!flag)
      cout<<"Element not found in the list"<<endl;
}
void circulardoublylist::display() {
   int i;
   struct nod *s;
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to display"<<endl;
      return;
   }
   s = start;
   for (i = 0;i < count-1;i++) {
      cout<<s->info<<"<->";
      s = s->n;
   }
   cout<<s->info<<endl;
}

//main driver function
int main() {
   int c;
   circulardoublylist cdl;
   while (1) //perform switch operation 
   {
      cout<<"1.Insert at Beginning"<<endl;
      cout<<"2.Insert at End"<<endl;
      cout<<"3.Insert at Position"<<endl;
      cout<<"4.Delete at Position"<<endl;
      cout<<"5.Update Node"<<endl;
      cout<<"6.Search Element"<<endl;
      cout<<"7.Display List"<<endl;
      cout<<"8.Exit"<<endl;
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c) {
         case 1:
            cdl.insert_begin();
         break;
         case 2:
            cdl.insert_end();
         break;
         case 3:
            cdl.insert_pos();
         break;
         case 4:
            cdl.delete_pos();
         break;
         case 5:
            cdl.update();
         break;
         case 6:
            cdl.search();
         break;
         case 7:
            cdl.display();
         break;
         case 8:
            exit(1);
         break;
         default:
            cout<<"Invalid  choice"<<endl;
      }
   }
   return 0;
}
