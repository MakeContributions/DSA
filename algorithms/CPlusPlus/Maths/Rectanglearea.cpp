#include <iostream>
class Rectangle{
  public:
  int width; 
  int height;
  void display(){
      cout<<width<<" "<<height<<endl;
  }
    
};
class RectangleArea:public Rectangle{
    public:
    void read_input(){
      cin>>width;
      cin>>height;
    }
    void display(){
        cout<<width*height<<endl;
    }
};

int main()
{
   
    RectangleArea r_area;
    r_area.read_input();
    r_area.Rectangle::display();
    r_area.display();
    
    return 0;
}
