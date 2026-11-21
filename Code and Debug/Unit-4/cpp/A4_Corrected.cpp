#include <iostream>
class WindowBox {int width=0,height=0;public:WindowBox& setWidth(int w){this->width=w;return *this;}WindowBox& setHeight(int h){this->height=h;return *this;}void display()const{std::cout<<"Window: "<<width<<" x "<<height<<'\n';}};
int main(){WindowBox box;box.setWidth(800).setHeight(600);box.display();}
