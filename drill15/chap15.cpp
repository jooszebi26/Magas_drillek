//g++ -w chap15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp `fltk-config --config --ldflags --use-images` -o chap15


#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <iostream>

double one (double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return cos(x) + slope(x);}

int main(){
    try{
        Simple_window win {Point{100,100}, 600, 600};

        
        Axis x {Axis::x, Point{100,300},400,20,"1==20 pixels"};
        Axis y {Axis::x, Point{100,500},400,20,"1==20 pixels"};
        x.set_color(Color::red);
        y.set_color(Color::red);

        win.attach(x);
        win.attach(y);

        constexpr int r_min = -10;
        constexpr int r_max = 11;
        constexpr int num_points = 400;
        constexpr int x_scale = 20;
        constexpr int y_scale = 20;
        const Point orig {300,300};

        Function f1 {one, r_min, r_max, orig, num_points, x_scale, y_scale};
        Function f1 {slope, r_min, r_max, orig, num_points, x_scale, y_scale};
        Function f3 {[](double x){return cos(x) + slope(x);}, r_min, r_max, orig, num_points, x_scale, y_scale};
        
        win.attach(f1);
        win.attach(f2);
        win.attach(f3);
        win.attach(f4);
        win.attach(f5);

        win.wait_for_button();

    }catch(exception& e){
        cerr << "Exception"<< e.what()<< endl;
        return 1;
    }
    catch(...){
        cerr << "Unknown error!" << endl;
        return 2;
    }
}