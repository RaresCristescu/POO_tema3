#include <iostream>
#include<string.h>
#include<list>
#include<typeinfo>
using namespace std;
class nevertebrate;
class animal
{
    char * nume;
public:
    virtual void afis(){for(unsigned int i=0;i<strlen(nume);i++)cout<<nume[i];cout<<endl;}
    animal(){nume=NULL;}
    animal(char*n){nume=n;}
    animal(const animal &a){nume=a.nume;}
    ~animal(){delete[]nume;}
    friend istream &operator >>(istream&,animal&);
    friend ostream &operator <<(ostream&,animal&);
    friend istream &operator >>(istream&,nevertebrate&);
    friend ostream &operator <<(ostream&,nevertebrate&);
    animal &operator =(const animal&);
    //int &operator[](int);
};
animal &animal::operator=(const animal& a)
{
    nume=new char[strlen(a.nume)];
    strcpy(nume,a.nume);
    return *this;
}
istream &operator >>(istream&in,animal&a)
{
    char v[100];
    in>>v;
    a.nume=new char[strlen(v)];
    strcpy(a.nume,v);
    return in;
}
ostream &operator <<(ostream&out,animal&a)
{
    out<<a.nume;
    return out;
}
class nevertebrate:public animal
{
    char *id;
public:
    nevertebrate():animal(){id=NULL;}
    nevertebrate(char*n):animal(){id=n;}
    nevertebrate(const nevertebrate &n):animal(n)
    {
        id=n.id;
    }
    ~nevertebrate(){delete[]id;}
    void afis(){cout<<((animal&)*this);cout<<" ";cout<<id;}
    friend istream &operator >>(istream&,nevertebrate&);
    friend ostream &operator <<(ostream&,nevertebrate&);
    nevertebrate &operator =(const nevertebrate&);
};
istream &operator >>(istream&in,nevertebrate&n)
{
    in>>((animal&)n);
    char v[100];
    in>>v;
    n.id=new char[strlen(v)];
    strcpy(n.id,v);
    return in;
}
ostream &operator <<(ostream&out,nevertebrate&n)
{
    out<<((animal&)n);
    out<<" "<<n.id;
    return out;
}
nevertebrate &nevertebrate::operator=(const nevertebrate&n)
{
    id=n.id;
    animal::operator=(n);
    return *this;
}
class vertebrate: public animal
{
    char *id;
public:
    vertebrate():animal(){id=NULL;}
    vertebrate(char*n):animal(){id=n;}
    vertebrate(const vertebrate &n):animal(n)
    {
        id=n.id;
    }
    ~vertebrate(){delete[]id;}
    void afis(){cout<<((animal&)*this);cout<<" ";cout<<id;}
    friend istream &operator >>(istream&,vertebrate&);
    friend ostream &operator <<(ostream&,vertebrate&);
    vertebrate &operator =(const vertebrate&);
};
istream &operator >>(istream&in,vertebrate&n)
{
    in>>((animal&)n);
    char v[100];
    in>>v;
    n.id=new char[strlen(v)];
    strcpy(n.id,v);
    return in;
}
ostream &operator <<(ostream&out,vertebrate&n)
{
    out<<((animal&)n);
    out<<" "<<n.id;
    return out;
}
vertebrate &vertebrate::operator=(const vertebrate&n)
{
    id=n.id;
    animal::operator=(n);
    return *this;
}
class pasari : public vertebrate
{
    char* nume_specie;
public:
    pasari():vertebrate(){nume_specie=NULL;}
    pasari(char *n):vertebrate(){nume_specie=n;}
    pasari(const pasari &p):vertebrate(p)
    {
        nume_specie=p.nume_specie;
    }
    ~pasari(){delete []nume_specie;}
    friend istream &operator >>(istream&,pasari&);
    friend ostream &operator <<(ostream&,pasari&);
    pasari &operator =(const pasari&);
};
ostream &operator <<(ostream&out,pasari&n)
{
    out<<((vertebrate&)n);
    out<<" "<<n.nume_specie;
    return out;
}
pasari &pasari::operator=(const pasari&n)
{
    nume_specie=n.nume_specie;
    vertebrate::operator=(n);
    return *this;
}
istream &operator >>(istream&in,pasari&n)
{
    in>>((vertebrate&)n);
    char v[100];
    in>>v;
    n.nume_specie=new char[strlen(v)];
    strcpy(n.nume_specie,v);
    return in;
}
class pesti : public vertebrate
{
    char* nume_specie;
    int lungime;
public:
    pesti():vertebrate(){nume_specie=NULL;lungime=0;}
    pesti(char *n):vertebrate(){nume_specie=n;}
    pesti(const pesti &p):vertebrate(p)
    {
        nume_specie=p.nume_specie;
        lungime=p.lungime;
    }
    ~pesti(){delete []nume_specie;}
    friend istream &operator >>(istream&,pesti&);
    friend ostream &operator <<(ostream&,pesti&);
    pesti &operator =(const pesti&);
};
ostream &operator <<(ostream&out,pesti&n)
{
    out<<((vertebrate&)n);
    out<<" "<<n.nume_specie;
    out<<" Lungimea pestelui este:";
    out<<n.lungime;
    return out;
}
pesti &pesti::operator=(const pesti&n)
{
    lungime=n.lungime;
    nume_specie=n.nume_specie;
    vertebrate::operator=(n);
    return *this;
}
istream &operator >>(istream&in,pesti&n)
{
    in>>((vertebrate&)n);
    char v[100];
    in>>v;
    n.nume_specie=new char[strlen(v)];
    strcpy(n.nume_specie,v);
    in>>n.lungime;
    return in;
}
class mamifere : public vertebrate
{
    char* nume_specie;
public:
    mamifere():vertebrate(){nume_specie=NULL;}
    mamifere(char *n):vertebrate(){nume_specie=n;}
    mamifere(const mamifere &p):vertebrate(p)
    {
        nume_specie=p.nume_specie;
    }
    ~mamifere(){delete []nume_specie;}
    friend istream &operator >>(istream&,mamifere&);
    friend ostream &operator <<(ostream&,mamifere&);
    mamifere &operator =(const mamifere&);
};
ostream &operator <<(ostream&out,mamifere&n)
{
    out<<((vertebrate&)n);
    out<<" "<<n.nume_specie;
    return out;
}
mamifere &mamifere::operator=(const mamifere&n)
{
    nume_specie=n.nume_specie;
    vertebrate::operator=(n);
    return *this;
}
istream &operator >>(istream&in,mamifere&n)
{
    in>>((vertebrate&)n);
    char v[100];
    in>>v;
    n.nume_specie=new char[strlen(v)];
    strcpy(n.nume_specie,v);
    return in;
}
class reptile : public vertebrate
{
    char* nume_specie;
public:
    reptile():vertebrate(){nume_specie=NULL;}
    reptile(char *n):vertebrate(){nume_specie=n;}
    reptile(const reptile &p):vertebrate(p)
    {
        nume_specie=p.nume_specie;
    }
    ~reptile(){delete []nume_specie;}
    friend istream &operator >>(istream&,reptile&);
    friend ostream &operator <<(ostream&,reptile&);
    reptile &operator =(const reptile&);
};
ostream &operator <<(ostream&out,reptile&n)
{
    out<<((vertebrate&)n);
    out<<" "<<n.nume_specie;
    return out;
}
reptile &reptile::operator=(const reptile&n)
{
    nume_specie=n.nume_specie;
    vertebrate::operator=(n);
    return *this;
}
istream &operator >>(istream&in,reptile&n)
{
    in>>((vertebrate&)n);
    char v[100];
    in>>v;
    n.nume_specie=new char[strlen(v)];
    strcpy(n.nume_specie,v);
    return in;
}
template <class T>
class AtlasZoologic
{
    int nr;
    list<T> v;
public:
    AtlasZoologic(int n=0){nr=n;}
    void operator +=(const T a){
     //int cnt=0;
    //list<T>::iterator p;
    this->v.push_back(a);
    nr++;
    }
    void afis(ostream &out){out<<nr<<endl;
    for(int i=0;i<nr;i++)
       out<<v[i]<<" ";
    }

};
//template<class T>
//void AtlasZoologic<T>::afis(){
//list<T> p;
//}
template<>
class AtlasZoologic<pesti>{

};
int main()
{
    animal a;
    cin>>a;
    //a=new nevertebrate;
    AtlasZoologic<animal> b;
    b+=a;
    b.afis(cout);
//    a.afis();
    //cout<<n;
   // m=n;
   // m.afis();
    return 0;
}
