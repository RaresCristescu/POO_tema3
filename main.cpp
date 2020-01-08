#include <iostream>
#include<string.h>
#include<list>
#include<typeinfo>
#include<iterator>
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
    cout<<"Numele animalului: ";
    in>>v;
    a.nume=new char[strlen(v)];
    strcpy(a.nume,v);
    return in;
}
ostream &operator <<(ostream&out,animal&a)
{
    out<<"Numele animalului: "<<a.nume;
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
    cout<<"Id-ul animalului: ";
    in>>v;
    n.id=new char[strlen(v)];
    strcpy(n.id,v);
    return in;
}
ostream &operator <<(ostream&out,nevertebrate&n)
{
    out<<((animal&)n);
    out<<" Id: "<<n.id;
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
    cout<<"Id-ul animalului: ";
    in>>v;
    n.id=new char[strlen(v)];
    strcpy(n.id,v);
    return in;
}
ostream &operator <<(ostream&out,vertebrate&n)
{
    out<<((animal&)n);
    out<<" Id: "<<n.id;
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
    out<<" Numele speciei: "<<n.nume_specie;
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
    cout<<"Numele speciei: ";
    in>>v;
    n.nume_specie=new char[strlen(v)];
    strcpy(n.nume_specie,v);
    return in;
}
class pesti : public vertebrate
{
    char* nume_specie;
    float lungime;
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
    float get_l()const{return lungime;}
};
ostream &operator <<(ostream&out,pesti&n)
{
    out<<((vertebrate&)n);
    out<<" Numele speciei: ";
    out<<n.nume_specie;
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
    int cnt=0,ver=0;
    float vi=1.00;
    in>>((vertebrate&)n);
    char v[100],c[20];
    cout<<"Numele speciei: ";
    in>>v;
    n.nume_specie=new char[strlen(v)];
    strcpy(n.nume_specie,v);
    n.lungime=0;
    cout<<"Lungimea pestelui: ";
    while(cnt==0){
    in>>c;
    cnt=1;
    for(int i=0;i<strlen(c);i++)
        {
            if(c[i]=='.'){ver=1;i++;}
            if(c[i]>'9'||c[i]<'0')cnt=0;
            if(ver!=1){
            n.lungime=n.lungime*10;
            n.lungime=n.lungime+c[i]-'0';
            }
            else {vi=vi/10;
            n.lungime=n.lungime+vi*(c[i]-'0');
            }
        }
    if (cnt==0)
        {
            n.lungime=0;
            cout<<"Introduceti o lungime valida: ";
        }
    }
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
    out<<" Numele speciei: "<<n.nume_specie;
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
    cout<<"Numele speciei: ";
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
    out<<" Numele speciei: "<<n.nume_specie;
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
    cout<<"Numele speciei: ";
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
    this->v.push_back(a);
    nr++;
    }
    void afis(){cout<<"Numarul total de animale este: ";
        cout<<nr<<endl;
    typename list<T>::iterator q;
    for(q=v.begin();q!=v.end();q++)
       cout<<*q<<endl;
    }

};
template<>
class AtlasZoologic<pesti>
{
    int nr,cnt;
    list<pesti> v;
public:
    AtlasZoologic(int n=0){nr=n;cnt=n;}
    void operator +=(const pesti a){
        float r=1.000;
        if(a.get_l()>=r)cnt++;
    this->v.push_back(a);
    nr++;
    }
    void afis(){cout<<"Numarul total de pesti este: "<<nr<<endl;
    if(cnt>0)cout<<"Numarul de pesti mai mari de 1 metru este: "<<cnt<<endl;
    list<pesti>::iterator q;
    for(q=v.begin();q!=v.end();q++)
       cout<<*q<<endl;
    }
};
int main()
{
    pesti a;
    reptile b;
    mamifere c;
    pasari d;
    AtlasZoologic<pesti> a1;
    AtlasZoologic<reptile> b1;
    AtlasZoologic<mamifere> c1;
    AtlasZoologic<pasari> d1;
    cin>>a;
    a1+=a;
    cin>>a;
    a1+=a;
    cout<<endl;
    a1.afis();
    cout<<endl<<endl;
    cin>>b;
    b1+=b;
    cin>>b;
    b1+=b;
    cout<<endl;
    b1.afis();
    cout<<endl<<endl;
    cin>>c;
    c1+=c;
    cin>>c;
    c1+=c;
    cout<<endl;
    c1.afis();
    cout<<endl<<endl;
    cin>>d;
    d1+=d;
    cin>>d;
    d1+=d;
    cout<<endl;
    d1.afis();
    return 0;
}
