#include <rubiksolveralgorithms.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include <Python.h>
#include <pyhelper.h>
#include <QObject>
#include <QDir>

using namespace std;

void M(string* o, string* s, string* p){

}

void thistlehwaite_algorithm(vector<string> v, string path){
    vector<string> T;
    vector<string> S (20, 0);
    string I = "FBRLUD";

    int G[36][2] = {{0, 9}, {2, 10}, {1, 8}, {3, 11}, {0, 1}, {4, 7}, {5, 8}, {7, 6}, {4, 8}, {2, 6}, {7, 8}, {3, 4}, {4, 9}, {6, 10}, {5, 8}, {7, 11}, {2, 1}, {6, 7}, {5, 3}, {7, 1}, {4, 1}, {2, 3}, {7, 6}, {3, 2}, {4, 8}, {6, 11}, {5, 10}, {7, 9}, {2, 3}, {6, 5}, {4, 3}, {2, 1}, {7, 1}, {5, 3}, {5, 6}, {1, 2}};

}

/*
#include<iostream>
#include<vector>
#define G(i,x,y)for(int i=x;i^y;i++)
#define h(x)s[a[x]/q*q+(a[x]+j)%q-42]
#define B(x)D=x;E=O.substr(j*3,3);G(i,0,3)E+=F[5-F.find(E[2-i])];G(i,0,D.length())D[i]=E[F.find(D[i++])];m.push_back(D);
#define P(a,b)G(i,0,6)G(k,49,52){e[0]=F[i];e[1]=k;m.push_back(e);}G(j,0,24){B(a)B(b)}
#define T C();z=m.size();for(b=c;b;){d=s;G(i,o=w=1,4){w*=z;if(o)G(j,0,w)if(o){s=d;u=j;G(k,0,i){f=m[u%z];G(x,0,f.length()){a=M[F.find(f[x++])];G(i,0,f[x]-48)G(l,0,2){q=3-l;p=4*l;G(j,0,q){t=h(p+3);G(k,-3,0)h(p-k)=h(p-1-k);h(p)=t;}}}u/=z;}C();if(c<b){u=j;G(k,0,i){std::cout<<m[u%z];u/=z;}b=c;o=0;}}}}
std::string s,a,D,E,d,f,e="  ",
    S="UFURUBULDFDRDBDLFRFLBRBLUFRURBUBLULFDRFDFLDLBDBR",
    F="ULFBRD",
    M[]={"KHEB*0.,","KRTI0<8@","KDNS*;2=","IVXG/@7>","BGWP,>4:","QNWT2468"},
    O=S.substr(24)+"FDRFRUFULFLDRDBRBURUFRFDBDLBLUBURBRDLDFLFULUBLBD";
    std::vector<std::string>m;
    int w,X=8,Y=16,o,c,u,b,z,p,q,t;

    void C(){c=0;G(i,X,Y)c+=s[i]!=S[i];}

void mixedMethod(int g, vector<string> v){
    G(i,1,g)s+=v[i];
    P("U2F1R1L3U2L1R3F1U2","L3R1F3L1R3D2L3R1F3L1R3");
    T;
    Y=24;
    T;
    X=0;T;
    m.clear();
    P("R3D3R1D3R3D2R1L1D1L3D1L1D2L3","R1F3L3F1R3F3L1F1");
    G(I,5,9){Y=I*6;T}
}
*/
