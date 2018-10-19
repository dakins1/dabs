#include <cstdio>
#include <iostream>
using namespace std;
typedef char T;


struct Node{
  T data;
  int prev;
  int next;

};

int ReadPrev(int node, FILE* file){
    fseek(file,node+sizeof(T)  , SEEK_SET);
    int ret;
    fread(&ret, sizeof(int), 1, file );
    return ret;
}
void WritePrev(int node,int value, FILE* file){
    fseek(file,node+sizeof(T)  , SEEK_SET);
    fwrite(&value, sizeof(int), 1, file );
}
int ReadNext(int node, FILE* file){
    fseek(file,node+ sizeof(T)+sizeof(int) ,SEEK_SET);
    int ret;
    fread(&ret, sizeof(int), 1, file );
    return ret;
}
void WriteNext(int node, int value, FILE* file){
    fseek(file,node+ sizeof(T)+sizeof(int) ,SEEK_SET);
    fwrite(&value, sizeof(int), 1, file );
    
}
T ReadData(int node, FILE* file){
    fseek(file, node, SEEK_SET);
    T ret;
    fread(&ret, sizeof(T), 1, file );
    return ret;

}
void WriteData(int node, T value, FILE* file){
    fseek(file, node, SEEK_SET);
    fwrite(&value, sizeof(T), 1, file );

}

int AllocateNode(FILE* file, int sz){
    //read freelist // but when is free list created in the other file?
    fseek(file, sizeof(Node), SEEK_SET);
    int freelist;
    fread(&freelist, sizeof(int), 1, file);

    int ret;
    if (freelist != -1){
        ret=freelist;
        freelist = ReadNext(freelist, file); //move freelist to next spot
        std::cout << "Freelist: " << freelist << endl;
        //write freelist
        fseek(file, sizeof(Node), SEEK_SET);
        fwrite(&freelist, sizeof(int), 1, file);
    } else {
        ret=sizeof(Node)+2*sizeof(int)+ sz* sizeof(Node);
    }

    return ret;
}

void DeallocateNode(int node, FILE* file){
    //read freelist
    fseek(file, sizeof(Node), SEEK_SET);
    int freelist;
    fread(&freelist, sizeof(int), 1, file);
        std::cout << "Freelist: " << freelist << endl;

    WriteNext (node, freelist, file);
    freelist=node;
        std::cout << "Freelist: " << freelist << endl;
    fseek(file, sizeof(Node), SEEK_SET);
    fwrite(&freelist, sizeof(int), 1, file);
}

int main(){

  FILE *f =  fopen("testList2018.bin", "w+");

  //start with sentinel at 0
  //writing prev of sentinel
  fseek (f, sizeof(char), SEEK_SET); //skip the data in Node
  int prev=0;
  fwrite(&prev, sizeof(int),1,f);//write preve
  int next=0;
  fwrite(&next, sizeof(int),1,f);//write next

  //freelist
  int freelist=-1; //initializing freelist
  fwrite(&freelist, sizeof(int), 1,f); //writing the free list

  //sz
  int sz=0; //init and writing size
  fwrite(&sz,sizeof(int),1,f);

  //allocate Node
  int address=AllocateNode(f,sz); //returns an ADDRESS!!
    cout << "Address: " << address << endl;

  WritePrev(address, 0, f);
  WriteNext(address,0,f);
  WriteData(address, 'x', f);
  
  WriteNext(0, address,f);  //sentinel
  WritePrev(0, address, f); //sentinel
  sz++;
  fseek (f, sizeof(Node)+sizeof(int), SEEK_SET); //skips over sentinel and free list
  fwrite(&sz,sizeof(int),1,f); //writes the new size

  cout<< ReadData(address,f) <<endl;

  fclose(f);

}
