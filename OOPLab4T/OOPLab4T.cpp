#include <iostream>
#include <string>
#include <map>
using namespace std;
class Entity {
private:
    string last_name;
    string first_name;
    string middle_name;
public:
    Entity() = default;
    Entity(string last_name, string first_name, string middle_name){
      this->first_name=first_name;
      this->middle_name=middle_name;
      this->last_name=last_name;
    }
    string get_last_name() const {
        return last_name;
    }

    string get_first_name() const {
        return first_name;
    }

    string get_middle_name() const {
        return middle_name;
    }

    void set_last_name(std::string last_name) {
        this->last_name = last_name;
    }

    void set_first_name(std::string first_name) {
        this->first_name = first_name;
    }

    void set_middle_name(std::string middle_name) {
        this->middle_name = middle_name;
    }
};

class Association {
private:
    map<pair<int, std::string>, Entity> data;
public:
   void operator()(int group_number, string surname, string name, string middle_name){
         Entity entity(surname, name, middle_name);
         data[make_pair(group_number, surname)] = entity;
   }
    Entity& operator[](pair<int, string> key) {
        if (data.find(key) != data.end()) {
            return data[key];
        }
    }

    friend ostream& operator<<(ostream& os, const Association& association) {
        for (auto& entity_pair : association.data) {
            os << "Group number: " << entity_pair.first.first << endl;
            os << "Surname: " << entity_pair.first.second << endl;
            os << "First name: " << entity_pair.second.get_first_name() << endl;
            os << "Middle name: " << entity_pair.second.get_middle_name() << endl;
            os << endl;
        }
        return os;
    }

   //  friend istream& operator>>(istream& is, Association& association) {
   //      int group_number;
   //      string surname, name, middle_name;
   //      while (is >> group_number >> surname >> name >> middle_name) {
   //          association(group_number, surname, name, middle_name);
   //      }
   //      return is;
   //  }
};

void Exercise2() {
    Association association;
    association(1, "Svereda", "Yuriy", "Genadiovich");
    association(2, "Ledinskyi", "Artem", "Oleksandrovich");
    association(3, "Krutov", "Glib", "Maksimovich");
    cout << association << endl;
}
#include<iostream>
#include<cmath>
#include <string>
using namespace std;
class Vector3D{
private:
double x,y,z;
int state;
int count;
public:
Vector3D(double xVal,double yVal,double zVal):state(0){
this->x=xVal;
this->y=yVal;
this->z=zVal;
}
Vector3D():state(0){
    x=0.0;
    y=0.0;
    z=0.0;
    count++;
}
Vector3D(double Val):state(0){
    x=Val;
    y=Val;
    z=Val;
    count++;
}
Vector3D(double *Val):state(0){
if(Val!=nullptr){
x=Val[0];
y=Val[1];
z=Val[2];
count++;
}else{
    state=1;
    cout<<"Value = nullptr!";
    count++;
}
}
~Vector3D(){
    cout<<endl;
    cout<<"Вектор деструктований, змінна станну : "<<state<<endl;
    count--;
}
Vector3D& operator++(){
x+=1;
y+=1;
z+=1;
return *this;
}
Vector3D& operator++(int a){
Vector3D T=*this;
x+=1;
y+=1;
z+=1;
return T;
}
Vector3D& operator--(){
    x-=1;
    y-=1;
    z-=1;
    return *this;
}
Vector3D& operator--(int a){
 Vector3D T=*this;
    x-=1;
    y-=1;
    z-=1;
 return T;
}
bool operator!(){
    if(x==0 && y==0 && z==0){
        return false;
    }else{
        return true;
    }   
}
Vector3D operator-(){
    return Vector3D(-x,-y,-z);
}
Vector3D& operator=(const Vector3D other){
    x=other.x;
    y=other.y;
    z=other.z;
    return *this;
}
Vector3D& operator+=(const Vector3D other){
     x+=other.x;
    y+=other.y;
    z+=other.z;
    return *this;
}
Vector3D& operator-=(const Vector3D other){
     x-=other.x;
    y-=other.y;
    z-=other.z;
    return *this;
}
Vector3D& operator*=(const Vector3D other){
     x*=other.x;
    y*=other.y;
    z*=other.z;
    return *this;
}
Vector3D& operator/=(int Num){
     if(Num==0){
        cout<<"Ділення на нуль"<<endl;
        state=-2;
     }
     x/=Num;
     y/=Num;
     z/=Num;
     return *this;
}

Vector3D operator+(Vector3D& C){
       x=x+C.x;
       y=y+C.y;
       z=z+C.z;  
       return *this;             
}
Vector3D operator-(Vector3D& C){
       x=x-C.x;
       y=y-C.y;
       z=z-C.z;   
       return *this;            
}
Vector3D operator*(Vector3D& C){
       x=x*C.x;
       y=y*C.y;
       z=z*C.z;   
       return *this;            
}
Vector3D& operator/(int Num){
     if(Num==0){
        cout<<"Ділення на нуль"<<endl;
        state=-3;
     }
     x=x/Num;
     y=y/Num;
     z=z/Num;
     return *this;
}

friend std::ostream& operator<<(std::ostream& os , Vector3D& C ){
      os<<C.x<<" \t";
      os<<C.y<<" \t";
      os<<C.z<<" \t";
      return os;
}
friend std::istream& operator>>(std:: istream& is ,Vector3D& A){
      is >>A.x;
      is >>A.y;
      is >>A.z;
      return is;
}
bool operator>(const Vector3D& A) {
  return(x>A.x && y>A.y && z>A.z);
}
bool operator<(const Vector3D& A) {
  return(x<A.x && y<A.y && z<A.z);
}
bool operator<=(const Vector3D& A) {
  return(x<=A.x && y<=A.y && z<=A.z);
}
bool operator>=(const Vector3D& A) {
  return(x>=A.x && y>=A.y && z>=A.z);
}
bool operator==(const Vector3D other){
   return(x==other.x &&y==other.y &&z==other.z);
}
bool operator!=(const Vector3D other){
   return(x!=other.x &&y!=other.y &&z!=other.z);
}
};

void Exercise1(){
    double Arr[3]={1,2,3};
    Vector3D A;
    cin>>A;
    cout<<"A :";
    cout<<A;
    Vector3D B(2,4,8);
    cout<<endl;
    cout<<"B :";
    cout<<B;
    Vector3D C(Arr); 
    cout<<endl;
    cin>>C;
    cout<<"C :";
    cout<<C<<endl;
    cout<<"A*B";
    A=A*B;
    cout<<A<<endl;
    cout<<"A++";
    A++;
    cout<<A<<endl;
     cout<<"A--";
    A--;
    cout<<A<<endl;
    cout<<"A+=B"<<endl;
    A+=B;
    cout<<A<<endl;
    cout<<"A*=B"<<endl;
    A*=B;
    cout<<A<<endl;
    cout<<"A/2"<<endl;
    A=A/2;
    cout<<A<<endl;
    cout<<"A=-A"<<endl;
    A=-A;
    cout<<A<<endl;
    Vector3D AYE=++C;
    cout<<"++C"<<endl;
   cout<<AYE<<endl;
   cout<<"--C"<<endl;
   AYE=--C;
   cout<<AYE<<endl;
   cout<<"A > C :";
   bool L=A>C;
   cout<<L<<endl;
   bool I=A>C;
   cout<<"A < C :";
   cout<<I<<endl;
   bool D=A<=C;
   cout<<"A<=C :";
   cout<<D<<endl;
   bool O=A>=C;
   cout<<"A>=C :";
   cout<<O<<endl;
   bool N=A==C;
   cout<<"A==C :";
   cout<<N<<endl;
   bool H=A!=C;
   cout<<"A!=C :";
   cout<<H;
}
int main(){
   int a;
   cout<<"Choose 1 or 2 :"<<endl;
   cin>>a;
   if(a==2){
   Exercise2();
   }
   if(a==1){
    Exercise1();
   }
   return 0;
}
