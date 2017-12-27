//
//  main.cpp
//  ClassEx
//
//  Created by Angalo Kurian Maliyil on 10/27/17.
//  Copyright © 2017 Angelo. All rights reserved.
//

#include <iostream>
#include "starterClass.h"
#include "string.h"

using namespace std;

enum programid
{
    classEx1,
    string1,
    referenceEx1,
    ipbufferEx1,
    rawStringLitEx1,
    sizeofarrEx1,
    runTimePolyEx1,
    cpConstructEx1,
};

void classex1()
{
    Starter acc = Starter((uint8_t)20);
    printf("Acc main %u",acc.getAcc());
    uint8_t acc_val = acc.getAcc();
    uint32_t acc_val2 = acc_val;
    printf("\nAcc main 2: %u\n",acc_val);
    cout <<"Accumulator Value: "<<acc_val2;
    cout<<endl;
    cout<< acc_val2;
    cout<<"\nblah";
    cout<<endl;
}

void stringfn1()
{
    string str1("This is the first String");
    string str2(str1);
    string str3(5, '#');
    string str4(str1,6,6);
    string str5(str2.begin(),str2.begin()+5);
    string str6(str2.begin(),str2.end());
    
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
    cout<<str5<<endl;
    //cout<<str6<<endl;
    
    uint8_t str6_len = str6.length();
    for(uint8_t idx = 0; idx < str6_len ; idx++)
        printf("0x%x ",(int)str6[idx]);
        //cout<<str6[idx];
    cout<<endl;
    
}

void references()
{
    int a = 10;
    int* b_ptr = new int();
    *b_ptr = 20;
    int* b_ptr_copy = b_ptr;
    int* a_ptr = &a;
    int &a_ref = a;
    int &b_ref = *b_ptr;
    cout<<"a_ref"<<a_ref<<endl;
    cout<<"b_ref"<<b_ref<<endl;

#ifdef NOT_DEF
    auto f = [](int &a_param)
    {
        a_param+=1;
        return;
    };
    
    f(a_ref);
    cout<<"a_ref - after f()"<<a_ref<<endl;
    f(b_ref);
    cout<<"b_ref - after f()"<<b_ref<<endl;
    f(b_ref);
    cout<<"b_ref - after f()"<<b_ref<<endl;
    
#endif
    cout<<"Changing b_ptr to point to a"<<endl;
    b_ptr = &a;
    cout<<"bref "<<b_ref <<" b_ptr"<<*b_ptr<<endl;
    *a_ptr += 10;
    cout<<"bref "<<b_ref <<" b_ptr"<<*b_ptr<<endl;
    b_ptr = b_ptr_copy;
    delete b_ptr;
    cout<<"bref "<<b_ref <<endl;
    cout<<"Adding cptr on heap"<<endl;
    int* c_ptr = new int();
    *c_ptr = 30;
    cout<<"bref "<<b_ref <<endl;
    printf("addr of bref : %p \n",&b_ref);
    printf("addr of cptr : %p \n",c_ptr);
}


void inputbufferex()
{
    int a;
    char ch[80];
    

    cin>>a;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(ch,80);
    
    cout<<a<<endl;
    cout<<ch<<endl;
}

void rawStringLit()
{
    string s1 = "My name \nis Angelo\n , did you \n not know that\n";
    
    string s2 = R"(My name \nis Angelo\n , did you \n not know that\n)";
    
    cout<<"String Normal: \n"<<s1<<endl;
    cout<<"String Literal: \n"<<s2<<endl;
}

void sizeofArray()
{
    int arr[2] = {1};
    printf("Arr Address: %p\n",arr);
    printf("Arr Address: %p\n",&arr);
    printf("Arr Address: %p\n",arr+1);
    printf("Arr Address: %p\n",&arr+1);
    
    struct test
    {
        int a;
        int b;
    }t1;
    
    test* p1;
    test* p2;
    p2 = (&t1 +1);
    p1 = &t1;
    printf("Str t1 address: %p\n",p1);
    printf("Str t1 address: %p\n",p2);
    printf("size = %ld\n", (uint8_t*)p2-(uint8_t*)p1);
}

void runtimePolymorphyism()
{
    class homosapien
    {
    public:
        virtual void getdescryption()
        {
            printf("I am homosapien \n");
        }
    };
    
    class human: public homosapien
    {
    public:
        virtual void getdescryption()
        {
            printf("I am a human\n");
        }
    };
    
    auto fprt = [](homosapien &type){ type.getdescryption();};
    homosapien hs;
    human hu;
    
    fprt(hs);
    fprt(hu);
}

void copyConstructor()
{
    class cpCls
    {
        public:
        
        int a;
        int b;
        cpCls(){a = 1; b = 1;}
        cpCls(int pa, int pb):a(pa),b(pb){}
        cpCls(const cpCls &cp)
        {
            printf("copy constructor called\n");
            a = cp.a;
            b = cp.b;
        }
    };
    
    cpCls c1(10,20);
    cpCls c2(c1);
    
    cout<<"a: "<<c2.a<<",b :"<<c2.b<<endl;
    //auto func = [](){};
    
    
}

int main(int argc, const char * argv[]) {
    
    programid id_to_execure = cpConstructEx1;
    
    switch (id_to_execure)
    {
        case classEx1:
            classex1();
            break;
        case string1:
            stringfn1();
            break;
        case referenceEx1:
            references();
            break;
        case ipbufferEx1:
            inputbufferex();
            break;
        case rawStringLitEx1:
            rawStringLit();
            break;
        case sizeofarrEx1:
            sizeofArray();
            break;
        case runTimePolyEx1:
            runtimePolymorphyism();
            break;
        case cpConstructEx1:
            copyConstructor();
            break;
        default:
            break;
            
    }
    
    return 0;
}
